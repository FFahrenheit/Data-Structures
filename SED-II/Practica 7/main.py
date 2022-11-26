"""
Practica 6 : Pila 
Ismael Ivan Lopez Murillo
Seminario de solución de problemas de estructuras de datos II
Sección D15
"""


class Pila:
    def __init__(self):
        self.pila = []

    def push(self,dato):
        self.pila.append(dato)

    def pop(self):
        return self.pila.pop()

    def tope(self):
        return self.pila[-1]

class Libro:
    def __init__(self, titulo='', autor='',editorial=''):
        self.titulo = titulo 
        self.autor = autor
        self.editorial = editorial
    
    def mostrar(self):
        print(f"Titulo: {self.titulo}")
        print(f"Autor: {self.autor}")
        print(f"Editorial: {self.editorial}",end='\n\n')

def main():
    opc = ''
    pila = Pila()

    print("""Bienvenido a la pila mágica de libros
Aqui puedes tomar gratis el libro que este hasta arriba en la pila, el cual puedes consultar antes 
Tambien puedes agregar un nuevo libro a esta pila para que alguien lo conozca
""")

    while opc != '4':

        print('\n\t\tPila mágica de libros')
        print('1) Agregar libro a la pila')
        print('2) Consultar libro en la pila')
        print('3) Llevar libro en la pila')
        print('4) Salir')

        opc = str(input('Ingrese su eleccion: '))
        print()

        if opc == '1':
            titulo = str(input("Ingrese titulo del libro: "))
            autor = str(input("Ingrese el autor del libro: "))
            editorial = str(input("Ingrese la editorial del libro: "))
            
            libro = Libro(titulo,autor,editorial)
            pila.push(libro)
            print("Libro apilado")
        elif opc == '2':
            try:
                libro : Libro = pila.tope()
                print("Libro en la pila mágica:")
                libro.mostrar()
            except:
                print("La pila mágica está vacía!")
        elif opc == '3':
            try:
                libro : Libro = pila.pop()
                print("Te has llevado: ")
                libro.mostrar()
            except:
                print("No puedes llevarte un libro. La pila mágica está vacía!")
        elif opc == '4':
            print("Gracias por usar la pila mágica")
        else:
            print("Seleccione una opcion valida")


if __name__ == "__main__":
    main()