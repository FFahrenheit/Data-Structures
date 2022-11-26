"""
Practica 4 : Ageanda con respaldo
Ismael Ivan Lopez Murillo
Seminario de solución de problemas de estructuras de datos II
Sección D15
"""

import os

_principal = "alumnos.txt"
_respaldo = "alumnos-respaldo.txt"

class Estudiante:
    def __init__(self, nombre='', codigo='', telefono='', carrera=''):
        self.nombre = nombre
        self.codigo = codigo 
        self.telefono = telefono
        self.carrera = carrera

    def leer(self, linea):
        lineas = linea.split('#')
        if len(lineas) == 4:
            self.nombre = lineas[0]
            self.codigo = lineas[1]
            self.telefono = lineas[2]
            self.carrera = lineas[3]
            return True
        else:
            return False
    
    def escribir(self):
        return f"{self.nombre}#{self.codigo}#{self.telefono}#{self.carrera}\n"

    def mostrar(self):
        print(f"Nombre: {self.nombre}")
        print(f"Codigo: {self.codigo}")
        print(f"Telefono: {self.telefono}")
        print(f"Carrera: {self.carrera}", end='\n\n')


def main():
    opc = ''
    while opc != '3':
        print("\n\n\t\tAplicacion Directorio")
        print("1) Agregar nuevo registro")
        print("2) Leer todo el archivo")
        print("3) Salir")

        opc = str(input("Ingrese su eleccion: "))
        print('')

        if opc == '1':
            nombre = str(input("Ingrese el nombre: "))
            codigo = str(input("Ingrese el codigo: "))
            telefono = str(input("Ingrese el telefono: "))
            carrera = str(input("Ingrese la carrera: "))

            estudiante = Estudiante(nombre,codigo,telefono,carrera)
            guardar_al_final(estudiante)
            print("Registro agregado")

        elif opc == '2':
            principal = open(_principal,'r')
            contenido = principal.read()

            estudiante = Estudiante()
            for linea in contenido.split('\n'):
                if estudiante.leer(linea):
                    estudiante.mostrar()

            principal.close()

        elif opc == '3':
            print("Gracias por usar el programa")
        else:
            print("Seleccione una opcion valida")
        
def guardar_al_final(estudiante : Estudiante):
    if not os.path.exists(_principal):
        with open(_principal, 'w'): pass
        
    principal = open(_principal,'r')    #Abrir principal en modo lectura
    respaldo = open(_respaldo,'w')      #Abrir resplado en modo escritura

    contenido = principal.read()        #Copiar el contenido 
    respaldo.write(contenido)           #del archivo original

    principal.close();respaldo.close()  #Cerrar ambos archivos

    principal = open(_principal,'w')    #Abrir principal en modo escritura
    respaldo = open(_respaldo,'r')      #Abrir respaldo en modo lectura

    contenido = respaldo.read()         #Copiar el contenido
    principal.write(contenido)          #del respaldo

    registro = estudiante.escribir()
    principal.write(registro)           #Agregar nuevo registro al original
    
    principal.close();respaldo.close()  #Cerrar ambos archivos


if __name__ == "__main__":
    main()