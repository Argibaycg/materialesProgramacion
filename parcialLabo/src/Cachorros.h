#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

struct S_Cachorro
{
  int ID_Cachorro;
  char Nombre[128];
  int Dias;
  char Raza[128];
  char Reservado[128];
  char Genero[128];
};
typedef struct S_Cachorro Cachorro;

Cachorro* cachorro_new();
Cachorro* cachorro_newParametros(char* ID_Cachorro,char* Nombre,char* Dias,char* Raza,char* Reservado,char* Genero);
//void employee_delete();

int cachorros_setId(Cachorro* this,int id);
int cachorros_getId(Cachorro* this,int* id);

int cachorros_setNombre(Cachorro* this,char* nombre);
int cachorros_getNombre(Cachorro* this,char* nombre);

int cachorros_setDias(Cachorro* this,int dias);
int cachorros_getDias(Cachorro* this,int dias);

int cachorros_setRaza(Cachorro* this,char* raza);
int cachorros_getRaza(Cachorro* this,char* raza);

int cachorros_setReservado(Cachorro* this,char* reservado);
int cachorros_getReservado(Cachorro* this,char* reservado);

int cachorros_setGenero(Cachorro* this,char* genero);
int cachorros_getGenero(Cachorro* this,char* genero);

int cachorros_mayores45Dias(void* elemento);
int cachorros_machos(void* elemento);


#endif // EMPLEADO_H_INCLUDED


