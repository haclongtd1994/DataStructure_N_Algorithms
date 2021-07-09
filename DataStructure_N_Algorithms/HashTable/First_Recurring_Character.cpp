//Google question:
//Give an array = [2,5,1,2,3,5,1,2,4]
//It should return 2
#include "Header.h"

namespace FirstRecurringChar {
  // Implement hash table
  struct ht_item {
    char* key;
    int value;
  };
  typedef struct ht_item ht_item;

  struct linked_list {
    ht_item* items;
    linked_list* next;
  };
  typedef struct linked_list linked_list;

  struct hash_table {
    ht_item** items;
    linked_list** overflow_buckets;
    int size;
    int count;
  };
  typedef struct hash_table hash_table;

  class Hash_table {
  private:
    hash_table* table;
  public:
    Hash_table(int size) {
      table = (hash_table*)malloc(sizeof(hash_table));
      table->size = size;
      table->count = 0;
      table->items = (ht_item**)calloc(table->size, sizeof(ht_item*));
      table->overflow_buckets = (linked_list**)calloc(table->size, sizeof(linked_list*));
      for (int i = 0; i < table->size; i++) {
        table->items[i] = NULL;
        table->overflow_buckets[i] = NULL;
      }
    }

    ~Hash_table() {
      for (int i = 0; i < table->size; i++) {
        free(table->items[i]);
        free(table->overflow_buckets[i]);
      }
      free(table->items);
      free(table->overflow_buckets);
      free(table);
    }

    int _hash(char* key) {
      int hash = 0;
      for (int i = 0; i < (sizeof(key) / sizeof(char)); i++) {
        hash = (hash + ((int)key[i] * i)) % table->size;
      }
      return hash;
    }

    ht_item* create_item(char* key, int value) {
      ht_item* item = (ht_item*)malloc(sizeof(ht_item));
      item->key = (char*)malloc(sizeof(char));
      copy(key, key + (sizeof(key) / sizeof(char)), item->key);
      item->value = value;
      return item;
    }

    linked_list* create_list(char* key, int value) {
      linked_list* list = (linked_list*)malloc(sizeof(linked_list));
      list->items = create_item(key, value);
      list->next = NULL;
      return list;
    }

    linked_list* search_key(linked_list* list, char* key) {
      bool flag = false;
      while (list) {
        if (strcmp(list->items->key, key) == 0) {
          flag = true;
          break;
        }
        list = list->next;
      }
      if (flag) {
        return list;
      }
      else {
        return NULL;
      }
    }

    void Handle_collission(char* key, int value) {
      // Get index
      int index = Hash_table::_hash(key);
      linked_list* node = table->overflow_buckets[index];

      // Check:: First linked list not exist
      if (!node) {
        node = create_list(key, value);
        table->overflow_buckets[index] = node;
        table->count++;
      }
      // Check: Second linked list not exist
      else if (!node->next) {
        // Check:: Exist key in overflowbukets
        linked_list* search = Hash_table::search_key(node, key);
        if (!search) {
          node->next = create_list(key, value);
          table->overflow_buckets[index] = node;
          table->count++;
        }
        // Check:: Exist key in overflowbuckets
        else {
          search->items->value = value;
          goto done;
        }
      }
      // Check:: Loop to end of linked list
      else {
        // Check:: Exist key in overflowbukets
        linked_list* search = Hash_table::search_key(node, key);
        if (!search) {
          linked_list* temp = node;
          while (node->next->next) {
            node = node->next;
          }
          node = node->next;
          node->next = create_list(key, value);
          table->overflow_buckets[index] = temp;
          table->count++;
        }
        // Check:: Exist key in overflowbuckets
        else {
          search->items->value = value;
          goto done;
        }

      }
    done:
      return;
    }

    void ht_insert(char* key, int value) {
      // Get index from key
      int index = Hash_table::_hash(key);

      // Check:: Not exist element with current index
      if (!table->items[index]) {
        // Check:: Full
        if (table->count == table->size) {
          cout << "Hash table full!" << endl;
          return;
        }
        // Check:: Not full
        else {
          ht_item* item = Hash_table::create_item(key, value);
          table->items[index] = item;
          table->count++;
          return;
        }
      }
      // Check:: Exist element with cur index
      else {
        // Check:: Update key exist
        if (strcmp(table->items[index]->key, key) == 0) {
          table->items[index]->value = value;
          return;
        }
        // Check: Has collission insert
        else {
          // Check:: Full
          if (table->count == table->size) {
            cout << "Hash table full!" << endl;
            return;
          }
          // Check:: Not full
          else {
            // Using linked list as overflow buckets to handle collission
            Handle_collission(key, value);
          }
        }
      }
    }

