all :
	lex bongo.l
	bison -d -v bongo.y
	gcc -std=c99 bongo.tab.c lex.yy.c point.c test.c -lcairo -lfl -o bongo
	./bongo < test.txt
	xpdf test.pdf &
