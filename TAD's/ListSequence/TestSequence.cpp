//
//  TestSequence.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#include <iostream>
#include <string>
#include <cassert>
#include "Sequence.h"

using namespace std;

void printSequence(Sequence *sequence)
{
    for(int i = 0; i < sequence->getQuantity(); i++)
    {
        cout << i << " " << sequence->get(i) << endl;
    }
}

void testInsert()
{
    Sequence *sequence = new Sequence();
    assert( sequence->getQuantity()==0 );
    
    string str = "teste";
    
    for(int i = 1; i <= 10; i++)
    {
        int qtBefore = sequence->getQuantity();
        string inserted = str.append(to_string(i));
        
        sequence->insert(i, inserted);
        
        for(int j = 1; j < i; j++)
        {
            assert( sequence->get(j) != inserted );
        }
        
        // Certifique-se que foi incrementada a quantidade
        assert( sequence->getQuantity() == qtBefore+1);
        
        // Certifique-se que o i-esimo elemento é o que foi inserido
        assert( sequence->get(i) == inserted );
    }
    
    delete sequence;
    
    cout << "TestInsert OK" << endl;
}

void testRemove()
{
    Sequence *sequence = new Sequence();
    assert( sequence->getQuantity()==0 );
    
    string inserted1 = "teste1";
    string inserted2 = "teste2";
    
    sequence->insertBegin(inserted1);
    sequence->insertBegin(inserted2);
    
    int qtBefore = sequence->getQuantity();
    string removed1 = sequence->remove(1);
    assert(removed1 == inserted2);
    assert(sequence->getQuantity() == qtBefore-1);
    
    qtBefore = sequence->getQuantity();
    string removed2 = sequence->remove(1);
    assert(removed2 == inserted1);
    assert(sequence->getQuantity() == qtBefore-1);
    
    delete sequence;
    
    cout << "TestRemove OK" << endl;
}

void testAll()
{
    Sequence* sequence = new Sequence();
    assert( sequence->getQuantity()==0 );
    
    sequence->insertBegin("a");
    sequence->removeBegin();
    
    sequence->insertBegin("a");
    sequence->removeEnd();
    
    sequence->insertEnd("a");
    sequence->removeBegin();
    
    sequence->insertEnd("a");
    sequence->removeEnd();
    
    sequence->insertBegin("a");
    sequence->insertBegin("b");
    sequence->insertBegin("c");
    
    assert( sequence->getQuantity() == 3 );
    assert( sequence->get(1) == "c" );
    assert( sequence->get(2) == "b" );
    assert( sequence->get(3) == "a" );
    
    sequence->insertBegin("x");
    assert( sequence->getQuantity() == 4 );
    assert( sequence->get(1) == "x" );
    assert( sequence->get(2) == "c" );
    assert( sequence->get(3) == "b" );
    assert( sequence->get(4) == "a" );
    
    sequence->insertEnd("l");
    sequence->insertEnd("m");
    sequence->insertEnd("n");
    
    assert( sequence->getQuantity() == 7 );
    assert( sequence->get(1) == "x" );
    assert( sequence->get(2) == "c" );
    assert( sequence->get(3) == "b" );
    assert( sequence->get(4) == "a" );
    assert( sequence->get(5) == "l" );
    assert( sequence->get(6) == "m" );
    assert( sequence->get(7) == "n" );
    
    assert( sequence->removeBegin() == "x");
    
    assert( sequence->getQuantity() == 6 );
    assert( sequence->get(1) == "c" );
    assert( sequence->get(2) == "b" );
    assert( sequence->get(3) == "a" );
    assert( sequence->get(4) == "l" );
    assert( sequence->get(5) == "m" );
    assert( sequence->get(6) == "n" );
    
    assert( sequence->removeEnd() == "n" );
    assert( sequence->removeBegin() == "c");
    
    assert( sequence->getQuantity() == 4 );
    assert( sequence->get(1) == "b" );
    assert( sequence->get(2) == "a" );
    assert( sequence->get(3) == "l" );
    assert( sequence->get(4) == "m" );
    
    delete sequence;
    
    cout << "Test OK" << endl;
}

