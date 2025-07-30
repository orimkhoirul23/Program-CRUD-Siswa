#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>

using namespace std;

#define first(L) L.first
#define last(L) L.last
#define info(P) (P)->info
#define next(P) (P)->next
#define nextLP(P) (P)->nextLP
#define nextJL(P) (P)->nextJL



struct infotype_peserta{
    string Nama_Peserta;
    string Asal_Sekolah;
    string Asal_Daerah;
    int point;


};

struct infotype_lomba{
    string Nama_Lomba;
    string Penyelenggara;
    string Tempat;
    string Kategori;
    string Waktu_Penyelenggaraan;
    int Lama_Penyelenggaraan;
    string Tingkat;
};



typedef struct elmJuaraLomba *adr_JuaraLomba;
typedef struct elmPeserta *adr_peserta;
typedef struct elmLombaPeserta *adr_lombaPeserta;
typedef struct elmLomba *adr_lomba;


struct elmJuaraLomba{
 adr_peserta nextJL;
 adr_JuaraLomba next;

};


struct listJuaraLomba{
adr_JuaraLomba first;

};

struct elmLombaPeserta{
 adr_lomba nextLP;
 adr_lombaPeserta next;

};

struct listLombaPeserta{
adr_lombaPeserta first;

};

struct elmLomba{
    infotype_lomba info;
    adr_lomba next;
    listJuaraLomba JL;
};

struct listLomba{
    adr_lomba first;

};

struct elmPeserta{
    infotype_peserta info;
    adr_peserta next;
    listLombaPeserta LP;
};

struct listPeserta{
    adr_peserta first;
};



void createListPeserta(listPeserta &P);
void createListLomba(listLomba &L);
void createListLombaPeserta(listLombaPeserta &LP);
void createListJuaraLomba(listJuaraLomba &JL);

adr_peserta createNewElementP(infotype_peserta P);
adr_lomba createNewElementL(infotype_lomba L);
adr_lombaPeserta createNewElementLP(adr_lomba L);
adr_JuaraLomba createNewElementJL(adr_peserta P);

void addPeserta(listPeserta &P, adr_peserta NP);
void addLomba(listLomba &L, adr_lomba NL);
void addLombaPeserta(listLombaPeserta &LP, adr_lombaPeserta NLP);

adr_lombaPeserta PesertaJoinLomba(listPeserta P,listLomba L,infotype_peserta IP,infotype_lomba IL);

bool CekInfoPeserta(adr_peserta,infotype_peserta);
bool CekInfoLomba(adr_lomba,infotype_lomba);

infotype_lomba InputDataLomba();
infotype_peserta InputDataPeserta();

adr_peserta SearchPeserta(listPeserta P,infotype_peserta NP);
adr_lomba SearchLomba(listLomba L,infotype_lomba NL);

adr_peserta deletePeserta(listPeserta &P, infotype_peserta IP);
adr_lomba deleteLomba(listLomba &L, infotype_lomba IL);

void PrintInfoPeserta(adr_peserta NP);
void PrintInfoLomba(adr_lomba NL);

void showPeserta(listPeserta P);
void showLomba(listLomba L);
void showLombaPeserta(infotype_peserta IP);
void showPesertaLomba(infotype_lomba IL);

void searchTingkatKejuaraan();

int jumlahPesertaLomba(listPeserta P, listLomba L, string namaPeserta);
int jumlahLombaPeserta(listPeserta P, listLomba L, string namaLomba);

int durasiLomba(string namaPeserta);



#endif // TUBES_H_INCLUDED
