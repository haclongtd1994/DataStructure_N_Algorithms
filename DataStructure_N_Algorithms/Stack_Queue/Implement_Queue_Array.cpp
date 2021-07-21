#include "Header.h"

class Queue_Array {
private:
  vector<int> origin, reorder;
  int length = 0;
public:
  Queue_Array() {
    this->length = 0;
  }

  void swap(vector<int>* src, vector<int>* des) {
    for (auto i = src->size(); i > 0; i--) {
      int temp = src->at(i-1);
      src->pop_back();
      des->push_back(temp);
    }
  }

  Queue_Array(int item) {
    origin.push_back(item);
    this->length = 1;
  }

  void enqueue(int item) {
    swap(&this->reorder, &this->origin);
    this->origin.push_back(item);
    this->length++;
  }

  void dequeue() {
    swap(&this->origin, &this->reorder);
    this->reorder.pop_back();
    this->length--;
  }

  void peek() {
    if (this->origin.size() > 0)
      cout << this->origin.front() << endl;
    else
      cout << this->reorder.back();
  }

  void print() {
    cout << "Queue using array" << endl;
    int counter = 0;

    if (this->origin.size() > 0) {
      for (auto i = this->origin.begin(); i != this->origin.end(); i++) {
        cout << counter << ": " << *i << endl;
        counter++;
      }
    }
    else {
      for (auto i = this->reorder.begin(); i != this->reorder.end(); i++) {
        cout << counter << ": " << *i << endl;
        counter++;
      }
    }
  }
};