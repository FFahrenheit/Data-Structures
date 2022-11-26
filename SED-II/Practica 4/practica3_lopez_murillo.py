"""
Practica 3 : CODEC 
Ismael Ivan Lopez Murillo
Seminario de solución de problemas de estructuras de datos II
Sección D15
"""

import os

def main():
    name = input("Ingrese el nombre del archivo: ")

    if not os.path.exists(name):
        filename =  name + ".txt"
    else:
        filename =  name

    if(os.path.exists(filename)):
        file = open(filename,'r')

        letra = file.read(1)

        coded_file = open(name + "-coded.txt",'w')

        while letra != '':
            if letra >= 'a' and letra < 'z':
                letter = chr(ord(letra)+1)
                print(letter,end='')
                coded_file.write(letter)
            elif letra == 'z':
                print('a',end='')
                coded_file.write('a')
            else:
                print(letra,end='')
                coded_file.write(letra)

            letra = file.read(1)
        
        coded_file.close()

        print("\n\n"+"-"*50+"\nAhora decodificando...\n"+"-"*50+"\n")

        coded_file = open(name + "-coded.txt",'r')

        letra = coded_file.read(1)

        decoded_file = open(name + "-decoded.txt",'w')

        while letra != '':
            if letra > 'a' and letra <= 'z':
                letter = chr(ord(letra)-1)
                print(letter,end='')
                decoded_file.write(letter)
            elif letra == 'a':
                print('z',end='')
                decoded_file.write('z')
            else:
                print(letra,end='')
                decoded_file.write(letra)

            letra = coded_file.read(1)

        coded_file.close()
        decoded_file.close()
    else:
        print("El archivo no existe :/")

if __name__ == "__main__":
    main()