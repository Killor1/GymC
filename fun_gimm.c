#include "gimm.h"

int menu(){
  int op2;
  
  printf("\n");
  printf("\n\t\t============================\n");
  printf("\t\t|      MENU PRINCIPAL      |");
  printf("\n\t\t============================\n");
  printf("\t\t| 1 | Gestor de dades      |\n");
  printf("\t\t| 2 | Entrenador Personal  |\n");
  printf("\t\t| 3 | Sortir               |\n");
  printf("\t\t============================\n");
  printf("\t\tTria una opció: ");
  scanf ("%d%*c", &op2);/*Tenemos que poner el %*c para que no nos lea el salto de llinea como caracter*/
  return op2;
}
int mostrar_menu(){/*defino void, el nombre de la funcion, y a continuacion la desarrollo*/
  int op;/*la variable para leer la opcion de menu*/

  
  printf("\n");
  printf("\n\t\t==========================\n");
	printf("\t\t|      GESTOR DADES      |");
  printf("\n\t\t==========================\n");
	printf("\t\t| 1 | Introduïr usuari   |\n");
	printf("\t\t| 2 | Esborrar usuari    |\n");
	printf("\t\t| 3 | Mostrar usuaris    |\n");
	printf("\t\t| 4 | Cercar usuari      |\n");
	printf("\t\t| 5 | Modificar usuari   |\n");
	printf("\t\t| 6 | Enrere             |\n");
  printf("\t\t==========================\n");
	printf("\t\tTria una opció: ");
  scanf ("%d%*c", &op);/*Tenemos que poner el %*c para que no nos lea el salto de llinea como caracter*/
  return op;
}/*Funcion para mostrar el menu y leer la opcion*/
int menu2(){
  int op1;

  printf("\n");
  printf("\n\t\t=============================\n");
  printf("\t\t|    ENTRENADOR PERSONAL    |");
  printf("\n\t\t=============================\n");
  printf("\t\t| 1 | Modificar meves dades |\n");
  printf("\t\t| 2 | Mostrar usuari        |\n");
  printf("\t\t| 3 | IMC                   |\n");
  printf("\t\t| 4 | Dietes                |\n");
  printf("\t\t| 5 | Rutines               |\n");
  printf("\t\t| 6 | Enrere                |\n");
  printf("\t\t=============================\n");
  printf("\t\tTria una opció: ");
  scanf ("%d%*c", &op1);/*Tenemos que poner el %*c para que no nos lea el salto de llinea como caracter*/
  return op1;

}/*Esta funcion muestra el segundo menu para usuarioos*/
void ordenar(contacte p[MAX_AGENDA], dades n[MAX_AGENDA], int cont){/*Esta funcion ha de recorrer dos fors,*/ 
  int i=0;
  int j=0;
  contacte paux;/*El contacto auxiliar que usaremos para guardar al ordenar*/
  dades naux;
  for (j=0; j<cont;j++){/*uno para los contactos por el eje de las j, */
     for (i=0; i<cont;i++){/*y el otro para eje i*/
        if ((strcmp(p[i].nom,p[j].nom))>0){/*Aqui comparamos, si el valor del campo del eje i menos el del eje j
        es mayor que cero consideraremos que tenemos que cambiarlos(esto es probar con < o > y ver como ordena si
        ascendente o descente y entonces decimos como cambiar)*/ 
        paux=p[j];/*Primero paso el valor de j a una auxiliar para no perderla*/
        p[j]=p[i];/*Ahora le digo que el valor de i tendria que ir donde la j*/
        p[i]=paux;/*y recuperamos el valor de j antiguo para ponerlo en el i ordenado*/
        naux=n[j];
        n[j]=n[i];
        n[i]=naux;
        }    
      }
  }
}/*Funcion para ordenar la agenda*/
void listar(contacte p[MAX_AGENDA],dades n[MAX_AGENDA], int cont){/*Esta funcion solo se encarga de pintar los datos en la pantalla*/
  int i=0;
  int j=0;
  for (j=0; j<cont;j++){/*solo hace falta un bucle que recorra de cero hasta el contador de contactos*/
    printf("\n");
    printf("\tUsuari %d:\n",j+1);/*como j parte de cero, le decimos j+1 para poder poner un contador de contactos al mostrarlos*/
    printf("\tNom: %s \n\tTlf: %s \n\tDni: %s \n",p[j].nom,p[j].tlf,p[j].dni);/*y ponemos los datos que queremos imprimir, en columna mejor que en filas para */
    printf("\tEdat: %d \n\tPes: %d \n\tAltura: %d \n",n[j].edat, n[j].pes,n[j].alt); /*tener menos problemas de tabulacion y para que quede mmejor*/
  }
  j = 0;/*antes del cierre de la funcion reinicio el contador de j's para que no de problemas despues*/
}/*Funcion que muestra la agenda por pantalla*/
int mostrar_user(contacte p[MAX_AGENDA],dades n[MAX_AGENDA], int *pcont){
    int contador;
    contador=*pcont;
    printf("\n");
    printf("\tUsuari %d:\n",contador);/*como j parte de cero, le decimos j+1 para poder poner un contador de contactos al mostrarlos*/
    printf("\tNom: %s \n\tTlf: %s \n\tDni: %s \n",p[contador-1].nom,p[contador-1].tlf,p[contador-1].dni);/*y ponemos los datos que queremos imprimir, en columna mejor que en filas para */
    printf("\tEdat: %d \n\tPes: %d \n\tAltura: %d \n",n[contador-1].edat, n[contador-1].pes,n[contador-1].alt); /*tener menos problemas de tabulacion y para que quede mmejor*/
}
/*void guardar_datos(contacte p[MAX_AGENDA], dades n[MAX_AGENDA], int *pcont){
  
    int contador;
    contador=*pcont;
    FILE *ptr; //inicializaremo una variable a archivo como apuntador
    ptr=fopen("/home/manu/Escritorio/datos.sql","a");
    
    fprintf(ptr,"\nUsuario %d,%s,%s,%s,%s,%s,%s",contador, p[contador].nom,p[contador].tlf,p[contador].dni, p[contador].pass, p[contador].sexe, p[contador].last_login);
    
    fclose(ptr);
}*/

