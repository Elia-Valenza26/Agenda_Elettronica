/*
 * Ricerca.c
 *
 *  Created on: 4 nov 2022
 *      Author: Massimo
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Strutture.h"
#include "Gestione_registrazioni.h"


int Ricerca_Data(FILE *registrazioni_file_p)
{

	Registrazione registrazione_t = {0,{0,0,0,},{0,0},{0,0},"","",0};  //struct temporanea di tipo Registrazione utilizzata per leggere nel file

	Data registrazione_p = {0}; //struct temporanea di tipo Data utilizzata per acquisire in input la data ricercata dall'utente
    int controllo = 0;          //variabile utilizzata per controllare l'esistenza della registrazione

    Acquisizione_Controllo_Data(&registrazione_p);

    rewind(registrazioni_file_p);
    fread(&registrazione_t, sizeof(Registrazione),1, registrazioni_file_p);

	while(!feof(registrazioni_file_p)){
		//controllo se la data iserita dell'utente corrisponde a una registrazione presente nel file e la visualizza
		if(registrazione_p.anno == registrazione_t.data.anno){
    	   if(registrazione_p.mese == registrazione_t.data.mese){
    		   if(registrazione_p.giorno == registrazione_t.data.giorno){
    			   visualizzazione_file(registrazione_t);
    			   controllo = 1;
    		   }
    	   }
		}
		fread(&registrazione_t, sizeof(Registrazione),1, registrazioni_file_p);

	}
    if(controllo==0){
    	printf("\n Non esiste registrazione nella data ricercata");
    }

    return controllo;
}



void Ricerca_Tipologia(FILE *registrazioni_file_p)
{

	Registrazione registrazione_t = {0,{0,0,0,},{0,0},{0,0},"","",0};  //struct temporanea di tipo Registrazione utilizzata per leggere nel file

	//variabile utilizzata per acquisire in input la tipologia cercata dall'utente
	char tipologia[1];

	//variabili sentinella
	int controllo_tipologia = 0, controllo = 0;
    //variabile utilizzata per acquisire la tipologia in stringa
    char tipologia_c[MAX_LUNGHEZZA_TIPO];

	//inserimento tipologia

   	do{ //ciclo che si ripete finche l'utente non inserisce un valore valido
   		controllo_tipologia = 0;
   		printf("\n Inserimento tipologia \n <1> EVENTO \t <2> APPUNTAMENTO \t <3> PROMEMORIA \n ---> ");
        scanf("%s", tipologia);
        //inserimento tipologia in stringa
        if(tipologia[0] == '1'){
        	strcpy(tipologia_c, "EVENTO");
        }else if(tipologia[0] == '2'){
        	strcpy(tipologia_c, "APPUNTAMENTO");
        }else if(tipologia[0] == '3'){
        	strcpy(tipologia_c, "PROMEMORIA");
        }else{
        	printf("\n Inserisci un valore valido");
        	scanf("%*[^\n]");    //pulisco buffer
        	controllo_tipologia = 1;
        }
   	}while(controllo_tipologia == 1);

    rewind(registrazioni_file_p);   //mando il puntatore all'inizio del file
    fread(&registrazione_t, sizeof(Registrazione),1, registrazioni_file_p);   //leggo da file

    while(!feof(registrazioni_file_p)){

    	//controllo se la tipologia inserita dall'utente corrisponde a una tipologia presente nel file e la visualizza
    	if(strcmp(tipologia_c, registrazione_t.tipologia) == 0){

    		visualizzazione_file(registrazione_t);
    		controllo = 1;
    	}

    	fread(&registrazione_t, sizeof(Registrazione),1, registrazioni_file_p);     //leggo da file
    	}

    if(controllo == 0){
    	printf("\n Non esistono registrazioni con la tipologia ricercata");
    }
}


void stringa_in_minuscolo_descrizione(char stringa[MAX_LUNGHEZZA_DESCRIZIONE])
{
	short int i = 0;

	while(stringa[i] != '\0'){
         stringa[i] = tolower(stringa[i]);
		i++;
	}
}


void Ricerca_Oggetto(FILE *registrazioni_file_p)
{

	Registrazione registrazione_t = {0,{0,0,0,},{0,0},{0,0},"","",0};  //struct temporanea di tipo Registrazione utilizzata per leggere nel file

	int controllo = 0;         						                  //variabile sentinella
	char oggetto_ric[MAX_LUNGHEZZA_DESCRIZIONE]; 					 // variabile che acquisisce in input l'oggetto cercato dall'utente

	printf("\n Ricerca per oggetto");
	printf("\n N.B. Vale anche per sottostringa");

	rewind(registrazioni_file_p);
	printf("\n Inserisci l'argomento da ricercare \n --->");
	scanf("%s", oggetto_ric);
	stringa_in_minuscolo_descrizione(oggetto_ric);

	fread(&registrazione_t, sizeof(Registrazione), 1, registrazioni_file_p);
	while(!feof(registrazioni_file_p)){

		stringa_in_minuscolo_descrizione(registrazione_t.descrizione);

		if(strstr(registrazione_t.descrizione, oggetto_ric) !=NULL){

			controllo = 1;
            visualizzazione_file(registrazione_t);
		}
		fread(&registrazione_t, sizeof(Registrazione),1, registrazioni_file_p);
	}

	if(controllo == 0){
		printf("\n Non e stata trovata nessuna registrazione");
	}

}
