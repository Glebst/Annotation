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

  if((in=fopen("C:\\DNA_genes.ptt", "r"))==NULL) {
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
