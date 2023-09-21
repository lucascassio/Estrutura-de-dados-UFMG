#include "../include/exp.h"
#include <string>

using namespace std;

void assignValues(string logicExpression, string values) {
    int parametros;
    int tamanho = values.size();

    while(logicExpression[i] != logicExpression.size()) {
        if(logicExpression[i] != "~" && logicExpression[i] != " " && logicExpression[i] != "|" && logicExpression[i] != "&") {
            logicExpression[i] = values[0];
        }
        i++;
        values[tamanho - 1]
    }
}

int logicExpRes(string logicExpression, string values) {

}

void satisfabilityRes();
