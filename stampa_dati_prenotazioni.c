#include "libr_caricamento_files.h"
#include <stdio.h>

void stampa_dati_prenotazioni(prenotazione prenotazioni[], int n_prenotazioni) {

  puts(" ");
  for (int i = 0; i < n_prenotazioni; i++) {
    printf("CodFiscale Paziente: %s\n", prenotazioni[i].CodFiscale);
    printf("Identificativo Medico: %s", prenotazioni[i].Id_medico);
    printf("Tipo di visita: %s\n", prenotazioni[i].tipo_visita);
    printf("Giorno Prenotazione: %d\n", prenotazioni[i].giorno_prenotazione);
    printf("Mese Prenotazione: %d\n", prenotazioni[i].mese_prenotazione);
    printf("Anno Prenotazione: %d\n", prenotazioni[i].anno_prenotazione);
    printf("Ora prenotazione: %d\n", prenotazioni[i].ora_prenotazione);
    if (prenotazioni[i].minuti_prenotazione == 0) {
      printf("Minuti prenotazione: %d0\n\n",
             prenotazioni[i].minuti_prenotazione);
    } else {
      printf("Minuti prenotazione: %d\n\n",
             prenotazioni[i].minuti_prenotazione);
    }
  }

} // termina la funzione
