#include <bits/stdc++.h>
#include "StacksQueue.h"
using namespace std;

int main() {

    srand(time(NULL));
    StacksQueue *q1 = new StacksQueue();
    queue<int> q2;

    int n = 100;
    for(int i=0;i<n;i++){
        int num = rand()%100000;
        q1->push(num);
        q2.push(num);
    }
    
    cout << "Comprobar elementos dentro usando iterador: "<< endl;
    Iterador it = q1->begin();
	while(it.hasNext()) {
		cout << it.next() << endl;
	}

    bool correcto = true;
    cout << "Comprobar front a medida que se sacan:" << endl;
    for(int i = 0; i < n; i++){
         cout << "StackQ: "<< q1->front() << " STLQ: "<< q2.front() << endl;
         if(q1->front() != q2.front()) correcto = false;
         q1->pop();
         q2.pop();
    }
    if(correcto) cout << "Resultados correctos" << endl;
    else cout << "Resultados incorrectos" << endl;


    return 0;
}