#include <stdio.h>

#define TIPODATO long
#define MAX_LEN unsigned long

struct Node{
    TIPODATO dato;
    struct Node *next;

    Node(){
        next = NULL;
    }

    Node(TIPODATO dato_a_insertar) : Node(){
        dato = dato_a_insertar;
        }        
};

struct List{
    TIPODATO len;
    struct Node *first;
    struct Node *last;

    List(){
        first = NULL;
        last = NULL;
        len = 0;
    }
};
