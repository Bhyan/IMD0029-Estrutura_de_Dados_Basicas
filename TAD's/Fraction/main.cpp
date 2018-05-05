//
//  main.cpp
//  Aula-Fracao
//
//

#include <iostream>
#include <cassert>
#include "Fracao.h"

void TestarSomar()
{
    Fracao f1 = Fracao(1, 3);
    Fracao f2 = *Fracao(1,3).somar( f1 );
    assert( f2.numerador == 2 );
    assert( f2.denominador == 3 );
}

void TestarSubtrair()
{
    Fracao f1 = Fracao(1, 3);
    Fracao f2 = *Fracao(1,3).subtrair( f1 );
    assert( f2.numerador == 0 );
}

void TestarMultiplicar()
{
    Fracao f1 = Fracao(1, 3);
    Fracao f2 = *Fracao(1,3).multiplicar( f1 );
    assert( f2.numerador == 1 );
    assert( f2.denominador == 9 );
}

void TestarDividir()
{
    Fracao f1 = Fracao(1, 3);
    Fracao f2 = *Fracao(1,3).dividir( f1 );
    assert( f2.numerador == 1 );
    assert( f2.denominador == 1 );
}

int main(int argc, const char * argv[]) {
    TestarSomar();
    TestarSubtrair();
    TestarMultiplicar();
    TestarDividir();
        
    Fracao f = Fracao(1,3);
    
    Fracao *f2 = Fracao(1,3).multiplicar( f )->dividir( f )->somar( f );

    assert(f2->numerador == 2);
    assert(f2->denominador == 3);

    std::cout << "Todos testes passaram.\n";
    
    return 0;
}
