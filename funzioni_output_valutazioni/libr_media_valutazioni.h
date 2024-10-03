#define N_RECORD_INIZIALI 20

typedef struct {
 char CodFiscale[17];
 char nome_paziente[20];
 char cognome_paziente[20];
 char sesso;
 int giorno_nascita;
 int mese_nascita;
 int anno_nascita;
} utente;



typedef struct {
 char Id_medico[20];
 char nome_medico[20];
 char cognome_medico[20];
 char tipo_visita[30];
 char descrizione[500];
 float prezzo;
 float val_utenza;
} medico;



typedef struct {
 char CodFiscale[17];
 char Id_medico[20];
 char tipo_visita[30];
 int valutazione;
 int giorno_prenotazione;
 int mese_prenotazione;
 int anno_prenotazione;
 int ora_prenotazione;
 int minuti_prenotazione;
} valutazione;

int main(); 
int cerca_valutazioni( char Id_medico[], int n_valutazioni, valutazione valutazioni[] );
int carica_file_visite( medico medici [] );
int carica_file_valutazioni( valutazione valutazioni[] ); 
void richiesta_ritorno_menu( );