#ifndef TYPES_AND_SYMBOLS_H
#define TYPES_AND_SYMBOLS_H

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


typedef enum {
    TYPE_INT,
    TYPE_VOID,
    TYPE_POINTER,
    TYPE_STRUCT,
    TYPE_BASE
    
} TypeKind;


typedef struct Type Type;

struct Type {
    TypeKind kind;
    union {
        Type* pointedType;  // Utilisé si TYPE_POINTER
        struct {
            char* name;    // Nom de la structure, si TYPE_STRUCT
            struct StructField* fields; // Champs si TYPE_STRUCT
            int fieldCount;// Nombre de champs dans la structure
            char* structName;
        } structInfo;
    } info;
};


typedef struct SymbolEntry {
    char* identifier;     // Nom de l'identifiant
    Type* type;           // Type du symbole
    bool isExtern;  
    bool isConstant;
    int value;            // Valeur associée au symbole, si nécessaire
    struct SymbolEntry* next; // Pour utiliser dans une liste chaînée, si nécessaire
} SymbolEntry;


#define MAX_SYMBOLS 1000

typedef struct SymbolTable {
    SymbolEntry* entries[127];
    int size;     
    int count;     
} SymbolTable;



Type* createType(TypeKind kind);

Type* lookupStructType(const char* name);

char* dttostr(TypeKind datatype);


#endif // TYPES_AND_SYMBOLS_H

