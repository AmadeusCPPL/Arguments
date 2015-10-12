
#include "Arguments.h"
#include <iostream>

using namespace std;

Arguments::Arguments(int argc, char* argv[])
{
    try
    {
        if ( argc < 0 || argv == 0 )
        {
            throw argc;
        }
        else
        {	
			 /// todo: Set app to be the first item from argv
			Arguments::app = argv[0];
			
			/// todo: Save the remaining from argv into the args vector (push_back)
			for (int i = 1; i < argc; i++) {
				args.push_back(argv[i]);
			}
        }
    }
    catch (int e)
    {
        cerr << "error: constructing argument object..." << endl;
        throw;
    }
}

Arguments::Arguments(const Arguments& rhs) : args(rhs.args), app (rhs.app)
{
	
}

const string&
Arguments::operator[](const size_t i) const
{
    try
    {
        if ( i >= args.size() ) throw i;
    }
    catch(size_t e)
    {
        cerr << "error: index out of range " << e << endl;
        throw;
    }
    // todo: return argument on index
	return args[i];
} 

Arguments& Arguments::operator=(const Arguments& rhs)
{
	if (this!=&rhs) {
		args = rhs.args;
		app = rhs.app;
		//cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
	}
	/* if ((args != rhs.args) && (app != rhs.app)) {
		args = rhs.args;
		app = rhs.app;
		//cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
	} */
	//cout<<"YYYYYYYYYYYYYYYYYYYYYYYYYYYYYY"<<endl;
	return *this;
} 

int Arguments::count() const{
	return args.size();
}
string Arguments::appName() const{
	return app;
}
