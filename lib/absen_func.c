#include "absen_func.h"

void absenMhs(struct Kls *bantu){
	struct List b;
	int temu;
	menu:
	system("cls");
	
	latar();
	printf("============================================================\n");
	printf("                  MENU ABSENSI MAHASISWA\n");
	printf("============================================================\n");
	printf("-->Nama  : ");
	fflush(stdin);
	scanf("%[^\n]s",b.nama);
	printf("-->NIM   : ");
	scanf("%d",&b.nim);
	printf("-->Kelas : ");
	fflush(stdin);
	scanf("%c",&b.kls);
	printf("============================================================\n");
	addMhs(b.nama,b.nim,b.kls,bantu);
}

void lihatAbsen(struct List *bantu){
	int status=0;
	system("cls");
	
	latar();
	printf("============================================================\n");
	printf("                LIHAT ABSENSI MAHASISWA\n");
	printf("============================================================\n");
	printf("+---------------+----------------------------------+-------+\n");
	printf("|      NIM      |          NAMA MAHASISWA          | KELAS |\n");
	printf("+---------------+----------------------------------+-------+\n");
	while(bantu!=NULL){
		status++;
		printf("|  %-11d  | %-32s |   %c   |\n",bantu->nim,bantu->nama,bantu->kls);
		bantu=bantu->next;
	}
	if(status==0){
		printf("|       -       |                -                 |   -   |\n");
	}
	printf("+---------------+----------------------------------+-------+\n");
	printf("============================================================\n");
}

void cetakAbsen(struct Kls *bantu){
	struct List *cek;
	FILE*file;
	int status=0,total=0;
	
	file=fopen("./db_cetak/kelas.txt","w");
	cek=bantu->mhs;
	
	fprintf(file,"============================================================\n");
	fprintf(file,"                  DATA ABSENSI MAHASISWA\n");
	fprintf(file,"============================================================\n");
	fprintf(file,"   ID Kelas   : %d\n",bantu->id);
	fprintf(file,"   Nama Kelas : %s\n",bantu->nam);
	fprintf(file,"   Keterangan : %s\n",bantu->ket);
	fprintf(file,"   Password   : %s\n",bantu->pass);
	fprintf(file,"============================================================\n");
	fprintf(file,"+---------------+----------------------------------+-------+\n");
	fprintf(file,"|      NIM      |          NAMA MAHASISWA          | KELAS |\n");
	fprintf(file,"+---------------+----------------------------------+-------+\n");
	while(cek!=NULL){
		status++;
		fprintf(file,"|  %-11d  | %-32s |   %c   |\n",cek->nim,cek->nama,cek->kls);
		cek=cek->next;
	}
	if(status==0){
		fprintf(file,"|       -       |                -                 |   -   |\n");
	}
	fprintf(file,"+---------------+----------------------------------+-------+\n");
	fprintf(file,"| Total Mahasiswa                                  |  %-3d  |\n",total);
	fprintf(file,"+---------------+----------------------------------+-------+\n");
	fprintf(file,"============================================================\n");
	
	
	fclose(file);
	delKls(bantu);
}

void modifAbsen(struct Kls *bantu){
	struct List *cek,*head,*depan,*blkng;
	int pil,status=0;
	
	lihatAbsen(bantu->mhs);
	
	if(bantu->mhs==NULL){
		printf("-->Maaf, tidak ada mahasiswa\n");
		return;
	}
	
	printf("-->Pilih NIM yang ingin dihapus : ");
	scanf("%d",&pil);
	cek=bantu->mhs;
	head=cek;
	while(status!=0){
		if(cek->nim==pil){
			status=1;
			if(cek==head){
				if(cek->next!=NULL){
					head=head->next;
					head->prev=NULL;
					bantu->mhs=head;
					free(cek);	
				}else{
					bantu->mhs=NULL;
					free(cek);
				}
			}else{
				if(cek->next!=NULL){
					depan=cek->next;
					blkng=cek->prev;
					blkng->next=depan;
					depan->prev=blkng;
					free(cek);
				}else{
					blkng=cek->prev;
					blkng->next=NULL;
					free(cek);
				}
			}
		}
		cek=cek->next;
	}
	
}