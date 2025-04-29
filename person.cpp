#include <emscripten/bind.h>

#ifdef __cplusplus
#define EXTERN extern "C"
#else
#define EXTERN
#endif

EXTERN
struct Person {
    const char* name;
    int age;
};

EXTERN EMSCRIPTEN_KEEPALIVE
Person* getTheOldestPerson(Person* persons, int length) {
    int maxAge = 0;
    int index = 0;
    for (int i = 0; i < length; i++) {
        if ( persons[i].age >= maxAge ) {
            maxAge = persons[i].age;
            index = i;
        }
    }
    return &persons[index];
}