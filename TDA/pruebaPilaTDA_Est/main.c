
#include "main.h"

int main()
{
    probarIngresarYMostrarProd();

    probarIngresarYMostrarTexto();

    probarPonerYSacarDePila();

    return 0;
}

void probarIngresarYMostrarProd(void)
{
    tProd   prod;
    int     cant = 0;

    puts("Probando ingresar productos y mostrar productos.\n"
         "======== ======== ========= = ======= =========");
    if(ingresarProducto(&prod))
        mostrarProducto(NULL);
    do
    {
        mostrarProducto(&prod);
        cant++;
    }while(ingresarProducto(&prod));
    fprintf(stdout, "Se mostraron %d productos.\n\n", cant);
}

void probarIngresarYMostrarTexto(void)
{
    char    linea[90];
    int     cant = 0;

    puts("Probando ingresar lineas de texto mostrandolas.\n"
         "======== ======== ====== == ===== ============");
    while(ingresarTexto(linea, sizeof(linea)))
    {
        cant++;
        printf("\"%s\"\n", linea);
    }
    fprintf(stdout, "Se mostraron %d lineas de texto.\n\n", cant);
}

void probarPonerYSacarDePila(void)
{
    tProd   prod,
            otro;
    char    linea[70];
    tPila   pila;
    int     cant;

    crearPila(&pila);

    puts("Probando primitivas de pila con productos.\n"
         "======== ========== == ==== === =========\n"
         "Probando pila llena y poner en pila.");
    mostrarProducto(NULL);
    cant = 0;
    while(!pilaLlena(&pila, sizeof(prod)) && ingresarProducto(&prod))
    {
        if(!ponerEnPila(&pila, &prod, sizeof(prod)))
        {
            fprintf(stderr, "ERROR - inesperado - pila llena.\n");
            puts("no se pudo cargar la informacion y"
                 " habria que tomar alguna decision drastica.");
        }
        mostrarProducto(&prod);
        cant++;
    }
    printf("se pusieron %d productos en la pila.\n\n", cant);
    puts("Probando ver el tope de la pila.");
    if(verTope(&pila, &otro, sizeof(otro)))
    {
        mostrarProducto(NULL);
        mostrarProducto(&otro);
    }
    else
        puts("La pila estaba vacia.");
    puts("");
    cant -= 2;
    printf("Probando pila vacia y sacar de pila %d productos (mostrandolos.\n",
           cant);
    if(pilaVacia(&pila))
        puts("La pila esta vacia.");
    else
        mostrarProducto(NULL);
    while( cant > 0 && sacarDePila(&pila, &prod, sizeof(prod)))
    {
        cant--;
        mostrarProducto(&prod);
    }
    puts("");
    puts("Probando ver el tope de la pila")

}
