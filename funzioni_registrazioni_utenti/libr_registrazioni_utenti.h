#define N_RECORD_INIZIALI 20
#define N_TIPI_VISITE 9

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

int main(); 
int carica_file_visite( medico medici[] );
void stampa_dati_medici( medico medici[], int n_medici );
int controllo_inserimento_medico( char Id_medico[], int counter_medici, medico medici[] );
int output_visite_MedSpecifico( char Id_medico[], int counter_medici, medico medici[], char *lista_visite[] );
int controllo_inserimento_visita( int n_visite_offerte, int tipo_visita, char *lista_visite[] );
int carica_file_prenotazioni( prenotazione prenotazioni[] );
void stampa_dati_prenotazioni( prenotazione prenotazioni[], int n_prenotazioni );
void output_date_occupate( char nome_visita[], prenotazione prenotazioni[], int counter_prenotazioni, char Id_medico[] );
int Determina_Accesso_visita( medico medici[], int  counter_medici, char nome_visita[] );
int richiesta_avvio_operazione(); 
void aggiungi_paziente( char Id_medico[], int flag_sesso, prenotazione prenotazioni[], utente utenti[],
                        valutazione valutazioni[], char nome_visita[], int *n_utenti, int *n_valutazioni, int *n_prenotazioni ); 

void controllo_cod_fiscale( char CodFiscale[] );
int cerca_paziente( utente utenti[], char CodFiscale[], char nome_paziente[], char cognome_paziente[], 
                      char *sesso, int *giorno_nascita, int *mese_nascita, int *anno_nascita, int flag_sesso,
                      int *controllo_compatibilità_sesso ); 

int carica_file_utenti( utente utenti[] );
void richiesta_data_prenotazione( int *giorno_prenotazione, int *mese_prenotazione, int *anno_prenotazione );
void richiesta_orario_prenotazione( int *ora_prenotazione, int *minuti_prenotazione );
int controllo_prenotazione_inserita( char Id_medico[], int giorno_prenotazione, int mese_prenotazione, int anno_prenotazione, 
                                         int ora_prenotazione, int minuti_prenotazione, prenotazione prenotazioni[] );
void output_prenotazioni_occupate( prenotazione prenotazioni[], char Id_medico[] ); 
void richiesta_valutazione_utenza( int *valutazione_utenza );
int carica_file_valutazioni( valutazione valutazioni[] );
void registra_nuova_valutazione( valutazione valutazioni[], int *n_valutazioni, char CodFiscale[], char Id_medico[],
                                  char nome_visita[], int valutazione_utenza, int giorno_prenotazione, int mese_prenotazione,
                                  int anno_prenotazione, int ora_prenotazione, int minuti_prenotazione );

void registra_nuova_prenotazione( prenotazione prenotazioni[], int *n_prenotazioni, char CodFiscale[], char Id_medico[], char nome_visita[],
                                 int giorno_prenotazione, int mese_prenotazione, int anno_prenotazione, int ora_prenotazione,
                                 int minuti_prenotazione ); 

void richiesta_anagrafica_paziente( char nome_paziente[], char cognome_paziente[], char *sesso, int flag_sesso, int *anno_nascita, 
                                   int *mese_nascita, int *giorno_nascita ); 
void controllo_sesso_paziente( char *sesso, int flag_sesso ); 
void richiesta_data_nascita( int *anno_nascita, int *mese_nascita, int *giorno_nascita ); 
void registra_nuovo_paziente( utente utenti[], int *n_utenti, char CodFiscale[], char nome_paziente[], char cognome_paziente[], 
                            char sesso, int giorno_nascita, int mese_nascita, int anno_nascita, char Id_medico[],
                            char nome_visita[],int giorno_prenotazione, int mese_prenotazione, int anno_prenotazione,
                            int ora_prenotazione, int minuti_prenotazione );