#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <iterator>
using namespace std;

class Solution {
public:
    unordered_map<int, int> twoSum(vector<int>& nums, int target) {
      unordered_map<int, int> result;
      for (int i = 0;i<nums.size()-1;i++){
        for (int j = i + 1; j < nums.size();j++){
          if (nums[i] + nums[j] == target){
            result.insert(pair<int, int>(i, j));
            return result;
          }
        }
      }
      return result;
    }
    // O(n^2)

    unordered_map<int, int> twoSum_2(vector<int>& nums, int target) {
      unordered_map<int, int> result;
      unordered_map<int, int> temp;

      for (int i=0; i < (nums.size() - 1); i++){
        if (temp.find(target - nums[i])!=temp.end()){
          result.insert(pair<int, int>(temp[target - nums[i]], i));
        }
        temp.insert(pair<int, int>(nums[i], i));
      } 

      return result;
    }
    // O(n)
};

int main(){
  int target;
  Solution a;
  vector<int> input;
  unordered_map<int, int> result;
  unordered_map<int, int> result_2;

  input.push_back(2);
  input.push_back(7);
  input.push_back(11);
  input.push_back(15);

  target = 128;
  result = a.twoSum(input, target);
  result_2 = a.twoSum_2(input, target);

  // printing map gquiz1
  unordered_map<int, int>::iterator itr, itr2;
  for (itr = result.begin(), itr2 = result_2.begin(); itr != result.end(); ++itr, ++itr2) {
      cout << "O(n^2)\t" << itr->first
          << '\t' << itr->second << '\n';
      cout << "O(n)\t" << itr2->first
          << '\t' << itr2->second << '\n';
  }
  cout << endl;

  return 0;
}