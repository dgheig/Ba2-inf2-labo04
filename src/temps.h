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
        /**
         * @brief constructor by default
         */
        Temps();
        /**
         * @brief constructor of class Temps
         * @param heure
         * @param minute
         * @param seconde
         */
        Temps(T heure, T minute, T seconde);
        /**
         * @brief constructor by copy
         * @param temps
         */
        template<typename U>
        Temps(const Temps<U>& temps);
        /**
         * @brief constructor by copy
         * @param temps
         */
        Temps(const Temps& temps);
        /**
         * @brief construct a full time HH:MM:SS just by converting seconds
         * @param seconde
         */
        Temps(T seconde);

        /**
         * @brief get method for hours
         * @return heure
         */
        T getHeure() const;
        /**
         * @brief get method for minutes
         * @return minute
         */
        T getMinute() const;
        /**
         * @brief get method for seconds
         * @return seconde
         */
        T getSeconde() const;

        /**
         * @brief convert seconds into hours
         * @return hours
         */
        T asHeure() const;
        /**
         * @brief convert seconds into minutes
         * @return minutes
         */
        T asMinute() const;
        /**
         * @brief convert a full time HH:MM:SS into seconds
         * @return seconds
         */
        T asSeconde() const;

        /**
         * @brief flux operator surcharger
         * @param stream
         * @return
         */
        std::ostream& print(std::ostream& stream=std::cout) const;

        /**
         * @brief allow to modify value of hours
         * @param heure
         */
        void setHeure(T heure);
        /**
         * @brief allow to modify value of minutes
         * @param minute
         */
        void setMinute(T minute);
        /**
         * @brief allow to modify value of seconds
         * @param seconde
         */
        void setSeconde(T seconde);

        /**
         * @brief surcharge of operator =, allow us to copy an object Temps into an other
         * @param temps
         * @return
         */
        template<typename U>
        Temps& operator=(const Temps<U>& temps);
        /**
         * @brief surcharge of operator =, allow us to copy an object Temps into an other
         * @param temps
         * @return
         */
        Temps& operator=(const Temps& temps);
        /**
         * @brief surcharge of operator +=, allow us to addition object
         * @param temps
         * @return
         */
        Temps& operator+=(const Temps& temps);
        /**
         * @brief surcharge of operator -=, allow us to substract object
         * @param temps
         * @return
         */
        Temps& operator-=(const Temps& temps);
        /**
         * @brief surcharge of operator +=, allow us to addition object
         * @param temps
         * @return
         */
        template<typename U>
        Temps& operator+=(const Temps<U>& temps);
        /**
         * @brief surcharge of operator -=, allow us to substract object
         * @param temps
         * @return
         */
        template<typename U>
        Temps& operator-=(const Temps<U>& temps);
        /**
         * @brief surcharge of operator ==, allow us to compare two object
         * @param temps
         * @return true if object are equal
         */
        bool operator==(const Temps& temps) const;
        /**
         * @brief surcharge of operator !=, allow us to compare two object
         * @param temps
         * @return true if objects are different
         */
        bool operator!=(const Temps& temps) const;

        /**
         * @brief cast object into float, it means it convert an HH:MM:SS into h.xxxxx
         * @return
         */
        operator float() const;
        /**
         * @brief cast object into double, it means it convert an HH:MM:SS into h.xxxx
         * @return
         */
        operator double() const;
        /**
         * @brief cast object into long double, it means it convert HH:MM:SS into h.xxxx
         * @return
         */
        operator long double() const;
        /**
         * @brief cast object into long long int, convert our full time HH:MM:SS into seconds
         * @return
         */
        operator long long() const;
        /**
         * @brief cast object into string, allow us to print it into HH:MM:SS format
         * @return
         */
        operator std::string() const;

    private:
        static T toSeconde(T heure, T minute, T seconde);
        void fromSeconde(T seconde);
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
