#ifndef EXP_H
#define EXP_H

#include <iostream>
#include <string>

using namespace std;

void assignValues(string logicExpression, string values);
int logicExpRes(string logicExpression, string values);
int satisfabilityRes(string logicExpression, string values);

#endif

