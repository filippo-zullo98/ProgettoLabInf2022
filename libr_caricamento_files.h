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
 int giorno_prenotazione;
 int mese_prenotazione;
 int anno_prenotazione;
 int ora_prenotazione;
 int minuti_prenotazione;
} prenotazione;


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

void carica_dati_files( int n_medici, int *n_utenti, int *n_prenotazioni, int *n_valutazioni );
int carica_file_visite( medico medici[] );
void crea_file_visite( medico medici[], int n_medici );
int controllo_scelta( int scelta );
void stampa_dati_medici( medico medici[], int n_medici );

int carica_file_utenti( utente utenti[] );
void crea_file_utenti( utente utenti[], int n_utenti );
void stampa_dati_utenti( utente utenti[], int n_utenti ); 

int carica_file_prenotazioni( prenotazione prenotazioni[] );
void crea_file_prenotazioni( prenotazione prenotazioni[], int n_prenotazioni );
void stampa_dati_prenotazioni( prenotazione prenotazioni[], int n_prenotazioni ); 

int carica_file_valutazioni( valutazione valutazioni[] );
void crea_file_valutazioni( valutazione valutazioni[], int n_valutazioni );
void stampa_dati_valutazioni( valutazione valutazioni[], int n_valutazioni );
void aggiorna_valutazioni_medici( medico medici[], valutazione valutazioni[], int n_valutazioni ); 

