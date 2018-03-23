#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 40

int deelTwee(int array[], int aantal) {
	for(int i=0;i<aantal;i++) {
		for(int j=0;j<aantal;j++) {
			if(i!=j) {
				printf("\t%d en %d\n", array[i], array[j]);
				if((array[i]%array[j])==0) {
					printf("\tGevonden: %d\n", array[i]/array[j]);
					return array[i]/array[j];
				}
			}
		}
	}
	printf("\tNiets gevonden.\n");
	return 0;
}

int main(void) {
	FILE *file;
	int buffer, laagste, hoogste, totaal;
	int array[MAX];
	int tellerInt;
	char c;
	int som = 0;

	file = fopen("input.txt", "r");
	if(file == NULL) {
		printf("Kon file niet openen!\n");
		return 0;
	}

	laagste=999999999;
	hoogste=0;
	totaal=0;
	tellerInt=0;
	while(fscanf(file, "%d%c", &buffer, &c)>0) {
		printf("%d \n", buffer);
		array[tellerInt] = buffer;
		tellerInt++;
		if(buffer<laagste) {
			laagste=buffer;
		}
		if(buffer>hoogste) {
			hoogste=buffer;
		}
		if(c=='\n') {
			totaal+= hoogste-laagste;
			printf("Totaal : %d Laagste:%d Hoogste:%d\n", totaal, laagste, hoogste);
			hoogste=0;
			laagste=999999999;
			som += deelTwee(array, tellerInt);
			tellerInt=0;
			printf("Som: %d\n", som);
		}
	}

	fclose(file);
	return 1;
}