#include <stdio.h>
#include <stdlib.h>
#define NR 16
#define MAX 100000

int vindGrootste(int geheugen[]) {
	int grootste=0;
	int plaats;

	for(int i=0;i<NR;i++) {
		if(geheugen[i]>grootste) {
			grootste=geheugen[i];
			plaats=i;
		}
	}
	return plaats;
}

void print(int geheugen[]) {
	for(int i=0;i<NR;i++) {
		printf("%d\t", geheugen[i]);
	}
	printf("\n");
}

int main(void) {
	//int geheugen[NR] = {0, 2, 7, 0};
	int geheugen[NR] = {5, 1, 10, 0, 1, 7, 13, 14, 3, 12, 8, 10, 7, 12, 0, 6};
	int gehgeh[MAX][NR];
	int gehTeller = 0;
	int verdeel, rest;
	int teller;
	int globTeller = 0;

	while(1) {
		globTeller++;
		//Waarde opslaan
		for(int i=0;i<NR;i++) {
			gehgeh[gehTeller][i]=geheugen[i];
		}
		gehTeller++;

		//Grootste getal vinden
		verdeel=0;
		teller=0;
		rest=0;
		int grootste = vindGrootste(geheugen);
		printf("Plaats met de grootste waarde: %d\n", grootste);

		teller=grootste;
		verdeel=geheugen[grootste];
		geheugen[grootste]=0;
		while(verdeel>0) {
			teller++;
			if(teller>NR-1) {
				teller=0;
			}
			printf("Teller: %d\n", teller);
			geheugen[teller]+=1;
			verdeel--;
		}

		print(geheugen);


		//Kijken of we nog verder moeten doen
		int gevonden = 0;

		for(int i=0;i<gehTeller;i++) {
			int internGevonden=0;
			for(int j=0;j<NR;j++) {
				if(geheugen[j]==gehgeh[i][j]) {
					internGevonden++;
				}
			}
			if(internGevonden==NR) {
				printf("%d rondes\n", globTeller);
				printf("%d blokken ertussen\n", globTeller-i);
				return 0;
			}
		}

		//scanf("%*c");
	}	
	return 1;
}