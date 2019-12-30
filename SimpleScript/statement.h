#ifndef STATEMENT_H_INCLUDED
#define STATEMENT_H_INCLUDED

#include <iostream>
#include <memory>
#include <list>
using namespace std;

#include "object.h"
#include "operation_expression.h"
#include "exception.h"
#include "function.h"

class Object;
class Function;
class OperationExpression;
class OperationExpressionsList;
class IdentifierExpression;

class Statement {
public:
    virtual void evaluate(Object&) = 0;
};

class StatementsList {
    list<unique_ptr<Statement>> statements;

public:
	void evaluate(Object&);

    void add(unique_ptr<Statement>);
};

class ConditionalStatement : public Statement {
    unique_ptr<OperationExpression> conditionExpressionPtr;

	unique_ptr<StatementsList> trueStatementListPtr;
	unique_ptr<StatementsList> falseStatementListPtr;

public:
    ConditionalStatement(unique_ptr<OperationExpression> oePtr,
		unique_ptr<StatementsList> trueStmtListPtr, unique_ptr<StatementsList> falseStmtListPtr)
            : conditionExpressionPtr(move(oePtr)), trueStatementListPtr(move(trueStmtListPtr)),
			falseStatementListPtr(move(falseStmtListPtr)) {}

    ConditionalStatement(unique_ptr<OperationExpression> oePtr, unique_ptr<StatementsList> trueStmtListPtr)
        : conditionExpressionPtr(move(oePtr)), trueStatementListPtr(move(trueStmtListPtr)), falseStatementListPtr(nullptr) {}

	virtual void evaluate(Object&);
};

class IterationStatement : public Statement {
    unique_ptr<OperationExpression> conditionExpressionPtr;
	unique_ptr<StatementsList> statementsListPtr;

public:
    IterationStatement(unique_ptr<OperationExpression> conditionExprPtr, unique_ptr<StatementsList> stmtsListPtr)
        : conditionExpressionPtr(move(conditionExprPtr)), statementsListPtr(move(stmtsListPtr)) {}

	virtual void evaluate(Object&);
};

class ReturnStatement : public Statement {
    unique_ptr<OperationExpression> expressionPtr;

public:
    ReturnStatement(unique_ptr<OperationExpression> exprPtr)
        : expressionPtr(move(exprPtr)) {}
	
	ReturnStatement()
        : expressionPtr(nullptr) {}

	virtual void evaluate(Object&);
};

class FunctionDeclarationStatement : public Statement {
    unique_ptr<Function> functionPtr;
	unique_ptr<Identifier> identifierPtr;

public:
    FunctionDeclarationStatement(unique_ptr<Function> functPtr, unique_ptr<Identifier> idPtr)
        : functionPtr(move(functPtr)), identifierPtr(move(idPtr)) {}

	FunctionDeclarationStatement(unique_ptr<Function> functPtr)
		: functionPtr(move(functPtr)), identifierPtr(nullptr) {}

	virtual void evaluate(Object&);
	Function getFunction();
};

class ExpressionStatement : public Statement {
    unique_ptr<OperationExpression> operationExpressionPtr;

public:
	ExpressionStatement(unique_ptr<OperationExpression> opExprPtr)
        : operationExpressionPtr(move(opExprPtr)) {}

	virtual void evaluate(Object&);
};

class VariableDeclarationStatement : public Statement {
    unique_ptr<OperationExpressionsList> operationExpressionsListPtr;

public:
	VariableDeclarationStatement(unique_ptr<OperationExpressionsList> opExprListPtr)
        : operationExpressionsListPtr(move(opExprListPtr)) {}

	virtual void evaluate(Object&);
};

class LogStatement : public Statement {
	unique_ptr<IdentifierExpression> identifierExpressionPtr;

public:
	LogStatement(unique_ptr<IdentifierExpression> iePtr)
		: identifierExpressionPtr(move(iePtr)) {}

	virtual void evaluate(Object&);
};

#endif // STATEMENT_H_INCLUDED
