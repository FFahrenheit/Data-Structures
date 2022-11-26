import os

def main():
    filename = 'TheCure-PicturesOfYou.txt'

    if(os.path.exists(filename)):
        file = open(filename,'r')

        contador = 0

        for linea in file:
            print(linea[:-1])

            #Si no esta vacia
            if linea.strip():
                contador += 1 

        print(f"\nTotal de lineas: {contador}")
    else:
        print("El archivo no existe :/")

if __name__ == "__main__":
    main()