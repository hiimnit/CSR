//
//  COO.hpp
//  CSR
//
//  Created by Filip Soukup on 29/10/2017.
//  Copyright © 2017 Filip Soukup. All rights reserved.
//

#ifndef COO_hpp
#define COO_hpp

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

template <typename T>
class COO {
    vector<T> * val;
    vector<int> * col;
    vector<int> * row;
    
    int n;
public:
    COO(int);
    COO(int, int);
    ~COO();
    
    void construct(int);
    int getSize() const;
    T getVal(int, int) const;
    bool setVal(int, int, T);
    void print() const;
};

#endif /* COO_hpp */