    void ht_delete(char* key) {
      int index = Hash_table::_hash(key);
      ht_item* item = table->items[index];
      linked_list* node = table->overflow_buckets[index];

      // Check:: item not exist
      if (!item) {
        cout << "Not exist this hash key: " << key << endl;
        return;
      }
      // Check:: Item existed
      else {
        if (!node && strcmp(item->key, key) == 0) {
          free(item->key);
          free(item);
          return;
        }
        else if (node) {
          if (strcmp(item->key, key) == 0) {
            item = Hash_table::create_item(node->items->key, node->items->value);
            linked_list* temp = node->next;
            node->next = NULL;
            node = temp;
            table->items[index] = item;
            table->overflow_buckets[index] = node;
            return;
          }
          else {
            bool flag = false;
            linked_list* curr = node;
            linked_list* prev = NULL;

            while (curr) {
              if (strcmp(curr->items->key, key) == 0) {
                flag = true;
                if (!prev) {
                  this->table->overflow_buckets[index] = curr->next;
                  free(curr->items->key);
                  free(curr->items);
                  free(curr);
                  return;
                }
                else {
                  prev->next = curr->next;
                  curr->next = NULL;
                  free(curr);
                  return;
                }
              }
              else {
                // Do nothing
              }

              prev = curr;
              curr = curr->next;
            }
            if (!flag)
              cout << "Not exist this hash key: " << key << endl;
          }
        }
      }
    }

    void print() {
      cout << "------------ Hash Table ------------" << endl;
      cout << setw(5) << "Index" << setw(10) << "Key:" << setw(10) << \
        "Value:" << endl;
      for (int i = 0; i < table->size; i++) {
        if (table->items[i]) {
          cout << setw(5) << i << setw(10) << table->items[i]->key << setw(10) \
            << table->items[i]->value << endl;
          linked_list* node = table->overflow_buckets[i];
          while (node) {
            cout << setw(60) << "-- Overflow buckets --" << endl;
            cout << setw(30) << "Key:" << setw(40) << "Value:" << endl;
            cout << setw(30) << node->items->key << setw(40) << \
              node->items->value << endl;
            node = node->next;
          }
        }
        else {
          // Do nothing
        }
      }
    }

    bool findkey(char* key) {
      int i = Hash_table::_hash(key);
      if (table->items[i]) {
        if (strcmp(table->items[i]->key, key) == 0) {
          return true;
        }
        linked_list* node = table->overflow_buckets[i];
        while (node) {
          if (strcmp(node->items->key, key) == 0)
            return true;
          node = node->next;
        }
      }
      return false;
    }
  };

  // Using the hash table data structure lib with unordered_map
  int first_recurring_unordered_map(int* arr, int length) {
    unordered_map<int, int> map;
    for (int i = 0; i < length; i++) {
      if (map[arr[i]] != NULL) {
        return arr[i];
      }
      else {
        map[arr[i]] = i;
      }
    }
  }
  // O(n)

  // Using the hash table data structure to solve this problem
  int first_recurring_ht(int* arr, int length) {
    int result = 0;
    Hash_table table(length);

    for (int i = 0; i < length; i++) {
      if (table.findkey( (char*)("Str" + (char)arr[i]) )) { // Find in Ht: O(1)
        result = arr[i];
        goto done;
      }
      else {
        table.ht_insert( (char*)("Str" + (char)arr[i]) , arr[i]);
      }
    }

done:
    return result;
  }
  // O(n)

  // Natural solution
  int first_recurring(int* arr, int length) {
    int result = 0;
    int index;
    if (length == 1)
      return arr[length - 1];
    for (int i = 0; i < length; i++) {
      for (int j = i + 1; j < length; j++) {
        if (arr[i] == arr[j]) {
          if (result == 0) {
            result = arr[i];
            index = j;
            break;
          }
          else if (result != 0 && j < index) {
            result = arr[i];
            index = j;
            break;
          }
          if (i >= index)
            goto done;
        }
      }
    }

  done:
    return result;
  }
  // O(n^2)

  int First_Recurring_Character_main() {
    int arr[9] = { 2, 3, 3, 5, 6, 7, 2 , 9, 10 };

    int result = first_recurring(arr, sizeof(arr) / sizeof(int));
    int retusl2 = first_recurring_ht(arr, sizeof(arr) / sizeof(int));
    int retusl3 = first_recurring_unordered_map(arr, sizeof(arr) / sizeof(int));

    cout << result << endl;
    cout << retusl2 << endl;
    cout << retusl3 << endl;


    //Hash_table table(10);
    //table.ht_insert((char*)"Hung", 123);
    //table.ht_insert((char*)"Hung", 13);
    //table.ht_insert((char*)"Y", 456);
    //table.ht_insert((char*)"Y", 1);
    //table.ht_insert((char*)"Y", 3);
    //table.ht_insert((char*)"Cho", 789);
    //table.ht_insert((char*)"Cho", 123);
    //table.ht_insert((char*)"Cho", 456);
    //table.ht_insert((char*)"sddfh", 456);
    //table.ht_insert((char*)"sddfh", 456);
    //table.ht_insert((char*)"a", 456);
    //table.ht_insert((char*)"b", 456);
    //table.ht_insert((char*)"c", 456);
    //table.ht_delete((char*)"Hung");
    //table.ht_delete((char*)"Nguyen");
    //table.ht_delete((char*)"sddfh");
    //table.ht_delete((char*)"b");
    //table.print();

    return 0;
  }
}