#ifndef MAINFUNC_H_
#define MAINFUNC_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <malloc.h>
#include <stddef.h>

#define CETAK "./db_cetak/absen.txt"
#define KLS "./db_kls/kelas.txt"
#define LOG "./db_log/login.txt"
#define MHS "./db_kls/mhs.txt"

struct List{
	int nim;
	char nama[50];
	char kls;
	struct List *next;
	struct List *prev;
};

struct Kls{
	int id;
	char nam[20];
	char ket[200];
	char pass[20];
	struct Kls *next;
	struct List *mhs;
};

struct Kls ada[10];

int next();
void latar();
void addMhs(char name[],int ni,char kl,struct Kls *m);
void addKls(int i,char name[],char kt[],char pas[],int index);
void openHash(int i,char name[],char kt[],char pas[]);
int cariTes(int i);
struct Kls *cariKls(int i);

#endif