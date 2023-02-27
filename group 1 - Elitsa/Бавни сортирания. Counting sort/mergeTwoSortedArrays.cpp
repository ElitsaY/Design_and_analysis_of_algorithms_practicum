#include <iostream>

using std::cout;

void createArr(const int *array1, const int *array2, const size_t &size1, const size_t &size2, int *result){

    size_t i = 0, j = 0, k = 0;

    while(i < size1 && j < size2)
        if(array1[i] < array2[j])
            result[k++] = array1[i++];
        else
            result[k++] = array2[j++];

    while(i < size1)
        result[k++] = array1[i++];

    while(j < size2)
        result[k++] = array2[j++];

}

int main(){

    int array1[] = { 1, 3, 5, 7, 8 };
    int array2[] = { 2, 3, 4, 8, 10 };

    size_t size1 = sizeof(array1) / sizeof(int);
    size_t size2 = sizeof(array2) / sizeof(int);

    int result[size1 + size2];

    createArr(array1, array2, size1, size2, result);

    for(size_t i = 0; i < size1 + size2; ++i)
        cout << result[i] << ' ';
    cout << '\n';

}