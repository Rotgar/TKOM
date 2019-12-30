%define parse.error verbose

%{
    #include <iostream>
	#include <string>
	#include <memory>
    using namespace std;

	#include "primitive.h"
	#include "identifier.h"
	#include "object.h"
	#include "function.h"
	#include "variable.h"
	#include "exception.h"
	#include "operation_expression.h"
	#include "statement.h"
	#include "assignment.h"
	#include "property.h"
	#include "program.h"

    extern int yylex(void);
    extern int yylineno;
    extern int yyparse();

    extern FILE *yyin;

	int arrayPosition = 0;

    bool errorReported = false;

    void yyerror(const char* s) {
      if(!errorReported) {
         cerr << "ERROR:\t at line " << yylineno << ":\t" << s << endl;
      }
    }

    void yyerror(const char* s, char c) {
      cerr << "ERROR:\tat line " << yylineno << ": " << s << " \"" << c << "\"" << endl;
      errorReported = true;
    }
%}

%union {
    int integerVal;
    float floatVal;
    bool booleanVal;
    char* stringVal;
	Identifier* identifierVal;
	StatementsList* statementsListVal;
	Statement* statementVal;
	OperationExpression* operationExpressionVal;
	ParametersList* parametersListVal;
	Object* objectVal;
	PropertyList* propertyListVal;
	Property* propertyVal;
	ArgumentsList* argumentsListyVal;
	OperationExpressionsList* operationExpressionsListVal;
	ObjectLiteral* objectLiteralVal;
}

%token<integerVal> INTEGER_T "integer"
%token<floatVal> FLOAT_T "FLOAT"
%token<booleanVal> BOOLEAN_T "BOOLEAN"
%token<stringVal> STRING_T "STRING"
%token<stringVal> IDENTIFIER "IDENTIFIER"
%token ASSIGN               "="
%token COLON                ":"
%token SEMICOLON            ";"
%token COMMA                ","
%token OPEN_BRACE           "{"
%token CLOSE_BRACE          "}"
%token IF                   "if"
%token WHILE                "while"
%token VAR                  "var"
%token FUNCTION_T           "function"
%token RETURN               "return"
%token PUSH                 "push"
%token SIZE                 "size"

%precedence NO_ELSE
%precedence ELSE
%left AND OR
%left LESS_THAN LESS_EQUAL_THAN GREATER_THAN GREATER_EQUAL_THAN EQUAL EQUAL_TYPE NOT_EQUAL
%left PLUS MINUS
%left ASTERISK SLASH
%right INC DEC NOT
%precedence NO_FUNCTION_CALL
%left OPEN_PARENTHESIS CLOSE_PARENTHESIS
%left DOT OPEN_BRACKET CLOSE_BRACKET

%type<identifierVal> identifier
%type<statementsListVal> block
%type<statementsListVal> statements_list
%type<statementsListVal> function_body
%type<statementVal> statement
%type<statementVal> conditional_statement
%type<statementVal> iteration_statement
%type<statementVal> return_statement
%type<statementVal> expression_statement
%type<statementVal> function_declaration_statement
%type<statementVal> variable_declaration_statement
%type<operationExpressionVal> operation_expression
%type<operationExpressionVal> assignment_expression
%type<operationExpressionVal> argument
%type<operationExpressionVal> function_call_expression
%type<operationExpressionVal> variable_declaration
%type<operationExpressionsListVal> variable_declaration_list
%type<parametersListVal> parameters_list
%type<propertyListVal> properties_names_and_values
%type<propertyListVal> array_elements
%type<propertyVal> property_name_and_value
%type<propertyVal> array_element
%type<objectLiteralVal> object_literal
%type<objectLiteralVal> array
%type<argumentsListyVal> arguments_list

