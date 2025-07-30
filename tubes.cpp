#include"tubes.h"


void createListPeserta(listPeserta &P) {
    first(P) = NULL;
}

void createListLomba(listLomba &L) {
    first(L) = NULL;
}

void createListLombaPeserta(listLombaPeserta &LP) {
    first(LP) = NULL;
}

void createListJuaraLomba(listJuaraLomba &JL) {
    first(JL) = NULL;
}

adr_peserta createNewElementP(infotype_peserta P) {
    adr_peserta NP = new elmPeserta;
    info(NP) = P;
    next(NP) = NULL;
    return NP;
}

adr_lomba createNewElementL(infotype_lomba L) {
    adr_lomba NL = new elmLomba;
    info(NL) = L;
    next(NL) = NULL;
    return NL;
}

adr_lombaPeserta createNewElementLP(adr_lomba L) {
    adr_lombaPeserta LP = new elmLombaPeserta;
    nextLP(LP) = L;
    next(LP) = NULL;
    return LP;
}

adr_JuaraLomba createNewElementJL(adr_peserta P){
    adr_JuaraLomba JL = new elmJuaraLomba;
    nextJL(JL) = P;
    next(JL) = NULL;
    return JL;
}

infotype_peserta InputDataPeserta()
{
    infotype_peserta dp;
    cout<<"Nama_Peserta: ";cin>>dp.Nama_Peserta;
    cout<<"Asal_Sekolah: ";cin>>dp.Asal_Sekolah;
    cout<<"Asal_Daerah: ";cin>>dp.Asal_Daerah;
    dp.point=0;

    return dp;
}

infotype_lomba InputDataLomba()
{
    infotype_lomba dl;

    cout<<"Nama_Lomba: ";cin>>dl.Nama_Lomba;
    cout<<"Kategori: ";cin>>dl.Kategori;
    cout<<"Tingkat: ";cin>>dl.Tingkat;
    cout<<"Tempat: ";cin>>dl.Tempat;
    cout<<"Penyelenggara: ";cin>>dl.Penyelenggara;
    cout<<"Waktu_Penyelenggaraan: ";cin>>dl.Waktu_Penyelenggaraan;
    cout<<"Lama_Penyelenggaraan: ";cin>>dl.Lama_Penyelenggaraan;

    return dl;

}




// Insert First
void addPeserta(listPeserta &P, adr_peserta NP)
{
    if(first(P)==NULL)
    {
        first(P)=NP;
    }else{
      next(NP)=first(P);
      first(P)=(NP);
    }

    createListLombaPeserta(NP->LP);
}
// Insert First
void addLomba(listLomba &L, adr_lomba NL)
{
    if(first(L)==NULL)
    {
        first(L)=NL;
    }else{
      next(NL)=first(L);
      first(L)=(NL);
    }

  createListJuaraLomba(NL->JL);
}
// Insert First
void addLombaPeserta(listLombaPeserta &LP, adr_lombaPeserta NLP)
{
    if(first(LP)==NULL)
    {
        first(LP)=NLP;
    }else{
      next(NLP)=first(LP);
      first(LP)=(NLP);
    }

}




bool CekInfoPeserta(adr_peserta SP,infotype_peserta NP)
{

   return info(SP).Nama_Peserta==NP.Nama_Peserta && info(SP).Asal_Daerah==NP.Asal_Daerah;
}


bool CekInfoLomba(adr_lomba SL,infotype_lomba NL)
{
    return NL.Kategori==info(SL).Kategori && NL.Lama_Penyelenggaraan==info(SL).Lama_Penyelenggaraan && NL.Nama_Lomba==info(SL).Nama_Lomba && NL.Penyelenggara==info(SL).Penyelenggara &&
          NL.Tempat==info(SL).Tempat && NL.Tingkat== info(SL).Tingkat && NL.Waktu_Penyelenggaraan==info(SL).Waktu_Penyelenggaraan;
}

