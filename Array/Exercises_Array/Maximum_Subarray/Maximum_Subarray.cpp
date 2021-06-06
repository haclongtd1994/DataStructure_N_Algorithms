#include <iostream>
#include <vector>
using namespace std;

vector<int> Solution(int *arr, int length){
  vector<int> vmax;
  int max=0;
  vector<int> vcurrent_value;
  int current_value=0;

  if (length != 1){
    for (int i = 0; i < (length-1); i++){
      current_value = arr[i];
      vcurrent_value.clear();
      vcurrent_value.push_back(i);
      for (int j = i + 1; j < (length); j++){
        current_value += arr[j];
        vcurrent_value.push_back(j);
        if (current_value > max){
          max = current_value;
          vmax = vcurrent_value;
        }
      }
    }
  }
  else{
    vmax.push_back(0);
    max = arr[0];
  }
  vmax.push_back(max);
  return vmax;
}

int main(){
  vector<int> max;
  int _array[] = {5,4,-1,7,8};
  int length = sizeof(_array)/sizeof(_array[0]);

  max = Solution(_array, length);

  cout<<"Output: "<<max[max.size()-1]<<endl;
  for (int i=0; i<max.size()-1; i++)
    cout<<max[i]<<" ";
  cout<<endl;

  return 0;
}