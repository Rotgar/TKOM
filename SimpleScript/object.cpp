#include <stdexcept>
#include <iostream>
#include <regex>
#include <string>
#include <sstream>

#include "object.h"
#include "function.h"
#include "primitive.h"

ostream& Object::printArray(ostream& out, Object object) {
    stringstream stream;
    map<int, string> arrayValues;

    map<string, Primitive>::iterator it = object.primitives.begin();
    while(it != object.primitives.end()) {
        stream<<it->second;
        arrayValues.insert(pair<int, string>(stoi(it->first), stream.str()));
        ++it;
        stream.str("");
    }

    map<string, Object>::iterator oit = object.objects.begin();
    while(oit != object.objects.end()) {
        stream<<oit->second;
        arrayValues.insert(pair<int, string>(stoi(oit->first), stream.str()));
        ++oit;
        stream.str("");
    }

    map<string, Function>::iterator fit = object.functions.begin();
    while(fit != object.functions.end()) {
        stream<<fit->second;
        arrayValues.insert(pair<int, string>(stoi(fit->first), stream.str()));
        ++fit;
        stream.str("");
    }

    out << "[ ";

    int positionChecker = 0;
    map<int, string>::iterator ait = arrayValues.begin();
    while(ait != arrayValues.end()) {
        if(ait != arrayValues.begin()) 
            out << ", ";
        if(ait->first != positionChecker){
            out << "\"empty\"";
        } else{
            out << ait->second;
            ++ait;
        }
        ++positionChecker;
    }
    return out << " ]";
}

ostream& operator<< (ostream& out, Object object) {
    if (object.isArray()) {
        return object.printArray(out, object);
    }

    out << "{ ";

    map<string, Primitive>::iterator it = object.primitives.begin();
    while(it != object.primitives.end()) {
        if(it != object.primitives.begin()) out << ", ";
        out << it->first << ": " << it->second;
        ++it;
    }
    map<string, Object>::iterator oit = object.objects.begin();

    while(oit != object.objects.end()) {
        if(oit != object.objects.begin()
           || !object.primitives.empty()) out << ", ";
        out << oit->first << ": " << oit->second;
        ++oit;
    }
    map<string, Function>::iterator fit = object.functions.begin();
    while(fit != object.functions.end()) {
        if(fit != object.functions.begin() || !object.primitives.empty()
           || !object.objects.empty()) out << ", ";
        out << fit->first << ": " << fit->second;
        ++fit;
    }
    return out << " }";
}

bool Object::hasObjectProperty(string propertyName) {
    map<string, Object>::iterator it =
            this->objects.find(propertyName);

    return it != this->objects.end();
}

Object& Object::getObject(Identifier identifier) {
    if(!identifier.hasTail()) {
        return this->objects[identifier.getHead()];
    }

    if(!this->hasObjectProperty(identifier.getHead())) {
        throw InvalidIdentifierException("Object doesn't have property with given name");
    }

    return this->objects[identifier.getHead()]
                .getObject(identifier.getTail());
}

Object& Object::getObjectWithID(Identifier identifier) {
    if(!identifier.hasTail()){
        return this->objects[identifier.getHead()];
    }

    if(!identifier.getTail().hasTail()){
        return this->objects[identifier.getHead()];
    }

    if(!this->hasObjectProperty(identifier.getHead())) {
        throw InvalidIdentifierException("Object doesn't have property with given name");
    }

    return this->objects[identifier.getHead()]
                .getObjectWithID(identifier.getTail());
}

Function& Object::getFunction(Identifier identifier) {
    if(!identifier.hasTail()) {
        return this->functions[identifier.getHead()];
    }

    if(!this->hasObjectProperty(identifier.getHead())) {
        throw InvalidIdentifierException("Object doesn't have property with given name");
    }

    return this->objects[identifier.getHead()]
                .getFunction(identifier.getTail());
}

Primitive& Object::getPrimitive(Identifier identifier) {
    if(!identifier.hasTail()) {
        return this->primitives[identifier.getHead()];
    }

    if(!this->hasObjectProperty(identifier.getHead())) {
        throw InvalidIdentifierException("Object doesn't have property with given name");
    }

    return this->objects[identifier.getHead()]
            .getPrimitive(identifier.getTail());
}

void Object::removeObject(Identifier identifier) {
    if(!identifier.hasTail()) {
        this->objects.erase(identifier.getHead());
        return;
    } else if(this->hasObjectProperty(identifier.getHead())) {
        return this->objects[identifier.getHead()]
            .removeObject(identifier.getTail());
    }
}

void Object::removeFunction(Identifier identifier) {
    if(!identifier.hasTail()) {
        this->functions.erase(identifier.getHead());
        return;
    } else if(this->hasObjectProperty(identifier.getHead())) {
        return this->objects[identifier.getHead()]
            .removeFunction(identifier.getTail());
    }
}

void Object::removePrimitive(Identifier identifier) {
    if(!identifier.hasTail()) {
        this->primitives.erase(identifier.getHead());
        return;
    } else if(this->hasObjectProperty(identifier.getHead())) {
        return this->objects[identifier.getHead()]
            .removePrimitive(identifier.getTail());
    }
}

bool Object::hasObject(Identifier identifier) {
    if(!identifier.hasTail()) {
        return this->objects.find(identifier.getHead()) != this->objects.end();
    }

    if(!this->hasObjectProperty(identifier.getHead())) {
        return false;
    }

    return this->objects[identifier.getHead()].hasObject(identifier.getTail());
}

bool Object::isObject(Identifier id) {
    if(!id.hasTail()) {
        return false;
    }

    if(!id.getTail().hasTail()) {
        return this->objects.find(id.getHead()) != this->objects.end();
    }

    if(!this->hasObjectProperty(id.getHead())) {
        return false;
    }

    return this->objects[id.getHead()].isObject(id.getTail());
}

bool Object::hasFunction(Identifier identifier) {
    if(!identifier.hasTail()) {
        return this->functions.find(identifier.getHead()) != this->functions.end();
    }

    if(!this->hasObjectProperty(identifier.getHead())) {
         return false;
    }

    return this->objects[identifier.getHead()]
                .hasFunction(identifier.getTail());
}

bool Object::hasPrimitive(Identifier identifier) {
    if(!identifier.hasTail()) {
        return this->primitives.find(identifier.getHead()) != this->primitives.end();
    }

    if(!this->hasObjectProperty(identifier.getHead())) {
        return false;
    }

    return this->objects[identifier.getHead()]
            .hasPrimitive(identifier.getTail());
}

bool Object::isArray() {
    return this->isObjectArray;
}

void Object::setArray(bool isArray) {
    this->isObjectArray = isArray;
}

int Object::getArraySize() {
    return this->arraySize;
}

void Object::setArraySize(int size) {
    this->arraySize = size;
}
