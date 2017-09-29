#!/usr/bin/python
#path de la ubicacion de python para pode ejecutarlo de la forma ./CrearPoblacion.py
#(necesita asignacion de permisos [sudo chmod 744 CrearPoblacion.py])

import os

def principal():
    print "\n\nIniciando rutina\n"
    print "Practica 2: Creacion de Poblacion Aleatoria y Graficacion de la Actitud\n\n"
    #verificamos si existe el archivo de Poblacion.txt (encargado de guadar la informacion de graficacion)
    if os.path.exists("Poblacion.txt"):
        #el archivo existe, se procede a borrarlo
        print "Se ha detectado la existencia del archivo Poblacion.txt"
        print "Procediendo a borrar el archivo para crear una nueva version"
        os.system("rm Poblacion.txt")
        print "Archivo borrado, continuando rutina\n"
    else:
        #el arcivo no existe, solo se notifica
        print "No se ha detectado la existencia del achivo Poblacion.txt"
        print "Continuando rutina de forma normal\n"
    #borrando achivos compilados de C++, volviendo a compilar y ejecutando programa en C++
    os.system("make clean")
    os.system("make run")
    print "Archivo Poblacion.txt generado, comenzando su graficacion"
    #ejecuta el programa de JAVA para graficar los datos generados por el pograma en C++
    print "Grafica Generada, terminando rutina"
    os.system("java -jar Graficacion.jar")
quit(principal())
