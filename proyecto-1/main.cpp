#include "Controlador.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    srand(time(NULL));
    Controlador* cont = new Controlador();
    char* dic = argv[1];
    char* archivoQueries = argv[2];
    char* archivoRespuestas = argv[3];
    char* k_most_frequent = argv[4];
    cont->loadDictionary(dic);
    cont->loadQueries(archivoQueries);
    cont->writePredictions(archivoRespuestas, k_most_frequent);
    delete cont;
}
