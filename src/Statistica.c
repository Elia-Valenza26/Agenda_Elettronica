/*
 * Statistica.c
 *
 *  Created on: 10 nov 2022
 *      Author: valen
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Strutture.h"
#include "Gestione_registrazioni.h"
#include "Ricerca.h"
#include "Ordinamento.h"


void Statistica_Appuntamenti(FILE *registrazioni_file_p)
{
	Registrazione registrazione_t = {0,{0,0,0},{0,0},{0,0},"","",0};

	int controllo = 0;
	//variabili utilizzate per convertire la data in giorni
	int n_giorni = 0, data_inizio_g = 0, data_fine_g = 0;
	//variabili utilizzate per contenere il numero di registrazioni di tipologia appuntamento e il numero di quelle importanti
	int n_reg_comprese = 0, n_reg_importanti = 0;
    //variabile utilizzata per calcolare la media giornaliera
	float media = 0;

	Data data_inizio = {0,0,0}, data_fine = {0,0,0}; //struct temporane di tipo Data utilizzate per acquisire in input la data di inizio e la data di fine su cui si vuole eseguire le statistica

	//acquisizione data
	printf("\n Inserisci la data di inizio");
	Acquisizione_Controllo_Data(&data_inizio);
	printf("\n inserimento data fine");
	Acquisizione_Controllo_Data(&data_fine);

	//conversione data in giorni
	data_inizio_g = Data_in_Giorni(data_inizio);
	data_fine_g = Data_in_Giorni(data_fine);

	rewind(registrazioni_file_p);
	fread(&registrazione_t, sizeof(Registrazione), 1, registrazioni_file_p);

	while(!feof(registrazioni_file_p)){

		n_giorni = Data_in_Giorni(registrazione_t.data);

		if(n_giorni >= data_inizio_g && n_giorni <= data_fine_g){
			if(strstr(registrazione_t.tipologia, "APPUNTAMENTO") !=NULL){

				controllo = 1;
		        n_reg_comprese++;

		        if(registrazione_t.contrassegno == 1){
		        n_reg_importanti++;
		        }
			}
		}

		fread(&registrazione_t, sizeof(Registrazione), 1, registrazioni_file_p);
	}

	if(controllo == 1){

		media = (float)n_reg_comprese / ((float)data_fine_g - (float)data_inizio_g);
     	printf("\n Media appuntamenti giornalieri ->%f", media);
	    printf("\n Gli appuntamenti importanti in questo periodo sono ->%d", n_reg_importanti);
	}else{
		printf("\n Non ci sono appuntamenti in programma nel lasso di tempo inserito");
	}
}
