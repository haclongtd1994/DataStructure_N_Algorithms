#include "Header.h"

vector<char> ReverseStringIterative(vector<char> str) {
  vector<char> ReverseStr;
  for (auto i = str.size(); i > 0; i--) {
    char temp = str.at(i - 1);
    ReverseStr.push_back(temp);
  }
  return ReverseStr;
}

string ReverseStringRecursion(string str) {
  if (str.empty())
    return "";
  else {
    return ReverseStringRecursion(str.substr(1)) + str.at(0);
  }
}