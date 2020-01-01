#define BOOLEAN_TRUE "true"
#define BOOLEAN_FALSE "false"

#define QUOTATION "\""

#include "primitive.h"

bool Primitive::isInteger() {
	return this->type == INTEGER;
}

bool Primitive::isFloat() {
	return this->type == FLOAT;
}

bool Primitive::isBoolean() {
	return this->type == BOOLEAN;
}

bool Primitive::isString() {
	return this->type == STRING;
}

int Primitive::getInteger() {
	return this->intVal;
}

float Primitive::getFloat() {
	return this->floatVal;
}

bool Primitive::getBoolean() {
	return this->boolVal;
}

string Primitive::getString() {
	return this->stringVal;
}

ostream& operator<<(ostream& out, const Primitive& primitive) {
    if(primitive.type == INTEGER) {
        return out << primitive.intVal;
    } else if (primitive.type == FLOAT) {
        return out << primitive.floatVal;
    } else if (primitive.type == BOOLEAN) {
		if (primitive.boolVal) return out << BOOLEAN_TRUE;
		else return out << BOOLEAN_FALSE;
    } else if (primitive.type == STRING) {
        return out << QUOTATION << primitive.stringVal << QUOTATION;
    } else return out;
}

bool operator==(const Primitive& primitive1, const Primitive& primitive2) {
    if(primitive1.type == INTEGER && primitive2.type == INTEGER) {
        return primitive1.intVal == primitive2.intVal;
    } else if (primitive1.type == FLOAT && primitive2.type == INTEGER) {
        return primitive1.floatVal == primitive2.intVal;
    } else if (primitive1.type == INTEGER && primitive2.type == FLOAT) {
        return primitive1.intVal == primitive2.floatVal;
    } else if (primitive1.type == FLOAT && primitive2.type == FLOAT) {
        return primitive1.floatVal == primitive2.floatVal;
    } else if (primitive1.type == BOOLEAN && primitive2.type == BOOLEAN) {
        return primitive1.boolVal == primitive2.boolVal;
    } else if (primitive1.type == STRING && primitive2.type == STRING) {
        return primitive1.stringVal == primitive2.stringVal;
    } else if (primitive1.type == STRING && primitive2.type == INTEGER) {
        return stoi(primitive1.stringVal) == primitive2.intVal;
    } else if (primitive1.type == INTEGER && primitive2.type == STRING) {
        return primitive1.intVal == stoi(primitive2.stringVal);
    } else if (primitive1.type == INTEGER && primitive2.type == BOOLEAN) {
        return (primitive1.intVal == 1 && primitive2.boolVal == true)
        || (primitive1.intVal == 0 && primitive2.boolVal == false);
    } else if (primitive1.type == BOOLEAN && primitive2.type == INTEGER) {
        return (primitive1.boolVal == true && primitive2.intVal == 1)
        || (primitive1.boolVal == false && primitive2.intVal == 0);
    } else return false;
}

bool operator&=(const Primitive& primitive1, const Primitive& primitive2) {
    if ( primitive1.type != primitive2.type) {
        return false;
    } else {
        return primitive1 == primitive2;
    }
}

bool operator!=(const Primitive& primitive1, const Primitive& primitive2) {
    return !(primitive1 == primitive2);
}

bool operator>(const Primitive& primitive1, const Primitive& primitive2) {
    if(primitive1.type == INTEGER && primitive2.type == INTEGER) {
        return primitive1.intVal > primitive2.intVal;
    } else if (primitive1.type == FLOAT && primitive2.type == INTEGER) {
        return primitive1.floatVal > primitive2.intVal;
    } else if (primitive1.type == INTEGER && primitive2.type == FLOAT) {
        return primitive1.intVal > primitive2.floatVal;
    } else if (primitive1.type == FLOAT && primitive2.type == FLOAT) {
        return primitive1.floatVal > primitive2.floatVal;
    } else if (primitive1.type == BOOLEAN && primitive2.type == BOOLEAN) {
        return primitive1.boolVal > primitive2.boolVal;
    }  else if (primitive1.type == STRING && primitive2.type == STRING) {
        return primitive1.stringVal > primitive2.stringVal;
    } else return false;
}

bool operator<(const Primitive& primitive1, const Primitive& primitive2) {
    if(primitive1.type == INTEGER && primitive2.type == INTEGER) {
        return primitive1.intVal < primitive2.intVal;
    } else if (primitive1.type == FLOAT && primitive2.type == INTEGER) {
        return primitive1.floatVal < primitive2.intVal;
    } else if (primitive1.type == INTEGER && primitive2.type == FLOAT) {
        return primitive1.intVal < primitive2.floatVal;
    } else if (primitive1.type == FLOAT && primitive2.type == FLOAT) {
        return primitive1.floatVal < primitive2.floatVal;
    } else if (primitive1.type == BOOLEAN && primitive2.type == BOOLEAN) {
        return primitive1.boolVal < primitive2.boolVal;
    }  else if (primitive1.type == STRING && primitive2.type == STRING) {
        return primitive1.stringVal < primitive2.stringVal;
    } else return false;
}

