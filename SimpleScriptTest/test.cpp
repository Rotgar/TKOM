#include "pch.h"
#include "../SimpleScript/primitive.h"
#include "../SimpleScript/primitive.cpp"
#include "../SimpleScript/identifier.h"
#include "../SimpleScript/identifier.cpp"
#include "../SimpleScript/object.h"
#include "../SimpleScript/object.cpp"
#include "../SimpleScript/function.h"
#include "../SimpleScript/function.cpp"
#include "../SimpleScript/variable.h"
#include "../SimpleScript/variable.cpp"
#include "../SimpleScript/exception.h"
#include "../SimpleScript/exception.cpp"
#include "../SimpleScript/operation_expression.h"
#include "../SimpleScript/operation_expression.cpp"
#include "../SimpleScript/statement.h"
#include "../SimpleScript/statement.cpp"
#include "../SimpleScript/assignment.h"
#include "../SimpleScript/assignment.cpp"
#include "../SimpleScript/property.h"
#include "../SimpleScript/property.cpp"
#include "../SimpleScript/program.h"
#include "../SimpleScript/program.cpp"
#include "../SimpleScript/SimpleScript.tab.h"
#include "../SimpleScript/SimpleScript.tab.c"
#include "../SimpleScript/lex.yy.c"

#include <iostream>
#include <string>
#include <memory>
using namespace std;

extern int yyparse();
extern Variable _PARSE_RESULT;
extern string _ERROR_MESSAGE;

#define INTEGER_VALUE_A 12
#define INTEGER_VALUE_B 81
#define INTEGER_MINUS_VALUE -76

#define FLOAT_VALUE_A 4.56f
#define FLOAT_VALUE_B 95.78f
#define FLOAT_MINUS_VALUE -6.84f

#define BOOLEAN_VALUE_TRUE true
#define BOOLEAN_VALUE_FALSE false

#define PARSE_RESULT_SUCCESS 0
#define PARSE_RESULT_FAILITURE 1

#define ID_A Identifier("a")
#define ID_B Identifier("b")
#define ID_C Identifier("c")

#define ptr std::unique_ptr

ConstantExpression createConstantExpression(int val) {
	Primitive primitive1 = Primitive(val);
	Variable variable1 = Variable(primitive1);
	return ConstantExpression(ptr<Variable>(new Variable(variable1)));
}

OperationExpressionAssignment createOpAssignExpr(ptr<Identifier> id, ptr<ConstantExpression> expr) {
	return OperationExpressionAssignment(move(id), move(expr));
}

OperationExpressionAssignment createMultiplicationAssignment(ptr<Identifier> id, ptr<ConstantExpression> expr1, ptr<ConstantExpression> expr2) {
	return OperationExpressionAssignment(move(id),
			ptr<OperationExpression>(new Multiplication(move(expr1), move(expr2))));
}

TEST(Primitive, Should_Contstruct_When_Passed_Int) {
	Primitive primitive = Primitive(INTEGER_VALUE_A);

	EXPECT_TRUE(primitive.isInteger());
	EXPECT_EQ(primitive.getInteger(), INTEGER_VALUE_A);
}

TEST(Primitive, Should_Contstruct_When_Passed_Float) {
	Primitive primitive = Primitive(FLOAT_VALUE_A);

	EXPECT_TRUE(primitive.isFloat());
	EXPECT_FLOAT_EQ(primitive.getFloat(), FLOAT_VALUE_A);
}

TEST(Primitive, Should_Contstruct_When_Passed_Bool) {
	Primitive primitive = Primitive(BOOLEAN_VALUE_TRUE);

	EXPECT_TRUE(primitive.isBoolean());
	EXPECT_EQ(primitive.getBoolean(), BOOLEAN_VALUE_TRUE);
}

TEST(Primitive, Should_Contstruct_When_Passed_String) {
	std::string str = "example";
	Primitive primitive = Primitive(str);

	EXPECT_TRUE(primitive.isString());
	EXPECT_EQ(primitive.getString(), str);
}

TEST(Primitive, Should_Be_Added_Correctly_When_Integers) {
	Primitive primitive1 = Primitive(INTEGER_VALUE_A);
	Primitive primitive2 = Primitive(INTEGER_VALUE_B);

	Primitive resultPrimitive = primitive1 + primitive2;

	EXPECT_TRUE(resultPrimitive.isInteger());
	EXPECT_EQ(resultPrimitive.getInteger(), INTEGER_VALUE_A + INTEGER_VALUE_B);
}

TEST(Primitive, Should_Be_Added_Correctly_When_Integer_And_Float) {
	Primitive primitive1 = Primitive(INTEGER_VALUE_A);
	Primitive primitive2 = Primitive(FLOAT_VALUE_A);

	Primitive resultPrimitive = primitive1 + primitive2;

	EXPECT_TRUE(resultPrimitive.isFloat());
	EXPECT_EQ(resultPrimitive.getFloat(), INTEGER_VALUE_A + FLOAT_VALUE_A);
}

TEST(Primitive, Should_Be_Added_Correctly_When_Floats) {
	Primitive primitive1 = Primitive(FLOAT_VALUE_A);
	Primitive primitive2 = Primitive(FLOAT_VALUE_B);

	Primitive resultPrimitive = primitive1 + primitive2;

	EXPECT_TRUE(resultPrimitive.isFloat());
	EXPECT_FLOAT_EQ(resultPrimitive.getFloat(), FLOAT_VALUE_A + FLOAT_VALUE_B);
}

TEST(Primitive, Should_Be_Concatenated_Correctly_When_Strings) {
	std::string str1 = "Winter";
	std::string str2 = "fell";

	Primitive primitive1 = Primitive(str1);
	Primitive primitive2 = Primitive(str2);

	Primitive resultPrimitive = primitive1 + primitive2;

	EXPECT_TRUE(resultPrimitive.isString());
	EXPECT_EQ(resultPrimitive.getString(), str1 + str2);
}

TEST(Primitive, Should_Be_Concatenated_Correctly_When_String_And_Integer) {
	std::string str1 = "Winter";
	int int1 = 2019;

	Primitive primitive1 = Primitive(str1);
	Primitive primitive2 = Primitive(int1);

	Primitive resultPrimitive = primitive1 + primitive2;

	EXPECT_TRUE(resultPrimitive.isString());
	EXPECT_EQ(resultPrimitive.getString(), str1 + to_string(int1));
}

TEST(Primitive, Should_Cast_To_True_When_Integer_Greater_Than_0) {

	Primitive primitive = Primitive(INTEGER_VALUE_A);

	EXPECT_TRUE(primitive.operator bool());
}

TEST(Primitive, Should_Cast_To_False_When_Integer_Less_Than_0) {
	Primitive primitive = Primitive(INTEGER_MINUS_VALUE);

	EXPECT_FALSE(primitive.operator bool());
}

