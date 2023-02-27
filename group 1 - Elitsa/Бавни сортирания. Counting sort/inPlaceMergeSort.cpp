#include <iostream>

using std::cout;

void merge(int *array, int start, int mid, int end){

    int start2 = mid + 1, value, index;

    if(array[mid] <= array[start2]) return;

    while(start <= mid && start2 <= end)
        if(array[start] <= array[start2]) start++;
        else{

            value = array[start2], index = start2;

            while(index != start){

                array[index] = array[index - 1];
                index--;

            }

            array[start] = value;

            start++;
            mid++;
            start2++;

        }

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