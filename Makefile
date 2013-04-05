all :
	lex bongo.l
	bison -d -v bongo.y
	gcc bongo.tab.c lex.yy.c -lfl -o bongo
	./bongo < test.txt