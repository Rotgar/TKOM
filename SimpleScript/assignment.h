#ifndef ASSIGNMENT_H_INCLUDED
#define ASSIGNMENT_H_INCLUDED

#include <memory>
using namespace std;

#include "object.h"
#include "function.h"
#include "variable.h"
#include "operation_expression.h"
#include "property.h"

class OperationExpressionAssignment : public OperationExpression {
	unique_ptr<Identifier> identifierPtr;
    unique_ptr<OperationExpression> expressionPtr;

public:
    OperationExpressionAssignment(unique_ptr<Identifier> idPtr, unique_ptr<OperationExpression> ePtr)
        : identifierPtr(move(idPtr)), expressionPtr(move(ePtr)) {}

    Variable evaluate(Object&) const;
};

class FunctionAssignment : public OperationExpression {
	unique_ptr<Identifier> identifierPtr;
    Function funct;

public:
    FunctionAssignment(unique_ptr<Identifier> idPtr, Function f)
        : identifierPtr(move(idPtr)), funct(f) {}

	Variable evaluate(Object&) const;
};

class ObjectLiteralAssignment : public OperationExpression {
	unique_ptr<Identifier> identifierPtr;
	unique_ptr<ObjectLiteral> objectLiteralPtr;

public:
	ObjectLiteralAssignment(unique_ptr<Identifier> idPtr, unique_ptr<ObjectLiteral> olPtr)
        : identifierPtr(move(idPtr)), objectLiteralPtr(move(olPtr)) {}

	Variable evaluate(Object&) const;
};

class ArrayPushExpressionAssignment: public OperationExpression {
    unique_ptr<Identifier> identifierPtr;
    unique_ptr<Property> propertyPtr;

public:
	ArrayPushExpressionAssignment(unique_ptr<Identifier> idPtr, unique_ptr<Property> ePtr)
        : identifierPtr(move(idPtr)), propertyPtr(move(ePtr)) {}

	Variable evaluate(Object&) const;
};

#endif // ASSIGNMENT_H_INCLUDED
