all:
	lex bongo.l
	bison -d -v bongo.y
	gcc bongo.tab.c lex.yy.c $(pkg-config -cflags -libs cairo) stack.c draw.c variable.c point.c -lm -lcairo -lfl -o bongo
	./bongo < test.txt
	xpdf test.pdf &

clean:
	rm *.output *.tab.* *.out *.yy.c *.o bongo *.pdf