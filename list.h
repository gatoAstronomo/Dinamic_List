#include "list_struct.h"


bool empty(List lista);                                // Devuelve 1 si esta vacia, 0 si no lo esta
MAX_LEN len(List lista);                               // Devuelve el largo de la lista, si esta vacia devuelve 0
void next_node(Node* &node);                             // Transforma el nodo al siguiente nodo
void inserta(MAX_LEN index, TIPODATO x,  List &lista); // Inserta en la posicion index el dato x
void append(TIPODATO x, List &lista);                  // Inserta x alfinal de la lista
void print(List lista);                                // Imprime la lista, mientras i < lista.len
void printv2(List lista);                              // Imprime la lista, mientras node != NULL
TIPODATO recupera(MAX_LEN index, List lista);          // Devuelve el dato de la posicion index
MAX_LEN index(TIPODATO x , List lista);                // Devuelve la posicion de un dato x determinado, si no existe devuelve -1
void del(MAX_LEN index, List &lista);                  // Elimina un elemento de la lista segun su index
void remove(TIPODATO x,List &lista);                   // Elimina el primer x que se encuentre
void clear(List &lista);                               // Elimina todos los elementos de una lista
void remove_all(TIPODATO x, List &lista);              // Elimina todos los x que se encuentren
void bubbleSort(List &lista);                          // Ordena de menor a mayor toda la lista

