//
//  asio_demo.cpp
//  C++Demo
//
//  Created by lhp3851 on 2019/1/5.
//  Copyright © 2019 Jerry. All rights reserved.
//

#include "asio_demo.hpp"
#include <stdio.h>
#include <string>
#include <boost/asio.hpp>

using namespace std;

using boost::asio::ip::tcp;

static string url = "https://httpbin.org/get";

// 服务器和某个客户端之间的“会话”
// 负责处理读写事件
class Session : public std::enable_shared_from_this<Session> {
    
public:
    Session(tcp::socket s) : socket_(std::move(s)) {}

    void start()
    {
        async_read();
    }
    
private:
    void async_read()
    {
        auto self(shared_from_this());
        socket_.async_read_some(boost::asio::buffer(data_),  // 异步读
                                [this, self](const boost::system::error_code &ec, size_t bytes_transferred)  // 读操作完成时回调该函数
                                {  // 捕获`self`使shared_ptr<session>的引用计数增加1，在该例中避免了async_read()退出时其引用计数变为0
                                    if (!ec)
                                        async_write(bytes_transferred);  // 读完即写
                                }
                                );
    }

    void async_write(std::size_t length)
    {
        auto self(shared_from_this());
        boost::asio::async_write(socket_, boost::asio::buffer(data_, length),  // 异步写
                                 [this, self](const boost::system::error_code &ec, size_t)
                                 {
                                     if (!ec)
                                         async_read();
                                 }
                                 );
    }

    tcp::socket socket_;  // “会话”基于已经建立的socket连接
    std::array<char, 1024> data_;
};

// 服务器类
// 监听客户端连接请求（async_accept）。与某个客户端建立socket连接后，为它创建一个session
class Server {
    
public:
    Server(boost::asio::io_service &io_service, int port)
    : acceptor_(io_service, tcp::endpoint(tcp::v4(), port)), socket_(io_service)
    {
        async_accept();
    }

    void run(){
        printf("kldfsldfsljdfjklsj");
        boost::asio::io_service io_service;
        Server listen = Server(io_service,52014);
        io_service.run();
    }

private:
    void async_accept()
    {
        acceptor_.async_accept(socket_, std::bind(&Server::handle_accept, this, std::placeholders::_1));  // 异步accept。socket连接建立后，调用handle_accept()
    }

    void handle_accept(const boost::system::error_code &ec)
    {
        if (!ec)
        {
            std::shared_ptr<Session> session_ptr(new Session(std::move(socket_)));
            session_ptr->start();
        }

        async_accept();  // 继续监听客户端连接请求
    }

    tcp::acceptor acceptor_;
    tcp::socket socket_;
};
