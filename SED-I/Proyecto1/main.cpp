#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <sstream>

/*
    Proyecto de Ismael Ivan Lopez Murillo
    SEDA 01
    Por favor, compilar usando C++11 o mas actual.
*/

using namespace std;

//Opciones
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

//Funciones auxiliares
void menu();
bool isInteger(string);
int toInteger(string);
bool isFloat(string);
float toFloat(string);
int requestInt(string);
float requestFloat(string);
char getHex(int);

//Funciones extra de la calculadora con punteros
float * potencia(float *, int*);
float *factorial(int*);
long *decToBin(int *);
int *binToDec(int *);
int *decToOct(int *);
int *octToDec(int *);
int *hexToDec(char *);
char * decToHex(int *);
bool isBinary(string const&);
bool isHex(string const&);
bool isOctal(string const&);
int getHexValue(char);

//Clase para operaciones de dos miembros
class Calculadora
{
    private:
        float numero1;
        float numero2;
        float resultado;
    public:
        float getNumero1() const;
        float getNumero2() const;
        float getResultado() const;
        void setNumero1(float);
        void setNumero2(float);
        void operacion(char);
};

float Calculadora::getNumero1() const {
    return numero1;
}

void Calculadora::setNumero1(float numero1) {
    Calculadora::numero1 = numero1;
}

float Calculadora:: getNumero2() const {
    return numero2;
}

void Calculadora::setNumero2(float numero2) {
    Calculadora::numero2 = numero2;
}

float Calculadora::getResultado() const {
    return resultado;
}

void Calculadora::operacion(char oprtr)
{
    switch(oprtr)
    {
        case '+':
            this->resultado = numero1 + numero2;
            break;
        case '-':
            this->resultado = numero1 - numero2;
            break;
        case '*':
            this->resultado = numero1 * numero2;
            break;
        case '/':
            if(this->numero2 != 0)
            {
                this->resultado = numero1 / numero2;
            }
            else
            {
                this->resultado = 0;
            }
            break;
        default:
            this->resultado = 0;
            break;
    }
}

float floatA, floatB;
int intA, *ptrIntA;

Calculadora calculadora;

int main()
{
    menu();
    cout << "Gracias por usar este proyecto" << endl;
    cout << "-Ismael Ivan Lopez Murillo" << endl;
    system("pause");
    system("cls");
}

void menu()
{
    int opc = 0;
    string input;
    do
    {
        system("cls");
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
            if(opc>=OPC_SUMA && opc<=OPC_DIVISION)
            {
                floatA = requestFloat("Ingrese el primer numero: ");
                floatB = requestFloat("Ingrese el segundo numero: ");
                calculadora.setNumero1(floatA);
                calculadora.setNumero2(floatB);
            }
            switch(opc)
            {
                case OPC_SUMA:
                    calculadora.operacion('+');
                    cout << "El resultado es " << calculadora.getResultado() << endl;
                    break;
                case OPC_RESTA:
                    calculadora.operacion('-');
                    cout << "El resultado es " << calculadora.getResultado() << endl;
                    break;
                case OPC_MULTIPLICACION:
                    calculadora.operacion('*');
                    cout << "El resultado es " << calculadora.getResultado() << endl;
                    break;
                case OPC_DIVISION:
                    calculadora.operacion('/');
                    cout << "El resultado es " << calculadora.getResultado() << endl;
                    break;
                case OPC_POTENCIA:
                    floatA = requestFloat("Ingrese la base: ");
                    intA = requestInt("Ingrese la potencia: ");
                    cout << "El resultado es: " << * potencia(&floatA, &intA) << endl;
                    break;
                case OPC_FACTORIAL:
                    intA = requestInt("Ingrese el numero a obtener factorial: ");
                    if(intA<0)
                    {
                        cout << "El factorial solo sirve con numeros positivos"<<endl;
                    }
                    else
                    {
                        cout << "El resultado es: " << * factorial(&intA) << endl;
                    }
                    break;
                case OPC_DEC_BIN:
                    intA = requestInt("Ingrese entero a convertir a binario: ");
                    if(intA>=0)
                    {
                        cout << "Binario: " << *decToBin(&intA) << endl;
                    }
                    else
                    {
                        cout << "Por el momento no se pueden convertir numeros negativos" << endl;
                    }
                    break;
                case OPC_BIN_DEC:
                    cout << "Ingrese el numero binario a obtener valor decimal: ";
                    getline(cin,input);
                    if(isBinary(input))
                    {
                        intA = toInteger(input);
                        ptrIntA = &intA;
                        cout << "Decimal: " << *binToDec(ptrIntA)<<endl;
                    }
                    else
                    {
                        cout << "El numero no esta en formato binario" << endl;
                    }
                    break;
                case OPC_DEC_OCT:
                    intA = requestInt("Ingrese entero a convertir a octal: ");
                    if(intA>=0)
                    {
                        cout << "Octal: " << *decToOct(&intA) << endl;
                    }
                    else
                    {
                        cout << "Por el momento no se pueden convertir numeros negativos" << endl;
                    }
                    break;
                case OPC_OCT_DEC:
                    cout << "Ingrese el numero octal a obtener valor decimal: ";
                    getline(cin,input);
                    if(isOctal(input))
                    {
                        *ptrIntA = toInteger(input);
                        cout << "Decimal: " << *octToDec(ptrIntA)<<endl;
                    }
                    else
                    {
                        cout << "El numero no esta en formato octal" << endl;
                    }
                    break;
                case OPC_DEC_HEX:
                    intA = requestInt("Ingrese entero a convertir a hexadecimal: ");
                    if(intA>=0)
                    {
                        cout << "Hexadecimal: " << decToHex(&intA) << endl;
                    }
                    else
                    {
                        cout << "Por el momento no se pueden convertir numeros negativos" << endl;
                    }
                    break;
                case OPC_HEX_DEC:
                    cout << "Ingrese el numero hexadecimal a obtener valor decimal: ";
                    getline(cin,input);
                    if(isHex(input))
                    {
                        cout << "Decimal: " << *hexToDec((char *)input.c_str())<<endl;
                    }
                    else
                    {
                        cout << "El numero no esta en formato hexadecimal" << endl;
                    }
                    break;
                case OPC_SALIR:
                    break;
                default:
                    cout << "Ingrese una opcion valida" << endl;
                    break;
            }
        }
        else
        {
            cout << "Ingrese una entrada valida" << endl;
        }
        if(opc!=OPC_SALIR)
        {
            system("pause");
        }
    }while(opc!=OPC_SALIR);
}

