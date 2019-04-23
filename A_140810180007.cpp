/* Nama : Putri Nabila 
   Kelas : A
   NPM : 140810180007
   Tanggal : 23 April 2019
   Deskripsi : UTS STRUKDAT PRATIKUM*/
   

#include<iostream>
#include<string.h>

using namespace std;

struct pBola{
 char name[10];
 char tim[12];
 int gol ;
 pBola* nextpbola;
};

struct Index{
 char index[1];
 pBola* FirstpBola;
 Index* next;
};

typedef Index* pointerInd;
typedef pBola* pointerCon;
typedef pointerInd listInd;

void createListInd(listInd& First){
 First=NULL;
}

void createElmtInd(pointerInd& pBaru){
 pBaru= new Index;
 cout<<"Masukan Index :"; cin>>pBaru->index;
 pBaru->next=NULL;
 pBaru->FirstpBola=NULL;
}

void createElmtpBola(pointerCon& pBaru){
 pBaru= new pBola;
 cout<<"Masukan Nama Pemain  :"; cin>>pBaru->name;
 cout<<"Masukan Nama tim  :"; cin>>pBaru->tim;
 cout<<"Masukkan jumlah Gol :" ; cin>>pBaru->gol;
 pBaru->nextpbola=NULL;
}

void traversalInd(listInd First){
 pointerInd pBantu;
 pBantu=First;
 cout<<"Index :"<<endl;
 while(pBantu!=NULL){
  cout<<"|- "<<pBantu->index<<endl;
  pBantu=pBantu->next;
 }
}

void linearSearch(listInd First,char key[20],int& status,pointerInd& pCari){
 status=0;
 pCari=First;
 while(status==0 && pCari!=NULL){
  if(strcmp(pCari->index,key)==0){
   status=1;
  }
  else{
   pCari=pCari->next;
  }
 }
}

void insertFirstInd(listInd& First,pointerInd pBaru){
 if(First==NULL){
  First=pBaru;
 }
 else{
  pBaru->next=First;
  First=pBaru;
 }
}

void deleteFirstInd(listInd& First,pointerInd pHapus){
 if(First==NULL){
  cout<<"tidak ada yang dihapus "<<endl;
 }
 else if(First->next==NULL){
  pHapus=First;
  First=NULL;
 }
 else{
  pHapus=First;
  First=pHapus->next;
  First->next=NULL;
 }
}

void insertFirstpBola(listInd& First,char key[20],pointerCon pBaru){
 pointerInd pInd;
 int ketemu;
 cout<<"Masukan Index yang di cari: "; cin>>key;
 linearSearch(First,key,ketemu,pInd);
 if(ketemu){
  cout<<"Ditemukan dengan Index :"<<pInd->index<<endl;
  if(pInd->FirstpBola==NULL){
   pInd->FirstpBola=pBaru;
  }
  else{
   pBaru->nextpbola=pInd->FirstpBola;
   pInd->FirstpBola=pBaru;
  }
 }
 else{
  cout<<" tidak di temukan"<<endl;
 }
}

void deleteFirstpbola(listInd& First,char key[20],pointerCon& pHapus ){
 int ketemu;
 pointerInd pInd;
 cout<<"Masukan Index yang di cari: "; cin>>key;
 linearSearch(First,key,ketemu,pInd);
  if(ketemu){
  cout<<"Ditemukan dengan nama :"<<pInd->index;
  if(pInd->FirstpBola==NULL){
   cout<<"Tidak ada yang di hapus"<<endl;
  }
  else if(pInd->FirstpBola->nextpbola==NULL){
   pHapus=pInd->FirstpBola;
   pInd->FirstpBola=NULL;
  }
  else{
   pHapus=pInd->FirstpBola;
   pInd->FirstpBola= pInd->FirstpBola->nextpbola;
   pHapus->nextpbola=NULL;

  }
 }
 else{
  cout<<"Nama Index tidak di temukan"<<endl;
 }
}

void traversalIndpbola(listInd First){
    pointerInd pBantuInd;
    pointerCon pBantuCon;
    cout<<"Traversal Index"<<endl;
    pBantuInd=First;
    while (pBantuInd!=NULL){ //
        cout<<"|- "<<pBantuInd->index<<endl;
        pBantuCon=pBantuInd->FirstpBola;
        while (pBantuCon!=NULL) { 
        cout<<"\t|- "<<pBantuCon->name<< " / "<<pBantuCon->tim<<"/"<<pBantuCon->gol<<endl;
        pBantuCon=pBantuCon->nextpbola;
        }
        pBantuInd=pBantuInd->next;
    }
}

main(){

    listInd q;
    int nd,nk,nt, pilih;
    char key [20];
    pointerInd pd,pc,phd;
    pointerCon pk,phk;
    createListInd(q);
    do{
        system("cls");
        cout<<"Menu"<<endl;
        cout<<"1.Insert Nama"<<endl;
        cout<<"2.Insert No daftar"<<endl;
        cout<<"3.Delete First Index"<<endl;
        cout<<"4.Delete First Nama"<<endl;
        cout<<"5.Tampilkan data pemain "<<endl;
        cout<<"6.Exit"<<endl;
        cout<<"Masukan pilihan :"; cin>>pilih;
        switch(pilih){
        case 1 :
            cout<<"Masukan banyak Index : ";
            cin>>nd;
            for(int i=0;i<nd;i++){
                createElmtInd(pd);
                insertFirstInd(q,pd);
            }
        break;
        case 2 :cout<<"Masukan banyak Nama :";
            	cin>>nk;
				cout<<"Masukkan Nama Tim   : ";
				cin>>nt;            
            traversalInd(q);
            for(int i=0;i<nk;i++){
                createElmtpBola(pk);
                insertFirstpBola(q,key,pk);
            }
        break;
        case 3 :
            deleteFirstInd(q,phd);
            traversalInd(q);
        break;
        case 4:
            deleteFirstpbola(q,key,phk);
            traversalIndpbola(q);
        break;
        case 5 :
            traversalIndpbola(q);
        break;
        default :
            exit(0);
        }
        system("pause");
    }while(pilih!=6);

}
