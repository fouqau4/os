#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include "mm.h"

int main(void)
{	
    srand (time(NULL));
    int *testa=NULL,i=0;
    int choosewhichone, number,number2;
    int what_to_want;//decide the user want to control it by himself or auto
    printf("this is B023040020-os4  \n ");
    printf("PLEASE ENTER 1 OR 2 OR 3 \n1 for control by yourself 2 for auto 3 for leave:  ");
    //1 is for uses 2 is easy to know what does it use for
    scanf("%d",&what_to_want);
    while(1)
    {	
	if(what_to_want==1)//to users can control what they want
	{	
		while(1)
		{
			printf("1.mymalloc\n""2.mycalloc\n""3.myrealloc\n""4.exit\n: ");
		    	scanf("%d", &choosewhichone);
			if(choosewhichone==4)
			{
				break;
			}
			else if(choosewhichone==1)
			{	
				printf("thie size of array:\n ");
				scanf("%d", &number);
				testa=(int*)mymalloc(sizeof(int)*number);
				int decide;
				printf("do you want to give the array value(1.yes 2.no): ");
				scanf("%d", &decide);
				if(decide==1)
				{
				    for(i=0; i<number; i++)
				    {
				        *(testa+i)=i;
				    }
				}
				printf("thie address of array: %p\n", testa);//show the position
				printf("thie value of array: \n");
				for(i=0; i<number; i++)
				{
				    printf("%d ", testa[i]);
				}
				printf("\n");
			}	
			else if(choosewhichone==2)
			{	
				//printf("jjasd\n");
				printf("array_size: ");
				scanf("%d", &number);
				testa=(int*)mycalloc(sizeof(int), number);
				printf("thie address of array: %p\n", testa);//show the position
				printf("thie value of array: ");
				for(i=0; i<number; i++)
				{
				    printf("%d ", testa[i]);
				}
			}
			else if(choosewhichone==3)
			{
				if(testa==NULL)
				{
				    printf("testa do not exist please malloc first\n");
			 
				}
				else
				{
					printf("thie size of array: ");
					scanf("%d", &number);
					int *testb=myrealloc(testa, sizeof(int)*number);
					printf("thie address of array: %p\n", testb);//show the position
					printf("thie value of array: ");
					for(i=0; i<number; i++)
					{
					  printf("%d ", testb[i]);
					}
				}
				testa=NULL;
			}               
			/*printf("\n\n1.malloc\n\n"
			       "2.calloc\n"
			       "3.realloc\n"
			       "4.exit\n: ");
			scanf("%d", &choosewhichone);*/
		}
			
	}
	else if(what_to_want==2)//just let it run
	{	
		int tem;
		printf("step 1 malloc\nrandom product a number \n");
		number=rand()%15+1;
		printf("number is %d\n",number);
		testa=(int*)mymalloc(sizeof(int)*number);
		for(i=0; i<number; i++)
		{
		       *(testa+i)=i;
	        }
		printf("thie address of array: %p\n", testa);//show the position
	        printf("thie value of array: \n");
	        for(i=0; i<number; i++)
		{
		        printf("%d ", testa[i]);
		}
		printf("\ndo u want to continue enter 1 or 2\n1for yes 2 for no :");//keep going or not
		scanf("%d",&tem);
		if(tem==1)
		{
			printf("step 2 calloc\nrandom product a number \n");
			number=rand()%15+1;
			printf("number is %d\n",number);
		        testa=(int*)mycalloc(sizeof(int), number);
			printf("thie address of array: %p\n", testa);//show the position
			printf("thie value of array: \n");
			for(i=0; i<number; i++)
			{
				printf("%d ", testa[i]);
			}
			printf("\ndo u want to continue enter 1 or 2\n1for yes 2 for no :");
			scanf("%d",&tem);//keep going or not
			if(tem==1)
			{
					printf("step 2 realloc\nrandom product a number \n");
					if(testa==NULL)
					{
					    printf("testa do not exist please malloc first\n");
				 
					}
					else
					{	
						number=rand()%20+1;
						printf("number is %d\n",number);		
						printf("thie size of array: ");
						int *testb=myrealloc(testa, sizeof(int)*number);
						printf("thie address of array: %p\n", testb);//show the position
						printf("thie value of array: \n");
						for(i=0; i<number; i++)
						{
						  printf("%d ", testb[i]);
						}
					}
					printf("\n");
					testa=NULL;
			}
		}	
	}
	else
	{
		break;
	}
	printf("PLEASE ENTER 1 OR 2 OR 3\n1 for control by yourself 2 for auto 3 for leave:   ");
        scanf("%d",&what_to_want);	
    }

    return 0;
}
