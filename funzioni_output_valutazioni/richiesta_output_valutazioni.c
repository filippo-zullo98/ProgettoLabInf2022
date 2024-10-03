#include <stdio.h>
#include <stdlib.h>
#include "libr_media_valutazioni.h"

void richiesta_output_valutazioni( int *n_valutazioni, int *n_medici ) {
  
  medico medici[*n_medici];
  valutazione valutazioni[*n_valutazioni];
  int counter_medici;
  char Id_medico[20];
  int result;
  char response;
  int flag_response;

  /* chiamata alla funzione per il caricamento delle informazioni presenti nel file binario "visite" */
  counter_medici = carica_file_visite( medici );
 
 
  /* mostra all'utente una lista rappresentativa di tutte le informazioni che riguardano i medici presenti nel file visite */
  puts( "LISTA DI TUTTI I MEDICI");
  for( int i = 0; i < counter_medici ; i++ ) { // finchè il valore di i è minore del contatore
    printf( "ID: %s", medici[i].Id_medico );
    printf( "Nome: %s", medici[i].nome_medico );
    printf( "Cognome : %s", medici[i].cognome_medico );
    printf( "Tipo di visita: %s\n", medici[i].tipo_visita );
    puts( " " );
  } // fine di for 

 
  while( result != 1 ) { // finchè il programma non legge un identficativo presente nel file delle valutazioni
   flag_response = 0; // inzializza il valore di flag_response a zero
   puts( "Scelga il medico di suo interesse per visualizzarne le valutazioni: " ); //richiedi in input l'identificativo
   while( getchar() != '\n' ); // finchè non viene immesso un carattere di newline
   fgets( Id_medico, 20, stdin );  // ricevi in input l'identificativo del medico
   /* chiama la funzione che restituisce il risultato della ricerca delle valutazioni di un medico specifico */  
   result = cerca_valutazioni( Id_medico, *n_valutazioni, valutazioni ); 
   if( result == 0 ) { // se l'identificativo non viene trovato
     while( flag_response != 1 ) { // finchè l'utente non decide se continuare a cercare nel file o meno la media di un medico 
       puts( "\nErrore! il medico inserito non esiste!" ); // mostra all'utente un messaggio di errore 
       puts( "Intende continuare l'operazione ? Y|N" ); // chiedi all'utente se intende continuare a effettuare la ricerca
       scanf( "%c", &response ); // ricevi una risposta
       if( response == 'N' || response == 'n' ) { // se l'utente vuole terminare la ricerca
         result = 1; // imposta il valroe di result a 1 e trermina la ricerca
         flag_response = 1; // imposta il valore di flag_response a 1 e termina la richiesta di continuazione dell'operazione
        } // fine di if 
       else if( response == 'Y' || response == 'y' ) { // se l'utente vuole continuare la ricerca
         result = 0; 
         flag_response = 1; // imposta il valore di flag_response a 1 e termina la richiesta di continuazione dell'operazione
        } // fine di else if 
        else if( response != 'Y' || response != 'y' || response != 'N' || response != 'n' ) { // se l'utente ha immesso alcuna risposta o una risposta scorretta
         result = 0;
         flag_response = 0;
         puts( "Errore nella digitazione!" ); // comunica all'utente un messaggio di errore
         while( getchar() != '\n' ); // finchè non viene immesso un carattere di newline
        } // fine di else if 

      } // fine di while interno
             
    } // fine di if 
  
  } // fine di while

  /* chiamata alla funzione per la richiesta del ritorno al menù principale */
  richiesta_ritorno_menu( );
  

} // termina la funzione 