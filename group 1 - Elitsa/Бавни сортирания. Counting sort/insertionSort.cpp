#include <iostream>

using std::cout;
using std::swap;

void sort(int *array, const size_t &size){

    size_t j, k;

    for(size_t i = 1; i < size; ++i){

        k = i;
        j = i - 1;

        while(array[k] < array[j])
            swap(array[k--], array[j--]);

    }

}

int main(){

    int array[] = { 5, 3, 5, 1, 8 };
    size_t size = sizeof(array) / sizeof(int);

    sort(array, size);

    for(size_t i = 0; i < size; ++i)
        cout << array[i] << ' ';
    cout << '\n';

}