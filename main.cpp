#include <iostream>
#include <stdio.h>
#include <limits.h>
#include "list.h"

using namespace std;

int main(){
    List lista;
    
    for(unsigned long i = 0; i < 10; i++){
        append(i, lista);
    }

    printv2(lista);

    return 0;
}