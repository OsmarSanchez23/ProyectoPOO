// ListaEmpleados.h
#ifndef LISTA_EMPLEADOS_H
#define LISTA_EMPLEADOS_H

#include <iostream>
#include "Empleado.h"
#include <string>

class ListaEmpleados {
private:
    static const int MAX_EM = 50;
    Empleado empleados[MAX_EM];
    int numEmpleados;

public:
    // Constructor
    ListaEmpleados();

    // Métodos
    void agregarEmpleado(const Empleado& nuevoEmpleado);
    void consultarEmpleadoPorID(int id);
    void modificarEmpleadoPorID(int id);
    void eliminarEmpleadoPorID(int id);
    void calcularSalarios();
    void aumentarBonosPorID(int id, double aumentoBono);
    //Metodo para agregar horas extras
    void agregarHorasExtrasPorID(int id, double horasExtras);
    
    //Deducciones
    void aplicarDeduccionesPorID(int id, double deducciones);
};

#endif

ListaEmpleados::ListaEmpleados() {
    numEmpleados = 0;
}

void ListaEmpleados::agregarEmpleado(const Empleado& nuevoEmpleado) {
    if (numEmpleados < MAX_EM) {
        empleados[numEmpleados] = nuevoEmpleado;
        numEmpleados++;
        std::cout << "Empleado agregado exitosamente." << std::endl;
    } else {
        std::cout << "No se puede agregar mas empleados. Limite alcanzado." << std::endl;
    }
}

void ListaEmpleados::consultarEmpleadoPorID(int id) {
    for (int i = 0; i < numEmpleados; i++) {
        if (empleados[i].getId() == id) {
            std::cout << "Informacion del empleado con ID " << id << ":" << std::endl;
            std::cout << "ID: " << empleados[i].getId() << std::endl;
            std::cout << "Nombre: " << empleados[i].getNombre() << std::endl;
            std::cout << "Salario Base: $" << empleados[i].getSalarioBase() << std::endl;
            std::cout << "Bono: $" << empleados[i].getBono() << std::endl;
            std::cout << "Horas Extras: " << empleados[i].getHorasExtras() << " horas" << std::endl;
            std::cout << "Deducciones: $" << empleados[i].getDeducciones() << std::endl;
            std::cout << "Salario Final: $" << empleados[i].calcularSalarioFinal() << std::endl;
            return;
        }
    }
    std::cout << "No se encontro ningun empleado con el ID " << id << "." << std::endl;
}

void ListaEmpleados::modificarEmpleadoPorID(int id) {
    for (int i = 0; i < numEmpleados; i++) {
        if (empleados[i].getId() == id) {
            std::cout << "Empleado encontrado. ¿Que deseas modificar?" << std::endl;
            std::cout << "1. Nombre" << std::endl;
            std::cout << "2. Salario Base" << std::endl;

            int opcion;
            std::cin >> opcion;

            switch (opcion) {
                case 1: {
                    std::string nuevoNombre;
                    std::cout << "Ingrese el nuevo nombre: ";
                    std::cin.ignore();
                    getline(std::cin, nuevoNombre);
                    empleados[i].setNombre(nuevoNombre);
                    break;
                }
                case 2: {
                    double nuevoSalarioBase;
                    std::cout << "Ingrese el nuevo salario base: $";
                    std::cin >> nuevoSalarioBase;
                    empleados[i].setSalarioBase(nuevoSalarioBase);
                    break;
                }
                default:
                    std::cout << "Opcion no valida." << std::endl;
                    return;
            }

            std::cout << "Empleado modificado exitosamente." << std::endl;
            return;
        }
    }

    std::cout << "No se encontro ningun empleado con el ID " << id << "." << std::endl;
}

void ListaEmpleados::eliminarEmpleadoPorID(int id) {
    for (int i = 0; i < numEmpleados; i++) {
        if (empleados[i].getId() == id) {
            for (int j = i; j < numEmpleados - 1; j++) {
                empleados[j] = empleados[j + 1];
            }
            numEmpleados--;
            std::cout << "Empleado eliminado exitosamente." << std::endl;
            return;
        }
    }

    std::cout << "No se encontro ningun empleado con el ID " << id << "." << std::endl;
}

void ListaEmpleados::calcularSalarios() {
    for (int i = 0; i < numEmpleados; i++) {
        double salarioFinal = empleados[i].calcularSalarioFinal();
        std::cout << "Salario final para " << empleados[i].getNombre() << ": $" << salarioFinal << std::endl;
    }
}

void ListaEmpleados::aumentarBonosPorID(int id, double aumentoBono) {
    for (int i = 0; i < numEmpleados; i++) {
        if (empleados[i].getId() == id) {
            empleados[i].aumentarBonos(aumentoBono);
            std::cout << "Bonos aumentados exitosamente para " << empleados[i].getNombre() << "." << std::endl;
            return;
        }
    }

    std::cout << "No se encontro ningun empleado con el ID " << id << "." << std::endl;
}

void ListaEmpleados::agregarHorasExtrasPorID(int id, double horasExtras) {
    for (int i = 0; i < numEmpleados; i++) {
        if (empleados[i].getId() == id) {
            empleados[i].setHorasExtras(horasExtras);
            std::cout << "Horas extras agregadas exitosamente para el empleado con ID " << id << "." << std::endl;
            return;
        }
    }

    std::cout << "No se encontró ningún empleado con el ID " << id << "." << std::endl;
}

void ListaEmpleados::aplicarDeduccionesPorID(int id, double deducciones) {
    for (int i = 0; i < numEmpleados; i++) {
        if (empleados[i].getId() == id) {
            empleados[i].setDeducciones(deducciones);
            std::cout << "Deducciones aplicadas exitosamente para el empleado con ID " << id << "." << std::endl;
            return;
        }
    }

    std::cout << "No se encontró ningún empleado con el ID " << id << "." << std::endl;
}
