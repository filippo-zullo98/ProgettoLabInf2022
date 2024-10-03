#include <stdio.h>
#include <string.h>
#include "libr_caricamento_files.h"
#define N_MEDICI 20

void aggiorna_valutazioni_medici( medico medici[], valutazione valutazioni[], int n_valutazioni ) {
  
  FILE *fPtr;
  
  /* in questo array è contenuta la somma di tutti i voti di tutti e 20 i medici */
  float voti_medici[N_MEDICI] = {0}; 
  /* in questo array viene tenuta traccia del numero di voti rilasciati da un paziente per un medico specifico */
  int frequency[N_MEDICI] = {0}; 
  float media_voti[N_MEDICI] = {0};
  
  for( int i = 0; i < N_MEDICI; i++ ) { // finchè la scansione non è stata effettuata su tutti i medici 
    for( int j = 0; j < n_valutazioni; j++ ) { // finchè non sono state scansionate tutte le valutazioni
    /* se nella struct delle valutazioni viene trovato un id di un medico che coincide con l'id presente nella struct medici */
      if( strncmp( medici[i].Id_medico, valutazioni[j].Id_medico, 20 ) == 0 ) { 
       voti_medici[i] = valutazioni[j].valutazione + voti_medici[i]; // aggiungi il voto all'array dei voti dei medici 
       frequency[i]++; // incrementa il numero di voti registrati per quel medico specifico 
      } // fine di if 
    } // fine di for interno 
  } // fine di for 
 
 for( int i = 0; i < N_MEDICI; i++ ) { // finchè il valore di i è minore del numero dei medici
    if( frequency[i] > 0 ) { // se il numero di voti memorizzati per un medico specifico è maggiore di zero
      media_voti[i] = voti_medici[i] / frequency[i]; // calcola la media dei voti 
    } // fine di if     
  } // fine di for 
  
  /*puts( " " );
  for( int i = 0; i < N_MEDICI; i++ )  {
    printf ( "medico[%d] = %.2f\n", i+1, media_voti[i] ); 
  } */   

  for( int i = 0; i < N_MEDICI; i++ ) { // finchè il valore di i è minore del numero di medici 
    medici[i].val_utenza = media_voti[i]; // aggiorna le valutazioni memorizzate nella struct medici 
  } // fine di for 

  // ricevi in input dal file di testo visite i dati delle visite da inserire nella struct utenti
  fPtr = fopen( "visite.dat", "wb" ); // Apertura del file binario in scrittura
  if(  fPtr == NULL ) { // se il file non viene aperto
    puts( "Errore nell'apertura del file!" ); // comunica all'utente un messaggio d'errore
  } // fine di if 
  
  /* Scrittura in file binario di tutti i record */
 else { // altrimenti
    fwrite( medici, sizeof( medico ), N_MEDICI, fPtr );
  } // fine di else
  

  fclose(fPtr); // chiusura del file
  
  //stampa_dati_medici( medici, n_medici );


  

 

} // termina la funzione 