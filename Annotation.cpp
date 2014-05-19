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

void Gran_genes (long nach[100000], long endd[100000], int qQ)
  {

    int i=1;
    int k=0;
    char ch;
    FILE *in;

  if((in=fopen("C:\\DNA_code2.ptt", "r"))==NULL) {
    printf("File can't be open.\n");
    exit(1);
  }
    while ((ch=getc(in))!='\n'){
    }

    while((ch=getc(in))!='\n'){
    }

    while((ch=getc(in))!='\n');


    while(i<=qQ)
    {
        while ((ch=getc(in))!='\t'){
            if (isdigit(ch)!=0 && k==0) {                        // This vetka, if search 2 point
            nach[i]=nach[i]*10+(int)ch-(int)'0';
            }
            if (ispunct(ch)!=0)
            k++;
            if (isdigit(ch)!=0&& k==2)
            endd[i]=endd[i]*10+(int)ch-(int)'0';
        }
        k=0;
        //cout<<nach[i]<<"\t"<<endd[i]<<"\n";
        while((ch=getc(in))!='\n');
        i++;
    }
    cout<<"\n"<<qQ<<"\n";

}
int genes(int qQ)
{

    int i=1;
    int k=0;
    char ch;
    FILE *in;

  if((in=fopen("C:\\DNA_code2.ptt", "r"))==NULL) {
    printf("File can't be open.\n");
    exit(1);
  }
    while ((ch=getc(in))!='\n'){
    cout<<ch;}
    cout<<ch;
    while((ch=getc(in))!='\n'){
    if (isdigit(ch)!=0)
    qQ=qQ*10+(int)ch-(int)'0';
    }
    return qQ;
    fclose (in);
    }

void refer(int *ref)
{
    int q1=0;
    FILE *fp;
    char ch;

    if((fp=fopen("C:\\DNA_code2.fna", "r"))==NULL)
    {
        printf("File can't be open.\n");
        exit(1);
    }

    while((ch=getc(fp))!='\n');
    while((ch=getc(fp))!=EOF)
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
            q1++;
            //cout<<ref[q1-1]<<"\t"<<ch<<"\n";
        }
    }
    cout<<"in ref "<<q1<<"\n";
fclose(fp);
}

void mutation(int *mut_pos, int *mut_code,int *Q)
{   //cout<<"\n"<<*Q<<"\n";
    int k=0;
    int i=1;
    char ch;
    FILE *in;

  if((in=fopen("C:\\mutation.txt", "r"))==NULL)
  {
    printf("File can't be open.\n");
    exit(1);
  }

    while(i<=300000)
    {
        while ((ch=getc(in))!=' '){
            if (isdigit(ch)!=0) {
            mut_pos[i]=mut_pos[i]*10+(int)ch-(int)'0';
            }
        }

        while ((ch=getc(in))!='\n')
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
fclose(in);

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
           // cout<<mut_pos[i]<<"\n";
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
            if ((-nach[j]+mut_pos[i])%3==0)
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




}

 void compare (int coden,int codem, int pos )
{
    int codons[6][21]=      // A=1, T=2, G=3, C=4
    {
     {222,221,122,321,241,441,141,341,212,412,411,112,111,312,311,232,233,431,331,211,123},
     {224,223,121,322,242,442,142,342,214,414,413,114,113,314,313,234,  0,432,332,213,  0},
     {  0,421,124,323,243,443,143,343,  0,  0,  0,  0,  0,  0,  0,  0,  0,433,333,231,  0},
     {  0,422,  0,324,244,444,144,344,  0,  0,  0,  0,  0,  0,  0,  0,  0,434,334,  0,  0},
     {  0,423,  0,  0,132,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,131,  0,  0,  0},
     {  0,424,  0,  0,134,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,133,  0,  0,  0}
    };

    char  Aminok[21][4]=
    {"Phe", "Leu","Ile","Val","Ser","Pro", "Thr", "Ala", "Tyr", "His","Gin","Asn", "Lys", "Asp","Glu","Cys","Trp","Arg","Gly", "Beg", "End"};

    int j=0;
    int l=0;
    int i1=0;
    int k=0;
    while (j<=21)
    {
        while (i1<=6)
        {
            if (codons[i1][j]==coden)
            k=j;
            if (codons[i1][j]==codem)
            l=j;
            i1++;
         }
        i1=0;
        j++;
    }
   if (k!=l)
   cout << "In position " <<pos<< " no sinonimic  " << Aminok[k][0]<<Aminok[k][1]<<Aminok[k][2]<< "->" << Aminok[l][0]<<Aminok[l][1]<<Aminok[l][2]<<"\n";
   if (k==l)
   cout<<"In position "<<pos<< " sinonimic  " << Aminok[k][0]<<Aminok[k][1]<<Aminok[k][2]<<"\n";


}
int main()
{
std::ofstream of("annotation.txt");

int j=0, Q=0;
int pos=0;
int coden=0, codem=0;
int qQ=0;
    qQ=genes(qQ);
    Gran_genes(nach, endd,qQ);
    refer(ref);

    mutation(mut_pos, mut_nuk_code,&Q);
    /*for (int i=0;i<=Q;i++)
    {
        cout<<mut_pos[i]<<"\n";
    }*/

    //cout<<"\n"<<Q<<"\n";
    for(int i=0;i<=Q;i++)
    {   pos=mut_pos[i];
        //cout<<j<<"\n";
       // cout<<mut_pos[i]<<"\t"<<mut_nuk_code[i]<<"\t"<<i<<"\n";
        InCodench(nach, endd, mut_nuk_code, ref, mut_pos, i, &coden, &codem,qQ,&g, *of);

        if (g==2)
        compare ( coden, codem, pos);
        if (g==0)
        cout<<mut_pos[i]<<" not gene\n";
        //if (coden!=0)
        //cout<<"\t"<<coden<<"\t"<<codem<<"\t"<<mut_nuk_code[i]<<"\n";
        //getchar();
    }
    return 0;

    }
