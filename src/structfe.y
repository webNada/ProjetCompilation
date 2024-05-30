%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "src/types_and_symbols.h"
#include "src/semantic_actions.h"



int yylex(void);   
extern int yylineno;  

int yyerror(const char *s) {
    fprintf(stderr, "Error at line %d: %s\n", yylineno, s);
    return 0;
}
%}


%define parse.error verbose
%union {
  
    char* string;
    int number; 
    void* ptr;
    struct SymbolEntry* symbol; 
    struct Type* type; 
    struct Code* code; 
    struct ExprAttributes* exprAttributes; 
};

%token <string> IDENTIFIER CONSTANT INTEGER
%token <string> SIZEOF
%token PTR_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP
%token EXTERN
%token <type> INT VOID
%token <type> STRUCT 
%token IF WHILE FOR RETURN

%precedence THEN
%precedence ELSE

// Déclaration de la priorité pour les opérations de décalage

%left '+' '-'
%left '*' '/'
%nonassoc '<' '>' LE_OP GE_OP
%nonassoc EQ_OP NE_OP
%nonassoc AND_OP OR_OP


%type <exprAttributes> primary_expression
%type <exprAttributes> postfix_expression
%type <exprAttributes> unary_expression
%type <exprAttributes> expression
%type <exprAttributes> direct_declarator  declarator
%type <exprAttributes> logical_and_expression logical_or_expression
%type <exprAttributes> equality_expression relational_expression
%type <exprAttributes> additive_expression multiplicative_expression
%type <exprAttributes> program declaration_specifiers
%type <exprAttributes> argument_expression_list 
%type <exprAttributes>  shift_expression
%type <exprAttributes> struct_declaration_list struct_declaration struct_specifier
%type <exprAttributes> type_specifier 
%type <code> function_definition external_declaration declaration
%type <code> compound_statement declaration_list statement_list
%type <code> statement  expression_statement 
%type <code> selection_statement iteration_statement jump_statement
%type <code> parameter_declaration parameter_list 
%type <string> unary_operator

%start program
%%


primary_expression
    : IDENTIFIER {
        if ($1 == NULL || strlen($1) == 0) {
            fprintf(stderr, "Debug: IDENTIFIER is NULL or empty at line %d\n", yylineno);
            yyerror("IDENTIFIER is NULL or empty");
            YYABORT;
        } else {
            printf("Debug: IDENTIFIER %s at line %d\n", $1, yylineno);
        }

        $$ = (ExprAttributes*) malloc(sizeof(ExprAttributes));
        if ($$ == NULL) {
            yyerror("Allocation failure");
            YYABORT;
        }

        $$->symbol = checkIdentifier($1);
        if ($$->symbol == NULL) {
            yyerror("Identifiant non déclaré.");
            $$->code = init_code(1, "");
            $$->type = NULL;
        } else {
            printf("Debug: Identifier %s found at line %d\n", $$->symbol->identifier, yylineno);
            $$->code = init_code(1, $$->symbol->identifier);
            $$->type = $$->symbol->type;
        }
    }
    | CONSTANT {
        printf("Debug: CONSTANT %s at line %d\n", $1, yylineno);

        $$ = (ExprAttributes*) malloc(sizeof(ExprAttributes));
        if ($$ == NULL) {
            yyerror("Allocation failure");
            YYABORT;
        }

        $$->symbol = (SymbolEntry*) malloc(sizeof(SymbolEntry));
        if ($$->symbol == NULL) {
            yyerror("Allocation failure");
            free($$);
            YYABORT;
        }

        $$->symbol->identifier = strdup($1);
        $$->symbol->type = createType(TYPE_INT);
        $$->symbol->isConstant = 1;
        $$->code = init_code(1, $1);
        $$->type = $$->symbol->type;
    }
    | '(' expression ')' {
        $$ = $2;
    }
    ;

