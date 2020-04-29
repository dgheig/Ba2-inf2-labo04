/*
-----------------------------------------------------------------------------------
Laboratory  : labo_04
File        : temps.h
Author(s)   : Carvalho Bruno et Gallay David
Date        : 

Purpose     : Declaring function Temps
Remark(s)   : since we can't assume which type will be used
              and that we don't assert types requirements,
              no functions could be qualified as noexcept
              (neiter the getters)

                There is the github repository:
                https://github.com/dgheig/Ba2-inf2-labo04

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
         * @brief constructor of class Temps
         * @param heure
         * @param minute
         * @param seconde
         * @throw negative_value resulting time must be positive
         */
        Temps(T heure=0, T minute=0, T seconde=0);

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
         * @throw negative_value resulting time must be positive
         */
        Temps(T seconde);

        /**
         * @brief getter for hours
         * @return heure
         */
        T getHeure() const;

        /**
         * @brief getter for minutes
         * @return minute
         */
        T getMinute() const;

        /**
         * @brief getter for seconds
         * @return seconde
         */
        T getSeconde() const;

        /**
         * @brief convert into hours representation
         * @return hours
         */
        T asHeure() const;

        /**
         * @brief convert into minutes representation
         * @return minutes
         */
        T asMinute() const;

        /**
         * @brief convert into seconds representation
         * @return seconds
         */
        T asSeconde() const;

        /**
         * @brief print object representation to stream
         * @param stream
         * @return reference on the stream parameter
         */
        std::ostream& print(std::ostream& stream=std::cout) const;

        /**
         * @brief allow to modify value of hours
         * @param heure
         * @throw negative_value hours must be positives
         */
        void setHeure(T heure);

        /**
         * @brief allow to modify value of minutes
         * @param minute
         * @throw std::invalid_argument minutes must be in [0, 60[ 
         */
        void setMinute(T minute);

        /**
         * @brief allow to modify value of seconds
         * @param seconde
         * @throw std::invalid_argument seconds must be in [0, 60[ 
         */
        void setSeconde(T seconde);

        /**
         * @brief surcharge of operator =, allow us to copy an object Temps into an other
         * @param temps
         * @return reference on itself
         */
        template<typename U>
        Temps& operator=(const Temps<U>& temps);

        /**
         * @brief surcharge of operator =, allow us to copy an object Temps into an other
         * @param temps
         * @return reference on itself
         */
        Temps& operator=(const Temps& temps);

        /**
         * @brief surcharge of operator +=, allow us to addition object
         * @param temps
         * @return reference on itself
         */
        Temps& operator+=(const Temps& temps);

        /**
         * @brief surcharge of operator -=, allow us to substract object
         * @param temps
         * @return reference on itself
         */
        Temps& operator-=(const Temps& temps);

        /**
         * @brief surcharge of operator +=, allow us to addition object
         * @param temps
         * @return reference on itself
         */
        template<typename U>
        Temps& operator+=(const Temps<U>& temps);

        /**
         * @brief surcharge of operator -=, allow us to substract object
         * @param temps
         * @return reference on itself
         */
        template<typename U>
        Temps& operator-=(const Temps<U>& temps);

        /**
         * @brief surcharge of operator ==, allow us to compare two object
         * @param temps
         * @return true if objects are equal
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
         * @return casted value to float
         */
        operator float() const;

        /**
         * @brief cast object into double, it means it convert an HH:MM:SS into h.xxxx
         * @return casted value to double
         */
        operator double() const;

        /**
         * @brief cast object into long double, it means it convert HH:MM:SS into h.xxxx
         * @return casted value to long double
         */
        operator long double() const;

        /**
         * @brief cast object into long long int, convert our full time HH:MM:SS into seconds
         * @return casted value to long long
         */
        operator long long() const;

        /**
         * @brief cast object into string, allow us to print it into HH:MM:SS format
         * @return casted value to std::string
         */
        operator std::string() const;

    private:
        static T toSeconde(T heure, T minute, T seconde);
        void fromSeconde(T seconde);
        T _heure;
        T _minute;
        T _seconde;
};


/**
 * @brief return the difference without check for overflow
 *        Object is granted to be positiv
 * @param t1 instance of Temps
 * @param t2 instance of Temps
 * @return return the difference between t1 and t2.
 */
template <typename T1, typename T2>
Temps<T1> operator+(Temps<T1> t1, const Temps<T2>& t2);

/**
 * @brief return the difference without check for underflow
 *        checks could be done using operator<
 *        Object is granted to be positiv
 * @param t1 instance of Temps
 * @param t2 instance of Temps
 * @return return the difference between t1 and t2.
 */
template <typename T1, typename T2>
Temps<T1> operator-(Temps<T1> t1, const Temps<T2>& t2);

/**
 * @param t1 instance of Temps
 * @param t2 instance of Temps
 * @return true if t1 is smaller than t2
 */
template <typename T1, typename T2>
Temps<T1> operator<(Temps<T1> t1, const Temps<T2>& t2);

/**
 * @param t1 instance of Temps
 * @param t2 instance of Temps
 * @return true if t1 is bigger than t2
 */
template <typename T1, typename T2>
Temps<T1> operator>(Temps<T1> t1, const Temps<T2>& t2);

/**
 * @brief print temps object representation to stream
 * @param stream
 * @return reference on the stream parameter
 */
template <typename T>
std::ostream& operator<<(std::ostream& stream, Temps<T> temps);


#include "temps.ipp"
#endif // TEMPS_H
