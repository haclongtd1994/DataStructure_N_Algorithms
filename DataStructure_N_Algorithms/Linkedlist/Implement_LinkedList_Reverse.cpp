#include "Header.h"

struct StagLinkedList {
  int items;
  StagLinkedList* next;
};
typedef struct StagLinkedList StagLinkedList;

class C_LinkedList {
private:
  int length;
  StagLinkedList* head, * tail;
public:
  C_LinkedList(int items) {
    StagLinkedList* node = new StagLinkedList;
    node->items = items;
    node->next = NULL;
    this->head = node;
    this->tail = this->head;
    this->length++;
  }
  ~C_LinkedList() {
    StagLinkedList* next = this->head;
    StagLinkedList* curr;
    while (next) {
      curr = next;
      next = next->next;
      free(curr);
    }
  }

  void print() {
    StagLinkedList* node = this->head;
    cout << "Linked List have Reverse" << endl;
    int counter = 0;

    while (node) {
      cout << counter << ": " << node->items << endl;
      node = node->next;
    }
  }

  void append(int items) {
    StagLinkedList* node = new StagLinkedList;
    node->items = items;
    node->next = NULL;
    this->tail->next = node;
    this->tail = node;
    this->length++;
  }

  void prepend(int items) {
    StagLinkedList* node = new StagLinkedList;
    node->items = items;
    node->next = this->head;
    this->head = node;
  }

  StagLinkedList* TraverseToIndex(int index) {
    StagLinkedList* node = this->head;
    int current = 0;
    while (current != this->length) {
      current++;
      node = node->next;
    }
    return node;
  }

  void Insert(int items, int pos) {
    if (pos == 0) {
      C_LinkedList::prepend(items);
    }
    else if (pos >= (this->length - 1)) {
      C_LinkedList::append(items);
    }
    else {
      StagLinkedList* prev = C_LinkedList::TraverseToIndex(pos - 1);
      StagLinkedList* node = new StagLinkedList;
      node->items = items;
      node->next = prev->next;
      prev->next = node;
      this->length++;
    }
  }

  void Remove(int pos) {
    if (pos == 0) {
      StagLinkedList* node = this->head;
      this->head = this->head->next;
      free(node);
      this->length--;
    }
    else if (pos >= (this->length - 1)) {
      StagLinkedList* prev = this->TraverseToIndex(this->length - 2);
      prev->next = NULL;
      free(this->tail);
      this->tail = prev;
      this->length--;
    }
    else {
      StagLinkedList* prev = this->TraverseToIndex(pos - 1);
      StagLinkedList* targ = prev->next;
      prev->next = targ->next;
      free(targ);
      this->length--;
    }
  }

  void Reverse() {
    if (this->length == 1) {
      return;
    }
    this->tail = this->head;
    StagLinkedList* first = this->head;
    StagLinkedList* second = this->head->next;
    while (second) {
      StagLinkedList* temp = second->next;
      second->next = first;
      first = second;
      second = temp;
    }
    this->tail->next = NULL;
    this->head = first;
  }
};