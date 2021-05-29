#include <iostream>
#include <cstdlib>
#include <assert.h>
using namespace std;

class MyArray{
private:
  int *arr_value;
  string *arr_key;
  int _size;
public:
  MyArray(int _size){
    this->_size = _size;
    arr_value = (int *)malloc(_size * sizeof(int));
    arr_key = (string *)malloc(_size * sizeof(string));
  }

  ~MyArray(){
    free(arr_value);
    free(arr_key);
  }

  bool exist(int index){
    return (bool)arr_value[index];
  }

  void push(int address, string key, int value){
    assert((0 <= address) && (address < this->_size));
    arr_value[address] = value;
    arr_key[address] = key;
  }

  int getval(int address){
    return this->arr_value[address];
  }

  void print(){
    cout<<"\tNum\t\t:\tKey\t\t:\tValue"<<endl;
    for (int i=0; i < this->_size ; i++){
      if ((bool)(this->arr_value[i])){
        cout<<"\t"<<i<<"\t\t:\t\""<<this->arr_key[i]<<"\"\t:\t"<<this->arr_value[i]<<endl;
      }
      else {
        cout<<"\t"<<i<<"\t\t:\t\"NULL\"\t:\tNULL"<<endl;
      }
    }
  }
};

class HashTable{
private:
  int _size;
  MyArray *_array;
public:
  HashTable(int _size){
    this->_size = _size;
    _array = new MyArray(this->_size);
  }

  ~HashTable(){
    // Do nothing
  }

  int _hash(string key){
    int hash = 0;
    for (int i = 0; key[i] ; i++){
      hash = (hash + ( (int)key[i] * i ) ) % (this->_size);
    }
    return hash;
  }

  void set(string key, int value){
    int address = this->_hash(key);
    this->_array->push(address, key, value);
  }

  int get(string key){
    int address = this->_hash(key);
    return this->_array->getval(address);
  }

  void print(){
      this->_array->print();
  }
};


int main(){
  HashTable ht(2);
  ht.set("Y", 10);
  ht.set("Apples", 20);
  ht.print();
  int test = ht.get("Apples");
  cout<<test;

  return 0;
}