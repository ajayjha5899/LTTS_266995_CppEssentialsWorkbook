#include <iostream>

#ifndef STACK_H
#define STACK_H

constexpr int max_size=50;

template<typename T>
class MyStack {
    T m_arr[max_size];
    int m_top;
    int m_maxlen;
public:
    MyStack(): m_top(-1), m_maxlen(max_size){
        //m_arr = new T[m_maxlen];
    }
    
    MyStack(int len): m_top(-1), m_maxlen(len){
        //m_arr = new T[m_maxlen];
    }
    
    void push(T val){
        if(m_top == m_maxlen-1){
            std::cout << "Stack full.\n";
        }
        else m_arr[++m_top] = val;

        return;
    }
    
    T pop(){
        if(m_top == -1) std::cout << "Stack empty.\n";
        else{    
            T temp = m_arr[m_top];
            --m_top;
            return temp;
        }
    }
    T peek() const {
        return m_arr[m_top];
    }
    bool isEmpty() const {
        return (m_top == -1);
    }
    bool isFull() const {
        return (m_top == m_maxlen-1);
    }
};

#endif