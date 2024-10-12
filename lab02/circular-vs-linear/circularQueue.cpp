#include <stdlib.h>
#include "queue.h"

using namespace std;

template <typename T> bool DynamicQueue<T> :: isEmpty() {
  if(A==nullptr) return true; 
  else return false;// dummy return
}

template <typename T> bool DynamicQueue<T> :: isFull() {
  return (tail == head && !isEmpty()); // dummy return
}

template <typename T> void DynamicQueue<T> :: grow() {
  unsigned int s = nextSize();
  T* nA = new T[s];
  if(tail == N){
    for(unsigned int i=0;i<N;i++){
    nA[i]= A[i];
    }
  }
  else{
    for(unsigned int i = head; i<N;i++){
      nA[i-head] = A[i];
    }
    for(int i=0;i<tail;i++){
      nA[N-head+1] = A[i];
    }
  }
  free(A);
  A = nA;
  head = 0;
  tail = N;
  N = s;
}

template <typename T> unsigned int DynamicQueue<T> :: size() {
  if(!isFull()){
    return (N+(tail-head))%N;
  }
  else{
    return N; // dummy return
  }
}

template <typename T> void DynamicQueue<T> :: QInsert(T x) {
  if(!isFull()){
    if(tail==N-1){
      A[tail] = x;
      tail=0;
    }
    else{
      A[tail]=x;
      tail = tail + 1;
    }
  }
  else{
    grow();
    A[tail]=x;
    tail++;
  }
}

template <typename T> bool DynamicQueue<T> :: QDelete(T* x) {
  if(isEmpty()) return false;
  else{
    if(head== (N-1)){
      head = 0;
    }
    else{
      head = head+1;
    }
  return true; // dummy return
  }
}
