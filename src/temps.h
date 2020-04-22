/*
-----------------------------------------------------------------------------------
Laboratory  : labo_04
File        : temps.h
Author(s)   : Carvalho Bruno et Gallay David
Date        : 

Purpose     : 
Remark(s)   :
                There is the github repository:

Compiler    : g++ 7.4.0
-----------------------------------------------------------------------------------*/

#ifndef TEMPS_H
#define TEMPS_H
#include <iostream>

template <typename T>
class Temps {
    public:
        //Constructeurs
        Temps(T heure, T minute, T seconde);
        Temps(const Temps& t);
        Temps(T seconde);

        //Getters
        T getHeure() const;
        T getMinute() const;
        T getSeconde() const;

        std::ostream& print(std::ostream& stream=std::cout) const;

        //Setters
        void setHeure(T heure);
        void setMinute(T minute);
        void setSeconde(T seconde);

        //Operators
        Temps& operator=(const Temps& t);
        bool operator==(const Temps& t) const;
        bool operator!=(const Temps& t) const;
        Temps& operator+=(const Temps& t);
        Temps& operator-=(const Temps& t);

        //Castings

    private:
        T _heure;
        T _minute;
        T _seconde;
};


// template <typename T1, typename T2, typename R>
// Temps<R> operator+(Temps<T1> t1, const Temps<T2>& t2);

template <typename T>
Temps<T> operator+(Temps<T> t1, const Temps<T>& t2);

// template <typename T1, typename T2, typename R>
// Temps<R> operator-(Temps<T1> t1, const Temps<T2>& t2);

template <typename T>
Temps<T> operator-(Temps<T> t1, const Temps<T>& t2);


template <typename T>
std::ostream& operator<<(std::ostream& stream, Temps<T> temps);


#include "temps.ipp"
#endif // TEMPS_H
