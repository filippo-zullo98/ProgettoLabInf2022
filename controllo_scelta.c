#include <stdio.h>
#include <string.h>
#include "libr_caricamento_files.h"

int controllo_scelta( int scelta ) {
 /* questa variabile conterrà l'esito del controllo sulla corretta scelta dell'operazione da svolgere */
 int flag = 0; // la variabile assumerà solo uno fra questi valori: 0 e 1. 

 if( scelta == 1 ) { // se la scelta dell'utente è l'operazione 1
   puts( " " );
   puts( "Caricamento dei dati memorizzati nel file di testo in corso..." );  
   flag = 1; // l'operazione scelta dall'utente è corretta, imposta ad 1 il valore del flag
  } // fine di if 

 else if( scelta == 2 ) { // altrimenti se la scelta dell'utente è l'operazione 2
   puts( " " );
   puts( "Uscita in corso..." ); 
   flag = 1; // l'operazione scelta dall'utente è corretta, imposta ad 1 il valore del flag
  } // fine di else if 

 if( flag == 0 ) { // se l'operazione scelta dall'utente è errata
   puts( " " );
   puts( "errore nella digitazione!" ); // comunica un messaggio di errore
  } // fine di if 

 return flag; // restituisci il valore del flag alla funzione chiamante 

} // termina la funzione 
