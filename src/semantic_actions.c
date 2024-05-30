#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "semantic_actions.h"
#include "types_and_symbols.h"
#include "structfe.tab.h" 
#define TABLE_SIZE 100  

SymbolTable* table = NULL;

ExprAttributes* createArgumentExpression(ExprAttributes* expression) {
   
    ExprAttributes* newExpr = (ExprAttributes*)malloc(sizeof(ExprAttributes));
    if (!newExpr) {
        fprintf(stderr, "Erreur : échec de l'allocation mémoire.\n");
        exit(EXIT_FAILURE); 
    }
    newExpr->next = NULL;
    newExpr->type = expression->type;
    return newExpr;
}

ExprAttributes* addArgumentExpression(ExprAttributes* list, ExprAttributes* expression) {
    
    if (!list) {
        return createArgumentExpression(expression);
    }
    
    ExprAttributes* current = list;
    while (current->next) {
        current = current->next;
    }
    
    current->next = createArgumentExpression(expression);
    return list; 
}


SymbolEntry* checkIdentifier(const char* identifier) {
  
    SymbolEntry* entry = (SymbolEntry*)malloc(sizeof(SymbolEntry));
    if (entry == NULL) {
        fprintf(stderr, "Erreur : échec d'allocation mémoire.\n");
        exit(EXIT_FAILURE);
    }
    entry->identifier = strdup(identifier); 
    entry->type = TYPE_INT; 
    entry->value = 0; 
    entry->isExtern = false; 
    entry->next = NULL; 
    return entry;
}


Code* insert_code(Code* code, int nargs, char* string, ...) {
    Code* first_code = code;
    char* nextarg;
    va_list lst;

    // Dernier élément de la chaîne de codes
    if (code != NULL) {
        while (code->next != NULL) {
            code = code->next;
        }
    }

    va_start(lst, string);
    nextarg = string;
    for (int i = 0; i < nargs; i++) {
        Code* new_code = (Code*)malloc(sizeof(Code));
        if (new_code == NULL) {
            fprintf(stderr, "Erreur : échec d'allocation mémoire.\n");
            va_end(lst);
            exit(EXIT_FAILURE);
        }

        new_code->codeString = strdup(nextarg); // Dupliquer la chaîne pour éviter des modifications inattendues
        new_code->next = NULL;

        if (code != NULL) {
            code->next = new_code;
            code = code->next;
        } else {
            first_code = new_code;
            code = new_code;
        }

        nextarg = va_arg(lst, char*);
    }
    va_end(lst);

    return first_code;
}


void print_code(Code* code) {
    while (code != NULL) {
        printf("%s\n", code->codeString);
        code = code->next;
    }
}

int est_constante(ExprAttributes* attribut) {
    
    if (attribut == NULL) {
        return 0; 
    }

    if (attribut->value != 0 && attribut->code == NULL && attribut->symbol == NULL && attribut->type == NULL) {
        return 1; 
    } else {
        return 0; 
    }
}

void free_code(Code* code) {
    while (code != NULL) {
        Code* temp = code;
        code = code->next;
        free(temp->codeString);
        free(temp); 
    }
}

void freeExprAttributes(ExprAttributes* attrs) {
    if (attrs) {
        if (attrs->code) {
            free_code(attrs->code);  
        }
        if (attrs->type) {
            free(attrs->type);  
        }
        free(attrs);  
    }
}



void concat_code(Code* dest, Code* src) {
    if (dest == NULL || src == NULL) {
        return; // Retourner immédiatement si l'une des entrées est NULL
    }
    while (dest->next != NULL) {
        dest = dest->next;
    }
    dest->next = src; // Attacher src à la fin de dest
}


void reset_table(SymbolTable* table) {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        SymbolEntry* entry = table->entries[i];
        while (entry != NULL) {
            entry->isConstant = 0;
            entry = entry->next;
        }
    }
}

SymbolEntry* insert(const char* name, SymbolTable* table) {
    if (table->count >= table->size) {
        
        return NULL;
    }
    SymbolEntry* entry = (SymbolEntry*)malloc(sizeof(SymbolEntry));
    if (!entry) {

        return NULL;
    }

    entry->identifier = strdup(name);
    if (!entry->identifier) {
        free(entry);
        return NULL;
    }

    entry->isConstant = 0;  
    table->entries[table->count++] = entry;
    return entry;
}


int checkTypeCompatibility(Type* type1, Type* type2) {
   
    if (type1 == type2) {
        return 1; 
    }

    if (type1 == NULL || type2 == NULL) {
        return 0; 
    }

    
    if (type1->kind != type2->kind) {
        return 0; 
    }

    
    switch (type1->kind) {
        
        case TYPE_STRUCT:
            
            if (type1->info.structInfo.structName != NULL && type2->info.structInfo.structName != NULL) {
                return strcmp(type1->info.structInfo.structName, type2->info.structInfo.structName) == 0;
            }
            return 0;
        case TYPE_POINTER:
            
            return checkTypeCompatibility(type1->info.pointedType, type2->info.pointedType);
        default:
            
            return 0; 
    }
}



void error_exit(const char* message) {
    fprintf(stderr, "%s\n", message);
    exit(EXIT_FAILURE);
}

Code* init_code(int num_elements, ...) {
    if (num_elements <= 0) return NULL;

    va_list args;
    va_start(args, num_elements);

    Code* head = NULL;
    Code* current = NULL;

    for (int i = 0; i < num_elements; ++i) {
        const char* str = va_arg(args, const char*);
        if (!str) continue;  // Ignorer les chaînes NULL

        Code* new_code = malloc(sizeof(Code));
        if (!new_code) error_exit("Erreur d'allocation mémoire pour Code");

        new_code->codeString = strdup(str);
        if (!new_code->codeString) {
            free(new_code);
            error_exit("Erreur d'allocation mémoire pour strdup");
        }

        new_code->next = NULL;

        if (current) {
            current->next = new_code;
        } else {
            head = new_code;  // Premier élément
        }
        current = new_code;
    }

    va_end(args);

    return head;
}

static int label_counter = 0;

char* new_et() {
    
    char* label = (char*)malloc(sizeof(char) * 10); 
    
    if (label == NULL) {
        fprintf(stderr, "Erreur : échec d'allocation mémoire pour une nouvelle étiquette.\n");
        exit(EXIT_FAILURE);
    }
    
    snprintf(label, 10, "et%d", label_counter++);
    
    return label;
}

Code* declare_var(SymbolTable* table) {
    Code* code = init_code(1, ""); 
    Code* first_code = code;

    for (int i = 0; i < 127; i++) {
        SymbolEntry* entry = table->entries[i];
        if (entry != NULL && entry->identifier[0] == '_') {
            insert_code(code, 4, dttostr(entry->type->kind), " ", entry->identifier, ";\n");
        }
    } 

    return first_code;
}


/*int main() {
    SymbolEntry* entry = checkIdentifier("testVariable");
    if (entry && entry->type) {  // Assurez-vous que `entry` ET `entry->type` ne sont pas nuls
        printf("SymbolEntry créé avec succès. Identifier: %s, Type: %d\n", 
               entry->identifier, 
               entry->type->kind);
    } else {
        printf("Échec de la création de SymbolEntry ou type non initialisé.\n");
    }

    // Libération de la mémoire si `entry` a été allouée
    if (entry) {
        free(entry->identifier);  // Libérez `identifier` seulement si `entry` est non nul
        free(entry);
    }

    return 0;
}
*/