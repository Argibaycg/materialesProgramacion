#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "LinkedList.h"

int parser_parseCachorros(char* fileName, LinkedList* listaRevelados);
int generarArchivoFilter(char* fileName,LinkedList* listaFiltrada);

#endif // PARSER_H_INCLUDED
