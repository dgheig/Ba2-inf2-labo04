//
// Created by bruno on 22/04/2020.
//

#ifndef BA2_LABO03_TEMPS_H
#define BA2_LABO03_TEMPS_H
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

    //Setters
    void setHeure(T heure);
    void setMinute(T minute);
    void setSeconde(T seconde);

    //Operators
    Temps& operator=(const Temps& t);
    bool operator==(const Temps& t) const;
    bool operator!=(const Temps& t) const;
    Temps operator+(const Temps& t) const;
    Temps& operator+=(const Temps& t);
    Temps operator-(const Temps& t) const;
    Temps& operator-=(const Temps& t);
    std::ostream& operator<<(std::ostream& os);

    //Castings

private:
    T _heure;
    T _minute;
    T _seconde;
};




#endif //BA2_LABO03_TEMPS_H
