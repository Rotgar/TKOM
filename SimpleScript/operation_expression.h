#ifndef OPERATION_EXPRESSION_H_INCLUDED
#define OPERATION_EXPRESSION_H_INCLUDED

#include <iostream>
#include <memory>

#include "object.h"
#include "variable.h"
#include "function.h"
#include "exception.h"

using namespace std;

class Object;
class Variable;
class Function;
class ArgumentsList;
class Identifier;

class OperationExpression {
public:
    virtual Variable evaluate(Object&) const = 0;
};

class OperationExpressionsList {
	list<shared_ptr<OperationExpression>> operationExpressionsList;

public:
	void add(shared_ptr<OperationExpression>);
	list<shared_ptr<OperationExpression>>::iterator begin();
	list<shared_ptr<OperationExpression>>::iterator end();

	size_t size() const;
	void evaluate(Object&);
};

class UnaryOperationExpression : public OperationExpression {
public:
    virtual Variable evaluate(Object&) const = 0;
    UnaryOperationExpression(unique_ptr<OperationExpression> ePtr)
        : expressionPtr(move(ePtr)) {}

protected:
    unique_ptr<OperationExpression> expressionPtr;
};

class BinaryOperationExpression : public OperationExpression {
public:
    virtual Variable evaluate(Object&) const = 0;
    BinaryOperationExpression(unique_ptr<OperationExpression> e1Ptr, unique_ptr<OperationExpression> e2Ptr)
        : expression1Ptr(move(e1Ptr)), expression2Ptr(move(e2Ptr)) {}

protected:
    unique_ptr<OperationExpression> expression1Ptr;
    unique_ptr<OperationExpression> expression2Ptr;
};

class ConstantExpression : public OperationExpression {
    unique_ptr<Variable> variablePtr;

public:
    ConstantExpression(unique_ptr<Variable> varPtr): variablePtr(move(varPtr)) {}
    virtual Variable evaluate(Object&) const;
};

class IdentifierExpression : public OperationExpression {
	unique_ptr<Identifier> identifierPtr;

public:
    IdentifierExpression(unique_ptr<Identifier> idPtr) 
		: identifierPtr(move(idPtr)) {}

    virtual Variable evaluate(Object&) const;
};

class ArraySizeExpression : public OperationExpression {
    unique_ptr<Identifier> identifierPtr;

public:
    ArraySizeExpression(unique_ptr<Identifier> idPtr) 
		: identifierPtr(move(idPtr)) {}

    virtual Variable evaluate(Object&) const;
};

class FunctionCallExpression : public OperationExpression {
	shared_ptr<Identifier> identifierPtr;
	shared_ptr<ArgumentsList> argumentsPtr;

public:
	FunctionCallExpression(unique_ptr<Identifier> idPtr,
		unique_ptr<ArgumentsList> args)
		: identifierPtr(move(idPtr)), argumentsPtr(move(args)) {}

	virtual Variable evaluate(Object&) const;
};

class Negation : public UnaryOperationExpression {
public:
    Negation(unique_ptr<OperationExpression> ePtr)
        : UnaryOperationExpression(move(ePtr)) {}
    virtual Variable evaluate(Object&) const;
};

class LogicalNot : public UnaryOperationExpression {
public:
    LogicalNot(unique_ptr<OperationExpression> ePtr)
        : UnaryOperationExpression(move(ePtr)) {}
    virtual Variable evaluate(Object&) const;
};

class Addition : public BinaryOperationExpression {
public:
    Addition(unique_ptr<OperationExpression> e1Ptr, unique_ptr<OperationExpression> e2Ptr)
        : BinaryOperationExpression(move(e1Ptr), move(e2Ptr)) {}
    virtual Variable evaluate(Object&) const;
};

