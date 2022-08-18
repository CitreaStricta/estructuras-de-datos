#include "Predictor.h"

Predictor::Predictor()
{
    trie = new TrieNode();
}

Predictor::~Predictor()
{
    delete trie;
}

void Predictor::insert(string s, int freq)
{
    this->trie->insert(s, freq);
}

bool Predictor::wordIsInTrie(string s)
{
    TrieNode* curNode = this->trie;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (curNode->accessChild(c) == nullptr)
            return false;
        else
            curNode = curNode->accessChild(c);
    }
    return curNode != nullptr && curNode->isEndOfWord();
}

queue<pair<string, int>>* Predictor::search(string root)
{
    // devolver todas las palabras que coindidan con "root"
    queue<pair<string, int>>* result = new queue<pair<string, int>>();
    TrieNode* curNode = this->trie;
    for (int i = 0; i < root.size(); i++)
    {
        char c = root[i];
        if (curNode->accessChild(c) != nullptr)
            curNode = curNode->accessChild(c);
        else
            return result;
    }

    searching(result, curNode, root);
    return result;
}

void Predictor::searching(queue<pair<string, int>>* resp, TrieNode* curNode, string root)
{
    if (curNode->isEndOfWord()) {
        resp->push(make_pair(root, curNode->getFrequency()));
    }
    for (int i = 0; i < 26; i++) {
        char c = char(i + 97);
        if (curNode->accessChild(c) == nullptr)
            continue;
        searching(resp, curNode->accessChild(c), root + c);
    }
}

// Este metodo Overload de "search" esta por si se quiere ignorar alguna letra en la recurcion
// Ej.: Busco "pal" y quiero buscar todas las palabras que inicien con "pal" exepto las palabras que siguen con "pala"
void Predictor::search(string root, queue<pair<string, int>>* resp, char ignore)
{
    TrieNode* curNode = this->trie;
    for (int i = 0; i < root.size(); i++) {
        char c = root[i];
        if (curNode->accessChild(c) != nullptr)
            curNode = curNode->accessChild(c);
        else
            return;
    }

    // De aqui en adelante es CASI IGUAL al metodo "searching" con la diferencia de que va a evitar entrar a "root + ignore"
    // Cuando encontrar letras distintas a "ignora" le sede el trabajo de la busqueda recursiva de las palabras al metodo "searching"
    if (curNode->isEndOfWord()) {
        resp->push(make_pair(root, curNode->getFrequency()));
    }

    for (int i = 0; i < 26; i++) {
        if (i != ignore - 97) {
            char c = char(i + 97);
            if (curNode->accessChild(c) == nullptr)
                continue;
            searching(resp, curNode->accessChild(c), root + c);
        }
    }
    return;
}

