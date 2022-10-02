//libreria
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <cstdlib>

// para no usar el std::cout<< sino directamente el cout<<
using namespace std;

//asignar nuevo nodo
struct Nodo{
    int dato;
    Nodo *siguiente;
};

//prototipo de funcion insertar
void insertarlista(Nodo *&, int); //* & cuando queremos asignar un nuevo valor  a la lista 
//prototipo de funcion mostrar
void mostrarlista(Nodo *, int);
//prototipo de funcion menu
void menu();
//prototipo de funcion buscar
void buscarlista(Nodo *,int);
//prototipo de funcion eliminar
void eliminarlista(Nodo *&,int);
//prototipo de funcion promedio par
void promedioparlista(Nodo *);
//prototipo de funcion promedio impar
void promedioimparlista(Nodo *);
//prototipo de funcion mostrar mayor
void mayorlista(Nodo *);
//prototipo de funcion mostar menor
void menorlista(Nodo *);
//prototipo de funcion eliminar duplicado
void duplicadolista(Nodo *&, int);

Nodo *lista = NULL;
//----------------------------------------------------------------------------------------
//creacion de un nuevo nodo insertar lista 
void insertarlista(Nodo *&lista, int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo ->dato = n;

    //creacion de nodos auxiliares
    Nodo *aux1 = lista;
    Nodo *aux2;

    //while para que la lista este ordenada 
    while ((aux1 != NULL)&&(aux1->dato <n)){
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }

    //condicional para saber si se inserta al principio o al final
    if(lista == aux1){
        lista = nuevo_nodo;
    }else{
        aux2->siguiente= nuevo_nodo;
    }
    nuevo_nodo->siguiente = aux1;
}
//----------------------------------------------------------------------------------------
//creacion de un nuevo nodo mostrar lista 
void mostrarlista(Nodo *lista){
    Nodo *actual = new Nodo();
    //señala a la lista
    actual = lista;

    while (actual !=NULL){
        cout<<actual ->dato <<"->";
        actual = actual->siguiente;
    } 
}

//----------------------------------------------------------------------------------------
//creacion de un nuevo nodo buscar lista 
void buscarlista(Nodo *lista, int buscar){
    bool band = false;
    //nuevo nodo
    Nodo * actual = new Nodo();
    //señala a la lista 1 posision
    actual = lista;

    //recorre la lista
    while ((actual != NULL)&&(actual ->dato <= buscar)){
        if (actual ->dato == buscar){
            band = true;
        }
        actual = actual ->siguiente;
    }
    if (band == true){
        cout<<"El ELEMENTO: " <<buscar <<" SI SE ENCUENTRA" <<endl;
    }else{
        cout<<"El ELEMENTO: " <<buscar <<" NO SE ENCUENTRA" <<endl;
    }   
}

//----------------------------------------------------------------------------------------
//creacion de un nuevo nodo eliminar lista 
void eliminarlista(Nodo *&lista,int borrar){
    //preguntamos si la lista esta vacia
    if (lista != NULL){
        Nodo *aux_Borrar;
        Nodo *anterior = NULL;

        aux_Borrar = lista;
        //recorrer la lista
        while ((aux_Borrar != NULL)&&(aux_Borrar->dato !=borrar)){
            anterior = aux_Borrar;
            aux_Borrar = aux_Borrar->siguiente;
        }
        //cuando el elemento no se encuentra
        if (aux_Borrar == NULL){
            cout<<"El elemento no existe en la lista";
        }
        //elimenar el primer elemento 
        else if(anterior == NULL){
            lista == lista->siguiente;
            delete aux_Borrar;
        }
        //cuando no el es primer elemento a eliminar
        else{
            anterior->siguiente = aux_Borrar->siguiente;
            delete aux_Borrar;
        }
    }
}
//----------------------------------------------------------------------------------------
//creacion de un nuevo nodo promedio par lista

