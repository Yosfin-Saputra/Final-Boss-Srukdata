#include "kls_func.h"

void buatKls(){
	struct Kls a;
	int nilai,i=1,cek;
	menu:
	system("cls");
	
	latar();
	printf("============================================================\n");
	printf("                      BUAT KELAS\n");
	printf("============================================================\n");
	a.id=0;
	while(a.id==0){
		nilai=i;
		cek=cariTes(nilai);
		if(cek==1){
			i++;
		}else{
			a.id=i;
		}
	}
	printf("-->ID Kelas   : %d\n",a.id);
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
			temp=bantu->next;
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
			ada[index].mhs=NULL;
		}
	}
	else{
		hapus=ada[index].next;
		while((hapus->id!=bantu->id) && hapus!=NULL){
			hapus=hapus->next;
		}
		if(hapus==NULL){
			printf("Maaf, ID tidak ditemukan\n");
			return;
		}
		temp=&ada[index];
		while(temp->next!=hapus){
			temp=temp->next;
		}
		buff=hapus->next;
		temp->next=buff;
		free(hapus);
	}
}

void adaKls(){
	struct Kls *bantu;
	int i,status=0;
	system("cls");
	
	latar();
	printf("============================================================\n");
	printf("                      KELAS TERSEDIA\n");
	printf("============================================================\n");
	for(i=0;i<10;i++){
		bantu=ada[i].next;
		if(ada[i].id!=0){
			status++;
			printf("-->ID Kelas   : %d\n",ada[i].id);
			printf("-->Nama Kelas : %s\n",ada[i].nam);
			printf("-->Keterangan : %s\n",ada[i].ket);
			printf("============================================================\n");
			while(bantu!=NULL){
				printf("-->ID Kelas   : %d\n",bantu->id);
				printf("-->Nama Kelas : %s\n",bantu->nam);
				printf("-->Keterangan : %s\n",bantu->ket);
				printf("============================================================\n");
				bantu=bantu->next;
			}
		}
	}
	if(status==0){
		printf("-->Tidak ada kelas tersedia\n");
		printf("============================================================\n");
	}
}