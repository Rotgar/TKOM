CC = g++ -g
FLAGS = -std=c++11
OBJS = assignment.o exception.o function.o identifier.o main.o object.o operation_expression.o primitive.o program.o property.o	statement.o variable.o parser.o lexer.o

all: interpreter

interpreter: $(OBJS)
	$(CC) $(OBJS) -o interpreter $(FLAGS)

property.o: property.cpp property.h
	$(CC) -c property.cpp

function.o: function.cpp function.h
	$(CC) -c function.cpp

object.o: object.cpp object.h
	$(CC) -c object.cpp

operation_expression.o: operation_expression.cpp operation_expression.h
	$(CC) -c operation_expression.cpp

assignment.o: assignment.cpp assignment.h
	$(CC) -c assignment.cpp

exception.o: exception.cpp exception.h
	$(CC) -c exception.cpp

identifier.o: identifier.cpp identifier.h
	$(CC) -c identifier.cpp


statement.o: statement.cpp statement.h
	$(CC) -c statement.cpp

variable.o: variable.cpp variable.h
	$(CC) -c variable.cpp

primitive.o: primitive.cpp primitive.h
	$(CC) -c primitive.cpp

program.o: program.cpp program.h
	$(CC) -c program.cpp

main.o: main.cpp
	$(CC) -c main.cpp

parser.o: SimpleScript.y
	bison -d SimpleScript.y
	$(CC) -c SimpleScript.tab.c -o parser.o

lexer.o: SimpleScript.l SimpleScript.tab.h
	flex SimpleScript.l
	$(CC) -c lex.yy.c -o lexer.o

clean:
	rm -f *.o *.tab.* interpreter