char* tiempo() {

        time_t tiempo = time(0);
        struct tm *tlocal = localtime(&tiempo);
        char output[128];
        strftime(output,128,"%d/%m/%y ",tlocal);
        
        return output;
}
  void Introducir(contacte p[MAX_AGENDA], dades n[MAX_AGENDA], int * pcont){ 
   int contador;
   contador=*pcont;
   int i=0;
   int j=0; 
  

  if (contador==MAX_AGENDA){/*Primero vemos si la agenda esta llena*/
    printf("\n");
    printf("\tEl servidor és ple!\n");/*Y lanzamos el mensaje de aviso si es el caso*/    
  }
  else{/*En el caso que quepan mas contactos: */
    printf("\n");
    printf("\tIntrodueix el nom de l'usuari: ");/*Pedimos el nombre del contacto*/
    scanf ("%[^\n]%*c", (char*) &p[contador].nom);/* %[^\n]%*c es la orden para que coja tanto el espacio para los nombres compuestos*/
    printf("\tIntrodueix el telèfon de l'usuari: ");/*como para obviar el intro en la entrada del caracter y no duplique cosas*/
    scanf ("%[^\n]%*c", (char*) &p[contador].tlf);/*En este aunque en teoria son numeros, lo ponemos tmb para ahorrar problemas*/
    printf("\tIntrodueix el DNI de l'usuari: ");/*como para obviar el intro en la entrada del caracter y no duplique cosas*/
    scanf ("%[^\n]%*c", (char*) &p[contador].dni);/*En este aunque en teoria son numeros, lo ponemos tmb para ahorrar problemas*/
    printf("\tIntrodueix l'edat de l'usuari: ");/*como para obviar el intro en la entrada del caracter y no duplique cosas*/
    scanf ("%d%*c", &n[contador].edat);/*En este aunque en teoria son numeros, lo ponemos tmb para ahorrar problemas*/
    printf("\tIntrodueix el pes de l'usuari (kg): ");/*como para obviar el intro en la entrada del caracter y no duplique cosas*/
    scanf ("%d%*c", &n[contador].pes);/*En este aunque en teoria son numeros, lo ponemos tmb para ahorrar problemas*/
    printf("\tIntrodueix l'altura de l'usuari (cm): ");
    scanf ("%d%*c", &n[contador].alt);
    printf("\tIntrodueix la contrassenya per l'usuari: ");
    scanf ("%[^\n]%*c", (char*) &p[contador].pass);
    strcpy(p[contador].last_login,tiempo());
    
    contador=contador+1;
    system ("clear");
       desarFitxer(p,contador ,"users.txt",sizeof(contacte));
        desarFitxer(n,contador ,"datos.txt",sizeof(dades));
    *pcont=contador;
  }
}/*Funcion para introducir los contactos*/
void borrar(contacte p[MAX_AGENDA], dades n[MAX_AGENDA], int *pcont){
        char conf;
        int i=0;
        int j=0;
        char busc[MAX_NOM];
        int contador;
        contador=*pcont;
       
        printf("\n\tCerca l'usuari que vols esborrar\n");
        printf("\tIntrodueix el nom de l'usuari: ");
        scanf("%[^\n]%*c", (char*)&busc);/*pedimos el nombre de lo que querremos borrar y lo metemos en la variable de busqueda*/
        while(i<=contador && strcmp(busc,p[i].nom)!=0){/*Y arrancamos un bucle que haga la busqueda sobre los contactos de la agenda*/
        i=i+1;/*con su iteraador correspondiente*/
        }
          if (strcmp (busc, p[i].nom) == 0){/*Aqui decimos que si encuentra un campo.nom igual a lo que pusimos en el buscador*/
            printf("\tNom: %s \n\tTlf: %s \n\tDni: %s \n",p[i].nom,p[i].tlf,p[i].dni);/*y ponemos los datos que queremos imprimir, en columna mejor que en filas para */
            printf("\tEdat: %d \n\tPes: %d \n\tAltura: %d \n",n[i].edat, n[i].pes,n[i].alt); /*tener menos problemas de tabulacion y para que quede mmejor*/
            printf ("\tVols esborrar aquest usuari? [s/n]:");
            scanf ("%c%*c",&conf);/*Y pedimos la confirmacion de si ha de ser borrado o no*/
              if ((conf =='s') || (conf == 'S')){/*si la respuesta es si:   */
                for (j=i+1; j<=contador; j++){/*creamos este bucle para que bnos vaya moviendo los contactos el de arriba a uno menos...*/
                p[j-1]=p[j];/*por eso decimos que nos copie el j+1 en la posicion del j*/
                n[j-1]=n[j];
                printf("Usuari Esborrat!\n");
                contador=contador-1;/*y le restamos uno al contador para que quede constancia ahi que hemos quitado un contacto*/
                }
              }
          } 
          else{ /*si no lo encontrase..........*/
              printf("\tUsuari inexistent!\n");/*Le damos el aviso al usuario*/
          } 
          i=0;
          j=0;
             desarFitxer(p,contador ,"users.txt",sizeof(contacte));
        desarFitxer(n,contador ,"datos.txt",sizeof(dades)); 
          *pcont=contador;
            
}/*Funcion para borrar un contacto de la agenda*/
void buscar(contacte p[MAX_AGENDA],dades n[MAX_AGENDA], int cont){
  char busc[MAX_NOM];
  int k=0;
  int trobat=0;
  
  printf("\tIntrodueix el nom de l'usuari: ");/*pedimos el contacto a buscar*/
  scanf("%[^\n]%*c", (char*) &busc);
  k=0;/*y leemos la entrada de datos en la variable tmb con el %[^\n]%*c para coger los compuestos sin problemas*/ 
            while((k != cont) && (strcmp (busc, p[k].nom) != 0)){
            k=k+1;/*Hacemos un bucle con las condiciones de salida que llegue al maximo de la agenda, o que la*/
            }
           if (strcmp (busc, p[k].nom) == 0){/*variable de busqueda sea cero. En este if comprobamos si lo que hemos puesto en el buscador es igual*/
               printf("\tNom: %s \n\tTlf: %s \n\tDni: %s \n",p[k].nom,p[k].tlf,p[k].dni);/*y ponemos los datos que queremos imprimir, en columna mejor que en filas para */
                printf("\tEdat: %d \n\tPes: %d \n\tAltura: %d\n",n[k].edat, n[k].pes,n[k].alt); /*tener menos problemas de tabulacion y para que quede mmejor*/
               trobat = 1;/*decimos que nuestro buscador ha cambiado a uno para que nos saque del bucle*/
           }
          else{/*Aqui es la condicion por la cual si no encuentra el nombre que buscamos, nps imprime el aviso en pantalla*/
            printf("\n\tNo s'ha trobat l'usuari introduït.\n");/*de que no lo ha encontrado*/
          }
}/*Funcion para buscar un contacto de la agenda*/
void modificar (contacte p[MAX_AGENDA],dades n[MAX_AGENDA], int *pcont){
   char conf;
   char campo;
   int i=0;
   int j=0;
   char busc[MAX_NOM];
   int contador;
   contador=*pcont;

        printf("\n\tTroba l'usuari que vols modificar:\n");
        printf("\tIntrodueix el nom de l'usuari:"" ");
        scanf("%[^\n]%*c", (char*)&busc);/*pedimos el nombre de lo que querremos borrar y lo metemos en la variable de busqueda*/
        while(i<=contador && strcmp(busc,p[i].nom)!=0){/*Y arrancamos un bucle que haga la busqueda sobre los contactos de la agenda*/
        i=i+1;/*con su iteraador correspondiente*/
        }
          if (strcmp (busc, p[i].nom) == 0){/*Aqui decimos que si encuentra un campo.nom igual a lo que pusimos en el buscador*/
            printf("\tNom: %s \n\tTlf: %s \n\tDni: %s \n",p[i].nom,p[i].tlf,p[i].dni);/*y ponemos los datos que queremos imprimir, en columna mejor que en filas para */
             printf("\tEdat: %d \n\tPes: %d \n\tAltura: %d\n",n[i].edat, n[i].pes,n[i].alt); /*tener menos problemas de tabulacion y para que quede mmejor*/
            printf ("\tVols modificar aquest usuari? [s/n]:");
            scanf ("%c%*c",&conf);/*Y pedimos la confirmacion de si ha de ser borrado o no*/
                if ((conf =='s') || (conf == 'S')){/*si la respuesta es si:   */
                   printf("Quin valor vols modifcar? [Nom(n) - Tlf(t) - DNI(d) - Edat(e) - Pes(p) - Alt(a)]: ");
                   scanf ("%c%*c",&campo);
                   switch (campo){
                    case 'n':
                     printf("Quin serà el nou nom? \n");
                     scanf ("%[^\n]%*c", (char*) &p[i].nom);
                     ordenar(p,n,contador);
                     break;
                    case 't':
                     printf("Quin serà el nou telefon? \n");
                     scanf ("%[^\n]%*c", (char*) &p[i].tlf);  
                     break;
                    case 'd':
                     printf("Quin serà el nou dni? \n");
                     scanf ("%[^\n]%*c", (char*) &p[i].dni);
                     break;
                    case 'e':
                     printf("Quina serà la nova edat? \n");
                     scanf ("%d%*c",&n[i].edat);
                     break;
                    case 'p':
                     printf("Quin serà el nou pes? \n");
                     scanf ("%d%*c",&n[i].pes);
                     break;
                    case 'a':
                     printf("Quina serà la nova altura? \n");
                     scanf ("%d%*c",&n[i].alt);
                     break;
                    default:
                     printf("Opció incorrecta!\n");
                  }
                }
                 else{
                  printf("Usuari no modificat!\n");
              }
          } 
          else{ /*si no lo encontrase..........*/
              printf("\tUsuari inexistent!\n");/*Le damos el aviso al usuario*/
          } 
          i=0;
          j=0; 
             desarFitxer(p,contador ,"users.txt",sizeof(contacte));
        desarFitxer(n,contador ,"datos.txt",sizeof(dades));
          *pcont=contador;
}/*Funcion para modificar los datos desde el menu principal.*/
void mod_user(contacte p[MAX_AGENDA],dades n[MAX_AGENDA], int *pcont){

  
   char campo;
   int contador;
   contador=*pcont;

     printf("Quin valor vols modifcar? [Nom(n) - Tlf(t) - DNI(d) - Edat(e) - Pes(p) - Alt(a)]: ");
     scanf ("%c%*c",&campo);
     switch (campo){
      case 'n':
       printf("Quin serà el nou nom? ");
       scanf ("%[^\n]%*c", (char*) &p[contador-1].nom);
       break;
      case 't':
       printf("Quin serà el nou telèfon? ");
       scanf ("%[^\n]%*c", (char*) &p[contador-1].tlf);  
       break;
      case 'd':
       printf("Quin serà el nou DNI? ");
       scanf ("%[^\n]%*c", (char*) &p[contador-1].dni);
       break;
      case 'e':
       printf("Quina serà la nova edat? ");
       scanf ("%d%*c",&n[contador-1].edat);
       break;
      case 'p':
       printf("Quin serà el nou pes? ");
       scanf ("%d%*c",&n[contador-1].pes);
       break;
      case 'a':
       printf("Quina serà la nova altura? ");
       scanf ("%d%*c",&n[contador-1].alt);
       break;
      default:
       printf("Opció incorrecta!\n");
    }
    desarFitxer(p,contador ,"users.txt",sizeof(contacte));
        desarFitxer(n,contador ,"datos.txt",sizeof(dades));   
}
void usuario(contacte p[MAX_AGENDA], dades n[MAX_AGENDA], int *pcont){ 
  int contador;
  contador=*pcont;
  char busc[MAX_NOM];
  int k=0;
  char conf;
  char passconf[MAX_PASS];

    printf("Introdueix el nom amb el cual iniciar la sessió de l'entrenador personal: ");
    scanf("%[^\n]%*c", (char*)&busc);/*pedimos el nombre de lo que querremos borrar y lo metemos en la variable de busqueda*/
         while((k != contador) && (strcmp (busc, p[k].nom) != 0)){
            k=k+1;/*Hacemos un bucle con las condiciones de salida que llegue al maximo de la agenda, o que la*/
            }
            if (strcmp (busc, p[k].nom) == 0){/*Aqui decimos que si encuentra un campo.nom igual a lo que pusimos en el buscador*/
              printf("\tNom: %s \n\tTlf: %s \n\tDni: %s \n",p[k].nom,p[k].tlf,p[k].dni);/*y ponemos los datos que queremos imprimir, en columna mejor que en filas para */
              printf("\tEdat: %d \n\tPes: %d \n\tAltura: %d\n",n[k].edat, n[k].pes,n[k].alt); /*tener menos problemas de tabulacion y para que quede mmejor*/
              printf("Vols iniciar sessió per aquest usuari? [s-n]: ");
              scanf ("%c%*c",&conf);
              if ((conf=='s') || (conf=='S')){
                printf("Introdueix la contrassenya per al teu usuari: ");
                scanf("%[^\n]%*c", &passconf);
                if (strcmp (passconf, p[k].pass) == 0){
                  loop2(p,n,pcont);
                }
                else{
                  printf("Contrasenya errònia!\n");
                }
              }
              else {
                system ("clear");
                menu();
              }
            }
           else{
            printf("Usuari no trobat!\n");
           }
}/*Esta funcion hace la entrada para la sesion de usuario para la opcion seis*/
void index_massa(contacte p[MAX_AGENDA], dades n[MAX_AGENDA], int *pcont){
  float imc;
  int contador;
  contador=*pcont;
  int pesact;

  printf("\nIntrodueix el teu pes actual: ");
  scanf ("%d%*c",&pesact);
  n[contador-1].pes=pesact;
  float alturacien = 0;
  alturacien =  ((float)n[contador-1].alt/100);
  float alturacuadrado = 0;
  alturacuadrado = (alturacien*alturacien);
  //printf("alturacuadrado: %g\n", alturacuadrado);
  //printf("alturacien: %g\n",alturacien);
  imc = (pesact / alturacuadrado);
  printf("El teu index de massa corporal, %s, és:  %.2f.\n",p[contador-1].nom, imc);
  if (imc < 16){
      printf("Vosté te un problema de primesa severa!\n");
  }
  if ((imc>=16) && (imc<=16.99)){
      printf("Vosté pateix primesa moderada.\n");
  }
  if ((imc>=17) && (imc<=18.49)){
      printf("Vosté pateix primesa lleu.\n");
  }
  if ((imc>=18.5) && (imc<=24.99)){
      printf("Vosté té un pes normal.\n");
  }
  if ((imc>=25) && (imc<=29.99)){
      printf("Vosté és preobes, vigileu!!.\n");
  }
  if ((imc>=30) && (imc<=34.99)){
      printf("Vosté pateix obesitat lleu.\n");
  }
  if ((imc>=35) && (imc<=39.99)){
      printf("Vosté pateix obesitat mitja.\n");
  }
  if (imc>=40){
      printf("Vosté pateix obesitat mórbida, hauria de visitar un especialista!.\n");
  }
}
void grutina(){/*Genera una rutina en base a los dias a la semana que ira .*/
 
  char opcion;
  int ndias;
  int i=0;
   
    char p1[10]="Pit";
    char p2[10]="Esquena"; 
    char p3[10]="Braç";
    char p4[10]="Cama";
    char p5[10]="Glutis" ;
    char p6[10]="Abdomen";
    char p7[10]="Espatlla";

   do{/*iniciamos el bucle*/
      printf("\n");
      printf("                          Generant Rutina Setmanal\n");
      printf("          ======================================================\n");
      printf("                              Instruccions : \n");
      printf("                  Seleccionar d' 2-6 dias a la setmana . \n");
      printf("                     Si vols sortir pressiona 7 \n" );
      printf("          ======================================================\n");
      printf("             Escriure quants dies assistirà durant la setmana: ");
      scanf("%d",&ndias);
 
  switch (ndias){/*Y el switch con las opciones elegidas*/
       case 2:
            printf("\n");
            printf("Rutina Setmanal:");                      
            printf("\n");
            printf("                      Dia 1:"); 
            printf("    %s,%s,%s,%s\n",p2,p1,p6,p7);
            printf("                      Dia 2:"); 
            printf("    %s,%s,%s\n",p3,p4,p5);
            break;
       case 3:
            printf("\n");
            printf("Rutina Setmanal:");                      
            printf("\n");
            printf("                      Dia 1:"); 
            printf("    %s,%s,%s\n",p2,p1,p6);
            printf("                      Dia 2:"); 
            printf("    %s,%s\n",p3,p7);
            printf("                      Dia 3:"); 
            printf("    %s,%s\n",p4,p5);
            break;
       case 4:
            printf("\n");
            printf("Rutina Setmanal:");          
            printf("                      Dia 1:"); 
            printf("    %s,%s\n",p2,p1);
            printf("                      Dia 2:"); 
            printf("    %s,%s\n",p6,p7);
            printf("                      Dia 3:"); 
            printf("    %s,%s\n",p3,p5);
            printf("                      Dia 4:"); 
            printf("    %s\n",p4);
            break;
       case 5:
            printf("\n");
            printf("Rutina Setmanal:");                      
            printf("                      Dia 1:"); 
            printf("    %s,%s\n",p2,p1);
            printf("                      Dia 2:"); 
            printf("    %s,%s\n",p3,p7);
            printf("                      Dia 3:"); 
            printf("    %s,%s\n",p4,p5);
            printf("                      Dia 4:"); 
            printf("    %s\n",p6);
            printf("                      Dia 5:"); 
            printf("    Entrenament lliure \n");
            break; 
       case 6:
            printf("\n");
            printf("Rutina Setmanal:");                      
            printf("                      Dia 1:"); 
            printf("    %s,%s\n",p2,p1);
            printf("                      Dia 2:"); 
            printf("    %s\n",p6);
            printf("                      Dia 3:"); 
            printf("    %s,%s\n",p3,p7);
            printf("                      Dia 4:"); 
            printf("    Entrenament lliure \n");
            printf("                      Dia 5:"); 
            printf("    %s,%s\n",p4,p5);
            printf("                      Dia 6:"); 
            printf("    Entrenament lliure \n");
            break;
       case 7:
            printf("\tAdeu!!!\n");/*Un mensajillo de salida*/
            opcion=7;
            break;
        default:
          printf("\tOpció Incorrecta!!\n");/*y un mensaje default para cuando se equivoque el usuariio*/
          break;
      }
 
  }
    while (opcion != 7);/*aqui tenemos la condicion de salida que es la que mostramos en el menu*/
}
void loop2(contacte p[MAX_AGENDA], dades n[MAX_AGENDA], int *pcont){
  int cont = 0;
  cont = *pcont;  
  int opcion1;

  do{

  opcion1=menu2();
  switch (opcion1){
    case 1:
      mod_user(p,n,&cont); //modificar el usuario (se podra reutilizar esta funcion manuel?)
      break;
    case 2:
      system("clear");
      mostrar_user(p,n,&cont); //no sé si es esta la funcion de mostrar usuario, peroe stá declarada y por usarla la aprovecho
      break;
    case 3:
      index_massa(p,n,&cont); //funcion index_massa, funciona esta tambien?
    case 4:
      //dietas() no habia una hecha por lo que dejo esto de placeholder
      break;
    case 5:
      grutina();
      break;
    case 6:
      printf("Desconectant.\n");
      printf("Tornant al menú principal.\n");
      system("clear");
      // volvemos al menú de antes, simplemente saliendo de este
      break;
    default:
      printf("\tOpció Incorrecta!\n");/*y un mensaje default para cuando se equivoque el usuariio*/
        break;  
    }
  }
  while(opcion1 != 6);
}  
void loop(contacte p[MAX_AGENDA], dades n[MAX_AGENDA], int *pcont){/*Ahora que hemos creado nuestras funciones, vamos al cuerpo del programa, ell main*/
  char option;
  int cont = 0;
  cont = *pcont;
  int opcion;
  
  do{/*iniciamos el bucle*/

    opcion=mostrar_menu();/*Llamando el menu*/
    switch (opcion){/*Y el switch con las opciones elegidas*/
      case 1:
        Introducir(p,n,&cont);/*Llamando la funcion de introduccion de datos*/
        break;
      case 2:
        borrar(p,n,&cont);/*la de borrado*/
        system ("clear");
        break;
      case 3:
        system ("clear");
        listar(p,n,cont);/*listado*/
        break;
      case 4:
       buscar(p,n,cont);/*busqueda*/
       break;
      case 5:
        modificar(p,n,&cont); 
        break;       
      case 6:
        system ("clear");
        desarFitxer(p,cont ,"users.txt",sizeof(contacte));
        desarFitxer(n,cont ,"datos.txt",sizeof(dades));
        printf("\tAdeu!!!\n");/*Un mensajillo de salida*/
        break;
      default:
        printf("\tOpció Incorrecta!\n");/*y un mensaje default para cuando se equivoque el usuariio*/
        break;
    }
  }
  while (opcion != 6);/*aqui tenemos la condicion de salida que es la que mostramos en el menu*/
}
void dietes(contacte p[MAX_AGENDA], dades n[MAX_AGENDA], int *pcont){
  float imc;
  int contador;
  contador=*pcont;
  int pesact;
 
  printf("\nIntrodueix el teu pes actual: ");
  scanf ("%d%*c",&pesact);
  n[contador-1].pes=pesact;
  float alturacien = 0;
  alturacien =  ((float)n[contador-1].alt/100);
  float alturacuadrado = 0;
  alturacuadrado = (alturacien*alturacien);
  //printf("alturacuadrado: %g\n", alturacuadrado);
  //printf("alturacien: %g\n",alturacien);
  imc = (pesact / alturacuadrado);
  printf("El teu index de massa corporal, %s, és:  %.2f.\n",p[contador-1].nom, imc);
  if (imc < 16){
      printf("Vosté te un problema de primesa severa!\n");
  }
  if ((imc>=16) && (imc<=16.99)){
      printf("Vosté pateix primesa moderada.\n");
  }
  if ((imc>=17) && (imc<=18.49)){
      printf("Vosté pateix primesa lleu.\n");
  }
  if ((imc>=18.5) && (imc<=24.99)){
      printf("Vosté té un pes normal.\n");
  }
  if ((imc>=25) && (imc<=29.99)){
      printf("Vosté és preobes, vigileu!!.\n");
  }
  if ((imc>=30) && (imc<=34.99)){
      printf("Vosté pateix obesitat lleu.\n");
  }
  if ((imc>=35) && (imc<=39.99)){
      printf("Vosté pateix obesitat mitja.\n");
  }
  if (imc>=40){
      printf("Vosté pateix obesitat mórbida, hauria de visitar un especialista!.\n");
  }
 
  if(imc<18.5){
    printf("Dieta para puyar pes:\n");
    printf("--------------------------------------------------------------------------------------\n");
    printf("- Totes les fruites i verdures que vulguis i de 2 a 3 litres d'aigua.\n");
    printf("Seleccionar 2 del següents platerets sense repetir :\n");
    printf("desdejuni:\n");
    printf("Torrada de pa amb formatge fresc\n");
    printf("truita de 3 ous, pebrot, ceba i formatge\n");
    printf("llet amb civada\n");
    printf("torrades de pa integral amb mantega i mel\n");
    printf("poma\n");
    printf("platan\n");
    printf("--------------------------------------------------------------------------------------\n");
    printf ("menjar:\n");
    printf ("filet amb verdura i arròs\n");
    printf ("pollastre a la planxa amb patates\n");
    printf ("llenties amb arròs i patates\n");
    printf ("filet amb verdura\n");
    printf ("cigrons amb espinacs\n");
    printf ("carn amb amanida\n");
    printf("--------------------------------------------------------------------------------------\n");
    printf ("Sopar:\n");
    printf("pescado a la plancha \n");
    printf("ensalada grande de atun\n");
    printf("pescado con ensadala\n");
    printf("salmon a la plancha\n");
    printf("ensalada de aguacate y tomate cherry\n");
 
  }
 
else if(imc>=18.5 && imc <26)
  {
    printf("Dieta para mantener el peso\n");
    printf("--------------------------------------------------------------------------------------\n");
    printf("- Totes les fruites i verdures que vulguis i de 2 a 3 litres d'aigua.\n");
    printf("- Evitar menjar greixos i carbohidrats\n");
    printf("Seleccionar 2 del següents platerets sense repetir :\n");
    printf("desdejuni\n");
    printf("Torrada de pa amb formatge fresc\n");
    printf("torrada de pa amb jamon serrà o gall dindi\n");
    printf("1 tazon de cereals\n");
    printf("1 peça de fruita\n");
    printf("torrada de pa amb melmelada\n");
    printf("--------------------------------------------------------------------------------------\n");
    printf ("menjar:\n");
    printf("amanida mixta (tomàquet enciam ceba cogombre) \n");
    printf("filet de *atun a la planxa\n");
    printf("crema de *calabacin\n");
    printf("filet de vedella a la planxa amb amanida d'enciam\n");
    printf("amanida de tomàquet amb anxoves i formatge\n");
    printf("gall dindi al forn\n");
    printf("arròs amb pollastre i verdures\n");
    printf("--------------------------------------------------------------------------------------\n");
    printf ("sopar:\n");
    printf ("verdures al forn (albergínia , *calabacin i pebrot)\n");
    printf ("crema de verduraz\n");
    printf ("bledes\n");
    printf ("atun a la planxa\n");
    printf ("pit de pollastre de pollastre a la planxa\n");
 
  }
else
  {
    printf("                      Dieta para bajar de peso\n");
    printf("--------------------------------------------------------------------------------------\n");
    printf("    A la setmana menjar: \n" );
    printf("- Mig got de llet semi desnatada per al te i el cafè ( 115cals , 4 grams de greix ) \n");
    printf("- Totes les fruites i verdures que vulguis i de 2 a 3 litres d'aigua.\n");
    printf("- Evitar menjar greixos i carbohidrats\n");
    printf(" Seleccionar 2 dels següents platerets sense repetir :\n");    
    printf("desdejuni\n");
    printf("suc d'aranja\n");
    printf("1 o 2 mandarines\n");
    printf("iogurt baix en greixos \n");
    printf("2 galetes integrals\n");
    printf("dinariscota amb york\n");
    printf("cafe amb llet descremada\n");
    printf("--------------------------------------------------------------------------------------\n");
    printf ("menjar:\n");
    printf ("amanida d'enciam tomàquet pastanaga pinya i palets de cranc\n");
    printf ("sardines rostides\n");
    printf ("iogurt desnatat\n");
    printf("coliflor a l'all arriero\n");
    printf("cuixa de pollastre encebollado\n");
    printf("--------------------------------------------------------------------------------------\n");
    printf("sopar\n");
    printf("sopa de tomàquet\n");
    printf("carxofes *salteadas amb *jamon\n");
    printf("poma\n");
    printf("iogurt descremat\n");
 
  }
}