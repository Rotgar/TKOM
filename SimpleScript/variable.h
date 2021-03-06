#ifndef VALUE_H_INCLUDED
#define VALUE_H_INCLUDED

#include <iostream>
#include <memory>

#include "identifier.h"
#include "primitive.h"
#include "object.h"
#include "function.h"

using namespace std;

typedef enum VariableTypes { PRIMITIVE, OBJECT, FUNCTION } ValueTypes;

class Object;
class Function;

class Variable {
    VariableTypes type;
    shared_ptr<Primitive> primitivePtr;
    shared_ptr<Object> objectPtr;
    shared_ptr<Function> functionPtr;

public:
    Variable():type(PRIMITIVE), primitivePtr(new Primitive()) {}
    Variable(Primitive p):type(PRIMITIVE), primitivePtr(new Primitive(p)) {}
    Variable(unique_ptr<Primitive> pPtr):type(PRIMITIVE), primitivePtr(move(pPtr)) {}
    Variable(unique_ptr<Object> oPtr):type(OBJECT), objectPtr(move(oPtr)) {}
    Variable(unique_ptr<Function> fPtr):type(FUNCTION), functionPtr(move(fPtr)) {}

    friend ostream& operator<< (ostream&, Variable);
    friend bool     operator== (const Variable&, const Variable&);
    friend bool     operator&= (const Variable&, const Variable&);
    friend bool     operator!= (const Variable&, const Variable&);
    friend bool     operator<  (const Variable&, const Variable&);
    friend bool     operator>  (const Variable&, const Variable&);
    friend bool     operator<= (const Variable&, const Variable&);
    friend bool     operator>= (const Variable&, const Variable&);

    operator bool() const;

    Variable& operator=  (const Variable&);

    Variable  operator+  (const Variable&) const;
    Variable  operator-  (const Variable&) const;
    Variable  operator*  (const Variable&) const;
    Variable  operator/  (const Variable&) const;
    Variable  operator-  () const;
    Variable  operator++ () const;
    Variable  operator-- () const;
    Variable  operator! () const;

    bool isPrimitive() const;
    bool isObject()const;
    bool isFunction()const;

    Primitive getPrimitive();
    Object getObject();
    Function getFunction();
};

#endif // VALUE_H_INCLUDED
