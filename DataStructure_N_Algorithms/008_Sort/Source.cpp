#include "Implement_BubbleSort.cpp"
#include "Implement_SelectionSort.cpp"
#include "Implement_InsertionSort.cpp"
#include "Implement_MergeSort.cpp"

int main() {
  int a[10] = { 6,3,8,19,28,39,49,13,53,23 };
  int b[10] = { 6,3,8,19,28,39,49,13,53,23 };
  int c[10] = { 6,3,8,19,28,39,49,13,53,23 };

  BubbleSort(a, 10);
  SelectionSort(b, 10);
  InsertionSort(c, 10);

  for (auto i = 0; i < 10; i++)
    cout << *(a + i) << " - ";
  cout << endl;

  for (auto i = 0; i < 10; i++)
    cout << *(b + i) << " - ";
  cout << endl;

  for (auto i = 0; i < 10; i++)
    cout << *(c + i) << " - ";
  cout << endl;

  vector<int> VMergeSort = { 1,3,5,2,5,13,5,1312,55,12313,5123 };
  VMergeSort = MergeSort(VMergeSort);

  for (auto i = VMergeSort.begin(); i != VMergeSort.end(); i++)
    cout << *i << " - ";
  cout << endl;

  return 0;
}