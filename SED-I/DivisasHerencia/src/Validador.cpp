#include "Validador.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <sstream>

bool Validador::isInteger(string s)
{
    if(s.empty())
    {
        return false;
    }
    if(s.at(0)=='-')
    {
        return !s.empty() && all_of(s.begin()+1, s.end(), ::isdigit); //Todo sea digito
    }
    else
    {
        return !s.empty() && all_of(s.begin()+1, s.end(), ::isdigit);
    }
}

int Validador::toInteger(string const number)
{
    return std::stoi(number);
}

bool Validador::isFloat(string s)
{
    std::istringstream iss(s);
    float f;
    iss >> noskipws >> f;
    return iss.eof() && !iss.fail();
}

float Validador::toFloat(string const number)
{
    return std::stof(number);
}

int Validador::requestInt(string const message)
{
    string input;
    do
    {
        cout << message;
        getline(cin,input);
        if(!isInteger(input))
        {
            cout << "Ingrese una entrada valida" << endl;
        }
    }while(!isInteger(input));
    return toInteger(input);
}
float Validador::requestFloat(string const message)
{
    string input;
    do
    {
        cout << message;
        getline(cin,input);
        if(!isFloat(input))
        {
            cout << "Ingrese una entrada valida" << endl;
        }
    }while(!isFloat(input));
    return toFloat(input);
}
