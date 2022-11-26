"""
Practica 7 : Agenda 
Ismael Ivan Lopez Murillo
Seminario de solución de problemas de estructuras de datos II
Sección D15
"""

import os

class Entrada:
    def __init__(self, nombre='',apellido='',codigo='',telefono='',carrera=''):
        self.nombre  = nombre
        self.apellido = apellido
        self.codigo = codigo
        self.telefono = telefono
        self.carrera = carrera

    def __str__(self):
        return f"{self.nombre},{self.apellido},{self.codigo},{self.telefono},{self.carrera}\n"
    
    def mostrar(self, busqueda=''):
        if busqueda != 'nombre':
            print("Nombre: " + self.nombre)
            print("Apellido: " + self.apellido)
        if busqueda != 'codigo':
            print("Codigo: " + self.codigo)
        if busqueda != 'telefono':
            print("Telefono: " + self.telefono)
        if busqueda != 'carrera':
            print("Carrera: " + self.carrera)
        print("\n")

    def leer(self):
        self.nombre = str(input("Ingrese el nombre: "))
        self.apellido = str(input("Ingrese el apellido: "))
        self.codigo = str(input("Ingrese el codigo: "))
        self.telefono = str(input("Ingrese el telefono: "))
        self.carrera = str(input("Ingrese la carrera: "))
    
    def cargar(self, linea):
        propiedades = linea.split(',')
        if len(propiedades) != 5:
            return False

        self.nombre  = propiedades[0]
        self.apellido = propiedades[1]
        self.codigo = propiedades[2]
        self.telefono = propiedades[3]
        self.carrera = propiedades[4]
        return True

class Agenda:
    def __init__(self, filename = None):
        self.entradas = []
        if filename != None:
            self.filename = filename + '.txt'
            archivo = open(self.filename,'w')   #Borrar todo
            archivo.close()
    
    def agregar_nuevo(self):
        entrada = Entrada()
        entrada.leer()
        self.entradas.append(entrada)
        if self.filename != None:
            self.guardar_entrada(entrada)

    def guardar_entrada(self,entrada):
        archivo = open(self.filename,'a')
        archivo.write(str(entrada))
        archivo.close()

    def cargar_agenda(self, _filename):
        self.filename = _filename + '.txt'
        if not os.path.exists(self.filename):
            return False
        archivo = open(self.filename,'r')
        contenido = archivo.read()
        lineas = contenido.split('\n')

        for linea in lineas:
            entrada = Entrada()
            if entrada.cargar(linea):
                self.entradas.append(entrada)
        archivo.close()
        return True

    def guardar_agenda(self):
        archivo = open(self.filename,'w')
        for entrada in self.entradas:
            archivo.write(str(entrada))

        archivo.close()

    def busqueda_telefono(self, telefono):
        entrada = next((e for e in self.entradas if e.telefono == telefono), None)
        if entrada != None:
            entrada.mostrar(busqueda='telefono')
        else:
            print("No se encontro la entrada con telefono " + telefono)
    
    def busqueda_nombre(self, nombre, apellido):
        n = nombre.lower()
        a = apellido.lower()
        entrada = next((e for e in self.entradas if e.nombre.lower() == n and e.apellido.lower() == a), None)
        if entrada != None:
            entrada.mostrar(busqueda='nombre')
        else:
            print(f"No se encontro a {nombre} {apellido}")

    def busqueda_codigo(self, codigo):
        entrada = next((e for e in self.entradas if e.codigo == codigo), None)
        if entrada != None:
            entrada.mostrar(busqueda='codigo')
        else:
            print("No se encontro la entrada del codigo " + codigo)

    def busqueda_carrera(self, carrera):
        ocurrencias = filter(lambda e: e.carrera == carrera, self.entradas)
        print()
        for entrada in ocurrencias:
            entrada.mostrar(busqueda='carrera')

    def borrar_entrada(self,codigo):
        for index, entrada in enumerate(self.entradas):
            if entrada.codigo == codigo:
                self.entradas.pop(index)
                return True
        
        return False

    def __len__(self):
        return len(self.entradas)

    def __bool__(self):
        return self.filename != None

def main():
    agenda = Agenda()
    opc = ''
    while opc != '6':
        print("\n\t\tAGENDA")
        print("1.- Abrir agenda")
        print("2.- Crear agenda")
        print("3.- Nueva entrada")
        print("4.- Borrar de agenda")
        print("5.- Busquedas")
        print("6.- Salir")

        opc = str(input("Ingrese su entrada: "))

        if opc in ['3','4','5'] and not agenda:
            print("Primero abra o cree una agenda")
            pass

        if opc == '1':
            agenda = Agenda()
            nombre = str(input("Ingrese el nombre de la agenda: "))
            if agenda.cargar_agenda(nombre):
                print(f"Agenda cargada con {len(agenda)} entradas")
            else:
                print("No se encontro el archivo, se creo una nueva agenda")
                
        elif opc == '2':
            print("Advertencia: Al crear una nueva agenda se borrará si existe una con el mismo nombre")
            nombre = str(input("Ingrese el nombre de la agenda nueva: "))
            agenda = Agenda(nombre)
            print("Nueva agenda creada")

        elif opc == '3':
            agenda.agregar_nuevo()
            print("Entrada agregada")

        elif opc == '4':
            codigo = str(input("Ingrese el codigo a borrar: "))
            if agenda.borrar_entrada(codigo):
                agenda.guardar_agenda()
                print("Entrada borrada")
            else:
                print("No se encontro la entrada")

        elif opc == '5':
            print("\nBusqueda por: ")
            print("1.- Nombre")
            print("2.- Codigo")
            print("3.- Telefono")
            print("4.- Carrera")

            busqueda = str(input("Ingrese el criterio de busqueda: "))

            if busqueda == '1':
                nombre = str(input("Ingrese el nombre de pila: "))
                apellido = str(input("Ingrese el apellido: "))
                agenda.busqueda_nombre(nombre,apellido)
            
            elif busqueda == '2':
                codigo = str(input("Ingrese el codigo: "))
                agenda.busqueda_codigo(codigo)
            
            elif busqueda == '3':
                telefono = str(input("Ingrese el telefono: "))
                agenda.busqueda_telefono(telefono)

            elif busqueda == '4':
                carrera = str(input("Ingrese la carrera: "))
                agenda.busqueda_carrera(carrera)
            
            else:
                print("Criterio invalido")

        elif opc == '6':
            print("Gracias por usar la agenda")

        else:
            print("Ingrese una entrada valida")
        
        if opc != '6':
            input("Presione enter para continuar")

if __name__ == "__main__":
    main()

    

    