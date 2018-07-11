//
//  RecBinSearch.cpp
//  Recursive Binary Search
//
//  Created by Eiji Adachi Medeiros Barbosa 
//

#include "Search.hpp"

int search(int v[], int size, int key, int begin)
{
    if(begin > size) return -1;

    int meio = (begin + size) / 2;

    if(key < v[meio]){
        return search(v, size, key, meio - 1);
    }
    else if(key > v[meio]){
        return search(v, meio + 1, key, size);
    }
    else return meio;
}
