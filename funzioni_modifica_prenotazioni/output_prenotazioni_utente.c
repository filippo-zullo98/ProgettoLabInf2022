#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "libr_modifica_prenotazioni.h"

int output_prenotazioni_utente( int counter_prenotazioni, prenotazione prenotazioni[], char CodFiscale[] ) {

  int flag = 0;

  system( "clear" );
  puts( "LISTA DELLE PRENOTAZIONI DA LEI REGISTRATE: " );
  for( int i = 0; i < counter_prenotazioni; i++ ) {
   /* se il codice fiscale inserito dal paziente coincide con codice fiscale memorizzato nel file */
   if( strncmp( CodFiscale, prenotazioni[i].CodFiscale, 17 ) == 0 ) {
     flag = 1;
     printf( "paziente %s\n", prenotazioni[i].CodFiscale );
     printf( "ha prenotato una visita %s\n", prenotazioni[i].tipo_visita );
     printf( "con il %s\n", prenotazioni[i].Id_medico );
     printf( "%d/%d/%d \n", prenotazioni[i].giorno_prenotazione, 
     prenotazioni[i].mese_prenotazione, prenotazioni[i].anno_prenotazione );
     if( prenotazioni[i].minuti_prenotazione == 0 ) { // se i minuti della prenotazione sono uguali a zero 
       printf( "ore %d:%d0\n\n", prenotazioni[i].ora_prenotazione, prenotazioni[i].minuti_prenotazione );
      } // fine di if  
     else { // altrimenti 
       printf( "ore %d:%d\n\n", prenotazioni[i].ora_prenotazione, prenotazioni[i].minuti_prenotazione );
      } // fine di else 
    } // fine di if 
  } // fine di for 

 return flag; // restituisci il valore del flag alla funzione chiamante 
  
} // termina la funzione 