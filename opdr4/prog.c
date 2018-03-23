#include <stdio.h>
#include <stdlib.h>
#define MAX 1100

int main(void) {
	FILE *file;
	int array[MAX];
	int aantal = 0;
	int plaats = 0;
	int teller = 0;

	file = fopen("input.txt", "r");
	if(file==NULL) {
		printf("Kon de file niet openen!\n");
		return 0;
	}

	while(fscanf(file, "%d", &array[aantal])>0) {
		aantal++;
	}
	printf("%d elementen ingelezen.\n", aantal);

	while(plaats < aantal && plaats >= 0) {
		printf("Plaats: %d\n", plaats);
		int buffer = array[plaats];
		array[plaats]++;
		plaats += buffer;
		teller++;
	}

	printf("%d stappen doorlopen!\n", teller);
	fclose(file);
	return 1;
}