/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   report.h
 * Author: Artashes Amatuni
 *
 * Created on December 28, 2017, 5:16 PM
 */

#ifndef REPORT_H
#define REPORT_H

#include <stdio.h>
#include <stdlib.h>
//**************  testing web  **********
#include <unistd.h> /* read, write, close */
#include <sys/socket.h> /* socket, connect */
#include <netinet/in.h> /* struct sockaddr_in, struct sockaddr */
#include <netdb.h> /* struct hostent, gethostbyname */
#include <cstdlib>
#include <string.h>
void error(const char *msg) { perror(msg); exit(0); }

class report {
public:
    report();
    report(const report& orig);
    void setHost(char *hostname);
    void setPort(int port);
    virtual ~report();
private:
    int portno;
    char *host;
};

#endif /* REPORT_H */

