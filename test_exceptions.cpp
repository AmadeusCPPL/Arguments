#include "gtest/gtest.h"

#include "Arguments.h"


TEST(ConstructorExceptionTest, ConstructorOutOfRangeNegative)
{
	//Arrange
	const int argc = 2;
	char * argv[argc] = {(char *)"appName", (char *)"argument2"};
	bool hasException = false;
	//Act
	
	//Assert
	try {
		Arguments arguments(-1, argv); 
	} catch (int e){
		hasException = true;
	}
	ASSERT_EQ(true, hasException);
}

TEST(ConstructorExceptionTest, ConstructorOutOfRangeZero)
{
	//Arrange
	const int argc = 0;
	char * argv[argc] = {};
	bool hasException = false;
	//Act
	
	//Assert
	try {
		Arguments arguments(argc, argv); 
	} catch (int e){
		hasException = true;
	}
	ASSERT_EQ(true, hasException);
}

TEST(ConstructorExceptionTest, ConstructorOutOfRangeZeroList)
{
	//Arrange
	const int argc = 1;
	char ** argv = 0;
	bool hasException = false;
	//Act
	
	//Assert
	try {
		Arguments arguments(argc, argv); 
	} catch (int e){
		hasException = true;
	}
	ASSERT_EQ(true, hasException);
}

TEST(ConstructorExceptionTest, SubscriptOperatorOutOfRange)
{
	//Arrange
	const int argc = 2;
	char * argv[argc] = {(char *)"appName", (char *)"argument2"};
	Arguments arguments(argc, argv); 
	bool hasException =false;
	//Act
	
	//Assert
	try {
		std::string aux = arguments[argc + 1];
	} catch (size_t e){
		hasException = true;
	}
	ASSERT_EQ(true, hasException);
}