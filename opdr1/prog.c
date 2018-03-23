#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	FILE *file;
	int buffer, laagste, hoogste, totaal;
	char c;

	file = fopen("input.txt", "r");
	if(file == NULL) {
		printf("Kon file niet openen!\n");
		return 0;
	}

	laagste=999999999;
	hoogste=0;
	totaal=0;
	while(fscanf(file, "%d%c", &buffer, &c)>0) {
		printf("%d \n", buffer);
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
		}
	}

	fclose(file);
	return 1;
}