/**
 * Parametros:
 * Recive (y el felipito la masca con mayo y ketchup) como parametros el string "root", es decir, la cadena a predecir y un int que le informa al metodo
 * la cantidad de palabras que tiene que buscar que inicien con el "root" entregado.
 * Retorna el puntero de una Queue (queue que, en este metodo, se llama "prediction")
 * donde se encontraran las palabras predichas para el "root" entregado.
 * 
 * Funcionamiento:
 * Inicio utilizando el metodo "search" del controlador para buscar todas las palabras que empiecen con el "root" buscado
 * y las guardo en una Queue que llamaremos "preliminar" que usaremos para seleccionar las palabras con mayor frecuencia.
 * Ahora se pregunta "Es la cantidad de palabras en preliminar mayor o igual a la k cantidad de palabras que debo encontrar?"
 * 
 *  NO: entonces muevo todas las palabras en "preliminar" a la Queue "prediction" vaciando asi "preliminar".
 *      Ahora se tiene que encontrar una cantidad distinta de palabras. Cantidad dada por
 *      ["k_mostFrequent" - (cantidad de palabras resien agregadas a "prediction")].
 *      Y le quito a "root" su ultima letra (Ej.: Tenia el "root" "pala" y ahora tengo "pal").
 *      Vuelvo a usar el metodo "search" para llenar "preliminar". Pero esta vez utilizo una version de "search" que evita
 *      que la 1era letra ya sacada de "root" se encuentre (Ej.: "root" era "pala", ahora es "pal". Evito "pala").
 *      Vuelve a preguntar.
 * 
 *  SI: entonces busco entre ellas las con mayor frecuencia y una ves encontradas las guardo en "prediction".
 *
 * Retorno el puntero con la Queue "prediction".
**/
queue<pair<string, int>>* Predictor::predict(string root, int k_mostFrequent)
{
    // queue <pair> auxiliar para filtrar las respuestas
    //busco todas las palabras en el diccionario que empiecen con la cadena entregada
    queue<pair<string, int>>* prediction = new queue<pair<string, int>>();
    queue<pair<string, int>>* preliminar = this->search(root);

    while (k_mostFrequent)
    {// mientras que no se hayan encontrado todas las palabras que se
    // deber encontras (es decir, mientras que 'k' no sea 0)
        if (preliminar->size() >= k_mostFrequent)
        {// si la cantidad de palabras en "preliminar" es mayor o igual
        // a la cantidad de palabras que quiero encontrar
        // entonces encuentra las con mayor frequencia y guardalas en prediction
            pair<string, int> filtro[k_mostFrequent];
            filtro[0] = preliminar->front();
            preliminar->pop();
            int menorIndex = 0; // el index de la 1era palabra en "filtro"
            /**
             * Saco palabras de "preliminar" y las guardo en el arreglo "filtro"
             * guardando en "menorIndex" siempre el indice de la palabra con la menor
             * frecuencia
             */
            for (int i = 1; i < k_mostFrequent; i++) {
                if (filtro[menorIndex].second > preliminar->front().second) {
                    menorIndex = i;
                }
                filtro[i] = preliminar->front();
                preliminar->pop();
            }
            /**
             * Ahora que "filtro" esta lleno
             * puedo empezar a sacar palabras de este si es que en "preliminar"
             * encuentro alguna palabra que tenga una mayor frecuencia
             * que la palabra con menor frecuencia en "filtro"
             */
            while (!preliminar->empty()) {
                if (filtro[menorIndex].second >= preliminar->front().second) {
                    preliminar->pop();
                    continue;
                }
                // si llega aqui entonces el que recien llego es mayor al mas chico por
                // lo tanto tengo que cambiar el mas chico por este nuevo mas grande.
                filtro[menorIndex] = preliminar->front();
                preliminar->pop();
                // Ahora tengo que buscar el nuevo mas chico
                for (int i = 0; i < k_mostFrequent; i++) {
                    if (filtro[menorIndex].second > filtro[i].second) {
                        menorIndex = i;
                    }
                }
            }
            for (int i = 0; i < k_mostFrequent; i++) {
                prediction->push(filtro[i]);
            }
            k_mostFrequent = 0;
        }
        else
        {// en caso de que no haya las suficientes palabras
        // guarda las que hayas podido encontrar y disminuye k en 1 por cada
        // palabra encontrada
            while (!preliminar->empty())
            {
                prediction->push(preliminar->front());
                preliminar->pop();
                k_mostFrequent--;
            }
            if(root.length() == 1) break;
            char ignore = root.at(root.length() - 1);
            root.pop_back(); // y busca el mismo string a predecir pero sin la ultima
                // letra (ej.: si la palabra es "pala" busca "pal")
            this->search(root, preliminar, ignore);
        }
    }
    delete preliminar;
    return prediction;
}

TrieNode* Predictor::searchWord(string s)
{// devuelve un puntero a la ultima letra del string 's'
    TrieNode* curNode = this->trie;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (curNode->accessChild(c) != nullptr) 
            curNode = curNode->accessChild(c);
        else
        {
            cout << "Word wasn't found" << endl;
            return nullptr;
        }
    }
    return curNode;
}

void Predictor::augmentFrequency(string s)
{
    TrieNode* p = searchWord(s);
    if(p != nullptr) p->augmentFrequency();
}