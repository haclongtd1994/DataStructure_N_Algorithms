#include <iostream>
#include <cstdlib>

using namespace std;

void mergesortArray(int *arr1, int length1, int *arr2, int length2, int slength, \
  int *result){
    for (size_t i = 0, j = 0, k = 0; i < slength; i++)
    {
        if (j != length1 && k != length2){
            if (arr1[j] < arr2[k]){
                result[i] = arr1[j];
                j++;
            }
            else if (arr2[k] < arr1[j]){
                result[i] = arr2[k];
                k++;
            }
            else {
                result[i] = arr1[j];
                result[i+1] = arr1[j];
                i++;
                j++;
                k++;
            }
        }
        else if (j == length1){
            result[i] = arr2[k];
            k++;
        }
        else if (k == length2){
            result[i] = arr1[j];
            j++;
        }
    }
}

int main(){
    int arr1[5] = {1, 12, 53, 129,2245};
    int arr2[4] = {2, 4, 53, 235};
    int length1 = sizeof(arr1)/sizeof(arr1[0]);
    int length2 = sizeof(arr2)/sizeof(arr2[0]);
    int slength = length1 + length2;
    static int *result;
    result = (int *)malloc(slength * sizeof(int));

    mergesortArray(arr1, length1, arr2, length2, slength, result);
    for ( int i = 0; i < slength; i++ ) {
        cout << "*(result + " << i << ") : ";
        cout << *(result + i) << endl;
    }

    return 0;
}