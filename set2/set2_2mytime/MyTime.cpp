#include <iostream>
#include "MyTime.h"

// default constructor
MyTime::MyTime():
    m_hours(0), m_minutes(0), m_seconds(0) {}

// generic constructor1
MyTime::MyTime(int hours, int minutes, int seconds):
    m_hours(hours), m_minutes(minutes), m_seconds(seconds) {}

// generic constructor2
MyTime::MyTime(int hours, int minutes):
    m_hours(hours), m_minutes(minutes), m_seconds(0) {}

// overloading + (time addition)
MyTime MyTime::operator+(const MyTime& time){
    int seconds = (m_seconds + time.m_seconds)%60;
    int minutes = (m_minutes + time.m_minutes + ((m_seconds + time.m_seconds)/60))%60;
    int hours = (m_hours + time.m_hours + ((m_minutes + time.m_minutes)/60));

    return MyTime(hours,minutes,seconds);
}

// overloading - (time subtraction)
MyTime MyTime::operator-(const MyTime& time){
    int seconds, minutes, hours;
    seconds = m_seconds - time.m_seconds;
    if(seconds < 0){
        seconds = 60 + seconds;
        minutes = m_minutes - time.m_minutes - 1;
    }
    else minutes = m_minutes - time.m_minutes - 1;
    if(minutes < 0){
        minutes = 60 + minutes;
        hours = m_hours - time.m_hours - 1;
    }
    else hours = m_hours - time.m_hours;

    return MyTime(hours,minutes,seconds);
}

// overloading + (adding time in seconds)
MyTime MyTime::operator+(int addtime){
    int seconds = addtime%60;
    addtime /= 60;
    int minutes = addtime%60;
    addtime /= 60;
    int hours = addtime;

    return MyTime(hours,minutes,seconds) + *this;
}

// overloading - (subtracting time in seconds)
MyTime MyTime::operator-(int addtime){
    int seconds = addtime%60;
    addtime /= 60;
    int minutes = addtime%60;
    addtime /= 60;
    int hours = addtime;

    return *this - MyTime(hours,minutes,seconds);
}

MyTime& MyTime::operator++(){
    *this = *this + MyTime(0,0,1);
    return *this;
}

MyTime MyTime::operator++(int dummy){
    MyTime orig(m_hours, m_minutes, m_seconds); //dummy object
    *this = *this + MyTime(0,0,1); //actual operation
    return orig; //return dummy object
}

MyTime& MyTime::operator+=(const MyTime& time){
    *this = *this + time;
    return *this;
}

bool MyTime::operator==(const MyTime& time){
    return (m_hours==time.m_hours) && (m_minutes==time.m_minutes) && (m_seconds==time.m_seconds);
}

bool MyTime::operator<(const MyTime& time){
    if(m_hours < time.m_hours) return true;
    if(m_hours == time.m_hours){
        if(m_minutes < time.m_minutes) return true;
        if(m_minutes == time.m_minutes){
            if(m_seconds < time.m_seconds) return true;
        }
    }
    return false;
}

bool MyTime::operator>(const MyTime& time){
    if(m_hours > time.m_hours) return true;
    if(m_hours == time.m_hours){
        if(m_minutes > time.m_minutes) return true;
        if(m_minutes == time.m_minutes){
            if(m_seconds > time.m_seconds) return true;
        }
    }
    return false;
}

void MyTime::display() const{
    std::cout << m_hours << " : " << m_minutes << " : " << m_seconds << std::endl;
    return;
}

std::ostream& operator<<(std::ostream& rout, const MyTime& time){
    rout << time.m_hours << " : " << time.m_minutes << " : " << time.m_seconds;
    return rout;
}
