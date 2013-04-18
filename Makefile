all :
	lex bongo.l
	bison -d -v bongo.y
	gcc bongo.tab.c lex.yy.c $(pkg-config -cflags -libs cairo) -lcairo test.c point.c -lfl -o bongo
	./bongo < test.txt

clean:
	rm *.output *.tab.* *.out *.yy.c *.o