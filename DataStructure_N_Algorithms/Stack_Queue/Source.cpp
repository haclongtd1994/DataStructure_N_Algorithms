#include "Implement_Stack_LinkedList.cpp"
#include "Implement_Stack_Array.cpp"
#include "Implement_Queue_LinkedList.cpp"
#include "Implement_Queue_Array.cpp"

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

  cout << endl;
  cout << "---------------------------" << endl;
  Queue queue((char*)"Hello");
  queue.enqueue((char*)"Hung");
  queue.enqueue((char*)"Ne");
  queue.enqueue((char*)"!");
  queue.dequeue();
  queue.print();

  cout << endl;
  cout << "---------------------------" << endl;
  Queue_Array queue_arr(1);
  queue_arr.enqueue(10);
  queue_arr.enqueue(100);
  queue_arr.enqueue(1000);
  queue_arr.dequeue();
  queue_arr.dequeue();
  queue_arr.dequeue();
  queue_arr.enqueue(100);
  queue_arr.dequeue();
  queue_arr.print();
}