#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
main(int argc,char*argv[]){FILE*f;char m[30000];int p=0,l=0,fp=0;for(int i=0;i<30000;i++)m[i]=0;f=fopen(argv[1],"r");if(f==NULL)return;while(!feof(f)){char x=fgetc(f);fp++;if(x=='>')p++;if(x=='<')p--;if(x=='+')m[p]++;if(x=='-')m[p]--;if(x=='.')printf("%c",m[p]);if(x==',')m[p]=getch();if(x=='['&&m[p]==0){l=fp;while(x!=']'){fp++;fseek(f,fp,SEEK_SET);x=fgetc(f);if(feof(f))return;};};if(x==']'&&m[p]!=0){fseek(f,l,SEEK_SET);fp-=l;};};fclose(f);}