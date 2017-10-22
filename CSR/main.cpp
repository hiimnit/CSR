//
//  main.cpp
//  CSR
//
//  Created by Filip Soukup on 22/10/2017.
//  Copyright © 2017 Filip Soukup. All rights reserved.
//

#include <iostream>
#include "CSR.hpp"

int main(int argc, const char * argv[]) {
    CSR<float> * c;
    c = new CSR<float>(5);
  
    c->setVal(0, 0, 5);
    c->setVal(1, 1, 6);
    c->setVal(2, 2, 7);
    c->setVal(3, 3, 8);
    c->setVal(4, 4, 9);

    c->setVal(2, 4, 1);
    c->setVal(2, 1, 2);
    
    c->print();

    cout << c->getVal(3, 3) << endl;
    cout << c->getVal(3, 4) << endl;

    return 0;
}