postfix_expression
    : primary_expression {
        $$ = $1;
    }
    | postfix_expression '(' ')' {
        $$ = $1;
        insert_code($$->code, 1, "()");
        if ($$->symbol) {
            $$->symbol->isConstant = 0;
        }
    }
    | postfix_expression '(' argument_expression_list ')' {
        $$ = $1;
        print_code($1->code);
        concat_code($$->code, $3->code);
        insert_code($$->code, 4, $1->symbol->identifier, "(", $3->symbol->identifier, ")");
    }
    | postfix_expression '.' IDENTIFIER
    | postfix_expression PTR_OP IDENTIFIER
    ;

argument_expression_list
    : expression {
        $$ = createArgumentExpression($1);
    }
    | argument_expression_list ',' expression {
        $$ = addArgumentExpression($1, $3);
    }
    ;

unary_expression
    : postfix_expression {
        $$ = $1;
    }
    | unary_operator unary_expression {
        $$ = $2;
        if (est_constante($$)) {
            insert_code($$->code, 2, $1, $2->symbol->identifier);
        } else {
            insert_code($$->code, 1, $1);
        }
    }
    | SIZEOF unary_expression {
        ExprAttributes* attr = (ExprAttributes*) malloc(sizeof(ExprAttributes));
        if (attr == NULL) {
            yyerror("Failed to allocate memory for ExprAttributes");
            exit(EXIT_FAILURE);
        }
        char sizeoff[32];
        sprintf(sizeoff, "%ld", sizeof($2->type));
        attr->code = init_code(1, sizeoff);
        attr->type = $2->type;
        $$ = attr;
    }
    | SIZEOF '(' type_specifier ')' {
        ExprAttributes* attr = (ExprAttributes*) malloc(sizeof(ExprAttributes));
        if (attr == NULL) {
            yyerror("Failed to allocate memory for ExprAttributes");
            exit(EXIT_FAILURE);
        }
        SymbolEntry* tmp = (SymbolEntry*) malloc(sizeof(SymbolEntry));
        if (tmp == NULL) {
            free(attr);
            yyerror("Failed to allocate memory for SymbolEntry");
            exit(EXIT_FAILURE);
        }
        tmp->identifier = "";
        char sizeoff[32];
        sprintf(sizeoff, "%ld", sizeof($3->type));
        attr->code = init_code(1, sizeoff);
        attr->symbol = tmp;
        $$ = attr;
    }
    ;


unary_operator
        : '&'   {$$ = "&";}
        | '*'   {$$ = "*";}
        | '-'   {$$ = "-";}
        ;

multiplicative_expression
    : unary_expression {
        $$ = $1;
    }
    | multiplicative_expression '*' unary_expression {
        if (checkTypeCompatibility($1->type, $3->type)) {
            $$ = (ExprAttributes*)malloc(sizeof(ExprAttributes));
            if ($$) {
                $$->type = $1->type;
                $$->code = insert_code(NULL, 3, $1->code->codeString, "*", $3->code->codeString);
            } else {
                yyerror("Allocation failure");
                freeExprAttributes($1);
                freeExprAttributes($3);
                $$ = NULL;
            }
        } else {
            yyerror("Incompatibilité de types pour l'opération de multiplication");
            freeExprAttributes($1);
            freeExprAttributes($3);
            $$ = NULL;
        }
    }
    | multiplicative_expression '/' unary_expression {
        if (checkTypeCompatibility($1->type, $3->type)) {
            $$ = (ExprAttributes*)malloc(sizeof(ExprAttributes));
            if ($$) {
                $$->type = $1->type;
                $$->code = insert_code(NULL, 3, $1->code->codeString, "/", $3->code->codeString);
            } else {
                yyerror("Allocation failure");
                freeExprAttributes($1);
                freeExprAttributes($3);
                $$ = NULL;
            }
        } else {
            yyerror("Incompatibilité de types pour l'opération de division");
            freeExprAttributes($1);
            freeExprAttributes($3);
            $$ = NULL;
        }
    }
