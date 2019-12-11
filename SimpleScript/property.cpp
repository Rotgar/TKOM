#include "property.h"
#include "variable.h"

int Property::elementCounter = 0;

void Property::setElementCounter(int val) {
	elementCounter = val;
}

int Property::getElementCounter() {
	return elementCounter;
}

bool Property::isOperationExpression() {
	return this->type == OPERATION_EXPRESSION_PROPERTY;
}

bool Property::isObjectLiteral() {
	return this->type == OBJECT_LITERAL_PROPERTY;
}

bool Property::isFunction() {
	return this->type == FUNCTION_PROPERTY;
}

string Property::getName() {
    return this->name;
}

Variable Property::evaluate(Object& scope) {
	if (this->isOperationExpression()) {
		return this->operationExpressionPtr->evaluate(scope);
	}
	else if (this->isObjectLiteral()) {
		return this->objectLiteralPtr->evaluate(scope);
	}
	else if (this->isFunction()) {
		return Variable(this->functionPtr);
	}
	else {
		return Variable();
	}
}

bool PropertyList::getIsArray(){
	return this->isArrayDeclaration;
}

void PropertyList::setIsArray(bool isArray){
	this->isArrayDeclaration = isArray;
}

Variable PropertyList::evaluate(Object& scope) {
	Object object;
	object.setArray(getIsArray()); // =[] lub ={} to differentiate object from list
	if(object.isArray()) {
		object.setArraySize(0);
	}

	for (std::list<shared_ptr<Property>>::iterator it = this->listPtr.begin(); it != this->listPtr.end(); ++it) {
		string propertyName = (*it)->getName();
		Identifier name(propertyName);
		Variable var = (*it)->evaluate(scope);

		if (var.isObject()) {
			object.getObject(name) = var.getObject();
		}
		else if (var.isFunction()) {
			object.getFunction(name) = var.getFunction();
		}
		else {
			object.getPrimitive(name) = var.getPrimitive();
		}
		if(object.isArray()) {
			if(stoi(propertyName) >= object.getArraySize()) {
				object.setArraySize(stoi(propertyName) + 1);
			}
		}
	}
	return Variable(shared_ptr<Object>(new Object(object)));
}

void PropertyList::add(shared_ptr<Property> property) {
    this->listPtr.push_back(property);
}

Variable ObjectLiteral::evaluate(Object& scope) {
	return this->propertyListPtr->evaluate(scope);
}
