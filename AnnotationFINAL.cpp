#include <iostream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
using namespace std;
    int ref[3000000];
    long nach[300000]={0};
    long endd[300000]={0};
    int mut_pos[300000];
    int mut_nuk_code[300000];
    char mut_nuk[300000];
    int g=0;

void Gran_genes (long nach[100000], long endd[100000], int qQ, FILE *ptt )
  {
    int y=0;
    int i=1;
    int k=0;
    char ch;

    while ((ch=getc(ptt))!='\n');
    while((ch=getc(ptt))!='\n');
    while((ch=getc(ptt))!='\n');

    while(i<=qQ)
    {
        while ((ch=getc(ptt))!='\t'){
            if (isdigit(ch)!=0 && k==0) {                        // This vetka, if search 2 point
            nach[i]=nach[i]*10+(int)ch-(int)'0';
            }
            if (ispunct(ch)!=0)
            k++;
            if (isdigit(ch)!=0&& k==2)
            endd[i]=endd[i]*10+(int)ch-(int)'0';
        }
        k=0;

        while((ch=getc(ptt))!='\n')
        {
            if (ch==EOF)
            {
                y=1;
                break;
            }
        }
       // cout<<nach[i]<<"\t"<<endd[i]<<"\t"<<i<<"\n";

        if (y==1)
        break;

        i++;
    }
   // cout<<"\n"<<qQ<<"\n";

}
int genes(int qQ, FILE *fna)
{

    int i=1;
    int k=0;
    char ch;

    while ((ch=getc(fna))!='\n'){
    cout<<ch;}
    cout<<ch;
    while((ch=getc(fna))!='\n'){
    if (isdigit(ch)!=0)
    qQ=qQ*10+(int)ch-(int)'0';
    }
    return qQ;
    }

void refer(int *ref, FILE *fna)
{
    int q1=0;
    char ch;

    while((ch=getc(fna))!='\n');
    while((ch=getc(fna))!=EOF)
    {
        if (ch!='\n')
        {
            if (ch=='A')
            ref[q1]=1;
            else if (ch=='T')
            ref[q1]=2;
            else if (ch=='G')
            ref[q1]=3;
            else if (ch=='C')
            ref[q1]=4;
            else cout<<"musora "<<ch;
            q1++;
            //cout<<ref[q1-1]<<"\t"<<ch<<"\n";
        }
    }
    cout<<"in ref "<<q1<<"\n";

}

void mutation(int *mut_pos, int *mut_code,int *Q, FILE *mut)
{   //cout<<"\n"<<*Q<<"\n";
    int k=0;
    int i=0;
    char ch;

    while(i<=300000)
    {
        while ((ch=getc(mut))!=' ')
        {
            if (isdigit(ch)!=0)
            {
                mut_pos[i]=mut_pos[i]*10+(int)ch-(int)'0';
            }
        }
        //cout<<mut_pos[i];

        while ((ch=getc(mut))!='\n')
        {
        if (isupper(ch)!=0){
            if (ch=='A')
            mut_nuk_code[i]=1;
            if (ch=='T')
            mut_nuk_code[i]=2;
            if (ch=='G')
            mut_nuk_code[i]=3;
            if (ch=='C')
            mut_nuk_code[i]=4;
            (*Q)++;
          //  cout<<mut_nuk_code[i]<<"\n";
            }

        i++;
        if (ch=='!'){
            i=999999;
            }
        }
        //if(*Q!=0)
        //cout<<"\n"<<*Q<<"\n";
    }


}



