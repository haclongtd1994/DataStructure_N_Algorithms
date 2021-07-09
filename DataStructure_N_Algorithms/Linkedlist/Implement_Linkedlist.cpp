#include "Header.h"

struct linkedlist {
  int item;
  linkedlist* next;
};
typedef struct linkedlist linkedlist;

class Linked_list {
private:
  linkedlist* head,* tail;
  int length;
public:
  Linked_list(int value) {
    // Initialize node;
    this->head = new linkedlist;
    this->head->item = value;
    this->head->next = NULL;
    this->tail = this->head;
    this->length = 1;
  }

  ~Linked_list() {
    linkedlist* temp = new linkedlist;
    while (head) {
      temp = head->next;
      free(head);
      head = temp;
    }
  }

  void print() {
    int count = 0;
    linkedlist* temp = new linkedlist;
    temp = head;
    cout << "Linked List:" << endl;
    while (temp) {
      cout << count << " : " << temp->item << endl;
      count++;
      temp = temp->next;
    }
    cout << "Length: " << this->length;
  }

  void append(int item) {
    linkedlist* temp = new linkedlist;
    temp->item = item;
    temp->next = NULL;
    this->tail->next = temp;
    this->tail = temp;
    this->length++;
  }

  void prepend(int item) {
    linkedlist* temp = new linkedlist;
    temp->item = item;
    temp->next = this->head;
    this->head = temp;
    this->length++;
  }

  linkedlist* traverseToIndex(int index) {
    int counter = 0;
    linkedlist* temp = new linkedlist;
    temp = this->head;
    while (counter != index) {
      temp = temp->next;
      counter++;
    }
    return temp;
  }

  void Insert(int item, int pos) {
    if (pos == 0) {
      this->prepend(item);
    }
    else if (pos >= (this->length)) {
      this->append(item);
    }
    else {
      linkedlist* temp = new linkedlist;
      temp->item = item;
      linkedlist* prev = traverseToIndex(pos - 1);
      linkedlist* next = prev->next;
      prev->next = temp;
      temp->next = next;
      this->length++;
    }
  }

  void Remove(int pos) {
    if (pos == 0) {
      linkedlist* temp = head->next;
      free(this->head);
      this->head = temp;
      this->length--;
    }
    else if (pos >= (this->length - 1)) {
      linkedlist* prev = this->traverseToIndex(this->length - 2);
      prev->next = NULL;
      free(this->tail);
      this->tail = prev;
      this->length--;
    }
    else {
      linkedlist* prev = this->traverseToIndex(pos - 1);
      linkedlist* target = prev->next;
      prev->next = target->next;
      free(target);
      this->length--;
    }
  }

};