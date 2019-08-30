#ifndef CONSOLA_CPP
#define CONSOLA_CPP
	#include"Log.cpp"
	#include<direct.h>
	#include"Logger.cpp"
	#include<string.h>
	#include<string>
	#include"CmdError.cpp"
	#include<iostream>
	using namespace std;
	class Consola{
		private:
			char usuario[20];
			Logger*logger;
			string nombreArchivo;
			int numLog;
			int contador;
		public:
			Consola(string usuario,string nombreArchivo,int numLog,int contador){
				setUsuario(usuario);
				this->nombreArchivo=nombreArchivo;
				this->numLog=numLog;
				logger=new Logger(nombreArchivo,usuario,numLog,contador);
			}
			void cmd(){
				//se ingresa un comando
				//el logger guarda un log 
				string comando;
				while(true){
					cout<<"\ncomando<exit para salir>: ";
					cin>>comando;
					if(comando=="listar"){
						logger->alArchivo();
						logger->delArchivo();
						logger->addLog(Log(usuario,comando,numLog));
					}else if(comando=="cd"){
						
						cout<<"cd";
						logger->addLog(Log(usuario,comando,numLog));
					}else if(comando=="exit"){
						logger->addLog(Log(usuario,comando,numLog));
						break;
					}else{
						logger->addLog(Log(usuario,comando,numLog));
						try
						{
							if(system(comando.c_str())){
								throw CmdError("Error en system");
							}
							
						}
						catch(CmdError&e){
							cout<<"my Except: "<<e.what();
						}	
					}	
				}
				
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
