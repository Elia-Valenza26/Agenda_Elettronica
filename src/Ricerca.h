/*
 * Ricerca.h
 *
 *  Created on: 4 nov 2022
 *      Author: Massimo
 */

#ifndef RICERCA_H_
#define RICERCA_H_




/**
 * Funzione che acquisisce in input dall'utente una determinata data e stampa in output tutte le registrazini presenti in quella data
 * @param registrazione_file_p file utilizzato per la ricerca
 * @return restituisce 0 se non vengono trovate registrazioni nella data ricercata, 1 se viene trovata almeno una registrazione
 */
int Ricerca_Data(FILE *registrazione_file_p);


/**
 * Procedura che acquisisce in input dall'utente la tipologia che si intende cercare e visualizza in output le registrazioni presenti nel file con tale tipologia
 * @param registrazione_file_p file utilizzato per la ricerca
 */
void Ricerca_Tipologia(FILE *registrazione_file_p);


/**
 * Questa procedura ha la funzione di convertire tutte la stringa che l'utente inserisce in input per la descrizione in minuscolo cosi da facilitare la ricerca
 * @param stringa protopito su cui lavora il sottoprogramma
 */
void stringa_in_minuscolo_descrizione(char stringa[MAX_LUNGHEZZA_DESCRIZIONE]);


/**
 *Procedura che acquisisce in input dall'untente l'oggetto che si intende cercare, vale anche per sottostringa, e visualizza in output tutte le registrazionu presenti nel file con tale oggetto
 * @param registrazioni_file_p file utilizzato per la ricerca
 */
void Ricerca_Oggetto(FILE *registrazioni_file_p);

#endif /* RICERCA_H_ */
