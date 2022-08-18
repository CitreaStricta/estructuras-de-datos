#include <iostream>
#include <string>
#include <time.h>
#include "Predictor.h"

using namespace std;

class Controlador
{
private:
    int dictFlag, queriesFlag;
    queue<string> *queries;
    Predictor* predictor;
    bool fileExists(char *file_name);
    queue<string>* loadFile(char *file_name);
public:
    Controlador();
    ~Controlador();
    void loadQueries(char* file_name);    
    void loadDictionary(char *file_name);        
    void writePredictions(char *file_name, char* m);
};