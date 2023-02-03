
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char *h1="<stdio.h>";
	char *h2="<stdlib.h>";
	char *h3="<string.h>";
	FILE *ptr1= fopen(argv[1],"r");//input file in read mode
	FILE *ptr2= fopen("out4.c","w");//output file write mode
	char buffer[500];//buffer for input file
	char buffer1[500];//buffer for library files 

	FILE *ptr3= fopen("pa1_stdio","r");//stdio header file open in read mode
	FILE *ptr4= fopen("pa1_stdlib","r");//stdlib header file open in read mode
	FILE *ptr5= fopen("pa1_string","r");//string header file open in read mode
	while ((fgets(buffer,500, ptr1)) != NULL)//iterate file untile file pointer is null 
    {
	if (buffer[0]=='#'&& buffer[1]=='i' ){//if line is stating with # 
		
			if((strstr(buffer, h1)) != NULL) {//if line is importing stdio header  file 
				
			
			
			while ((fgets(buffer1, 500, ptr3)) != NULL){
				fputs(buffer1,ptr2);//copy all content of file into out4.c file  
				
				}
				
			
			 
				
				}
				//if line is importing stdlib header file 
			else if((strstr(buffer,h2)) != NULL) {
			
			
			while ((fgets(buffer1, 500, ptr4)) != NULL){
				
				fputs(buffer1,ptr2);//copy all content of file into out4.c file 
				
				}
				
		
				}
				
				//if line is importing string header  file 
			else if((strstr(buffer,h3)) != NULL) {
			
			while ((fgets(buffer1, 500, ptr5)) != NULL){
				fputs(buffer1,ptr2);//copy all content of file into out4.c file 
				
				}
			
			
			 
				
				}
	
			
		}
		//if its not header line copy content in out4.c file
		else fputs(buffer,ptr2);
		
	}
	
	
	
	
return 0;	//return gracefully
}




