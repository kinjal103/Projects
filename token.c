#include<stdio.h>
#include<string.h>

int main (int argc,char *argv[])
{
  int fd,size,i,c,new;
  char str[500],buffer,buffer1[12];
  char * pch;
  
  if(argc!=2)
    printf("Invalid number of arguments");
  fd=open(argv[1],0666);
  size=lseek(fd,0,2);
  lseek(fd,0,0);
  //printf("size=%d",size);
  if(fd!=-1)
    {
    c=read(fd,str,size);
    }
  else
    printf("error");
  printf("\nstring=%s",str);
  //char str[] ="- This, a sample string.";
  printf ("Splitting string \"%s\" into tokens:\n",str);
  pch = strtok (str," ,.-!#$^{(})1234567890");
  
  new=creat("tokens.txt",0666);
  if(fd!=-1)
    {
    printf("\nFile opened");
    }
  
  while (pch != NULL)
  {
    strcpy(buffer1,pch);
    write(new,buffer1,strlen(buffer1));
    write(new," ",1);
    //printf ("%s\n",pch);
    pch = strtok (NULL, " ,.-!#$^{(})1234567890");
  }
  close(new);
  new=open("tokens.txt",0666);
  
  c=read(new,str,size);
  for(i=0;i<size;i++)
    {
    if(str[i]>='A' && str[i]<='Z')
      str[i]=str[i]+32;
    }
  new=creat("case.txt",0666);
  if(fd!=-1)
    {
    printf("\nFile opened");
    }
  write(new,str,strlen(str));
   
  return 0;
}
