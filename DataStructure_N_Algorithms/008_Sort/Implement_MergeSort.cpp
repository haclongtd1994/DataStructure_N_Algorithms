#include "Header.h"

vector<int> slicing(vector<int> value, int pos, int num) {
  vector<int> result;
  int result_idx = 0;
  
  if (((uint16_t)pos + (uint16_t)num) > value.size())
    return {};

  while (result_idx <= num) {
    result.push_back(value.at(pos));
    result_idx++;
    pos++;
  }

  return result;
}

vector<int> SubMerge(vector<int> left, vector<int> right) {
  vector<int> result;
  int left_idx = 0;
  int right_idx = 0;

  while ((left_idx < left.size()) || (right_idx < right.size())) {
    if (left_idx == left.size()) {
      result.push_back(right.at(right_idx));
      right_idx++;
    }
    else if (right_idx == right.size()) {
      result.push_back(left.at(left_idx));
      left_idx++;
    }
    else {
      if (right.at(right_idx) < left.at(left_idx)) {
        result.push_back(right.at(right_idx));
        right_idx++;
      }
      else {
        result.push_back(left.at(left_idx));
        left_idx++;
      }
    }
  }

  return result;
}

vector<int> MergeSort(vector<int> value) {
  // Base Recursion
  if (value.size() == 1)
    return value;

  // devide 2 vector left and right
  int left_start = 0;
  int left_end  = ((int)value.size() / 2) - 1;
  int right_start = ((int)value.size() / 2);
  int right_end = (int)value.size() - 1;
  vector<int> left = slicing(value, left_start, left_end - left_start);
  vector<int> right = slicing(value, right_start, right_end - right_start);

  // Recursion
  return SubMerge(
    MergeSort(left),
    MergeSort(right)
  );
}