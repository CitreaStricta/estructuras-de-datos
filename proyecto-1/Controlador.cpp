#include "Controlador.h"
#include <ctype.h>
#include <time.h>
#include <fstream>
#include <random>
#include <stdexcept>
#include <string>
#include <utility>

Controlador::Controlador()
{
    predictor = new Predictor();
    dictFlag = 0;
    queriesFlag = 0;
}

Controlador::~Controlador()
{
    delete queries;
    delete predictor;
}

bool Controlador::fileExists(char* file_name)
{
    ifstream myfile(file_name);
    if (!myfile.is_open())
    {
        myfile.close();
        cout << "No se logro abrir " << file_name << endl;
        return false;
    }
    myfile.close();
    return true;
}

queue<string>* Controlador::loadFile(char* file_name)
{
    queue<string>* lines = new queue<string>();
    if (!fileExists(file_name))
        return lines;
    ifstream myfile(file_name);
    string line;
    /**
     * Lee cada linea del archivo y borra todo lo que haya desde el caracter '%'
     * hasta "npos" del string hasta que ya no haya mas lineas y las guarda dentro
     * de una queue de strings.
     **/
    while (getline(myfile, line)) // guarda cada linea del archivo dentro de un string
    { // si encuentra el caracter '%' y no es el final del string
        if (line.find('%') != line.npos)
            // elimina del string todo lo que haya desde el caracter '%' en adelante
            line.erase(line.find('%'));
        // guarda la string en la queue de strings
        lines->push(line);
    }
    myfile.close();
    return lines;
}

void Controlador::loadDictionary(char* file_name)
{
    queue<string>* dic = loadFile(file_name);
    if (!dic->empty())
        dictFlag = 1;
    else
    {
        delete dic;
        return;
    }
    
    int freq = 0;

    while (!dic->empty()) {
        freq = rand() % 1001;
        predictor->insert(dic->front(), freq);
        dic->pop();
    }

    delete dic;
}

void Controlador::loadQueries(char* file_name)
{
    queries = loadFile(file_name);
    if (!queries->empty())
        queriesFlag = 1;
}

void Controlador::writePredictions(char* file_name, char* m)
{
    if (dictFlag && queriesFlag) {
        queue<pair<string, int>>* prediction;
        int k_mostFrequent = stoi(m);
        ofstream respuesta(file_name);
        while (!queries->empty()) {
            prediction = this->predictor->predict(queries->front(), k_mostFrequent);
            respuesta << queries->front() << ": ";
            while (!prediction->empty()) {
                respuesta << prediction->front().first << " " << prediction->front().second << " ";
                predictor->augmentFrequency(prediction->front().first);
                prediction->pop();
            }        
            respuesta << endl;
            queries->pop();
            delete prediction;
        }
        respuesta.close();
    }
}