#include "gtest/gtest.h"

#include "Arguments.h"


//Tests if a move to "0" is accepted or not


TEST(ConstructorTest, AppName)
{
	//Arrange
	const int argc = 2;
	char * argv[argc] = {(char *)"appName", (char *)"argument2"};
	Arguments arguments(argc, argv);
	//Act
	
	//Assert
	ASSERT_EQ(argv[0],arguments.appName());
}

TEST(ConstructorTest, ArgumentsCount)
{
	//Arrange
	const int argc = 3;
	char * argv[argc] = {(char *)"appName", (char *)"argument2", (char *)"argument2"};
	Arguments arguments(argc, argv);
	//Act
	
	//Assert
	ASSERT_EQ(argc-1, arguments.count());
	ASSERT_NE(argc, arguments.count());
}

TEST(ConstructorTest, AllArguments)
{
	//Arrange
	const int argc = 2;
	char * argv[argc] = {(char *)"appName", (char *)"argument2"};
	Arguments arguments(argc, argv);
	//Act
	
	//Assert
	ASSERT_EQ(argv[0],arguments.appName());
	
	for (int i = 0; i < argc-1; i++) {
		ASSERT_EQ(argv[i+1],arguments[i]);
	}
}


TEST(ConstructorTest, CopyConstructor)
{
	//Arrange
	const int argc = 2;
	char * argv[argc] = {(char *)"appName", (char *)"argument2"};
	Arguments argums(argc, argv); 
	Arguments arguments(argums);
	
	//Act
	
	//Assert
	ASSERT_EQ(arguments.appName(), argums.appName());
	for (int i = 0; i < argc-1; i++) {
		ASSERT_EQ(arguments[i], argums[i]);
	}
}

TEST(ConstructorTest, AssignmentOperator)
{
	//Arrange
	const int argc = 2;
	char * argv[argc] = {(char *)"appName", (char *)"argument2"};
	const int argc1 = 1;
	char * argv1[argc1] = {(char *)"Name"};
	Arguments argums(argc, argv); 
	Arguments arguments(argc1, argv1);
	arguments = argums;
	
	//Act
	
	//Assert
	ASSERT_EQ(arguments.appName(), argums.appName());
	for (int i = 0; i < argc-1; i++) {
		ASSERT_EQ(arguments[i], argums[i]);
	}
}

TEST(ConstructorTest, SubscriptOperator)
{
	//Arrange
	const int argc = 2;
	char * argv[argc] = {(char *)"appName", (char *)"argument2"};
	Arguments arguments(argc, argv); 

	//Act
	
	//Assert
	ASSERT_EQ(argv[0],arguments.appName());
	for (int i = 0; i < argc-1; i++) {
		ASSERT_EQ(argv[i+1],arguments[i]);
	}
}

/*void redirectOutput() {
	// This can be an ofstream as well or any other ostream
	std::stringstream buffer;

	// Save cout's buffer here
	std::streambuf *sbuf = std::cout.rdbuf();

	// Redirect cout to our stringstream buffer or any other ostream
	std::cout.rdbuf(buffer.rdbuf());
}
void redirectToSelfOutput()
	// When done redirect cout to its old self
	std::cout.rdbuf(sbuf);
}
*/

