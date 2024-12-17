
#include "Busqueda.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

Busqueda::Busqueda(int n) {
	this->vec = new int[n];

	srand(time(NULL));

	for(int i=0;i<n;i++) {
		this->vec[i] = rand() % n + 1;
	}
	this->tam = n;
	 sort(this->vec,this->vec + this->tam);

	// for(int i=0;i<this->tam;i++) cout<<this->vec[i]<<" ";
	// puts("");
}

Busqueda::~Busqueda(){
	delete[] this->vec;
}
int Busqueda::size(){
	return this->tam;
}

int Busqueda::lineal(int num){
/*
Input: un numero entero "num" y un arreglo "vec" de 'n' numeros enteros
Output: El index del arreglo "vec" donde el numero entero "num" se encuentra
o '-1' si el numero no se encuentra en el arreglo
//									Analisis Big-Oh
*/
	//for i <- 0 to tam - 1 do            n
	for(int i = 0; i < this->tam; i++)
		//if vec[i] = num then            n
		if(this->vec[i] == num)
			//return i                    1
			return i;
	//return -1                           1
	return -1;
}//                                      O(n)

int Busqueda::binariaRecursiva(int num,int l,int r){
	if(r<l) return -1;

	int mid = floor((l+r)/2);

	if(vec[mid] == num) return mid;

	if(num < vec[mid])
		return binariaRecursiva(num, l, mid - 1);
	return binariaRecursiva(num, mid + 1, r);
}

int Busqueda::binariaIterativa(int num){
/*
Input: un numero entero "num" y un arreglo "vec" de 'n' numeros enteros
Output: El index del arreglo "vec" donde el numero entero "num" se encuentra
o '-1' si el numero no se encuentra en el arreglo
//									Analisis Big-Oh
primero <- 0                              1
medio <- 0                                1
ultimo <- tam-1                           2
while primero <= ultimo do              log(n)
	medio <- (primero + ultimo)/2       log(n)
	if num = vec[medio] then            log(n)
		return medio                      1
	if vec[medio] > num then            log(n)
		ultimo <- medio-1               log(n)
	else
		primero <- medio+1              log(n)
return -1                                 1
*/
    int primero = 0;
    int medio = 0;
    int ultimo = tam - 1;

    while(primero <= ultimo){
        medio = (primero + ultimo) / 2;

        if(num == vec[medio])
			return medio;

		if(vec[medio] > num)
			ultimo = medio - 1;
		else																	
			primero = medio + 1;
    }
    return -1;
}

int Busqueda::binariaRecursiva(int num){
	return binariaRecursiva(num,0,tam-1);
}