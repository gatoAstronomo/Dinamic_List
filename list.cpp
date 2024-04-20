#include <stdio.h>
#include <iostream>
#include "list.h"


using namespace std;

bool empty(List lista){
	return(lista.first==NULL);
}

MAX_LEN len(List lista){
	return lista.len;
}

void next_node(Node* &node){
    if(node != NULL)
        node = node->next;
}

void inserta(MAX_LEN index, TIPODATO x,  List &lista){
	
    if(index < 1 || index > lista.len + 1){
        printf("error: fuera de indice\n");
        return;
	}

    // Guarda toda la la lista de nodos en aux
    Node* aux = lista.first;

    // Crea el nodo que vamos a insertar
    Node* n = new Node;
    n->dato = x;

    if(index == 1){ // Si inserta primero
        lista.first = n;
        lista.first->next = aux;
        
        lista.last = n;
        lista.len++;
    }
    else if(index == lista.len + 1){  // Si inserta alfinal este sera el nuevo ultimo nodo
        
        lista.last->next = n;

        lista.last = n;
        lista.len++;
    }else{
        for(MAX_LEN i = 0; i < index - 2; i++){ // Si inserta entremedio
            next_node(aux);
        }
        n->next = aux->next;
        aux->next = n; 
        lista.len++;
    }
    
}

void append(TIPODATO x, List &lista){
    // Crea el nodo que vamos a insertar y le inserta el numero
    Node* n = new Node;
    n->dato = x;

    if(lista.first == NULL){
        lista.first = n;
        lista.last = n;
        lista.len++;
    }else{
	    lista.last->next = n;

        lista.last = n;
        lista.len++;
    }

}

void print(List lista){

    if(lista.len==0){
        cout << "[]\n";
        return;
    }

    Node* node = lista.first;
    printf("[%d, ", node->dato);

     for(MAX_LEN i = 1 ; i < lista.len; i++){
        node = node->next;
        printf("%d, ", node->dato);
    }
    printf("\b\b]\n");
}

void printv2(List lista){
    
    if(lista.len==0){
        cout << "[]\n";
        return;
    }
    
    printf("[%d, ", lista.first->dato);

     for(Node *node = lista.first->next; node != NULL ; node = node->next){
        printf("%d, ", node->dato);
    }
    printf("\b\b]\n");
}

TIPODATO recupera(MAX_LEN index, List lista){
    Node* node = lista.first; 
    for(MAX_LEN i = 1 ; i < index ; i++){
        node = node->next;
    }
    return node->dato;
}

MAX_LEN index(TIPODATO x , List lista){
    Node* node = lista.first;
	for(MAX_LEN i = 1 ; i < lista.len + 1; i++){
        if(node->dato == x){
			return i;
		}
        node = node->next;
	}
	return -1;
}

void del(MAX_LEN index, List &lista){
    if (index<1 || index>lista.len){
        cout << "error: del: fuera de indice\n";
        return;
    }

	Node* aux = lista.first;
	if(index == 1){
		lista.first = aux->next;
        lista.len--;
	} else {
		Node* aux2 = lista.first;
		for(MAX_LEN i = 0 ; i < index - 2 ; i++){
			aux2 = aux2->next;
		}
		aux = aux2->next; // aux tiene todos los nodos adelante del que eliminamos
		aux2->next = aux->next;
        lista.len--;
	}
	aux->next = NULL;
	delete aux;
}

void remove(TIPODATO x, List &lista){
    MAX_LEN i = index(x, lista);
    if(i == -1){
        printf("error: remove: numero no encontrado\n");
        return;
    }
    del(i, lista);
}

void clear(List &lista){

    while(!empty(lista))
        del(1,lista);

}

void remove_all(TIPODATO x, List &lista){

    for(MAX_LEN i = index(x, lista); i != -1; i = index(x, lista)){
        del(i, lista);
    }

}

void bubbleSort(List &lista) {
    if (lista.len <= 1) // Si la lista está vacía o tiene un solo elemento, ya está ordenada
        return;

    bool swapped; // Variable para verificar si se realizó un intercambio en el paso actual

    Node *ptr; // Puntero auxiliar para recorrer la lista
    Node *lastSorted = NULL; // Puntero al último nodo ordenado

    do {
        swapped = false;
        ptr = lista.first;

        while (ptr->next != lastSorted) {
            if (ptr->dato > ptr->next->dato) {
                // Intercambiar los datos de los nodos
                TIPODATO temp = ptr->dato;
                ptr->dato = ptr->next->dato;
                ptr->next->dato = temp;

                swapped = true;
            }
            ptr = ptr->next;
        }
        lastSorted = ptr;
    } while (swapped);
}
