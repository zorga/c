#include "velos.h"

void initList(struct velolist *liste) {
	liste->first = NULL;
}

void emptyList(struct velolist *liste) {
	struct velonode *temp = NULL; 
	struct velonode *second = liste->first;

	while(second) {
		temp = second;
		second = second->next;
		free(temp);	
	}
	initList(liste);	
}

void addVelo(struct velolist *liste, int num) {
	struct velonode *second = liste->first;

	// verifie si le velo est deja enregistre
	while(second) {
		if(second->numero == num){
			second->nbtours++;
			return;
		}
		second = second->next;
	}

	// cherche le dernier velonode de la liste
	second = liste->first;
	while(second && second->next) {
		second = second->next;
	}

	// creation du nouveau velo
	struct velonode *nouveau =  malloc(sizeof(struct velonode));
	nouveau->numero = num;
	nouveau->nbtours = 0;
	nouveau->next = NULL;

	// ajout en fin de liste
	if(!second) {
		liste->first = nouveau;
	} else {
		second->next = nouveau;
	}
}


void removeVelo(struct velolist *liste, int num) {
	struct velonode *prev = NULL; 
	struct velonode *curr = liste->first;

	while(curr) {
		if(curr->numero == num) {
			if(!prev){
				liste->first = curr->next;
			} else {
				prev->next = curr->next;
			}
			free(curr);
			return;
		}
		prev = curr;
		curr = curr->next;
	}
}

int getFirst(struct velolist *liste) {
	struct velonode *second = liste->first;
	struct velonode *bestVelo = NULL;
	int best = -1;	

	while(second) {
		if(second->nbtours > best){
			bestVelo = second;
			best = second->nbtours;
		}
		second = second->next;
	}

	if(best != -1) return bestVelo->numero;
	return -1;
}


