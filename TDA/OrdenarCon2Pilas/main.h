#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

int cargarArchivo(char *path);
int mostrarArchivo(char *path);
int cargarPila(char *path, tPila *p1);
void mostrarPila(tPila *p1);
int ordenarArchivoEnPila(char *path, tPila *p1);

#endif // MAIN_H_INCLUDED
