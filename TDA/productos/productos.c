
#include "productos.h"

int ingresarProducto(tProd *d)
{
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
    static int posi = 0;

    if(posi == sizeof(productos) / sizeof(tProd))
    {
        posi = 0;
        return 0;
    }
    *d = productos[posi];
    posi++;

    return 1;
}

void mostrarProducto(const tProd *d)
{
    if(d)
        fprintf(stdout,
                "%-*s %-*s ...\n",
                sizeof(d->codProd) - 1, d->codProd,
                sizeof(d->descrip) - 1, d->descrip);
    else
        fprintf(stdout,
                "%-*.*s %-*.*s ...\n",
                sizeof(d->codProd) - 1, sizeof(d->codProd) - 1, "Cod. Producto",
                sizeof(d->descrip) - 1, sizeof(d->descrip) - 1,
                    "Descripcion del producto");
}
