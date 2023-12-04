#include <iostream>
#include <string>

using namespace std;

//Creamos la clase para admins
class admins{
	//Definimos los atributos de la clase
	private:
		string usuario;
		string contrasena;
	
	//Definimos las funciones de la clase	
	public:
		//Metodo Constructor
		admins(){
			usuario = "osmar";
			contrasena = "2305";
		}
		
		//Metodo para validar el ingreso
		bool ingresar(string usua, string contra){
			if(usua == usuario && contra == contrasena){
				cout << " \nIngreso exitoso\n";
				return true;
			}else{
				cout << "\nContrasena o usuario incorrectos \nIntenta de nuevo\n";
				return false;
			}
		}
};
