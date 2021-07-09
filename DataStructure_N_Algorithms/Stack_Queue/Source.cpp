#include "Implement_Stack_LinkedList.cpp"
#include "Implement_Stack_Array.cpp"

int main() {
  Stack_LinkedList stacklinkedlist((char*)"Hello");
  stacklinkedlist.push((char*)"Hung");
  stacklinkedlist.push((char*)"Ne");
  stacklinkedlist.push((char*)"!");
  stacklinkedlist.pop();
  stacklinkedlist.print();

  cout << endl;
  cout << "---------------------------" << endl;
  Stack_Vector StackArray("Hello");
  StackArray.push("Hung");
  StackArray.push("Ne");
  StackArray.push("!");
  StackArray.pop();
  StackArray.print();
}