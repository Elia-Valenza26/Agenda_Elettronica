/*
 ============================================================================
 Name        : agenda_elettronica.c
 Author      : Massimo Manzulli - Elia Valenza
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Agenda Elettronica che permette di gestire registrazioni,
 	 	 	   ricercarle, ordinarle o  effettuare una statistica, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "Strutture.h"
#include "Gestione_registrazioni.h"
#include "Ricerca.h"
#include "Ordinamento.h"
#include "Statistica.h"
#include "Menu.h"


int main(void) {

	setvbuf(stdout, NULL, _IONBF,0);  //funzione utile per evitare eventuali errori nella lettura e scrittura

	char scelta[1];
	scelta[0] = '0'; //variabile utilizzata per la scelta del menu

	//Fase di apertura file
	FILE *registrazioni_file;

	//controllo apertura file
	if((registrazioni_file = fopen("Registrazioni.txt", "rb+")) == NULL){
		printf("ERRORE... Non e stato possibile aprire il file");
	}

    printf("\n\t\t\t\t*******************AGENDA ELETTRONICA********************\n");

    while((scelta[0] = Menu_Principale())!= '0'){

    		switch(scelta[0])
    		{

    			case '1':
    				Menu_Gestione(registrazioni_file);
    			break;

    			case '2':
    				Menu_Ricerca(registrazioni_file);
    			break;

    			case '3':
    				Statistica_Appuntamenti(registrazioni_file);
    			break;

    			case '4':
    				Menu_Ordinamento(registrazioni_file);

    		}
    }

    fclose(registrazioni_file); //chiusura del file

	return 0;
}



