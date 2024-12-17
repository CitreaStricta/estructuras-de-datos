#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <random>
#include <time.h>
#include <iomanip>


using namespace std;

void printeoDeIndices(int *indices, int *respuestas,int q){
    for(int i = 0; i < q; i++)
        cout <<"Indice " << indices[i] << ": "<< respuestas[indices[i]] << endl;
}

void printArray(int *arr, int n){
    for (int i = 0; i < n; i++)
        cout << arr[i]<<endl;
}

// Esto no es nada. Ignoralo (me dio penita borrarlo)
void solucionUno2(int *vec, int n, int *q, int Q, int *resp){
    for(int i = 0; i < Q; i++){
        int aux = q[i] + 1;
        while(((aux < n) && vec[q[i]] >= vec[aux])){
            aux++;
        }
        if(aux == n){
            resp[i] = -1;
        }
        else{
            resp[i] = vec[aux];   
        }
    }
}

void solucionUno(int *vec, int n, int *resp){
    for(int i = 0; i < n; i++){
        int aux = i + 1;
        while(((aux < n) && vec[i] >= vec[aux])){
            aux++;
        }
        if(aux == n){
            resp[i] = -1;
        }
        else{
            resp[i] = vec[aux];
        }
    }
}

void solucionDos(int *vec, int n, int *resp){
    stack<int> h;
    h.push(0);
    for (int i = 1; i < n; i++){
        while(!h.empty() && vec[i] > vec[h.top()]){
            resp[h.top()] = vec[i];
            h.pop();
        }
        h.push(i);
    }

    while(!h.empty()){
        resp[h.top()] = -1;
        h.pop();
    }
}

int main(){
    srand (time(NULL));
    const int n = 14000;
    int q;
    int vec[n];

    cout << "Cuantos indices quieres buscar?" << endl;
    cin >> q;

    auto ab = q;

    int* indices = new int[ab];
    cout << "Que indices quieres buscar?\nRango: 0 a " << (999) << endl;
    for(int i = 0; i < q; i++)
        cin>>indices[i];

    for(int i = 0; i < n; i++)
        vec[i] = rand() % 999;
    
    // cout << rand() % 999 << endl;


    int respuestas[n];
    int respuestas2[n];

    double time;
    int rep = 3;
    clock_t start;

    cout <<"Con n igual a " << n << endl << endl;
    cout << "Desorden" << endl;
    start = clock();
    for(int i=0; i<rep; i++) solucionUno(vec, n, respuestas);
    time = ((double)clock() - (double)start) / CLOCKS_PER_SEC;
    cout << "Sol.1: " << fixed << setprecision(10) << time/((double)(rep*n)) << endl;

    start = clock();
    for(int i=0; i<rep; i++) solucionDos(vec, n, respuestas2);
    time = ((double)clock() - (double)start) / CLOCKS_PER_SEC;
    cout << "Sol.2: " << fixed << setprecision(10) << time/((double)(rep*n)) << endl;

    // printeoDeIndices(indices, respuestas, q);


    cout << endl;
    cout << "Orden Creciente" << endl;
    sort(vec, vec + n);                 // sort creciente

    start = clock();
    for(int i=0; i<rep; i++) solucionUno(vec, n, respuestas);
    time = ((double)clock() - (double)start) / CLOCKS_PER_SEC;
    cout << "Sol.1: " << fixed << setprecision(10) << time/((double)(rep*n)) << endl;

    start = clock();
    for(int i=0; i<rep; i++) solucionDos(vec, n, respuestas2);
    time = ((double)clock() - (double)start) / CLOCKS_PER_SEC;
    cout << "Sol.2: " << fixed << setprecision(10) << time/((double)(rep*n)) << endl;

    // printeoDeIndices(indices, respuestas, q);


    cout << endl;
    cout << "Orden Decreciente" << endl;
    sort(vec, vec + n, greater<int>()); // sort decreciente

    start = clock();
    for(int i=0; i<rep; i++) solucionUno(vec, n, respuestas);
    time = ((double)clock() - (double)start) / CLOCKS_PER_SEC;
    cout << "Sol.1: "  << fixed << setprecision(10) << time/((double)(rep*n)) << endl;

    start = clock();
    for(int i=0; i<rep; i++) solucionDos(vec, n, respuestas2);
    time = ((double)clock() - (double)start) / CLOCKS_PER_SEC;
    cout << "Sol.2: "  << fixed << setprecision(10) << time/((double)(rep*n)) << endl << endl;

    // printeoDeIndices(indices, respuestas, q);


    delete[] indices;
    return 0;
}