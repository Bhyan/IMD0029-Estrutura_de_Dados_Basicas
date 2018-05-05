//
//  Node.hpp
//
//  Created by Eiji Adachi Medeiros Barbosa 
//

#ifndef Node_hpp
#define Node_hpp

#include <string>

class Node
{
private:
    std::string value;
public:
    Node();
    
    Node( std::string val );
    
    std::string getValue();
    
    void setValue(std::string val);
};
#endif /* Node_hpp */
