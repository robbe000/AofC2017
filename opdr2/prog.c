#include <stdio.h>
#include <stdlib.h>
#define BRT 1000
#define ZOEK 368078

int array[BRT][BRT];

void zien(void) {
	char c;
	printf("\n\n");
	for(int r=0;r<BRT;r++) {
		for(int k=0;k<BRT;k++) {
			printf("%d\t", array[k][r]);
		}
		printf("\n");
	}
	scanf("%c", &c);
}

int main(void) {
	int i=BRT/2, j=BRT/2, teller=1, mover=0;

	for(int r=0;r<BRT;r++) {
		for(int k=0;k<BRT;k++) {
			array[r][k]=0;
		}
	}

	//Opvullen
	while(i<BRT && j<BRT && i>0 && j>0) {
		for(int t=0; t<(mover-1);t++) {
			array[i][j]=teller;
			j++;
			teller++;
		}
		for(int t=0;t<mover;t++) {
			array[i][j]=teller;
			i--;
			teller++;
		}
		for(int t=0;t<mover;t++) {
			array[i][j]=teller;
			j--;
			teller++;
		}
		for(int t=0;t<mover+1;t++) {
			array[i][j]=teller;
			i++;
			teller++;
		}
		mover+=2;
	}
	printf("Het laatste getal: %d\n", teller);

	//zoeken
	for(int r=0;r<BRT;r++) {
		for(int k=0;k<BRT;k++) {
			if(array[k][r] == ZOEK) {
				printf("Getal gevonden op k: %d en r: %d\n", k, r);
				printf("De afstand is: %d\n", abs((BRT/2)-r)+abs((BRT/2-k)));
			}
		}
	}
	
	return 0;
}