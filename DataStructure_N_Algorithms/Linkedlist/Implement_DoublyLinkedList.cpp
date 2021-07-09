#include"Header.h"

struct doublylinkedlist {
  int items;
  doublylinkedlist* next;
  doublylinkedlist* prev;
};
typedef struct doublylinkedlist doublylinkedlist;

class Doubly_Linked_List {
private:
  doublylinkedlist* head,* tail;
  int length;
public:
  Doubly_Linked_List(int value) {
    this->head = new doublylinkedlist;
    this->tail = this->head;
    this->head->items = value;
    this->head->next = NULL;
    this->head->prev = NULL;
    this->length = 1;
  }

  ~Doubly_Linked_List() {
    doublylinkedlist* temp;
    while (this->head) {
      temp = this->head->next;
      free(this->head);
      this->head = temp;
    }
  }

  void print() {
    doublylinkedlist* temp = this->head;
    int count = 0;
    cout << "\n\nDoubly linked list" << endl;
    while (temp) {
      cout << count << ": " << temp->items << endl;
      count++;
      temp = temp->next;
    }
    cout << "Length: " << this->length;
  }

  void append(int value) {
    doublylinkedlist* node = new doublylinkedlist;
    node->items = value;
    node->next = NULL;
    node->prev = this->tail;
    this->tail->next = node;
    this->tail = node;
    this->length++;
  }

  void prepend(int value) {
    doublylinkedlist* node = new doublylinkedlist;
    node->items = value;
    node->prev = NULL;
    node->next = this->head;
    this->head->prev = node;
    this->head = node;
    this->length++;
  }

  doublylinkedlist* TraverseToIndex(int index) {
    int left = index;
    int max_idx = this->length - 1;
    int right = max_idx - left;
    doublylinkedlist* currentnode = new doublylinkedlist;

    if (left <= right) {
      int counter = 0;
      currentnode = this->head;
      while (left != counter) {
        currentnode = currentnode->next;
        counter++;
      }
    }
    else {
      int counter = 0;
      currentnode = this->tail;
      while (right != counter) {
        currentnode = currentnode->prev;
        counter++;
      }
    }
    return currentnode;
  }

  void Insert(int value, int pos) {
    if (pos == 0) {
      this->prepend(value);
    }
    else if (pos >= (this->length - 1)) {
      this->append(value);
    }
    else {
      doublylinkedlist* node = new doublylinkedlist;
      doublylinkedlist* next = new doublylinkedlist;
      node->items = value;
      doublylinkedlist* prev = this->TraverseToIndex(pos - 1);
      next = prev->next;
      node->prev = prev;
      node->next = next;
      prev->next = node;
      next->prev = node;
      this->length++;
    }
  }

  void Remove(int pos) {
    if (pos == 0) {
      doublylinkedlist* temp = new doublylinkedlist;
      temp = this->head;
      this->head = this->head->next;
      this->head->prev = NULL;
      delete temp;
      this->length--;
    }
    else if (pos >= (this->length - 1)) {
      doublylinkedlist* temp = new doublylinkedlist;
      temp = this->tail;
      this->tail = this->tail->prev;
      this->tail->next = NULL;
      delete temp;
      this->length--;
    }
    else {
      doublylinkedlist* prev = this->TraverseToIndex(pos - 1);
      doublylinkedlist* target = prev->next;
      doublylinkedlist* next = target->next;
      prev->next = next;
      next->prev = next;
      delete target;
      this->length--;
    }
  }
};