void testInsertBegin()
{
    Sequence* sequence = new Sequence();
    assert( sequence->getQuantity() == 0 );
    
    sequence->insertBegin("a");
    assert( sequence->getQuantity() == 1 );
    assert( sequence->get(1) == "a" );
    
    sequence->insertBegin("b");
    assert( sequence->getQuantity() == 2 );
    assert( sequence->get(1) == "b" );
    assert( sequence->get(2) == "a" );
    
    sequence->insertBegin("c");
    assert( sequence->getQuantity() == 3 );
    assert( sequence->get(1) == "c" );
    assert( sequence->get(2) == "b" );
    assert( sequence->get(3) == "a" );
    
    sequence->insertBegin("x");
    assert( sequence->getQuantity() == 4 );
    assert( sequence->get(1) == "x" );
    assert( sequence->get(2) == "c" );
    assert( sequence->get(3) == "b" );
    assert( sequence->get(4) == "a" );
    
    delete sequence;
    
    cout << "TestInsertBegin OK" << endl;
}

void testInsertEnd()
{
    Sequence* sequence = new Sequence();
    assert( sequence->getQuantity()==0 );
    
    sequence->insertEnd("a");
    assert( sequence->getQuantity() == 1 );
    assert( sequence->get(1) == "a" );
    
    sequence->insertEnd("b");
    assert( sequence->getQuantity() == 2 );
    assert( sequence->get(1) == "a" );
    assert( sequence->get(2) == "b" );
    
    sequence->insertEnd("c");
    assert( sequence->getQuantity() == 3 );
    assert( sequence->get(1) == "a" );
    assert( sequence->get(2) == "b" );
    assert( sequence->get(3) == "c" );
    
    sequence->insertEnd("x");
    assert( sequence->getQuantity() == 4 );
    assert( sequence->get(1) == "a" );
    assert( sequence->get(2) == "b" );
    assert( sequence->get(3) == "c" );
    assert( sequence->get(4) == "x" );
    
    delete sequence;
    
    cout << "TestInsertEnd OK" << endl;
}

void testRemoveBegin()
{
    Sequence* sequence = new Sequence();
    assert( sequence->getQuantity()==0 );
    
    sequence->insertBegin("a");
    assert( sequence->getQuantity() == 1 );
    assert( sequence->get(1) == "a" );
    
    assert( sequence->removeBegin() == "a" );
    assert( sequence->getQuantity()==0 );
    
    sequence->insertBegin("a");
    sequence->insertBegin("b");
    assert( sequence->getQuantity() == 2 );
    assert( sequence->get(1) == "b" );
    assert( sequence->get(2) == "a" );
    
    assert( sequence->removeBegin() == "b" );
    assert( sequence->getQuantity()== 1 );
    assert( sequence->get(1) == "a" );
    
    sequence->insertBegin("c");
    assert( sequence->getQuantity() == 2 );
    assert( sequence->get(1) == "c" );
    assert( sequence->get(2) == "a" );
    
    assert( sequence->removeBegin() == "c" );
    assert( sequence->getQuantity() == 1 );
    assert( sequence->removeBegin() == "a" );
    assert( sequence->getQuantity() == 0 );
    
    delete sequence;
    
    cout << "TestRemoveBegin OK" << endl;
}

void testRemoveEnd()
{
    Sequence* sequence = new Sequence();
    assert( sequence->getQuantity()==0 );
    
    sequence->insertBegin("a");
    assert( sequence->getQuantity() == 1 );
    assert( sequence->get(1) == "a" );
    
    assert( sequence->removeEnd() == "a" );
    assert( sequence->getQuantity()==0 );
    
    sequence->insertBegin("a");
    sequence->insertBegin("b");
    assert( sequence->getQuantity() == 2 );
    assert( sequence->get(1) == "b" );
    assert( sequence->get(2) == "a" );
    
    assert( sequence->removeEnd() == "a" );
    assert( sequence->getQuantity()== 1 );
    assert( sequence->get(1) == "b" );
    
    sequence->insertEnd("c");
    assert( sequence->getQuantity() == 2 );
    assert( sequence->get(1) == "b" );
    assert( sequence->get(2) == "c" );
    
    assert( sequence->removeEnd() == "c" );
    assert( sequence->getQuantity() == 1 );
    assert( sequence->removeEnd() == "b" );
    assert( sequence->getQuantity() == 0 );
    
    delete sequence;
    
    cout << "TestRemoveEnd OK" << endl;
}

int main(int argc, const char * argv[]) {
    testInsertBegin();
    testInsertEnd();
    
    testRemoveBegin();
    testRemoveEnd();
    
    testAll();
    
    testInsert();
    testRemove();
    
    return 0;
}
