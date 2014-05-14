#include <iostream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>

void InCodench(long nach [100000], long endd[100000], ifstream in("Mutation"), char ref)
{ /*int q1=0;
  int i=0;
  int Sinonim=0;        //Flag of sinonimic
  long pos=0;
  char ch;*/            //This do function
  in>>ch;
 
      in>>pos;
      q1++;
      for (i=0;i<=100000;i++){
          if(pos>=nach[i])&&(pos<=end[i])
            Sinonim=1;                            //if k=1, then mutation is in gene
            else Sinonim=2;                       //if k=2, then mutation isn't in gene
      }
      if (Sinonim==1)
        in>>ch;
        if ((nach[i]-pos)%3==0)
            codench={ref[pos],ref[pos+1],ref[pos+2]};
        if ((nach[i]-pos)%3==1)
            codench={ref[pos-1],ref[pos],ref[pos+1]};
        if ((nach[i]-pos)%3==2)
            codench={ref[pos-2],ref[pos-1],ref[pos]};
  return (codench,Sinonim);
}