%destructor { } <integerVal>
%destructor { } <floatVal>
%destructor { } <booleanVal>
%destructor { free ($$); } <stringVal>
%destructor { free ($$); } <identifierVal>
%destructor { free ($$); } <statementsListVal>
%destructor { free ($$); } <statementVal>
%destructor { free ($$); } <operationExpressionVal>
%destructor { free ($$); } <operationExpressionsListVal>
%destructor { free ($$); } <parametersListVal>
%destructor { free ($$); } <propertyListVal>
%destructor { free ($$); } <propertyVal>
%destructor { free ($$); } <objectLiteralVal>
%destructor { free ($$); } <argumentsListyVal>

%%
program                         : statements_list {
										Program(unique_ptr<StatementsList>($1)).evaluate();
									}
                                | /* empty statements list */
                                ;

statements_list                 : statements_list statement {
										$1->add(unique_ptr<Statement>($2));
										$$ = $1;
									}
                                | statement {
										StatementsList* stmtsList = new StatementsList();
										stmtsList->add(unique_ptr<Statement>($1));

										$$ = stmtsList;
									}
                                ;

statement                       : expression_statement
                                | variable_declaration_statement
                                | function_declaration_statement
                                | return_statement
                                | iteration_statement
                                | conditional_statement
                                ;

expression_statement            : assignment_expression delimiter {
										$$ = new ExpressionStatement(unique_ptr<OperationExpression>($1));
									}
                                | operation_expression delimiter {
										$$ = new ExpressionStatement(unique_ptr<OperationExpression>($1));
									}
                                ;

assignment_expression           : identifier ASSIGN operation_expression {
										$$ = new OperationExpressionAssignment(unique_ptr<Identifier>($1),
												unique_ptr<OperationExpression>($3));
									}
								| identifier DOT PUSH OPEN_PARENTHESIS array_element CLOSE_PARENTHESIS {
										$$ = new ArrayPushExpressionAssignment(unique_ptr<Identifier>($1),
												unique_ptr<Property>($5));
									}
                                | identifier ASSIGN function_declaration_statement {
										FunctionDeclarationStatement* fdstmtPtr = dynamic_cast<FunctionDeclarationStatement*> ($3);
										Function funct = fdstmtPtr->getFunction();

										$$ = new FunctionAssignment(unique_ptr<Identifier>($1), funct);
									}
                                | identifier ASSIGN object_literal {
										$$ = new ObjectLiteralAssignment(unique_ptr<Identifier>($1),
											unique_ptr<ObjectLiteral>($3));
									}
                                | identifier ASSIGN array {
									$$ = new ObjectLiteralAssignment(unique_ptr<Identifier>($1),
											unique_ptr<ObjectLiteral>($3));
                  					}
								| INC identifier {
										Primitive onePrimitive = Primitive(1);
										Variable one = Variable(onePrimitive);

										OperationExpression* expression = new Addition(
											unique_ptr<OperationExpression>(new IdentifierExpression(unique_ptr<Identifier>($2))),
											unique_ptr<OperationExpression>(new ConstantExpression(unique_ptr<Variable>(new Variable(one))))
											);

										$$ = new OperationExpressionAssignment(unique_ptr<Identifier>($2),
												unique_ptr<OperationExpression>(expression));
									}
                                | DEC identifier {
										Primitive onePrimitive = Primitive(1);
										Variable one = Variable(onePrimitive);

										OperationExpression* expression = new Subtraction(
											unique_ptr<OperationExpression>(new IdentifierExpression(unique_ptr<Identifier>($2))),
											unique_ptr<OperationExpression>(new ConstantExpression(unique_ptr<Variable>(new Variable(one)))));

										$$ = new OperationExpressionAssignment(unique_ptr<Identifier>($2),
												unique_ptr<OperationExpression>(expression));
									}
                                ;

object_literal                  : OPEN_BRACE properties_names_and_values CLOSE_BRACE {
										$$ = new ObjectLiteral(unique_ptr<PropertyList>($2));
									}
                                ;

