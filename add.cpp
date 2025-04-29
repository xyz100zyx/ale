#include <emscripten/bind.h>
#include <vector>
#include <iostream>

#ifdef __cplusplus
#define EXTERN extern "C"
#else
#define EXTERN
#endif

EXTERN EMSCRIPTEN_KEEPALIVE
int add(int a, int b) {
    return a + b;
}

EXTERN EMSCRIPTEN_KEEPALIVE
int sumArray(int array[], int length) {
    std::vector<int> vec(array, array + length);
    std::cout << "arr: " << array;
    int sum = 0;
    for (int num : vec) {
        sum += num;
    }
    return sum;
}