#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

// Implement struct for items of hash table
struct ht_item{
  char* key;
  int value;
};
typedef struct ht_item ht_item;

struct Hash_Table{
  ht_item** items;
  int size;
  int count;
};
typedef class Hash_Table Hash_Table;

// Implement class for hash table
class c_Hash_Table{
private:
  Hash_Table* table;
public:
  c_Hash_Table(int size){
    table = (Hash_Table*)malloc(sizeof(Hash_Table));
    table->size = size;
    table->count = 0;
    table->items = (ht_item**)calloc(table->size, sizeof(ht_item*));
    for (int i=0;i<table->size;i++){
      table->items[i] = NULL;
    }
  }

  ~c_Hash_Table(){
    for (int i=0;i<table->size;i++){
      if (table->items[i]!=NULL){
        free(table->items[i]->key);
        free(table->items[i]);
      }
    }
    free(table->items);
    free(table);
  }

  int _hash(char* key){
    int hash = 0;
    for (int i = 0; key[i] ; i++){
      hash = (hash + ( (int)key[i] * i ) ) % (table->size);
    }
    return hash;
  }

  ht_item* create_item(char* key, int value){
    ht_item* item = (ht_item*)malloc(sizeof(ht_item));
    item->key = (char*)malloc( sizeof(key)/sizeof(char) + 1);

    copy(key, key + sizeof(key)/sizeof(char), item->key);
    item->value = value;
    return item;
  }

  void handle_collision(ht_item* item) {
  }

  void ht_insert(char* key, int value){
    // Create item
    ht_item* item = create_item(key, value);
    int index = _hash(key);
    
    // Check key not exist
    if (table->items[index] == NULL){
      // Check table full
      if (table->size == table->count){
        cout<<"Insert Error: Hash table full"<<endl;
        free(item);
        return;
      }
      else{
        table->items[index] = item;
        table->count++;
      }
    }
    // If key exist
    else{
      // Scenario 1: Update value
      if (strcmp(table->items[index]->key, key)){
        table->items[index]->value = value;
      }
      // Scenario 2: Collision
      else{
        handle_collision(item);
        return;
      }
    }
  }

  void print_all(){
    cout<<"Hash Table print out:"<<endl;
    cout<<setw(10)<<"Key:"<<setw(20)<<"Value:"<<endl;
    for (int i=0;i<table->size;i++){
      if (table->items[i]!=NULL){
        cout<<setw(10)<<table->items[i]->key<<setw(20)<<table->items[i]->value<<endl;
      }
    }
  }

};



int main(){
  c_Hash_Table test(5);
  test.ht_insert((char*)"Hung", 10);
  test.ht_insert((char*)"Y", 100);
  test.print_all();
  return 0;
}