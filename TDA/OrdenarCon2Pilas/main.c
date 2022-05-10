#include <stdio.h>
#include <stdlib.h>

#include "../pilaEstatica/pila.h"
#include "../productos/productos.h"
#include "main.h"

int main()
{
    tPila p1;
    FILE *pf = fopen("productos.dat","wb");
    if(!pf)
        return 0;

    cargarArchivo("productos.dat");

    mostrarArchivo("productos.dat");

    crearPila(&p1);

 //   cargarPila("productos.dat", &p1);

    ordenarArchivoEnPila("productos.dat", &p1);

    mostrarPila(&p1);

    return 0;
}

int cargarArchivo(char *path)
{
    FILE *pf = fopen(path,"wb");
    if(!pf)
        return 0;

    static const tProd productos[] = {
        //1234567890     123456789 123456789 123456789 123456789 12345
//        { "clavoro3/4", "Clavo de oro 24 kilates de 3/4 de pulgada" },
//        { "martillo3K", "Martillo bolita con saca clavos de 3 kilos" },
//        { "alamyeso1",  "Alambre de yeso de un milimetro de espesor" },
//        { "rem-vid15",  "Remache de vidrio de 1,5 milimetros" },
//        { "plom-telgo", "Plomada de poliestireno expandido" },
//        { "limagoma17", "Lima de goma de 17 pulgadas" } };
        { "5", "Clavo de oro 24 kilates de 3/4 de pulgada" },
        { "65", "Martillo bolita con saca clavos de 3 kilos" },
        { "9",  "Alambre de yeso de un milimetro de espesor" },
        { "3",  "Remache de vidrio de 1,5 milimetros" },
        { "2", "Plomada de poliestireno expandido" },
        { "8", "Lima de goma de 17 pulgadas" } };

    fwrite(productos,sizeof(productos),1,pf);
    fclose(pf);
    return 1;
}

int mostrarArchivo(char *path)
{
    tProd producto;
    FILE *pf = fopen(path,"rb");
    if(!pf)
        return 0;

    fread(&producto, sizeof(producto),1,pf);

    while(!feof(pf))
    {
       mostrarProducto(&producto);
       fread(&producto, sizeof(producto),1,pf);
    }

    fclose(pf);
    return 1;
}

int cargarPila(char *path, tPila *p1)
{
    tProd producto;
    FILE *pf = fopen(path,"rb");
    if(!pf)
        return 0;

    fread(&producto, sizeof(producto),1,pf);
    while(!feof(pf))
    {
        if(!pilaLlena(p1,sizeof(producto)))
            ponerEnPila(p1,&producto,sizeof(producto));
        fread(&producto, sizeof(producto),1,pf);
    }

    fclose(pf);
    return 1;
}

void mostrarPila(tPila *p1)
{
    tProd producto;

    printf("\n::::Procedemos a mostrar la pila::::\n");
    while(!pilaVacia(p1))
    {
        sacarDePila(p1,&producto,sizeof(producto));
        mostrarProducto(&producto);
    }
}

int ordenarArchivoEnPila(char *path, tPila *p1)
{
    tPila p2;
    tProd productoArch,
          productoP1,
          productoP2;
    crearPila (&p2);

    FILE *pf = fopen(path,"rb");

    if(!pf)
        return 0;

    fread(&productoArch, sizeof(productoArch),1,pf);
    memcpy(&productoP1, &productoArch, sizeof(productoArch));

    while(!feof(pf))
    {
        verTope(p1, &productoP1, sizeof(productoP1));
        if(!pilaLlena(p1,sizeof(productoP1)))
        {
          if( atoi(productoArch.codProd) >= atoi(productoP1.codProd) )
          {
            ponerEnPila(p1,&productoArch,sizeof(productoArch));
          }
          else
          {
            while(!pilaVacia(p1) && atoi(productoArch.codProd) < atoi(productoP1.codProd))
            {
                sacarDePila(p1, &productoP1, sizeof(productoP1));
                ponerEnPila(&p2, &productoP1,sizeof(productoP1));
                verTope(p1, &productoP1, sizeof(productoP1));
            }

            ponerEnPila(p1, &productoArch, sizeof(productoArch));

            while(!pilaVacia(&p2) && !pilaLlena(p1, sizeof(productoP2)))
            {
                sacarDePila(&p2, &productoP2,sizeof(productoP2));
                ponerEnPila(p1, &productoP2,sizeof(productoP2));
            }

          }
        }

        fread(&productoArch, sizeof(productoArch),1,pf);
    }

    fclose(pf);
    return 1;
}
