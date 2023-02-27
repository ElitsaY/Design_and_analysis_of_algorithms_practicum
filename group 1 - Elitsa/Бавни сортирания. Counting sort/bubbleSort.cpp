#include <iostream>

using std::cout;
using std::swap;

void sort(int *array, const size_t &size){

    for(size_t i = 0; i < size - 1; ++i)
        for(size_t j = i + 1; j < size; ++j)
            if(array[i] > array[j])
                swap(array[i], array[j]);

}

int main(){

    int array[] = { 5, 3, 5, 1, 8 };
    size_t size = sizeof(array) / sizeof(int);

    sort(array, size);

    for(size_t i = 0; i < size; ++i)
        cout << array[i] << ' ';
    cout << '\n';

}