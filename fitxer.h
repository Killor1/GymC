/* fitxer.h
   programa auxiliar per desar informació en fitxers */

#include <stdio.h>

#define MAX_FILE 256

/* Acció que desa un fitxer al directori on s'executa el programa
	void * list -> s'ha de passar la taula que conté la informació: p.ex. agenda,
	int elemenents -> s'ha de passar el nombre d'elements que ocupen la taula: p.ex. elements,
	char fileName[MAX_FILE], -> s'ha de passar el nom que voleu que tingui el fitxer: p. ex. "agenda.dat"
	int size -> s'ha de passar la mida del tipus que ocupa la taula: p.ex. sizeof(contacte)
	així en l'exemple es cridaria:
	desarFitxer(agenda, elements ,"agenda.dat",sizeof(contacte));	*/
void desarFitxer(void * list,int el,char fileName[MAX_FILE],int size);



/* Funció que recupera a la llista els tipus recuperats i retorna el nombre que ha recuperat:
	void * list -> s'ha de passar la taula que conté la informació: p.ex. agenda,
	int MAX -> s'ha de passar el nombre m'àxim d'elements que pot tenir la taula: p.ex. MAX_AGENDA,
	char fileName[MAX_FILE], -> s'ha de passar el nom del fitxer d'on es volen recuperar les dades: p. ex. "agenda.dat"
	int size -> s'ha de passar la mida del tipus que ocupa la taula: p.ex. sizeof(contacte)
	així en l'exemple es cridaria:
	elements=recuperarFitxer(agenda, MAX_AGENDA ,"agenda.dat",sizeof(contacte));	*/
int recuperarFitxer(void * list,int MAX, char fileName[MAX_FILE], int size);

