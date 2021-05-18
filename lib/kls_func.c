#include "kls_func.h"

void buatKls(){
	struct Kls a;
	int temu;
	menu:
	system("cls");
	
	latar();
	printf("============================================================\n");
	printf("                      BUAT KELAS\n");
	printf("============================================================\n");
	printf("-->ID Kelas   : ");
	scanf("%d",&a.id);
	temu=cariTes(a.id);
	if(temu==1){
		printf("-->Maaf, ID sudah digunakan\n");
		printf("============================================================\n");
		temu=next(2);
		if(temu==1) goto menu;
		else return;
	}
	printf("-->Nama Kelas : ");
	fflush(stdin);
	scanf("%[^\n]s",a.nam);
	printf("-->Keterangan : ");
	fflush(stdin);
	scanf("%[^\n]s",a.ket);
	printf("-->Password   : ");
	fflush(stdin);
	scanf("%[^\n]s",a.pass);
	printf("============================================================\n");
	openHash(a.id,a.nam,a.ket,a.pass);
}

void viewKls(struct Kls *bantu){
	system("cls");
	
	latar();
	printf("============================================================\n");
	printf("                 EDIT DAN LIHAT KELAS\n");
	printf("============================================================\n");
	printf("-->ID Kelas   : %d\n",bantu->id);
	printf("-->Nama Kelas : %s\n",bantu->nam);
	printf("-->Keterangan : %s\n",bantu->ket);
	printf("-->Password   : %s\n",bantu->pass);
	printf("============================================================\n");
}

struct Kls *modifKls(struct Kls *bantu){
	struct Kls *s;
	struct Kls a;
	system("cls");
	
	latar();
	printf("============================================================\n");
	printf("                 EDIT DAN LIHAT KELAS\n");
	printf("============================================================\n");
	printf("-->ID Kls Lama   : %d\n",bantu->id);
	printf("-->ID Kls Baru   : ");
	scanf("%d",&a.id);
	printf("-->Pass Lama     : %s\n",bantu->pass);
	printf("-->Pass Baru     : ");
	fflush(stdin);
	scanf("%[^\n]s",a.pass);
	printf("-->Nama Kls Lama : %s\n",bantu->nam);
	printf("-->Nama Kls Baru : ");
	fflush(stdin);
	scanf("%[^\n]s",a.nam);
	printf("-->Ket. Lama     : %s\n",bantu->ket);
	printf("-->Ket. Baru     : ");
	fflush(stdin);
	scanf("%[^\n]s",a.ket);
	printf("============================================================\n");
	openHash(a.id,a.nam,a.ket,a.pass);
	delKls(bantu);
	s=cariKls(a.id);
	return s;
}

void delKls(struct Kls *bantu){
	struct Kls *hapus,*temp,*buff;
	int index;
	index=bantu->id%10;
	if(index<0) index*=-1;
	if(ada[index].id == bantu->id){
		if(bantu->next!=NULL){
			bantu->next=temp;
			ada[index].id=temp->id;
			strcpy(ada[index].nam,temp->nam);
			strcpy(ada[index].ket,temp->ket);
			strcpy(ada[index].pass,temp->pass);
			ada[index].next=temp->next;
			free(temp);
		}else{
			ada[index].id=0;
			strcpy(ada[index].nam,"");
			strcpy(ada[index].ket,"");
			strcpy(ada[index].pass,"");
			ada[index].next=NULL;
		}
	}
	else{
		hapus=&ada[index];
		while(hapus->id!=bantu->id && hapus!=NULL){
			hapus=hapus->next;
		}
		if(hapus==NULL){
			printf("Maaf, ID tidak ditemukan\n");
			return;
		}
		while(temp->next!=hapus){
			temp=temp->next;
		}
		buff=hapus->next;
		temp->next=buff;
		free(hapus);
	}
}