void InCodench(long nach[100000], long endd[100000], int mut_nuk_code[300000], int ref[3000000], int mut_pos[300000], int i,int *coden, int *codem,int qQ,int *g)
{   //cout<<(*j)<<"\t";//<<qQ<<"\n";
    int k,j = 0;
   // cout<<i<<"\n";
    while ((j)<=qQ)
    {   //cout<<mut_pos[*i]<<"\t"<<nach[j]<<"\t"<<endd[*j]<<"\n";
        if(mut_pos[i]>=nach[j] && mut_pos[i]<=endd[j])
        {
            k=1;
            (*g)=2;
            //cout<<"\t"<<nach[j]<<"\t"<<mut_pos[i]<<"\t"<<endd[j]<<"\n";
            break;
            }                            //if k=1, then mutation is in gene
        else {
            k=2;}
            (j)++;
            //if k=2, then mutation isn't in gene
    }
        //cout<<k<<"\n";
        if (k==1)
        {
          // cout <<"\n"<< ref[mut_pos[i]-2] <<ref[mut_pos[i]-1]<< ref[mut_pos[i]]<<ref[mut_pos[i]+1]<<ref[mut_pos[i]+2]<<"\n";
            //getchar();
           // cout<<(mut_pos[i]-nach[j])%3<<"\n";
            if ((mut_pos[i]-nach[j])%3==0)
                {
                (*coden)=ref[mut_pos[i]]*100+ref[mut_pos[i]+1]*10+ref[mut_pos[i]+2];
                (*codem)=mut_nuk_code[i]*100+ref[mut_pos[i]+1]*10+ref[mut_pos[i]+2];
                }
            if ((-nach[j]+mut_pos[i])%3==1)
                {
                (*coden)=ref[mut_pos[i]-1]*100+ref[mut_pos[i]]*10+ref[mut_pos[i]+1];
                (*codem)=ref[mut_pos[i]-1]*100+mut_nuk_code[i]*10+ref[mut_pos[i]+1];
                }
            if ((-nach[j]+mut_pos[i])%3==2)
                {
                (*coden)=ref[mut_pos[i]-2]*100+ref[mut_pos[i]-1]*10+ref[mut_pos[i]];
                (*codem)=ref[mut_pos[i]-2]*100+ref[mut_pos[i]-1]*10+mut_nuk_code[i];
                }
        }
//cout<<(*coden)<<"\t"<<(*codem)<<"\n";



}

 void compare (int coden,int codem, int pos )
{
    int codons[6][21]=      // A=1, T=2, G=3, C=4
    {
     {222,221,122,321,241,441,141,341,212,412,411,112,111,312,311,232,233,431,331,211,123},
     {224,223,121,322,242,442,142,342,214,414,413,114,113,314,313,234,  9,432,332,213,  9},
     {  9,421,124,323,243,443,143,343,  9,  9,  9,  9,  9,  9,  9,  9,  9,433,333,231,  9},
     {  9,422,  9,324,244,444,144,344,  9,  9,  9,  9,  9,  9,  9,  9,  9,434,334,  9,  9},
     {  9,423,  9,  9,132,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,131,  9,  9,  9},
     {  9,424,  9,  9,134,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,133,  9,  9,  9}
    };

    char  Aminok[21][4]=
    {"Phe", "Leu","Ile","Val","Ser","Pro", "Thr", "Ala", "Tyr", "His","Gin","Asn", "Lys", "Asp","Glu","Cys","Trp","Arg","Gly", "Beg", "End"};
    std::ofstream of("annotation.txt", std::ios_base::app);
    int j=0;
    int l=-1;
    int i1=0;
    int k=-1;
    int t=0;
    while (j<=20)
    {   t=0;
        while (i1<=5)
        {
            if (codons[i1][j]-coden==0)
            {k=j;
            //cout<<"coden nayden "<<codons[i1][j]<<"\t"<<coden<<" "<<k<<"\n";
            t++;
            }
            i1++;
        }
        i1=0;
         while (i1<=5)
        {
            if (codons[i1][j]-codem==0)
            {l=j;
            //cout<<"codem nayden "<<codons[i1][j]<<"\t"<<codem<<l<<"\n";
            t++;
            }
        i1++;
        }
          // cout<<i1<<"\t"<<codons[i1][j]<<"\t"<<coden<<"\t"<<codem<<"\t"<<k<<"\t"<<l<<"\n";
          // getchar();

           // cout<<i1<<"\n";


        i1=0;
        j++;
        if (t==2)
        break;
    }

   if (k!=l)
   of  <<pos<< " n  " << Aminok[k][0]<<Aminok[k][1]<<Aminok[k][2]<< " " << Aminok[l][0]<<Aminok[l][1]<<Aminok[l][2]<<"\n";
   if (k==l)
   of<<pos<< " s  " << Aminok[k][0]<<Aminok[k][1]<<Aminok[k][2]<<"\n";


}
int main()
{

FILE *ptt = fopen(argv[1], "r"), *ref=fopen(argv[2], "w"), *mut = fopen(argv[3], "w");

int j=0, Q=0;
int pos=0;
int coden=0, codem=0;
int qQ=0;
    qQ=genes(qQ, fna);
    cout<<qQ;

    Gran_genes(nach, endd,qQ, ptt);
    cout<< "Gg on\n";
    refer(ref, fna);

    cout<<"ref on\n";
    mutation(mut_pos, mut_nuk_code,&Q, mut);
    cout << "mutation on\n";
    std::ofstream of("annotation.txt");
    for(int i=0;i<=Q;i++)
    {
        pos=mut_pos[i];

        InCodench(nach, endd, mut_nuk_code, ref, mut_pos, i, &coden, &codem,qQ,&g);
        compare ( coden, codem, pos);
    }
    return 0;

    }

