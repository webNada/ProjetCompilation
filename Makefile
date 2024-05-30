all: compilefe compilebe clean

compilebe:
	flex src/Be.l
	bison -dv src/structbe.y -o y.tab.c
	gcc lex.yy.c y.tab.c -o backend -lfl

compilefe:
	flex -o lex.yy.c src/Fe.l
	bison -d -v src/structfe.y -o structfe.tab.c --report=all -Wconflicts-sr
	gcc -DYYDEBUG=1 -g3 src/types_and_symbols.c src/semantic_actions.c lex.yy.c structfe.tab.c main.c -lfl -o frontend

clean:
	rm -f lex.yy.c structfe.tab.c structfe.tab.h y.tab.c y.tab.h structfe.output y.output 
	

zip:
	tar -zcvf Projet-zina-mirza-maryam.tar.gz main.c Readme.txt testing.sh src/*.h src/*.c src/*.l src/*.y Makefile Tests/*