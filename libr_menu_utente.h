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
void scelta_operazione( int n_medici, int *n_utenti, int *n_prenotazioni, int *n_valutazioni );
int carica_file_visite( medico medici[] );
void richiesta_prenotazione( int *n_prenotazioni, int *n_utenti, int *n_valutazioni );

void richiesta_output_valutazioni( int *n_valutazioni, int *n_medici);

void richiesta_modifica_prenotazione( int *n_prenotazioni, int *n_valutazioni );

void richiesta_medici_ordinati( int n_medici, int n_prenotazioni );