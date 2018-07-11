//
//  main.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#include <iostream>
#include <cassert>
#include <fstream>
#include "Search.hpp"

using namespace std;

void readInput(const string, int, int[]);
void testSearch(int[], int);

const string MY_PATH = "input.txt";
const int SIZE = 500000;

int main(int argc, const char * argv[])
{
    int *v = new int[SIZE];
    readInput(MY_PATH, SIZE, v);

    testSearch(v, SIZE);

    std::cout << "All tests passed!" << std::endl;

    delete [] v;

    return 0;
}

void testSearch(int v[], int size)
{
    for( int i = 0; i < size; i+=100 )
    {
        int key = v[i];
        int index = search(v, size, key);
        assert( v[index] == key );
    }

    assert( search(v, size, -1)  == NOT_FOUND );
    assert( search(v, size, -10) == NOT_FOUND );
    assert( search(v, size, 65624)  == NOT_FOUND );
    assert( search(v, size, 65952)  == NOT_FOUND );
}

void readInput(const string path, int size, int v[]){
    ifstream file(path);

    if(!file.good())
    {
        cout << "ERROR: File does not exist: " << path << endl;
        exit(-1);
    }

    for( int i = 0; i < size; i++){
        int x;
        file >> x;
        v[i] = x;
    }

    file.close();
}
