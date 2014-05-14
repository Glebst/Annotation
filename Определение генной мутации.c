#include <iostream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>

void (long nach [100000], long endd[100000], ifstream in("Mutation"), ifstream inn("Referens_strukt"))
{ int q1=0;
  int i=0;
  int k=0;
  long pos=0;
  char ch;
  in>>ch;
  while (ch!=EOF){
      in>>pos;
      for (i=0;i<=100000;i++){
          if(pos>=nach[i])&&(pos<=end[i])
            k=1;                            //if k=1, then mutation is in gene
            else k=2;                       //if k=2, then mutation isn't in gene
      }
      if (k==1)

