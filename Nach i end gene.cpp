#include <iostream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>

int main(int argc, char *argv[])
{ long nach[100000]={0};
  long endd[100000]={0};
  int q1=0;
  int i=0;
  int k=0;
  char ch;

  std::ifstream in("DNA_code2.ptt");
    in>>ch;
    while (ch!='/n')
    in>>ch;
    while(ch!='/n')
    in>>ch;
    while(ch!=EOF){
    in>>ch;

    if (k==2){                                  // k- kol-vo naydenyh tochek podryad
    if (isdigit(ch)!=0)                         // This vetka, if search 2 point
    endd[i]=endd[i]*10+atol(ch);
    else {
    k=0;
    i=i+1;}
    }

    if (k!=2)
    {
    if (isdigit(ch)!=0)
    nach[i]=nach[i]*10+atol(ch);

    if (k==1){
    if (ispunct(ch)!=0) &&(ch=='.')
    k=2;
    else {
    k=0;
    nach[i]=0;}
    }

    if (ispunct(ch)!=0) &&(ch=='.')
    k=1;
    }

  }
  in.close();
  return (nach, endd);
}

