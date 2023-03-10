/*
 * Gestione_Registrazioni.h
 *
 *  Created on: 27 ott 2022
 *      Author: Massimo
 */

#ifndef GESTIONE_REGISTRAZIONI_H_
#define GESTIONE_REGISTRAZIONI_H_



#include "strutture.h"
#include <stdio.h>
#include <stdlib.h>



/**
 * Funzione che calcola la durata di una determinata registrazione, nel dettaglio converte gli orari in minuti restituendo la durata
 * @param   registrazione_p struct di tipo Registrazione, prototipo contenente la registrazione sulla quale opera il sottoprogramma
 * @return  restituisce la durata in float
 */
float Calcolo_Durata(Registrazione registrazione_p);


/**
 * Procedura che permette la visualizzazione di una registrazione
 * @param registrazione_p struct di tipo Registrazione, prototipo contenente i dati per la visualizzazzione
 */
void visualizzazione_file(Registrazione registrazione_p);


/**
 * Questo sottoprogramma acquisisce la data e controlla che l'utente ne inserisca una valida
 * @param data_p strcut di tipo Data, prototipo utilizzato per acquisire i dati dopo il controllo tramite puntatore
 */
void Acquisizione_Controllo_Data(Data *data_p);


/**
 * Questo sottoprogramma permette di acquisire e controllare che venga inserito dall'utente un orario valido
 * @param orario_p struct di tipo Orario, prototipo utilizzato per acquisire i dati dopo il controllo tramite puntatore
 */
void Acquisizione_Controllo_Orario(Orario *orario_p );


/**
 * Questo sottoprogramma ha la funzione di controllare se nel file esiste gia una registrazione uguale a quella
 * che l'utente vuole inserire e se trovata viene fatta visualizzare
 * @param data_ora_utente struct di tipo Registrazione, prototipo contenente i dati dell'utente della registrazione che si vuole inserire
 * @param registrazioni_file_p file utilizzato per prendere le registrazioni utilizzate nel controllo
 * @return Nel caso in cui il sottoprogramma trovi una registrazione nel file nella stessa data e nella stessa ora di quella che l'utente vuole inserire, controllo sarà  uguale a 1
 */
int Controllo_Esistenza_Registrazione(Registrazione data_ora_utente, FILE *registrazioni_file_p);


/**
 * Funzione utilizzata per inserire i dati in input dall'utente della registrazione che si vuole inserire
 * @param registrazioni_file_p file utilizzato per eventuali controlli
 * @return restituisce la struct contenente i dati inseriti in input dall'utente
 */
Registrazione Inserimento_Dati_Registrazione(FILE *registrazioni_file_p);


/**
 * Procedura utilizzata per inserire le registrazione nel file
 * @param registrazioni_file_p file sul quale vengono inserite le registrazioni
 */
void Inserimento_Registrazioni_file(FILE *registrazioni_file_p);


/**
 * Funzione utilizzata per controllare se il codice inserito dall'utente sia assocciato a una registrazione presente nel file
 * @param registrazioni_file_p file utilizzato per prendere le registrazioni utilizzate nel controllo
 * @param codice variabile contenente il codice inserito dall'utente
 * @return nel caso in cui il sottoprogramma trovi una corrispondenza con il codice dell'utente e il codice della registrazione nel file, restituisce 1
 */
int Controllo_Codice(FILE *registrazioni_file_p, int codice);


/**
 * Procedura utilizzata per modificare una registrazione gia presente nel file
 * @param registrazioni_file_p file sul quale avviene la modifica della registrazione
 */
void Modifica_Registrazione(FILE *registrazioni_file_p);

/**
 * Procedura utilizzata per eliminare una registrazione presente nel file
 * @param registrazioni_file_p file sul quale avviene l'eliminazione
 */
void Eliminazione_Registrazione(FILE *registrazioni_file_p);


#endif /* GESTIONE_REGISTRAZIONI_H_ */
