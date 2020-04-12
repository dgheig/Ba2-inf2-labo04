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
#include <cstdlib>
#include "src/rotor.h"
#include "src/enigma.h"

using namespace std;

#define WAIT_ENTER while(cin.get()!='\n')

int main() {
    Enigma enigma (REFLECTOR_B, {ROTOR_I, ROTOR_II, ROTOR_III});
    
    std::string s = "VIVELINFORMATIQUEALAHEIGVD";
    std::string crypted = enigma.encrypt(s);
    cout << s << std::endl;
    cout << crypted << std::endl;
    enigma.reset();
    cout << enigma.encrypt(crypted) << std::endl;

    cout << "Please, press <ENTER> to end the program" << endl;
    WAIT_ENTER;
    return EXIT_SUCCESS;
}
