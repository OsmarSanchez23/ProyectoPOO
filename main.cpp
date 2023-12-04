#include <iostream>
#include <string>
#include "admins.h"
#include "ListaEmpleados.h"

using namespace std;

int main(){
	//Variables a usar en el programa
	string usua;
	string contra;
	int contador = 3;
	int contador2=1;
	char opcion;
	
	//Creamos un objeto de la clase ListaEmpleados
	ListaEmpleados listaEmpleados;
	
	//Creamos un objeto de la clase admins llamado Jefe
	admins Jefe;
	
	
	//Do While de el Ingreso con usuario y contrasena
	cout << "-------------------Control de Trabajadores y Pagos---------------------------\n";
	do{
		cout << "Ingresa tu usuario: \n";
		cin >> usua;
		cout << "Ingresa tu contrasena: \n";
		cin >> contra;
		
		//Valida a partir del metodo de la clase admins si el usuario y contra con correctos. Despues de 3 intentos el programa se cierra automaticamente
		if(Jefe.ingresar(usua,contra)){
			do {
			//Menu de empleados con todos sus metodos
			cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Gestion de Empleados >>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
			cout << "Selecciona una opcion: \na)Agregar Nuevo Empleado \nb)Consultar Individual de Empleado \nc)Agregar Bonos \nd)Agregar horas extras \ne)Modificar \nf)Agregar Deducciones \ng)Eliminar \nh)Salir\n";
			cin >> opcion;
			switch(opcion){
				case 'a': {
					int id;
					string nombre;
					double salarioBase;
                
                	cout << "Ingrese el ID del empleado: ";
                	cin >> id;
                	cout << "Ingrese el nombre del empleado: ";
                	cin.ignore();
                    getline(cin, nombre);
                	cout << "Ingrese el salario base del empleado: ";
                	cin >> salarioBase;

					//Generas una objeto de la clase empleado que sea un lista y lo agrega a travez de un metodo
                	Empleado empleado(id, nombre, salarioBase);
                	listaEmpleados.agregarEmpleado(empleado);
					break;
				}
				case 'b':{
					int idConsulta;
                    cout << "Ingrese el ID del empleado a consultar: ";
                    cin >> idConsulta;
                    
                    //Manda a llamar el metodo de ListaEmpleados para consultar un id que se ingreso anteriormente
                    listaEmpleados.consultarEmpleadoPorID(idConsulta);
					break;
				}
				case 'c':{
					int idBono;
                    double bono;
                    cout << "Ingrese el ID del empleado al que desea agregar bonos: ";
                    cin >> idBono;
                    cout << "Ingrese la cantidad de bonos a agregar: ";
                    cin >> bono;
                    //Llama al metodo de aumentar bonos de ListaEmpleados y lo hace a partir de primero buscar un id y depues agregar la cantidad del bono para despues internamente hacer la suma de estos bonos
                    listaEmpleados.aumentarBonosPorID(idBono, bono);
					break;
				}
				case 'd':{
					int id;
                	double horasExtras;
                	cout << "Ingrese el ID del empleado para agregar horas extras: ";
                	cin >> id;
                	cout << "Ingrese la cantidad de horas extras a agregar: ";
                	cin >> horasExtras;
                	//Realiza lo mismo que el metodo anterior solo que ahora pide horas extra, esas horas extra las multiplica $250 y eso se lo suma a la cantidad del salario final
                	listaEmpleados.agregarHorasExtrasPorID(id, horasExtras);
					break;
				}
				case 'e':{
					int idModificar;
                    cout << "Ingrese el ID del empleado a modificar: ";
                    cin >> idModificar;
                    //En esta parte solamente mandas un id, si este id existe internamente hay otro menu en el cual eliges que dato cambiar si el saldo o el nombrer del empleado
                    listaEmpleados.modificarEmpleadoPorID(idModificar);
					break;
				}
				case 'f':{
					int id;
                	double deducciones;
                	cout << "Ingrese el ID del empleado para aplicar deducciones: ";
                	cin >> id;
                	cout << "Ingrese el monto de deducciones a aplicar: ";
                	cin >> deducciones;
                	//Al igual que los otros a partir de un id y una cantidad de deducciones, simplemente internamente hace las operaciones y esta cantidad de deducciones se las resta al salario inicial
                	listaEmpleados.aplicarDeduccionesPorID(id, deducciones);
					break;
				}
				case 'g':{
					int idEliminar;
                    cout << "Ingrese el ID del empleado a eliminar: ";
                    cin >> idEliminar;
                    //Aqui simplemente se envia un id y dentro del metodo se elmina todo el registro del trabajador con ese id
                    listaEmpleados.eliminarEmpleadoPorID(idEliminar);
					break;
				}
				case 'h':{
					cout << "Hasta luego ...";
					//En esta parte seteamos los valores de contadores a 0 que son los que controlan los do while, entonces al ponerlos en 0 sale de los 2 ciclos automaticamente
					contador = 0;
					contador2 = 0;
					break;
				}	
			}
			}while(contador2 !=0);
		}else {
			contador--;
		}
		
	}while (contador != 0);
	return 0;
}

