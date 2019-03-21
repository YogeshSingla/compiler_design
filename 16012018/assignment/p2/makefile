# part of the makefile
ref_bool: ref_boolean.l ref_boolean.y
	bison -d ref_boolean.y
	flex ref_boolean.l
	cc -o $@ ref_boolean.tab.c lex.yy.c -lfl