TEST(Primitive, Should_Cast_To_True_When_Float_Greater_Than_0) {
	Primitive primitive = Primitive(FLOAT_VALUE_A);

	EXPECT_TRUE(primitive.operator bool());
}
TEST(Primitive, Should_Cast_To_False_When_Float_Less_Than_0) {
	Primitive primitive = Primitive(FLOAT_MINUS_VALUE);

	EXPECT_FALSE(primitive.operator bool());
}

TEST(Primitive, Should_Cast_To_False_When_String) {
	std::string str = "example";
	Primitive primitive = Primitive(str);

	EXPECT_FALSE(primitive.operator bool());
}

TEST(Primitive, Should_Cast_To_Value_When_Bool) {
	Primitive primitive1 = Primitive(BOOLEAN_VALUE_TRUE);
	Primitive primitive2 = Primitive(BOOLEAN_VALUE_FALSE);

	EXPECT_TRUE(primitive1.operator bool());
	EXPECT_FALSE(primitive2.operator bool());
}

/* OBJECT TESTS */
TEST(Object, Should_Preserve_Last_Assignment) {
	Object scope;

	Identifier id = Identifier("id1");

	Primitive primitive = Primitive(INTEGER_VALUE_A);
	Function funct = Function();
	Object obj = Object();

	scope.getFunction(id) = funct;
	scope.getObject(id) = obj;
	scope.getPrimitive(id) = primitive;

	EXPECT_TRUE(scope.hasPrimitive(id));
	EXPECT_EQ(scope.getPrimitive(id).getInteger(), INTEGER_VALUE_A);
}

TEST(Object, Should_Not_Contain_Entity_After_Removal) {
	Object scope;

	Identifier id = Identifier("id1");
	Function funct = Function();

	scope.getFunction(id) = funct;

	EXPECT_FALSE(scope.hasPrimitive(id));
}

TEST(Object, Should_Be_Able_To_Nest_Objects) {
	Object scope;

	Identifier id1 = Identifier("function");
	Identifier id2 = Identifier("object");
	Identifier id3 = Identifier(id2, "primitive");
	Identifier id4 = Identifier(id2, "object2");
	Identifier id5 = Identifier(id4, "primitive2");
	Identifier id6 = Identifier(id4, "object3");
	Identifier id7 = Identifier(id6, "function2");

	Primitive primitive = Primitive(INTEGER_VALUE_A);
	Primitive primitive2 = Primitive(BOOLEAN_VALUE_FALSE);
	Function funct = Function();
	Function funct2 = Function();
	Object obj = Object();
	Object obj2 = Object();
	Object obj3 = Object();

	scope.getFunction(id1) = funct;
	scope.getObject(id2) = obj;
	scope.getPrimitive(id3) = primitive;
	scope.getObject(id4) = obj2;
	scope.getPrimitive(id5) = primitive2;
	scope.getObject(id6) = obj3;
	scope.getFunction(id7) = funct2;

	EXPECT_TRUE(scope.hasFunction(id1));
	EXPECT_TRUE(scope.hasObject(id2));
	EXPECT_TRUE(scope.hasPrimitive(id3));
	EXPECT_TRUE(scope.hasObject(id4));
	EXPECT_TRUE(scope.hasPrimitive(id5));
	EXPECT_TRUE(scope.hasObject(id6));
	EXPECT_TRUE(scope.hasFunction(id7));

	EXPECT_EQ(scope.getPrimitive(id3).getInteger(), INTEGER_VALUE_A);
	EXPECT_EQ(scope.getPrimitive(id5).getBoolean(), BOOLEAN_VALUE_FALSE);
}

TEST(Object, Should_Throw_Exception_When_Identifier_Nested_Not_To_Object_Identifier_Assignment) {
	Object scope;

	Identifier id1 = Identifier("function");
	Identifier id2 = Identifier(id1, "primitive");

	Primitive primitive = Primitive(INTEGER_VALUE_A);
	Function funct = Function();

	scope.getFunction(id1) = funct;

	EXPECT_ANY_THROW(scope.getPrimitive(id2) = primitive);
}

TEST(Object, Should_Remove_Function_Correctly) {
	Object scope;

	Identifier id1 = Identifier("function");
	Function funct = Function();

	scope.getFunction(id1) = funct;
	scope.removeFunction(id1);

	EXPECT_FALSE(scope.hasFunction(id1));
}
TEST(Object, Should_Remove_Nested_Primitive) {
	Object scope;

	Identifier id1 = Identifier("object1");
	Identifier id2 = Identifier(id1, "object2");
	Identifier id3 = Identifier(id2, "primitive");

	Primitive primitive = Primitive(INTEGER_VALUE_A);
	Object obj1 = Object();
	Object obj2 = Object();

	scope.getObject(id1) = obj1;
	scope.getObject(id2) = obj2;
	scope.getPrimitive(id3) = primitive;

	scope.removePrimitive(id3);

	EXPECT_TRUE(scope.hasObject(id1));
	EXPECT_TRUE(scope.hasObject(id2));
	EXPECT_FALSE(scope.hasPrimitive(id3));
}

TEST(Object, Should_Not_Throw_Exception_When_Removing_Not_Existing_Entity) {
	Object scope;

	Identifier id1 = Identifier("function");
	Identifier id2 = Identifier("primitive");

	Function funct = Function();

	scope.getFunction(id1) = funct;

	EXPECT_NO_THROW(scope.removePrimitive(id2));
}

/* IDENTIFIER TESTS */

TEST(Identifier, Should_Be_Able_To_Nest) {
	std::string id1 = "id1";
	std::string id2 = "id2";

	Identifier identifier1 = Identifier(id1);
	Identifier identifier2 = Identifier(id1, id2);

	EXPECT_FALSE(identifier1.hasTail());
	EXPECT_TRUE(identifier2.hasTail());

	EXPECT_EQ(identifier1.getHead(), id1);
	EXPECT_EQ(identifier2.getHead(), id1);
}

TEST(Identifier, Should_Generate_Tail_Properly) {
	std::string id1 = "id1";
	std::string id2 = "id2";
	std::string id3 = "id3";

	Identifier identifier1 = Identifier(id1);
	Identifier identifier2 = Identifier(identifier1, id2);
	Identifier identifier3 = Identifier(identifier2, id3);

	Identifier tail = identifier3.getTail();

	EXPECT_FALSE(identifier1.hasTail());
	EXPECT_TRUE(identifier2.hasTail());
	EXPECT_TRUE(identifier3.hasTail());

	EXPECT_EQ(identifier3.getHead(), id1);
	EXPECT_EQ(tail.getHead(), id2);
	EXPECT_EQ(tail.getTail().getHead(), id3);
}

