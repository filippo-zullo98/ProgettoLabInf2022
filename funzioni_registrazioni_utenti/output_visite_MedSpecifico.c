#include "libr_registrazioni_utenti.h"
#include <stdio.h>
#include <string.h>

int output_visite_MedSpecifico( char Id_medico[], int counter_medici, medico medici[], char *lista_visite[] ) {

  char nome_medico[20]; 
  int counter_visite_MedSpecif = 0; // variabile contatore che contiene il numero di visite che un determinato medico può effettuare
  char visita[30];
  

  
  for( int i = 0; i < counter_medici; i++ ) { // finchè il valore di i è minore del numero di medici memorizzati nel file 
    /* se l'Id del medico inserito dall'utente è uguale all'id del medico memorizzato nel file */
    if( strncmp( Id_medico, medici[i].Id_medico, 20 ) == 0 ) {  
     /* copia il cognome del medico nella variabile nome_medico */
     strncpy( nome_medico, medici[i].cognome_medico, 20 );
     break; // esci dal ciclo 
    } // fine di if 
    
  } // fine di for 
  
  /* mostra i tipi di visite offerte dal medico specificato dall'utente */
  printf( "Ha scelto il medico = %s", Id_medico );
  printf( "Visite offerte dal dott.%s" , nome_medico ); 
  for( int i = 0; i < counter_medici; i++ ) { // finchè il valore di i è minore del numero di medici memorizzati nel file 
    /* se l'Id del medico inserito dall'utente è uguale all'id del medico memorizzato nel file */
    if( strncmp( Id_medico, medici[i].Id_medico, 20 ) == 0 ) { 
     counter_visite_MedSpecif++; // incrementa il numero di visite che un determinato medico può effettuare
     strncpy( visita, medici[i].tipo_visita, 30 ); // copia il tipo di visita presente nel file all'interno della stringa visita
      lista_visite[counter_visite_MedSpecif] = visita; // copia la stringa visita all'interno della lista delle visite 
     printf( "%d - %s\n\n", counter_visite_MedSpecif, medici[i].tipo_visita );
    } // fine di if 
  } // fine di for   

  return counter_visite_MedSpecif; // restituisci il valore di ritorno alla funzione chiamante 
  
} // termina la funzione 