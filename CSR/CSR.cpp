//
//  CSR.cpp
//  CSR
//
//  Created by Filip Soukup on 22/10/2017.
//  Copyright © 2017 Filip Soukup. All rights reserved.
//

#include "CSR.hpp"

template <typename T>
CSR<T>::CSR(int n) : n(n) {
    if (n <= 0) {
        return;
    }
    
    construct(n * n / 10);
};

template <typename T>
CSR<T>::CSR(int n, int reserve) : n(n) {
    if (n <= 0) {
        return;
    }
    
    construct(reserve);
};

// TODO:
// konstruktor s poctem nenulovych pro rezervaci
template <typename T>
void CSR<T>::construct(int reserve) {
    val = new vector<T>();
    val->reserve(reserve);
    col = new vector<int>();
    col->reserve(reserve);
    
    row = new vector<int>(n + 1, 0); // posledni vzdy = delce val/col
};

template <typename T>
CSR<T>::~CSR() {
    if (row != NULL)
        delete row;
    if (col != NULL)
        delete col;
    if (val != NULL)
        delete val;
};

template <typename T>
int CSR<T>::getSize() const {
    return n;
};

template<typename T>
T CSR<T>::getVal(int x, int y) const {
    if (x >= n || y >= n || x < 0 || y < 0)
        return T{}; // error

    /*
    for (int i = (*row)[x]; i < (*row)[x + 1]; ++i)
        if ((*col)[i] == y)
            return (*val)[i]; // puleni?
    */
    int offset = (*row)[x];
    int d = (*row)[x + 1] - offset;
    int q;
    while (true) {
        q = d / 2;
        if (q == d)
            break;
        
        if ((*col)[offset + q] == y)
            return (*val)[offset + q];
        
        if ((*col)[offset + q] < y)
            offset += d - q;
        
        d = q;
    }
    
    return T{};
};

template<typename T>
bool CSR<T>::setVal(int x, int y, T value) {
    bool update = false;
    
    if (x >= n || y >= n || x < 0 || y < 0)
        return false; // error

    // TODO: lepsi porovnani s nulou
    if ((*row)[x] == (*row)[x + 1]) {
        if (value != 0) {
            // vlozit v row[x]
            auto it1 = val->cbegin() + (*row)[x];
            val->emplace(it1, value);
            auto it2 = col->cbegin() + (*row)[x];
            col->emplace(it2, y); // mozna it - 1
            update = true;
        }
    } else {
        int i = (*row)[x];
        if (y < (*col)[i]) {
            auto it1 = val->cbegin() + i;
            val->emplace(it1, value);
            auto it2 = col->cbegin() + i;
            col->emplace(it2, y); // mozna it - 1
            update = true;
        } else {
            int offset = i;
            int d = (*row)[x + 1] - i;
            int q;
            while (true) {
                q = d / 2;
                
                if ((*col)[offset + q] == y) {
                    (*val)[offset + q] = value;
                    break;
                    
                } else if (q == 0) {
                    auto it1 = val->cbegin() + offset + 1;
                    val->emplace(it1, value);
                    auto it2 = col->cbegin() + offset + 1;
                    col->emplace(it2, y); // mozna it - 1
                    update = true;
                    break;
                } else if ((*col)[offset + q] < y)
                    offset += d - q;
                
                d = q;
            }
        }
    }
    
    if (update)
        for_each(row->begin() + x + 1, row->end(), [](int &n){ n++; }); // mozna x + 1
    
    
    return true;
};

template<typename T>
void CSR<T>::print() const {
    cout << " value : ";
    for (auto it = val->cbegin(); it < val->cend(); ++it)
        cout << *it << ' ';
    
    cout << endl << " col   : ";
    for (auto it = col->cbegin(); it < col->cend(); ++it)
        cout << *it << ' ';
    
    cout << endl << " row   : ";
    for (auto it = row->cbegin(); it < row->cend(); ++it)
        cout << *it << ' ';
    
    cout << endl;
};

template class CSR<int>;
template class CSR<double>;
template class CSR<float>;

