#include <iostream>
#include <vector>
using namespace std;

std::vector<int> arr {1,2,3,4,5,6};

bool hasPairwithSum_1(std::vector<int> array, int sum){
    // Loop first itel
    for (int i=0; i<(array.size()) ;i++){
        for(int j=i+1; j < (array.size() - 1) ; j++){
            if(array[i] + array[j]==sum){
                return true;
            }
        }
    }
    return false;
}

int main(){
    printf("has Pair of Sum: %d", hasPairwithSum_1(arr, 8));
}