properties_names_and_values     : /* empty object */ {
										PropertyList* propertyList = new PropertyList();
										propertyList->setIsArray(false);
										$$ = propertyList;
									}
                                | properties_names_and_values COMMA property_name_and_value {
										$1->add(unique_ptr<Property>($3));
										$$ = $1;
									}
                                | property_name_and_value {
										PropertyList* propertyList = new PropertyList();
										propertyList->setIsArray(false);
										propertyList->add(unique_ptr<Property>($1));

										$$ = propertyList;
									}
                                ;

property_name_and_value         : IDENTIFIER COLON operation_expression {
										$$ = new Property($1, unique_ptr<OperationExpression>($3));
									}
                                | IDENTIFIER COLON function_declaration_statement {
										FunctionDeclarationStatement* fdstmtPtr = dynamic_cast<FunctionDeclarationStatement*> ($3);
										Function funct = fdstmtPtr->getFunction();

										$$ = new Property($1, unique_ptr<Function>(new Function(funct)));
									}
                                | IDENTIFIER COLON object_literal {
										$$ = new Property($1, unique_ptr<ObjectLiteral>($3));
									}

								| IDENTIFIER COLON array {
										$$ = new Property($1, unique_ptr<ObjectLiteral>($3));
									}
                                ;

array                           : 
								{ Property::setElementCounter(0); }
								  OPEN_BRACKET array_elements CLOSE_BRACKET {
										$$ = new ObjectLiteral(unique_ptr<PropertyList>($3));
									}
                                ;

array_elements                  : /* empty elem */ {
										PropertyList* propertyList = new PropertyList();
										propertyList->setIsArray(true);
										$$ = propertyList;
									}
                                | array_elements COMMA array_element {
										$1->add(unique_ptr<Property>($3));
										$$ = $1;
									}
                                | array_element {
										PropertyList* propertyList = new PropertyList();
										propertyList->setIsArray(true);
										propertyList->add(unique_ptr<Property>($1));

										$$ = propertyList;
									}
                                ;

array_element                  : operation_expression {
										$$ = new Property(unique_ptr<OperationExpression>($1));
									}
                                | function_declaration_statement{
										FunctionDeclarationStatement* fdstmtPtr = 
											dynamic_cast<FunctionDeclarationStatement*> ($1);
										Function funct = fdstmtPtr->getFunction();

										$$ = new Property(unique_ptr<Function>(new Function(funct)));
                                	}	
                                | object_literal {
                  						$$ = new Property(unique_ptr<ObjectLiteral>($1));
									}
				  				| 
									{ arrayPosition = Property::getElementCounter(); } 
								  array {
										Property::setElementCounter(arrayPosition);
                  						$$ = new Property(unique_ptr<ObjectLiteral>($2));
                                	}
                                ;

