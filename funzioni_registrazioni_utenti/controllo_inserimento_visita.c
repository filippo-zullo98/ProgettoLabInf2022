#include "libr_registrazioni_utenti.h"
#include <stdio.h>
#include <string.h>

int controllo_inserimento_visita( int n_visite_offerte, int tipo_visita, char *lista_visite[] ) {
  
  int flag = 0; 

  if( tipo_visita > 0 && tipo_visita <= n_visite_offerte ) { // se il numero della visita selezionato fa parte dell'elenco delle visite
    printf( "Lei ha scelto la visita -> %s.", lista_visite[tipo_visita] ); // comunica all'utente la visita che ha scelto 
    flag = 1; // imposta a uno il valore del flag 
  } // fine di if 
  
  else { // altrimenti 
    printf( "il medico inserito è inesistente!\n" ); // comunica all'utente che ha sbagliato 
  } // fine di else 

  return flag; // restituisci il valore del flag alla funzione chiamante
  
} // termina la funzione 