/* OPERATION EXPRESSION */
TEST(OperationExpression, Should_Assign_Constant_To_Variable_Properly) {
	/*
		a = 12
	*/
	Object globalScope = Object();
	
	ptr<ConstantExpression> aConstantExpression = make_unique<ConstantExpression>(createConstantExpression(INTEGER_VALUE_A));

	OperationExpressionAssignment aExpressionAssignment = createOpAssignExpr(move(ptr<Identifier>(new Identifier("a"))), move(aConstantExpression));
	Variable result = aExpressionAssignment.evaluate(globalScope);

	EXPECT_TRUE(result.isPrimitive());
	EXPECT_TRUE(globalScope.hasPrimitive(ID_A));
	EXPECT_TRUE(globalScope.getPrimitive(ID_A).isInteger());

	EXPECT_EQ(result.getPrimitive().getInteger(), INTEGER_VALUE_A);
	EXPECT_EQ(globalScope.getPrimitive(ID_A).getInteger(), INTEGER_VALUE_A);
}

TEST(OperationExpression, Should_Assign_Addition_Constant_To_Variable_Properly) {
	/*
		a = 12
		b = a + 8
	*/
	Object globalScope = Object();
	ptr<ConstantExpression> aConstantExpression = make_unique<ConstantExpression>(createConstantExpression(INTEGER_VALUE_A));

	OperationExpressionAssignment aExpressionAssignment = createOpAssignExpr(move(ptr<Identifier>(new Identifier("a"))), move(aConstantExpression));
	Variable constantAssignmentResult = aExpressionAssignment.evaluate(globalScope);

	
	ptr<ConstantExpression> sumConstantExpression = make_unique<ConstantExpression>(createConstantExpression(INTEGER_VALUE_B));

	OperationExpressionAssignment bExpressionAssignment = OperationExpressionAssignment(move(ptr<Identifier>(new Identifier("b"))),
			ptr<OperationExpression>(new Addition(
				move(sumConstantExpression),
				ptr<OperationExpression>(new IdentifierExpression(move(ptr<Identifier>(new Identifier("a"))))))));

	Variable result = bExpressionAssignment.evaluate(globalScope);

	EXPECT_TRUE(constantAssignmentResult.isPrimitive());
	EXPECT_TRUE(globalScope.hasPrimitive(ID_A));
	EXPECT_TRUE(globalScope.getPrimitive(ID_A).isInteger());

	EXPECT_TRUE(result.isPrimitive());
	EXPECT_TRUE(globalScope.hasPrimitive(ID_B));
	EXPECT_TRUE(globalScope.getPrimitive(ID_B).isInteger());

	EXPECT_EQ(constantAssignmentResult.getPrimitive().getInteger(), INTEGER_VALUE_A);
	EXPECT_EQ(globalScope.getPrimitive(ID_A).getInteger(), INTEGER_VALUE_A);

	EXPECT_EQ(result.getPrimitive().getInteger(), INTEGER_VALUE_A + INTEGER_VALUE_B);
	EXPECT_EQ(globalScope.getPrimitive(ID_B).getInteger(), INTEGER_VALUE_A + INTEGER_VALUE_B);
}

TEST(OperationExpression, Should_Assign_Subtraction_From_Self) {
	/*
		a = 12 * 13
		a = a - 12
	*/
	Object globalScope = Object();
	
	OperationExpressionAssignment expressionAssignment1 = createMultiplicationAssignment(move(ptr<Identifier>(new Identifier("a"))), 
		move(make_unique<ConstantExpression>(createConstantExpression(INTEGER_VALUE_A))),
		move(make_unique<ConstantExpression>(createConstantExpression(INTEGER_VALUE_B))));
	Variable firstAssignmentResult = expressionAssignment1.evaluate(globalScope);

	OperationExpressionAssignment expressionAssignment2 = OperationExpressionAssignment(move(ptr<Identifier>(new Identifier("a"))),
			ptr<OperationExpression>(new Subtraction(
				ptr<OperationExpression>(new IdentifierExpression(move(ptr<Identifier>(new Identifier("a"))))),
				move(make_unique<ConstantExpression>(createConstantExpression(INTEGER_VALUE_A))))));

	Variable result = expressionAssignment2.evaluate(globalScope);

	EXPECT_TRUE(firstAssignmentResult.isPrimitive());
	EXPECT_TRUE(result.isPrimitive());

	EXPECT_TRUE(globalScope.hasPrimitive(ID_A));
	EXPECT_TRUE(globalScope.getPrimitive(ID_A).isInteger());

	EXPECT_EQ(firstAssignmentResult.getPrimitive().getInteger(), INTEGER_VALUE_A * INTEGER_VALUE_B);
	EXPECT_EQ(globalScope.getPrimitive(ID_A).getInteger(), (INTEGER_VALUE_A * INTEGER_VALUE_B) - INTEGER_VALUE_A);
}

TEST(OperationExpression, Should_Assign_Constants_Multiplication) {
	/*
		a = 12 * 13
	*/
	Object globalScope = Object();
	OperationExpressionAssignment expressionAssignment1 = createMultiplicationAssignment(move(ptr<Identifier>(new Identifier("a"))), 
		move(make_unique<ConstantExpression>(createConstantExpression(INTEGER_VALUE_A))), 
		move(make_unique<ConstantExpression>(createConstantExpression(INTEGER_VALUE_B))));
	Variable result = expressionAssignment1.evaluate(globalScope);

	EXPECT_TRUE(result.isPrimitive());
	EXPECT_TRUE(globalScope.hasPrimitive(ID_A));
	EXPECT_TRUE(globalScope.getPrimitive(ID_A).isInteger());
	EXPECT_EQ(result.getPrimitive().getInteger(), INTEGER_VALUE_A * INTEGER_VALUE_B);
}

