#include <cstdlib>
#include <cstddef>
#pragma once

/*
 * You must NOT add ANY other includes than this.
 * The purpose of this file is to implement the functioning of a stack in C++.
 * Implement all the method functions in this file, your way.
 * Ensure that ALL of them are on average constant time. Amortized O(1) is OK.
 * You must NOT change the method signature of any of the methods.
 * You may add any additional methods or data members as you need.
 * Those methods and data members should be protected.
 */

template <typename T>
class Stack {
    // ADD ANY ADDITIONAL DATA MEMBERS OR METHODS HERE
protected:
    std::vector<T> A;
    int head;

    // DO NOT CHANGE THE METHOD SIGNATURES BELOW
public:
    Stack();
    ~Stack();
    void push(T value);
    T pop();
    T peek();
    bool isEmpty();
    size_t getSize();
};

// ENTER YOUR IMPLEMENTATIONS OF METHODS BELOW
template<typename T>
Stack<T>::Stack(){
    A;
    head=-1;
}

template<class T> Stack<T>::~Stack(){

}
template<typename T>
void Stack<T>::push(T x){
    A.push_back(x);
    ++head; 
}

template<typename T>
T Stack<T>::pop(){
    if(!isEmpty()){
        T x = A[head];
        head--; 
        A.pop_back();
        return x;
    }
    else throw std::out_of_range("Stack 1 underflow");
}

template<typename T>
T Stack<T>::peek(){
    //std::cout << head << '\n';
    if(!isEmpty()){
        return A[head];
    }
    else throw std::out_of_range("Stack 2 underflow");
}
 
template<typename T>
bool Stack<T>::isEmpty(){
    if(head < 0) return true;
    else return false;
}

template<typename T>
size_t Stack<T>::getSize(){
    if(!isEmpty()) return head+1;
    else return 0;
}