adr_peserta SearchPeserta(listPeserta P,infotype_peserta NP)
{
  if(first(P)==NULL)
  {
      return NULL;
  }else{

    adr_peserta SP=first(P);

    while(!CekInfoPeserta(SP,NP) && next(SP)!=NULL)
    {
        SP=next(SP);
    }

    if(CekInfoPeserta(SP,NP))
    {
        return SP;
    }else{
       return NULL;

    }

  }

}
adr_lomba SearchLomba(listLomba L,infotype_lomba NL)
{

  if(first(L)==NULL)
  {
      return NULL;
  }else{

    adr_lomba SL=first(L);

    while(!CekInfoLomba(SL,NL) && next(SL)!=NULL)
    {
        SL=next(SL);
    }

    if(CekInfoLomba(SL,NL))
    {
        return SL;
    }else{
       return NULL;

    }

  }

}


adr_peserta deletePeserta(listPeserta &P, infotype_peserta IP)
{
    adr_peserta DP=SearchPeserta(P,IP);


    if(SearchPeserta(P,IP)!=NULL)
    {


        adr_peserta D=first(P);

        while(next(D)!=DP)
        {
            D=next(D);
        }

        next(D)=next(DP);
        next(DP)=NULL;
    }

    return DP;
}

adr_lomba deleteLomba(listLomba &L, infotype_lomba IL)
{
    adr_lomba DL=SearchLomba(L,IL);
    if(SearchLomba(L,IL)!=NULL)
    {


        adr_lomba D=first(L);

        while(next(D)!=DL)
        {
            D=next(D);
        }

        next(D)=next(DL);
        next(DL)=NULL;
    }

    return DL;
}

void PrintInfoPeserta(adr_peserta NP)
{
    cout<<"Nama_Peserta: "<<info(NP).Nama_Peserta<<endl;
    cout<<"Asal_Sekolah: "<<info(NP).Asal_Sekolah<<endl;
    cout<<"Asal_Daerah: "<<info(NP).Asal_Daerah<<endl;
    cout<<"Point: "<<info(NP).point<<endl;
    cout<<endl;
}
void PrintInfoLomba(adr_lomba NL)
{
    cout<<"Nama_Lomba: "<<info(NL).Nama_Lomba<<endl;
    cout<<"Kategori: "<<info(NL).Kategori<<endl;
    cout<<"Tingkat: "<<info(NL).Tingkat<<endl;
    cout<<"Tempat: "<<info(NL).Tempat<<endl;
    cout<<"Penyelenggara: "<<info(NL).Penyelenggara<<endl;
    cout<<"Waktu_Penyelenggaraan: "<<info(NL).Waktu_Penyelenggaraan<<endl;
    cout<<"Lama_Penyelenggaraan: "<<info(NL).Lama_Penyelenggaraan<<endl;
    cout<<endl;

}



void showPeserta(listPeserta P)
{
    if(first(P)==NULL)
    {
        cout<<"Tidak ada peserta "<<endl;
    }else{
        adr_peserta FP=first(P);
        while(FP!=NULL)
       {
          PrintInfoPeserta(FP);
          FP=next(FP);
       }

    }


}
void showLomba(listLomba L)
{

    if(first(L)==NULL)
    {
        cout<<"TIdak ada lomba"<<endl;
    }else{
       adr_lomba FL=first(L);
       while(FL!=NULL)
       {
         PrintInfoLomba(FL);
         FL=next(FL);
       }

    }


}

void showLombaPeserta(listPeserta P,infotype_peserta IP)
{
    adr_peserta NP=SearchPeserta(P,IP);

    adr_lombaPeserta ILP=NP->LP.first;

    while(ILP!=NULL)
    {
       PrintInfoLomba(nextLP(ILP));
       ILP=next(ILP);
    }

}

void showPesertaLomba(listPeserta P,listLomba L,infotype_lomba IL)
{


    adr_peserta FP=first(P);

     while(FP!=NULL)
     {
         adr_lombaPeserta LFP=FP->LP.first;
         while(LFP!=NULL)
         {
             if(CekInfoLomba(nextLP(LFP),IL))
             {
                 PrintInfoPeserta(FP);
             }

             LFP=next(LFP);
         }

         FP=next(FP);
     }
}