//----------------------------------------------------------------------------------------
//creacion de un nuevo nodo menor lista
void menorlista(Nodo *lista){
    int menor = 99999;
    while (lista != NULL){
        if ((lista -> dato) <menor){
            menor = lista -> dato;
        }
        lista = lista ->siguiente;
    }
    cout<<menor;
}
//----------------------------------------------------------------------------------------
//creacion de un nuevo nodo mayor lista
void mayorlista(Nodo *lista){
    int mayor = 0;
    while(lista != NULL){
        if((lista -> dato) > mayor){
            mayor = lista -> dato;
        }
        lista = lista ->siguiente;
    }
    cout<<mayor;
}
//----------------------------------------------------------------------------------------
//creacion de un nuevo nodo eliminar duplicado lista
void duplicadolista(Nodo *lista,int n){
    Nodo *aux = lista;
    n = aux ->dato;
    lista = aux -> siguiente;
    delete aux;
    
}
//----------------------------------------------------------------------------------------
//creacion de nodo menu 
void menu(){
    int cont,i,dato,cant;

    do{
        cout<<"\n\t\tLISTA ENLAZADA \n\n";
        cout<<" 1. INSERTAR AL INICIO               "<<endl;
        cout<<" 2. MOSTRAR ELEMENTOS DE LA LISTA    "<<endl;
        cout<<" 3. BUSCAR ELEMENTO EN LA LISTA      "<<endl;
        cout<<" 4. ELIMINAR ELEMENTO DE LA LISTA    "<<endl;
        cout<<" 5. CALCULAR PROMEDIO PARES          "<<endl;
        cout<<" 6. CALCULAR PROMEDIO IMPARES        "<<endl;
        cout<<" 7. CALCULAR MENOR NUMERO            "<<endl;
        cout<<" 8. CALCULAR MAYOR NUMERO            "<<endl;
        cout<<" 9. MOSTRAR ELEMENTO REPETIDO        "<<endl;
        cout<<" 10. ELEIMINAR ELEMENTO REPETIDO     "<<endl;
        cout<<" 11. SALIR                           "<<endl;

        cout<<"\n INGRESE EL NUMERO DE LA ACCION QUE DESEAS REALIZAR: "; cin>>cont;

        switch (cont){
            case 1:
                cout<<"\n CUANTOS NUMERO QUIERES INGRESAR A LA LISTA: "; cin>>cant;
                //contador para la lista
                    for (i = 1; i <= cant; i++){
                        cout<<"\n"<<i <<") NUMERO A INSERTAR : "; cin>> dato;
                        insertarlista(lista, dato);
                        cout<<"\n";
                    }
                break;
            
            case 2:
                //mostramos la lista 
                cout<<"\n LOS ELEMENTO DE LA LISTA SON: \n" <<endl;
                mostrarlista(lista);
                cout<<"\n";
                break;
                
          
            case 3:
                //buscar un elemento en la lista 
                cout<<"\n QUE ELEMENTO DESEAS BUSCAR: "; cin>>dato;
                buscarlista(lista,dato);
                cout<<"\n";
                break;

            case 4:
                // eliminar elemrnto de la lista
                cout<<"\n QUE ELEMENTO DECEAS ELIMINAR: "; cin>>dato;
                eliminarlista(lista,dato);
                cout<<"\n";
                break;

            case 7:
                //calcular menor elemento de la lista
                cout<<"\nEL MENOR ELEMENTO DE LA LISTA ES: ";
                menorlista(lista);
                cout<<"\n";
                break;
                
            case 8:
                //calcular mayor elemento de la lista
                cout<<"\nEL MAYOR ELEMENTO DE LA LISTA ES: ";
                mayorlista(lista);
                cout<<"\n";
                break;
            
            case 10:
                //eliminar elementos repetidos
                cout<<"\nLOS ELEMENTOS SE ELIMINARON CORRECTAMENTE ";
                duplicadolista(lista, dato);
                cout<<"\n";
                break;
        }
    } while (cont != 11);
}

//insertar elementos a la lista 
int main(){

    menu();
    return 0;
}   