#include <memory>
using namespace std;

#include "object.h"
#include "function.h"
#include "variable.h"
#include "operation_expression.h"
#include "assignment.h"
#include "property.h"

#define IDENTIFIER_REGEX "[0-9]+"

bool checkRegex(string value){
    regex identifierRegex(IDENTIFIER_REGEX);
    return regex_match(value, identifierRegex);
}

Variable OperationExpressionAssignment::evaluate(Object& scope) const {
    Variable var = this->expressionPtr->evaluate(scope);

    if(scope.isObject(*(this->identifierPtr))){
        Object id = scope.getObjectWithID(*(this->identifierPtr));
        if(id.isArray()){
            if(!checkRegex(this->identifierPtr->getLastId())) {
                throw invalid_argument("trying to add literal as position");
            }
        } else {
            if(checkRegex(this->identifierPtr->getLastId())) {
                throw invalid_argument("trying to add position to object");
            }
        }
    }

    if(var.isPrimitive()) {
        scope.getPrimitive(*(this->identifierPtr)) = var.getPrimitive();

        scope.removeObject(*(this->identifierPtr));
        scope.removeFunction(*(this->identifierPtr));
    } else if(var.isObject()) {
        scope.getObject(*(this->identifierPtr)) = var.getObject();

        scope.removePrimitive(*(this->identifierPtr));
        scope.removeFunction(*(this->identifierPtr));
    } else if(var.isFunction()) {
        scope.getFunction(*(this->identifierPtr)) = var.getFunction();

        scope.removePrimitive(*(this->identifierPtr));
        scope.removeObject(*(this->identifierPtr));
    }
	return var;
}

Variable FunctionAssignment::evaluate(Object& scope) const {
    scope.getFunction(*(this->identifierPtr)) = this->funct;
    scope.removeObject(*(this->identifierPtr));
    scope.removePrimitive(*(this->identifierPtr));

	return Variable(shared_ptr<Function>(new Function(this->funct)));
}

Variable ObjectLiteralAssignment::evaluate(Object& scope) const {
	Variable var = this->objectLiteralPtr->evaluate(scope);

    scope.getObject(*(this->identifierPtr)) = var.getObject();
    scope.removePrimitive(*(this->identifierPtr));
    scope.removeFunction(*(this->identifierPtr));

    return var;
}

Variable ArrayPushExpressionAssignment::evaluate(Object& scope) const {
    Variable var = this->propertyPtr->evaluate(scope);

    Object& id = scope.getObjectWithID(*(this->identifierPtr));
    if(!id.isArray()){
        throw invalid_argument("push() can only be used on array");
    }
    Identifier* pushedElem = new Identifier(*(this->identifierPtr), to_string(id.getArraySize()));
    id.setArraySize(id.getArraySize() + 1);
    if(var.isPrimitive()) {
        scope.getPrimitive(*(pushedElem)) = var.getPrimitive();

        scope.removeObject(*(pushedElem));
        scope.removeFunction(*(pushedElem));
    } else if(var.isObject()) {
        scope.getObject(*(pushedElem)) = var.getObject();

        scope.removePrimitive(*(pushedElem));
        scope.removeFunction(*(pushedElem));
    } else if(var.isFunction()) {
        scope.getFunction(*(pushedElem)) = var.getFunction();

        scope.removePrimitive(*(pushedElem));
        scope.removeObject(*(pushedElem));
    }
	return var;
}