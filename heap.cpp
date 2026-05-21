// heap.cpp
// Diba Mirza

#include "heap.h"
#include <iostream>
using std::cout;
//helpers
void Heap::bubbleUp(int index) {
  while (index > 0) {
    int parent = (index - 1) / 2;
      if (vdata[index] < vdata[parent]) {
        std::swap(vdata[index], vdata[parent]);
        index = parent;
      } else {
          break;
      }
  }
}

void Heap::bubbleDown(int index) {
  int n = vdata.size();
  while (true) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;

    if (left < n && vdata[left] < vdata[smallest]) {
      smallest = left;
    }
    if (right < n && vdata[right] < vdata[smallest]) {
      smallest = right;
    }
    if (smallest != index) {
      std::swap(vdata[index], vdata[smallest]);
      index = smallest;
    } else {
      break; 
    }
  }
}
// Builds a heap from the range [start, end) using the heapify algorithm
// Should run in O(n) time
Heap::Heap(std::vector<int>::iterator start, std::vector<int>::iterator end){
  vdata.assign(start, end);
  int n = vdata.size();
  for (int i = n / 2 - 1; i >= 0; --i) {
    bubbleDown(i);
  }
}

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
  vdata.push_back(value);
  bubbleUp(vdata.size() - 1);
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
  if (vdata.empty()) {
    return;
  }
  vdata[0] = vdata.back();
  vdata.pop_back();
  if (!vdata.empty()) {
    bubbleDown(0);
  }
}

// Returns the minimum element in the heap
int Heap::top(){
  return vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  return vdata.empty();
}
    