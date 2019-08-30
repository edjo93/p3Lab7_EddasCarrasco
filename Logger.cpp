#ifndef LOGGER_CPP
#define LOGGER_CPP
	#include<string>
	#include<string.h>
	#include<vector>
	#include"Log.cpp"
	using namespace std;
	class Logger{
		private:
			string nombreArchivo;
			char usuario[20];
			int numLog;
			vector<Log*>logs;
			//opcional writer de ofstream
		public:
			addLog(Log*log){
				logs.push_back(log);
			}
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
		
		    int getNumLog() {
		        return numLog;
		    }
		
		    void setNumLog(int numLog) {
		        this->numLog = numLog;
		    }
			~Logger(){
			}
			
			
		
	};
#endif