TEST(OperationExpression, Should_Assign_Variables_Subtraction_Properly) {
	/*
		a = 12
		b = a + 8
		c = b - a
	*/
	Object globalScope = Object();
	
	ptr<ConstantExpression> aConstantExpression = make_unique<ConstantExpression>(createConstantExpression(INTEGER_VALUE_A));
	OperationExpressionAssignment aExpressionAssignment = createOpAssignExpr(move(ptr<Identifier>(new Identifier("a"))), move(aConstantExpression));

	Variable constantAssignmentResult = aExpressionAssignment.evaluate(globalScope);
	
	ptr<ConstantExpression> sumConstantExpression = make_unique<ConstantExpression>(createConstantExpression(INTEGER_VALUE_B));
	OperationExpressionAssignment bExpressionAssignment = OperationExpressionAssignment(move(ptr<Identifier>(new Identifier("b"))),
														ptr<OperationExpression>(new Addition(
															move(sumConstantExpression),
															ptr<OperationExpression>(new IdentifierExpression(move(ptr<Identifier>(new Identifier("a"))))))));

	Variable bAssignmentResult = bExpressionAssignment.evaluate(globalScope);

	OperationExpressionAssignment cExpressionAssignment = OperationExpressionAssignment(move(ptr<Identifier>(new Identifier("c"))),
			ptr<OperationExpression>(new Multiplication(
				ptr<OperationExpression>(new IdentifierExpression(move(ptr<Identifier>(new Identifier("a"))))),
				ptr<OperationExpression>(new IdentifierExpression(move(ptr<Identifier>(new Identifier("b"))))))));

	Variable result = cExpressionAssignment.evaluate(globalScope);

	EXPECT_TRUE(constantAssignmentResult.isPrimitive());
	EXPECT_TRUE(globalScope.hasPrimitive(ID_A));
	EXPECT_TRUE(globalScope.getPrimitive(ID_A).isInteger());

	EXPECT_TRUE(bAssignmentResult.isPrimitive());
	EXPECT_TRUE(globalScope.hasPrimitive(ID_B));
	EXPECT_TRUE(globalScope.getPrimitive(ID_B).isInteger());

	EXPECT_TRUE(result.isPrimitive());
	EXPECT_TRUE(globalScope.hasPrimitive(ID_C));
	EXPECT_TRUE(globalScope.getPrimitive(ID_C).isInteger());

	EXPECT_EQ(constantAssignmentResult.getPrimitive().getInteger(), INTEGER_VALUE_A);
	EXPECT_EQ(bAssignmentResult.getPrimitive().getInteger(), INTEGER_VALUE_A + INTEGER_VALUE_B);

	EXPECT_EQ(globalScope.getPrimitive(ID_A).getInteger(), INTEGER_VALUE_A);
	EXPECT_EQ(globalScope.getPrimitive(ID_B).getInteger(), INTEGER_VALUE_A + INTEGER_VALUE_B);

	EXPECT_EQ(result.getPrimitive().getInteger(), INTEGER_VALUE_A * (INTEGER_VALUE_A + INTEGER_VALUE_B));
	EXPECT_EQ(globalScope.getPrimitive(ID_C).getInteger(), INTEGER_VALUE_A * (INTEGER_VALUE_A + INTEGER_VALUE_B));
}

TEST(OperationExpression, Should_Increment_Variable_Properly) {
	/*
		a = 12
		++a
	*/
	Object globalScope = Object();
	
	ptr<ConstantExpression> aConstantExpression = make_unique<ConstantExpression>(createConstantExpression(INTEGER_VALUE_A));
	OperationExpressionAssignment aExpressionAssignment = createOpAssignExpr(move(ptr<Identifier>(new Identifier("a"))), move(aConstantExpression));

	Variable assignmentResult = aExpressionAssignment.evaluate(globalScope);
	ptr<ConstantExpression> oneConstantExpression = make_unique<ConstantExpression>(createConstantExpression(1));
	OperationExpressionAssignment expressionAssignment2 = OperationExpressionAssignment(move(ptr<Identifier>(new Identifier("a"))),
								ptr<OperationExpression>(new Addition(ptr<OperationExpression>(
									new IdentifierExpression(move(ptr<Identifier>(new Identifier("a"))))), move(oneConstantExpression))));
	
	Variable result = expressionAssignment2.evaluate(globalScope);

	EXPECT_TRUE(assignmentResult.isPrimitive());
	
	EXPECT_TRUE(result.isPrimitive());
	EXPECT_TRUE(globalScope.hasPrimitive(ID_A));
	EXPECT_TRUE(globalScope.getPrimitive(ID_A).isInteger());

	EXPECT_EQ(assignmentResult.getPrimitive().getInteger(), INTEGER_VALUE_A);
	EXPECT_EQ(result.getPrimitive().getInteger(), INTEGER_VALUE_A + 1);
	EXPECT_EQ(globalScope.getPrimitive(ID_A).getInteger(), INTEGER_VALUE_A + 1);
}

TEST(OperationExpression, Should_Negate_Variable_Properly) {
	/*
		a = 12 * 13
		a = -a
	*/
	Object globalScope = Object();
	
	ptr<ConstantExpression> constExpr1 = make_unique<ConstantExpression>(createConstantExpression(INTEGER_VALUE_A));
	ptr<ConstantExpression> constExpr2 = make_unique<ConstantExpression>(createConstantExpression(INTEGER_VALUE_B));

	OperationExpressionAssignment expressionAssignment1 = createMultiplicationAssignment(move(ptr<Identifier>(new Identifier("a"))), move(constExpr1), move(constExpr2));
	Variable firstAssignmentResult = expressionAssignment1.evaluate(globalScope);
	OperationExpressionAssignment expressionAssignment2 = OperationExpressionAssignment(move(ptr<Identifier>(new Identifier("a"))),
			ptr<OperationExpression>(new Negation(ptr<OperationExpression>(new IdentifierExpression(move(ptr<Identifier>(new Identifier("a"))))))));

	Variable result = expressionAssignment2.evaluate(globalScope);

	EXPECT_TRUE(firstAssignmentResult.isPrimitive());
	EXPECT_TRUE(result.isPrimitive());

	EXPECT_TRUE(globalScope.hasPrimitive(ID_A));
	EXPECT_TRUE(globalScope.getPrimitive(ID_A).isInteger());

	EXPECT_EQ(firstAssignmentResult.getPrimitive().getInteger(), INTEGER_VALUE_A * INTEGER_VALUE_B);
	EXPECT_EQ(globalScope.getPrimitive(ID_A).getInteger(), -(INTEGER_VALUE_A * INTEGER_VALUE_B));
}

TEST(OperationExpression, Should_Logically_Negate_Boolean_Variable_Properly) {
	/*
		a = true
		a = !a
	*/
	Object globalScope = Object();
	
	Variable variable1 = Variable(BOOLEAN_VALUE_TRUE);
	ptr<ConstantExpression> constantExpression1 = make_unique<ConstantExpression>(ptr<Variable>(new Variable(variable1)));

	OperationExpressionAssignment expressionAssignment1 = createOpAssignExpr(move(ptr<Identifier>(new Identifier("a"))), move(constantExpression1));
	Variable firstAssignmentResult = expressionAssignment1.evaluate(globalScope);

	OperationExpressionAssignment expressionAssignment2 = OperationExpressionAssignment(move(ptr<Identifier>(new Identifier("a"))),
			ptr<OperationExpression>(new LogicalNot(ptr<OperationExpression>(new IdentifierExpression(move(ptr<Identifier>(new Identifier("a"))))))));

	Variable result = expressionAssignment2.evaluate(globalScope);

	EXPECT_TRUE(firstAssignmentResult.isPrimitive());
	EXPECT_TRUE(result.isPrimitive());

	EXPECT_TRUE(globalScope.hasPrimitive(ID_A));
	EXPECT_TRUE(globalScope.getPrimitive(ID_A).isBoolean());

	EXPECT_EQ(firstAssignmentResult.getPrimitive().getBoolean(), BOOLEAN_VALUE_TRUE);
	EXPECT_EQ(globalScope.getPrimitive(ID_A).getBoolean(), BOOLEAN_VALUE_FALSE);
}

