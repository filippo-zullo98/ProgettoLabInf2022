#include "libr_registrazioni_utenti.h"
#include <stdio.h>
#include <string.h>

void registra_nuovo_paziente( utente utenti[], int *n_utenti, char CodFiscale[], char nome_paziente[], char cognome_paziente[], 
                            char sesso, int giorno_nascita, int mese_nascita, int anno_nascita, char Id_medico[],
                            char nome_visita[],int giorno_prenotazione, int mese_prenotazione, int anno_prenotazione,
                            int ora_prenotazione, int minuti_prenotazione )
{
  
  FILE *fPtr; // variabile puntatore ad una struct di tipo file 
   
 /* memorizza tutti i dati anagrafici immessi in input dal paziente */
       strncpy( utenti[*n_utenti - 1].CodFiscale, CodFiscale, 17 );
       strncpy( utenti[*n_utenti - 1].nome_paziente, nome_paziente, 20 );
       strncpy( utenti[*n_utenti - 1].cognome_paziente, cognome_paziente, 20 );
       utenti[*n_utenti - 1].sesso = sesso;
       utenti[*n_utenti - 1].giorno_nascita = giorno_nascita;
       utenti[*n_utenti - 1].mese_nascita = mese_nascita;
       utenti[*n_utenti - 1].anno_nascita = anno_nascita;       
  
  
  fPtr = fopen( "utenti.dat", "ab" ); // Apertura del file in lettura
  if(  fPtr == NULL ) { // se il file non viene aperto
    puts( "Errore nell'apertura del file!" ); // comunica all'utente un messaggio d'errore
  } // fine di if

  // Lettura del file 
  else { // altrimenti
   fwrite( utenti[*n_utenti - 1].CodFiscale, sizeof( utente ), 1, fPtr );
  } // fine di else

  

  fclose( fPtr ); // chiusura del file */ 

     
} // termina la funzione 