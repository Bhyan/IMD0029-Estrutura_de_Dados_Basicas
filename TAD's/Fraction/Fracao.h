//
//  Fracao.hpp
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#ifndef Fracao_h
#define Fracao_h

class Fracao {
public:
    int numerador;
    int denominador;
    
    Fracao(int,int);
    ~Fracao();
    Fracao* somar(Fracao&);
    Fracao* subtrair(Fracao&);
    Fracao* multiplicar(Fracao&);
    Fracao* dividir(Fracao&);
    void imprimir();
    Fracao* simplificar();
};

#endif /* Fracao_h */