TEST(OperationExpression, Should_Compare_Variables_Properly) {
	/*
		a = 12
		b = a + 8
		c = a >= b
	*/
	Object globalScope = Object();
	
	ptr<ConstantExpression> aConstantExpression = make_unique<ConstantExpression>(createConstantExpression(INTEGER_VALUE_A));
	OperationExpressionAssignment aExpressionAssignment = createOpAssignExpr(move(ptr<Identifier>(new Identifier("a"))), move(aConstantExpression));
	Variable constantAssignmentResult = aExpressionAssignment.evaluate(globalScope);

	ptr<ConstantExpression> sumConstantExpression = make_unique<ConstantExpression>(createConstantExpression(INTEGER_VALUE_B));
	IdentifierExpression aIdExpression = IdentifierExpression(move(ptr<Identifier>(new Identifier("a"))));

	OperationExpressionAssignment bExpressionAssignment = OperationExpressionAssignment(move(ptr<Identifier>(new Identifier("b"))),
			ptr<OperationExpression>(new Addition(
				move(sumConstantExpression),
				ptr<OperationExpression>(new IdentifierExpression(move(ptr<Identifier>(new Identifier("a"))))))));

	Variable bAssignmentResult = bExpressionAssignment.evaluate(globalScope);
	Identifier* cIdentifier = new Identifier("c");

	OperationExpressionAssignment cExpressionAssignment =OperationExpressionAssignment(ptr<Identifier>(ptr<Identifier>(new Identifier("c"))),
			ptr<OperationExpression>(new GreaterThanOrEqualTo(
				ptr<OperationExpression>(new IdentifierExpression(move(ptr<Identifier>(new Identifier("a"))))),
				ptr<OperationExpression>(new IdentifierExpression(move(ptr<Identifier>(new Identifier("b"))))))));

	Variable result = cExpressionAssignment.evaluate(globalScope);

	EXPECT_TRUE(constantAssignmentResult.isPrimitive());
	EXPECT_TRUE(globalScope.hasPrimitive(ID_A));
	EXPECT_TRUE(globalScope.getPrimitive(ID_A).isInteger());

	EXPECT_TRUE(bAssignmentResult.isPrimitive());
	EXPECT_TRUE(globalScope.hasPrimitive(ID_B));
	EXPECT_TRUE(globalScope.getPrimitive(ID_B).isInteger());

	EXPECT_TRUE(result.isPrimitive());
	EXPECT_TRUE(globalScope.hasPrimitive(ID_C));
	EXPECT_TRUE(globalScope.getPrimitive(ID_C).isBoolean());

	EXPECT_EQ(constantAssignmentResult.getPrimitive().getInteger(), INTEGER_VALUE_A);
	EXPECT_EQ(bAssignmentResult.getPrimitive().getInteger(), INTEGER_VALUE_A + INTEGER_VALUE_B);

	EXPECT_EQ(globalScope.getPrimitive(ID_A).getInteger(), INTEGER_VALUE_A);
	EXPECT_EQ(globalScope.getPrimitive(ID_B).getInteger(), INTEGER_VALUE_A + INTEGER_VALUE_B);

	EXPECT_EQ(result.getPrimitive().getBoolean(), BOOLEAN_VALUE_FALSE);
	EXPECT_EQ(globalScope.getPrimitive(ID_C).getBoolean(), BOOLEAN_VALUE_FALSE);
}

TEST(OperationExpression, Should_Compare_Variable_And_Constant_Properly) {
	/*
		a = 12
		b = a == 12
	*/
	Object globalScope = Object();
	
	OperationExpressionAssignment aExpressionAssignment = createOpAssignExpr(move(ptr<Identifier>(new Identifier("a"))), 
		move(make_unique<ConstantExpression>(createConstantExpression(INTEGER_VALUE_A))));
	Variable constantAssignmentResult = aExpressionAssignment.evaluate(globalScope);

	IdentifierExpression aIdExpression = IdentifierExpression(move(ptr<Identifier>(new Identifier("a"))));

	OperationExpressionAssignment bExpressionAssignment = OperationExpressionAssignment(move(ptr<Identifier>(new Identifier("b"))),
			ptr<OperationExpression>(new Equals(
				move(make_unique<ConstantExpression>(createConstantExpression(INTEGER_VALUE_A))),
				ptr<OperationExpression>(new IdentifierExpression(move(ptr<Identifier>(new Identifier("a"))))))));

	Variable result = bExpressionAssignment.evaluate(globalScope);

	EXPECT_TRUE(constantAssignmentResult.isPrimitive());
	EXPECT_TRUE(globalScope.hasPrimitive(ID_A));
	EXPECT_TRUE(globalScope.getPrimitive(ID_A).isInteger());

	EXPECT_TRUE(result.isPrimitive());
	EXPECT_TRUE(globalScope.hasPrimitive(ID_B));
	EXPECT_TRUE(globalScope.getPrimitive(ID_B).isBoolean());

	EXPECT_EQ(constantAssignmentResult.getPrimitive().getInteger(), INTEGER_VALUE_A);
	EXPECT_EQ(globalScope.getPrimitive(ID_A).getInteger(), INTEGER_VALUE_A);

	EXPECT_EQ(result.getPrimitive().getBoolean(), BOOLEAN_VALUE_TRUE);
	EXPECT_EQ(globalScope.getPrimitive(ID_B).getBoolean(), BOOLEAN_VALUE_TRUE);
}

/*****************************************************************************************************************************************************
 * 																		PARSER
*****************************************************************************************************************************************************/

int runParser(string input) {
	yy_scan_string(input.c_str());
	int result = yyparse();
	yylex_destroy();
	return result;
}

TEST(Parser, Should_Declare_Single_Variable_Without_Var) {
	ostringstream inputStream;
	inputStream << "a;";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
}

TEST(Parser, Should_Fail_When_Missing_Semicolon) {
	ostringstream inputStream;
	inputStream << "a";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_FAILITURE);
}

TEST(Parser, Should_Declare_Two_Variables) {
	ostringstream inputStream;
	inputStream << "var a, b;";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
}

TEST(Parser, Should_Not_Declare_Two_Variables_Without_Var) {
	ostringstream inputStream;
	inputStream << "a, b;";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_FAILITURE);
}

TEST(Parser, Should_Assign_And_Return_Value) {
	ostringstream inputStream;
	inputStream << "a = " << INTEGER_VALUE_A << "; return a;";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
	EXPECT_EQ(_PARSE_RESULT.getPrimitive().getInteger(), INTEGER_VALUE_A);
}

TEST(Parser, Should_Fail_When_Wrongly_Placed_Semicolon) {
	ostringstream inputStream;
	inputStream << "var a =; " << INTEGER_VALUE_A << "; return a;";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_FAILITURE);
}

