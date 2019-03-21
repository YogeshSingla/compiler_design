# part of the makefile
variable_checker: variable_checker.l variable_checker.y
	bison -d variable_checker.y
	flex variable_checker.l
	cc -o $@ variable_checker.tab.c lex.yy.c -lfl