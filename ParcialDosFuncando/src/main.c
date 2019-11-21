#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Revelados.h"
#include "LinkedList.h"
#include "Parser.h"

int main()
{
	int totalRevelado;
	int cantidadMayor150;
	int cantidadMayor300;
	int cantidadPolaroid;

	LinkedList* listaRevelados = ll_newLinkedList();

    if(parser_parseRevelados("data.csv",listaRevelados)==1)
    {
        
        printf("Correcta Lectura de arhivos\n");
        totalRevelado = ll_count(listaRevelados,revelados_totalesCount);

        cantidadMayor150 = ll_count(listaRevelados,revelados_ventaMayor150);

        cantidadMayor300 = ll_count(listaRevelados,revelados_ventaMayor300);

        cantidadPolaroid = ll_count(listaRevelados,revelados_polaroid);

    }else
    {
    	printf("Error leyendo revelados\n");

    }
    if(generarInforme_saveAsText("informe.txt",listaRevelados,totalRevelado,cantidadMayor150,cantidadMayor300,cantidadPolaroid)==0)
    {
    	printf("Archivo generado correctamente\n");
    }else
    {
    	printf("Error generando archivo\n");
    }

    return 0;
}


