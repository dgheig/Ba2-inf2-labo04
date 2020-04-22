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
#include <string>

template <typename T>
class Temps {
    public:
        //Constructeurs
        Temps(T heure, T minute, T seconde);
        template<typename U>
        Temps(const Temps<U>& t);
        Temps(const Temps& t);
        Temps(T seconde);

        //Getters
        T getHeure() const;
        T getMinute() const;
        T getSeconde() const;

        T asHeure() const;
        T asMinute() const;
        T asSeconde() const;

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

        template<typename U>
        Temps<T>& operator+=(const Temps<U>& t);
        template<typename U>
        Temps<T>& operator-=(const Temps<U>& t);

        //Castings
        // template<typename U>
        // operator U() const;

        operator float() const;
        operator double() const;
        operator long long() const;
        operator std::string() const;

    private:
        T _heure;
        T _minute;
        T _seconde;
};


template <typename T1, typename T2>
Temps<T1> operator+(Temps<T1> t1, const Temps<T2>& t2);

template <typename T1, typename T2>
Temps<T1> operator-(Temps<T1> t1, const Temps<T2>& t2);

template <typename T>
std::ostream& operator<<(std::ostream& stream, Temps<T> temps);


#include "temps.ipp"
#endif // TEMPS_H
