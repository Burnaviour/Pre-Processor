
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// funtions prototypes//
char *get_macro_head(char *);
char *get_macro(char const*);
char *get_body_of_macro(char *);
char *get_line_with_macro(char *fname, char *str);	
void replace_Macro(char *string, const char *head, const char *body);
//global variables
int i=0;
char temp[200];
int main(int argc, char *argv[])
{
	
	//check for the input arguments
	if(argc != 2)
	{
	printf("Must have an input file name in the arguments\n");
	exit(0);
	}

	//this function should return the line carrying the MACRO “#define . . .”
	char *macroline = get_macro(argv[1]);
	
	fputs(macroline,stdout); //disply the line on console
	//head is an array that carries the head of MACRO
	char *head = get_macro_head(macroline);
	printf("Head: ");
	fputs(head,stdout);
	printf("\n");
	//get body of the MACRO
	char *body =get_body_of_macro(macroline);
	printf("\nBody: ");
	fputs(body,stdout);

	//get the line where head of MACRO is used in the main()
	char *line_with_head =get_line_with_macro(argv[1],head);
	printf("\nLine in main: ");
	
	fputs(line_with_head,stdout);
	printf("\n");
	
	// started replacing macro with its body 
    FILE * fPtr; 
    FILE * fTemp;
    char buffer_s[300];
	
    /*  Open all required files */
    fPtr  = fopen("out2.c","r");
    fTemp = fopen("out3.c", "w"); 

    /* if fopen() return NULL then exit */
    if (fPtr == NULL || fTemp == NULL)
    {
        /* Unable to open file*/
        printf("\niles not found make sure give the write file name \n");
        exit(1); //exit gracefully 
    }

    while ((fgets(buffer_s, 300, fPtr)) != NULL)
    {
       
        //if line starts with macro define it will ignore 
        if (buffer_s[0]=='#'&& buffer_s[1]=='d'){
			continue;
			}
		//replacing macro with body	
        replace_Macro(buffer_s, head, body);//funtion to replace macros with body 

        // After replacing macro write it to output file.
        fputs(buffer_s, fTemp);
    }


    /* Close all files*/
    fclose(fPtr);
    fclose(fTemp);




	
	
	return 0;//return gracefully
}

char * get_macro(char const* filename){
	
FILE *filePointer=fopen(filename,"r");
char ch;
char *string="macros not found";
char *buffer = malloc(sizeof(char) * 200);
//iterate file char by char 
while((ch=fgetc(filePointer))!=EOF) {
	int i=0;//index is 2 because 0 and 1 index are #d 
	char d;
	//found macro line 
	if (ch=='#'&& (d=fgetc(filePointer))=='d'){
		
		buffer[i]=ch;//store # in buffer
		i++;
		buffer[i]=d;//store #d in buffer
		i++;
		while((ch=fgetc(filePointer))!='\n'){
			
			buffer[i]=ch;//fill buffer with macro line
			i++;
			
			}
		buffer[i]='\n';
		buffer[i+1]='\0';//null character for terminating string 
		
		return buffer; //return buffer to main 
	
		
		}
		
	  
	  }
	if (buffer=NULL) return string;//return if buffer is empty
}




char *get_macro_head(char *stre){
	char *buffer1 = malloc(sizeof(char) * 100);
	
	int j=0;
	while(stre[i]!='\0')//iterate until it reach null char
	{
		
		if (stre[i]==32)//if space then after that macro head is started
		
		{	
			i++;//increment space character  
			
			while(stre[i]!=32) {//witerate till space found 
			
			buffer1[j]=stre[i];//copy string data into buffer 
			j++;
			i++;
			
		}
		
		buffer1[j]='\0';//null character for terminating string
		
		return buffer1;	
			
			}
		
	
	i++;
	
	}	
	
}	
	
char *get_body_of_macro(char *str)
{
	
char *buffer2 = malloc(sizeof(char) * 50);
	
	i=i+1;
	int j=0;
	while(str[i]!='\0')//iterate until it reach null char
	{
	if(str[i]=='\n'){//if \n found break loop 
		break;
		}
	buffer2[j]=str[i];

	i++;
	j++;
	
	}	
	
	buffer2[j]='\0';//null character for terminating string
	return buffer2;
	
}	

char *get_line_with_macro(char *fname, char *str) {
	/*  Open  required files */
	FILE *fp=fopen(fname,"r");
	
	int line_count = 0;//line count if 0 then not found macro line 
	

	while(fgets(temp, 100, fp) != NULL) {
		//compare head in a temp buffer so we can return that line 
		if((strstr(temp, str)) != NULL) {

			if (temp[0]!='#'){
				line_count++;
				return temp;//return temp buffer 
				
				}
			
		}
		
	}
	//line = 0 not found macro 
	if(line_count == 0) {
		printf("\nMATCH NOT FOUND .\n");
	}
	
	
	fclose(fp);
	
   	
}

void replace_Macro(char *string, const char *head, const char *body){
	
	char *temp=malloc(sizeof(char) * 300);//temp char pointer array 
    int index = 0;//index to calculate 
	char *pos_of_head;//position of head in the macro line 
    int len_of_org = strlen(head);//length of head 
	//if head and body are same then return 
    if (strcmp(head,body)==0) {
        return;
    }
    //read till macro found
    while ((pos_of_head = strstr(string, head)) != NULL)
    {	//store line which has macro in a temp buffer as a backup
        strcpy(temp, string);
        
        // index where the macro head stated in that line 
        index = pos_of_head - string;
		
        // null character added where macro head starting found 
        string[index] = '\0';
        // Concatenate string with body 
        strcat(string, body);
      
        // Concatenate string with remaining words after the macro  
        strcat(string, temp + index + len_of_org);
    }
	free(temp);//free the temporary memory 
	
	
}