;



additive_expression
    : multiplicative_expression {
        $$ = $1;
    }
    | additive_expression '+' multiplicative_expression {
        if (checkTypeCompatibility($1->type, $3->type)) {
            $$ = (ExprAttributes*)malloc(sizeof(ExprAttributes));
            if ($$) {
                $$->type = $1->type;
                $$->code = insert_code(NULL, 3, $1->code->codeString, "+", $3->code->codeString);
            } else {
                yyerror("Allocation failure");
                freeExprAttributes($1);
                freeExprAttributes($3);
                $$ = NULL;
            }
        } else {
            yyerror("Incompatibilité de types pour l'opération d'addition");
            freeExprAttributes($1);
            freeExprAttributes($3);
            $$ = NULL;
        }
    }
    | additive_expression '-' multiplicative_expression {
        if (checkTypeCompatibility($1->type, $3->type)) {
            $$ = (ExprAttributes*)malloc(sizeof(ExprAttributes));
            if ($$) {
                $$->type = $1->type;
                $$->code = insert_code(NULL, 3, $1->code->codeString, "-", $3->code->codeString);
            } else {
                yyerror("Allocation failure");
                freeExprAttributes($1);
                freeExprAttributes($3);
                $$ = NULL;
            }
        } else {
            yyerror("Incompatibilité de types pour l'opération de soustraction");
            freeExprAttributes($1);
            freeExprAttributes($3);
            $$ = NULL;
        }
    }
;

shift_expression
    : additive_expression
    {
        $$ = $1; 
    }
    | shift_expression LE_OP additive_expression {
        if (checkTypeCompatibility($1->type, $3->type)) {
            $$ = (ExprAttributes*)malloc(sizeof(ExprAttributes));
            if ($$ != NULL) {
                $$->type = $1->type; 
                $$->code = insert_code(NULL, 3, $1->code->codeString, "<<", $3->code->codeString);
            } else {
                yyerror("Allocation failure");
                freeExprAttributes($1);  
                freeExprAttributes($3);  
                $$ = NULL;
            }
        } else {
            yyerror("Incompatibilité de types pour l'opération de décalage à gauche");
            freeExprAttributes($1);  
            freeExprAttributes($3);  
            $$ = NULL; 
        }
    }
    | shift_expression GE_OP additive_expression {
        if (checkTypeCompatibility($1->type, $3->type)) {
            $$ = (ExprAttributes*)malloc(sizeof(ExprAttributes));
            if ($$ != NULL) {
                $$->type = $1->type; 
                $$->code = insert_code(NULL, 3, $1->code->codeString, ">>", $3->code->codeString);
            } else {
                yyerror("Allocation failure");
                freeExprAttributes($1);  
                freeExprAttributes($3);  
                $$ = NULL;
            }
        } else {
            yyerror("Incompatibilité de types pour l'opération de décalage à droite");
            freeExprAttributes($1);  
            freeExprAttributes($3);  
            $$ = NULL; 
        }
    }
