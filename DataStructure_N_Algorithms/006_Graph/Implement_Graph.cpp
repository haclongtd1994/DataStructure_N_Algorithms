#include "Header.h"

class Graph {
private:
  unordered_set<string> key;
  unordered_multimap<string, int> node;
public:
  void addVertex(string key) {
    this->key.insert(key);
  }

  void addEdge(string key, int value) {
    if (this->key.find(key) == this->key.end()) {
      cout << "Vertex not found !" << endl;
    }
    else {
      node.insert({ {key, value} });
      node.insert({ {std::to_string(value), std::stoi(key)} });
    }
  }

  void print() {
    bool flag = false;
    for (unsigned int i = 0; i != this->node.bucket_count(); i++) {
        for (auto j = this->node.begin(i); j != this->node.end(i); j++) {
          cout << "Bucket #" << j->first << ": ";
          cout << "<" << j->first << ", " << j->second
            << ">  ";
          flag = true;
        }
        if (flag) {
          cout << endl;
          flag = false;
        }
    }
  }

};