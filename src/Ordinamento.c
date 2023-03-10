/*
 * Ordinamento.c
 *
 *  Created on: 8 nov 2022
 *      Author: Massimo
 */

#include <stdio.h>
#include <stdlib.h>
#include "Strutture.h"
#include "Gestione_registrazioni.h"
#include "Ricerca.h"


#define GIORNI_ANNO 365
#define GIORNI_ANNO_B 366
#define GIORNI_MESE 31
#define GIORNI_MESE_2 30
#define GIORNI_MESE_F 28
#define GIORNI_MESE_B 29


int Data_in_Giorni(Data registrazione_p)
{
	int data_in_giorni = 0;

	//controllo se il mese ha 31 giorni
	if(registrazione_p.mese >= 1 && registrazione_p.mese <= 12){
		if((registrazione_p.giorno>=1 && registrazione_p.giorno<=GIORNI_MESE) && (registrazione_p.mese==1 || registrazione_p.mese==3 || registrazione_p.mese==5 || registrazione_p.mese==7 || registrazione_p.mese==8 || registrazione_p.mese==10 || registrazione_p.mese==12)){
			data_in_giorni = registrazione_p.anno * GIORNI_ANNO;
			data_in_giorni = data_in_giorni + (registrazione_p.mese * GIORNI_MESE);
            data_in_giorni = data_in_giorni + registrazione_p.giorno;

        //controllo se il mese ha 30 giorni
		}else if((registrazione_p.giorno>=1 && registrazione_p.giorno<=GIORNI_MESE_2) && (registrazione_p.mese==4 || registrazione_p.mese==6 || registrazione_p.mese==9 || registrazione_p.mese==11)){
			data_in_giorni = registrazione_p.anno * GIORNI_ANNO;
			data_in_giorni = data_in_giorni + (registrazione_p.mese * GIORNI_MESE_2);
			data_in_giorni = data_in_giorni + registrazione_p.giorno;

			 //controllo se il mese ha 28 giorni
			}else if((registrazione_p.giorno>=1 && registrazione_p.giorno<=GIORNI_MESE_F) && (registrazione_p.mese==2)){
				data_in_giorni = registrazione_p.anno * GIORNI_ANNO;
				data_in_giorni = data_in_giorni + (registrazione_p.mese * GIORNI_MESE_F);
				data_in_giorni = data_in_giorni + registrazione_p.giorno;

				//controllo se l'anno e bisestile
				}else if((registrazione_p.giorno==GIORNI_MESE_B && registrazione_p.mese==2 && (registrazione_p.anno%400==0 ||(registrazione_p.anno%4==0 && registrazione_p.anno%100!=0)))){
					data_in_giorni = registrazione_p.anno * GIORNI_ANNO_B;
					data_in_giorni = data_in_giorni + (registrazione_p.mese * GIORNI_MESE_B);
					data_in_giorni = data_in_giorni + registrazione_p.giorno;
				}
	}
	return data_in_giorni;
}


void Importanza(Registrazione registrazioni_app[], int n_registrazioni)
{
	Registrazione registrazione_t = {0,{0,0,0},{0,0},{0,0},"","",0}; 	//struct temporanea di tipo Registrazione
	int j = 0; // indice

	for(j=0; j < n_registrazioni; j++){ //ciclo che gira sul numero delle registrazioni e stampa in output le registrazioni importanti
		registrazione_t = registrazioni_app[j];

		if(registrazione_t.contrassegno == 1){

			visualizzazione_file(registrazione_t);
		}
	}

	for(j=0; j < n_registrazioni; j++){  //ciclo che gira sul numero delle registrazioni e stampa in output le registrazioni non importanti

		registrazione_t = registrazioni_app[j];

		if(registrazione_t.contrassegno == 0){

			visualizzazione_file(registrazione_t);
		}
	}

}


