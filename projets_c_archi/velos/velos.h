//****************************************************************************
//** Définition de Vélos
//****************************************************************************

#ifndef VELOS_H
#define VELOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct velonode { // noeud de la liste chaînée de vélos.
	int numero; // numéro du vélo représenté par ce noeud
	int nbtours; // nombre de tours effectués par le vélo
	struct velonode *next; // noeud suivant de la liste
};

struct velolist { // liste chaînee de vélos
	struct velonode *first; // premier noeud de la liste
};

// ARGUMENTS: liste - une liste chaînée de vélos
// PRE: liste est un pointeur vers une zône de mémoire dûment allouée, mais
//      non initialisée.
// POST: liste représente la liste vide (liste pointe vers une 
//       structure velolist a laquelle aucun velonode n'est attaché).
void initList(struct velolist *liste);

// ARGUMENTS: liste - une liste chaînée de vélos
// PRE: liste a déjà été initialisée par le passé (via initList); 
//      elle est ou n'est pas vide
// POST: liste représente la liste vide. Attention aux pertes de mémoire...
void emptyList(struct velolist *liste);

// ARGUMENTS: liste - une liste chaînée de vélos
//            num - un numéro de vélo
// PRE: liste a déjà été initialisée par le passé (via initList)
// POST: si num n'était pas dans la liste, un vélo de numéro num et 
//       ayant effectué 1 tour est ajouté dans liste,
//       sinon, 1 tour est ajouté au nombre de tours du vélo num
void addVelo(struct velolist *liste, int num);

// ARGUMENTS: liste - une liste chaînée de vélos
//            num - un numéro de vélo
// PRE: liste a déjà été initialisée par le passé (via initList)
// POST: le vélo de numéro num ne fait pas partie de la liste chaînée liste
void removeVelo(struct velolist *liste, int num);

// ARGUMENTS: liste - une liste chaînée de vélos
// RETURN : le numéro du vélo ayant le plus de tours dans la liste, ou -1 si 
//          la liste ne contient pas de vélo.
// PRE: liste a deja été initialisée par le passé (via initList)

// POST: liste reste inchangée

int getFirst(struct velolist *liste);


#endif // VELOS_H