TEST(Parser, Should_Fail_When_Two_Semicolons) {
	ostringstream inputStream;
	inputStream << "var a = " << INTEGER_VALUE_A << ";; return a;";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_FAILITURE);
}

TEST(Parser, Should_Fail_When_Variable_Name_Starts_With_Number) {
	ostringstream inputStream;
	inputStream << "var 1a = " << INTEGER_VALUE_A << "; return 1a;";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_FAILITURE);
}

TEST(Parser, Should_Fail_When_Variable_Name_Starts_With_Symbol) {
	ostringstream inputStream;
	inputStream << "var @a = " << INTEGER_VALUE_A << "; return @a;";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_FAILITURE);
}

TEST(Parser, Should_Assign_Value_When_Valid_Variable_Name) {
	ostringstream inputStream;
	inputStream << "var a = " << INTEGER_VALUE_A << "; return a;";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
	EXPECT_EQ(_PARSE_RESULT.getPrimitive().getInteger(), INTEGER_VALUE_A);
}

TEST(Parser, Should_Assign_Boolean_Value_When_Valid_Variable_Name) {
	ostringstream inputStream;
	inputStream << "var a = true; return a;";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
	EXPECT_TRUE(_PARSE_RESULT.getPrimitive().isBoolean());
	EXPECT_EQ(_PARSE_RESULT.getPrimitive().getBoolean(), BOOLEAN_VALUE_TRUE);
}

TEST(Parser, Should_Assign_Float_Value_When_Valid_Variable_Name) {
	ostringstream inputStream;
	inputStream << "var a = " << FLOAT_MINUS_VALUE << "; return a;";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
	EXPECT_TRUE(_PARSE_RESULT.getPrimitive().isFloat());
	EXPECT_EQ(_PARSE_RESULT.getPrimitive().getFloat(), FLOAT_MINUS_VALUE);
}

TEST(Parser, Should_Fail_When_Assigning_Undeclared_Variable) {
	ostringstream inputStream;
	inputStream << "a = b";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_FAILITURE);
	EXPECT_EQ(_ERROR_MESSAGE, "[ERROR]\tInvalid identifier: Error! Undefined identifier.");
}

TEST(Parser, Should_Fail_When_Single_Variable_Declared_Without_Var) {
	ostringstream inputStream;
	inputStream << "a; return;";

	string input = inputStream.str();
	int result = runParser(input);
	
	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
	EXPECT_EQ(_ERROR_MESSAGE, "[ERROR]\tInvalid identifier: Error! Undefined identifier.");
}

TEST(Parser, Should_Fail_When_Multiple_Variables_Declared_Without_Var) {
	ostringstream inputStream;
	inputStream << "a, b, c; return;";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_FAILITURE);
}

TEST(Parser, Should_Assign_Variable_And_Return) {
	ostringstream inputStream;
	inputStream << "b = 2; a = b; return a;";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
	EXPECT_TRUE(_PARSE_RESULT.getPrimitive().isInteger());
	EXPECT_EQ(_PARSE_RESULT.getPrimitive().getInteger(), 2);
}

TEST(Parser, Should_Return_Valid_Boolean_OR_Operation_Result) {
	ostringstream inputStream;
	inputStream << "var a = true; var b = false; return (a || b);";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
	EXPECT_TRUE(_PARSE_RESULT.getPrimitive().isBoolean());
	EXPECT_EQ(_PARSE_RESULT.getPrimitive().getBoolean(), BOOLEAN_VALUE_TRUE);
}

TEST(Parser, Should_Return_Valid_Boolean_AND_Operation_Result) {
	ostringstream inputStream;
	inputStream << "var a = true; var b = false; return (a && !b);";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
	EXPECT_TRUE(_PARSE_RESULT.getPrimitive().isBoolean());
	EXPECT_EQ(_PARSE_RESULT.getPrimitive().getBoolean(), BOOLEAN_VALUE_TRUE);
}

TEST(Parser, Should_Return_Valid_Boolean_Complex_Operation_Result) {
	ostringstream inputStream;
	inputStream << "var a = true, b = false, c = 12; return (c < 12) || (a && b);";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
	EXPECT_TRUE(_PARSE_RESULT.getPrimitive().isBoolean());
	EXPECT_EQ(_PARSE_RESULT.getPrimitive().getBoolean(), BOOLEAN_VALUE_FALSE);
}

TEST(Parser, Should_Return_True_When_Comparing_Equal_Integers) {
	ostringstream inputStream;
	inputStream << "var a = 1, b = 1; return (a == b);";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
	EXPECT_TRUE(_PARSE_RESULT.getPrimitive().isBoolean());
	EXPECT_EQ(_PARSE_RESULT.getPrimitive().getBoolean(), BOOLEAN_VALUE_TRUE);
}

TEST(Parser, Should_Return_False_When_Comparing_Not_Equal_Integers) {
	ostringstream inputStream;
	inputStream << "var a = 1, b = 2; return (a == b);";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
	EXPECT_TRUE(_PARSE_RESULT.getPrimitive().isBoolean());
	EXPECT_EQ(_PARSE_RESULT.getPrimitive().getBoolean(), BOOLEAN_VALUE_FALSE);
}

TEST(Parser, Should_Return_True_When_Negate_Comparing_Not_Equal_Integers) {
	ostringstream inputStream;
	inputStream << "var a = 1, b = 2; return (a != b);";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
	EXPECT_TRUE(_PARSE_RESULT.getPrimitive().isBoolean());
	EXPECT_EQ(_PARSE_RESULT.getPrimitive().getBoolean(), BOOLEAN_VALUE_TRUE);
}

TEST(Parser, Should_Return_False_When_Negate_Comparing_Equal_Integers) {
	ostringstream inputStream;
	inputStream << "var a = 1, b = 1; return (a != b);";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
	EXPECT_TRUE(_PARSE_RESULT.getPrimitive().isBoolean());
	EXPECT_EQ(_PARSE_RESULT.getPrimitive().getBoolean(), BOOLEAN_VALUE_FALSE);
}

TEST(Parser, Should_Return_True_When_Comparing_Boolean_True) {
	ostringstream inputStream;
	inputStream << "var a = true, b = true; return (a == b);";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
	EXPECT_TRUE(_PARSE_RESULT.getPrimitive().isBoolean());
	EXPECT_EQ(_PARSE_RESULT.getPrimitive().getBoolean(), BOOLEAN_VALUE_TRUE);
}

TEST(Parser, Should_Return_True_When_Comparing_Boolean_False) {
	ostringstream inputStream;
	inputStream << "var a = false, b = false; return (a == b);";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
	EXPECT_TRUE(_PARSE_RESULT.getPrimitive().isBoolean());
	EXPECT_EQ(_PARSE_RESULT.getPrimitive().getBoolean(), BOOLEAN_VALUE_TRUE);
}

