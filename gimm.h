//gimm.h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "fitxer.h"

/*LLamamos tambien las funciones de string, por si las moscas*/
#define MAX_NOM 50
#define MAX_TLF 10
#define MAX_AGENDA 20
#define MAX_DNI 10
#define MAX_APELLIDO 16
#define MAX_PASS 10
                 
typedef struct {
  char nom[MAX_NOM];
  char tlf[MAX_TLF];
  char dni[MAX_DNI];
  char pass[MAX_PASS];
  char last_login[500];
}contacte;
/*definimos como sera el tipo contacto, las diferentes variables que tendremos*/
typedef struct {
  int edat;
  int pes;
  int alt;
}dades; 

int menu();
int mostrar_menu();
int menu2();
void ordenar(contacte p[MAX_AGENDA], dades n[MAX_AGENDA], int cont);
void listar(contacte p[MAX_AGENDA],dades n[MAX_AGENDA], int cont);
int mostrar_user(contacte p[MAX_AGENDA],dades n[MAX_AGENDA], int *pcont);
char* tiempo();
void Introducir(contacte p[MAX_AGENDA], dades n[MAX_AGENDA], int * pcont);
void borrar(contacte p[MAX_AGENDA], dades n[MAX_AGENDA], int *pcont);
void buscar(contacte p[MAX_AGENDA],dades n[MAX_AGENDA], int cont);
void modificar (contacte p[MAX_AGENDA],dades n[MAX_AGENDA], int *pcont);
void mod_user(contacte p[MAX_AGENDA],dades n[MAX_AGENDA], int *pcont);
void usuario(contacte p[MAX_AGENDA], dades n[MAX_AGENDA], int *pcont);
void index_massa(contacte p[MAX_AGENDA], dades n[MAX_AGENDA], int *pcont);
void grutina();
void dietes(contacte p[MAX_AGENDA], dades n[MAX_AGENDA], int *pcont);
void loop2(contacte p[MAX_AGENDA], dades n[MAX_AGENDA], int *pcont);
void loop(contacte p[MAX_AGENDA], dades n[MAX_AGENDA], int *pcont);
