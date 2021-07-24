#include "Implement_BinarySearchTree.cpp"

int main() {
  BinarySearchTree bt;
  bt.insert(46);
  bt.insert(10);
  bt.insert(25);
  bt.insert(65);
  bt.insert(14);
  bt.insert(15);
  bt.remove(10);

  bt.print();
  string rt = bt.lookup(10) ? "Yes" : "No";
  cout << endl << "Lookup function: " << rt << endl;
}