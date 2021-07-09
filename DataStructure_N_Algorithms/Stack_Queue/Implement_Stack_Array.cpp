#include "Header.h"

class Stack_Vector {
private:
  vector<string> array;
public:
  Stack_Vector() {

  }
  Stack_Vector(string item) {
    array.push_back(item);
  }
  
  void print() {
    cout << "Stack using vector as dynamic array" << endl;
    int counter = 0;

    for (auto i = array.rbegin(); i != array.rend(); i++) {
      cout << counter << ": " << *i << endl;
      counter++;
    }
  }

  void peek() {
    cout << array.back() << endl;
  }

  void push(string item) {
    array.push_back(item);
  }

  void pop() {
    array.pop_back();
  }
};