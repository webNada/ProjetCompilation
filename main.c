#include <stdio.h>
#include <stdlib.h>
#include "structfe.tab.h"  

extern int yyparse(void);
extern FILE *yyin; 
extern int yydebug;

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *srcFile = fopen(argv[1], "r");
    if (!srcFile) {
        fprintf(stderr, "Error opening source file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    FILE *dstFile = fopen(argv[2], "w");
    if (!dstFile) {
        fprintf(stderr, "Error opening destination file %s\n", argv[2]);
        fclose(srcFile); // Assurez-vous de fermer srcFile avant de sortir
        return EXIT_FAILURE;
    }

    yyin = srcFile;
    yydebug = 1;

    int parseResult = yyparse();
    if (parseResult == 0) {
        fprintf(dstFile, "Parsing completed successfully.\n");
        printf("Parsing successful.\n");
    } else {
        fprintf(dstFile, "Parsing failed.\n");
        fprintf(stderr, "Parsing encountered errors.\n");
    }

    fclose(srcFile);
    fclose(dstFile);

    return EXIT_SUCCESS;
}
