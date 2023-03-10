/*
 * Menu.h
 *
 *  Created on: 10 nov 2022
 *      Author: Massimo
 */

#ifndef MENU_H_
#define MENU_H_


/**
 * Funzione che verifica la scelta dell'utente per il menu principale, ovvero che venga inserito un valore valido
 * @param  scelta prototipo contenente la scelta dell'utente sulla quale avvine il controllo
 * @return restituisce 1 se la scelta dell'utente corrisponde a una di quelle proposte, altrimenti 0
 */
char Scelta_Coretta_Menu(char scelta[]);


/**
 * Funzione utile all'utente per sfruttare tutte le funzionalita del software
 * @return restituisce la scelta dell'utente
 */
char Menu_Principale();


/**
 * Funzione che verifica la scelta dell'utente per il menu gestione registrazioni e il menu ricerca, ovvero che venga inserito un valore valido
 * @param scelta prototipo contenente la scelta dell'utente sulla quale avvine il controllo
 * @return restituisce la scelta dell'utente
 */
char Scelta_Coretta_Gestione_Ricerca(char scelta[]);


/**
 * Funzione utile all'utente per sfruttare le funzionalita di gestione delle registrazioni
 * @param registrazioni_file_p file contentente le registrazioni
 */
void Menu_Gestione(FILE *registrazioni_file_p);


/**
 * Funzione utile all'utente per sfruttare le funzionalita di ricerca delle registrazioni
 * @param registrazioni_file_p file contenente le registrazioni
 */
void Menu_Ricerca(FILE *registrazioni_file_p);


/**
 * Funzione che verifica la scelta dell'utente per il menu ordinamento, ovvero che venga inserito un valore valido
 * @param  scelta prototipo contenente la scelta dell'utente sulla quale avvine il controllo
 * @return restituisce 1 se la scelta dell'utente corrisponde a una di quelle proposte, altrimenti 0
 */
char Scelta_Coretta_Ordinamento(char scelta[]);


/**
 * Funzione utile all'utente per ordinare le registrazioni e visualizzarle
 * @param registrazioni_file_p file contenente le registrazioni
 */
void Menu_Ordinamento(FILE *registrazioni_file_p);








#endif /* MENU_H_ */
