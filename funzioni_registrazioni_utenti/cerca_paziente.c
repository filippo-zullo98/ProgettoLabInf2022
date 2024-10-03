#include <stdio.h>
#include <string.h>
#include "libr_registrazioni_utenti.h"

int cerca_paziente( utente utenti[], char cod_fiscale[], char nome_paziente[], char cognome_paziente[], 
                     char *sesso, int *giorno_nascita, int *mese_nascita, int *anno_nascita, 
                     int flag_sesso, int *controllo_compatibilità_sesso ) {
  
  FILE *fPtr; // variabile puntatore ad una struct di tipo file 
  int counter_pazienti; // variabile contatore che contiene il numero di pazienti memorizzati nel file binario "utenti"
  int value = 0; // variabile che contiene il valore di ritorno 

  /* chiamata alla funzione per il caricamento delle informazioni presenti nel file utenti */
  counter_pazienti = carica_file_utenti( utenti );

  for( int i = 0; i < counter_pazienti; i++ ) { // finchè il valore del contatore dei pazienti è minore di i
    if( strncmp( cod_fiscale, utenti[i].CodFiscale, 17 ) == 0 ) { // se il codice fiscale del paziente è presente nel file 
     strncpy( nome_paziente, utenti[i].nome_paziente, 20 ); 
     strncpy( cognome_paziente, utenti[i].cognome_paziente, 20 );
     *sesso = utenti[i].sesso;
     *anno_nascita = utenti[i].anno_nascita;
     *mese_nascita = utenti[i].mese_nascita;
     *giorno_nascita = utenti[i].giorno_nascita;   
     value = 1; // imposta il valore di ritorno a 1
     puts( "\nPaziente trovato nel file!" ); // comunica all'utente un messaggio 
     printf( "nome: %s", utenti[i].nome_paziente ); 
     printf( "Cognome: %s", utenti[i].cognome_paziente );
     break; // termina il ciclo for 
    } // fine di if 
  } // fine di for 
  
 if( value == 1 ) { // se il paziente esiste
   if( flag_sesso == 1 ) { // se la visita è ginecologica
     if( *sesso != 'f' && *sesso != 'F' ) { // se l'utente sbaglia l'inserimento
       puts( "Errore! Non è possibile effettuare questo tipo di visita." );
       puts( "Solo le persone di sesso femminile possono prenotarsi per questo tipo di visita." );
       *controllo_compatibilità_sesso = 1; // imposta il controllo sulla compatibilità del sesso con la visita ad 1
      } // fine di if 
    } // fine di if 
 
   if( flag_sesso == 2 ) { // se la visita è urologica 
     if( *sesso != 'm' && *sesso != 'M' ) { // se l'utente sbaglia l'inserimento
       puts( "Errore! Non è possibile effettuare questo tipo di visita." );
       puts( "Solo le persone di sesso maschile possono prenotarsi per questo tipo di visita." );
       *controllo_compatibilità_sesso = 1; // imposta il controllo sulla compatibilità del sesso con la visita ad 1
      } // fine di if 
    } // fine di if 
  
  } // fine di if 
  
  
  return value;

} // termina la funzione 