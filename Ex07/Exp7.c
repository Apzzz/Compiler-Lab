#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
    char code[10][30], str[20], opr[10];
    int i = 0,k=0;
    FILE *fp1,*fp2;
    fp1=fopen("quad.txt","r");
    fp2=fopen("output.txt","w");
    
    char op,op1[10],op2[10],res[10];
    while(!feof(fp1))
    {
    	fscanf(fp1,"%c%s%s%s\n",&op,op1,op2,res);
    	printf("%c %s %s %s\n",op,op1,op2,res);
    
    	switch (op)
    	{
			case '+':
					strcpy(opr, "ADD ");
					i=0;
					break;
			case '-':
					strcpy(opr, "SUB ");
					i=0;
					break;
			case '*':
					strcpy(opr, "MUL ");
					i=1;
					break;
			case '/':
					strcpy(opr, "DIV ");
					i=1;
					break;
	    }
	    
	    if(strlen(op1)==2)
	    {	
	    	if (op1[1]=='1')
	    		fprintf(fp2,"MOV AX,DL\n");
	    	else if (op1[1]=='2')
	    		fprintf(fp2,"MOV BX,DH\n");
	    	else if (op1[1]=='3')
	    		fprintf(fp2,"MOV CX,CL\n");
	    	else if (op1[1]=='4')
	    		fprintf(fp2,"MOV DX,CH\n");
	    }
	    else
	    	fprintf(fp2,"MOV AX,[%s]\n", op1);
	    
	    if(strlen(op2)==2)
	    {	
	    	if (op2[1]=='1')
	    		fprintf(fp2,"MOV BX,DL\n");
	    	else if (op2[1]=='2')
	    		fprintf(fp2,"MOV BX,DH\n");
	    	else if (op2[1]=='3')
	    		fprintf(fp2,"MOV BX,CL\n");
	    	else if (op2[1]=='4')
	    		fprintf(fp2,"MOV BX,CH\n");
	    }
	    else
	    	fprintf(fp2,"MOV BX,[%s]\n",op2);
	    	
    	if (i==0)
	    	fprintf(fp2,"%sAX,BX\n", opr);
	    else
	    	fprintf(fp2,"%sBX\n", opr);
	    	
	    if(strlen(res)==2)
	    {	
	    	if (res[1]=='1')
	    		fprintf(fp2,"MOV DL,AX\n");
	    	else if (res[1]=='2')
	    		fprintf(fp2,"MOV DH,AX\n");
	    	else if (res[1]=='3')
	    		fprintf(fp2,"MOV CL,AX\n");
	    	else if (res[1]=='4')
	    		fprintf(fp2,"MOV CH,AX\n");
	    }	    
	    k++;    
    }
}
