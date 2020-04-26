/*
-----------------------------------------------------------------------------------
Laboratory  : labo_04
File        : exceptions.h
Author(s)   : Carvalho Bruno et Gallay David
Date        : 

Purpose     : Defining customs exceptions
Remark(s)   :   
                There is the github repository:

Compiler    : g++ 7.4.0
-----------------------------------------------------------------------------------*/

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

class negative_value: public std::invalid_argument {
    public:
        negative_value(const char* msg): std::invalid_argument(msg) {}
        negative_value(std::string msg): negative_value(msg.c_str()) {}

        // virtual const char* what() const noexcept {
        //     return ;
        // }
};


#endif // EXCEPTIONS_H