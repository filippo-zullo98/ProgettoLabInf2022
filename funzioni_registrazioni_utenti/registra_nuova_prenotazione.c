#include "libr_registrazioni_utenti.h"
#include <stdio.h>
#include <string.h>

void registra_nuova_prenotazione( prenotazione prenotazioni[], int *n_prenotazioni, char CodFiscale[], char Id_medico[], char nome_visita[],
                                 int giorno_prenotazione, int mese_prenotazione, int anno_prenotazione, int ora_prenotazione,
                                 int minuti_prenotazione )
{ 
  FILE *fPtr; // variabile puntatore ad una struct di tipo file 

  /* memorizza tutti i dati immessi dal paziente che interessano la prenotazione che intende effettuare */
  strncpy( prenotazioni[*n_prenotazioni - 1].CodFiscale, CodFiscale, 17 );
  strncpy( prenotazioni[*n_prenotazioni - 1].Id_medico, Id_medico, 20 );
  strncpy( prenotazioni[*n_prenotazioni - 1].tipo_visita, nome_visita, 30 );
  prenotazioni[*n_prenotazioni - 1].giorno_prenotazione = giorno_prenotazione;
  prenotazioni[*n_prenotazioni - 1].mese_prenotazione = mese_prenotazione;
  prenotazioni[*n_prenotazioni - 1].anno_prenotazione = anno_prenotazione;
  prenotazioni[*n_prenotazioni - 1].ora_prenotazione = ora_prenotazione;
  prenotazioni[*n_prenotazioni - 1].minuti_prenotazione = minuti_prenotazione;  

  fPtr = fopen( "prenotazioni.dat", "ab" ); // Apertura del file in lettura
  if(  fPtr == NULL ) { // se il file non viene aperto
    puts( "Errore nell'apertura del file!" ); // comunica all'utente un messaggio d'errore
  } // fine di if

  // Lettura del file 
  else { // altrimenti
  fwrite( prenotazioni[*n_prenotazioni - 1].CodFiscale, sizeof( prenotazione ), 1, fPtr );
  } // fine di else

  

  fclose( fPtr ); // chiusura del file */ 


} // termina funzione 