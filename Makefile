all :
	lex bongo.l
	bison -d -v bongo.y
	gcc bongo.tab.c lex.yy.c $(pkg-config -cflags -libs cairo) -lcairo stack.c draw.c point.c -lfl -o bongo
	./bongo < test.txt
	xpdf test.pdf &

clean:
	rm *.output *.tab.* *.out *.yy.c *.o bongo *.pdf