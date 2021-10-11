#include "mat.h"

int main()
{	
	/* declaration of mats */
	mat MAT_A={0};
	mat MAT_B={0};
	mat MAT_C={0};
	mat MAT_D={0};
	mat MAT_E={0};
	mat MAT_F={0};
	
	int loop=0; /* count how many commands */
	char c=',';
	char s[MAX_NUM], temp[MAX_NUM]; /* declaration of 2 strings */
	char *text; /* pointer to s */
	
	/* array of mats in string type */		
	char *str_mats[]={"MAT_A,","MAT_B,","MAT_C,","MAT_D,","MAT_E,","MAT_F,"};

	/* declaration of array of mats by pointer p */
	mat *p;
	
	p=&MAT_F;
	p--;
	p=&MAT_E;
	p--;
	p=&MAT_D;
	p--;
	p=&MAT_C;
	p--;
	p=&MAT_B;
	p--;
	p=&MAT_A;
	
	printf("Please enter your commands:\n");
	
	for(;;) /* infinite loop */
	{	
		/* declaration of loop variables:
		i - counter for loops
		ct1,ct2,ct3 - parameters for calculation in loops
		error - check if ther is an error in command
		count - counter for ',' 
		letter - counter for lettetrs */
			 
		int i=0, ct1=-1, ct2=-1, ct3=-1, error=1, count=0, letter=0;   
		
		/* declaring 3 strings that get the name of each mat */
		char x[LENGTH], y[LENGTH], z[LENGTH];
	
		fgets(s,MAX_NUM,stdin);/* get the input from user */
				
		strcpy(temp,s);
	
		for(i=0;i<strlen(temp);i++)
        {
        	if(c==temp[i])
        	count++;
        	
        	if(isalpha(temp[i])!=0)
        	letter++;
        }
	
		if(strcmp(s,"stop\n")==0) /* stop */
        stop();     
         
		text=strtok(s," ,");

		while(text != NULL) /* loop that checks if the string ended */
		{
			if(strcmp(text,"read_mat")==0) /* read_mat */
        	{
        		if(letter>11)/* if there is more than 11 letters there is an error*/
				break;
        	
        		text = strtok(NULL," ");/* text read the mat from command */        	
												
       		 	for(i=0;i<LENGTH+1;i++)
       		 	{
       		 		/* check which mat i should read into */
       		 		if(strcmp(text,str_mats[i])==0)
       				{
       					error=read_mat(*(p+i),count-1); /* calling to read_mat subroutine */
       		 			break;
       		 		}
       		 	}       		
        	}
        	
        	if(strcmp(text,"print_mat")==0) /* print_mat */
        	{ 	
        		if(count!=0)/* if there is more than 0 ',' there is an error*/
        		break;
        	
        		text = strtok(NULL," "); /* text read the mat from command */
        		
        		for(i=0;i<LENGTH+1;i++)
       		 	{
       		 		/* check which mat i should print */
       		 		if(strncmp(text,str_mats[i],LENGTH)==0)
       				{
       					print_mat(*(p+i)); /* calling to print_mat subroutine */
       					error=0;      					      		
       		 			break;
       		 		}
       		 	}
        	}
        	
        	if(strcmp(text,"add_mat")==0) /* add_mat */
        	{
        		if(count>2) /* if there is more than 2 ',' there is an error*/
        		break;     		        		        		
        		
        		text = strtok(NULL," ,");
        		strcpy(x,text);
       					
        		text = strtok(NULL," ,");
        		strcpy(y,text);
        		        		
        		text = strtok(NULL," ");
        		strcpy(z,text);       		          		        		   
       		     		       			
				for(i=0;i<LENGTH+1;i++)
				{
				/* check which mats i need in the command */
					if(strncmp(x,str_mats[i],LENGTH)==0)
					ct1=i;
			
					if(strncmp(y,str_mats[i],LENGTH)==0)
					ct2=i;
			
					if(strncmp(z,str_mats[i],LENGTH)==0)
					ct3=i;					
        		}
        		
        		if((ct1!=-1)&&(ct2!=-1)&&(ct3!=-1))	/* check if the name of mat is legal*/
        		{
        			add_mat(*(p+ct1),*(p+ct2),*(p+ct3)); /* calling to add_mat subroutine */
        			error=0;
        			break;
        		}
        	}
        	
        	if(strcmp(text,"sub_mat")==0) /* sub_mat */
        	{
        		if(count>2) /* if there is more than 2 ',' there is an error*/
        		break; 
        		
        		text = strtok(NULL," ,");
        		strcpy(x,text);
       					
        		text = strtok(NULL," ,");
        		strcpy(y,text);
        		        		
        		text = strtok(NULL," ");
        		strcpy(z,text);
			
				for(i=0;i<LENGTH+1;i++)
				{
					/* check which mats i need in the command */
					if(strncmp(x,str_mats[i],LENGTH)==0)
					ct1=i;
			
					if(strncmp(y,str_mats[i],LENGTH)==0)
					ct2=i;
			
					if(strncmp(z,str_mats[i],LENGTH)==0)
					ct3=i;					
        		}
        		
        		if((ct1!=-1)&&(ct2!=-1)&&(ct3!=-1))	/* check if the name of mat is legal*/
        		{
        			sub_mat(*(p+ct1),*(p+ct2),*(p+ct3)); /* calling to sub_mat subroutine */
        			error=0;
        			break;
        		}       		
        	}
        	
        	if(strcmp(text,"mul_mat")==0) /* mul_mat */
        	{
        		if(count>2) /* if there is more than 2 ',' there is an error*/
        		break; 
        		
        		text = strtok(NULL," ,");
        		strcpy(x,text);
       					
        		text = strtok(NULL," ,");
        		strcpy(y,text);
        		        		
        		text = strtok(NULL," ");
        		strcpy(z,text);
			
				for(i=0;i<LENGTH+1;i++)
				{
					/* check which mats i need in the command */
					if(strncmp(x,str_mats[i],LENGTH)==0)
					ct1=i;
			
					if(strncmp(y,str_mats[i],LENGTH)==0)
					ct2=i;
			
					if(strncmp(z,str_mats[i],LENGTH)==0)
					ct3=i;					
        		}
        		
        		if((ct1!=-1)&&(ct2!=-1)&&(ct3!=-1))	/* check if the name of mat is legal*/
        		{
        			mul_mat(*(p+ct1),*(p+ct2),*(p+ct3)); /* calling to mul_mat subroutine */
        			error=0;
        			break;
        		}
        	}
        	
        	if(strcmp(text,"mul_scalar")==0) /* mul_scalar */
        	{
        		float f; /* float number from command */
        		
        		/* if there is more than 2 ',' or there is more than 17 letters there is an error */
        		if((count>2)||(letter>17)) 
        		break; 
        		        		
        		text = strtok(NULL," ,");
        		strcpy(x,text);
        		
        		text = strtok(NULL," ,");
        		
        		/* check if the input number is legal */
        		if(atof(text)==0)
				if(strchr(text,'0')==NULL)
				break;
        		
        		f=atof(text);
   		
        		text = strtok(NULL," ");
        		strcpy(y,text);
			
				for(i=0;i<LENGTH+1;i++)
				{
					/* check which mats i need in the command */
					if(strncmp(x,str_mats[i],LENGTH)==0)
					ct1=i;
			
					if(strncmp(y,str_mats[i],LENGTH)==0)
					ct2=i;
        		}
        		
        		if((ct1!=-1)&&(ct2!=-1)) /* check if the name of mat is legal*/	
        		{
        			mul_scalar(*(p+ct1),f,*(p+ct2)); /* calling to mul_scalar subroutine */
        			error=0;
        			break;
        		}
        	}
        	
        	if(strcmp(text,"trans_mat")==0) /* trans_mat */
        	{
        		if(count>1) /* if there is more than 1 ',' there is an error*/
        		break;
        		
        		text = strtok(NULL," ,");
        		strcpy(x,text);
        		
        		text = strtok(NULL," ");
        		strcpy(y,text);
			
				for(i=0;i<LENGTH+1;i++)
				{
					/* check which mats i need in the command */
					if(strncmp(x,str_mats[i],LENGTH)==0)
					ct1=i;
			
					if(strncmp(y,str_mats[i],LENGTH)==0)
					ct2=i;
        		}
        		
        		if((ct1!=-1)&&(ct2!=-1)) /* check if the name of mat is legal*/	
        		{
					trans_mat(*(p+ct1),*(p+ct2)); /* calling to trans_mat subroutine */
        			error=0;
        			break;
        		}        	
        	}
        	  	
      		text = strtok(NULL," ,"); /* "cut" inputed string to finish command */
    	}
    	
    	loop++;
    	
    	if(loop==MAX_NUM) /* check end of commands from input file if user didn't enter stop */
    	break;
    	
    	if(strcmp(s,"\n")==0)/* if the user pressed enter instead of command nothing happens */
        error=0;
   
    	if(error==1)/* if there is an error somewhere in the code the user will be noticed */
        printf("\nTHERE IS AN ERROR IN THIS LINE!! :\n%s\n",temp);
    }
	/* if the user didn't enter stop command */
	printf("\nYOU SHOULD HAVE ENTER STOP COMMAND!!\n");
		
return 0;							
}
