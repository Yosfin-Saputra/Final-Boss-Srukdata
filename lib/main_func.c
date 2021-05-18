#include "main_func.h"

void latar(){
	printf("============================================================\n");
	printf("                APLIKASI PENGELOLAAN ABSENSI\n");
}

int next(){
	char pil;
	
	printf("Ingin lanjutkan? y/t : ");
	fflush(stdin);
	scanf("%c",&pil);
	if(pil=='y') return 1;
	else return 0;
}