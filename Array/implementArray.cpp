#include <iostream>
#include <cstring>
#include <assert.h>

using namespace std;

const int INIT_ARRAY = 5;
const int Factor = 2;

template <class T>
class dynamic_array{
private:
    T* array;
    int _size;
    int capacity;
public:
    //constructor
    dynamic_array(){
        this->_size = 0;
        this->capacity = INIT_ARRAY;
        array = new T[this->capacity];
    }
    
    // deconstructor
    ~dynamic_array(){
        delete[] array;
    }
    
    // Function to get data at index
    T get(int index){
        // Check range of the index
        assert((0 <= index) && (index < _size));
        return array[index];
    }

    // Function to resize data
    void resize(){
        capacity = capacity * Factor;       // Load new capacity
        T* temp = new T[capacity];      // Init new temp array with new capacity
        copy(array, array + _size, temp);   // copy old data to temp array
        delete[] array;                     // Delete old array
        array = temp;                       // Assign temp to array
    }

    // Function to Insert data
    void InsertData(T element, int pos){
        // Check range of the position
        assert((0<=pos) && (pos<_size+1));
        // Check size overload capacity
        if (_size == capacity){
            resize();
        }
        for (int i = _size; i > pos;i--){
            array[i] = array[i+1];
        }
        _size++;
        array[pos] = element;
    }

    // Append data
    void push(T data){
        InsertData(data, _size);
    }

    // Print pretty
    void pretty_print(){
        cout<<"[";
        for (int i=0; i<_size;i++)
          cout<<array[i]<<" ";
        if(_size==0)
          cout<<array[0];
        cout<<"]"<<endl;
    }
};

int main(){
    dynamic_array<int> arr;
    arr.push(0);
    arr.push(7);
    arr.push(7);
    arr.push(5);
    arr.push(0);
    arr.push(1);
    arr.push(6);
    arr.push(0);
    arr.push(7);
    arr.push(7);
    arr.pretty_print();
    return 0;
}