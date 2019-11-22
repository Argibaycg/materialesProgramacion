#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Parser.h"
#include "Cachorros.h"

int parser_parseCachorros(char* fileName, LinkedList* listaCachorros)
{
	int retorno = -1;
	int cantidadLeida;
	char ID_Cachorro[128];
	char Nombre[128];
	char Dias[128];
	char Raza[128];
	char Reservado[128];
	char Genero[128];
	Cachorro* pCachorro;
	FILE *pFile;

	pFile = fopen(fileName,"r");

	if(listaCachorros != NULL && pFile != NULL)
	{
		cantidadLeida = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",ID_Cachorro,Nombre,Dias,Raza,Reservado,Genero);

		do {
				cantidadLeida = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",ID_Cachorro,Nombre,Dias,Raza,Reservado,Genero);
				if (cantidadLeida == 6)
				{
					pCachorro =	cachorro_newParametros(ID_Cachorro,Nombre,Dias,Raza,Reservado,Genero);
					ll_add(listaCachorros,pCachorro);
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

int generarArchivoFilter(char* fileName,LinkedList* listaFiltrada)
{
	int retorno = -1;
	int i;
	int len = 0;
	int ID_Cachorro;
	char Nombre[128];
	int Dias;
	char Raza[128];
	char Reservado[128];
	char Genero[128];

	FILE* pFileTexto;
	pFileTexto = fopen(fileName, "w");
	Cachorro* pCachorro = NULL;

	if(listaFiltrada!=NULL && pFileTexto != NULL)
	{
		len = ll_len(listaFiltrada);

		if(len >= 0)
		{
			for(i=0; i < len; i++)
			{
				pCachorro = ll_get(listaFiltrada,i);
				if(pCachorro != NULL)
				{
					ID_Cachorro = pCachorro->ID_Cachorro;
					strcpy(Nombre,pCachorro->Nombre);
					Dias = pCachorro->Dias;
					strcpy(Raza,pCachorro->Raza);
					strcpy(Reservado,pCachorro->Reservado);
					strcpy(Genero,pCachorro->Genero);
				}
				fprintf(pFileTexto,"%d,%s,%d,%s,%s,%s\n",ID_Cachorro,Nombre,Dias,Raza,Reservado,Genero);
			}
			retorno = 1;
		}
	}
		fclose(pFileTexto);
	    return retorno;
}
