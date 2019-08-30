#ifndef LOGGER_CPP
#define LOGGER_CPP
	#include<string>
	#include<string.h>
	#include<vector>
	#include"Log.cpp"
	#include<iostream>
	#include<fstream>
	using namespace std;
	class Logger{
		private:
			string nombreArchivo;
			char usuario[20];
			int numLog;
			Log logs[200];
			int contador;
			//opcional writer de ofstream
		public:
			Logger(){
				
			}
			Logger(string nombreArchivo,string usuario,int numLog,int contador){
				this->nombreArchivo=nombreArchivo;
				setUsuario(usuario);
				setNumLog(numLog);
				this->contador=contador;
				
			}
			addLog(Log log){
				logs[contador++]=log;
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
			
			void alArchivo(){
				ofstream escribir(nombreArchivo.c_str(),ios::binary);
				if(!escribir){
					cout<<"\nno se puede abrir el archivo\n";
					return;
				}
				//escribimos la informacion del vector
				for(int i=0;i<contador;i++){
					escribir.write(reinterpret_cast<char*>(&logs[i]),sizeof(logs[i]));//escribir desde el ultimo registro
				}
				//limpiar el arreglo
				escribir.close();
			}
			void delArchivo(){
				ifstream leer(nombreArchivo.c_str(),ios::binary);
				if(!leer){
					cout<<"\nno se puede abrir el archivo\n";
					return ;
				}
				Log log;
				leer.read(reinterpret_cast<char*>(&log),sizeof(log));
				cout<<usuario<<"& listar"<<endl;
				while(!leer.eof()){
					log.print();
					leer.read(reinterpret_cast<char*>(&log),sizeof(log));
				}
				leer.close();
			}
		
	};
#endif
