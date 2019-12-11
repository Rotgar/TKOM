#include <memory>
using namespace std;

#include "object.h"
#include "function.h"
#include "variable.h"
#include "operation_expression.h"
#include "assignment.h"
#include "property.h"

#define NUMBER_REGEX "[0-9]+"

bool checkRegex(string value){
    regex identifierRegex(NUMBER_REGEX);
    return regex_match(value, identifierRegex);
}

void handleArray(shared_ptr<Identifier> identifierPtr, Object& scope){
    if(scope.isObject(*(identifierPtr))){
        Object& id = scope.getObjectWithID(*(identifierPtr));
        if(id.isArray()){
            if(!checkRegex(identifierPtr->getLastId())) {
                throw InvalidIdentifierException("Error! Trying to add literal as position");
            }
            int potentialSize = stoi(identifierPtr->getLastId());
            if(potentialSize > id.getArraySize()) {
                id.setArraySize(potentialSize + 1);
            }
        } else {
            if(checkRegex(identifierPtr->getLastId())) {
                throw InvalidIdentifierException("Error! Trying to add number property to object");
            }
        }
    }
}

Variable OperationExpressionAssignment::evaluate(Object& scope) const {
    Variable var = this->expressionPtr->evaluate(scope);
    handleArray(this->identifierPtr, scope);
    
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
    handleArray(this->identifierPtr, scope);

    scope.getFunction(*(this->identifierPtr)) = this->funct;
    scope.removeObject(*(this->identifierPtr));
    scope.removePrimitive(*(this->identifierPtr));

	return Variable(shared_ptr<Function>(new Function(this->funct)));
}

Variable ObjectLiteralAssignment::evaluate(Object& scope) const {
	Variable var = this->objectLiteralPtr->evaluate(scope);
    handleArray(this->identifierPtr, scope);

    scope.getObject(*(this->identifierPtr)) = var.getObject();
    scope.removePrimitive(*(this->identifierPtr));
    scope.removeFunction(*(this->identifierPtr));

    return var;
}

Variable ArrayPushExpressionAssignment::evaluate(Object& scope) const {
    Variable var = this->propertyPtr->evaluate(scope);

    Object& id = scope.getObject(*(this->identifierPtr));
    if(!id.isArray()){
        throw InvalidIdentifierException("push() can only be used on array");
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