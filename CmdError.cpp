#ifndef USEREXCEPT_CPP
#define USEREXCEPT_CPP
	#include<stdexcept>
	using namespace std;
	class CmdError:public runtime_error{
		public:
			CmdError(char*mensaje):runtime_error(mensaje){
				
			}
	};
#endif
