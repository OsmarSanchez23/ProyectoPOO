// Empleado.h
#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <iostream>
#include <string>

class Empleado {
private:
    int id;
    std::string nombre;
    double salarioBase;
    double bono;
    double horasExtras;
    double deducciones;

public:
    // Constructor
    Empleado(int i = 0, std::string n = "", double salBase = 0.0);

    // Métodos
    int getId();
    void setId(int i);

    std::string getNombre();
    void setNombre(std::string n);

    double getSalarioBase();
    void setSalarioBase(double salBase);

    double getBono();
    void setBono(double bono);

    double getHorasExtras();
    void setHorasExtras(double horasExtras);

    double getDeducciones();
    void setDeducciones(double deducciones);

    // Calculo del salario final
    double calcularSalarioFinal();

    // Método para aumentar únicamente los bonos y actualizar el salario final
    void aumentarBonos(double aumentoBono);
    
    
};

#endif

Empleado::Empleado(int i, std::string n, double salBase)
    : id(i), nombre(n), salarioBase(salBase), bono(0.0), horasExtras(0.0), deducciones(0.0) {}

int Empleado::getId() {
    return id;
}

void Empleado::setId(int i) {
    id = i;
}

std::string Empleado::getNombre() {
    return nombre;
}

void Empleado::setNombre(std::string n) {
    nombre = n;
}

double Empleado::getSalarioBase() {
    return salarioBase;
}

void Empleado::setSalarioBase(double salBase) {
    salarioBase = salBase;
}

double Empleado::getBono() {
    return bono;
}

void Empleado::setBono(double b) {
    bono = b;
}

double Empleado::getHorasExtras() {
    return horasExtras;
}

void Empleado::setHorasExtras(double he) {
    horasExtras = he;
}

double Empleado::getDeducciones() {
    return deducciones;
}

void Empleado::setDeducciones(double ded) {
    deducciones = ded;
}

double Empleado::calcularSalarioFinal() {
    // Calculo del salario final teniendo en cuenta bonos, horas extras y deducciones
    double salarioFinal = salarioBase + bono + (horasExtras * 250) - deducciones;
    return salarioFinal;
}

void Empleado::aumentarBonos(double aumentoBono) {
    bono += aumentoBono;
}


