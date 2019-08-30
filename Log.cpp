#ifndef LOG_CPP
#define LOG_CPP
	#include<string>
	#include<string.h>
	using namespace std;
	class Log{
		private:
			char usuario[20];
			char comando[20];
			int numLog;
		public:
			string getUsuario() {
		        return usuario;
		    }
		
		    void setUsuario(string usuario) {
		        const char*co=usuario.data();
				int longitud=usuario.size();
				longitud=(longitud<20?longitud:19);
				strncpy(this->usuario,co,longitud);
				this->usuario[longitud]='\0';
		    }
		
		    string getComando() {
		        return comando;
		    }
		
		    void setComando(string comando) {
		        const char*co=comando.data();
				int longitud=comando.size();
				longitud=(longitud<20?longitud:19);
				strncpy(this->comando,co,longitud);
				this->comando[longitud]='\0';
		    }
		
		     int getNumLog() {
		        return numLog;
		    }
		
		    void setNumLog(int numLog) {
		        this->numLog = numLog;
		    }
			~Log(){
				
			}	
	};
#endif
