#include <stdio.h>
#include <string.h>
#include "libr_registrazioni_utenti.h"

int controllo_prenotazione_inserita( char Id_medico[], int giorno_prenotazione, int mese_prenotazione, int anno_prenotazione, int ora_prenotazione, 
                                   int minuti_prenotazione, prenotazione prenotazioni[] ) 
{ 
  int value = 0;  
  FILE *fPtr; // variabile puntatore ad una struct di tipo file 
  int counter_prenotazioni; // variabile che contiene il numero di prenotazioni memorizzate nel file binario "prenotazioni"
  
  fPtr = fopen( "prenotazioni.dat", "rb" ); // Apertura del file in lettura
  if(  fPtr == NULL ) { // se il file non viene aperto
    puts( "Errore nell'apertura del file!" ); // comunica all'utente un messaggio d'errore
  } // fine di if 

  // Lettura del file 
  else { // altrimenti
   counter_prenotazioni = 0;   
   while( fread( &prenotazioni[counter_prenotazioni], sizeof( prenotazione ), 1, fPtr ) == 1 ) {  // finchè la funzione fread restituisce 1 
     counter_prenotazioni++; // incrementa il valore del contatore del numero di prenotazioni
    } // fine di while

   
  } // fine di else

  fclose( fPtr ); // chiusura del file 
  
  
  for( int i = 0; i < counter_prenotazioni; i++ ) { // se il medico è lo stesso
   /* se l'id del medico presente nel file delle prenotazioni coincide con l'id del medico inserito dall'utente */
   if( strncmp( Id_medico, prenotazioni[i].Id_medico, 20 ) == 0 ) { 
     /* se l'anno della prenotazione presente nel file delle prenotazioni coincide con l'anno della prenotazione inserito dall'utente */
     if( anno_prenotazione == prenotazioni[i].anno_prenotazione ) {
       /* se il mese della prenotazione presente nel file delle prenotazioni coincide con il mese della prenotazione inserita dall'utente */
       if( mese_prenotazione == prenotazioni[i].mese_prenotazione ) {
         /* se il giorno della prenotazione presente nel file delle prenotazioni coincide con il giorno della prenotazione inserita dall'utente */
         if( giorno_prenotazione == prenotazioni[i].giorno_prenotazione ) { 
           /* se l'ora della prenotazione presente nel file delle prenotazioni coincide con l'ora della prenotazione inserita dall'utente */
           if( ora_prenotazione == prenotazioni[i].ora_prenotazione ) { 
             /* se i minuti della prenotazione presenti nel file delle prenotazioni coincide con i minuti della prenotazione inseriti dall'utente */
             if( minuti_prenotazione == prenotazioni[i].minuti_prenotazione ) {
               printf( "Data occupata!\n"); 
               value = 1; // imposta il valore di value a 1
              } 
            }
          }
        }
      }
    } 
  }
  
  return value; // restituisci il valore di value alla funzione chiamante 
  
} // termina la funzione 