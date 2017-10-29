//
//  main.cpp
//  CSR
//
//  Created by Filip Soukup on 22/10/2017.
//

#include <iostream>
#include "CSR.hpp"

void doolittle(int d, CSR<double> * c) {
    for (int k = 0; k < d; ++k) {
        for (int j = k; j < d; ++j) {
            double sum = 0.;
            for (int p = 0; p < k; ++p)
               sum += c->getVal(k, p) * c->getVal(p, j);
            c->setVal(k, j, c->getVal(k, j) - sum); // not dividing by diagonals
        }
        for (int i = k + 1; i < d; ++i){
            double sum = 0.;
            for (int p = 0; p < k; ++p)
                sum += c->getVal(i, p) * c->getVal(p, k);
            c->setVal(i, k, (c->getVal(i, k) - sum) / c->getVal(k, k));
        }
    }
}

int main(int argc, const char * argv[]) {
    /*
    CSR<double> * c;
    c = new CSR<double>(5);
    
    c->setVal(0, 0, 5);
    c->setVal(1, 1, 6);
    c->setVal(2, 2, 7);
    c->setVal(3, 3, 8);
    c->setVal(4, 4, 9);

    c->setVal(2, 4, 1);
    c->setVal(2, 1, 2);
    
    c->print();

    doolittle(5, c);
    
    c->print();
    */
    
    CSR<int> * qq = new CSR<int>(5);
    for(int i = 0; i < 5; ++i)
        for(int j = 0; j < 5; ++j)
            qq->setVal(i, j, i * 10 + j);
    
    qq->print();
    
    for(int i = 0; i < 5; ++i) {
        for(int j = 0; j < 5; ++j)
            cout << qq->getVal(i, j) << ' ';
        cout << endl;
    }
    
    return 0;
}
