
RM = rm

CPPTOOL = g++
CPPFLAGS = -Wall

CPP = $(CPPTOOL) $(CPPFLAGS) -c
LINK = $(CPPTOOL) -o

GTEST_DIR=C:\gtest-1.7.0\gtest-1.7.0

GTEST_LIB=$(GTEST_DIR)\make\gtest_main.a

GTEST_INC=-isystem $(GTEST_DIR)\include


all: main.exe

test: test.exe
	test.exe

main.exe: main.o Arguments.o
	$(LINK) main.exe main.o Arguments.o

main.o: main.cpp Arguments.h
	$(CPP) main.cpp

Arguments.o: Arguments.cpp Arguments.h
	$(CPP) Arguments.cpp

	
test.exe: test_constructor.o test_exceptions.o Arguments.o $(GTEST_LIB)
	$(LINK) test.exe test_constructor.o test_exceptions.o Arguments.o $(GTEST_LIB)

test_constructor.o: test_constructor.cpp Arguments.h
	$(CPP) test_constructor.cpp $(GTEST_INC)
	
test_exceptions.o: test_exceptions.cpp Arguments.h
	$(CPP) test_exceptions.cpp $(GTEST_INC)
	
clean:
	$(RM) *.o
	$(RM) *.exe
