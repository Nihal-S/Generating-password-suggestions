#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void insert_substring(char *a, char b, int position);

char *substring(char *string, int position, int length)
{
   char *pointer;
   pointer=(char*)malloc(sizeof(char)*length+1);
   int c;
    

 
   for( c = 0 ; c < length ; c++ )
      *(pointer+c) = *((string)+c);      
       
   *(pointer+c) = '\0';
 
   return pointer;
}

char* add_more_char(char* str, int need) 
{ 
    int pos = 0; 
    char c[1];

    char low_case[] = "abcdefghijklmnopqrstuvwxyz"; 
  
    for (int i = 0; i < need; i++) { 
        pos = (rand() % strlen(str)); 
        c[0] = low_case[rand() % 26];
        insert_substring( str, c[0], pos);
    } 
    return str; 
} 


void insert_substring(char *a, char c, int position)
{

   if(position==0) position++;
   if(position==strlen(a)) position--;
   char b[2];
   b[0]=c;
   b[1]='\0';
   char *f, *e;
   int length;
   
   length = strlen(a);
   
   f = substring(a, 1, position - 1 );   
   e = substring(a+position-1, 1, length-position+1);
    
   strcpy(a, "");
   strcat(a, f);
   free(f);
   strcat(a, b);
   strcat(a, e);
   free(e);
}

char* suggester(int l,int u,int d,int s,char* str1){
    char num[] = "0123456789"; 
    char low_case[] = "abcdefghijklmnopqrstuvwxyz"; 
    char up_case[] = "ABCDEFGHIJKLMNOPQRSTUVXYZW"; 
    char spl_char[] = "@#$_()!";
    int n = strlen(str1);
    char *str;
    str=(char*)malloc(sizeof(char)*n);
    strcpy(str,str1);

    int pos =0;
    char c[1];

    if (l == 0) { 
        pos = (rand() % strlen(str));
        c[0] = low_case[rand() % 26];
        insert_substring( str, c[0], pos);
    } 
  
    if (u == 0) { 
        pos = (rand() % strlen(str));
        c[0] = up_case[rand() % 26];
        insert_substring( str, c[0], pos);
    } 

    if (d == 0) { 
        pos = (rand() % strlen(str));
        c[0] = num[rand() % 10];
        insert_substring( str, c[0], pos);
    } 

    if (s == 0) { 
        pos = (rand() % strlen(str));
        c[0] = spl_char[rand() % 7];
        insert_substring( str, c[0], pos);
    } 
  
    return str; 
    
}


void generate_password(char * pass){
    int l=0;
    int u=0;
    int d=0;
    int s=0;
    int need=0; 
    int n = strlen(pass);
    char *original;
    original=(char*)malloc(sizeof(char)*n);
    strcpy(original,pass);

    char suggest[200];
    for(int i = 0; i < n; i++)
    {
        if (pass[i]>=97 && pass[i]<=122) {
            l=1;
        }
        else if (pass[i]>=65 && pass[i]<=90){   
            u=1;
        }
        else if (pass[i]>=48 && pass[i]<=57){   
            d=1;
        }
        else
        {
            s=1;
        }
  
    }
    if ((l + u + d + s) == 4 && n>=8) { 
       printf ("Your Password is Strong\n"); 
        return; 
    }
     else
     {
        printf ("Suggested passowrds \n"); 
     
     for(int i = 0; i < 10; i++)
     {
         strcpy(suggest,suggester(l,u,d,s,original));
         need = 8 - strlen(suggest);
         if (need >0)
         {
             strcpy(suggest, add_more_char(suggest,need));
         }
        printf("\nPassword %d:%s\n",i+1,suggest);
     }
     }
}


int main()
{
    char *pass;
    pass=(char*)malloc(sizeof(char)*200);
    printf("Enter the password for which you need suggestions\n");
    scanf ("%s",pass);
    generate_password(pass);
    return 0;
}