;
relational_expression
    : shift_expression {
        $$ = $1;
    }
    | relational_expression '<' shift_expression {
        if (checkTypeCompatibility($1->type, $3->type)) {
            $$ = (ExprAttributes*)malloc(sizeof(ExprAttributes));
            if ($$ != NULL) {
                $$->code = insert_code(NULL, 3, $1->code->codeString, "<", $3->code->codeString);
                $$->type = createType(TYPE_BASE); 
            } else {
                yyerror("Allocation failure");
                freeExprAttributes($1);
                freeExprAttributes($3);
                $$ = NULL;
            }
        } else {
            yyerror("Incompatibilité de types pour l'opération de comparaison <");
            freeExprAttributes($1);
            freeExprAttributes($3);
            $$ = NULL;
        }
    }
    | relational_expression '>' shift_expression {
        if (checkTypeCompatibility($1->type, $3->type)) {
            $$ = (ExprAttributes*)malloc(sizeof(ExprAttributes));
            if ($$ != NULL) {
                $$->code = insert_code(NULL, 3, $1->code->codeString, ">", $3->code->codeString);
                $$->type = createType(TYPE_BASE);
            } else {
                yyerror("Allocation failure");
                freeExprAttributes($1);
                freeExprAttributes($3);
                $$ = NULL;
            }
        } else {
            yyerror("Incompatibilité de types pour l'opération de comparaison >");
            freeExprAttributes($1);
            freeExprAttributes($3);
            $$ = NULL;
        }
    }
    | relational_expression LE_OP shift_expression {
        if (checkTypeCompatibility($1->type, $3->type)) {
            $$ = (ExprAttributes*)malloc(sizeof(ExprAttributes));
            if ($$) {
                $$->code = insert_code(NULL, 3, $1->code->codeString, "<<", $3->code->codeString);
                $$->type = createType(TYPE_BASE);
            } else {
                yyerror("Allocation failure");
                freeExprAttributes($1);
                freeExprAttributes($3);
                $$ = NULL;
            }
        } else {
            yyerror("Incompatibilité de types pour l'opération de comparaison <<");
            freeExprAttributes($1);
            freeExprAttributes($3);
            $$ = NULL;
        }
    }
    | relational_expression GE_OP shift_expression {
        if (checkTypeCompatibility($1->type, $3->type)) {
            $$ = (ExprAttributes*)malloc(sizeof(ExprAttributes));
            if ($$) {
                $$->code = insert_code(NULL, 3, $1->code->codeString, ">>", $3->code->codeString);
                $$->type = createType(TYPE_BASE);
            } else {
                yyerror("Allocation failure");
                freeExprAttributes($1);
                freeExprAttributes($3);
                $$ = NULL;
            }
        } else {
            yyerror("Incompatibilité de types pour l'opération de comparaison >>");
            freeExprAttributes($1);
            freeExprAttributes($3);
            $$ = NULL;
        }
    }
    ;
equality_expression
    : relational_expression
    {
        $$ = $1;
    }
    | equality_expression EQ_OP relational_expression {
        if (checkTypeCompatibility($1->type, $3->type)) {
            $$ = (ExprAttributes*)malloc(sizeof(ExprAttributes));
            if ($$) {
                $$->code = insert_code(NULL, 3, $1->code->codeString, "==", $3->code->codeString);
                $$->type = createType(TYPE_BASE); 
            } else {
                yyerror("Allocation failure");
                freeExprAttributes($1);
                freeExprAttributes($3);
                $$ = NULL;
            }
        } else {
            yyerror("Incompatibilité de types pour l'opération d'égalité");
            freeExprAttributes($1);
            freeExprAttributes($3);
            $$ = NULL; 
        }
    }
    | equality_expression NE_OP relational_expression {
        
        if (checkTypeCompatibility($1->type, $3->type)) {
            $$ = (ExprAttributes*)malloc(sizeof(ExprAttributes));
            if ($$) {
                $$->code = insert_code(NULL, 3, $1->code->codeString, "!=", $3->code->codeString);
                $$->type = createType(TYPE_BASE); 
            } else {
                yyerror("Allocation failure");
                freeExprAttributes($1);
                freeExprAttributes($3);
                $$ = NULL;
            }
        } else {
            yyerror("Incompatibilité de types pour l'opération de différence");
            freeExprAttributes($1);
            freeExprAttributes($3);
            $$ = NULL;
        }
    }
    ;

logical_and_expression
    : equality_expression
    {
        $$ = $1;
    }
    | logical_and_expression AND_OP equality_expression {
        if (checkTypeCompatibility($1->type, $3->type)) {
            $$ = (ExprAttributes*)malloc(sizeof(ExprAttributes));
            if ($$) {
                
                $$->code = insert_code(NULL, 3, $1->code->codeString, "&&", $3->code->codeString);
                $$->type = createType(TYPE_BASE);  
            } else {
                yyerror("Allocation failure");
                freeExprAttributes($1); 
                freeExprAttributes($3); 
                $$ = NULL;
            }
        } else {
            yyerror("Incompatibilité de types pour l'opération logique ET");
            freeExprAttributes($1); 
            freeExprAttributes($3);
            $$ = NULL; 
        }
    }
    ;


