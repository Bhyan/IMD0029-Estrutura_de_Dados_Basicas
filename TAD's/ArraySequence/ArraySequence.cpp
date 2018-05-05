//
//  ArraySequence.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#include <iostream>
#include "Sequence.h"
#include "Node.h"

Node **content;
const int SIZE = 7;
unsigned int init;
unsigned int end;

Sequence::Sequence()
{
    content = new Node*[SIZE];
    this->quantity = 0;
    init = 0;
    end = 0;
}

Sequence::~Sequence()
{
    // TO - DO
    delete [] content;
}

/**
 Returns the i-th element in this sequence.
 */
Node* Sequence::get(int i)
{
    return content[i - 1];
}

/**
 Inserts the element in this sequence.
 After inserting, the element must be in the i-th position.
 */
void Sequence::insert(int i, Node* element)
{
    if(this->quantity != 0){
        for(int posicao = end; posicao > i - 1; posicao --){
            content[posicao] = content[posicao - 1];
        }
    }
    content[i - 1] = element;
    end ++;
    this->quantity ++;
}

/**
 Inserts the element in the begin of this sequence.
 After inserting, the element will be the first in the sequence.
 */
void Sequence::insertBegin(Node* element)
{
/*
    if(this -> quantity != 0){
        for(unsigned int i = end; i > 0; i --){
            content[i] = content[i - 1];
        }
    }
    
    content[init] = element;
    end ++;
    this -> quantity ++;
*/
    insert(1, element);
}

/**
 Inserts the element in the end position of this sequence.
 After inserting, the element will be the last in the sequence.
 */
void Sequence::insertEnd(Node* element)
{
/*
    content[end] = element;
    end ++;
    this -> quantity ++;
*/
    insert(end+1, element);
}

/**
 Removes the element in the i-th position of this sequence.
 Returns the removed element.
 */
Node* Sequence::remove(int i)
{
    Node* copia = new Node(content[i-1]->getValue()); 

    for(int unsigned posicao = i-1; posicao < end; posicao++)
    {
        content[posicao] = content[posicao+1];
    }

    this->quantity--; 
    end--;

    return copia;
}

/**
 Removes the first element in this sequence.
 Returns the removed element.
 */
Node* Sequence::removeBegin()
{
/*    Node *copia = new Node(content[init] -> getValue());

    for(unsigned int i = 0; i < end; i ++){
        content[i] = content[i + 1];
    }
    this -> quantity --;
    end --;

    return copia;
*/
    return remove(1);
}

/**
 Removes the last element in this sequence.
 Returns the removed element.
 */
Node* Sequence::removeEnd()
{
/*
    if(this->quantity == 0){ 
        return nullptr;
    }

    Node *copia = new Node(content[end - 1] -> getValue());

    this -> quantity --;
    end --;

    return copia;
*/
    return remove(end);
}

bool Sequence::isEmpty()
{
    return this->getQuantity()==0;
}

int Sequence::getQuantity()
{
    return this->quantity;
}
