/// App using the Arugments class
#include <iostream>

#include "Arguments.h"

void redirectOutput() {
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


int main( int argc, char* argv[] )
{
    using namespace std;

    try
    {
		//Arguments arguments(argc, argv);
        Arguments args(argc, argv);
		args = args;
		//Arguments args(arguments);
		Arguments argsss(argc, argv); 
		argsss=args;
		//argsss = args;
        cout << "Name of the application: " <<
            args.appName() << endl;

        for ( int i = 0; i < args.count(); ++i )
        {
            cout << args[i] << endl;
        }
		cout<<args[-1];
		
		/*cout<<"Si cu = operator"<<endl;
		cout << "Name of the application: " <<
			argsss.appName() << endl;
		for ( int i = 0; i < argsss.count(); ++i )
        {
            cout << argsss[i] << endl;
        } */
		
    }
    /// This will catch throws from the try block with an integer param
    catch (int e)
    {
        cerr << "Construction error occured..." << endl;
    }
    /// This will catch throws from the try block with a size_t param
    catch (size_t e)
    {
        cerr << "Out of range error occured ..." << endl;
    }
	
    cout << "Ending application... " << endl;
    return 0;
}
