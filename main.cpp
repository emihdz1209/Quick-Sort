//Quicksort
//Es un algoritmo de ordenamiento muy eficiente que se basa en la técnica de divide y vencerás, 
//y que es muy utilizado en la práctica. Su tiempo de ejecución en el caso promedio es O(n log n), y en el peor caso es O(n²). 
//A pesar de esto, en la práctica suele ser más rápido que otros algoritmos de ordenamiento como el mergesort o el heapsort.

#include <iostream>
#include <vector>
using namespace std;

void quicksort(vector<int> &vec, int n){

    if(n<=1){return;} //Caso base

    int pivot = vec[n/2]; //Se elige el pivote como el elemento en la mitad del vector
    vector<int> left_vec; //Vector izquierdo
    vector<int> right_vec; //Vector derecho

    for(int i=0; i<n; i++){ //Se recorre el vector original
        if(i != n/2){ //Si el indice no es el del pivote
            if(vec[i] < pivot){ //Si el elemento es menor al pivote
                left_vec.push_back(vec[i]); //Se agrega al vector izquierdo
            }
            else{ //Si el elemento es mayor al pivote
                right_vec.push_back(vec[i]); //Se agrega al vector derecho
            }
        }
    }

    quicksort(left_vec, left_vec.size()); //Se ordena el vector izquierdo
    quicksort(right_vec, right_vec.size()); //Se ordena el vector derecho

    int i=0; //indice para recorrer el vector original
    for(int l:left_vec){ //Se recorre el vector izquierdo
        vec[i] = l; //Se asigna el elemento del vector izquierdo al vector original
        i++; //Se incrementa el indice del vector original
    }

    vec[i] = pivot; //Se asigna el pivote al vector original
    i++; //Se incrementa el indice del vector original

    for(int r:right_vec){ //Se recorre el vector derecho
        vec[i] = r; //Se asigna el elemento del vector derecho al vector original
        i++; //Se incrementa el indice del vector original
    }
}

main(){

    vector<int> vec = {1, 5, 3, 2, 4, 8, 6, 7};

    cout << endl << endl << "Vector desordenado: ";
    for(int i:vec){
        cout << i << ", ";
    }

    quicksort(vec, (vec.size()-1));

    cout << endl << endl << "Vector ya ordenado: ";
    for(int i:vec){
        cout << i << ", ";
    }

    cout << endl << endl;

    return 0;
}