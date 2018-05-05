//
//  LinkedList.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList()
{
    this->head = new Node<string>();
    this->tail = new Node<string>();
    
    this->head->setNext(this->tail);
    this->head->setPrevious(NULL);

    this->tail->setNext(NULL);
    this->tail->setPrevious(this->head);

    this->quantity = 0;
}

LinkedList::~LinkedList()
{
    // TO-DO
}

Node<string>* LinkedList::getHead(void)
{
    return this->head;
}

Node<string>* LinkedList::getTail(void)
{
    return this->tail;
}

int LinkedList::getQuantity(void)
{
    return this->quantity;
}

bool LinkedList::isEmpty(void)
{
    return this->quantity == 0;
}

string LinkedList::get(int i)
{
    if( i < 1 || i > this->getQuantity())
    {
        std::cout << "Valor do índice de busca deve estar entre [1, quantity].\n";
        return "";
    }
	if( this->isEmpty() )
	{
		std::cout << "Não há elementos a serem retornados, pois lista está vazia.\n";
        return "";
	}
		
    int counter = 1;
    
    string result;
    for(Node<string>* n = this->head->getNext(); n != this->tail; n = n->getNext())
    {
        if( i == counter )
        {
            result = n->getValue();
            break;
        }
        counter++;
    }
    
    return result;
}

int LinkedList::search(string s)
{
    Node<string> *aux = this -> head -> getNext();
    int index = 1;

    while(aux != this -> tail){
        if(aux -> getValue() != s){
            aux = aux -> getNext();
            index ++;
        }
        else{
            return index;
        }
    }

//	std::cout << "\tERRO - Método search ainda não foi implementado.\n";
    
    return -1;
}

bool LinkedList::insertBegin(string s)
{
    Node<string> *aux = this -> head -> getNext();
    Node<string> *n_insert = new Node<string>(s);

    this -> head -> setNext(n_insert);
    aux -> setPrevious(n_insert);
    n_insert -> setPrevious(this -> head);
    n_insert -> setNext(aux);

    ++ this -> quantity;

//   	std::cout << "\tERRO - Método insertBegin ainda não foi implementado.\n";
    return true;
}

bool LinkedList::insertEnd(string s)
{
    Node<string> *aux = this -> tail -> getPrevious();
    Node<string> *n_insert = new Node<string>(s);

    this -> tail -> setPrevious(n_insert);
    aux -> setNext(n_insert);
    n_insert -> setPrevious(aux);
    n_insert -> setNext(this -> tail);

    ++ this -> quantity;

//	std::cout << "\tERRO - Método insertEnd ainda não foi implementado.\n";

    return true;
}

bool LinkedList::insert(int i, string s)
{
    Node<string> *aux = this -> head -> getNext();
    Node<string> *prev = nullptr;
    Node<string> *n_insert = new Node<string>(s);
    int cont = 1;

    while(aux != this -> tail && cont < i){
        aux = aux -> getNext();
        cont ++;
    }

    prev = aux -> getPrevious();
    prev -> setNext(n_insert);
    aux -> setPrevious(n_insert);
    n_insert -> setPrevious(prev);
    n_insert -> setNext(aux);

    ++ this -> quantity;
//    std::cout << "\tERRO - Método insert ainda não foi implementado.\n";

    return true;
}

string LinkedList::removeEnd(void)
{
    Node<string> *aux = this -> tail -> getPrevious();
    Node<string> *prev = aux -> getPrevious();
    string result;

    this -> tail -> setPrevious(prev);
    prev -> setNext(this -> tail);
    
    result = aux -> getValue();

    delete aux;

    -- this -> quantity;

//    std::cout << "\tERRO - Método removeEnd ainda não foi implementado.\n";

    return result;
}

string LinkedList::removeBegin(void)
{
    Node<string> *aux = this -> head -> getNext();
    Node<string> *next = aux -> getNext();
    string result;

    this -> head -> setNext(next);
    next -> setPrevious(this -> head);

    result = aux -> getValue();

    delete aux;

    -- this -> quantity;

//    std::cout << "\tERRO - Método removeBegin ainda não foi implementado.\n";
    return result;
}

string LinkedList::remove(int indice)
{
    Node<string> *aux = this -> head -> getNext();
    Node<string> *prev = nullptr;
    Node<string> *next = nullptr;
    string result;
    int cont = 1;

    while(aux != this -> tail && cont != indice){
        aux = aux -> getNext();
        cont ++;
    }

    prev = aux -> getPrevious();
    next = aux -> getNext();

    prev -> setNext(next);
    next -> setPrevious(prev);

    result = aux -> getValue();

    delete aux;

    -- this -> quantity;

//    std::cout << "\tERRO - Método remove ainda não foi implementado.\n";

    return result;
}

void LinkedList::print(void)
{
	for(Node<string>* n = this->head->getNext(); n != this->tail; n = n->getNext())
	{
		std::cout << n->getValue() << " ";
	}
	std::cout << std::endl;
}

ListStatus LinkedList::checkConsistency()
{
	if( this->head == NULL )
	{
		return HeadNull;
	}
	else if( this->head->getNext() == NULL )
	{
		return HeadNextNull;
	}
	else if( this->head->getNext()->getPrevious() != this->head )
	{
		return IncorrectLink;
	}
	else if( this->head->getPrevious() != NULL )
	{
		return HeadPrevious;
	}
	
	if( this->tail == NULL )
	{
		return TailNull;
	}
	else if( this->tail->getPrevious() == NULL )
	{
		return TailPreviousNull;
	}
	else if( this->tail->getPrevious()->getNext() != this->tail )
	{
		return IncorrectLink;
	}
	else if( this->tail->getNext() != NULL )
	{
		return TailNext;
	}
	
	if(this->isEmpty())
	{
		if( this->head->getNext() != this->tail )
		{
			return HeadTail;
		}
		
		if( this->head != this->tail->getPrevious() )
		{
			return HeadTail;
		}
	}
	else
	{
		// Verifica encadeamento dos elementos
		for(Node<string>* i = this->head->getNext(); i != this->tail; i=i->getNext())
		{
			if( i->getNext()->getPrevious() != i )
			{
				return IncorrectLink;
			}
			if( i->getPrevious()->getNext() != i )
			{
				return IncorrectLink;
			}
		}
	}
	
	return OK;
}
