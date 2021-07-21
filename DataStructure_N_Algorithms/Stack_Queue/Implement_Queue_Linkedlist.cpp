#include "Header.h"

struct Stag_linkedlist {
  char* item;
  Stag_linkedlist* next;
};

class Queue {
private:
  Stag_linkedlist* first, * last;
  int length = 0;

public:
  Queue() {
    this->first = NULL;
    this->last = NULL;
    this->length = 0;
  }
  Stag_linkedlist* create_item(char* item) {
    Stag_linkedlist* node = new Stag_linkedlist;
    node->item = (char*)malloc(sizeof(item) / sizeof(char));
    copy(item, item + (sizeof(item) / sizeof(char)), node->item);
    node->next = NULL;
    return node;
  }
  Queue(char* item) {
    Stag_linkedlist* node = Queue::create_item(item);
    this->first = node;
    this->last = node;
    this->length = 1;
  }

  void peek() {
    cout << this->first->item;
  }

  void enqueue(char* item) {
    if (this->length == 0) {
      Stag_linkedlist* node = Queue::create_item(item);
      this->first = node;
      this->last = node;
    }
    else {
      Stag_linkedlist* node = Queue::create_item(item);
      node->next = NULL;
      this->last->next = node;
      this->last = node;
    }
    this->length++;
  }
  
  void dequeue() {
    if (this->length == 0)
      return;
    else if (this->length == 1) {
      this->first = NULL;
      this->last = NULL;
      this->length = 0;
    }
    else {
      Stag_linkedlist* temp = this->first;
      this->first = this->first->next;
      free(temp);
      this->length--;
    }
  }

  void print() {
    Stag_linkedlist* node = this->first;
    cout << "Queue implemented by LinkedList" << endl;
    int counter = 0;

    while (node) {
      cout << counter << ": " << node->item << endl;
      counter++;
      node = node->next;
    }
  }
};