//
//  VectorDemo.cpp
//  C++Demo
//
//  Created by lhp3851 on 2018/12/30.
//  Copyright © 2018 Jerry. All rights reserved.
//

#include "VectorDemo.hpp"
#include <iostream>
#include <vector>

using namespace std;
//函数
template<typename T>
void printer(const T& val) {
    cout << val << endl;
}

//仿函数
template<typename T>
struct functor
{
    void operator()(const T& obj)
    {
        cout << obj << endl;
    }
};

//Lambda
void lambdaPrinter(const vector<int>& valList) {
    for_each(valList.cbegin(), valList.cend(), [](const int& val)->void{cout << val << endl; });
}


//init
void init(){
    vector<int> v1;
    
    int a[4] = {0,1,2,3};
    vector<int> v5(5,*(a));
    
    cout << sizeof(v5) << "\n" << v5.size() << endl;
    
    v5.pop_back();
    v5.push_back(5);
    
    //迭代器
//    for (auto iter = v5.begin(); iter != v5.end(); iter ++) {
//        cout << *(iter) << endl;
//    }

//    for_each(v5.begin(), v5.end(), printer<int>);
    
//    for_each(v5.begin(), v5.end(), functor<int>());
    
//    lambdaPrinter(v5);
    
    //区间遍历
    for (auto val: v5) {
        cout << val << endl;
    }
}





