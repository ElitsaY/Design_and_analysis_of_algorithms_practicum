#include <iostream>
#include <vector>

using std::cout;
using std::vector;

void merge(int *array, int start, int mid, int end){

    vector<int> temp(end - start + 1);

    int i = start, j = mid + 1, index = 0;

    while(i <= mid && j <= end){

        if(array[i] <= array[j])
            temp[index++] = array[i++];
        else
            temp[index++] = array[j++];

    }

    while(i <= mid)
        temp[index++] = array[i++];

    while(j <= end)
        temp[index++] = array[j++];
    
    for(size_t k = start; k <= end; ++k)
        array[k] = temp[k - start];
}

void sort(int *array, const int &start, const int &end){

    if(start >= end) return;

    int mid = (start + end) / 2;

    sort(array, start, mid);
    sort(array, mid + 1, end);

    merge(array, start, mid, end);

}

int main(){

    int array[] = { 5, 3, 5, 1, 8 };
    int size = sizeof(array) / sizeof(int);

    sort(array, 0, size - 1);

    for(size_t i = 0; i < size; ++i)
        cout << array[i] << ' ';
    cout << '\n';

}