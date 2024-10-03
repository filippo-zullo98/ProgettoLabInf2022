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

void ordina_medici_PerPrezzo( medico medici[], int n_medici );
int carica_file_visite( medico medici[] );
void stampa_dati_medici( medico medici[], int n_medici );
int ordina_prezzi_medici( medico medici[], int n_medici, float prezzi[] );
void output_prezzi_MedDecr( int n_prezzi, medico medici[], float new_lista_prezzi[], int n_medici, float prezzi[] );
void output_prezzi_MedCresc( int n_prezzi, medico medici[], float new_lista_prezzi[], int n_medici, float prezzi[] );

void ordina_PerPrezzo_PerVisita( medico medici[], int n_medici ); 
int ordina_tipi_visite( medico medici[], int n_medici, char *lista_visite[], char tipo_visita[] );
void output_listaVisite_MedDecr( int n_prezzi, medico medici[], float new_lista_prezzi[], int n_medici, float prezzi[], int n_visite, 
                                 char *new_lista_visite[], char *lista_visite[], char tipo_visita[] );
void output_listaVisite_MedCresc( int n_prezzi, medico medici[], float new_lista_prezzi[], int n_medici, float prezzi[], int n_visite, 
                                 char *new_lista_visite[], char *lista_visite[], char tipo_visita[] );

void ordina_medici_PerValutazioni( medico medici[], int n_medici );
int ordina_valutazioni_medici( medico medici[], int n_medici, float valutazioni[] );
void output_valutazioni_MedDecr( int n_valutazioni, medico medici[], float new_lista_valutazioni[], int n_medici, float valutazioni[] );
void output_valutazioni_MedCresc( int n_valutazioni, medico medici[], float new_lista_valutazioni[], int n_medici, float valutazioni[] );

void ordina_PerValutazioni_PerVisita( medico medici[], int n_medici ); 
void output_ValPerVisita_MedDecr( int n_valutazioni, medico medici[], float new_lista_valutazioni[], int n_medici, float valutazioni[],
                                  int n_visite, char *new_lista_visite[], char *lista_visite[], char tipo_visita[] );
void output_ValPerVisita_MedCresc( int n_valutazioni, medico medici[], float new_lista_valutazioni[], int n_medici, float valutazioni[],
                                  int n_visite, char *new_lista_visite[], char *lista_visite[], char tipo_visita[] );

void ordina_PerNum_Prenotazioni( medico medici[], int n_medici, prenotazione prenotazioni[], int n_prenotazioni );
int carica_file_prenotazioni( prenotazione prenotazioni[] );
int crea_lista_prenotazioni( medico medici[], int n_medici, prenotazione prenotazioni[], int n_prenotazioni, int lista_prenotazioni[], 
                             int lista_prenotazioni_SenzaDuplicati[] );
void output_listDec_prenotazioni( medico medici[], int n_medici, prenotazione prenotazioni[], int n_prenotazioni, int lista_prenotazioni[], 
                                  int lista_prenotazioni_SenzaDuplicati[], int counter_somma_prenotazioni, int new_lista_prenotazioni[] );
void output_listCresc_prenotazioni( medico medici[], int n_medici, prenotazione prenotazioni[], int n_prenotazioni, int lista_prenotazioni[], 
                                  int lista_prenotazioni_SenzaDuplicati[], int counter_somma_prenotazioni, int new_lista_prenotazioni[] );

void ordina_PerVisita_PerNprenot( medico medici[], int n_medici, prenotazione prenotazioni[], int n_prenotazioni );
void outputMedDec_PerVis_PerNpren( medico medici[], int n_medici, prenotazione prenotazioni[], int n_prenotazioni, int lista_prenotazioni[], 
                                int lista_prenotazioni_SenzaDuplicati[], int counter_somma_prenotazioni, int new_lista_prenotazioni[], 
                                int n_visite, char *new_lista_visite[], char *lista_visite[], char tipo_visita[] );
void outputMedCresc_PerVis_PerNpren( medico medici[], int n_medici, prenotazione prenotazioni[], int n_prenotazioni, int lista_prenotazioni[], 
                                int lista_prenotazioni_SenzaDuplicati[], int counter_somma_prenotazioni, int new_lista_prenotazioni[], 
                                int n_visite, char *new_lista_visite[], char *lista_visite[], char tipo_visita[] );

void richiesta_continuazione_OpOrdinamento( int n_medici, int n_prenotazioni );
