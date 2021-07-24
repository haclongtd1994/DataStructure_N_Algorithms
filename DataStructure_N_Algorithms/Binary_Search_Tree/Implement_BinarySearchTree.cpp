#include "Header.h"

struct Binary_Node {
  int value;
  Binary_Node* left;
  Binary_Node* right;
};
typedef struct Binary_Node Binary_Node;

class BinarySearchTree {
private:
  Binary_Node* root;
public:
  BinarySearchTree() {
    root = NULL;
  }

  ~BinarySearchTree() {

  }

  void insert(int value) {
    Binary_Node* node = new Binary_Node;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    if (root == NULL) {
      root = node;
    }
    else {
      Binary_Node* temp = this->root;
      while (temp) {
        if (value > temp->value) {
          if (temp->right == NULL)
            break;
          temp = temp->right;
        }
        else {
          if (temp->left == NULL)
            break;
          temp = temp->left;
        }
      }
      if (temp->value < value)
        temp->right = node;
      else
        temp->left = node;
    }
  }

  bool lookup(int value) {
    if (!this->root)
      return false;
    Binary_Node* temp = this->root;
    while (temp) {
      if (temp->value == value)
        return true;
      else if (value > temp->value) {
        temp = temp->right;
      }
      else {
        temp = temp->left;
      }
    }
    return false;
  }

  void remove(int value) {
    Binary_Node* cur = this->root;
    Binary_Node* par = NULL;

    while (cur) {
      if (cur->value == value) {
        // Go ahead remove job
        
        // Check cur node not have right child
        if (cur->right == NULL) {
          if (par == NULL)
            this->root = cur->left;
          else {
            // Check relationship between parent node and left node
            if (par->value > cur->value) {
              par->left = cur->left;
            }
            else {
              par->right = cur->left;
            }
          }
        }
        
        // Cur have right child but right child doesn't have left child
        else if (cur->right->left == NULL) {
          cur->right->left = cur->left;
          if (par == NULL)
            this->root = cur->left;
          else {
            // Check Opt1: value of parent node > value of current node
            if (par->value > cur->value) {
              par->left= cur->right;
            }
            else {
              par->right = cur->right;
            }
          }
        }
        
        // Right child have left child
        else {
          // Let's find leftmost & leftmostpar
          Binary_Node* leftmost = cur->right->left;
          Binary_Node* leftmostpar = cur->right;
          while (leftmost->left) {
            leftmostpar = leftmost;
            leftmost = leftmost->left;
          }

          leftmostpar->left = leftmost->right;
          leftmost->left = cur->left;
          leftmost->right = cur->right;

          if (par == NULL)
            this->root = leftmost;
          else {
            if (par->value < cur->value)
              par->right = leftmost;
            else
              par->left = leftmost;
          }
        }
        return;
      }
      else if (value > cur->value) {
        par = cur;
        cur = cur->right;
      }
      else {
        par = cur;
        cur = cur->left;
      }
    }
    return;
  }

  void print() {
    this->print2D(this->root, 0); // Initial with space equal 0
  }

  void print2D(Binary_Node* node, int space) {
    if (node == NULL)
      return;

    // Recursion right node
    this->print2D(node->right, space + 10);

    cout << endl;
    for (int i = 0; i < space; i++)
      cout << " ";
    cout << node->value << endl;

    // Recursion left node
    this->print2D(node->left, space + 10);
  }
};