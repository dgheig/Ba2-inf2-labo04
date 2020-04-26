/*
-----------------------------------------------------------------------------------
Laboratory  : labo_04
File        : labo_04_carvalho_bruno_gallay_david.cpp
Author(s)   : Carvalho Bruno et Gallay David
Date        : 

Purpose     : Prove the good working of classes defined in others files.
Remark(s)   :
                There is the github repository:

Compiler    : MinGW-g++ 6.3.0 and g++ 7.4.0
-----------------------------------------------------------------------------------*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include "src/temps.h"

using namespace std;

#define WAIT_ENTER while(cin.get()!='\n')

int main() {
    Temps<int> t1(1, 1, 1);
    Temps<float> t2(0, 0, 0);

    Temps<double> t3(1, 23, 45);

    std::cout << t1 << std::endl;
    std::cout << t2 << std::endl;
    std::cout << t3 << std::endl;
    std::cout << t3.asHeure() << std::endl;
    std::cout << t3.asMinute() << std::endl;
    std::cout << (Temps<int>)t2 << std::endl;
    std::cout << t1 + t1 << std::endl;
    std::cout << t1 + t2 << std::endl;
    std::cout << (float)t3 << std::endl;
    std::cout << (double)t3 << std::endl;
    std::cout << (long long)t3 << std::endl;
    std::cout << std::string(t3) << std::endl;
    try {
        t2 - t3;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    cout << "Please, press <ENTER> to end the program" << endl;
    WAIT_ENTER;
    return EXIT_SUCCESS;
}
