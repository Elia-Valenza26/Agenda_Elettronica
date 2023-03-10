/*
 * Menu.c
 *
 *  Created on: 10 nov 2022
 *      Author: Massimo
 */


#include <stdio.h>
#include <stdlib.h>
#include "Strutture.h"
#include "Gestione_registrazioni.h"
#include "Ricerca.h"
#include "Ordinamento.h"


char Scelta_Corretta_Menu(char scelta[]){
	int corretto = 0;

	if(scelta[0] == '0' || scelta[0] == '1' || scelta[0] == '2' || scelta[0] == '3' || scelta[0] == '4'){
          corretto = 1;
  	}

	return corretto;
}


char Menu_Principale()
{

	char scelta[1];
	int scelta_corretta = 0;


	do{

		printf("\n\n");
	    printf("\t\t\t\t*********************************************************");
	    printf("\n\n\t\t\t\t*\t\t<0>  EXIT\t\t\t\t*");
        printf("\n\t\t\t\t*\t\t<1>  GESTIONE REGISTRAZIONE\t\t*" );
        printf("\n\t\t\t\t*\t\t<2>  RICERCA REGISTRAZIONI\t\t*");
        printf("\n\t\t\t\t*\t\t<3>  STATISTICA APPUNTAMENTI\t\t*");
	    printf("\n\t\t\t\t*\t\t<4>  ORDINAMENTI REGISTRAZIONE \t\t*\n\n");
	    printf("\t\t\t\t*********************************************************\n");
	    printf("\n" );

	    printf("Inserisci la tua scelta --> ");
	    scanf("%s",scelta);

        scelta_corretta = Scelta_Corretta_Menu(scelta);

	    if(scelta_corretta != 1){

	    	printf("\nOcchio! Hai inserito un valore non valido");
	    }


	}while(scelta_corretta == 0);


    scanf("%*[^\n]");
	return scelta[0];


}


char Scelta_Corretta_Gestione_Ricerca(char scelta[]){
	int corretto = 0;

	if(scelta[0] == '0' || scelta[0] == '1' || scelta[0] == '2' || scelta[0] == '3'){
		corretto = 1;
	}


	return corretto;
}

void Menu_Gestione(FILE *registrazioni_file_p)
{

	char scelta[1];
	int scelta_corretta = 0;


	do{

		printf("\t\t\t\t*************************************************");
		printf("\n\t\t\t\t*\t<1>  Aggiungi registrazione\t\t*" );
		printf("\n\t\t\t\t*\t<2>  Modifica registrazione\t\t*");
		printf("\n\t\t\t\t*\t<3>  Elimina registrazione\t\t*");
		printf("\n\t\t\t\t*\t<0>  Torna indietro\t\t\t*\n");
		printf("\t\t\t\t*************************************************\n");
		printf("\n" );

	    printf("Inserisci la tua scelta --> ");
	    scanf("%s",scelta);

	    scelta_corretta = Scelta_Corretta_Gestione_Ricerca(scelta);

	    if(scelta_corretta != 1){

	    	printf("\nOcchio! Hai inserito un valore non valido");
	    }


	}while(scelta_corretta == 0);


	switch(scelta[0])
	{
		case '0':
		break; //Torna indietro

		case '1':
			Inserimento_Registrazioni_file(registrazioni_file_p);
		break;

		case '2':
			Modifica_Registrazione(registrazioni_file_p);
		break;

		case '3':
			Eliminazione_Registrazione(registrazioni_file_p);
		break;
	}


}


void Menu_Ricerca(FILE *registrazioni_file_p)
{

	char scelta[1];
	int scelta_corretta = 0;


	do{
		 printf("\t\t\t\t*********************************************************");
		 printf("\n\t\t\t\t*\t<1>  Ricerca per data\t\t\t\t*" );
		 printf("\n\t\t\t\t*\t<2>  Ricerca per tipologia\t\t\t*");
		 printf("\n\t\t\t\t*\t<3>  Ricerca per oggetto\t\t\t*");
	     printf("\n\t\t\t\t*\t<0>  Torna indietro\t\t\t\t*\n");
   		 printf("\t\t\t\t*********************************************************\n");
		 printf("\n" );

		 printf("Inserisci la tua scelta --> ");
	     scanf("%s",scelta);

	     scelta_corretta = Scelta_Corretta_Gestione_Ricerca(scelta);

	     if(scelta_corretta != 1){

	    	printf("\nOcchio! Hai inserito un valore non valido");
	    }


	}while(scelta_corretta == 0);


	switch(scelta[0])
	{
		case '0':
		break; //Torna indietro

		case '1':
			Ricerca_Data(registrazioni_file_p);
		break;

		case '2':
			Ricerca_Tipologia(registrazioni_file_p);
		break;

		case '3':
			Ricerca_Oggetto(registrazioni_file_p);
		break;
	}


}


char Scelta_Coretta_Ordinamento(char scelta[])
{
	int corretto = 0;

	if(scelta[0] == '0' || scelta[0] == '1' || scelta[0] == '2'){
		corretto = 1;
	}

	return corretto;
}


void Menu_Ordinamento(FILE *registrazioni_file_p)
{
	char scelta[1];
	int scelta_corretta = 0;


	do{
	     printf("\t\t\t\t*********************************************************");
		 printf("\n\t\t\t\t*\t<1>  Ordinamento per data\t\t\t*" );
		 printf("\n\t\t\t\t*\t<2>  Ordinamento per importanza\t\t\t*");
		 printf("\n\t\t\t\t*\t<0>  Torna indietro\t\t\t\t*\n");
		 printf("\t\t\t\t*********************************************************\n");
		 printf("\n" );

		 printf("Inserisci la tua scelta --> ");
		 scanf("%s",scelta);

		 scelta_corretta = Scelta_Corretta_Gestione_Ricerca(scelta);

		 if(scelta_corretta != 1){

		    printf("\nOcchio! Hai inserito un valore non valido");

		 }


	}while(scelta_corretta == 0);


	switch(scelta[0])
	{
		case '0':
		break; //Torna indietro

		case '1':
			Ordinamento_Data(registrazioni_file_p);
		break;

		case '2':
			Ordinamento_Importanza(registrazioni_file_p);;
		break;
	}

}

