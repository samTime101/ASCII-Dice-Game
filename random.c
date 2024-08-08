#include<stdlib.h>
#include "./include/rand.h"

int _random(int max,int min){
    //rand() % (max_number + 1 - minimum_number) + minimum_number
    return rand() % (max + 1 - min) + min;
}
