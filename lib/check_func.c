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
	char user[20],pass[20],name[30];
	int no,cekU,cekP,nip,status=0;
	
	int line=lineF(LOG);
	file=fopen(LOG,"r");
	for(int i=0;i<line;i++){
		fscanf(file,"%d,%[^,],%[^,],%[^,],%d",&no,user,pass,name,&nip);
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
	if(line==0) fprintf(file,"1,admin,admin,admin,1\n2,sipa,sipa,sipa,2\n");
	fclose(file);
}

int addD(char u[],char p[],char name[],int nip,int kode){
	FILE*file,*find;
	int no,nomor,cekU,status=1,mode=1;   //status=1 untuk status sign up berhasil
	char user[20],pass[20],n[30];
	
	int line=lineF(LOG);
	find=fopen(LOG,"r");
	for(int i=0;i<line;i++){
		fscanf(find,"%d,%[^,],%[^,],%[^,],%d",&no,user,pass,n,&nomor);
		cekU=strcmp(user,u);
		if(cekU==0){
			status=0;
			break;
		}
	}
	fclose(find);
	
	file=fopen(LOG,"a+");
	
	if(kode==1001 && status!=0){
		
		kode=next(3);
		if(kode==1){
			fprintf(file,"%d,%s,%s,%s,%d\n",line+1,u,p,name,nip);
			mode=1;
		}
		
	}
	if(status==0) printf("-->Maaf, username anda telah terpakai\n");
	else if(mode==0) printf("-->Maaf, kode salah\n");
	
	fclose(file);
	
	if(status==0||mode==0) return 0;
	else return 1;
}

void hapus(char u[],char p[]){
	FILE*baca,*t;
	int i,no,nomor,cekU,line;
	char buffer[50];
	
	int lanjut=next(3);
	if(lanjut==0){
		return;
	}
	
	line=lineF("./db_log/login.txt");
	
	baca=fopen(LOG,"r");
	t=fopen(LOGT,"w");
	
	while(fgets(buffer,sizeof(buffer),baca)){
		fprintf(t,"%s",buffer);
	}
	
	fclose(baca);
	fclose(t);
	
//	line=lineF(LOGT);
//	baca=fopen(LOGT,"r");
//	tuker=fopen(LOG,"w");
//	for(i=0;i<line;i++){
//		fscanf(baca,"%d,%[^,],%[^,],%[^,],%d",&no,user,pass,n,&nomor);
//		fprintf(tuker,"%d,%s,%s,%s,%d\n",no,user,pass,n,nomor);
//	}
//	fclose(baca);
//	fclose(tuker);
}