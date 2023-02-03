
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void strip_off_slash_star_comments(FILE *ptr1);
void strip_off_double_slash_comments(FILE *ptr);
int main(int argc, char *argv[])
{
	
char const* const fileName = argv[1];	
FILE *ptr=fopen(fileName,"r");
if(ptr == NULL)//if pointer are null exit the program with  message
   {
      printf("Files not found !\n");   
      exit(1);             
   }	
//check for the input arguments
if(argc != 2)
{
printf("Must have an input file name in the arguments\n");
exit(0);
}

strip_off_double_slash_comments(ptr);
FILE *ptr1= fopen("out1.c", "r");
strip_off_slash_star_comments(ptr1);
return 0;
}
void strip_off_slash_star_comments(FILE *ptr1)

{	
FILE *fptr;
char ch;
char ch1;
fptr = fopen("out2.c", "w");
while ((ch = fgetc(ptr1)) != EOF)//iterate till end of file 
	{		
		
		
		if(ch=='/'){
		
		int check=0;
			
		if((ch = fgetc(ptr1))=='*'){//if character is /
			check=1;
	 
			while ((ch = fgetc(ptr1))!= EOF){
				 if(ch=='*'&& (ch1=fgetc(ptr1))=='/') // if the comment 'seems' like ending
				{
				  
				break;  
                
                
				}
				
				};  
		}
		if (check==0){
			fputc('/',fptr);//if check 0 paste / in the file 
			}	
			
		}
	
		else fputc(ch,fptr);//print  characters in the file other than comments 
	}
	fseek(ptr1,0,SEEK_SET);//move the file pointer index to 0 so we can read file again or iterate it     


}

void strip_off_double_slash_comments(FILE *ptr)
{	
char ch;
FILE *fptr;
fptr = fopen("out1.c", "w");

while ((ch = fgetc(ptr)) != EOF)//iterate till end of file 
	{		
		//if / found 	
		if(ch=='/'){
		int check=0;//check for '/' if the check is 0 it means its a single / if it is 1 then its double slash 
			
		if((ch = fgetc(ptr))=='/'){//if character is /
			check=1;
		//iterate till the end of line beacuse comment is found and we dont want to add this text next to comment so file pointer will jump to next line  
			while ((ch = fgetc(ptr))!= '\n');  
		}
		if (check==0){
			fputc('/',fptr);//if check 0 paste / in the file 
			}	
			
		}
	
	fputc(ch,fptr);//print  characters in the file other than comments 
	}
	fseek(ptr,0,SEEK_SET);//move the file pointer index to 0 so we can read file again or iterate it     

	fseek(fptr,0,SEEK_SET);

	}

