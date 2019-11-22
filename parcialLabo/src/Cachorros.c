#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Parser.h"
#include "Cachorros.h"


/** \brief asigna espacio de memoria para un nuevo empleado
 * \return puntero del espacio de memoria
 */
Cachorro* cachorro_new(){

	Cachorro* cachorro = (Cachorro*)malloc( sizeof(Cachorro));

	if(cachorro != NULL)
	{
		cachorro->ID_Cachorro = 0;
		strcpy(cachorro->Nombre, "");
		cachorro->Dias = 0;
		strcpy(cachorro->Raza, "");
		strcpy(cachorro->Reservado, "");
		strcpy(cachorro->Genero, "");
	}
return cachorro;
}

/** \brief asigna espacio de memoria para em empleado y asigna por parametro los campos de la estructura
 * \param char* idStr
 * \param char* nombreStr
 * \param char* horasTrabajadasStr
 * \param char* sueldo
 * \return puntero del espacio de memoria
 */
Cachorro* cachorro_newParametros(char* ID_Cachorro,char* Nombre,char* Dias,char* Raza,char* Reservado,char* Genero)
{
	Cachorro* cachorro = cachorro_new();

	if(cachorro != NULL)
	{
		cachorros_setId(cachorro,atoi(ID_Cachorro));
		cachorros_setNombre(cachorro,Nombre);
		cachorros_setDias(cachorro,atoi(Dias));
		cachorros_setRaza(cachorro,Raza);
		cachorros_setReservado(cachorro,Reservado);
		cachorros_setGenero(cachorro,Genero);
	}
return cachorro;
}


/** \brief asigna el id al campo del empleado
 * \param Employee* this
 * \param int id
 * \return int
 */
int cachorros_setId(Cachorro* this,int id)
{
	int retorno = -1;

	if(this != NULL)
	{
		this->ID_Cachorro = id;
		retorno = 0;
	}

	return retorno;
}

/** \brief obtiene el id del campo del empleado
 * \param Employee* this
 * \param int id
 * \return int
 */
int cachorros_getId(Cachorro* this,int* id)
{
	int retorno = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->ID_Cachorro;
		retorno = 0;
	}

	return retorno;
}

/** \brief asigna el nombre al campo del empleado
 * \param Employee* this
 * \param char* nombre
 * \return int
 */
int cachorros_setNombre(Cachorro* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL)
	{
		strcpy(this->Nombre, nombre);
		retorno = 0;
	}

	return retorno;
}

/** \brief obtiene el nombre trabajadas del campo del empleado
 * \param Employee* this
 * \param char* nombre
 * \return int
 */
int cachorros_getNombre(Cachorro* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->Nombre);
		retorno = 0;
	}

	return retorno;

}

/** \brief asigna el nombre al campo del empleado
 * \param Employee* this
 * \param char* nombre
 * \return int
 */
int cachorros_setDias(Cachorro* this,int dias)
{
	int retorno = -1;

	if(this != NULL)
	{
		this->Dias = dias;
		retorno = 0;
	}

	return retorno;
}

/** \brief obtiene el nombre trabajadas del campo del empleado
 * \param Employee* this
 * \param char* nombre
 * \return int
 */
int cachorros_getDias(Cachorro* this,int dias)
{
	int retorno = -1;

	if(this != NULL)
	{
		dias = this->Dias;
		retorno = 0;
	}

	return retorno;
}
/** \brief asigna las horas trabajadas al campo del empleado
 * \param Employee* this
 * \param int horasTrabajadas
 * \return int
 */
int cachorros_setRaza(Cachorro* this,char* raza)
{
	int retorno = -1;

	if(this != NULL)
	{
		strcpy(this->Raza, raza);
		retorno = 0;
	}

	return retorno;
}

/** \brief obtiene las horas trabajadas del campo del empleado
 * \param Employee* this
 * \param int* horasTrabajadas
 * \return int
 */
int cachorros_getRaza(Cachorro* this,char* raza)
{
	int retorno = -1;

	if(this != NULL && raza != NULL)
	{
		strcpy(raza, this->Raza);
		retorno = 0;
	}

	return retorno;

}

/** \brief asigna el sueldo al campo del empleado
 * \param Employee* this
 * \param int sueldo
 * \return int
 */
int cachorros_setReservado(Cachorro* this,char* reservado)
{
	int retorno = -1;

	if(this != NULL)
	{
		strcpy(this->Reservado, reservado);
		retorno = 0;
	}

	return retorno;
}

/** \brief obtiene el sueldo del campo del empleado
 * \param Employee* this
 * \param int sueldo
 * \return int
 */
int cachorros_getReservado(Cachorro* this,char* reservado)
{
	int retorno = -1;

	if(this != NULL && reservado != NULL)
	{
		strcpy(reservado, this->Reservado);
		retorno = 0;
	}

	return retorno;

}

int cachorros_setGenero(Cachorro* this,char* genero)
{
	int retorno = -1;

	if(this != NULL && genero != NULL)
	{
		strcpy(this->Genero,genero);
		retorno = 0;
	}

	return retorno;
}

/** \brief obtiene el nombre trabajadas del campo del empleado
 * \param Employee* this
 * \param char* nombre
 * \return int
 */
int cachorros_getGenero(Cachorro* this,char* genero)
{
	int retorno = -1;

	if(this != NULL && genero != NULL)
	{
		strcpy(this->Genero,genero);
		retorno = 0;
	}

	return retorno;
}

int cachorros_mayores45Dias(void* elemento)
{
	int returnAux = -1;
	Cachorro* auxCachorro;
	auxCachorro = (Cachorro*) elemento;
	int dias;

	dias = auxCachorro->Dias;
	if(dias > 45)
	{
		returnAux = 1;
	}

	return returnAux;
}

int cachorros_machos(void* elemento)
{
	int returnAux = -1;
	Cachorro* auxCachorro;
	auxCachorro = (Cachorro*) elemento;

	if(strcmp(auxCachorro->Genero,"H") == 0)
	{
		returnAux = 1;
	}

	return returnAux;
}


