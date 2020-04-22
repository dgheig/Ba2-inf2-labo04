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

#ifndef TEMPS_IPP
#define TEMPS_IPP

#define SEC_IN_MIN 60
#define MIN_IN_H 60
#define SEC_IN_H (SEC_IN_MIN * MIN_IN_H)

#include <sstream>
//Constructeurs

template<typename T>
Temps<T>::Temps(T heure, T minute, T seconde) {
    _heure = heure;
    _minute = minute;
    _seconde = seconde;
}


template<typename T>
template<typename U>
Temps<T>::Temps(const Temps<U>& t): Temps(t.getHeure(), t.getMinute(), t.getSeconde()) {
    
}

template<typename T>
Temps<T>::Temps(const Temps<T>& t) {
    _heure = t._heure;
    _minute = t._minute;
    _seconde = t._seconde;
}

template <typename T>
Temps<T>::Temps(T seconde) {
    _heure = seconde / SEC_IN_H;
    seconde -= _heure * SEC_IN_H;
    _minute = seconde / SEC_IN_MIN;
    seconde -= _minute * SEC_IN_MIN;
    _seconde = seconde;
}

//Getters
template<typename T>
T Temps<T>::getHeure() const {
    return _heure;
}

template<typename T>
T Temps<T>::getMinute() const {
    return _minute;
}

template<typename T>
T Temps<T>::getSeconde() const {
    return _seconde;
}

template<typename T>
T Temps<T>::asHeure() const {
    return _heure + _minute / MIN_IN_H + _seconde / SEC_IN_H;
}

template<typename T>
T Temps<T>::asMinute() const {
    return _heure * MIN_IN_H + _minute + _seconde / SEC_IN_MIN;
}

template<typename T>
T Temps<T>::asSeconde() const {
    return _heure * SEC_IN_H + _minute * SEC_IN_MIN + _seconde;
}

template<typename T>
std::ostream& Temps<T>::print(std::ostream& stream) const {
    return stream << _heure << ':' << _minute << ':' << _seconde;
}

//Setters
template<typename T>
void Temps<T>::setHeure(T heure) {
    _heure = heure;
}

template<typename T>
void Temps<T>::setMinute(T minute) {
    _minute = minute;
}

template<typename T>
void Temps<T>::setSeconde(T seconde) {
    _seconde = seconde;
}

//Operators
template<typename T>
Temps<T>& Temps<T>::operator=(const Temps<T>& t) {
    _heure = t._heure;
    _minute = t._minute;
    _seconde = t._seconde;

    return *this;
}

template<typename T>
bool Temps<T>::operator!=(const Temps<T>& t) const {
    return (_heure != t._heure) || (_minute != t._minute) || (_seconde != t._seconde);
}

template<typename T>
bool Temps<T>::operator==(const Temps<T>& t) const {
    return !(this != t);
}

template<typename T>
Temps<T>& Temps<T>::operator+=(const Temps<T>& t) {
    if((_seconde + t._seconde) >= 60){
        _seconde = (_seconde + t._seconde) - 60;
        _minute++;
    } else {
        _seconde = _seconde + t._seconde;
    }
    if((_minute + t._minute) >= 60){
        _minute = (_minute + t._minute) - 60;
        _heure++;
    } else {
        _minute = _minute + t._minute;
    }

    _heure = _heure + t._heure;

    return *this;
}

template<typename T>
Temps<T>& Temps<T>::operator-=(const Temps<T>& t) {
    return *this; // TODO
}

template<typename T>
template<typename U>
Temps<T>& Temps<T>::operator+=(const Temps<U>& t) {
    return *this += (Temps<T>) t;
}

template<typename T>
template<typename U>
Temps<T>& Temps<T>::operator-=(const Temps<U>& t) {
    return *this -= (Temps<T>) t;
}

template <typename T1, typename T2>
Temps<T1> operator+(Temps<T1> t1, const Temps<T2>& t2) {
    return t1 += t2;
}

template <typename T1, typename T2>
Temps<T1> operator-(Temps<T1> t1, const Temps<T2>& t2) {
    return t1 -= t2;
}

template<typename T>
std::ostream& operator<<(std::ostream& stream, Temps<T> temps) {
    return temps.print(stream);
}


//Castings
// template<typename T>
// template<typename U>
// Temps<T>::operator U() const {
//     return asHeure();
// }


template<typename T>
Temps<T>::operator float() const {
    return Temps<float>(*this).asHeure();
}

template<typename T>
Temps<T>::operator double() const {
    return Temps<double>(*this).asHeure();
}

template<typename T>
Temps<T>::operator long long() const {
    return asSeconde();
}

template<typename T>
Temps<T>::operator std::string() const {
    std::stringstream ss;
    print(ss);
    return ss.str();
}

#endif // TEMPS_IPP