#include "lib/main_func.h"
#include "lib/check_func.h"
#include "lib/kls_func.h"
#include "lib/absen_func.h"


void dosenSign();
void menuMhs();
void dosen();
void editKls(struct Kls *bantu);
void lihatKls(struct Kls *bantu);
void cekId();
void loginDosen();
void signUp();


int main(){
	int pil;
	
	checkDirect();
	tes();
	
	do{
		system("cls");
		
		latar();
		printf("============================================================\n");
		printf("                      MENU LOGIN\n");
		printf("============================================================\n");
		printf("--> 1. Sebagai Dosen\n");
		printf("--> 2. Sebagai Mahasiswa\n");
		printf("--> 3. Keluar\n");
		printf("============================================================\n");
		printf("--> Pilih menu : ");
		scanf("%d",&pil);
		printf("============================================================\n");
		
		switch(pil){
			case 1:
				dosenSign();
				break;
			case 2:
				menuMhs();
				break;
			case 3:
				
				break;
			default:
				break;
		}
		
	}while(pil!=3);
	
	return 0;
}

void dosenSign(){
	int pil;
	
	do{
		system("cls");
		
		latar();
		printf("============================================================\n");
		printf("                      MENU DOSEN\n");
		printf("============================================================\n");
		printf("--> 1. Sign In\n");
		printf("--> 2. Sign Up\n");
		printf("--> 3. Hapus Akun\n");
		printf("--> 4. Kembali\n");
		printf("============================================================\n");
		printf("--> Pilih menu : ");
		scanf("%d",&pil);
		printf("============================================================\n");
		
		switch(pil){
			case 1:
				loginDosen(1);
				break;
			case 2:
				signUp();
				break;
			case 3:
				loginDosen(2);
				break;
			case 4:
				break;
			default:
				break;
		}
		
	}while(pil!=4);
}

void menuMhs(){
	int pil,lanjut=1;
	
	do{
		system("cls");
		
		latar();
		printf("============================================================\n");
		printf("                     MENU MAHASISWA\n");
		printf("============================================================\n");
		printf("--> 1. Absensi\n");
		printf("--> 2. Lihat Kelas\n");
		printf("--> 3. Kembali\n");
		printf("============================================================\n");
		printf("--> Pilih menu : ");
		scanf("%d",&pil);
		printf("============================================================\n");
		
		switch(pil){
			case 1:
				cekId(3);
				break;
			case 2:
				adaKls();
				lanjut=next(1);	
				break;
			case 3:
					
				break;
			default:
				break;
		}
		
	}while(pil!=3 && lanjut==1);	
}

void dosen(){
	int pil,lanjut=1;
	
	do{
		system("cls");
		
		latar();
		printf("============================================================\n");
		printf("                      MENU DOSEN\n");
		printf("============================================================\n");
		printf("--> 1. Buat Kelas\n");
		printf("--> 2. Edit dan Lihat Kelas\n");
		printf("--> 3. Lihat Absensi Kelas\n");
		printf("--> 4. Kelas yang Tersedia\n");
		printf("--> 5. Kembali\n");
		printf("============================================================\n");
		printf("--> Pilih menu : ");
		scanf("%d",&pil);
		printf("============================================================\n");
		
		switch(pil){
			case 1:
				buatKls();
				break;
			case 2:
				
				cekId(1);
				break;
			case 3:
				
				cekId(2);
				break;
			case 4:
				adaKls();
				lanjut=next(1);
				break;
			case 5:
				break;
			default:
				break;
		}
		
	}while(pil!=5 && lanjut==1 );
}

void editKls(struct Kls *bantu){
	int pil,lanjut=1;
	
	do{
		system("cls");
		
		latar();
		printf("============================================================\n");
		printf("                      MENU DOSEN\n");
		printf("============================================================\n");
		printf("                 EDIT DAN LIHAT KELAS\n");
		printf("============================================================\n");
		printf("--> 1. Edit Kelas\n");
		printf("--> 2. Lihat Tampilan Kelas\n");
		printf("--> 3. Hapus Kelas\n");
		printf("--> 4. Kembali\n");
		printf("============================================================\n");
		printf("--> Pilih menu : ");
		scanf("%d",&pil);
		printf("============================================================\n");
		
		switch(pil){
			case 1:
				bantu=modifKls(bantu);
				break;
			case 2:
				viewKls(bantu);
				lanjut=next(1);
				break;
			case 3:
				lanjut=next(3);
				if(lanjut==1){
					delKls(bantu);
					lanjut=0;
				}
				break;
			case 4:
				break;
			default:
				break;
		}
		
	}while(pil!=4 && lanjut==1 );
}

