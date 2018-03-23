#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

int main(void) {
	FILE *file;
	char c, buffer[MAX][MAX];
	int teller, tellerA=1;
	int valid = 0;
	int tussenValid;

	file = fopen("input.txt", "r");
	if(file == NULL) {
		printf("Kon file niet openen!\n");
		return 0;
	}

	teller = 0;
	while(fscanf(file, "%s%c", buffer[teller], &c)>0) {
		teller++;
		if(c=='\n') {
			for(int i=0; i<teller;i++) {
				int aantTrue=0;
				for(int j=0;j<teller;j++) {
					if(strcmp(buffer[i], buffer[j])==0) {
						aantTrue++;
					}
				}
				if(aantTrue > 1) {
					tussenValid++;
				}
			}
			if(tussenValid > 1) {
				printf("%d Niet geldig!\n", tellerA);
			} else {
				printf("%d Geldig!\n", tellerA);
				valid++;
			}
			tellerA++;
			tussenValid=0;
			teller=0;
		}
	}
	printf("\n\nAantal valid: %d\n", valid);

	fclose(file);
	return 1;
}

