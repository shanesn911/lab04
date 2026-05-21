// heap.cpp
// Diba Mirza

#include "heap.h"
#include <iostream>
using std::cout;

static void bubbleUp(std::vector<int>& v, int index) {
  while (index > 0) {
    int parent = (index - 1) / 2;
    if (v[index] < v[parent]) {
      std::swap(v[index], v[parent]);
      index = parent;
    } else {
      break;
    }
  }
}

static void bubbleDown(std::vector<int>& v, int index) {
  int n = (int)v.size();
  while (true) {
    int left  = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;
    if (left  < n && v[left]  < v[smallest]) smallest = left;
    if (right < n && v[right] < v[smallest]) smallest = right;
    if (smallest != index) {
      std::swap(v[index], v[smallest]);
      index = smallest;
    } else {
      break;
    }
  }
}
 


// Builds a heap from the range [start, end) using Floyd's heapify algorithm.
// Runs in O(n) time.
Heap::Heap(std::vector<int>::iterator start, std::vector<int>::iterator end) {
  vdata.assign(start, end);                     // copy all values in
  int n = (int)vdata.size();
  for (int i = n / 2 - 1; i >= 0; --i) {
    bubbleDown(vdata, i);
  }
}

// Pushes a value into the heap, then ensures the heap is correctly arranged.
void Heap::push(int value) {
  vdata.push_back(value);
  bubbleUp(vdata, (int)vdata.size() - 1);
}

// Pops the minimum value off the heap (does not return it),
// then restores the heap property.
void Heap::pop() {
  if (vdata.empty()) return;
  vdata[0] = vdata.back();
  vdata.pop_back();
  if (!vdata.empty()) {
    bubbleDown(vdata, 0);
  }
}

// Returns the minimum element (the root).
int Heap::top() {
  return vdata[0];
}

// Returns true if the heap is empty, false otherwise.
bool Heap::empty() {
  return vdata.empty();
}