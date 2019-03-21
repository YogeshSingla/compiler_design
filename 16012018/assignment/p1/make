# part of the makefile
ref_as: ref_as.l ref_as.y
	bison -d ref_as.y
	flex ref_as.l
	cc -o $@ ref_as.tab.c lex.yy.c -lfl
