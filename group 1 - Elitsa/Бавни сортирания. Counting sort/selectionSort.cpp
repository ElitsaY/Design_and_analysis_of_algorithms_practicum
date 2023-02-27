#include <iostream>

using std::cout;
using std::swap;

void sort(int *array, const size_t &size){

    int m, index;

    for(size_t i = 0; i < size - 1; ++i){

        m = array[i];
        index = i;
        for(size_t j = i + 1; j < size; ++j)
            if(m > array[j]){

                m = array[j];
                index = j;

            }

        if(i != index)
            swap(array[i], array[index]);

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