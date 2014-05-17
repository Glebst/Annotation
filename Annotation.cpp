#include <iostream>

#include <fstream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

void Gran_genes (long nach[100000], long endd[100000])
  {
    long q1=0;
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
    q1=q1*10+(int)ch-(int)'0';
    cout<<ch;}
    cout<<ch;
    while((ch=getc(in))!='\n');
    cout<<ch;
    cout<<ch;

    while(i<=q1){
        cout<<ch;
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
        cout<<nach[i]<<"\t"<<endd[i]<<"\n";
        while((ch=getc(in))!='\n');
        i++;
    }

}

char *refer()
{
    char ref[1000000];
  int q1=0;
  FILE *fp;
  char ch;

  if((fp=fopen("C:\\DNA_code2.fna", "r"))==NULL) {
    printf("File can't be open.\n");
    exit(1);
  }
  while((ch=getc(fp))!='\n');
  while((ch=getc(fp))!=EOF) {
    if (ch!='\n'){
    ref[q1+1]=ch;

    q1++;
    }
  }
  fclose(fp);
return ref;
}


void mutation(int *mut_pos)
{

    int k=0;
    int i=1;
    char ch;
    int mut_nuk_code[100000];

    FILE *in;

  if((in=fopen("C:\\mutation.qu", "r"))==NULL) {
    printf("File can't be open.\n");
    exit(1);
  }


    while(i<=300000){

        while ((ch=getc(in))!=' '){
            if (isdigit(ch)!=0) {                        // This vetka, if search 2 point
            mut_pos[i]=mut_pos[i]*10+(int)ch-(int)'0';
            }
        }

        while ((ch=getc(in))!='\n'){
        if (isupper(ch)!=0){
            if (ch=='A')
            mut_nuk_code[i]=1;
            if (ch=='T')
            mut_nuk_code[i]=2;
            if (ch=='G')
            mut_nuk_code[i]=3;
            if (ch=='C')
            mut_nuk_code[i]=4;
            }

        i++;
        if (ch=='!')
        i=999999;}
    }


}

char *recode_mut(int mut_nuk_code [], char mut_nuk[])
{
    int i=0;

    while (isdigit(mut_nuk_code[i])!=0)
    {       if (mut_nuk_code[i]==1)
            mut_nuk[i]='A';
            if (mut_nuk_code[i]==2)
            mut_nuk[i]='T';
            if (mut_nuk_code[i]==3)
            mut_nuk[i]='G';
            if (mut_nuk_code[i]==4)
            mut_nuk[i]='C';
            i++;
    }
            return mut_nuk;
}


void InCodench(long nach [100000], long endd[100000], char mut_nuk[100000], char ref[3000000], int mut_pos[100000], int i)
{
    int k;
    string codens, codems;
    if(mut_pos[i]>=nach[i] && mut_pos[i]<=endd[i])
    k=1;                            //if k=1, then mutation is in gene
    else k=2;                       //if k=2, then mutation isn't in gene

    if (k==1)
    {
        if ((nach[i]-mut_pos[i])%3==0)
            {
            codens=ref[mut_pos[i]]+ref[mut_pos[i]+1]+ref[mut_pos[i]+2];
            codems=mut_nuk[i]+ref[mut_pos[i]+1]+ref[mut_pos[i]+2];
            }
        if ((nach[i]-mut_pos[i])%3==1)
            {
            codens=ref[mut_pos[i]-1]+ref[mut_pos[i]]+ref[mut_pos[i]+1];
            codems=ref[mut_pos[i]-1]+mut_nuk[i]+ref[mut_pos[i]+1];
            }
        if ((nach[i]-mut_pos[i])%3==2)
            {
            codens=ref[mut_pos[i]-2]+ref[mut_pos[i]-1]+ref[mut_pos[i]];
            codems=ref[mut_pos[i]-2]+ref[mut_pos[i]-1]+mut_nuk[i];
            }
    }


}

    void extraction(string codens, string codems,int coden, int codem )  //function for coding codons
    {
        char codenchs[3]={0};
        char codemchs[3]={0};



        codenchs[0]= codens[0];
        codenchs[1]= codens[1];
        codenchs[2]= codens[2];


        codemchs[0]= codems[0];
        codemchs[1]= codems[1];
        codemchs[2]= codems[2];

        for (int i1=0; i1<=2; i1++)
        {
            if (codenchs[i1]=='A')
            coden=coden*10+1;
            if (codenchs[i1]=='T')
            coden=coden*10+2;
            if (codenchs[i1]=='G')
            coden=coden*10+3;
            if (codenchs[i1]=='C')
            coden=coden*10+1;

            if (codemchs[i1]=='A')
            codem=codem*10+1;
            if (codemchs[i1]=='T')
            codem=codem*10+2;
            if (codemchs[i1]=='G')
            codem=codem*10+3;
            if (codemchs[i1]=='C')
            codem=codem*10+4;

        }

    }

 void compare (int coden,int codem, int pos, int codons[6][21], char Aminok[21][4]){
    int j=0;
    int l=0;
    int i1=0;
    int k=0;
    while (j<=21)
    {while (i1<=6)
        {if (codons[i1][j]==coden)
            k=j;
         if (codons[i1][j]==codem)
            l=j;
         i1++;
         }
    i1=0;
    j++;
    }
   if (k!=l)
   cout << "In position " <<pos<< " no sinonimic  " << Aminok[k] << "->" << Aminok[l];
   if (k==l)
   cout <<"In position "<<pos<< " sinonimic  " << Aminok[k];



}
main()
{   char ref[1000000]={0};    //to massiv 'referens'
    long nach[100000]={0};
    long endd[100000]={0};
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
    char mut_nuk[100000];
    int mut_pos[100000];
    int pos=0;
    string codens;
    string codems;
    int coden=0;
    int codem=0;
    Gran_genes (nach, endd);
    refer();
    mutation(mut_pos);
    for(int i=0;i<=100000;i++){
        pos=mut_pos[i];
        InCodench(nach, endd, mut_nuk, ref, mut_pos, i);
        extraction(codens, codems, coden,codem );
        compare ( coden, codem, mut_pos, codons, Aminok);
    }
}
