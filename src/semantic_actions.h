#ifndef SEMANTIC_ACTIONS_H
#define SEMANTIC_ACTIONS_H

#include <stdlib.h> // Pour malloc, free, etc.
#include <string.h> // Pour strdup, etc.
#include <stdio.h>  // Pour fprintf, etc.
#include <stdbool.h> 
#include "types_and_symbols.h"

extern SymbolTable* table;

typedef struct ExprAttributes {
    struct Code* code;         // Pointeur vers la structure Code
    SymbolEntry* symbol;
    Type* type;  
    int value; 
    struct ExprAttributes* next; 
} ExprAttributes;

typedef struct Code {
    char* codeString; // Chaîne représentant le code généré
    struct Code* next; // Pointeur vers le prochain élément de la liste
} Code;


// Prototypes des fonctions auxiliaires
SymbolEntry* checkIdentifier(const char* identifier);
Type* getType(SymbolEntry* entry);
void pushIdentifierInfo(SymbolEntry* entry);
Code* insert_code(Code* code, int nargs, char* strings, ...);

SymbolEntry* insert(const char* name, SymbolTable* table) ;

void print_code(Code* code);
void free_code(Code* code);
void freeExprAttributes(ExprAttributes* attrs);
void concat_code(Code* dest, Code* src);

ExprAttributes* createArgumentExpression(ExprAttributes* expression);
ExprAttributes* addArgumentExpression(ExprAttributes* list, ExprAttributes* expression);

int est_constante(ExprAttributes* attribut);
int checkTypeCompatibility(Type* type1, Type* type2);
SymbolEntry* insert_symbol(const char* identifier, SymbolTable* table);
Code* init_code(int num_elements, ...);
char* new_et();
extern SymbolTable* table;
void reset_table(struct SymbolTable* table);
Code* declare_var(SymbolTable* table);

#endif /* SEMANTIC_ACTIONS_H */