logical_or_expression
    : logical_and_expression
    {
        $$ = $1;
    }
    | logical_or_expression OR_OP logical_and_expression {
        if (checkTypeCompatibility($1->type, $3->type)) {
            $$ = (ExprAttributes*)malloc(sizeof(ExprAttributes));
            if ($$) {
                $$->code = insert_code(NULL, 3, $1->code->codeString, "||", $3->code->codeString);
                $$->type = createType(TYPE_BASE); 
                yyerror("Allocation failure");
                freeExprAttributes($1); 
                freeExprAttributes($3); 
                $$ = NULL;
            }
        } else {
            yyerror("Incompatibilité de types pour l'opération logique OU");
            freeExprAttributes($1); 
            freeExprAttributes($3); 
            $$ = NULL; 
        }
    }
    ;



expression
    : logical_or_expression {
        $$ = $1;
    }
    | unary_expression '=' expression {
        if (checkTypeCompatibility($1->type, $3->type)) {
            $$ = (ExprAttributes*)malloc(sizeof(ExprAttributes));
            if ($$) {
                
                $$->code = insert_code(NULL, 3, $1->code->codeString, "=", $3->code->codeString);
                $$->type = $1->type;  
                yyerror("Allocation failure");
                freeExprAttributes($1);
                freeExprAttributes($3); 
                $$ = NULL;
            }
        } else {
            yyerror("Incompatibilité de types pour l'opération d'assignation");
            freeExprAttributes($1); 
            freeExprAttributes($3); 
            $$ = NULL; 
        }
    }
    ;

declaration
    : declaration_specifiers declarator ';' 
    {
        SymbolEntry *sym = $1->symbol;  
        if (sym) {
            if (sym->isExtern) {
                $$ = init_code(3, "extern ", dttostr(sym->type->kind), " ");
            } else {
                $$ = init_code(2, dttostr(sym->type->kind), " ");
            }
            if ($$ == NULL) {
                yyerror("Allocation failure");
                freeExprAttributes($1);
                freeExprAttributes($2);
                return 1;  
            }
            insert_code($2->code, 1, ";\n");
            concat_code($$, $2->code);
        } else {
            yyerror("SymbolEntry is NULL");
            freeExprAttributes($1);
            freeExprAttributes($2);
            return 1;  
        }
    }
    | struct_specifier ';' {
        $$ = init_code(1, ";\n");
        if ($$ == NULL) {
            yyerror("Allocation failure");
            return 1;  
        }
    }
    ;


declaration_specifiers
    : EXTERN type_specifier {
        if ($2 == NULL) {
            yyerror("Allocation failure or SymbolEntry is NULL");
            YYABORT;
        }
        $$ = $2;
        $$->symbol->isExtern = 1;
    }
    | type_specifier {
        if ($1 == NULL) {
            yyerror("Allocation failure or SymbolEntry is NULL");
            YYABORT;
        }
        $$ = $1;
        $$->symbol->isExtern = 0;
    }
    ;

