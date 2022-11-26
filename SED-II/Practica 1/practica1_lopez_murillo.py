"""
Practica 1 : POO
Ismael Ivan Lopez Murillo
Seminario de solución de problemas de estructuras de datos II
Sección D15
"""


class Complejo:
    def __init__(self, real = 0, imag = 0):
        self.real = real
        self.imag = imag

    def get_real(self):
        return self.real

    def set_real(self,real):
        self.real = real 
    
    def get_imag(self):
        return self.imag
    
    def set_imag(self, imag):
        self.imag = imag
    
    def __str__(self):
        return f"({self.real} + {self.imag}i)"

    def __add__(self,other):
        real = self.real + other.real
        imag = self.imag + other.imag
        return Complejo(real,imag)

    def __sub__(self,other):
        real = self.real - other.real 
        imag = self.imag - other.imag
        return Complejo(real,imag)

    def __mul__(self,other):
        real = self.real * other.real - self.imag * other.imag
        imag = self.real * other.imag + other.real * self.imag
        return Complejo(real,imag)

def main():
    opc = ''
    while opc != '4':
        print("\t\tCalculadora de numeros complejos")
        print("1) Suma")
        print("2) Resta")
        print("3) Muliplicacion")
        print("4) Salir")
        opc = str(input("Ingrese su eleccion: "))

        if opc in ['1','2','3']:
            real = float(input("Ingrese la parte real del primer numero: "))
            imag = float(input("Ingrese la parte imaginaria del primer numero: "))
            num1 = Complejo(real,imag)

            real = float(input("Ingrese la parte real del segundo numero: "))
            imag = float(input("Ingrese la parte imaginaria del segundo numero: "))
            num2 = Complejo(real,imag)

        if opc == '1':
            res = num1 + num2
            print(f"{num1} + {num2} = {res}")
        elif opc == '2':
            res = num1 - num2
            print(f"{num1} - {num2} = {res}")
        elif opc == '3':
            res = num1 * num2
            print(f"{num1} * {num2} = {res}")
        elif opc == '4':
            print('Gracias por usar la calculadora')
            break
        else:
            print('Ingrese una opcion valida')
        

if __name__ == '__main__':
    main()