/*
 * Strutture.h
 *
 *  Created on: 27 ott 2022
 *      Author: Massimo
 */

#ifndef STRUTTURE_H_
#define STRUTTURE_H_

/**
 * Costanti utilizzate per definire la grandezza di determinati array di stringhe
 */
#define MAX_LUNGHEZZA_TIPO 20
#define MAX_LUNGHEZZA_DESCRIZIONE 200


/**
 * Struttura dati che rappresenta la data di ogni singola registrazione
 */
typedef struct{

  unsigned  short	int giorno;
  unsigned  short	int mese;
  unsigned	short	int anno;
}Data;


/**
 * Struttura dati che rappresenta l'orario di ogni singola registrazione
 */
typedef struct{

  unsigned short	int ora;
  unsigned short	int minuto;

}Orario;


/**
 * Struttura dati che rappresenta le caratteristiche di ogni singola registrazione
 */
typedef struct{
                    int codice;
            Data        data;
            Orario      orario_inizio;
            Orario      orario_fine;
	        char        tipologia[MAX_LUNGHEZZA_TIPO];
	        char        descrizione[MAX_LUNGHEZZA_DESCRIZIONE];
   unsigned short	int contrassegno;
}Registrazione;


#endif /* STRUTTURE_H_ */
