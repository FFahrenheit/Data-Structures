"""
Practica 2 : Codificador Cesar a pantalla 
Ismael Ivan Lopez Murillo
Seminario de solución de problemas de estructuras de datos II
Sección D15
"""

import os

def main():
    filename = input("Ingrese el nombre del archivo: ")

    if not os.path.exists(filename):
        filename = filename + ".txt"

    if os.path.exists(filename):
        file = open(filename,'r')

        letra = file.read(1)

        while letra != '':
            if letra >= 'a' and letra < 'z':
                print(chr(ord(letra)+1),end='')
            elif letra == 'z':
                print('a',end='')
            else:
                print(letra,end='')

            letra = file.read(1)
    else:
        print("El archivo no existe :/")

if __name__ == "__main__":
    main()