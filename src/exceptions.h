/*
-----------------------------------------------------------------------------------
Laboratory  : labo_04
File        : exceptions.h
Author(s)   : Carvalho Bruno et Gallay David
Date        : 

Purpose     : Defining customs exceptions
Remark(s)   : We did not define what() function overload
              since we use std::invalid_argument's one

              In my opinion, defining this class is a theorical exercise
              std::invalid_argument was more than good enough for all the needs
              of this project
              
                There is the github repository:
                https://github.com/dgheig/Ba2-inf2-labo04

Compiler    : g++ 7.4.0
-----------------------------------------------------------------------------------*/

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

class negative_value: public std::invalid_argument {
    public:
        /**
         * @brief Constructor
         * @param msg error message
         */
        negative_value(const char* msg): std::invalid_argument(msg) {}
        
        /**
         * @brief Constructor
         * @param msg error message
         */
        negative_value(std::string msg): negative_value(msg.c_str()) {}
};


#endif // EXCEPTIONS_H