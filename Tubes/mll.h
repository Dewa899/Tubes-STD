#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED

#include <iostream>
using namespace std;

#define info_pr(P) (P)->info_pr
#define info_co(P) (P)->info_co

#define next(P) (P)->next
#define prev(P) (P)->prev
#define next_pr(P) (P)->next_pr

#define produk(P) (P)->produk
#define next_relasi(P) (P)->next_relasi

#define first(P) ((P).first)
//parent
struct infotype_co{
    string nama;
    int tahun;
};


typedef struct elm_co *adr_co;

typedef struct elm_relasi *adr_relasi;

typedef struct elm_pr *adr_pr;

struct elm_co{
    infotype_co info_co;
    adr_co next;
    adr_co prev;
    adr_relasi next_relasi;
};

struct list_co{
    adr_co first;
};
//relasi

struct elm_relasi{
    adr_pr produk;
    adr_relasi next;
};


//child/produk
struct infotype_pr{
        string produk;
};


struct elm_pr{
    infotype_pr info_pr;
    adr_pr next;
};

struct list_pr{
    adr_pr first;
};


// fungsi dan procedure
void newPerusahaan(adr_co &E, infotype_co X);
void newProduk(adr_pr &E, infotype_pr X);
void newProduk(adr_relasi &E, adr_pr X);

void insertPerusahaan(list_co &L1,adr_co P);
void insertProduk(list_pr &L2,adr_pr P);

adr_co searchPerusahaan(list_co &L1, string nama);
adr_pr searchProduk(list_pr &L2, string produk);

void deleteFirstPerusahaan(list_co &L1, adr_co &P);
void deleteLastPerusahaan(list_co &L1, adr_co &P);
void deleteAfterPerusahaan(list_co &L1, string nama, adr_co &P);

void addProdukPerusahaan(list_co &L1 ,list_pr &L2, string perusahaan, string produk);
void perusahaanProduk(list_co L,string produk);
void deletePerusahaan(list_co &L1, string nama, adr_co &P);
void deleteProdukPerusahaan(list_co &L1, string nama, adr_relasi &P);
void showProdukPerusahaan(list_co L1);
int hitungJenisProduk(list_co L1, string nama);
void jangkauanTerluas(list_co L1);

void menu(int no, list_co &L1, list_pr &L2);




#endif // MLL_H_INCLUDED
