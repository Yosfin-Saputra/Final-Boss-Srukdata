#ifndef MAINFUNC_H_
#define MAINFUNC_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <malloc.h>
#include <stddef.h>

#define CETAK "./db_cetak/absen.txt"

//struct List{
//	int nim;
//	char nama[50];
//	char kls;
//	struct List *next;
//	struct List *prev;
//};
//
struct Kls{
	int id;
	char nam[20];
	char ket[200];
	char pass[20];
	struct Kls *next;
//	struct List *mhs;
};

struct Kls ada[10];

int next();
void latar();
//void addMhs(int nim, char nama[],char kls, struct List *mhs);
//void addKls(int id,char nama[],char ket[],char pass[],int index);
void openHash(int id,char nama[],char ket[],char pass[]);
//void cari(int id,int nim,char nama[],char kls);
int cariTes(int i);
struct Kls *cariKls(int i);

#endif