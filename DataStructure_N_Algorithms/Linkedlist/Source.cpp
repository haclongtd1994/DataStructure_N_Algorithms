#include "Implement_Linkedlist.cpp"
#include "Implement_DoublyLinkedList.cpp"
#include "Implement_LinkedList_Reverse.cpp"

int main() {
  Linked_list lk(100);
  lk.append(1);
  lk.append(12);
  lk.append(123);
  lk.append(1234);
  lk.prepend(6789);
  lk.Insert(99, 0);
  lk.Insert(99, 56);
  lk.Insert(99, 4);
  lk.print();
  lk.Remove(0);
  lk.print();
  lk.Remove(7);
  lk.print();
  lk.Remove(9);
  lk.print();
  lk.Remove(2);
  lk.print();

  cout << "\n\n\n-----------------------------------------------------";
  Doubly_Linked_List dlk(100);
  dlk.print();
  dlk.append(101);
  dlk.prepend(99);
  dlk.append(101);
  dlk.prepend(99);
  dlk.Insert(123, 100);
  dlk.Insert(123, 0);
  dlk.Insert(5555, 3);
  dlk.print();
  dlk.Remove(3);
  dlk.Remove(0);
  dlk.Remove(99);
  dlk.print();

  cout << "\n\n\n-----------------------------------------------------";
  C_LinkedList clk(100);
  clk.append(200);
  clk.prepend(50);
  clk.print();
  clk.Reverse();
  clk.print();



  return 0;
}