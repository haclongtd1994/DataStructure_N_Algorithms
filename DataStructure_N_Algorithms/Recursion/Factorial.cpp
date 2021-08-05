#include "Header.h"

int FactorialRecursive(int number) {
  if (number == 1)
    return 1;
  return number * FactorialRecursive(number-1);
}

int FactorialIterative(int number) {
  int Factorial = number;
  for (int i = number - 1; i > 0; i--) {
    Factorial = Factorial * i;
  }
  return Factorial;
}