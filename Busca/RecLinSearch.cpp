//
//  RecLinearSearch.cpp
//  Recursive Linear Search
//
//  Created by Eiji Adachi Medeiros Barbosa 
//

#include "Search.hpp"

int search(int v[], int size, int key, int begin)
{
    if(size == 0) return -1;

    else if(key == v[size]){
        return size;
    }

    else{
        return search(v, size - 1, key, 0);
    }
}
