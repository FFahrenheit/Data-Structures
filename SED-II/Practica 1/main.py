from complejo import Complejo

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