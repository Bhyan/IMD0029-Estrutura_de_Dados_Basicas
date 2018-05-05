//
//  Fracao.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#include "Fracao.h"
#include <iostream>

int calcularMDC(int,int);

Fracao::Fracao(int numerador, int denominador)
{
    this->numerador = numerador;
    this->denominador = denominador;
}

Fracao::~Fracao()
{
    //Do nothing
}

Fracao* Fracao::somar(Fracao &f1)
{
    int numerador = this->numerador * f1.denominador + f1.numerador * this->denominador;
    int denominador =this->denominador * f1.denominador;
    this->numerador = numerador;
    this->denominador = denominador;
    return this->simplificar();
}

Fracao* Fracao::subtrair(Fracao &f1)
{
    int numerador = this->numerador * f1.denominador - f1.numerador * this->denominador;
    int denominador =this->denominador * f1.denominador;
    this->numerador = numerador;
    this->denominador = denominador;
    return this->simplificar();
}

Fracao* Fracao::multiplicar(Fracao &f1)
{
    int numerador = this -> numerador * f1.numerador;
    int denominador = this -> denominador * f1.denominador;
    this -> numerador = numerador;
    this -> denominador = denominador;
    return this -> simplificar();
}

Fracao* Fracao::dividir(Fracao &f1)
{
    int numerador = this -> numerador / f1.numerador;
    int denominador = this -> denominador / f1.denominador;
    this -> numerador = numerador;
    this -> denominador = denominador;
    return this -> simplificar();
}

Fracao* Fracao::simplificar()
{
    int mdc = calcularMDC(this->numerador, this->denominador);
    
    this->numerador /= mdc;
    this->denominador /= mdc;
    
    return this;
}

void Fracao::imprimir()
{
    if( this->numerador == 0 )
    {
        std::cout << 0 << std::endl;
    }
    else if( this->denominador == 1 )
    {
        std::cout << this->numerador << std::endl;
    }
    else
    {
        std::cout << this->numerador << "/" << this->denominador << std::endl;
    }
}

int calcularMDC(int a, int b)
{
    if( b == 0 )
    {
        return a;
    }
    else
    {
        return calcularMDC(b, a % b);
    }
}
