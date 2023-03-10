/*
 * Ordinamento.h
 *
 *  Created on: 9 nov 2022
 *      Author: valen
 */

#ifndef ORDINAMENTO_H_
#define ORDINAMENTO_H_


/**
 * Funzione utilizzata per convertire la data in giorni, utile per l'ordinamento per data
 * @param registrazione_p prototipo di tipo Data contenente la data da dover convertire
 * @return restituisce la data convertita in giorni
 */
int Data_in_Giorni(Data registrazione_p);


/**
 * Procedura utilizzata per la visualizzazione distinta delle registrazioni importanti e non importanti
 * @param registrazioni_app array contenente le registrazioni da visualizzare
 * @param n_registrazioni numero delle registrazioni presenti nel file
 */
void Importanza(Registrazione registrazioni_app[], int n_registrazioni);


/**
 * Procedura utilizzata per l'ordinamento
 * @param a
 * @param n_registrazioni
 */
void Selection_Sort_data( Registrazione a[], int n_registrazioni);


/**
 * Procedura utilizzata per ordinare per data le registrazioni nel file e visualizzarle
 * @param registrazioni_file_p file utilizzato per leggere le registrazioni
 */
void Ordinamento_Data(FILE *registrazioni_file_p);


/**
 * Procedura utilizzata per ordinare per tipologia le registrazioni nel file e visualizzarle
 * @param registrazioni_file_p file utilizzato per leggere le registrazioni
 */
void Ordinamento_Importanza(FILE *registrazioni_file_p);




#endif /* ORDINAMENTO_H_ */
