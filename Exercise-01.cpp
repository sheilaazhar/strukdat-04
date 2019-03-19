/*
Nama		: Sheila Azhar Almufarida
NPM			: 140810180001
Tanggal		: 19 Maret 2019
Nama Program: Exercise-01
Deskripsi	: Input nama panjang, divisi, dan gaji pegawai menggunakan fungsi single linked list
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

struct pegawai{
    char nama[30];
    char divisi[15];
    int gaji;
    pegawai* next;
};
typedef pegawai* pointer;
typedef pointer List;

void createList(List& First){
    First = NULL;
    }

void createElmt (pointer& pBaru){
    pBaru = new pegawai;
    cin.ignore();
    cout<<"Nama     : "; cin.getline(pBaru->nama, 30);
    cout<<"Bidang   : "; cin>>pBaru->divisi;
    cout<<"Gaji     : "; cin>>pBaru->gaji;
    pBaru->next=NULL;
}

void insertFirst (List& First, pointer pBaru){
    if(First==NULL){
        First=pBaru;
    }
    else{
        pBaru->next=First;
        First=pBaru;
    }
}

void insertLast (List& First, pointer pBaru){
    pointer Last;
    if (First==NULL){
        First=pBaru;
    }
    else {
        Last=First;
        while (Last->next!=NULL){
            Last=Last->next;
        }
        Last->next=pBaru;
    }
}
void traversal (List First){
    pointer pBantu;
    pBantu=First;
    while(pBantu != NULL){
        cout<<"Nama     : "<<pBantu->nama<<endl;
        cout<<"Bidang   : "<<pBantu->divisi<<endl;
        cout<<"Gaji     : "<<pBantu->gaji<<endl;
        pBantu=pBantu->next;
        cout<<endl;
    }
}

void deleteFirst(List& First, pointer& pHapus){
    if(First==NULL){
        pHapus=NULL;
        cout<<"List kosong, tidak ada  yang dihapus"<<endl;
    }
    else if(First->next==NULL){
        pHapus=First;
        First=NULL;
    }
    else {
        pHapus=First;
        First=First->next;
        pHapus->next=NULL;
    }
}

void deleteLast (List& First, pointer& pHapus){
    pointer Last, precLast;
    if (First==NULL){
        pHapus=NULL;
        cout<<"List kosong, tidak ada yang dihapus"<<endl;
    }
    else if(First->next==NULL){
        pHapus=First;
        First=NULL;
    }
    else {
        Last=First;
        precLast=NULL;
        while (Last->next!=NULL){
            precLast=Last;
            Last=Last->next;
        }
        pHapus=Last;
        precLast->next=NULL;
    }
}

main()
{
    pointer pBaru;
    List first;
    int pilihan;

    createList(first);
    while(1){
        system("cls");
        cout<<"Menu Data Pegawai"<<endl;
        cout<<"1. Tambah data di awal "<<endl;
        cout<<"2. Tambah data di akhir"<<endl;
        cout<<"3. Hapus data paling awal"<<endl;
        cout<<"4. Hapus data paling akhir"<<endl;
        cout<<"5. Tampilkan data"<<endl;
        cout<<"6. Exit"<<endl;
        cout << "Masukan Pilihan : "; cin >> pilihan;
        switch(pilihan){
        case 1:
            createElmt(pBaru);
            insertFirst(first, pBaru);
        break;

        case 2:
            createElmt(pBaru);
            insertLast(first, pBaru);
        break;

        case 3:
            deleteFirst(first, pBaru);
        break;

        case 4:
            deleteLast(first, pBaru);
        break;

        case 5:
            traversal(first);
        break;

        case 6:
            return 0;
            break;
        }
        system("pause");
    }
}
