all :
	lex bongo.l
	bison -d -v bongo.y
	gcc -std=c99 bongo.tab.c lex.yy.c $(pkg-config -cflags -libs cairo) -lcairo draw.c point.c -lfl -o bongo
	./bongo < test.txt
	xpdf test.pdf &

clean:
	rm *.output *.tab.* *.out *.yy.c *.o bongo *.pdf