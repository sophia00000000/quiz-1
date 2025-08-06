#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
#define LIMITE 3 //Límite de la cola


struct nodo{
    char info[30];
    struct nodo *sig;
};
// apunta al principio de la lista y final. Dos punteros para q al insertar un nodo al final no tengamos que recorrer la lista.
struct nodo *primero=NULL;
struct nodo *ultimo=NULL;
int cantidad=0; //cantidad de elementos en la cola

int vacia(){
    if (primero == NULL)
        return 1;
    else
        return 0;
}


void insertar(char *x){
    if (cantidad >= LIMITE) {
        printf("La cola está llena, No se pueden agregar más clientes. \n");
        return;
    }
    struct nodo *nuevo;
    nuevo=malloc(sizeof(struct nodo));
    strcpy(nuevo->info, x);
    nuevo->sig=NULL;
    if (vacia()){
        primero = nuevo;
        ultimo = nuevo;
    }//si hay nodes en la lista, el nuevo nodo se inserta al final.
    else{
        ultimo->sig = nuevo;
        ultimo = nuevo;
    }
    cantidad++;
}

char* extraer(){
    static char nombreExtraido[30];
    if (!vacia()){
        strcpy(nombreExtraido, primero->info);
        struct nodo *bor = primero;
        if (primero == ultimo){
            primero = NULL;
            ultimo = NULL;
        }
        else{
            primero = primero->sig;
        }
        free(bor);
        cantidad--;
        return nombreExtraido;
    }
    else
        return ("cola está vacía, no se puede extraer ");
}

void imprimir(){
    struct nodo *reco = primero;
    printf("Fila:\n");
    while (reco != NULL){
        printf(" - %s\n", reco->info);
        reco = reco->sig;
    }
    printf("\n");
}


int main(){
    insertar("ana");
    insertar("pedro");
    insertar("sophia");
    imprimir();
    insertar("luis"); 
    imprimir();
    printf("Extraemos uno de la cola: %s\n", extraer());
    imprimir();
    return 0;
}