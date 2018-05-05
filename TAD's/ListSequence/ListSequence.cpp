//
//  Sequence.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#include "Sequence.h"
#include "Node.h"


Sequence::Sequence()
{
    this->first = NULL;
    this->quantity = 0;
}

Sequence::~Sequence()
{
    // TO - DO
}

/**
 Returns the i-th element in this sequence.
 */
std::string Sequence::get(int i)
{
    if (i > this->getQuantity())
    {
        throw "ERRO:Sequencia::get - Posição inválida";
    }

    Node* curr = first;
    int counter = 1;
    
    while( curr!= NULL && counter < i )
    {
        curr = curr->getNext();
        counter++;
    }
    
    return curr->getValue();
}

Node* Sequence::getFirst(){
    return this->first;

}

void Sequence::setFirst(Node* n){
    this->first = n;

}


/**
 Inserts the element in this sequence.
 After inserting, the element must be in the i-th position.
 */
void Sequence::insert(int i, std::string element)
{
    // TO - DO
    Node *aux = this -> getFirst();
    Node *new_node = new Node(element);
    int cont = 1;

    if(this -> isEmpty() || i == 1){
        insertBegin(element);
    }
    else{
        while(aux -> getNext() != nullptr && cont != i - 1){
            aux = aux -> getNext();
            cont ++;
        }

        new_node -> setNext(aux -> getNext());
        aux -> setNext(new_node);

        ++ this -> quantity;
    }
}

/**
 Inserts the element in the begin of this sequence.
 After inserting, the element will be the first in the sequence.
 */
void Sequence::insertBegin(std::string element)
{
    // TO - DO
    Node *aux = new Node(element);

    if(this -> getFirst() != nullptr){
        aux -> setNext(this -> getFirst());
    }

    this -> setFirst(aux);
    ++ this -> quantity;
}

/**
 Inserts the element in the end position of this sequence.
 After inserting, the element will be the last in the sequence.
 */
void Sequence::insertEnd(std::string element)
{
    // TO - DO
    Node *aux = this -> getFirst();
    Node *new_node = new Node(element);

    if(this -> isEmpty()){
        this -> setFirst(new_node);
    }
    else{
        while(aux -> getNext() != nullptr){
            aux = aux -> getNext();
        }
        aux -> setNext(new_node);
    }

    ++ this -> quantity;
}

/**
 Removes the element in the i-th position of this sequence.
 Returns the removed element.
 */
std::string Sequence::remove(int i)
{
    // TO - DO
    Node *aux = this -> getFirst();
    Node *prev = nullptr;
    int cont = 1;
    std::string result;

    if(this -> isEmpty() || i == 1){
        return removeBegin();
    }
    else{
        while(aux -> getNext() != nullptr && cont != i - 1){
            prev = aux;
            aux = aux -> getNext();
            cont ++;
        }
        
        prev -> setNext(aux -> getNext());

        result = aux -> getValue();

        delete aux;

        -- this -> quantity;
    }

    return result;
}

/**
 Removes the first element in this sequence.
 Returns the removed element.
 */
std::string Sequence::removeBegin()
{
    // TO - DO
    Node *aux = this -> getFirst();
    std::string result;

    this -> setFirst(aux -> getNext());
    result = aux -> getValue();

    delete aux;
    -- this -> quantity;

    return result;
}

/**
 Removes the last element in this sequence.
 Returns the removed element.
 */
std::string Sequence::removeEnd()
{
    // TO - DO
    Node *aux = this -> getFirst();
    Node *prev = nullptr;
    std::string result;

    if(this -> quantity == 1){
        return removeBegin();
    }
    else{
        while(aux -> getNext() != nullptr){
            prev = aux;
            aux = aux -> getNext();
        }

        prev -> setNext(nullptr);

        result = aux -> getValue();
    }

    delete aux;

    -- this -> quantity;

    return result;
}

bool Sequence::isEmpty()
{
    return this->getQuantity()==0;
}

int Sequence::getQuantity()
{
    return this->quantity;
}
