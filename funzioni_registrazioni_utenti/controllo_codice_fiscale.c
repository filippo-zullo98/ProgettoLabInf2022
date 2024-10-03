#include <stdio.h>
#include <string.h>
#include "libr_registrazioni_utenti.h"

void controllo_cod_fiscale( char CodFiscale[] ) {
 
  int counter_string; // variabile in cui sarà presente il numero di stringhe memorizzate nella variabile "CodFiscale"
  int flag = 0; 

  /* inserisci una condizione tale che se il paziente non esiste vengono richiesti questi dati, altrimenti vengono direttamente acquisiti dal file degli utenti*/
  puts( "Inserisca il proprio codice fiscale: " ); // input codice fiscale paziente
  while( getchar() != '\n' );
  scanf( "%s", CodFiscale );

  /* chiamata alla funzione per il conteggio dei caratteri memorizzati nella variabile "CodFiscale" */
  counter_string = strlen( CodFiscale );
  //printf( "%d", counter_string );
  if( counter_string != 16 ) { // se il codice fiscale non è di sedici caratteri 
   puts( "Il codice fiscale è errato!" );
   while( flag != 1 ) { // finchè il codice fiscale risulta errato 
     puts( "Inserisca il proprio codice fiscale: " );
     scanf( "%s", CodFiscale );     
     /* chiamata alla funzione per il conteggio dei caratteri memorizzati nella variabile "CodFiscale" */
     counter_string = strlen( CodFiscale );
     if( counter_string != 16 ) { // se il codice fiscale non è di sedici caratteri
       puts( "Il codice fiscale è errato!" );  
      } // fine di if 
     else { // altrimenti 
       flag = 1; // imposta il valore del flag a 1
      } // fine di else 
    } // fine di while     
  } // fine di if
 

} // termina la funzione 