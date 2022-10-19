//
// Created by Gabriel de Taxis on 24/09/2022.
//
#include <cstdlib>
#include <deque>
#include <iostream>
#include "asio.hpp"
#include <cstring>

// std::string read_(asio::ip::tcp::socket & socket) {
//        asio::streambuf buf;
//        asio::read_until( socket, buf, "\n" );
//        std::string data = asio::buffer_cast<const char*>(buf.data());
//        return data;
// }
// void send_(asio::ip::tcp::socket & socket, const std::string& message) {
//        const std::string msg = message + "\n";
//        asio::write( socket, asio::buffer(message) );
// }

using asio::ip::udp;

enum { max_length = 1024 };

void server(asio::io_context& io_context, unsigned short port)
{
  std::vector<udp::endpoint> AllClient;
  int _Player = 0;
  int Setup = 0;
  udp::socket sock(io_context, udp::endpoint(udp::v4(), port));
  int Turn = 0;
  for (;;)
  {
    char data[max_length];
    char sender[max_length];
    std::memset(&data, '\0', max_length);
    std::memset(&sender, '\0', max_length);
    udp::endpoint sender_endpoint;
    size_t length = sock.receive_from(asio::buffer(data, max_length), sender_endpoint);
    // std::cout << "Reply : " << data << std::endl;
    if (!strcmp(data, "Connexion::Ready::2")) {//|| Turn <= 3
      // std::cout << "OUPI - 2" << std::endl;
      std::memset(&sender, '\0', max_length);
      std::strcat(sender, "Connexion::2");
      _Player = 2;
    } else if (!strcmp(data, "Connexion::Ready::3")) {//|| Turn <= 3
      // std::cout << "OUPI - 3" << std::endl;
      std::memset(&sender, '\0', max_length);
      std::strcat(sender, "Connexion::3");
      _Player = 3;
    } else {
      char temp[max_length];
      snprintf(temp, max_length, "%s", data);
      std::memset(&sender, '\0', max_length);
      std::strcat(sender, temp);
    }
    // std::cout << "Sender 1 : " << sender << std::endl;
    int l = 0;
    for(int i = 0; i < AllClient.size(); i++) {
      if (AllClient.at(i) == sender_endpoint)
        l = 1;
    }
    if (l == 0)
      AllClient.push_back(sender_endpoint);
    if (AllClient.size() == _Player && Setup == 0) {
      char tmp[max_length];
        for (int a = 0; a < AllClient.size(); a++) {
              char tmp[max_length];
              std::memset(&tmp, '\0', max_length);
              char Number[max_length];
              snprintf(Number, max_length, "%d", a+1);
              std::strcat(tmp, sender);
              std::strcat(tmp, "::");
              std::strcat(tmp, Number);
              sock.send_to(asio::buffer(tmp, std::strlen(tmp)), AllClient.at(a));
              // std::cout << "| Socket CONNEXION Send a  [ " << a << " ] --> " << tmp << std::endl;
        }
        Setup=1;
    } else if (Setup == 1) {
      for (int a = 0; a < AllClient.size(); a++) {
        if (AllClient.at(a) != sender_endpoint) {
          sock.send_to(asio::buffer(sender, std::strlen(sender)), AllClient.at(a));
          // std::cout << "| Socket Send a  [ " << a << " ] --> " << sender << std::endl;
        }
      // std::memset(&data, '\0', max_length);
      }
    }
            // Turn++;
  }
}

int main()
{
   unsigned short port = 3335;
   asio::io_context io_context;

   server(io_context, port);

//    asio::io_service io_service_object;
//    asio::ip::tcp::acceptor 
//   acceptor_object(
//     io_service_object, 
//     asio::ip::tcp::endpoint(asio::ip::tcp::v4(), 
//                   9999));
//    asio::ip::tcp::socket socket_object(io_service_object);
//    acceptor_server.accept(server_socket);
//     asio::io_service io_service;
// //listen for new connection
//     asio::ip::tcp::acceptor acceptor_(io_service, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), 1234 ));
// //socket creation 
//     asio::ip::tcp::socket socket_(io_service);
// //waiting for connection
//       acceptor_.accept(socket_);
// //read operation
//       std::string message = read_(socket_);
//       std::cout << message << std::endl;
// //write operation
//       send_(socket_, "Hello From Server!");
//       std::cout << "Servent sent Hello message to Client!" << std::endl;
   return 0;
}