#define N_MEDICI 20
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
void controllo_cod_fiscale( char cod_fiscale[] );
int cerca_prenotazione( prenotazione prenotazioni[], char CodFiscale[] );
int carica_file_prenotazioni( prenotazione prenotazioni[] );
int carica_file_visite( medico medici[] );
int controllo_scelta_medico( prenotazione prenotazioni[], int counter_prenotazioni, char CodFiscale[], 
                             char Id_medico[], char tipo_visita[] );
int output_prenotazioni_utente( int counter_prenotazioni, prenotazione prenotazioni[], char CodFiscale[] );
void richiesta_continuazione_modifica();
void modifica_prenotazione( prenotazione prenotazioni[], char CodFiscale[], medico medici[], int *n_prenotazioni, 
                            valutazione valutazioni[], int *n_valutazioni ); 
int output_visite_MedSpecifico( char Id_medico[], int counter_medici, medico medici[], char *lista_visite[] );
int controllo_inserimento_visita( int n_visite_offerte, int tipo_visita, char *lista_visite[] );
void stampa_dati_prenotazioni( prenotazione prenotazioni[], int n_prenotazioni );
int richiesta_data( prenotazione prenotazioni[], int *giorno_prenotazione, int *mese_prenotazione, int *anno_prenotazione, int *ora_prenotazione, 
                    int *minuti_prenotazione, int counter_prenotazioni, char Id_medico[], char CodFiscale[] );
int scelta_OpModifica( ); 
void sposta_giorno_prenotazione( prenotazione prenotazioni[], int counter_prenotazioni, char Id_medico[], char CodFiscle[],
                                 int giorno_prenotazione, int mese_prenotazione, int anno_prenotazione, int ora_prenotazione,
                                 int minuti_prenotazione, medico medici[], int counter_medici, char nome_visita[], 
                                 valutazione valutazioni[], int *n_valutazioni ); 
void richiesta_data_prenotazione( int *giorno_prenotazione, int *mese_prenotazione, int *anno_prenotazione );
void richiesta_orario_prenotazione( int *ora_prenotazione, int *minuti_prenotazione );
int nuova_prenotazione_inserita( char Id_medico[], int giorno_sostitutivo, int mese_sostituitivo, int anno_sostitutivo, 
                                                    int ora_sostituitiva, int minuti_sostitutivi, prenotazione prenotazioni[] ); 


void output_date_occupate( char nome_visita[], prenotazione prenotazioni[], int counter_prenotazioni, char Id_medico[] );
int controllo_prenotazione_inserita( char Id_medico[], int giorno_prenotazione, int mese_prenotazione, int anno_prenotazione,
                                      int ora_prenotazione, int minuti_prenotazione, prenotazione prenotazioni [] ); 
void output_prenotazioni_occupate( prenotazione prenotazioni[], char Id_medico[] );
void registra_data_spostata( prenotazione prenotazioni[], char Id_medico[], char CodFiscale[], int giorno_prenotazione, 
                             int mese_prenotazione, int anno_prenotazione, int ora_prenotazione, int minuti_prenotazione, int giorno_sostitutivo, 
                             int mese_sostitutivo, int anno_sostitutivo, int ora_sostitutiva, int minuti_sostitutivi, char nome_visita[] );
int carica_file_valutazioni( valutazione valutazioni[] );
void modifica_giorno_valutazione( valutazione valutazioni[], int *n_valutazioni, char Id_medico[], char CodFiscale[], 
                                   int giorno_prenotazione, int mese_prenotazione, int anno_prenotazione, 
                                   int ora_prenotazione, int minuti_prenotazione, int giorno_sostitutivo, 
                                   int mese_sostitutivo, int anno_sostitutivo, int ora_sostitutiva, 
                                   int minuti_sostitutivi, char nome_visita[] ); 
void cancella_giorno_prenotazione( prenotazione prenotazioni[], int *n_prenotazioni, char Id_medico[], 
                                   char CodFiscale[], int giorno_prenotazione, int mese_prenotazione, 
                                   int anno_prenotazione, int ora_prenotazione, int minuti_prenotazione,
                                   char tipo_visita[] );
void registra_data_cancellata( prenotazione prenotazioni[], int n_prenotazioni );

