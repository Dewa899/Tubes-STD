#include <iostream>
#include "mll.h"
using namespace std;

int main()
{
    //list perusahaan baru
    list_co L1;
    first(L1) = NULL;
    //elemen perusahaan baru
    adr_co E;
    infotype_co X;

    X.nama = "Apple";
    X.tahun = 1990;
    newPerusahaan(E,X);
    insertPerusahaan(L1,E);

    X.nama = "Honda";
    X.tahun = 1876;
    newPerusahaan(E,X);
    insertPerusahaan(L1,E);

    X.nama = "IKEA";
    X.tahun = 1876;
    newPerusahaan(E,X);
    insertPerusahaan(L1,E);

    X.nama = "KYT";
    X.tahun = 1876;
    newPerusahaan(E,X);
    insertPerusahaan(L1,E);

    X.nama = "Uniclo";
    X.tahun = 1876;
    newPerusahaan(E,X);
    insertPerusahaan(L1,E);

    X.nama = "Asus";
    X.tahun = 1876;
    newPerusahaan(E,X);
    insertPerusahaan(L1,E);


    // list produk baru
    list_pr L2;
    first(L2) = NULL;
    //elemen produk baru
    adr_pr P;
    infotype_pr Y;

    Y.produk = "Handphone";
    newProduk(P,Y);
    insertProduk(L2,P);

    Y.produk = "Otomotif";
    newProduk(P,Y);
    insertProduk(L2,P);

    Y.produk = "Laptop";
    newProduk(P,Y);
    insertProduk(L2,P);

    Y.produk = "Asuransi";
    newProduk(P,Y);
    insertProduk(L2,P);

    Y.produk = "Mabel";
    newProduk(P,Y);
    insertProduk(L2,P);

    Y.produk = "Bangunan";
    newProduk(P,Y);
    insertProduk(L2,P);

    Y.produk = "Fashion";
    newProduk(P,Y);
    insertProduk(L2,P);


    //menyambungkan perusahaan dengan produk menggunakan relasi
    addProdukPerusahaan(L1,L2,"Apple","Handphone");
    addProdukPerusahaan(L1,L2,"Apple","Laptop");
    addProdukPerusahaan(L1,L2,"Asus","Laptop");
    addProdukPerusahaan(L1,L2,"Asus","Handphone");
    showProdukPerusahaan(L1);
    perusahaanProduk(L1,"Laptop");
    jangkauanTerluas(L1);

    adr_relasi T;
    deleteProdukPerusahaan(L1,"Apple",T);
    deleteProdukPerusahaan(L1,"Asus",T);
    showProdukPerusahaan(L1);

    deletePerusahaan(L1,"Apple",E);
    deletePerusahaan(L1,"KYT",E);
    showProdukPerusahaan(L1);

    int no = 11;
    while(no != 0){
        cout << " -------------------------------------------------------------------------------------------" <<endl;
        cout << "| 	                               MENU CORPORATION                                     |" << endl;
        cout << " -------------------------------------------------------------------------------------------" <<endl;
        cout<<"| [1]  Menambahkan data perusahaan.                                                        |"  <<endl;
        cout<<"| [2]  Menambahkan data jenis produk.                                                      |"  <<endl;
        cout<<"| [3]  Mencari data perusahaan tertentu.                                                   |"  <<endl;
        cout<<"| [4]  Menambahkan relasi perusahaan dengan jenis produk yang ditawarkannya.               |"  <<endl;
        cout<<"| [5]  Mencari data perusahaan yang memiliki jenis produk tertentu.                        |"  <<endl;
        cout<<"| [6]  Menghapus data perusahaan berserta relasinya.                                       |"  <<endl;
        cout<<"| [7]  Menghapus data jenis produk pada perusahaan tertentu.                               |"  <<endl;
        cout<<"| [8]  Menampilkan data seluruh perusahaan beserta semua jenis produk yang ditawarkannya.  |"  <<endl;
        cout<<"| [9]  Menghitung banyaknya jenis produk yang dimiliki oleh suatu perusahaan.              |"  <<endl;
        cout<<"| [10] Menampilkan data perusahaan yang memiliki jangkauan layanan paling luas.            |"  <<endl;
        cout<<"| [0]  Keluar                                                                              |"  <<endl;
        cout<< " ------------------------------------------------------------------------------------------" << endl;
        cout<<endl<<"==> Mau nomor berapa? : ";
        cin>>no;
        menu(no,L1,L2);
    }


    return 0;
}
