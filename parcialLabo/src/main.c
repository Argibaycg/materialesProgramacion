#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cachorros.h"
#include "LinkedList.h"
#include "Parser.h"
#include "utn.h"

int main()
{
	int option;
	LinkedList* listaCachorros = ll_newLinkedList();
	LinkedList* listaMayoresde45Dias = NULL;
	LinkedList* listaMachos = NULL;

	do{
	    	 printf("Menu:\n"
	    	    	   "1. Cargar Archivo\n"
	    	    	   "2. Imprimir Lista\n"
	    			   "3. Filtrar menores de 45 Dias\n"
	    			   "4. Filtrar Machos\n"
	    			   "5. Generar lista Callejeros\n"
	    			   "6. Salir\n");

	    	 utn_getInt(&option);

	        switch(option)
	        {
	            case 1:
	            	if(listaCachorros != NULL)
	            	{
						if(parser_parseCachorros("cachorros.csv",listaCachorros)==1)
						{
							printf("Correcta Lectura de arhivos\n");
						}else
						{
							printf("Error leyendo archivo\n");
						}
	            	}
	                break;
	            case 2:
	            	imprimirListado(listaCachorros);
	            	break;
	            case 3:
	            	listaMayoresde45Dias = ll_filter(listaCachorros,cachorros_mayores45Dias);

	            	if(generarArchivoFilter("listaMayores45.csv",listaMayoresde45Dias)==1)
	            	{
	            		printf("Se guardo la lista en un archivo nuevo\n");
	            	}else
	            	{
	            		printf("No se puedo guardar la nueva lista\n");
	            	}
	            	break;
	            case 4:
	            	listaMachos = ll_filter(listaCachorros,cachorros_machos);

	            	if(generarArchivoFilter("listaMachos.csv",listaMachos)==1)
	            	{
	            		printf("Se guardo la lista en un archivo nuevo\n");
	            	}else
	            	{
	            		printf("No se puedo guardar la nueva lista\n");
	            	}
	            	break;
	            case 5:
	            	if(imprimirListadoCallejeros(listaCachorros)==-1)
	            	{
	            		printf("No se pudo imprimir");
	            	}
	            	break;
	            case 6:

	            	break;
	        }
	    }while(option != 6);


	return 0;

}

