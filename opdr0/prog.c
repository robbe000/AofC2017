#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

int main(void) {
	FILE *file;
	int array[MAX];
	int teller=0;
	int aantal=0;
	int som=0;

	file=fopen("input.txt", "r");
	if(file==NULL) {
		printf("Kon file niet openen!\n");
		return 0;
	}
	while(fscanf(file, "%1d", &array[aantal])>0) {
		aantal++;
	}
	printf("%d elementen ingelezen!\n", aantal);

	while(teller<aantal) {
		int volgende = teller + (aantal/2);
		if(volgende >= aantal) {
			volgende = volgende - aantal;
		}
		printf("%d en %d (nr %d en %d)\n", array[teller], array[volgende], teller, volgende);
		if(array[teller]==array[volgende]) {
			som+=array[teller];
		}
		teller++;
	}
	//Laatste element
	//if(array[teller-1]==array[0]) {
	//	som+=array[teller-1];
	//	printf("%d en %d\n", array[teller-1], array[0]);
	//}
	printf("De som is: %d\n", som);
	return 1;
}