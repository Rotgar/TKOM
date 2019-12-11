#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <map>
#include <string>

#include "function.h"
#include "identifier.h"
#include "primitive.h"

using namespace std;

class Function;

class Object {
    map<string, Object> objects;
    map<string, Function> functions;
    map<string, Primitive> primitives;

    bool hasObjectProperty(string);
    bool isObjectArray;
    int arraySize;

public:

    bool hasObject(Identifier);
    bool hasFunction(Identifier);
    bool hasPrimitive(Identifier);

    friend ostream& operator<< (ostream&, Object);
    ostream& printArray(ostream&, Object);

    Object& getObject(Identifier);
    Object& getObjectWithID(Identifier);
    Function& getFunction(Identifier);
    Primitive& getPrimitive(Identifier);

    void removeObject(Identifier);
    void removeFunction(Identifier);
    void removePrimitive(Identifier);

    bool isObject(Identifier);
    bool isArray();
    void setArray(bool);
    int getArraySize();
    void setArraySize(int);
};

#endif // OBJECT_H_INCLUDED
