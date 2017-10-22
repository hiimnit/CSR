//
//  CSR.hpp
//  CSR
//
//  Created by Filip Soukup on 22/10/2017.
//  Copyright © 2017 Filip Soukup. All rights reserved.
//

#ifndef CSR_hpp
#define CSR_hpp

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

template <typename T>
class CSR {
    vector<T> * val;
    vector<int> * col;
    vector<int> * row;
    
    int n;
public:
    CSR(int);
    CSR(int, int);
    ~CSR();
    
    void construct(int);
    int getSize() const;
    T getVal(int, int) const;
    bool setVal(int, int, T);
    void print() const;
};

#endif /* CSR_hpp */
