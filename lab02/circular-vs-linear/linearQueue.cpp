#include <stdlib.h>
#include "queue.h"

using namespace std;

template <typename T> bool DynamicQueue<T> :: isEmpty() {
  return head==tail; // dummy return
}

template <typename T> bool DynamicQueue<T> :: isFull() {
  return (tail-head)== N; // dummy return
}

template <typename T> void DynamicQueue<T> :: grow() {
    unsigned int s = nextSize();
    T* nT = new T[s];
    for(unsigned i=0;i<N;i++){
      nT[i] = A[i];
      }
      free(A);
      A = nT;
      N = s;
}

template <typename T> unsigned int DynamicQueue<T> :: size() {
  return (tail-head); // dummy return
}

template <typename T> void DynamicQueue<T> :: QInsert(T x) {
  int s;
  s = size();
  if(!isFull()){
    if(tail==N){
      for(unsigned i=head;i<size();i++){
        A[i-head] = A[head];
      }
      head = 0;
      tail = head + s;
    }
  }
  else{
    grow();
  }
    A[tail] = x;
    tail++;
}

template <typename T> bool DynamicQueue<T> :: QDelete(T* x) {
  if(isEmpty()) return false;
  else{
    head = (head+1);
    return true; // dummy return
  }
}
