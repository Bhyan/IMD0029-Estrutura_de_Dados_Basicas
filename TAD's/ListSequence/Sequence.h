//
//  Sequence.h
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#ifndef __Sequence__Sequence__
#define __Sequence__Sequence__


#include <string>
#include <iostream>
#include "Node.h"

class Sequence
{
private:
    Node *first;
    int quantity;
    
public:
    Sequence();
    
    ~Sequence();
    
    /**
     Returns the i-th element in this sequence.
     */
    std::string get(int i);
    
    /**
     Inserts the element in this sequence. After inserting, the element must be in the i-th position.
     */
    void insert(int i, std::string element);
    
    /**
     Inserts the element in the begin of this sequence.
     */
    void insertBegin(std::string element);
    
    /**
     Inserts the element in the end position of this sequence.
     */
    void insertEnd(std::string element);
    
    /**
     Removes the element in the i-th position of this sequence.
     Returns the removed element.
     */
    std::string remove(int i);
    
    /**
     Removes the element in begin of this sequence.
     Returns the removed element.
     */
    std::string removeBegin();
    
    /**
     Removes the element in begin of this sequence.
     Returns the removed element.
     */
    std::string removeEnd();
    
    /**
     Checks whether the sequence is empty or not.
     */
    bool isEmpty();
    
    /**
     Returns the quantity of elements in the sequence.
     */
    int getQuantity();

    void setFirst(Node* n);

    Node* getFirst();
};

#endif /* defined(__Sequence__Sequence__) */
