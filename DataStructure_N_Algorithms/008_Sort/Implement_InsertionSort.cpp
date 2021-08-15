#include "Header.h"

void InsertionSort(int* value, int length) {
  // Loop all unordered
  for (int i = 1; i < length; i++) {
    //Get the first unorder element
    int temp = value[i];
    int j = i - 1;

    // Loop all sorted element
    while ((j >= 0) && (temp < value[j])) {
      value[j + 1] = value[j];
      j--;
    }

    // Load temp to correct location
    value[j + 1] = temp;
  }
}