type_specifier
    : VOID {
        $$ = malloc(sizeof(ExprAttributes));
        if ($$ == NULL) {
            yyerror("Failed to allocate memory for ExprAttributes");
            YYABORT;
        }
        $$->type = createType(TYPE_VOID);
        if ($$->type == NULL) {
            free($$);
            yyerror("Failed to create type TYPE_VOID");
            YYABORT;
        }
        $$->code = NULL;
        $$->symbol = malloc(sizeof(SymbolEntry));
        if ($$->symbol == NULL) {
            free($$->type);
            free($$);
            yyerror("Failed to allocate memory for SymbolEntry");
            YYABORT;
        }
        $$->symbol->isExtern = 0;
    }
    | INT {
        $$ = malloc(sizeof(ExprAttributes));
        if ($$ == NULL) {
            yyerror("Failed to allocate memory for ExprAttributes");
            YYABORT;
        }
        $$->type = createType(TYPE_INT);
        if ($$->type == NULL) {
            free($$);
            yyerror("Failed to create type TYPE_INT");
            YYABORT;
        }
        $$->code = NULL;
        $$->symbol = malloc(sizeof(SymbolEntry));
        if ($$->symbol == NULL) {
            free($$->type);
            free($$);
            yyerror("Failed to allocate memory for SymbolEntry");
            YYABORT;
        }
        $$->symbol->isExtern = 0;
    }
    | struct_specifier {
        $$ = $1;
    }
    ;

struct_specifier
    : STRUCT IDENTIFIER '{' struct_declaration_list '}'
    {
        if (!$4) {
            yyerror("Internal error: struct_declaration_list returned NULL");
            exit(EXIT_FAILURE);
        }
        if (!$4->code || !$4->type) {
            yyerror("Incomplete exprAttributes from struct_declaration_list");
            freeExprAttributes($4);
            exit(EXIT_FAILURE);
        }
        $$ = $4; 
        print_code($$->code); 
    }
    | STRUCT '{' struct_declaration_list '}'
    {
        if (!$3 || !$3->code || !$3->type) {
            yyerror("Incomplete or missing exprAttributes for anonymous struct");
            exit(EXIT_FAILURE);
        }
        $$ = $3;
        print_code($$->code); 
    }
    | STRUCT IDENTIFIER
    {
        ExprAttributes* attr = (ExprAttributes*) malloc(sizeof(ExprAttributes));
        if (!attr) {
            yyerror("Failed to allocate memory for exprAttributes");
            exit(EXIT_FAILURE);
        }
        char* identifier = (char*)$2;
        attr->code = init_code(1,identifier); ;
        attr->type = lookupStructType($2); 
        attr->symbol = NULL; 

        if (!attr->code || !attr->type) {
            yyerror("Failed to initialize exprAttributes correctly");
            free(attr);
            exit(EXIT_FAILURE);
        }

        $$ = attr;
        print_code($$->code); 
    }
;

struct_declaration_list
    : struct_declaration {
        $$ = $1; 
    }
    | struct_declaration_list struct_declaration {
        if ($$ == NULL) $$ = $1; 
        if ($1->code && $2->code) { 
            concat_code($1->code, $2->code); 
        }
        $$ = $1; 
        freeExprAttributes($2);
    }
;



struct_declaration
         : type_specifier declarator ';' {
        $$ = malloc(sizeof(ExprAttributes));
        if ($$ == NULL) {
            yyerror("Failed to allocate memory for ExprAttributes");
            exit(EXIT_FAILURE);
        }
        if ($1 && $2) {
            $$->type = $1->type;  
            $$->symbol = $2->symbol;  
            $$->code = init_code(1, ";");
            if ($2->code) {
                concat_code($$->code, $2->code);
            }
        } else {
            yyerror("Type specifier or declarator returned NULL");
            free($$);
            $$ = NULL;
            return 1; 
        }
     
    }


declarator
    : '*' direct_declarator {
        $$ = malloc(sizeof(ExprAttributes));
        if ($$ == NULL) {
            yyerror("Failed to allocate memory for ExprAttributes");
            exit(EXIT_FAILURE);
        }
        $$->code = init_code(1, "*");
        if ($2 && $2->code) {
            concat_code($$->code, $2->code);
        } else {
            yyerror("Code from direct_declarator is NULL");
            free($$);
            return 1;
        }
        if ($2 && $2->symbol) {
            $2->symbol->type = createType(TYPE_POINTER);
            $$->symbol = $2->symbol;
        } else {
            yyerror("Symbol from direct_declarator is NULL or not properly initialized");
            free($$);
            return 1;
        }
    }
    | direct_declarator {
        if ($1 == NULL) {
            yyerror("direct_declarator returned NULL");
            $$ = NULL;
            return 1;
        }
        $$ = $1;
    }
    ;


