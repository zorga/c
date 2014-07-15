#include "velos.h"

int compare(char *stra, char *strb);
int toInt(char *s);

int main() {
	struct velolist *velol = malloc(sizeof(struct velolist));
	int i, j;
	char input[100] = {0};
	char command[50] = {0};
	char arg[50] = {0};

	initList(velol);

	printf("********* 24H VELOS *********\n");
	printf("help pour plus d'informations\n");

	while(1){
		printf("> ");
		fgets(input, 100, stdin);
		
		// Parse l'entré
		for(i=0; input[i] && input[i] != ' ' && input[i] != '\n' && i < 50; i++){
			command[i] = input[i];	
		}
		command[i] = '\0';
		i++;

		if(input[i]){
			for(j = i; input[j] && input[i] != '\n' && input[j] != ' ' && j < 100; j++){
				arg[j-i] = input[j];	
			}
			arg[j-i-1] = '\0';
		} else arg[0] = '\0';
		
		int argi = toInt(arg);

		// choix
		if (compare(command, "add") && argi) {
			addVelo(velol, argi);	
		} else if(compare(command, "remove") && argi) {
			removeVelo(velol, argi);
		} else if(compare(command, "winner")) {
			printf("%d\n", getFirst(velol));	
		} else if(compare(command, "restart")) {
			emptyList(velol);	
		} else if(compare(command, "help")) {
			printf("commandes disponibles :\n");
			printf("- Add numero : ajout d'un tour à un vélo\n");
			printf("- Remove numero : retire un vélo de la course\n");
			printf("- Winner : affiche le gagnant\n");
			printf("- Restart : redémarre la course\n");
			printf("- Quit : quitte le programme\n");
		} else if(compare(command, "quit")) {
			break;
		}

	}
	return 0;
}

int compare(char *stra, char *strb) {
	int i;
	for(i=0; stra[i]; i++) stra[i] = tolower(stra[i]);
	return !strcmp(stra, strb);
}

int toInt(char *s) {
	char c;
	int i = 0, res;

	while((c = *(s + i)) != '\0' && c >= '0' && c <= '9') {
		if(i==0) {
			res =  (c - '0');
		}
		else res = (10 * res) + (c - '0');
		i++;
	}
	return res;
}

