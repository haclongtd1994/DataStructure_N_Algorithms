#include "Header.h"

void SelectionSort(int* value, int length) {
  for (auto i = 0; i < length-1; i++) {
    int min = i;

    for (auto j = i + 1; j < length; j++) {
      if (value[j] < value[min])
        min = j;
    }

    swap(value[i], value[min]);
  }
}