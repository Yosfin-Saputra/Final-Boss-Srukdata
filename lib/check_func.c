#include "check_func.h"

void checkDirect(){
	struct stat st = { 0 };

    if (stat("db_cetak", &st) == -1) {
        mkdir("db_cetak");
    }
    if (stat("db_kls", &st) == -1) {
        mkdir("db_kls");
    }
    if (stat("db_log", &st) == -1) {
        mkdir("db_log");
    }
}

int lineF(char file[]){
	int i,line;
	FILE*hitung;
	hitung=fopen(file,"r");
	while(!feof(hitung)){
		i=fgetc(hitung);
		if(i=='\n') line++;
	}
	fclose(hitung);
	return line;
}

int loginD(char u[],char p[]){
	FILE* file;
	char user[20],pass[20];
	int no,cekU,cekP,status=0;
	
	int line=lineF(LOG);
	file=fopen(LOG,"r");
	for(int i=0;i<line;i++){
		fscanf(file,"%d,%[^,],%[^\n]",&no,user,pass);
		cekU=strcmp(user,u);
		cekP=strcmp(pass,p);
		if(cekU=cekP==0){
			status++;
			break;
		}
	}
	fclose(file);
	if(status!=0) return 1;
	else return 0;
}

void tes(){
	FILE*file;
	
	file=fopen(LOG,"w");
	int line=lineF(LOG);
	fprintf(file,"1,admin,admin\n");
	fclose(file);
}