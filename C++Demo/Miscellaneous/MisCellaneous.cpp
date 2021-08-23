//
//  MisCellaneous.cpp
//  C++Demo
//
//  Created by Jerry on 2020/10/17.
//  Copyright © 2020 Jerry. All rights reserved.
//

#include <iostream>
#include "MisCellaneous.hpp"

void bitSet () {
    std::bitset<4> mask("1100");
    std::bitset<4> val("0111");
    val and_eq mask;
    std::cout << val << '\n';
    
    int i = 10;
    int &ref = i;
    int *p = &i;
    printf("%d, %d, %p:", i, ref, p);
}

