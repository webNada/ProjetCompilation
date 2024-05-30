#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "types_and_symbols.h"

#define MAX_TYPES 100  // Taille maximale pour la table des types

Type* typeTable[MAX_TYPES];  // Table des types avec une taille fixe
int typeTableSize = 0;

Type* createType(TypeKind kind) {
    Type* newType = malloc(sizeof(Type));
    if (!newType) {
        fprintf(stderr, "Failed to allocate memory for type\n");
        return NULL;
    }
    newType->kind = kind;
    switch (kind) {
        case TYPE_POINTER:
            newType->info.pointedType = NULL;  // Initialisation à NULL pour les types pointeur
            break;
        case TYPE_STRUCT:
            newType->info.structInfo.name = NULL;
            newType->info.structInfo.fields = NULL;
            newType->info.structInfo.fieldCount = 0;
            break;
        default:
            
            break;
    }
    return newType;
}

Type* lookupStructType(const char* name) {
    for (int i = 0; i < typeTableSize; i++) {
        if (typeTable[i]->kind == TYPE_STRUCT && strcmp(typeTable[i]->info.structInfo.name, name) == 0) {
            return typeTable[i];
        }
    }
    return NULL;
}

char* dttostr(TypeKind kind) {
    switch (kind) {
        case TYPE_INT:
            return "int";
        case TYPE_VOID:
            return "void";
        case TYPE_POINTER:
            return "pointer";
        case TYPE_STRUCT:
            return "struct";
        default:
            return "unknown type";
    }
}

