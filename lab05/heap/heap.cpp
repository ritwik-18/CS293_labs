#include <iostream>

/*
In this exercise, we will implement heap as discussed in the class.
We need to implement the following functions.


ONLY THIS FILE MUST BE MODIFIED FOR SUBMISSION

You may edit main.cpp for writing more test cases.
But your code must continue to work with the original main.cpp


THERE IS ONLY ONE TEST CASE ONLY FOR YOUR UNDERSTANDING.

-- You may need to generate more random tests to get your tests right
-- Print will not work until you have a good printing function
*/


#include "heap.h"


int Heap::parent(int i) {
  if(i < 1 || i >= Heap::size()) return -1;
  else{
    int in = (i-1)/2;
    return in; // dummy return
  }
}

int Heap::left(int i) {
  if((2*i + 1) >= Heap::size()) return -1;
  else return (2*i + 1); // dummy return
}

int Heap::right(int i) {
  if((2*i+2)>=Heap::size()) return -1;
  else return (2*i + 2); //dummy
}

int Heap::max() {
  if(Heap::sz > 0) return store[0]; //dummy
  else return -1;
}

void Heap::swap(int i, int j) {
  int s = store[j];
  store[j] = store[i];
  store[i] = s;
  swap_count++;
}

void Heap::insert(int v) {
  int size = Heap::size();
  store[size] = v;
  while(size > 0 && store[Heap::parent(size)] < store[size]){
    int par = (size-1)/2;
    Heap::swap(size,par);
    size = par;
  }
  Heap::sz++;
}

void Heap::heapify(int i) {
  int c;
  if(Heap::right(i) == -1 && Heap::left(i) == -1) c = i;
  else if(Heap::right(i) == -1){
    if(store[Heap::left(i)] > store[i]) c = Heap::left(i);
    else c =i;
  }
  else if(Heap::left(i) == -1){
    if(store[Heap::right(i)] > store[i]) c = Heap::right(i);
    else c = i;
  }
  else{
    if( store[Heap::left(i)]>store[i] && store[Heap::left(i)]>store[Heap::right(i)]) c = Heap::left(i);
    else if(store[Heap::right(i)]>store[i] && store[Heap::right(i)]>store[Heap::left(i)]) c = Heap::right(i);
    else c = i;
  }
  if(c == i) return;
  Heap::swap(c,i);
  Heap::heapify(c);
}


void Heap::deleteMax() {
  Heap::swap(0,(Heap::size()-1));
  Heap::sz--;
  Heap::heapify(0);
}

void Heap::buildHeap() {
  for(int i = Heap::sz-1;i>=0;i--){
    Heap::heapify(i);
  }
}

void Heap::heapSort() {
  Heap::buildHeap();
  while (Heap::sz > 0){
    Heap::deleteMax();
  }
}


