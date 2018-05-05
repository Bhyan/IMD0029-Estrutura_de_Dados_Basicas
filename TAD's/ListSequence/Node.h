//
//  Node.h
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#ifndef __Sequence__Node__
#define __Sequence__Node__

#include <string>

class Node
{
private:
    std::string value;
    Node* next;
public:
    Node();
    
    Node( std::string val );
    
    std::string getValue();
    
    void setValue(std::string val);
    
    Node* getNext();
    
    void setNext(Node* node);
};

#endif /* defined(__Sequence__Node__) */
