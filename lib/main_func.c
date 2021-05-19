#include "main_func.h"

void latar(){
	printf("============================================================\n");
	printf("                APLIKASI PENGELOLAAN ABSENSI\n");
}

int next(int n){
	char pil;
	if(n==1)
		printf("Ingin lanjutkan? y/t : ");
	else if(n==2)
		printf("Ingin mengulang? y/t : ");
	else
		printf("Anda yakin? y/t : ");
	fflush(stdin);
	scanf("%c",&pil);
	if(pil=='y') return 1;
	else return 0;
}

void addMhs(char name[],int ni,char kl,struct Kls *m){
	struct List *baru,*bantu;
	baru=(struct List*)malloc(sizeof(struct List));
	baru->nim=ni;
	strcpy(baru->nama,name);
	baru->kls=kl;
	baru->next=NULL;
	baru->prev=NULL;
	if(m->mhs==NULL){
		m->mhs=baru;
	}else{
		bantu=m->mhs;
		while(bantu->next!=NULL) bantu=bantu->next;
		bantu->next=baru;
		baru->prev=bantu;
	}
}

void addKls(int i,char name[],char kt[],char pas[],int index){
	struct Kls *baru,*bantu;
	bantu=&ada[index];
	while(bantu->next!=0){
		bantu=bantu->next;
	}
	baru=(struct Kls *)malloc(sizeof(struct Kls));
	baru->id=i;
	strcpy(baru->nam,name);
	strcpy(baru->ket,kt);
	strcpy(baru->pass,pas);
	baru->mhs=NULL;
	baru->next=NULL;
	bantu->next=baru;
}

void openHash(int i,char name[],char kt[],char pas[]){
	int index;
	index=i%10;
	if(index<0) index*=-1;
	if(ada[index].id == 0){
		ada[index].id=i;
		strcpy(ada[index].nam,name);
		strcpy(ada[index].ket,kt);
		strcpy(ada[index].pass,pas);
	}
	else{
		addKls(i,name,kt,pas,index);
	}
}

int cariTes(int i){
	int index,mode=0;
	struct Kls *bantu;
	index=i%10;
	bantu=&ada[index];
	while(bantu!=0){
		if(bantu->id==i){	
			mode++;
		}
		bantu=bantu->next;
	}
	if(mode==0) return 0;
	else return 1;
}

struct Kls *cariKls(int i){
	int index,mode=0;
	struct Kls *bantu;
	index=i%10;
	bantu=&ada[index];
	while(bantu!=0){
		if(bantu->id==i){
			return bantu;
		}
		bantu=bantu->next;
	}
}