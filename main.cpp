/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Artashes Amatuni
 *
 * Created on December 26, 2017, 11:38 AM
 */

#include <cstdlib>

using namespace std;

/*
 * 
 */
int main(void) {
    
 struct addrinfo hints, *server;
 memset(&hints, 0, sizeof hints);
 hints.ai_family =  AF_INET;
 hints.ai_socktype = SOCK_STREAM;
 hints.ai_flags = AI_PASSIVE || SOCK_NONBLOCK;
 getaddrinfo(NULL, "125", &hints, &server);

 int sockfd = socket(server->ai_family, server->ai_socktype, server->ai_protocol);
 bind(sockfd, server->ai_addr, server->ai_addrlen);
 listen(sockfd, 10);
 
 struct sockaddr_storage client_addr;
 socklen_t addr_size = sizeof client_addr;
 char headers[] = "HTTP/1.0 200 OK\r\nServer: CPi\r\nContent-type: text/html\r\n\r\n";
 char buffer[2048];
 //char html[] = "<html><head><title>Temperature</title></head><body><p>{\"humidity\":81%,\"airtemperature\":23.5C}</p></body></html>\r\n";
 char html[] = "<html><head><title>Temperature</title></head><body><p>{\"humidity\":81%,\"airtemperature\":23.5C}</p></body></html>\r\n";
 //char html[] = "<!DOCTYPE HTML>\r\n<html>\r\n<br><input type=\"button\" name=\"bl\" value=\"Turn LED ON \" onclick=\"location.href='/ON'\"><br><br><br><br><input type=\"button\" name=\"bl\" value=\"Turn LED OFF\" onclick=\"location.href='/OFF'\"></html>\n";
 char data[2048] = {0};
 snprintf(data, sizeof data, "%s %s", headers, html);

 for (;;) {
  int client_fd = accept(sockfd, (struct sockaddr *) &client_addr, &addr_size);
  if (client_fd > 0)
  {
   int n = read(client_fd, buffer, 2048);
   printf("%s", buffer);
   fflush(stdout);
   n = write(client_fd, data, strlen(data));
   close(client_fd); 
  }
 }
 return 0;
}

