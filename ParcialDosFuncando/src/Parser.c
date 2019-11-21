#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Revelados.h"
#include "LinkedList.h"
#include "Parser.h"

int parser_parseRevelados(char* fileName, LinkedList* listaRevelados)
{
	int retorno = -1;
	int cantidadLeida;
	char ID_Venta[1024],Fecha_Venta[1024],Tipo_Foto[1024],Cantidad[1024],Precio_Unitario[1024],CUIT_Cliente[1024];
	Revelado* pRevelado;
	FILE *pFile;

	pFile = fopen(fileName,"r");

	if(listaRevelados != NULL && pFile != NULL)
	{
		cantidadLeida = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",ID_Venta,Fecha_Venta,Tipo_Foto,Cantidad,Precio_Unitario,CUIT_Cliente);

		do {
				cantidadLeida = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",ID_Venta,Fecha_Venta,Tipo_Foto,Cantidad,Precio_Unitario,CUIT_Cliente);
				if (cantidadLeida == 6)
				{
					pRevelado =	revelado_newParametros(ID_Venta,Fecha_Venta,Tipo_Foto,Cantidad,Precio_Unitario,CUIT_Cliente);
					ll_add(listaRevelados,pRevelado);
					retorno = 1;
				}else
				{
					printf("Error en la lectura de datos.\n");
					retorno = -1;
					break;
				}
			} while (!feof(pFile));
	}
		return retorno;
}

int generarInforme_saveAsText(char* path , LinkedList* listaRevelados, int total, int mayorUno, int mayorDos, int polaroid)
{
	int retorno = -1;
	int i;

	FILE* pFileTexto;
	pFileTexto = fopen(path, "w");

	if(listaRevelados!=NULL && path != NULL)
	{

		if(pFileTexto != NULL)
		{
				fprintf(pFileTexto,"********************\n");
				fprintf(pFileTexto,"Informe de ventas\n");
				fprintf(pFileTexto,"********************\n");
				fprintf(pFileTexto,"- Cantidad de fotos reveladas totales: %d\n", total);
				fprintf(pFileTexto,"- Cantidad de ventas por un monto mayor a $150: %d\n", mayorUno);
				fprintf(pFileTexto,"- Cantidad de ventas por un monto mayor a $300: %d\n", mayorDos);
				fprintf(pFileTexto,"- Cantidad de fotos polaroids reveladas: %d\n",polaroid);
				fprintf(pFileTexto,"********************\n");

			retorno = 0;
		}
	}
		fclose(pFileTexto);
	    return retorno;
}

/*
 ********************
Informe de ventas
********************
- Cantidad de fotos reveladas totales: XX
- Cantidad de ventas por un monto mayor a $150: XX
- Cantidad de ventas por un monto mayor a $300: XX
- Cantidad de fotos polaroids reveladas: XX
********************
  */