TEST(Parser, Should_Return_False_When_Comparing_Boolean_True_And_False) {
	ostringstream inputStream;
	inputStream << "var a = true, b = false; return (a == b);";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
	EXPECT_TRUE(_PARSE_RESULT.getPrimitive().isBoolean());
	EXPECT_EQ(_PARSE_RESULT.getPrimitive().getBoolean(), BOOLEAN_VALUE_FALSE);
}

TEST(Parser, Should_Return_False_When_Comparing_Boolean_And_Integer_Diff_Than_1) {
	ostringstream inputStream;
	inputStream << "var a = true, b = 2; return (a == b);";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
	EXPECT_TRUE(_PARSE_RESULT.getPrimitive().isBoolean());
	EXPECT_EQ(_PARSE_RESULT.getPrimitive().getBoolean(), BOOLEAN_VALUE_FALSE);
}

TEST(Parser, Should_Return_True_When_Comparing_Boolean_True_And_Integer_1) {
	ostringstream inputStream;
	inputStream << "var a = true, b = 1; return (a == b);";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
	EXPECT_TRUE(_PARSE_RESULT.getPrimitive().isBoolean());
	EXPECT_EQ(_PARSE_RESULT.getPrimitive().getBoolean(), BOOLEAN_VALUE_TRUE);
}

TEST(Parser, Should_Return_False_When_Type_Comparing_Boolean_True_And_Integer_1) {
	ostringstream inputStream;
	inputStream << "var a = true, b = 1; return (a &= b);";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
	EXPECT_TRUE(_PARSE_RESULT.getPrimitive().isBoolean());
	EXPECT_EQ(_PARSE_RESULT.getPrimitive().getBoolean(), BOOLEAN_VALUE_FALSE);
}

TEST(Parser, Should_Return_True_When_Comparing_Boolean_False_And_Integer_0) {
	ostringstream inputStream;
	inputStream << "var a = 0, b = false; return (a == b);";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
	EXPECT_TRUE(_PARSE_RESULT.getPrimitive().isBoolean());
	EXPECT_EQ(_PARSE_RESULT.getPrimitive().getBoolean(), BOOLEAN_VALUE_TRUE);
}

TEST(Parser, Should_Return_True_When_Comparing_Equal_String_And_Integer) {
	ostringstream inputStream;
	inputStream << "var a = 12, b = \"12\"; return (a == b);";

	string input = inputStream.str();
	int result = runParser(input);;

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
	EXPECT_TRUE(_PARSE_RESULT.getPrimitive().isBoolean());
	EXPECT_EQ(_PARSE_RESULT.getPrimitive().getBoolean(), BOOLEAN_VALUE_TRUE);
}

TEST(Parser, Should_Return_False_When_Type_Comparing_String_And_Integer) {
	ostringstream inputStream;
	inputStream << "var a = 12, b = \"12\"; return (a &= b);";

	string input = inputStream.str();
	int result = runParser(input);;

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
	EXPECT_TRUE(_PARSE_RESULT.getPrimitive().isBoolean());
	EXPECT_EQ(_PARSE_RESULT.getPrimitive().getBoolean(), BOOLEAN_VALUE_FALSE);
}

TEST(Parser, Should_Return_True_When_Type_Comparing_String_And_Concatenated_Integer) {
	ostringstream inputStream;
	inputStream << "var a = \"125\", b = \"12\" + 5; return (a &= b);";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
	EXPECT_TRUE(_PARSE_RESULT.getPrimitive().getBoolean());
}

TEST(Parser, Should_Construct_Empty_Object) {
	ostringstream inputStream;
	inputStream << "var obj = { }; return;";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
}

TEST(Parser, Should_Construct_Simple_Object_From_JSON_Style_Literal) {
	ostringstream inputStream;
	inputStream << "var obj = { a: " << FLOAT_MINUS_VALUE << ", b: "<< INTEGER_VALUE_A  << " }; return obj.b;";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
	EXPECT_TRUE(_PARSE_RESULT.getPrimitive().isInteger());
	EXPECT_EQ(_PARSE_RESULT.getPrimitive().getInteger(), INTEGER_VALUE_A);
}

TEST(Parser, Should_Construct_Nested_Object_From_JSON_Style_Literal) {
	ostringstream inputStream;
	inputStream << "var obj = { a: " << FLOAT_MINUS_VALUE << ", b: "
	<< INTEGER_VALUE_A  << " }; obj2 = { obj: obj, c: true}; return obj2.obj.b;";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
	EXPECT_TRUE(_PARSE_RESULT.getPrimitive().isInteger());
	EXPECT_EQ(_PARSE_RESULT.getPrimitive().getInteger(), INTEGER_VALUE_A);
}

TEST(Parser, Should_Construct_Complex_Object_From_JSON_Style_Literal) {
	ostringstream inputStream;
	inputStream << "var obj = { a: " << FLOAT_MINUS_VALUE << ", b: " << INTEGER_VALUE_A 
	<< " }; obj2 = { obj: obj, c: function(x) { return x * 2; } }; return obj2.c(obj2.obj.b);";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
	EXPECT_TRUE(_PARSE_RESULT.getPrimitive().isInteger());
	EXPECT_EQ(_PARSE_RESULT.getPrimitive().getInteger(), INTEGER_VALUE_A * 2);
}

TEST(Parser, Should_Access_Object_Properties_With_Array_Notation) {
	ostringstream inputStream;
	inputStream << "var obj = { a: " << FLOAT_MINUS_VALUE << ", b: "<< INTEGER_VALUE_A  
	<< " }; obj2 = { obj: obj, c: function(x) { return x * 2; } }; return obj2[\"c\"](obj2.obj.b);";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
	EXPECT_TRUE(_PARSE_RESULT.getPrimitive().isInteger());
	EXPECT_EQ(_PARSE_RESULT.getPrimitive().getInteger(), INTEGER_VALUE_A * 2);
}

TEST(Parser, Should_Fail_When_Random_Literal_Inside_Object_Body) {
	ostringstream inputStream;
	inputStream << "var obj = { a: " << FLOAT_MINUS_VALUE << ", b: " << INTEGER_VALUE_A 
	<< ", c }; return;";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_FAILITURE);
}

TEST(Parser, Should_Fail_When_Wrong_Notation_Inside_Object_Body) {
	ostringstream inputStream;
	inputStream << "var obj = { a: " << FLOAT_MINUS_VALUE << ", b: " << INTEGER_VALUE_A 
	<< ", c - \"abc\" }; return;";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_FAILITURE);
}

TEST(Parser, Should_Throw_When_Undefined_Variable_Assignment_Inside_Object_Body) {
	ostringstream inputStream;
	inputStream << "var obj = { a: " << FLOAT_MINUS_VALUE << ", b: " << INTEGER_VALUE_A 
	<< ", c: d }; return;";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
	EXPECT_EQ(_ERROR_MESSAGE, "[ERROR]\tInvalid identifier: Error! Undefined identifier.");
}

