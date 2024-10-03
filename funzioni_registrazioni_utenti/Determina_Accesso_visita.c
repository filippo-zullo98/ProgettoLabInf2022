#include <stdio.h> 
#include <string.h>
#include "libr_registrazioni_utenti.h"


int Determina_Accesso_visita( medico medici[], int  counter_medici, char nome_visita[] ) {
  int flag = 0;

  if( strncmp( nome_visita, medici[4].tipo_visita, 30 ) == 0 ) { // se il tipo di visita è ginecologica
    flag = 1; // imposta il buffer a 1
  } // fine di if 

  else if( strncmp( nome_visita, medici[6].tipo_visita, 30 ) == 0 ) { // se il tipo di visita è urologica
   flag = 2; // imposta il buffer a 2
  } // fine di else if 


  return flag; // restiutisci il valore del flag alla funzione chiamante 

  
} // termina la funzione 