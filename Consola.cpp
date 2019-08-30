#ifndef CONSOLA_CPP
#define CONSOLA_CPP
	#include"Log.cpp"
	#include"Logger.cpp"
	#include<string.h>
	#include<string>
	using namespace std;
	class Consola{
		private:
			char usuario[20];
			Logger*logger;
		public:
			
			void cmd(){
				//se ingresa un comando
				
			}
			void setUsuario(string usuario) {
		        const char*co=usuario.data();
				int longitud=usuario.size();
				longitud=(longitud<20?longitud:19);
				strncpy(this->usuario,co,longitud);
				this->usuario[longitud]='\0';
		    }
		    string getUsuario() {
		        return usuario;
		    }
			~Consola(){
			
			}
	};
#endif
