#include <stdio.h>
#include <string.h>
#include "libr_modifica_prenotazioni.h"

int cerca_prenotazione( prenotazione prenotazioni[], char CodFiscale[] ){
  
  
  int counter_prenotazioni; // variabile nella quale sarà contenuto il numero di prenotazioni memorizzate nel file 
  int flag = 0;
  
 /* chiamata alla funzione per il caricamento delle informazioni presenti nel file binario "prenotazioni" */
 counter_prenotazioni = carica_file_prenotazioni( prenotazioni );
 /* chiamata alla funzione che si occupa di mostrare all'utente le prenotazioni da lui registrate */
 flag = output_prenotazioni_utente( counter_prenotazioni, prenotazioni, CodFiscale ); 
 

  return flag; // restituisci il valore del flag alla funzione chiamante 
  
} // termina la funzione 