operation_expression            : OPEN_PARENTHESIS operation_expression CLOSE_PARENTHESIS { $$ = $2; }
                                | INTEGER_T {
										Primitive primitive = Primitive($1);
										$$ = new ConstantExpression(unique_ptr<Variable>(new Variable(primitive)));
									}
                                | FLOAT_T {
										Primitive primitive = Primitive($1);
										$$ = new ConstantExpression(unique_ptr<Variable>(new Variable(primitive)));
									}
                                | BOOLEAN_T {
										Primitive primitive = Primitive($1);
										$$ = new ConstantExpression(unique_ptr<Variable>(new Variable(primitive)));
									}
                                | STRING_T {
										Primitive primitive = Primitive(string($1), true);
										$$ = new ConstantExpression(unique_ptr<Variable>(new Variable(primitive)));
									}
                                | operation_expression AND operation_expression {
										$$ = new LogicalAnd(unique_ptr<OperationExpression>($1),
											unique_ptr<OperationExpression>($3));
									}
                                | operation_expression OR operation_expression {
										$$ = new LogicalOr(unique_ptr<OperationExpression>($1),
											unique_ptr<OperationExpression>($3));
									}
                                | operation_expression LESS_THAN operation_expression {
										$$ = new LessThan(unique_ptr<OperationExpression>($1),
											unique_ptr<OperationExpression>($3));
									}
                                | operation_expression LESS_EQUAL_THAN operation_expression {
										$$ = new LessThanOrEqualTo(unique_ptr<OperationExpression>($1),
											unique_ptr<OperationExpression>($3));
									}
                                | operation_expression GREATER_THAN operation_expression {
										$$ = new GreaterThan(unique_ptr<OperationExpression>($1),
											unique_ptr<OperationExpression>($3));
									}
                                | operation_expression GREATER_EQUAL_THAN operation_expression {
										$$ = new GreaterThanOrEqualTo(unique_ptr<OperationExpression>($1),
											unique_ptr<OperationExpression>($3));
									}
                                | operation_expression EQUAL operation_expression {
										$$ = new Equals(unique_ptr<OperationExpression>($1),
											unique_ptr<OperationExpression>($3));
									}
								| operation_expression EQUAL_TYPE operation_expression {
										$$ = new EqualsType(unique_ptr<OperationExpression>($1),
											unique_ptr<OperationExpression>($3));
									}	
                                | operation_expression NOT_EQUAL operation_expression {
										$$ = new NotEquals(unique_ptr<OperationExpression>($1),
											unique_ptr<OperationExpression>($3));
									}
                                | operation_expression PLUS operation_expression {
										$$ = new Addition(unique_ptr<OperationExpression>($1),
											unique_ptr<OperationExpression>($3));
									}
                                | operation_expression MINUS operation_expression {
										$$ = new Subtraction(unique_ptr<OperationExpression>($1),
											unique_ptr<OperationExpression>($3));
									}
                                | operation_expression ASTERISK operation_expression {
										$$ = new Multiplication(unique_ptr<OperationExpression>($1),
											unique_ptr<OperationExpression>($3));
									}
                                | operation_expression SLASH operation_expression {
										$$ = new Division(unique_ptr<OperationExpression>($1),
											unique_ptr<OperationExpression>($3));
									}
                                | NOT operation_expression {
										$$ = new LogicalNot(unique_ptr<OperationExpression>($2));
									}
								| MINUS operation_expression {
										$$ = new Negation(unique_ptr<OperationExpression>($2));
									}
                                | function_call_expression { 
										$$ = $1; 
									}
                                | identifier DOT SIZE OPEN_PARENTHESIS CLOSE_PARENTHESIS {
										$$ = new ArraySizeExpression(unique_ptr<Identifier>($1));
									}
								| identifier %prec NO_FUNCTION_CALL {
										$$ = new IdentifierExpression(unique_ptr<Identifier>($1));
									}
                                ;

function_call_expression        : identifier OPEN_PARENTHESIS arguments_list CLOSE_PARENTHESIS {
										$$ = new FunctionCallExpression(
											unique_ptr<Identifier>($1),
											unique_ptr<ArgumentsList>($3));
									}
                                ;

arguments_list                  : /* empty arguments list */ {
										ArgumentsList* argsList = new ArgumentsList();
										$$ = argsList;
									}
                                | arguments_list COMMA argument {
										$1->add(shared_ptr<OperationExpression>($3));
										$$ = $1;
									}
                                | argument {
										ArgumentsList* argsList = new ArgumentsList();
										argsList->add(shared_ptr<OperationExpression>($1));

										$$ = argsList;
									}
                                ;

argument                        : operation_expression { $$ = $1; }
                                ;

variable_declaration_statement  : VAR variable_declaration_list delimiter {
										$$ = new VariableDeclarationStatement(
											unique_ptr<OperationExpressionsList>($2));
									}
                                ;

variable_declaration_list       : variable_declaration_list COMMA variable_declaration {
										$1->add(shared_ptr<OperationExpression>($3));

										$$ = $1;
									}
                                | variable_declaration {
										OperationExpressionsList* list = new OperationExpressionsList();
										list->add(shared_ptr<OperationExpression>($1));

										$$ = list;
									}
                                ;

