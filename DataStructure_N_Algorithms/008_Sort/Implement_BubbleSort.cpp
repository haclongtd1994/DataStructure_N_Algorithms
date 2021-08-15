#include "Header.h"

void swap(int* a, int* b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

void BubbleSort(int* value, int length) {
  for (auto i = (length - 1); i >= 0; i--) {
    for (auto j = 0; j < i; j++) {
      if (value[j] > value[j + 1])
        swap(value[j], value[j + 1]);
    }
  }
}