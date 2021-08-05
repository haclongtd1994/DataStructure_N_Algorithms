#include "Factorial.cpp"
#include "Fibonacci.cpp"
#include "ReverseString.cpp"

int main() {
  cout << FactorialIterative(1) << endl;
  cout << FactorialRecursive(5) << endl;
  cout << FibonacciRecursive(8) << endl;
  cout << FibonacciIterative(8) << endl;

  vector<char> test;
  test.push_back('H');
  test.push_back('e');
  test.push_back('l');
  test.push_back('l');
  test.push_back('o');

  test = ReverseStringIterative(test);
  for (auto i = test.begin(); i != test.end(); i++)
    cout << *i;
  cout << endl;

  cout << ReverseStringRecursion("Hello");

  return 0;
}