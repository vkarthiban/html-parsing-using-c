#include<stdio.h>
int main()
{
     char ch,readn[70],writen[70],cont[1000];
     int count=0;
     FILE *fptr,*fp;
     printf("\nenter your read file name\n");
     scanf("%s",&readn);
     fptr=fopen(readn,"r");
     if(fptr==NULL)
     {

         printf("\nfile can't be open\n");

          exit(0);
     }
     else
     {
          printf("\nfile open sucessfully\n");


      printf("\nenter your write file name\n");
      scanf("%s",&writen);
      fp=fopen(writen,"w");
      if(fp==NULL)
       {

         printf("file dost not created");
         exit(0);
       }
     else
     {
         printf("file has been created");

            fputs("<pre>",fp);

     while((ch=fgetc(fptr))!=EOF)
     {

         if(ch=='<')
           {    int x=0;
                     fputs("<em style='color:red';>",fp);
                    fputs("&lt",fp);

               while((ch=fgetc(fptr))!='>')
              {
                   cont[x]=ch;
                   x++;
              }

                fputs(cont,fp);
               fputs("&gt",fp);
               fputs("</em>",fp);
               memset(cont,0,1000);

           }

        else
         {  int x=0;
            fputs("<em style='color:green';>",fp);
            cont[x]=ch;
                  x++;

         }
           fputs(cont,fp);
            fputs("</em>",fp);
            memset(cont,0,1000);


        if(ch==' '||ch=='\n')
          {
              count++;
          }
       }

      }

        fputs("</pre>",fp);
     }
     fclose(fp);
     printf("\n the number of words present in the file:%d",count);
     fclose(fptr);
     return 0;

}
