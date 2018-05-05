//
//  Node.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#include "Node.h"

Node::Node()
{
    this->setNext(NULL);
}

Node::Node( std::string val )
{
    this->setValue(val);
    this->setNext(NULL);
}

std::string Node::getValue()
{
    return this->value;
}

void Node::setValue(std::string val)
{
    this->value = val;
}

Node* Node::getNext()
{
    return this->next;
}

void Node::setNext(Node* node)
{
    this->next = node;
}