bool operator<=(const Primitive& primitive1, const Primitive& primitive2) {
    return !(primitive1 > primitive2);
}

bool operator>=(const Primitive& primitive1, const Primitive& primitive2) {
    return !(primitive1 < primitive2);
}

Primitive& Primitive::operator=(const Primitive& primitive) {
    this->type = primitive.type;

    if(this->type == INTEGER) {
        this->intVal = primitive.intVal;
    } else if(this->type == FLOAT) {
        this->floatVal = primitive.floatVal;
    } else if(this->type == BOOLEAN) {
        this->boolVal = primitive.boolVal;
    } else if(this->type == STRING) {
        this->stringVal = primitive.stringVal;
    }
    return *this;
}

Primitive Primitive::operator+(const Primitive& primitive) const {
    if(this->type == INTEGER && primitive.type == INTEGER) {
        return Primitive(this->intVal + primitive.intVal);
    } else if (this->type == FLOAT && primitive.type == INTEGER) {
        return Primitive(this->floatVal + primitive.intVal);
    } else if (this->type == INTEGER && primitive.type == FLOAT) {
        return Primitive(this->intVal + primitive.floatVal);
    } else if (this->type == FLOAT && primitive.type == FLOAT) {
        return Primitive(this->floatVal + primitive.floatVal);
    } else if (this->type == STRING && primitive.type == STRING) {
        return Primitive(this->stringVal + primitive.stringVal);
    } else if (this->type == INTEGER && primitive.type == STRING) {
        return Primitive(to_string(this->intVal) + primitive.stringVal);
    } else if (this->type == STRING && primitive.type == INTEGER) {
        return Primitive(this->stringVal + to_string(primitive.intVal));
    } else if (this->type == BOOLEAN && primitive.type == BOOLEAN) {
        if(this->boolVal == true && primitive.boolVal == true){
            return Primitive(2);
        } else if(this->boolVal == false && primitive.boolVal == false){
            return Primitive(0);
        } else return Primitive(1);
    } else return Primitive();
}

Primitive Primitive::operator-(const Primitive& primitive) const {
    if(this->type == INTEGER && primitive.type == INTEGER) {
        return Primitive(this->intVal - primitive.intVal);
    } else if (this->type == FLOAT && primitive.type == INTEGER) {
        return Primitive(this->floatVal - primitive.intVal);
    } else if (this->type == INTEGER && primitive.type == FLOAT) {
        return Primitive(this->intVal - primitive.floatVal);
    } else if (this->type == FLOAT && primitive.type == FLOAT) {
        return Primitive(this->floatVal - primitive.floatVal);
    } else return Primitive();
}

Primitive Primitive::operator*(const Primitive& primitive) const {
    if(this->type == INTEGER && primitive.type == INTEGER) {
        return Primitive(this->intVal * primitive.intVal);
    } else if (this->type == FLOAT && primitive.type == INTEGER) {
        return Primitive(this->floatVal * primitive.intVal);
    } else if (this->type == INTEGER && primitive.type == FLOAT) {
        return Primitive(this->intVal * primitive.floatVal);
    } else if (this->type == FLOAT && primitive.type == FLOAT) {
        return Primitive(this->floatVal * primitive.floatVal);
    } else return Primitive();
}

Primitive Primitive::operator/(const Primitive& primitive) const {
    if(this->type == INTEGER && primitive.type == INTEGER) {
        return Primitive(this->intVal / primitive.intVal);
    } else if (this->type == FLOAT && primitive.type == INTEGER) {
        return Primitive(this->floatVal / primitive.intVal);
    } else if (this->type == INTEGER && primitive.type == FLOAT) {
        return Primitive(this->intVal / primitive.floatVal);
    } else if (this->type == FLOAT && primitive.type == FLOAT) {
        return Primitive(this->floatVal / primitive.floatVal);
    } else return Primitive();
}

Primitive Primitive::operator-() const {
   if (this->type == INTEGER) {
      return Primitive(-intVal);
   } else if (this->type == FLOAT) {
      return Primitive(-floatVal);
   } else return Primitive();
}

Primitive Primitive::operator++() const {
   if (this->type == INTEGER) {
      return Primitive(intVal + 1);
   } else if (this->type == FLOAT) {
      return Primitive(floatVal + 1);
   } else return Primitive();
}

Primitive Primitive::operator--() const {
   if (this->type == INTEGER) {
      return Primitive(intVal - 1);
   } else if (this->type == FLOAT) {
      return Primitive(floatVal - 1);
   } else return Primitive();
}

Primitive Primitive::operator!() const {
   if (this->type == BOOLEAN) {
      return Primitive(!boolVal);
   } else return Primitive();
}

Primitive::operator bool() const {
    if(this->type == BOOLEAN) {
        return this->boolVal;
    } else if (this->type == INTEGER) {
        return this->intVal > 0;
    } else if (this->type == FLOAT) {
        return this->floatVal > 0;
    } else return false;
}
