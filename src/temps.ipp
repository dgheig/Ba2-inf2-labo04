/*
-----------------------------------------------------------------------------------
Laboratory  : labo_04
File        : temps.ipp
Author(s)   : Carvalho Bruno et Gallay David
Date        : 

Purpose     : Defining function Temps
Remark(s)   :
                There is the github repository:
                https://github.com/dgheig/Ba2-inf2-labo04

Compiler    : g++ 7.4.0
-----------------------------------------------------------------------------------*/

#ifndef TEMPS_IPP
#define TEMPS_IPP

#define SEC_IN_MIN 60
#define MIN_IN_H 60
#define SEC_IN_H (SEC_IN_MIN * MIN_IN_H)

#include <sstream>
#include "exceptions.h"

// Constructors

template<typename T>
Temps<T>::Temps(T heure, T minute, T seconde): _heure(0), _minute(0), _seconde(0) {
    // Let the user enter negative parameter
    // as long as the resulting time is positive
    fromSeconde(toSeconde(heure, minute, seconde));
}


template<typename T>
template<typename U>
Temps<T>::Temps(const Temps<U>& temps): Temps() {
    *this = temps;
}

template<typename T>
Temps<T>::Temps(const Temps<T>& temps): Temps() {
    *this = temps;
}

template <typename T>
Temps<T>::Temps(T seconde): Temps() {
    fromSeconde(seconde);
}

template <typename T>
void Temps<T>::fromSeconde(T seconde) {
    if (seconde < 0)
        throw negative_value("La classe Temps ne peut avoir une valeur negative");
    _heure = (T)(int)(seconde / SEC_IN_H);
    seconde -= _heure * SEC_IN_H;
    _minute = (T)(int)(seconde / SEC_IN_MIN);
    seconde -= _minute * SEC_IN_MIN;
    _seconde = seconde;
}

// Getters
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
    return asSeconde() / SEC_IN_H;
}

template<typename T>
T Temps<T>::asMinute() const {
    return asSeconde() / SEC_IN_MIN;
}

template<typename T>
T Temps<T>::asSeconde() const {
    return toSeconde(
        getHeure(),
        getMinute(),
        getSeconde()
    );
}

template<typename T>
std::ostream& Temps<T>::print(std::ostream& stream) const {
    return stream << _heure << ':' << _minute << ':' << _seconde;
}

// Setters
template<typename T>
void Temps<T>::setHeure(T heure) {
    if (heure < 0)
        throw negative_value("La classe Temps ne peut avoir d'heures negatives");
    _heure = heure;
}

template<typename T>
void Temps<T>::setMinute(T minute) {
    if (minute < 0 or MIN_IN_H <= minute)
        throw std::invalid_argument("Les minutes doivent etre entre 0 et 59");
    _minute = minute;
}

template<typename T>
void Temps<T>::setSeconde(T seconde) {
    if (seconde < 0 or SEC_IN_MIN <= seconde)
        throw std::invalid_argument("Les secondes doivent etre entre 0 et 59");
    _seconde = seconde;
}

// Operators

template<typename T>
template<typename U>
Temps<T>& Temps<T>::operator=(const Temps<U>& temps) {
    _heure = (T)temps.getHeure();
    _minute = (T)temps.getMinute();
    _seconde = (T)temps.getSeconde();
    return *this;
}

template<typename T>
Temps<T>& Temps<T>::operator=(const Temps<T>& temps) {
    _heure = temps._heure;
    _minute = temps._minute;
    _seconde = temps._seconde;
    return *this;
}

template<typename T>
bool Temps<T>::operator!=(const Temps<T>& temps) const {
    return (_heure != temps._heure) || (_minute != temps._minute) || (_seconde != temps._seconde);
}

template<typename T>
bool Temps<T>::operator==(const Temps<T>& temps) const {
    return !(this != temps);
}

template<typename T>
Temps<T>& Temps<T>::operator+=(const Temps<T>& temps) {
    fromSeconde(asSeconde() + temps.asSeconde());
    return *this;
}

template<typename T>
Temps<T>& Temps<T>::operator-=(const Temps<T>& temps) {
    fromSeconde(asSeconde() - temps.asSeconde());
    return *this;
}

template<typename T>
T Temps<T>::toSeconde(T heure, T minute, T seconde) {
    return heure * SEC_IN_H + minute * SEC_IN_MIN + seconde;
}

template<typename T>
template<typename U>
Temps<T>& Temps<T>::operator+=(const Temps<U>& temps) {
    return *this += Temps<T>(temps);
}

template<typename T>
template<typename U>
Temps<T>& Temps<T>::operator-=(const Temps<U>& temps) {
    return *this -= Temps<T>(temps);
}

template <typename T1, typename T2>
Temps<T1> operator+(Temps<T1> temps1, const Temps<T2>& temps2) {
    return temps1 += temps2;
}

template <typename T1, typename T2>
Temps<T1> operator-(Temps<T1> temps1, const Temps<T2>& temps2) {
    return temps1 -= temps2;
}

template <typename T1, typename T2>
Temps<T1> operator<(Temps<T1> t1, const Temps<T2>& t2) {
    return t1.asSeconde() < t2.asSeconde();
}
template <typename T1, typename T2>
Temps<T1> operator>(Temps<T1> t1, const Temps<T2>& t2) {
    return t2 < t1;
}

template<typename T>
std::ostream& operator<<(std::ostream& stream, Temps<T> temps) {
    return temps.print(stream);
}

template<typename T>
Temps<T>::operator float() const {
    return Temps<float>(*this).asHeure();
}

template<typename T>
Temps<T>::operator double() const {
    return Temps<double>(*this).asHeure();
}

template<typename T>
Temps<T>::operator long double() const {
    return Temps<long double>(*this).asHeure();
}

template<typename T>
Temps<T>::operator long long() const {
    return (long long)asSeconde();
}

template<typename T>
Temps<T>::operator std::string() const {
    std::stringstream ss;
    print(ss);
    return ss.str();
}

#endif // TEMPS_IPP