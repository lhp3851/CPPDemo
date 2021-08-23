//
//  main.cpp
//  C++Demo
//
//  Created by lhp3851 on 2018/12/30.
//  Copyright © 2018 Jerry. All rights reserved.
//

#include <iostream>
#include "Vector/VectorDemo.hpp"
#include "Networking/sync_client.hpp"
#include "Networking/asio/asio_demo.cpp"

using namespace std;

class StringAppend{
public:
    explicit StringAppend(const string& str) : ss(str){}
    
    void operator() (const string& str) const{
        cout<<str<<' '<<ss<<endl;
    }
    
private:
    const string ss;
};

struct test {
    char a;
    char b;
    short c; 
    int d;
};


int main(int argc, const char * argv[]){
    
//    boost::asio::io_service service;
//
//    Server *server = new Server(service, 9000);
    
//    server->run();
    
    std::bitset<4> b("0000");
    
    std::bitset<4> c("0010");
    
    printf("%d, %d:", b.any(), c.any());
    
    
    return 0;
}