class Subtraction : public BinaryOperationExpression {
public:
    Subtraction (unique_ptr<OperationExpression> e1Ptr, unique_ptr<OperationExpression> e2Ptr)
        : BinaryOperationExpression(move(e1Ptr), move(e2Ptr)) {}
    virtual Variable evaluate(Object&) const;
};

class Multiplication : public BinaryOperationExpression {
public:
    Multiplication(unique_ptr<OperationExpression> e1Ptr, unique_ptr<OperationExpression> e2Ptr)
        : BinaryOperationExpression(move(e1Ptr), move(e2Ptr)) {}
    virtual Variable evaluate(Object&) const;
};

class Division : public BinaryOperationExpression {
public:
    Division(unique_ptr<OperationExpression> e1Ptr, unique_ptr<OperationExpression> e2Ptr)
        : BinaryOperationExpression(move(e1Ptr), move(e2Ptr)) {}
    virtual Variable evaluate(Object&) const;
};

class LessThan : public BinaryOperationExpression {
public:
    LessThan(unique_ptr<OperationExpression> e1Ptr, unique_ptr<OperationExpression> e2Ptr)
        : BinaryOperationExpression(move(e1Ptr), move(e2Ptr)) {}
    virtual Variable evaluate(Object&) const;
};

class GreaterThan : public BinaryOperationExpression {
public:
    GreaterThan(unique_ptr<OperationExpression> e1Ptr, unique_ptr<OperationExpression> e2Ptr)
        : BinaryOperationExpression(move(e1Ptr), move(e2Ptr)) {}
    virtual Variable evaluate(Object&) const;
};

class LessThanOrEqualTo : public BinaryOperationExpression {
public:
    LessThanOrEqualTo(unique_ptr<OperationExpression> e1Ptr, unique_ptr<OperationExpression> e2Ptr)
        : BinaryOperationExpression(move(e1Ptr), move(e2Ptr)) {}
    virtual Variable evaluate(Object&) const;
};

class GreaterThanOrEqualTo : public BinaryOperationExpression {
public:
    GreaterThanOrEqualTo(unique_ptr<OperationExpression> e1Ptr, unique_ptr<OperationExpression> e2Ptr)
        : BinaryOperationExpression(move(e1Ptr), move(e2Ptr)) {}
    virtual Variable evaluate(Object&) const;
};

class Equals : public BinaryOperationExpression {
public:
    Equals(unique_ptr<OperationExpression> e1Ptr, unique_ptr<OperationExpression> e2Ptr)
        : BinaryOperationExpression(move(e1Ptr), move(e2Ptr)) {}
    virtual Variable evaluate(Object&) const;
};

class EqualsType : public BinaryOperationExpression {
public:
    EqualsType(unique_ptr<OperationExpression> e1Ptr, unique_ptr<OperationExpression> e2Ptr)
        : BinaryOperationExpression(move(e1Ptr), move(e2Ptr)) {}
    virtual Variable evaluate(Object&) const;
};

class NotEquals : public BinaryOperationExpression {
public:
    NotEquals(unique_ptr<OperationExpression> e1Ptr, unique_ptr<OperationExpression> e2Ptr)
        : BinaryOperationExpression(move(e1Ptr), move(e2Ptr)) {}
    virtual Variable evaluate(Object&) const;
};

class LogicalOr : public BinaryOperationExpression {
public:
    LogicalOr(unique_ptr<OperationExpression> e1Ptr, unique_ptr<OperationExpression> e2Ptr)
        : BinaryOperationExpression(move(e1Ptr), move(e2Ptr)) {}
    virtual Variable evaluate(Object&) const;
};

class LogicalAnd : public BinaryOperationExpression {
public:
    LogicalAnd(unique_ptr<OperationExpression> e1Ptr, unique_ptr<OperationExpression> e2Ptr)
        : BinaryOperationExpression(move(e1Ptr), move(e2Ptr)) {}
    virtual Variable evaluate(Object&) const;
};

#endif // OPERATION_EXPRESSION_H_INCLUDED