variable_declaration            : assignment_expression { 
										$$ = $1;
									}
                                | IDENTIFIER {
										Primitive zeroPrimitive = Primitive(0, true);
										Variable zero = Variable(zeroPrimitive);

										$$ = new OperationExpressionAssignment(unique_ptr<Identifier>(new Identifier($1)),
												unique_ptr<OperationExpression>(new ConstantExpression(unique_ptr<Variable>(new Variable(zero)))));
									}
                                ;

function_declaration_statement  : FUNCTION_T IDENTIFIER OPEN_PARENTHESIS parameters_list CLOSE_PARENTHESIS function_body {
										Function* functionPtr = new Function(shared_ptr<ParametersList>($4),
											shared_ptr<StatementsList>($6));

										$$ = new FunctionDeclarationStatement(unique_ptr<Function>(functionPtr),
											unique_ptr<Identifier>(new Identifier($2)));

									}
                                | FUNCTION_T OPEN_PARENTHESIS parameters_list CLOSE_PARENTHESIS function_body {
										Function* functionPtr = new Function(shared_ptr<ParametersList>($3),
											shared_ptr<StatementsList>($5));

										$$ = new FunctionDeclarationStatement(unique_ptr<Function>(functionPtr));

									}
                                ;

parameters_list                 : /* empty parameters list */ {
										ParametersList* paramsList = new ParametersList();
										$$ = paramsList;
									}
                                | parameters_list COMMA IDENTIFIER {
										$1->add($3);
										$$ = $1;
									}
                                | IDENTIFIER {
										ParametersList* paramsList = new ParametersList();
										paramsList->add($1);

										$$ = paramsList;
									}
                                ;

function_body                   : OPEN_BRACE statements_list CLOSE_BRACE { $$ = $2; }
                                ;

return_statement                : RETURN operation_expression delimiter {
										$$ = new ReturnStatement(unique_ptr<OperationExpression>($2));
									}
								| RETURN delimiter {
										$$ = new ReturnStatement();
								}
                                ;

iteration_statement             : WHILE OPEN_PARENTHESIS operation_expression CLOSE_PARENTHESIS block {
										$$ = new IterationStatement(unique_ptr<OperationExpression>($3),
												unique_ptr<StatementsList>($5));
									}
                                ;

conditional_statement           : IF OPEN_PARENTHESIS operation_expression CLOSE_PARENTHESIS block %prec NO_ELSE {
										$$ = new ConditionalStatement(unique_ptr<OperationExpression>($3),
												unique_ptr<StatementsList>($5));
									}
					            | IF OPEN_PARENTHESIS operation_expression CLOSE_PARENTHESIS block ELSE block {
										$$ = new ConditionalStatement(unique_ptr<OperationExpression>($3),
												unique_ptr<StatementsList>($5), unique_ptr<StatementsList>($7));
									}
                                ;

block                           : OPEN_BRACE statements_list CLOSE_BRACE { 
										$$ = $2; 
									}
                                | statement {
										StatementsList* stmtsList = new StatementsList();
										stmtsList->add(unique_ptr<Statement>($1));

										$$ = stmtsList;
									}
                                ;

delimiter						: SEMICOLON
								;

identifier                      : identifier DOT IDENTIFIER {
										Identifier* id = new Identifier(*($1), $3);
										$$ = id;

										delete $1;
										delete [] $3;
									}
                                | identifier OPEN_BRACKET STRING_T CLOSE_BRACKET {
									Identifier* id;
									try{
										id = new Identifier(*($1), $3, true);
									}
									catch(InvalidIdentifierException e){
										cout<<", at line: "<<yylineno<<endl;
										exit(0);
									}
										
										$$ = id;

										delete $1;
										delete [] $3;
									}
                                | identifier OPEN_BRACKET INTEGER_T CLOSE_BRACKET {
                    					Identifier* id = new Identifier(*($1), $3);
        								$$ = id;

										delete $1;
                  					}
                                | IDENTIFIER {
										Identifier* id = new Identifier($1);
										$$ = id;

										delete [] $1;
									}
                                ;
%%
