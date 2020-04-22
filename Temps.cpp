//
// Created by bruno on 22/04/2020.
//

#include "Temps.h"

//Constructeurs

template<typename T>
Temps<T>::Temps(T heure, T minute, T seconde) {
    _heure = heure;
    _minute = minute;
    _seconde = seconde;
}

template<typename T>
Temps<T>::Temps(const Temps<T> &t) {
    _heure = t._heure;
    _minute = t._minute;
    _seconde = t._seconde;
}

template <typename T>
Temps<T>::Temps(T seconde) {
    _heure = seconde / 3600;
    _minute = (seconde / 3600) - (_heure * 60);
    _seconde = seconde - (_heure * 3600) - (_minute * 60);
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
Temps<T> & Temps<T>::operator=(const Temps<T> &t) {
    _heure = t._heure;
    _minute = t._minute;
    _seconde = t._seconde;

    return *this;
}

template<typename T>
bool Temps<T>::operator!=(const Temps<T> &t) const {
    return (_heure != t._heure) || (_minute != t._minute) || (_seconde != t._seconde);
}

template<typename T>
bool Temps<T>::operator==(const Temps<T> &t) const {
    return !(this != t);
}

template<typename T>
Temps<T> Temps<T>::operator+(const Temps<T> &t) const {
}

template<typename T>
Temps<T> & Temps<T>::operator+=(const Temps<T> &t) {
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
Temps<T> Temps<T>::operator-(const Temps<T> &t) const {}

template<typename T>
Temps<T> & Temps<T>::operator-=(const Temps<T> &t) {}

template<typename T>
std::ostream & Temps<T>::operator<<(std::ostream &os) {}