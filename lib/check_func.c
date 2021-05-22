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

int loginD(char u[],char p[]){
	FILE* file;
	char user[20],pass[20],name[30];
	int no,cekU,cekP,nip,status=0;
	
	int line=barisF(LOG);
	file=fopen(LOG,"r");
	for(int i=0;i<line;i++){
		fscanf(file,"%d,%[^,],%[^,],%[^,],%d",&no,user,pass,name,&nip);
		cekU=strcmp(user,u);
		cekP=strcmp(pass,p);
		if(cekU==0 && cekP==0){
			status=1;
			break;
		}
	}
	fclose(file);
	if(status==1) return 1;
	else return 0;
}

void tes(){
	FILE*file,*buka;
	
	file=fopen(LOG,"w");
	int line=barisF(LOG);
	if(line==0) fprintf(file,"1,admin,admin,admin,1\n");
	
	buka=fopen(KLS,"a+");
	buka=fopen(MHS,"a+");
	
	fclose(file);
	fclose(buka);
}

void saveKlsMhs(){
	struct Kls *bantu;
	struct List *siswa;
	int i;
	FILE *file,*cek;
	file=fopen(KLS,"w");
	cek=fopen(MHS,"w");
	for(i=0;i<10;i++){
		if(ada[i].id!=0){
			bantu=&ada[i];
			siswa=bantu->mhs;
			while(bantu!=NULL){
				fprintf(file,"%d,%s,%s,%s\n",bantu->id,bantu->nam,bantu->ket,bantu->pass);
				while(siswa!=NULL){
					fprintf(cek,"%d,%d,%s,%c\n",bantu->id,siswa->nim,siswa->nama,siswa->kls);
					siswa=siswa->next;
				}
				bantu=bantu->next;
			}
		}
	}
	fclose(file);
	fclose(cek);
}

int barisF(char file[]){
	char buffer[255];
	FILE*tes;
	int i=-1;
	tes=fopen(file,"r");
	while(!feof(tes)){
		fgets(buffer,sizeof(buffer),tes);
		i++;
	}
	fclose(tes);
	return i;
}

void loadKlsMhs(){
	int i,line1,line2,d;
	struct Kls k;
	struct Kls *bantu;
	struct List m;
	line1=barisF(KLS);
	line2=barisF(MHS);
	
	FILE *file,*cek;
	file=fopen(KLS,"r");
	cek=fopen(MHS,"r");
	if(line1!=0){
		for(i=0;i<line1;i++){
			fscanf(file,"%d,%[^,],%[^,],%[^\n]",&k.id,k.nam,k.ket,k.pass);
			openHash(k.id,k.nam,k.ket,k.pass);
		}
	}
	if(line2!=0){
		for(i=0;i<line2;i++){
			fscanf(cek,"%d,%d,%[^,],%c",&d,&m.nim,m.nama,&m.kls);
			bantu=cariKls(d);
			addMhs(m.nama,m.nim,m.kls,bantu);
		}
	}
	
	fclose(file);
	fclose(cek);
}

