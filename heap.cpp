// heap.cpp
// Diba Mirza

#include "heap.h"
#include <iostream>
using std::cout;

Heap::Heap(std::vector<int>::iterator start, std::vector<int>::iterator end) {
  vdata.assign(start, end);
  int n = (int)vdata.size();
  for (int i = n / 2 - 1; i >= 0; --i) {
    int index = i;
    while (true) {
      int left = 2 * index + 1;
      int right = 2 * index + 2;
      int smallest = index;
      if (left < n && vdata[left] < vdata[smallest]) smallest = left;
      if (right < n && vdata[right] < vdata[smallest]) smallest = right;
      if (smallest != index) {
        std::swap(vdata[index], vdata[smallest]);
        index = smallest;
      } else break;
    }
  }
}

void Heap::push(int value) {
  vdata.push_back(value);
  int index = (int)vdata.size() - 1;
  while (index > 0) {
    int parent = (index - 1) / 2;
    if (vdata[index] < vdata[parent]) {
      std::swap(vdata[index], vdata[parent]);
      index = parent;
    } else break;
  }
}

void Heap::pop() {
  if (vdata.empty()) return;
  vdata[0] = vdata.back();
  vdata.pop_back();
  int index = 0;
  int n = (int)vdata.size();
  while (true) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;
    if (left < n && vdata[left] < vdata[smallest]) smallest = left;
    if (right < n && vdata[right] < vdata[smallest]) smallest = right;
    if (smallest != index) {
      std::swap(vdata[index], vdata[smallest]);
      index = smallest;
    } else break;
  }
}

int Heap::top() {
    return vdata[0];
}

bool Heap::empty() {
    return vdata.empty();
}