void lihatKls(struct Kls *bantu){
	int pil,lanjut=1;
	
	do{
		system("cls");
		
		latar();
		printf("============================================================\n");
		printf("                      MENU DOSEN\n");
		printf("============================================================\n");
		printf("                 LIHAT ABSENSI KELAS\n");
		printf("============================================================\n");
		printf("--> 1. Lihat Absensi\n");
		printf("--> 2. Edit Absensi\n");
		printf("--> 3. Cetak Absensi\n");
		printf("--> 4. Kembali\n");
		printf("============================================================\n");
		printf("--> Pilih menu : ");
		scanf("%d",&pil);
		printf("============================================================\n");
		
		switch(pil){
			case 1:
				lihatAbsen(bantu->mhs);
				lanjut=next(1);
				break;
			case 2:
					
				break;
			case 3:
				
				lanjut=next(1);
				break;
			case 4:
				break;
			default:
				break;
		}
		
	}while(pil!=4 && lanjut==1 );
}

void cekId(int n){
	int a,temu;
	char pass[20];
	struct Kls *bantu;
	menu:
	system("cls");
	
	latar();
	printf("============================================================\n");
	printf("                       CEK ID KELAS\n");
	printf("============================================================\n");
	printf("-->ID Kelas : ");   
	scanf("%d",&a);
	temu=cariTes(a);
	if(temu==1){
		printf("-->Password : ");
		fflush(stdin);
		scanf("%[^\n]s",pass);
		bantu=cariKls(a);
		temu=strcmp(pass,bantu->pass);
		
		if(temu==0){
			printf("============================================================\n");
			if(n==1) editKls(bantu);
			else if(n==2) lihatKls(bantu);
			else absenMhs(bantu);
			return;
		}else{
			printf("-->Maaf, password salah\n");
			printf("============================================================\n");
		}
		
	}else{
		printf("-->Maaf, ID tidak ditemukan\n");
		printf("============================================================\n");
	}
	temu=next(2);
	if(temu==1) goto menu;
	else return;
}

void loginDosen(int n){
	char user[20],pass [20];
	menu:
	system("cls");
	
	latar();
	printf("============================================================\n");
	printf("                         SIGN IN\n");
	printf("============================================================\n");
	printf("-->Username : ");
	fflush(stdin);
	scanf("%[^\n]s",user);
	printf("-->Password : ");
	fflush(stdin);
	scanf("%[^\n]s",pass);
	int cek=loginD(user,pass);
	if(cek==1){
		if(n==1){
			printf("============================================================\n");
			dosen();
		}
		else{
			int cekU=strcmp(user,"admin");
			int cekP=strcmp(pass,"admin");
			
			if(cekU=cekP==0){
				printf("-->Maaf, akun admin tidak dapat dihapus\n");  //admin tidak boleh dihapus agar ada 1 akun login 
				printf("============================================================\n");
				cek=next(2);
				if(cek==1) goto menu;
			}else {
				printf("============================================================\n");
				hapus(user,pass);
			}
		}
	}else{
		printf("-->Maaf, username atau password salah\n");
		printf("============================================================\n");
		cek=next(2);
		if(cek==1) goto menu;
	}
}

void signUp(){
	char user[20],pas[20],nam[30];
	int ni,kod=10;
	menu:
	system("cls");
	
	latar();
	printf("============================================================\n");
	printf("                         SIGN UN\n");
	printf("============================================================\n");
	printf("-->Kode     : ");
	scanf("%d",&kod);
	printf("-->Username : ");
	fflush(stdin);
	scanf("%[^\n]s",user);
	printf("-->Nama     : ");
	fflush(stdin);
	scanf("%[^\n]s",nam);
	printf("-->NIP      : ");
	scanf("%d",&ni);
	printf("-->Password : ");
	fflush(stdin);
	scanf("%[^\n]s",pas);
	printf("============================================================\n");
	kod=addD(user,pas,nam,ni,kod);
	printf("============================================================\n");
	if(kod==0){                  //jika gagal, ditanya diulang?
		kod=next(2);
		if(kod==1) goto menu;
	}
}