bool isInteger(string s)
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

int toInteger(string const number)
{
    return std::stoi(number);
}

bool isFloat(string s)
{
    std::istringstream iss(s);
    float f;
    iss >> noskipws >> f;
    return iss.eof() && !iss.fail();
}

float toFloat(string const number)
{
    return std::stof(number);
}

int requestInt(string const message)
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
float requestFloat(string const message)
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

float * potencia(float * b, int * p)
{
    float * res = (float*) malloc(sizeof(float));
    *res = 1;
    for(int i=0; i< abs(*p);i++)
    {
        *res *= *b;
    }
    if(*p < 0)
    {
        * res = 1/ *res;
    }
    return res;
}
float *factorial(int *n)
{
    float * res = (float*)malloc(sizeof(float));
    *res = 1;
    for(int i=1; i <= *n; i++)
    {
        *res *= i;
    }
    return res;
}

long * decToBin(int *n)
{
    int * residuo = (int*) malloc(sizeof(int)), *cociente = (int*) malloc(sizeof(int));
    int base = 2;
    int pot = 0;
    long * res = (long*) malloc(sizeof(long));
    * res = 0;

    while((pow(base,++pot)-1) < *n);

    for(int i=0; i<pot; i++)
    {
        *residuo = *n % base;
        *cociente = *n / base;
        *res += pow(10,i) * (*residuo);
        *n = *cociente;
    }
    return res;
}

bool isBinary(string const& number)
{
    return number.length() > 0 && number.find_first_not_of("01", 0) == std::string::npos;
}

bool isHex(string const& number)
{
    return number.length() > 0 && number.find_first_not_of("0123456789abcdefABCDEF", 0) == std::string::npos;
}

int *binToDec(int *n)
{
    int * res = (int*)malloc(sizeof(int));
    *res = 0;
    int val = *n;
    string value = to_string(val);
    for(int i=0; i<value.length(); i++)
    {
        *res+= ((int) (value.at(value.length()-i-1))-48)*pow(2,i);
    }
    return res;
}

int *decToOct(int *n)
{
    int * residuo = (int*) malloc(sizeof(int)), *cociente = (int*) malloc(sizeof(int));
    int base = 8;
    int pot = 0;
    auto * res = (int*) malloc(sizeof(int));
    * res = 0;

    while((pow(base,++pot)-1) < *n);

    for(int i=0; i<pot; i++)
    {
        *residuo = *n % base;
        *cociente = *n / base;
        *res += pow(10,i) * (*residuo);
        *n = *cociente;
    }
    return res;
}

bool isOctal(string const& number)
{
    return number.length() > 0 && number.find_first_not_of("01234567", 0) == std::string::npos;
}

int *octToDec(int *n)
{
    int * res = (int*)malloc(sizeof(int));
    *res = 0;
    string value = to_string(*n);
    for(int i=0; i<value.length(); i++)
    {
        *res+= ((int) (value.at(value.length()-i-1))-48)*pow(8,i);
    }
    return res;
}

int *hexToDec(char *hex)
{
    int * res = (int*)malloc(sizeof(int));
    *res = 0;
    string value = hex;
    for(int i=0; i<value.length(); i++)
    {
        *res+= getHexValue(value.at(value.length()-1-i))*pow(16,i);
    }
    return res;
}

int getHexValue(char c)
{
    c = toupper(c);
    if(c>= '0' && c<= '9')
    {
        return c - 48;
    }
    else
    {
        return c + 10 - 65;
    }
}

char * decToHex(int *n)
{
    int * residuo = (int*) malloc(sizeof(int)), *cociente = (int*) malloc(sizeof(int));
    int base = 16;
    int pot = 0;

    while((pow(base,++pot)-1) < *n);
    char *res = new char[pot+1];
    for(int i=0; i<pot; i++)
    {
        *residuo = *n % base;
        *cociente = *n / base;
        res[pot-i-1] = getHex(*residuo);
        n = cociente;
    }
    res[pot] = '\0';
    return res;
}

char getHex(int value)
{
    if(value<=9 && value>=0)
    {
        return (char)(value+48);
    }
    else
    {
        return (char)((value-10) + 65);
    }
}