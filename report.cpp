/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   report.cpp
 * Author: Artashes Amatuni
 * 
 * Created on December 28, 2017, 5:16 PM
 */

#include "report.h"

report::report() {
}

report::report(const report& orig) {
}

void report::setHost(char *hostname){
    host = hostname;
}

void report::setPort(int port){
    portno = port;
}

report::~report() {
}

/*
 

    int portno =        80;
    char *host =        "109.75.38.38";
    char *message_fmt = "POST /input/post.json?json={\"value\":25}&node=test&apikey=0ec8a75dd4f3c61789cd7ef909477e40 HTTP/1.1\r\nHost: 109.75.38.38\r\nConnection: close\r\n\r\n";
    
    
    struct hostent *server;
    struct sockaddr_in serv_addr;
    int sockfd, bytes, sent, received, total;
    char request[1024],response[4096];

    //if (argc < 3) { puts("Parameters: <apikey> <command>"); exit(0); }

    // fill in the parameters
    sprintf(request,message_fmt);
    printf("Request:\n%s\n",request);

    // create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("ERROR opening socket");

    // lookup the ip address
    server = gethostbyname(host);
    cout << server << endl;
    if (server == NULL) error("ERROR, no such host");

    // fill in the structure
    memset(&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    memcpy(&serv_addr.sin_addr.s_addr,server->h_addr,server->h_length);

    // connect the socket
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    // send the request
    total = strlen(request);
    sent = 0;
    do {
        bytes = write(sockfd,request+sent,total-sent);
        if (bytes < 0)
            error("ERROR writing message to socket");
        if (bytes == 0)
            break;
        sent+=bytes;
    } while (sent < total);

    // receive the response
    memset(response,0,sizeof(response));
    total = sizeof(response)-1;
    received = 0;
    do {
        bytes = read(sockfd,response+received,total-received);
        if (bytes < 0)
            error("ERROR reading response from socket");
        if (bytes == 0)
            break;
        received+=bytes;
    } while (received < total);

    if (received == total)
        error("ERROR storing complete response from socket");

    // close the socket
    close(sockfd);

    // process response
    printf("Response:\n%s\n",response);

 
 
 */
