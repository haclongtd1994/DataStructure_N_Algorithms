#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

/* -------------------------------- Hash Table ------------------------------ */
// Implement struct for items of hash table
struct ht_item{
  char* key;
  int value;
};
typedef struct ht_item ht_item;

struct linked_list{
  ht_item* item;
  linked_list* next;
};
typedef struct linked_list linked_list;

struct hash_table{
  ht_item** items;
  linked_list** overflow_buckets;
  int size;
  int count;
};
typedef struct hash_table hash_table;

class Hash_Table{
private:
  hash_table* table;
public:
  Hash_Table(int size){
    table = (hash_table*)malloc(sizeof(hash_table));
    this->table->size = size;
    this->table->count = 0;
    this->table->items = \
      (ht_item**)calloc(this->table->size, sizeof(ht_item*));
    this->table->overflow_buckets = \
      (linked_list**)calloc(this->table->size, sizeof(linked_list*));
    for (int i=0; i<this->table->size; i++){
      this->table->items[i] = NULL;
      this->table->overflow_buckets[i] = NULL;
    }
  }

  ~Hash_Table(){
    for (int i=0; i<this->table->size; i++){
      free(this->table->items[i]);
      free(this->table->overflow_buckets[i]);
    }
    free(this->table->items);
    free(this->table->overflow_buckets);
    free(this->table);
  }

  int _hash(char* key){
    int hash = 0;
    for (int i=0; key[i]; i++)
      hash = (hash + ((int)key[i] * i)) % table->size;
    return hash;
  }

  void handle_collission(int index, ht_item* item){
    linked_list* list = (linked_list*)malloc(sizeof(linked_list));
    list->item = item;
    list->next = NULL;

    if(!this->table->overflow_buckets[index]){
      this->table->overflow_buckets[index] = list;
      return;
    }
    else if(!this->table->overflow_buckets[index]->next) {
      this->table->overflow_buckets[index]->next = list;
      return;
    }
    else {
      linked_list* temp = this->table->overflow_buckets[index];
      while(temp->next->next)
        temp = temp->next;
      temp = temp->next;
      temp->next = list;
    }
  }

  void ht_insert(char* key, int value){
    int index = Hash_Table::_hash(key);
    // create item object
    ht_item* item = (ht_item*)malloc(sizeof(ht_item));
    item->key = (char*)malloc(sizeof(char));
    copy(key, key + (sizeof(key)/sizeof(char)), item->key);
    item->value = value;

    // Check index exist or not
    if (!this->table->items[index]){
      // Check full capacity
      if (this->table->size == this->table->count){
        cout << "Hash is full!";
        return;
      }
      // Add new item
      else{
        this->table->items[index] = item;
        this->table->count++;
        return;
      }
    }
    // If existing
    else {
      // Check key match or not
      if (strcmp(this->table->items[index]->key, key) == 0){
        this->table->items[index]->value = value;
        return;
      }
      // Handle collission
      else {
        handle_collission(index, item);
        return;
      }
    }
  }

  void ht_delete(char* key) {
    int index = this->_hash(key);
    ht_item* item = this->table->items[index];
    linked_list* node = this->table->overflow_buckets[index];

    // Not exist data
    if (!item) {
      cout << "Key string not exist hash key! Please check again!";
      return;
    }
    // Exist data
    else {
      // Check node: NULL and key exist in item
      if (!node && strcmp(item->key, key) == 0) {
        item->key = NULL;
        item = NULL;
        free(item->key);
        free(item);
        this->table->count--;
        return;
      }
      // Node != NULL
      else if (node) {
        // Check position of data
        // Exist at items of hash table?
        if (strcmp(item->key, key) == 0) {
          linked_list* temp = node->next;
          node->next = NULL;
          ht_item* itemp = (ht_item*)malloc(sizeof(ht_item));
          itemp->key = (char*)malloc(sizeof(char));
          copy(key, key + (sizeof(key) / sizeof(char)), node->item->key);
          itemp->value = node->item->value;
          item = itemp;

          this->table->overflow_buckets[index] = temp;
          return;
        }
        // Exist in overflow buckets
        else {
          linked_list* curr = node;
          linked_list* prev = NULL;

          while (curr) {
            if (strcmp(curr->item->key, key) == 0) {
              if (prev == NULL) {
                this->table->overflow_buckets[index] = curr->next;
                free(curr->item->key);
                free(curr->item);
                free(curr);
                return;
              }
              else {
                prev->next = curr->next;
                curr->next = NULL;
                free(curr->item->key);
                free(curr->item);
                free(curr);
                return;
              }
            }

            prev = curr;
            curr = curr->next;
          }
        }
      }
    }
  }

  void print(){
    cout<< "Hash Table:" << endl;
    cout<<setw(10)<<"Key:"<<setw(20)<<"Value:"<<endl;
    for (int i=0; i<this->table->size; i++){
      if (this->table->items[i]){
        cout << setw(10) << this->table->items[i]->key << \
          setw(20) << this->table->items[i]->value;
        linked_list* node = this->table->overflow_buckets[i];
        while(node){
          cout << " => overflow_buckets => " << "Key: " << node->item->key \
            << "  Value:" << node->item->value;
          node = node->next;
        }
        cout<<endl;
      }
    }
  }
};



int main(){
  Hash_Table table(4);
  cout << table._hash((char *)"Hung") << " " << table._hash((char *)"Heo");
  table.ht_insert((char *)"Hung", 123);
  table.ht_insert((char *)"Y", 456);
  table.ht_insert((char *)"Cho", 789);
  table.ht_insert((char *)"YYYY", 9999);
  table.ht_delete((char*)"YYYY");
  table.print();
  return 0;
}