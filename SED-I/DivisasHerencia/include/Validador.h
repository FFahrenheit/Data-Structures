#ifndef VALIDADOR_H
#define VALIDADOR_H

#include <iostream>
#include <string.h>
using namespace std;

class Validador
{
    public:
        bool isInteger(string);
        int toInteger(string);
        bool isFloat(string);
        float toFloat(string);
        int requestInt(string);
        float requestFloat(string);
};

#endif // VALIDADOR_H
