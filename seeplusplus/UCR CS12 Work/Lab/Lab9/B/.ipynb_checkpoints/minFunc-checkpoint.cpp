#include "minFunc.h"
const int * min(const int arr[], int arrSize) {
    if(arrSize == 1){
        return arr;
    }
    else if(arrSize == 0){
        return nullptr;
    }
    else{
        const int * mini = min(arr, arrSize-1);
        if(*mini > arr[arrSize-1]){
            mini = &arr[arrSize-1];
        }
        return mini;
    }
}