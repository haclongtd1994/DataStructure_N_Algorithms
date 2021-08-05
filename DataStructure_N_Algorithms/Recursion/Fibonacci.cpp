#include "Header.h"

// 0, 1, 1, 2, ...

int FibonacciRecursive(int index) {
  if (index < 2) {
    return index;
  }
  return FibonacciRecursive(index - 1) + FibonacciRecursive(index - 2);
}

int FibonacciIterative(int index) {
  vector<int> vector_arr;
  vector_arr.push_back(0);
  vector_arr.push_back(1);
  for (int i = 2; i < index + 1; i++) {
    vector_arr.push_back(vector_arr[i - 1] + vector_arr[i - 2]);
  }
  return (int)vector_arr[index];
}