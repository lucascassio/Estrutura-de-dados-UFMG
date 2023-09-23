#include "../include/exp.h"
#include "../include/pilhaEncadeada.h"
#include "../include/arvoreBinaria.h"
#include <string>

using namespace std;

int main(int argc, char **argv) {
    if (argc < 4) {
        cout << "Argumentos invalidos !!!";
        return 1;
    }

    string problem = argv[1];
    string logicExpression = argv[2];
    string values = argv[3];

    cout << logicExpression << endl;

    if(problem == "-a") {
        logicExpRes(logicExpression, values);
    } else if(problem == "-s") {
        satisfabilityRes(logicExpression, values);
    }

    return 0;
}
