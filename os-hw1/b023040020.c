#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#define STD_INPUT 0
#define STD_OUTPUT 1
#define SIZE 50
#define TRUE 1

int main()
{	
	char *get_loc;//get the last &
	int file_input,file_out;
	int whether_back=0;
	int j=0,k=0;
	int choice=0;
	int fd[2],_fd;
	pid_t children_parent1,children_children,proc;
	char *argv_1[50]={0},*argv_2[50]={0};
	char input[100]={0};
	char *temp,*temp2,*test1,*test2;
	char test[100];
	char *how_to_sep="|",*how_to_sep_part1=" ",*how_to=">",*how_to2="<";
	char ch;//garbage;
	while(1)
	{	
		whether_back=0;
		printf("b023040020 my first hw shell %d\n",k);
		int i;
		fgets(input, (int)sizeof(input), stdin);
		if(input[strlen(input)-1]=='\n')//make sure its in the right lengh
		{ 
	   		 input[strlen(input)-1]='\0';
		}
		pipe(&fd[0]);
		if(strchr(input, '&')!=NULL)//make in background
		{ 	
			for(i=0;i<=99;i++)
			{
				if(input[i]=='&')
					get_loc=&input[i];
			}
			
            input[(int)(get_loc-input)]='\0';
           	whether_back=1;
        }
		if((proc=fork())!=0)
		{	
			if(whether_back==1)
				continue;//direct end the loop in parent;

			close(fd[1]);
			close(fd[0]);
			waitpid(proc, NULL, 0); //wait his children
		}
		else
		{
			if(strchr(input, '|')!=NULL)//pipe
			{
					temp=strtok(input,how_to_sep);
					temp2=strtok (NULL, how_to_sep);
					test1=strtok(temp,how_to_sep_part1);
					argv_1[0]=test1;
					int j=1;
					while (test1!= NULL)
					{	
						test1= strtok (NULL,how_to_sep_part1);
						argv_1[j]=test1;
						j++;
					}  
					j=1;
					test2=strtok(temp2,how_to_sep_part1);
					argv_2[0]=test2;
					while (test2 != NULL)
					{
						test2 = strtok (NULL,how_to_sep_part1);
						argv_2[j]=test2;
						j++;
					}  
					if((children_parent1=fork())==0)//children_parent(actually is children)
					{	
						//printf("this is parent\n");
						close(fd[0]);
						close(STD_OUTPUT);
		
						dup(fd[1]);
					
						close(fd[1]);
						
						execvp(argv_1[0], argv_1);
						
						exit(0);
					}
					if((children_children=fork())==0)//children
					{	
						//printf("this is children\n");
						close(fd[1]); 

						close(STD_INPUT); 

						dup(fd[0]); 

						close(fd[0]); 

						execvp(argv_2[0], argv_2);
						
						exit(0);
					}
					close(fd[0]); 
					close(fd[1]); 
					waitpid(children_children, NULL, 0);
			}
			else if(strchr(input, '<')!=NULL)//input
			{
				temp=strtok(input,how_to2);
				temp2=strtok (NULL, how_to2);
				test1=strtok(temp,how_to_sep_part1);
				argv_1[0]=test1;
				int j=1;
				while (test1!= NULL)
				{	
					test1= strtok (NULL,how_to_sep_part1);
					argv_1[j]=test1;
					j++;
				}  
				j=1;
				test2=strtok(temp2,how_to_sep_part1);
				argv_2[0]=test2;
				while (test2 != NULL)
				{
					test2 = strtok (NULL,how_to_sep_part1);
					argv_2[j]=test2;
					j++;
				}  
				file_input=open(argv_2[0], O_RDONLY); 
				close(STD_INPUT);
				dup2(file_input, STD_INPUT); 
				close(file_input);
				execvp(argv_1[0], argv_1);
			}
			else if(strchr(input, '>')!=NULL)//output
			{	
				//printf(">>\n");
				temp=strtok(input,how_to);
				temp2=strtok (NULL, how_to);
				test1=strtok(temp,how_to_sep_part1);
				argv_1[0]=test1;
				int j=1;
				while (test1!= NULL)
				{	
					test1= strtok (NULL,how_to_sep_part1);
					argv_1[j]=test1;
					j++;
				}  
				j=1;
				test2=strtok(temp2,how_to_sep_part1);
				argv_2[0]=test2;
				while (test2 != NULL)
				{
					test2 = strtok (NULL,how_to_sep_part1);
					argv_2[j]=test2;
					j++;
				}  
				file_out=open(argv_2[0], O_WRONLY | O_CREAT,10750 | O_TRUNC, 0644);
				close(STD_OUTPUT);
				dup2(file_out, STD_OUTPUT); 
				close(file_out);
				execvp(argv_1[0], argv_1);
			}
			else//single one
			{
				temp=strtok(input,how_to_sep_part1);
				argv_1[0]=temp;
				int j=1;
				while (temp != NULL)
				{
					temp = strtok (NULL,how_to_sep_part1);
					argv_1[j]=temp;
					j++;
				}  
				if(fork()!=0)
				{
					wait(0);
				}
				else
				{
					execvp(argv_1[0], argv_1);
				}
			}
		}
		k++;
	}
	return 0;
}
