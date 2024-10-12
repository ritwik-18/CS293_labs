#include <cstdlib>
#include <cstddef>
#include "stack.h"
#pragma once

/*
 * You must NOT add ANY other includes than what is already here.
 * The purpose of this file is to implement the functioning of a queue in C++.
 * The task is to implement a Queue using stacks. This requires two stacks.
 * Ensure that ALL of them are on average constant time. Amortized O(1) is OK.
 * You must NOT change the data members or ANY of the method signatures.
 * NOR are you allowed to add any additional methods or data members.
 * You are free to use the PUBLIC methods of the Stack class here.
 */

template <typename T>
class Queue {
    class Stack<T> first_stack;
    class Stack<T> second_stack;
public:
    Queue();
    ~Queue();
    void enqueue(T value);
    T dequeue();
    T peek();
    bool isEmpty();
    size_t getSize();
};

// ENTER YOUR IMPLEMENTATIONS OF METHODS BELOW

template<typename T>
Queue<T>::Queue(){
    // Stack<T> first_stack;
    // Stack<T> second_stack;
}

template<typename T>
Queue<T>::~Queue(){
    // first_stack.~Stack();
    // second_stack.~Stack();
}


template<typename T>
void Queue<T>::enqueue(T value){
    first_stack.push(value);
}

template<typename T>
T Queue<T>::dequeue(){
    int s = first_stack.getSize();
    
    if(second_stack.isEmpty()){
        for(int i = s-1;i>=0;i--){
            T x = first_stack.pop();
            second_stack.push(x);
        }
    }
    return second_stack.pop();
}

template<typename T>
T Queue<T>::peek(){
    //cout << "hi";
    if(!(second_stack.isEmpty())){
        return second_stack.peek();
    }
    
    else{
        while(!(first_stack.isEmpty())){
            T x = first_stack.pop();
            second_stack.push(x);
        }
        return second_stack.peek();
    }
}

template<typename T>
bool Queue<T>::isEmpty(){
    if(first_stack.getSize() == 0 && second_stack.getSize() == 0) return true;
    else return false;
}

template<typename T>
size_t Queue<T>::getSize(){
    return first_stack.getSize()+second_stack.getSize();
}




