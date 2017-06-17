/*gym.h*/
#include "gimm.h"

void main(){
  contacte p[MAX_AGENDA];/*definimos la cantidad maxima del tipo contacto*/
  dades n[MAX_AGENDA];
  int opcion;
  int cont;
  cont=0;
  cont=recuperarFitxer(p, MAX_AGENDA ,"users.txt",sizeof(contacte));
  cont=recuperarFitxer(n, MAX_AGENDA ,"datos.txt",sizeof(dades));

  do{/*iniciamos el bucle*/

    opcion=menu();/*Llamando el menu*/
    switch (opcion){/*Y el switch con las opciones elegidas*/
      case 1:
        loop(p,n,&cont);/*Llamando la funcion de introduccion de datos*/
        break;
      case 2:
        usuario(p,n,&cont);
        break;
      case 3:
        printf("\tAdeu!!!\n");/*Un mensajillo de salida*/
        break;
      default:
        printf("\tOpció Incorrecta!\n");/*y un mensaje default para cuando se equivoque el usuariio*/
        break;
    }
  }while (opcion != 3);/*aqui tenemos la condicion de salida que es la que mostramos en el menu*/
}
