/*
 * GestionePrenotazioni.c
 *
 *  Created on: 27 ott 2022
 *      Author: Massimo
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Strutture.h"
#include "Ricerca.h"


#define ORA_MINUTI 60

#define ANNO_INIZIO_S 2022  //anno inizio attivita software
#define ANNO_FINE_S 2050   //anno fine attivita software
#define GIORNI_ANNO 365
#define GIORNI_ANNO_B 366
#define GIORNI_MESE 31
#define GIORNI_MESE_2 30
#define GIORNI_MESE_F 28
#define GIORNI_MESE_B 29


float Calcolo_Durata(Registrazione registrazione_p)
{
			// variabili di lavoro per il calcolo della durata
            float durata_reg_fine = 0, durata_reg_inizio = 0, durata_reg_totale = 0;

            durata_reg_fine = (float)registrazione_p.orario_fine.ora * ORA_MINUTI;
            durata_reg_fine = durata_reg_fine + (float)registrazione_p.orario_fine.minuto;


            durata_reg_inizio = (float)registrazione_p.orario_inizio.ora * ORA_MINUTI;
            durata_reg_inizio  = durata_reg_inizio + (float)registrazione_p.orario_inizio.minuto;

            durata_reg_totale = durata_reg_fine - durata_reg_inizio;

            if(durata_reg_totale <= 59){
            	durata_reg_totale = durata_reg_totale / 100;
            }else{
            	durata_reg_totale = durata_reg_totale / ORA_MINUTI;
            }


	return durata_reg_totale;
}


void visualizzazione_file(Registrazione registrazione_p)
{

	float durata = 0; 							//variabile utilizzata per acquisire la durata per la visualizzazzione
	durata = Calcolo_Durata(registrazione_p);
    char importante[3]; 						//Array utilizzato per segnalare all'utente in output se una registrazione è importante o meno



    if(registrazione_p.contrassegno == 1){
    	strcpy(importante, "SI");
    }else{
    	strcpy(importante, "NO");
    }

    //Visualizzazzione
	printf("\n\t CODICE -->%d", registrazione_p.codice);
	printf("\n\t IMPORTANTE -->%s", importante);
	printf("\n\t DATA -->%d/%d/%d ", registrazione_p.data.anno, registrazione_p.data.mese, registrazione_p.data.giorno);
	printf("\n\t ORARIO INIZIO -->%d:%d", registrazione_p.orario_inizio.ora, registrazione_p.orario_inizio.minuto);
	printf("\n\t DURATA -->%.2f", durata);
	printf("\n\t TIPOLOGIA -->%s", registrazione_p.tipologia);
	printf("\n\t DESCRIZIONE -->%s", registrazione_p.descrizione);
}


void Acquisizione_Controllo_Data(Data *data_p)
{

	 int corretto = 0; //variabile sentinella
	//variabili temporanee per il controllo della data
     int anno_t = 0;
     int mese_t = 0;
     int giorno_t = 0;

     int input = 0;   //variabile utilizzata per controllare l'input inserito dall'utente


     //Questo ciclo girera  finche¨ non verra  inserita una data corretta
	do{
      anno_t = 0;     // azzerriamo le varibili in caso di errato inserimento della data
      mese_t = 0;
      giorno_t = 0;

    do{
    printf("\n\n Inserisci la data nel formato yyyy/mm/dd \n--->");
    input = scanf("%d/%d/%d", &anno_t, &mese_t, &giorno_t);
    scanf("%*[^\n]");   //pulisco il buffer

    if(!input){
    	printf("\n Inserisci un valore valido");
    }

    }while(!input);

    //controllo anno
    if(anno_t >= ANNO_INIZIO_S && anno_t <= ANNO_FINE_S){    //Per ipotesi il software e attivo fino al 2050

    //controllo se il mese ha 31 giorni
    if(mese_t >= 1 && mese_t <= 12){
          if((giorno_t>=1 && giorno_t<=GIORNI_MESE) && (mese_t==1 || mese_t==3 || mese_t==5 || mese_t==7 || mese_t==8 || mese_t==10 || mese_t==12)){

        	  corretto = 1;
    //controllo se il mese ha 30 giorni
    }else if((giorno_t>=1 && giorno_t<=GIORNI_MESE_2) && (mese_t==4 || mese_t==6 || mese_t==9 || mese_t==11)){

    		  corretto = 1;
    //controllo se il mese ha 28 giorni
    }else if((giorno_t>=1 && giorno_t<=GIORNI_MESE_F) && (mese_t==2)){

    		  corretto = 1;
    //controllo se l'anno Ã¨ bisestile
    }else if((giorno_t==GIORNI_MESE_B && mese_t==2 && (anno_t%400==0 ||(anno_t%4==0 && anno_t%100!=0)))){

    		  corretto = 1;

    }else{
       printf("\n Inserisci un giorno corretto");
       scanf("%*[^\n]");          // pulisco il buffer
    }

    }else{
    	printf("\n Inserisci un mese compreso da 1 a 12");
    }
    }else{

    	printf("\n Inserisci un anno compreso dal 2022 al 2050 ");
    }

	}while(corretto == 0);

    printf("\n Data inserita correttamente");

	data_p->anno = anno_t;           //Passo per indirizzo alla struct Data la data
	data_p->mese = mese_t;           // che l'utente inserisce in input
	data_p->giorno = giorno_t;
}


void Acquisizione_Controllo_Orario(Orario *orario_p )
{

	short int corretto = 0;	 //variabile sentinella
	short int input = 0;    // variabile utilizzata per controllare l'input inserito dall'utente

	//variabili temporanee per il controllo dell'orario
	short int ora_t = 0;
	short int minuto_t = 0;

    //Questo ciclo girera finche non verra inserito un orario valido
    do{
    	corretto = 0;

    	ora_t = 0;
    	minuto_t = 0;

        do{
        	printf("\n --->");
        	input = scanf("%hd:%hd", &ora_t, &minuto_t);
            scanf("%*[^\n]");   //pulisco il buffer

        	if(!input){
        		printf("\n Inserisci un valore valido");
        	}
        }while(!input);

        if(ora_t >=0 && ora_t <=23){
        	if(minuto_t >= 0 && minuto_t <=59){
    			corretto = 1;

        	}else{
    	    	printf("\n Inserire minuti compresi da 0 a 59");
    	         }
    	}else{
    		printf("\n Inserire un ora compresa tra 0 e 23");
    	}

    }while(corretto == 0);

    orario_p->ora = ora_t;             //Passo per indirizzo alla struct orario_p l'orario controllato
    orario_p->minuto = minuto_t;       //inserito dall'utente in input
}


int Controllo_Esistenza_Registrazione(Registrazione data_ora_utente, FILE *registrazioni_file_p)
{

	    short int controllo = 0;

		Registrazione registrazione_t = {0,{0,0,0},{0,0},{0,0},"","",0};  //variabile temporanea utilizzata per acquisire le registrazioni dal file

		//variabili utilizzate per trasfromare l'orario della registrazione del file in minuti
		unsigned short int OrarioInizio_reg_file_in_min = 0, OrarioFine_reg_file_in_min = 0;

		//variabili utilizzate per convertite l'orario della registrazione contenente i dati inseriti dall'utente in minuti
		unsigned short int OrarioInizio_reg_utente_in_min = 0, OrarioFine_reg_utente_in_min = 0;

		//Viene convertito l'orario di inzio della registrazione che l'utente vuole inserire in minuti
		OrarioInizio_reg_utente_in_min = data_ora_utente.orario_inizio.ora * 60;
		OrarioInizio_reg_utente_in_min = OrarioInizio_reg_utente_in_min + data_ora_utente.orario_inizio.minuto;

		//Viene convertito l'orario di fine della registrazione che l'utente vuole inserire in minuti
	    OrarioFine_reg_utente_in_min = data_ora_utente.orario_fine.ora * 60;
	    OrarioFine_reg_utente_in_min = OrarioFine_reg_utente_in_min + data_ora_utente.orario_fine.minuto;


		rewind(registrazioni_file_p);  //posiziono il puntatore del file all'inizio
		fread(&registrazione_t, sizeof(Registrazione),1, registrazioni_file_p);  //leggo la struct dal file



    while(!feof(registrazioni_file_p)){         //ciclo che si ripete fino alla fine del file

    	//Controllo se la data inserita dall'utente corrisponde alla data della struct letta dal file
        if(data_ora_utente.data.anno == registrazione_t.data.anno){
            if(data_ora_utente.data.mese == registrazione_t.data.mese){
                if(data_ora_utente.data.giorno == registrazione_t.data.giorno){

                	//Viene convertito l'orario di inzio della registrazione presente nel file in minuti
                	OrarioInizio_reg_file_in_min = 0;
                    OrarioInizio_reg_file_in_min = registrazione_t.orario_inizio.ora *60;
                    OrarioInizio_reg_file_in_min = OrarioInizio_reg_file_in_min + registrazione_t.orario_inizio.minuto;

                    //Viene convertito l'orario di fine della registrazione presente nel file in minuti
                    OrarioFine_reg_file_in_min = 0;
                    OrarioFine_reg_file_in_min = registrazione_t.orario_fine.ora * 60;
                    OrarioFine_reg_file_in_min = OrarioFine_reg_file_in_min + registrazione_t.orario_fine.minuto;


                    //Controlli per verificare che l'orario della registrazione che l'utente vuole inserire non si accavalli con un'altra registrazione presente
                    if(OrarioInizio_reg_file_in_min <= OrarioInizio_reg_utente_in_min  && OrarioFine_reg_file_in_min >= OrarioInizio_reg_utente_in_min){
                        controllo = 1;
                        visualizzazione_file(registrazione_t);   //visualizza la registrazione gia presente nel file
                    }
                    else if(OrarioInizio_reg_file_in_min <= OrarioFine_reg_utente_in_min && OrarioFine_reg_file_in_min >= OrarioFine_reg_utente_in_min){
                    	controllo = 1;
                    	visualizzazione_file(registrazione_t);
                    }
                    else if(OrarioInizio_reg_utente_in_min < OrarioInizio_reg_file_in_min && OrarioFine_reg_utente_in_min > OrarioFine_reg_file_in_min){
                    	controllo = 1;
                    	visualizzazione_file(registrazione_t);
                    }
               }
            }
         }
        fread(&registrazione_t, sizeof(Registrazione),1, registrazioni_file_p);    //leggo la struct dal file

    }

    return controllo;
}


Registrazione Inserimento_Dati_Registrazione(FILE *registrazioni_file_p)
{

	Registrazione registrazione_t = {0,{0,0,0},{0,0},{0,0},"","",0};  //variabile temporanea utilizzata per acquisire i dati in input della registrazione

	//variabili controllo campo data e orario
   int controllo_tempo = 0;
   int controllo_esistenza_reg = 0;

   //variabili controllo campo tipologia
   char tipologia[1];
   int controllo_tipologia = 0;
   //variabili controllo campo importanza
   char contrassegno[1];



    printf("\n Inserimento registrazioni");
    //Ciclo che si ripete finche l'utente non inserisce un orario che non influisca con le altre registrazioni
    do{
    	//inserimento data
    	Acquisizione_Controllo_Data(&registrazione_t.data);

    	//inserimento orario
    	printf("\n Inserire l'orario di inizio nel formato h:m");
    	Acquisizione_Controllo_Orario(&registrazione_t.orario_inizio);
    	printf("\n Inserire l'orario di fine nel formato h:m");
        Acquisizione_Controllo_Orario(&registrazione_t.orario_fine);

        //controllo esistenza registrazione
    	printf("\n Verifico la tua richiesta......");
    	scanf("%*[^\n]"); //pulisce il buffer

    	controllo_esistenza_reg = Controllo_Esistenza_Registrazione(registrazione_t, registrazioni_file_p);

    	if(controllo_esistenza_reg == 1){
    		printf("\n Registrazione gia esistente");
    	    scanf("%*[^\n]"); //pulisce il buffer
    	}else{
    		printf("\n Richiesta accettata");
    		controllo_tempo = 1;
    	}

     }while(controllo_tempo == 0);

    	//inserimento tipologia
    //ciclo che si ripete finche l'utente non inserisce un valore valido
    do{
    	//scelta tipologia
    	 printf("\n Inserimento tipologia \n <1> EVENTO \t <2> APPUNTAMENTO \t <3> PROMEMORIA \n ---> ");
         scanf("%s", tipologia);

         //inserimento tipologia in stringa
    	 if(tipologia[0] == '1'){
    		 controllo_tipologia = 0;
    		 strcpy(registrazione_t.tipologia, "EVENTO");
    	 }else if(tipologia[0] == '2'){
    		 controllo_tipologia = 0;
    		 strcpy(registrazione_t.tipologia, "APPUNTAMENTO");

    	 }else if(tipologia[0] == '3'){
    		 controllo_tipologia = 0;
    		 strcpy(registrazione_t.tipologia, "PROMEMORIA");
    	 }else{
    		 printf("\n Inserisci un valore valido");
    		 controllo_tipologia = 1;
    	 }

     }while(controllo_tipologia == 1);

    //inserimento descrizione
    printf("\n Inserisci una descrizione di massimo 200 caratteri \n --> ");
    fflush(stdin);
    fgets(registrazione_t.descrizione, 200, stdin);

    //inserimento constrassegno
    printf("\n Inserire <1> per dichiarare la registrazione come importante, altrimenti un carattere qualsiasi \n --> ");
    scanf("%s", contrassegno);

    if(contrassegno[0] == '1'){
    	registrazione_t.contrassegno = 1;
    }else{

    	registrazione_t.contrassegno = 0;
    }

    scanf("%*[^\n]"); //pulisco il buffer

    return registrazione_t;
}


void Inserimento_Registrazioni_file(FILE *registrazioni_file_p)
{
	Registrazione registrazione_t = {0,{0,0,0},{0,0},{0,0},"","",0};  //struct temporanea di tipo Registrazione utilizzata per leggere i dati dell'utente e scriverla nel file
	Registrazione registrazione_c = {0,{0,0,0},{0,0},{0,0},"","",0};  // struct temporanea di tipo Registrazione utilizzata per leggere il codice dell'ultima registrazione presente nel file

	registrazione_t = Inserimento_Dati_Registrazione(registrazioni_file_p);

	fseek(registrazioni_file_p,(registrazione_t.codice-1)*sizeof(registrazione_t), SEEK_END);       //posiziono il puntatore all'ultima registrazione presente nel file
	fread(&registrazione_c, sizeof(Registrazione),1, registrazioni_file_p);                         //leggo da file

	registrazione_t.codice = registrazione_c.codice + 1;                                            //incremento il codice della registrazione che si vuole inserire

	fseek(registrazioni_file_p, (registrazione_t.codice-1)*sizeof(registrazione_t), SEEK_SET);      //posiziono il puntatore
	fwrite(&registrazione_t, sizeof(Registrazione),1, registrazioni_file_p);                        //scrivo sul file
}


int Controllo_Codice(FILE *registrazioni_file_p, int codice)
{

	Registrazione registrazione_t = {0,{0,0,0,},{0,0},{0,0},"","",0};  //struct temporanea di tipo Registrazione utilizzata per leggere le registrazione del file
	int controllo = 0;

	rewind(registrazioni_file_p);
	fread(&registrazione_t, sizeof(Registrazione), 1, registrazioni_file_p);

	while(!feof(registrazioni_file_p)){

		if(codice == registrazione_t.codice){
			controllo = 1;
		}

		fread(&registrazione_t,sizeof(Registrazione), 1, registrazioni_file_p);
	}

	return controllo;
}


void Modifica_Registrazione(FILE *registrazioni_file_p)
{

	Registrazione registrazione_t = {0,{0,0,0,},{0,0},{0,0},"","",0}; // struct temporanea di tipo Registrazione

	int codice = 0; 	//variabile utilizzata per acquisire in input il codice della registrazione da voler modificare
	int input = 0;     //variabile utilizzata per controllare l'input inserito dall'utente

	//variabili sentinella
	int controllo_esistenza_reg = 0;
	int controllo_codice = 0;

	printf("\n Modifica registrazione");

	//ciclo che si ripete finche l'utente non inserisce una data in cui e presente una registrazione
	do{
       controllo_esistenza_reg = Ricerca_Data(registrazioni_file_p);

	}while(controllo_esistenza_reg == 0);

    //ciclo che si ripete finche l'utente non inserisce una codice appartenente a una registrazione
	do{
	   printf("\n Inserisci il codice della registrazione da modificare \n -->");
	   input = scanf("%d", &codice);
	   scanf("%*[^\n]");   //pulisco il buffer

       controllo_codice = Controllo_Codice(registrazioni_file_p, codice);

       if(controllo_codice == 0){
        	 printf("\n Il codice inserito non e associato a nessuna registrazione");
       }else if(!input){
        	 printf("\n Inserire un valore valido");
       }

	}while(controllo_codice == 0 || !input);

    registrazione_t = Inserimento_Dati_Registrazione(registrazioni_file_p);
    registrazione_t.codice = codice;

    fseek(registrazioni_file_p, (registrazione_t.codice-1)*sizeof(registrazione_t), SEEK_SET);
    fwrite(&registrazione_t, sizeof(Registrazione),1, registrazioni_file_p);
}


void Eliminazione_Registrazione(FILE *registrazioni_file_p)
{

	Registrazione registrazione_t = {0,{0,0,0,},{0,0},{0,0},"","",0};   //struct temporanea di tipo Registrazione utilizzata per leggere dal file
	Registrazione registrazione_r = {0,{0,0,0,},{0,0},{0,0},"","",0};   //struct temporanea di tipo Registrazione utilizzata per azzerrare la registrazione da voler eliminare

	int n_registrazioni = 0;	//variabile utilizzata per acquisire il numero di registrazioni

	//acquisisco il numero di registrazioni
	fseek(registrazioni_file_p,(registrazione_t.codice-1)*sizeof(registrazione_t), SEEK_END);
	fread(&registrazione_t, sizeof(Registrazione),1, registrazioni_file_p);
	n_registrazioni = registrazione_t.codice;
	Registrazione registrazione_a[n_registrazioni];  //array di appoggio utilizzato per contenere le registrazioni esclusa quella da voler eliminare

	int codice = 0; //variabile utilizzata per acquisire in input dall'utente la registrazione da voler eliminare
	int input = 0; //variabile utilizzata per controllare l'input inserito dall'utente
	//variabili sentinella
	int controllo_esistenza_reg = 0, controllo_codice = 0;
	//variabili di lavoro indici
	int i = 0, k = 0;

	printf("\n\n Eliminazione registrazione");

	//ciclo che si ripete finche l'utente non inserisce una data in cui e presente una registrazione
	do{

		controllo_esistenza_reg = Ricerca_Data(registrazioni_file_p);

	}while(controllo_esistenza_reg == 0);

	do{
		printf("\n Inserisci il codice della registrazione da voler eliminare o <-1> per uscire \n-->");
		input = scanf("%d", &codice);  //prendo in input il codice della registrazione da voler eliminare

		if(!input){
			printf("\n Inserire un valore valido");
		}

	}while(!input);


	if(codice != -1){
		controllo_codice = Controllo_Codice(registrazioni_file_p, codice);
        if(controllo_codice == 1){
        	fseek(registrazioni_file_p,(codice-1)*sizeof(Registrazione), SEEK_SET);
            fwrite(&registrazione_r, sizeof(Registrazione), 1, registrazioni_file_p);   //azzerro sul file la struct con il codice inserito dall'utente
            rewind(registrazioni_file_p);
            fread(&registrazione_t, sizeof(Registrazione), 1, registrazioni_file_p);

            while(!feof(registrazioni_file_p)){  	//ciclo che si ripete finche il puntatore del file non si posizioni alla fine del file
            	if(registrazione_t.codice>0){
            		i++;  							//incremento indice array
            		registrazione_t.codice = i;     //assegno il codice delle registrazioni
            		registrazione_a[i] = registrazione_t;
            	}

            	 fread(&registrazione_t, sizeof(Registrazione), 1, registrazioni_file_p);

            }

            fclose(registrazioni_file_p);          //chiudo il file
            //riapro il file in modalita lettura e scrittura
            if((registrazioni_file_p = fopen("Registrazioni.txt", "wb+")) == NULL){
            	 printf("ERRORE");
             }else{

            	 rewind(registrazioni_file_p);
            	 for(k=0; k<n_registrazioni; k++){
            		 registrazione_t = registrazione_a[k];

            		 fseek(registrazioni_file_p, (registrazione_t.codice-1)*sizeof(registrazione_t), SEEK_SET);
            		 fwrite(&registrazione_t, sizeof(Registrazione),1, registrazioni_file_p);
            	 }
                 printf("\n Eliminazione avvenuta");
             }

           }else{
        	   printf("\n Il codice inserito non e associato a nessuna registrazione ");
           }
	  }
}

