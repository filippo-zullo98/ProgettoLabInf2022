#include "libr_registrazioni_utenti.h"
#include <stdio.h>

void richiesta_anagrafica_paziente( char nome_paziente[], char cognome_paziente[], char *sesso, int flag_sesso, int *anno_nascita, 
                                   int *mese_nascita, int *giorno_nascita ) {
  
  puts( "\nPaziente non registrato nel file!" );
  puts( "Inserisca il proprio nome: " ); // input nome paziente
  while( getchar() != '\n' );
  fgets( nome_paziente, 20, stdin );
  puts( "Inserisca il proprio cognome: " );
  fgets( cognome_paziente, 20, stdin );
  puts( "Inserisca il sesso: " );
  scanf( "%c", sesso ); 
  
  /* chiamata alla funzione per la verifica dell'inserimento corretto del sesso */
   controllo_sesso_paziente( sesso, flag_sesso ); 
  /* chiamata alla funzione per la verifica dell'inserimento corretto della data di nascita*/
  richiesta_data_nascita( anno_nascita, mese_nascita, giorno_nascita );  
  
} // termina la funzione 