void Selection_Sort_data( Registrazione a[],int giorni[], int n_registrazioni)
{

	//indici
	unsigned short int i = 0, j = 0, p = 0;

	int min = 0; //variabile temporanea

	Registrazione registrazione_min = {0,{0,0,0},{0,0},{0,0},"","",0};  //struct temporanea di tipo Registrazione

    for(i = 0; i < n_registrazioni - 1 ; i++){
    	     registrazione_min = a[i];
    	     min = giorni[i];
    	     p = i;

    	     for(j = i+1; j < n_registrazioni; j++){
    	    	 if(giorni[j] < min) {
    	    		 registrazione_min = a[j];
    	    		 min = giorni[j];
    	    		 p = j;
    	    	 }
    	     }
    	     	 a[p] = a[i];
    	         giorni[p] = giorni[i];
    	         a[i] = registrazione_min;
    	         giorni[i] = min;
    }




}


void Ordinamento_Data(FILE *registrazioni_file_p)
{

	Registrazione registrazione_t = {0,{0,0,0},{0,0},{0,0},"","",0}; //struct temporanea di tipo Registrazione utilizzata per leggere dal file

	int data_in_giorni = 0;   		//variabile temporanea utilizzata per convertire la data in giorni
	int n_registrazioni = 0;  	   //variabile utilizzata per acquisire il numero di registrazioni
	char importanza[1];       	  //variabile di lavoro
	int i = 0, j = 0;         	 //indici

		//Prendo il numero del numero di registrazioni
	fseek(registrazioni_file_p,(registrazione_t.codice-1)*sizeof(registrazione_t), SEEK_END);
	fread(&registrazione_t, sizeof(Registrazione),1, registrazioni_file_p);
	n_registrazioni = registrazione_t.codice;

	int giorni[n_registrazioni];                       //array temporaneo utilizzato per contenere le registrazioni in giorni
	Registrazione registrazioni_app[n_registrazioni]; //array temporaneo utilizzato per contenere le registrazioni

	rewind(registrazioni_file_p);
	fread(&registrazione_t, sizeof(Registrazione), 1, registrazioni_file_p);

	while(!feof(registrazioni_file_p)){
		data_in_giorni = Data_in_Giorni(registrazione_t.data);
		giorni[i] = data_in_giorni;
		registrazioni_app[i] = registrazione_t;
        i++;

		fread(&registrazione_t, sizeof(Registrazione), 1, registrazioni_file_p);
	}

	Selection_Sort_data(registrazioni_app, giorni, n_registrazioni);

	for(j=0; j < n_registrazioni; j++){ //ciclo utilizzato per la visualizzazione delle registrazioni

		registrazione_t = registrazioni_app[j];

        visualizzazione_file(registrazione_t);
        }
	printf("\n Per mandare in alto quelle importanti <1> altrimenti un carattere qualsiasi\n -->");
	scanf("%s", importanza);

	if(importanza[0] == '1'){

		Importanza(registrazioni_app, n_registrazioni);
	}
}


void Ordinamento_Importanza(FILE *registrazioni_file_p)
{
	Registrazione registrazione_t = {0,{0,0,0},{0,0},{0,0},"","",0}; //struct temporanea di tipo Registrazione utilizzata per leggere dal file

	int n_registrazioni = 0; //variabile utilizzata per acquisire il numero di registrazioni
	int i = 0;              //indice

	//prendo il numero delle registrazioni
	fseek(registrazioni_file_p,(registrazione_t.codice-1)*sizeof(registrazione_t), SEEK_END);
	fread(&registrazione_t, sizeof(Registrazione),1, registrazioni_file_p);
	n_registrazioni = registrazione_t.codice;

	Registrazione registrazioni_app[n_registrazioni];    //array temporaneo utilizzato per contenere le registrazioni

	rewind(registrazioni_file_p);
	fread(&registrazione_t, sizeof(Registrazione), 1, registrazioni_file_p);

	while(!feof(registrazioni_file_p)){
		registrazioni_app[i] = registrazione_t;
	    i++;
	    fread(&registrazione_t, sizeof(Registrazione), 1, registrazioni_file_p);
	}

	Importanza(registrazioni_app, n_registrazioni);
}