TEST(Parser, Should_Access_Global_Function) {
	ostringstream inputStream;
	inputStream << "function sum(x, y) { return x + y; } var obj = { a: " << INTEGER_MINUS_VALUE 
	<< ", b: "<< INTEGER_VALUE_A  << " }; obj2 = { obj: obj, c: function(x) { return x * 2; } };"
	<< " return sum(obj2.obj.a, obj2.obj.b);";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
	EXPECT_TRUE(_PARSE_RESULT.getPrimitive().isInteger());
	EXPECT_EQ(_PARSE_RESULT.getPrimitive().getInteger(), INTEGER_VALUE_A + INTEGER_MINUS_VALUE);
}

TEST(Parser, Should_Return_Break_Execution) {
	ostringstream inputStream;
	inputStream << "function sum(x, y) { return x + y; } var obj = { a: " << INTEGER_MINUS_VALUE 
	<< ", b: "<< INTEGER_VALUE_A  << " }; obj2 = { obj: obj, c: function(x) { return x * 2; } };"
	<< " return obj2.obj.a; obj2.c(obj2.obj.a);";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
	EXPECT_TRUE(_PARSE_RESULT.getPrimitive().isInteger());
	EXPECT_EQ(_PARSE_RESULT.getPrimitive().getInteger(), INTEGER_MINUS_VALUE);
}

TEST(Parser, Should_Be_Able_To_Return_Empty_Value) {
	ostringstream inputStream;
	inputStream << "function sum(x, y) { return x + y; } var obj = { a: " 
	<< INTEGER_MINUS_VALUE << ", b: "<< INTEGER_VALUE_A  << " }; return;";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
}

TEST(Parser, Should_Successfully_Chain_Variable_Declarations) {
	ostringstream inputStream;
	inputStream << "var x = " << INTEGER_MINUS_VALUE << ", b = "<< FLOAT_VALUE_B  
	<< ", obj = { a: " << INTEGER_MINUS_VALUE << ", b: " << INTEGER_VALUE_A << " }; return b;";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
	EXPECT_TRUE(_PARSE_RESULT.getPrimitive().isFloat());
	EXPECT_EQ(_PARSE_RESULT.getPrimitive().getFloat(), FLOAT_VALUE_B);
}

TEST(Parser, Should_Execute_Positive_Block_When_Condtion_Evaluates_To_True) {
	ostringstream inputStream;
	inputStream << "var x =" << FLOAT_VALUE_A << ", y = 12, z = true; if(y >= 12 && z) { x = " 
	<< FLOAT_VALUE_B << "; } return x;";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
	EXPECT_TRUE(_PARSE_RESULT.getPrimitive().isFloat());
	EXPECT_EQ(_PARSE_RESULT.getPrimitive().getFloat(), FLOAT_VALUE_B);
}

TEST(Parser, Should_NOT_Execute_Positive_Block_When_Condtion_Evaluates_To_False) {
	ostringstream inputStream;
	inputStream << "var x =" << FLOAT_VALUE_A << ", y = 12, z = true; if(y < 12 && z) { x = " 
	<< FLOAT_VALUE_B << "; } return x;";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
	EXPECT_TRUE(_PARSE_RESULT.getPrimitive().isFloat());
	EXPECT_EQ(_PARSE_RESULT.getPrimitive().getFloat(), FLOAT_VALUE_A);
}

TEST(Parser, Should_Execute_Negative_Block_When_Condtion_Evaluates_To_False) {
	ostringstream inputStream;
	inputStream << "var x =" << FLOAT_VALUE_A << ", y = 12, z = true; if(y < 12 && z) { x = " 
	<< FLOAT_VALUE_B << "; } else { x = x * 5; } return x;";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
	EXPECT_TRUE(_PARSE_RESULT.getPrimitive().isFloat());
	EXPECT_EQ(_PARSE_RESULT.getPrimitive().getFloat(), FLOAT_VALUE_A * 5);
}

TEST(Parser, Should_While_Loop_Until_Condition_Evaluates_To_True) {
	ostringstream inputStream;
	inputStream << "var counter = 0; while(counter < " << INTEGER_VALUE_B 
	<< ") { ++counter; } return counter;";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
	EXPECT_TRUE(_PARSE_RESULT.getPrimitive().isInteger());
	EXPECT_EQ(_PARSE_RESULT.getPrimitive().getInteger(), INTEGER_VALUE_B);
}

TEST(Parser, Should_Function_Create_Its_Own_Scope) {
	ostringstream inputStream;
	inputStream << "var counter = 0, x = " << FLOAT_MINUS_VALUE << "; function func () { var x = " 
	<< INTEGER_VALUE_A << "; ++counter; } func(); return x;";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
	EXPECT_TRUE(_PARSE_RESULT.getPrimitive().isFloat());
	EXPECT_EQ(_PARSE_RESULT.getPrimitive().getFloat(), FLOAT_MINUS_VALUE);
}

TEST(Parser, Should_Initialize_List) {
	ostringstream inputStream;
	inputStream << "var x = []; return x;";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
	EXPECT_TRUE(_PARSE_RESULT.getObject().isArray());
}

TEST(Parser, Should_Return_Size_Of_List) {
	ostringstream inputStream;
	inputStream << "var x = [1, \"abc\", {}]; return x;";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
	EXPECT_TRUE(_PARSE_RESULT.getObject().isArray());
	EXPECT_EQ(_PARSE_RESULT.getObject().getArraySize(), 3);
}

TEST(Parser, Should_Push_New_Element_At_End_Of_List) {
	ostringstream inputStream;
	inputStream << "var x = [1, \"abc\", {}]; x.push("<< INTEGER_VALUE_A <<"); return x;";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
	EXPECT_TRUE(_PARSE_RESULT.getObject().isArray());
	EXPECT_EQ(_PARSE_RESULT.getObject().getArraySize(), 4);

	Identifier thirdPos = Identifier("3");
	EXPECT_EQ(_PARSE_RESULT.getObject().getPrimitive(thirdPos).getInteger(), INTEGER_VALUE_A);
}

TEST(Parser, Should_Increase_Array_Size_When_Assigning_New) {
	ostringstream inputStream;
	inputStream << "var x = [1, \"abc\", {}]; x.push("<< INTEGER_VALUE_A <<"); return x;";

	string input = inputStream.str();
	int result = runParser(input);

	EXPECT_EQ(result, PARSE_RESULT_SUCCESS);
	EXPECT_TRUE(_PARSE_RESULT.getObject().isArray());
	EXPECT_EQ(_PARSE_RESULT.getObject().getArraySize(), 4);

	Identifier thirdPos = Identifier("3");
	EXPECT_EQ(_PARSE_RESULT.getObject().getPrimitive(thirdPos).getInteger(), INTEGER_VALUE_A);
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
