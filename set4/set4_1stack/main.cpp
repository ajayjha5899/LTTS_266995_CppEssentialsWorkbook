#include <iostream>
#include "Stack.h"

int main(){
    MyStack<int> s1(5);

    if(s1.isEmpty()) std::cout << "Stack empty.\n";
    else std::cout << "Stack is not empty.\n";

    for(int i=0; i<5; i++){
        s1.push(i);
    }

    if(s1.isFull()) std::cout << "Stack full.\n";
    else std::cout << "Stack is not full.\n";

    std::cout << s1.peek() << std::endl;
    
    std::cout << s1.pop() << std::endl;

    if(s1.isFull()) std::cout << "Stack full.\n";
    else std::cout << "Stack is not full.\n";

    return 0;
}