direct_declarator
    : IDENTIFIER {
        if ($1 == NULL || strlen($1) == 0) {
            yyerror("IDENTIFIER is NULL or empty");
            $$ = NULL;
            YYABORT;
        } else {
           
            $$ = (ExprAttributes*) malloc(sizeof(ExprAttributes));
            if (!$$) {
                yyerror("Failed to allocate memory for ExprAttributes");
                exit(EXIT_FAILURE);
            }
           
            $$->code = init_code(1, $1);
            $$->symbol = (SymbolEntry*) malloc(sizeof(SymbolEntry));
            if (!$$->symbol) {
                free($$);
                yyerror("Failed to allocate memory for SymbolEntry");
                exit(EXIT_FAILURE);
            }
            $$->symbol->identifier = strdup($1);
            if (!$$->symbol->identifier) {
                free($$->symbol);
                free($$);
                yyerror("Failed to duplicate identifier");
                exit(EXIT_FAILURE);
            }
            $$->symbol->type = NULL;
        }
    }
    | '(' declarator ')'
    {
        $$ = $2;
    }
    |direct_declarator '(' parameter_list ')'
    {
        if ($1 != NULL && $3 != NULL) {
            $$ = $1;
            insert_code($$->code, 1, "(");
            concat_code($$->code, $3);
            insert_code($$->code, 1, ")");
        } else {
            fprintf(stderr, "Null pointer encountered in parameter list\n");
        }
    }
    | direct_declarator '(' ')'
   {
        if ($1 == NULL) {
            yyerror("direct_declarator is NULL");
            $$ = NULL;
            YYABORT;
        }
        $$ = $1;
        insert_code($$->code, 2, $1->code->codeString, "()");
    }
    ;


parameter_list
        : parameter_declaration {
            
           $$ = $1;
        }
        | parameter_list ',' parameter_declaration {
           
             $$ = $1;
            insert_code($$, 1, ", ");
            concat_code($$, $3); 
        }
        ;

parameter_declaration
    : declaration_specifiers declarator {
        SymbolEntry* paramEntry = (SymbolEntry*)malloc(sizeof(SymbolEntry));
        if (!paramEntry) {
            yyerror("Allocation failure for SymbolEntry");
            freeExprAttributes($1);
            freeExprAttributes($2);
            return 1;
        }
        paramEntry->type = $1->symbol->type;
        $$ = init_code(0);
        concat_code($$, $1->code);
        concat_code($$, $2->code);
        freeExprAttributes($1);
        freeExprAttributes($2);
    }
    ;
statement
    : compound_statement{
        $$ = $1; 
    	}
        | expression_statement{
        $$ = $1; 
    	}
        | selection_statement{
        $$ = $1; 
    	}
        | iteration_statement{
        $$ = $1; 
    	}
        | jump_statement {
        $$ = $1; 
   	 }
    ;

compound_statement
    : '{' '}' 
    {
        $$ = init_code(0);
    }
    | '{' statement_list '}' 
    {
        $$ = $2; 
    }
    | '{' declaration_list '}' 
    {
        $$ = $2; 
    }
    | '{' declaration_list statement_list '}' 
    {
        $$ = $2; 
        concat_code($$, $3);
    }
    ;


declaration_list
        : declaration{
        $$ = $1; 
    	}
        | declaration_list declaration {
        $$ = $1; 
        concat_code($$, $2);
	}
        ;

statement_list
    : statement
    {
        $$ = $1; 
    }
    | statement_list statement
    {
        $$ = $1; 
        concat_code($$, $2); 
    }
    ;


