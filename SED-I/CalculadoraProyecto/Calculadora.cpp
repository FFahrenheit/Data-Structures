#define _GLIBCXX_USE_C99 1

#include <iostream>
#include <string>

using namespace std;

enum Opciones
{
    OPC_SUMA = 1,
    OPC_RESTA,
    OPC_MULTIPLICACION,
    OPC_DIVISION,
    OPC_POTENCIA,
    OPC_FACTORIAL,
    OPC_DEC_BIN,
    OPC_BIN_DEC,
    OPC_DEC_OCT,
    OPC_OCT_DEC,
    OPC_DEC_HEX,
    OPC_HEX_DEC,
    OPC_SALIR
};

void menu();
bool isInteger(string);
int toInteger(string);

float * ptr1, *ptr2 = NULL, a, b;


int main()
{

}

void menu()
{
    int opc = 0;
    string input;
    do
    {
        cout << "\n\n\t\tMENU\n";
        cout << OPC_SUMA << ") Suma" << endl;
        cout << OPC_RESTA << ") Resta" << endl;
        cout << OPC_MULTIPLICACION << ") Multiplicacion" << endl;
        cout << OPC_DIVISION << ") Division" << endl;
        cout << OPC_POTENCIA << ") Potencia" << endl;
        cout << OPC_FACTORIAL << ") Factorial" << endl;
        cout << OPC_DEC_BIN << ") Decimal a binario" << endl;
        cout << OPC_BIN_DEC << ") Binario a decimal" << endl;
        cout << OPC_DEC_OCT << ") Decimal a octal" << endl;
        cout << OPC_OCT_DEC << ") Octal a decimal" << endl;
        cout << OPC_DEC_HEX << ") Decimal a hexadecimal" << endl;
        cout << OPC_HEX_DEC << ") Hexadecimal a Decimal" << endl;
        cout << OPC_SALIR << ") Salir" << endl;
        cout << "Su opcion: ";
        getline(cin,input);
        if(isInteger(input))
        {
            opc = toInteger(input);
            cout << opc << endl;
        }
        else 
        {
            cout << "Ingrese una opcion valida" << endl;
        }
    }while(opc!=OPC_SALIR);
}

bool isInteger(string s)
{
    if(s.at(0)=='-')
    {
        return !s.empty() && all_of(s.begin()+1, s.end(), ::isdigit); //Todo sea digito
    }
    else 
    {
        return !s.empty() && all_of(s.begin()+1, s.end(), ::isdigit); //Todo sea digito
    }
}

int toInteger(string number)
{
    return std::stoi(number);
}