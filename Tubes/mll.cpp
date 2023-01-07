#include "mll.h"
string line = "================================================================";

void newPerusahaan(adr_co &E, infotype_co X){
    E = new elm_co;
    info_co(E) = X;
    next(E) = NULL;
    prev(E) = NULL;
    next_relasi(E) = NULL;
}
void newProduk(adr_pr &E, infotype_pr X){
    E = new elm_pr;
    info_pr(E) = X;
    next(E) = NULL;
}
void newRelasi(adr_relasi &E, adr_pr X){
    E = new elm_relasi;
    produk(E) = X;
    next(E) = NULL;
}
void insertPerusahaan(list_co &L1,adr_co P){
    if (first(L1) == NULL){
        first(L1) = P;
    }else{
        adr_co Q = first(L1);
        while(next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
        prev(P) = Q;
    }
}
void insertProduk(list_pr &L2,adr_pr P){
    if (first(L2) == NULL){
        first(L2) = P;
    }else{
        adr_pr Q = first(L2);
        while(next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
}
adr_co searchPerusahaan(list_co &L1, string nama){
    adr_co P = first(L1);

    while(P != NULL){
        if (info_co(P).nama == nama){
            return P;
        }
        P = next(P);
    }
    return NULL;
}
adr_pr searchProduk(list_pr &L2, string produk){
    adr_pr P = first(L2);

    while(P != NULL){
        if (info_pr(P).produk == produk){
            return P;
        }
        P = next(P);
    }
    return P;
}
void addProdukPerusahaan(list_co &L1 ,list_pr &L2, string perusahaan, string produk){
    adr_co P = searchPerusahaan(L1, perusahaan);
    adr_pr Q = searchProduk(L2, produk);
    adr_relasi R;
    newRelasi(R,Q);
    if(P != NULL){
        if (next_relasi(P) == NULL){
            next_relasi(P) = R;
        }else{
            adr_relasi p = next_relasi(P);
            while(next(p) != NULL){
                p = next(p);
            }
            next(p) = R;
        }
    }
}
void perusahaanProduk(list_co L,string produk){
    adr_co P = first(L);
    adr_relasi p;
    cout<<line<<endl;
    cout<<"Perusahaan dengan produk "<< produk<<endl;
    while(P != NULL){
        p = next_relasi(P);
        while(p != NULL){
            if(produk == info_pr(produk(p)).produk){
                cout<<info_co(P).nama<<endl;
            }
            p = next(p);
        }
        P = next(P);
    }
}
//membuat semua jenis fungsi delete untuk perusahaan
void deleteFirstPerusahaan(list_co &L1, adr_co &P){
    P = first(L1);
    first(L1) = next(P);
    prev(first(L1)) = NULL;
    next(P) = NULL;
}
void deleteLastPerusahaan(list_co &L1, adr_co &P){
    P = first(L1);
    while(next(P) != NULL){
        P = next(P);
    }
    next(prev(P)) = NULL;
    prev(P) = NULL;

}
void deleteAfterPerusahaan(list_co &L1, string nama, adr_co &P){
    P = searchPerusahaan(L1,nama);
    adr_co q = prev(P);

    next(q) = next(P);
    prev(next(P)) = q;
    next(P) = NULL;
    prev(P) = NULL;
}
void deletePerusahaan(list_co &L1, string nama, adr_co &P){
    P = searchPerusahaan(L1, nama);
    adr_relasi Q;
    if(P != NULL){
        while(next_relasi(P) != NULL){
        deleteProdukPerusahaan(L1,nama,Q);
        }
        if(P == first(L1)){
            deleteFirstPerusahaan(L1,P);
        }else if(next(P) == NULL){
            deleteLastPerusahaan(L1,P);
        }else{
            deleteAfterPerusahaan(L1,nama,P);
        }
        cout << "Perusahaan telah dihapus" << endl;
    }else{
        cout<<"Data perusahaan tersebut tidak ditemukan!"<<endl;
    }

}
void deleteProdukPerusahaan(list_co &L1, string nama, adr_relasi &P){
    adr_co Q = searchPerusahaan(L1, nama);

    if(Q != NULL){
        adr_relasi R = next_relasi(Q);
        adr_relasi prec;
        if(R != NULL){
            while(next(R) != NULL){
                prec = R;
                R = next(R);
            }
            if(R == next_relasi(Q)){
                next_relasi(Q) = NULL;
            }else{
                P = R;
                next(prec) = NULL;
            }
        }

        cout << "Produk telah dihapus" << endl;
    }else{
        cout<<"Data perusahaan tersebut tidak ditemukan!"<<endl;
    }


}
void showProdukPerusahaan(list_co L1){
    adr_co P = first(L1);
    adr_relasi p;
    cout<<"====================================== DAFTAR =============================="<<endl;
    cout<<"============================== Perusahaan dan Produk ======================="<<endl;
    while(P != NULL){
        cout<<"Perusahaan "<< info_co(P).nama<<endl;
        cout<<"Produk :"<<endl;
        p = next_relasi(P);
        while(p != NULL){
            cout<<info_pr(produk(p)).produk<<endl;
            p = next(p);
        }
        cout<<endl;
        P = next(P);
    }
}
void infoPerusahaan(list_co L1,string nama){
    adr_co P = searchPerusahaan(L1,nama);
    if (P != NULL){
        adr_relasi p = next_relasi(P);
        cout<<line<<endl;
        cout<<"Perusahaan "<< info_co(P).nama<<endl;
        cout<<"Berdiri sejak "<< info_co(P).tahun<<endl;
        cout<<"Produk : "<< endl;
        while(p != NULL){
            cout<<info_pr(produk(p)).produk<<endl;
            p = next(p);
        }
        cout<<endl;
    }else{
        cout<<"Data perusahaan tersebut tidak ditemukan!"<<endl;
    }

}
int hitungJenisProduk(list_co L1, string nama){

    adr_co P = searchPerusahaan(L1,nama);
    adr_relasi p;
    int tot = 0;
    p = next_relasi(P);
    while(p != NULL){
        tot++;
        p = next(p);
    }
    return tot;
}
void jangkauanTerluas(list_co L1){
    cout<<"Perusahaan dengan jangkauan terluas adalah :"<<endl;
    adr_co P = first(L1);
    int top = 0;
    while(P != NULL){
        if(hitungJenisProduk(L1,info_co(P).nama) > top){
            top = hitungJenisProduk(L1,info_co(P).nama);
        }
        P = next(P);
    }
    P = first(L1);
    while(P != NULL){
        if(hitungJenisProduk(L1,info_co(P).nama) == top){
            cout<<info_co(P).nama<<endl;
        }
        P = next(P);
    }
}
void menu(int no, list_co &L1, list_pr &L2){

    adr_co P;
    adr_pr Q;
    adr_relasi R;
    infotype_co X;
    infotype_pr Y;
    string nama;
    string produk;
    int total;
    switch (no){
        case 1:
            cout<<"Masukkan  nama perusahaan :";
            cin>>X.nama;
            cout<<"Masukkan tahun perusahaan berdiri :";
            cin>>X.tahun;
            newPerusahaan(P,X);
            insertPerusahaan(L1,P);
            break;
        case 2:
            cout<<"Masukkan nama produk :";
            cin>>Y.produk;
            newProduk(Q,Y);
            insertProduk(L2,Q);
            break;
        case 3:
            cout<<"Masukkan nama perusahaan :";
            cin>>nama;
            infoPerusahaan(L1,nama);
            break;
        case 4:
            cout << "Masukkan nama produk :";
            cin >> produk;
            cout << "Masukkan nama perusahaan :";
            cin >> nama;
            addProdukPerusahaan(L1, L2, nama, produk);
            break;
        case 5:
            cout << "Masukkan nama produk :";
            cin>>produk;
            perusahaanProduk(L1, produk);
            break;
        case 6:
            cout << "Masukkan nama perusahaan :";
            cin >> nama;
            deletePerusahaan(L1, nama, P);
            break;
        case 7:
            cout << "Masukkan nama perusahaan :";
            cin >> nama;
            deleteProdukPerusahaan(L1, nama, R);
            break;
        case 8:
            showProdukPerusahaan(L1);
            break;
        case 9:
            cout << "Masukkan nama perusahaan :";
            cin >> nama;
            total = hitungJenisProduk(L1, nama);
            cout << total << endl;
            break;
        case 10:
            jangkauanTerluas(L1);
        case 0:
            break;
        default:
            cout << "Masukan salah!"<< endl;
    }
}

