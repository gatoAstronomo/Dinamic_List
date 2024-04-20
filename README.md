Lista dinamica
==============
Compilación
-------
Para compilar simplemente nos posicionamos en la carpeta principal y ejecutamos en la consola
```bash
make
```
Configuración
-------
### Directivas del preprocesador
En el archivo list_struct.h encontraremos las siguientes lineas
```cpp
#define TIPODATO long
#define MAX_LEN unsigned long
```
- TIPODATO será el tipo de dato numerico que guardaremos en nuestra lista.
- MAX_LEN es el largo máximo que podra alcanzar la lista dinamico aunque esto casi nunca ocurrira ya que es bastante probable que se nos acabe la memoria antes.

Podemos cambiar estas definiciones según nuestras necesidades por ejemplo si necesitaramos guardar `short` y estamos seguros que nuestra lista no tendra un largo mayor a `INT_MAX = 2¹⁶ - 1` remplazamos:
```cpp
#define TIPODATO short
#define MAX_LEN int
```
y ya estaria.

Uso
-------

```cpp
#include <cstdio>
#include "list.h"

int main(){
    // Instanciamos la lista
    List lista;
    // Agregamos un 10,12 y 14 e imprimimos
    append(10, lista);
    append(12, lista);
    append(14, lista);
    print(lista); // -> [10, 12, 14]
    
    // Busca el indice del elemento 12
    index(12, lista); // -> 1

    del(2, lista); // Elimina el elemento de la posición 2
    print(lista); // -> [10, 14]
    
    // Imprimimos el largo
    printf("%d",len(lista)); // -> 2

    return 0;
}
```

Estas son las demás funciones
```cpp
bool empty(List lista);  // Devuelve 1 si esta vacia, 0 si no lo esta
MAX_LEN len(List lista);  // Devuelve el largo de la lista, si esta vacia devuelve 0
void next_node(Node* &node);  // Transforma el nodo al siguiente nodo
void inserta(MAX_LEN index, TIPODATO x,  List &lista);  // Inserta en la posicion index el dato x
void append(TIPODATO x, List &lista);  // Inserta x alfinal de la lista
void print(List lista);  // Imprime la lista, mientras i < lista.len
void printv2(List lista);  // Imprime la lista, mientras node != NULL
TIPODATO recupera(MAX_LEN index, List lista);  // Devuelve el dato de la posicion index
MAX_LEN index(TIPODATO x , List lista);  // Devuelve la posicion de un dato x determinado, si no existe devuelve -1
void del(MAX_LEN index, List &lista);  // Elimina un elemento de la lista segun su index
void remove(TIPODATO x,List &lista);  // Elimina el primer x que se encuentre
void clear(List &lista);  // Elimina todos los elementos de una lista
void remove_all(TIPODATO x, List &lista)  // Elimina todos los x que se encuentren
void bubbleSort(List &lista); // Ocupa el algoritmo bubblesort para ordenar la lista menor a mayor
```