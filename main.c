#include <stdio.h>
#include <string.h>
#include "libr_menu_utente.h"



// la funzione main inizializza l'esecuzione del programma
int main(void) {

 int n_medici = N_RECORD_INIZIALI;
 int n_utenti = N_RECORD_INIZIALI;
 int n_prenotazioni = N_RECORD_INIZIALI;
 int n_valutazioni = N_RECORD_INIZIALI;  
 /*chiamata alla funzione per il caricamento dei dati su cui è basato il funzionamento del programma */
 carica_dati_files( n_medici, &n_utenti, &n_prenotazioni, &n_valutazioni); 
 /* chiamata alla funzionoe per l'output del menu per la scelta del tipo di operazione da effettuare */ 
 scelta_operazione( n_medici, &n_utenti, &n_prenotazioni, &n_valutazioni );

} // fine di main
