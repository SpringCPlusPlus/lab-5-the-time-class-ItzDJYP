#include <iostream>
#include "../include/Time.h"
using namespace std;

// Overload the + operator
Time Time::operator+(const Time &other) const{
    int totalMinutes = minutes + other.minutes;
    int totalHours = hours + other.hours + totalMinutes / 60;
    totalMinutes %= 60;
    return Time(totalHours, totalMinutes);
}

// Overload the += operator
Time& Time::operator+=(const Time &other){
    minutes += other.minutes;
    hours += other.hours + minutes / 60;
    minutes %= 60;
    return *this;
}

// Overload the < operator
bool Time::operator<(const Time &other) const{
    return (hours * 60 + minutes) < (other.hours * 60 + other.minutes);
}

// Overload the > operator
bool Time::operator>(const Time &other) const{
    return (hours * 60 + minutes) > (other.hours * 60 + other.minutes);
}

// Overload the == operator
bool Time::operator==(const Time &other) const{
    return (hours * 60 + minutes) == (other.hours * 60 + other.minutes);
}

// Overload the friend function operator<<
ostream &operator<<(ostream &os, const Time &tm){
    os << tm.getHours() << ":" << (tm.getMinutes() < 10 ? "0" : "") << tm.getMinutes();
    return os;
}