expression_statement
    : ';'
    {
        $$ = init_code(0);  
    }
    | expression ';'
    {
       if (strrchr($1->code->codeString, ';') == NULL) {
            insert_code($1->code, 1, ";\n"); 
        }
        $$ = $1->code;   
    }
    ;

selection_statement
    : IF '(' expression ')' statement %prec THEN
    {
        char* etq_if = new_et();
        char* etq_else = new_et();

        if ($3->type->kind != TYPE_INT) {
        yyerror("Condition must be an INT!");
    }


        $$ = $3->code;
        insert_code($$, 7, "if (!", $3->symbol->identifier, ") goto ", etq_else, ";\n", etq_if, ":\n");
        concat_code($$, $5);
        insert_code($$, 2, etq_else, ":\n");

    }
    | IF '(' expression ')' statement ELSE statement
    {
        char* etq_true = new_et();
        char* etq_false = new_et();
        char* etq_def = new_et();

        if ($3->type->kind != TYPE_INT) {
        yyerror("Condition must be an INT!");
    }

        $$ = $3->code;
        insert_code($$, 7, "if (!", $3->symbol->identifier, ") goto ", etq_false, ";\n", etq_true, ":\n");
        concat_code($$, $5);
        insert_code($$, 5, "goto ", etq_def, ";\n", etq_false, ":\n");
        concat_code($$, $7);
        insert_code($$, 5, "goto ", etq_def, ";\n", etq_def, ":\n");
    }
    ;


iteration_statement
    : WHILE '(' expression ')' statement
    {
        char* etq_debut = new_et();
        char* etq_fin = new_et();

        if ($3->type->kind != TYPE_INT) {
            yyerror("Condition must be an INT!");
        }

        $$ = $3->code;
        insert_code($$, 6, etq_debut, ":\nif (!", $3->symbol->identifier, ") goto ", etq_fin, "\n");
        concat_code($$, $5);
        insert_code($$, 2, "goto ", etq_debut, "\n", etq_fin, ":\n");
    }
    | FOR '(' expression_statement expression_statement expression ')' statement
    {
        char* etq_debut = new_et();
        char* etq_condition = new_et();
        char* etq_fin = new_et();

        if ($5->type->kind != TYPE_INT) {
            yyerror("Condition must be un INT!");
        }

        Code* code3 = $5->code;

        $$ = $5->code;
        insert_code($$, 4, etq_debut, ":\nif (!", $5->symbol->identifier, ") goto ", etq_fin, "\n");
        concat_code($$, $7);
        concat_code($$, code3);
        insert_code($$, 2, "goto ", etq_debut, "\n", etq_fin, ":\n");
    }
    ;



jump_statement
    : RETURN ';'
    {
        $$ = init_code(1, "return;\n");
    }
    | RETURN expression ';'
    {
        char* tmp = malloc(strlen($2->symbol->identifier) + 10);
        sprintf(tmp, "return %s;\n", $2->symbol->identifier);
        insert_code($2->code, 1, tmp);
        free(tmp); 
        $$ = $2->code;
    }
    ;


program
        : external_declaration
        {
                print_code($1);
                free_code($1);
        }
        | program external_declaration
        {
                print_code($2);
                free_code($2);
        }
        ;

external_declaration
    : function_definition
    {
        $$ = $1; 
    }
    | declaration
    {
        $$ = $1; 
    }
    
    ;

function_definition
    : declaration_specifiers declarator compound_statement
    {
        Code* code = NULL;
        if ($1->symbol->isExtern) {
            code = init_code(2, "extern ", dttostr($1->symbol->type->kind));
        } else {
            code = init_code(1, dttostr($1->symbol->type->kind));
        }

        concat_code(code, $2->code);
        insert_code(code, 1, " {\n");
        concat_code(code, declare_var(table));
        concat_code(code, $3);
        insert_code(code, 1, "}\n");
        reset_table(table);
        $$ = code;
    }
    ;




%%

