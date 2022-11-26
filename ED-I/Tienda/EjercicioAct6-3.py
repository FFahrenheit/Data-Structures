"""
FUNDAMENTOS FILOSOFICOS DE LA COMPUTACION SECCION D07
NOMBRE DEL ALUMNO: Ismael Iván López Murillo   Código 220975903
Maestro: Conrado Cruz Gomez
PROGRAMA DISTRIBUCIÓN NORMAL
FECHA. 17/NOVIEMBRE/2020
TEMA: Manejo de listas de tipo char o entero con funciones.
"""

import os
import random
import math 

def main():
    bienvenida()
    data = []
    opc = 0
    os.system("pause")
    os.system("color 07")
    while opc != -1:
        os.system("cls")
        print("*"*10,"MENU","*"*10)
        print(f"En este momento, tiene {len(data)} datos almacenados para estadistica")
        print("1) Ingresar n datos")
        print("2) Ingresar n numeros al azar")
        print("3) Vaciar datos")
        print("4) Imprimir datos")
        print("5) Obtener promedio")
        print("6) Obtener varianza")
        print("7) Obtener desviacion estandar")
        print("8) Obtener desviacion estandar de la poblacion")
        print("9) Obtener todos los calculos")
        print("10) Obtener probabilidad")
        print("11) Guardar mis datos en un archivo")
        print("12) Cargar mis datos desde un archivo")
        print("13) Cargar datos de texto plano")
        print("0) Mostrar creditos")
        print("-1) SALIR")
        opc = str(input("Ingrese su eleccion: "))

        try:
            opc = int(opc)
        except ValueError:
            continue
        
        if opc == 1:
            n = int(input("Ingrese cuantos datos va a agregar: "))
            agregarDatos(data,n)        
        elif opc == 2:
            n = int(input("Ingrese cuantos datos va a agregar: "))
            minVal = int(input("Ingrese el valor entero minimo a agregar: "))
            maxVal = int(input("Ingrese el valor entero maximo a agregar: "))
            agregarDatosRandom(data,n,minVal,maxVal)
        elif opc == 3:
            data.clear()
            print("Se ha borrado la data")
        elif opc == 4:
            imprimirDatos(data)
        elif opc == 5:
            prom = obtenerPromedio(data)
            print(f"El promedio de los datos es {prom:.4f}")
        elif opc == 6:
            varianza = obtenerVarianza(data)
            print(f"La varianza de los datos es {varianza:.4f}")
        elif opc == 7:
            desvEst = obtenerDesviacionStd(data)
            print(f"La desviacion estandar es {desvEst[0]:.4f}")
            print(f"SD =  {desvEst[1]:.4f}")
            print(f"SM =  {desvEst[2]:.4f}")
        elif opc == 8:
            desvEstPob = obtenerDesviacionStdPob(data)
            print(f"La desviacion estandar de la poblacion es {desvEstPob:.4f}")
        elif opc == 9:
            calcularTodo(data)
        elif opc == 10:
            x = float(input("Ingrese el valor a obtener probabilidad: "))
            prob = calcularProbabilidad(data,x)
            print(f"La probabilidad de que ocurra {x} en nuestra data es de {prob:.6f}")
        elif opc == 11:
            filename = str(input("Ingrese el nombre del archivo (sin extension) a guardar: "))
            guardarDatos(data,filename)
        elif opc == 12:
            filename = str(input("Ingrese el nombre del archivo (sin extension) a cargar: "))
            cargarDatos(data,filename)
        elif opc == 13:
            dta = str(input("Ingrese todo el string de sus datos: \n"))
            sep = str(input("Ingrese el separador de datos (, / # ): "))
            cargarDatosStr(data,dta,sep)
        elif opc == 0:
            bienvenida()
        elif opc == -1:
            print("Gracias por usar mi programa")
            break
        else:
            print("Ingrese una opcion valida")
        
        os.system("pause")
        color = random.randint(0,9)
        os.system(f"color 0{color}")


def cargarDatos(data,filename):
    file = open(filename+".txt",'r')
    
    values = file.read().split("\n")

    for val in values:
        data.append(float(val))

    file.close()        
    print(f"Se han cargado {len(values)} datos en {filename}.txt")


def guardarDatos(data,filename):
    file = open(filename+".txt",'w')

    for i in range(len(data)):
        file.write(str(data[i]))
        if i != len(data)-1:
            file.write("\n")
    
    file.close()        
    print(f"Se han guardado {len(data)} datos en {filename}.txt")


def cargarDatosStr(data,source,separator):
    values = source.split(separator)
    for val in values:
        data.append(float(val))
    print(f"Se han agregado {len(values)} datos")


def calcularProbabilidad(data,x):
    prom = obtenerPromedio(data)
    desv = obtenerDesviacionStd(data)
    desv = desv[0]   #Solo nos importa la desviacion
    return (1/(desv*math.sqrt(2*math.pi)))*math.exp((-1)*((x-prom)**2)/(2*desv**2))


def calcularTodo(data):
    prom = obtenerPromedio(data)
    print(f"El promedio de los datos es {prom:.4f}")
    varianza = obtenerVarianza(data)
    print(f"La varianza de los datos es {varianza:.4f}")
    desvEst = obtenerDesviacionStd(data)
    print(f"La desviacion estandar es {desvEst[0]:.4f}")
    print(f"SD =  {desvEst[1]:.4f}")
    print(f"SM =  {desvEst[2]:.4f}")
    desvEstPob = obtenerDesviacionStdPob(data)
    print(f"La desviacion estandar de la poblacion es {desvEstPob:.4f}")


def obtenerDesviacionStdPob(data):
    prom = obtenerPromedio(data)
    acum = 0
    for d in data:
        acum += (d-prom)**2
    return acum/len(data)


def obtenerDesviacionStd(data):
    varianza = obtenerVarianza(data)
    prom = obtenerPromedio(data)
    desv = math.sqrt(varianza)
    sd = prom - desv 
    sm = prom + desv 
    return [desv, sd, sm]


def obtenerVarianza(data):
    prom = obtenerPromedio(data)
    acum = 0
    for d in data:
        acum += (d-prom)**2
    return acum/(len(data)-1)


def obtenerPromedio(data):
    acum = 0
    for d in data:
        acum += d
    return acum / len(data)


def imprimirDatos(data):
    for i in range(len(data)):
        if i != len(data) - 1:
            print(data[i],end=' , ')
        else:
            print(data[i],end='\n')


def agregarDatosRandom(data,n,minV,maxV):
    for _ in range(n):
        data.append(random.randint(minV,maxV))
    print(f"Se han agregado {n} datos")


def agregarDatos(data,n):
    for i in range(n):
        val = float(input(f"Ingrese el valor {i+1} a agregar: "))
        data.append(val)
    print(f"Se han agregado {n} datos")


def bienvenida():
    os.system("color 0a")
    print("Bienvenido al programa de calculo de distribucion normal")
    print("Programado por Ismael Ivan Lopez Murillo")
    print("Ing. en computacion 2020B")


if __name__ == "__main__":
    main()
