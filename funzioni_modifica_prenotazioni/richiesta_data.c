#include <stdio.h>
#include <string.h>
#include "libr_modifica_prenotazioni.h"


int richiesta_data( prenotazione prenotazioni[], int *giorno_prenotazione, int *mese_prenotazione, int *anno_prenotazione, int *ora_prenotazione, 
                    int *minuti_prenotazione, int counter_prenotazioni, char Id_medico[], char CodFiscale[] ) 
{

  int flag = 0; 

  // richiesta di input di una delle date mostrate nell'elenco all'utente
  printf( "\n\nInserisca il giorno della prenotazione che intende spostare o cancellare---> " );
  scanf( "%d", giorno_prenotazione );
  printf( "Inserisca il mese della prenotazione che intende spostare o cancellare---> " );
  scanf( "%d", mese_prenotazione );
  printf( "Inserisca l'anno della prenotazione che intende spostare o cancellare---> " );
  scanf( "%d", anno_prenotazione );
  printf( "Inserisca l'ora della prenotazione che intende spostare o cancellare---> " );
  scanf( "%d", ora_prenotazione );
  printf( "Inserisca i minuti della prenotazione che intende spostare o cancellare---> " );
  scanf( "%d", minuti_prenotazione );
    
  // finchè il valore di i è minore del numero di elementi memorizzati nel file binario "PRENOTAZIONI"
  for( int i = 0; i < counter_prenotazioni; i++ ) { 
   // se il codice fiscale inserito dall'utente corrisponde con quello presente nella struct prenotazioni 
   if( strncmp( CodFiscale, prenotazioni[i].CodFiscale, 17 ) == 0 ) {
     // se l'Id del medico inserito dall'utente corrisponde con quello presente nella struct delle prenotazioni
     if( strncmp( Id_medico, prenotazioni[i].Id_medico, 20 ) == 0 ) {
       // se il giorno della prenotazione inserito dall'utente corrisponde con quello presente nella struct delle prenotazioni
       if( *giorno_prenotazione == prenotazioni[i].giorno_prenotazione ) { 
         // se il mese della prenotazione inserito dall'utente corrisponde con quello presente nella struct delle prenotazioni
         if( *mese_prenotazione == prenotazioni[i].mese_prenotazione ) {
           // se l'anno della prenotazione inserito dall'utente corrisponde con quello presente nella struct delle prenotazioni    
           if( *anno_prenotazione == prenotazioni[i].anno_prenotazione ) {
             // se l'ora della prenotazione inserita dall'utente corrisponde con quella presente nella struct delle prenotazioni 
             if( *ora_prenotazione == prenotazioni[i].ora_prenotazione ) {
               // se i minuti della prenotazione inseriti dall'utente corrispondono con quelli presenti nella struct delle prenotazioni
               if( *minuti_prenotazione == prenotazioni[i].minuti_prenotazione ) {
                 flag = 1; // imposta il valore del flag a 1
                }   
              }
            } 
          } 
        } 
      }  
    } 
  } // fine di for 
  
  if( flag == 0 ) { // se non è stato trovata alcuna data coincidente con quella inserita dall'utente
    puts( "Errore! Non ha effettuato alcuna prenotazine in questa data con il medico selezionato!" );
    puts( "La preghiamo di inserire correttamente la data." );
  } // fine di if 
   


  return flag; // restituisci il valore del flag alla funzione chiamante 
  
} // termina la funzione