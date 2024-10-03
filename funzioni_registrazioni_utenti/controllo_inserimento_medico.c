#include "libr_registrazioni_utenti.h"
#include <stdio.h>
#include <string.h>

int controllo_inserimento_medico( char Id_medico[], int counter_medici, medico medici[] ) {
  
  int flag = 0; 

  for( int i = 0; i < counter_medici; i++ ) { // cicla sulla struct medici
   /* se il medico inserito dall'utente corrisponde ad uno presente nella struct medici */
    if( strncmp( Id_medico, medici[i].Id_medico, 20 ) == 0 ) { 
     puts( "il medico esiste" ); // comunica all'utente che il medico esiste
     flag = 1; // imposta ad 1 il valore del flag 
     break; // esci dal ciclo for 
    } // fine di if interno        
  } // fine di for 

 if( flag == 0 ) { // se il medico inserito non esiste
    puts( "Il medico inserito è inesistente!" );
  } // fine di if 
    


  return flag; // restituisci il valore del flag alla funzione chiamante
  
} // termina la funzione 