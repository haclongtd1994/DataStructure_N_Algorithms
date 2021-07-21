#include "Header.h"

struct Stag_Linkedlist {
  char* items;
  Stag_Linkedlist* next;
};
typedef struct Stag_Linkedlist Stag_Linkedlist;

class Stack_LinkedList {
private:
  Stag_Linkedlist* top;
  Stag_Linkedlist* bottom;
  int length;
public:
  Stack_LinkedList() {
    top = NULL;
    bottom = NULL;
    length = 0;
  }
  Stag_Linkedlist* create_node(char* item) {
    Stag_Linkedlist* node = new Stag_Linkedlist;
    node->items = (char*)malloc(sizeof(item) / sizeof(char));
    copy(item, item + (sizeof(item) / sizeof(char)), node->items);
    return node;
  }

  Stack_LinkedList(char* item) {
    Stag_Linkedlist* node = create_node(item);
    node->next = NULL;
    top = node;
    bottom = node;
    this->length = 1;
  }

  void print() {
    cout << "Stack using linked list" << endl;
    Stag_Linkedlist* temp = this->top;
    int counter = 0;

    while (temp) {
      cout << counter << ": " << temp->items << endl;
      counter++;
      temp = temp->next;
    }
  }

  void push(char* item) {
    Stag_Linkedlist* node = create_node(item);
    if (this->length == 0) {
      node->next = NULL;
      this->top = node;
      this->bottom = node;
    }
    else {
      node->next = this->top;
      this->top = node;
    }
    this->length++;
  }

  Stag_Linkedlist* peek() {
    return this->top;
  }

  void pop() {
    if (this->length == 0) {
      return;
    }
    else if (this->length == 1) {
      this->top = NULL;
      this->bottom = NULL;
      this->length--;
    }
    else {
      Stag_Linkedlist* temp = this->top;
      this->top = this->top->next;
      free(temp);
      this->length--;
    }
  }
};