#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<windows.h>
#include<malloc.h>
struct record
{
	char data[30];
	bool prstatus;
	int amount;
	struct record *next;
};
typedef struct record srecord;
srecord *head,*current,*last;
int i,j;
int main_exit;
add()//FUNCTION FOR ADDING RECORDS
{
	char v;
    printf("\n\nFor creating a record, enter the name of the account holder and the amount you wish to deposit(minimum 5000)\n");
    current = (srecord *)malloc(sizeof(srecord));
    if(current==NULL)
    {
    	printf("\nMemory not allocated");
    	return 0;
	}
	scanf("%s",current->data);
	re_try:
	scanf("%d",&current->amount);
	if(current->amount<5000)
	{
		printf("\nThe amount must be minimum Rs 5000 for creation of account\n");
		printf("\nPlease re-enter the amount to be deposited\n");
		goto re_try;
	}
	current->next=NULL;
	printf("\nDo you wish for a net banking?(y for yes and n for no)\n");
	scanf("%s",&v);
	if(v=='y')
		   current->prstatus=1;
		else
		   current->prstatus=0;
	if(head==NULL&&head==last)
	{
		head=current;
		last=current;
	}
	else
	{
		last->next=current;
		last=current;
	}
}
remover()//FUNCTION FOR REMOVING RECORDS
{
	srecord *temp,*r,*prev;
	char n[30];
	//int flag=0;
	printf("\nEnter the name of the person whose record you wish to delete : ");
	scanf("%s",n);
	temp=head;
	if(strcmp(temp->data,n)==0)
    {
    	if(temp->next==NULL)
    	{
    		free(temp);
    		//flag=1;
		}
		else
		{
			head=head->next;
			free(temp);
    		//flag=1;
		}
    }
	while(temp!=NULL)
	{
    if(strcmp(temp->next->data,n)==0)
    {
    	r=temp->next;
    	if(r->next==NULL)
    	{
    		temp->next=NULL;
    		free(r);
		    flag=1;
		}
		else
		{
    	    temp->next=r->next;
    	    free(r);
		    //flag=1;
		}
	}
	else
        temp=temp->next;
    }
	//if(flag==0)
	    //printf("\nName does not exist\n");
}
deposit()//FUNCTION FOR RECORDING THE DEPOSIT AMOUNT IN CUSTUMER'S ACCOUNT
{
	srecord *temp;
	char n[30];
	int a,flag=0;
	printf("\nEnter the name of the customwer in whose bank account you wish to deposit in the amount into : \n");
	scanf("%s",n);
	temp=head;
	while(temp!=NULL)
	{
		if(strcmp(temp->data,n)==0)
		    {
		    	printf("\nEnter the amount to be withdrawen : \n");
	            scanf("%d",&a);
	            temp->amount = temp->amount - a;
	            flag=1;
			} 
		temp=temp->next;
    }
	if(flag==0)	
		printf("\nName does not exist\n");
}
withdraw()//FUNCTION FOR RECORDING THE AMOUNT WITHDRWAN IN CUSTUMER'S ACCOUNT
{
	srecord *temp;
	char n[30];
	int a,flag=0;
	printf("\nEnter the name of the customwer in whose bank account you wish to withdraw in the amount into : \n");
	scanf("%s",n);
	temp=head;
	while(temp!=NULL)
	{
		if(strcmp(temp->data,n)==0)
		    {
		    	printf("\nEnter the amount to be withdrawen : \n");
		    	re_amt:
	            scanf("%d",&a);
	            if((temp->amount)-a<5000)
	            {
	            	printf("\nOne cannot have an amount in an account less than 5000\n");
	            	printf("\nPlease re-enter the amount to be withdrawn\n");
	            	goto re_amt;
				}
	            else
	                temp->amount = temp->amount - a;
	            flag=1;
			}
		temp=temp->next;
	}
	if(flag==0)	
		printf("\nName does not exist\n");
}
update()//FUNCTION FOR UPDATING ACCOUNT
{
	srecord *temp;
	int flag=0;
	char p,q,n[30],name[30];
	printf("\nDo you wish to change your name?(y for yes or n for no)\n");
	scanf("%s",&p);
	if(p=='y')
	{
		printf("\nEnter your old name : \n");
		scanf("%s",n);
		temp=head;
		while(temp!=NULL)
	    {
		    if(strcmp(temp->data,n)==0)
		    {
		    	printf("\nEnter your new name : \n");
		    	scanf("%s",temp->data);
		    	flag=1;
			}
			temp=temp->next;
	    }
		if(flag==0)	
		   printf("\nName does not exist\n");	
	}
	p='x';
	printf("\nDo you wish to change your net banking status?(y for yes or n for no)\n");
	scanf("%s",&p);
	if(p=='y')
	{
		printf("\nEnter your name : \n");
		scanf("%s",n);
		re_again:
		printf("\nEnter whether you to allow netbanking or not(y for yes or n for no) : \n");
		scanf("%s",&q);
		flag=0;
		temp=head;
		while(temp!=NULL)
	    {
		    if(strcmp(temp->data,n)==0)
		    {
		    	if(q=='y')
		    	   temp->prstatus=1;
		    	else if(q=='n')
		    	   temp->prstatus=0;
		    	else
		    	{
		    		printf("\nYou can only enter y or n(y for net banking and n for no net banking)\n");
		    		goto re_again;
				}	
				flag=1;	
			}
			temp=temp->next;
	    }
		if(flag==0)	
		   printf("\nName does not exist\n");	
	}
}
view()
{
	srecord *temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("%s   %d   ",temp->data,temp->amount);
		if(temp->prstatus==1)
		  printf("net banking allowed\n");
		else
		  printf("net banking not allowed\n");
		temp=temp->next;
	}
	
}
menu()
{
	int ch;
	char ans;
	do
	{
		system("cls");
		printf("\n\nEnter \n1. Add records\n2. Remove records\n3. Update records\n4. Withdraw cash\n5. Deposit cash\n6. check details of existing customers\n");
	    scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			add();
			break;
		case 2:
			remover();
			break;
		case 3:
			update();
			break;
	    case 4:
			withdraw();
			break;
		case 5:
			deposit();
			break;
		case 6:
			view();
			break;
		default: printf("Invalid choice");
		}
		printf("\n\nDo you wish to continue?(y for yes and n for no)\n");
		scanf("%s",&ans);
	}while(ans=='y');
}
int main()
{
	char pass[10],password[10]="MyCapt";
	int i=0;
	printf("\n\n    Enter the password to login   :    ");
	scanf("%s",pass);
	pass[10]='\0';
	if(strcmp(pass,password)==0)
	{
		printf("\n\n   Password match\n\n");
		printf("   Loading the menu");
		for(i=0;i<=10;i++)
		{
			printf(".");
	    }
		for(i=0;i<=32767;i++)
		{
			for(j=0;j<=32767;j++)
		    {
			    printf("");
		    }
	    }
	    system("cls");
	    menu();
    }
    else
    {
    	printf("\n\n  Wrong Password\n\n");
    	login_try:
    	printf("  Enter 1 for retry and o for exit  :   ");
    	scanf("%d",&main_exit);
    	if(main_exit==1)
    	{
    		system("cls");
    		main();
    	}
    	else if(main_exit==0)
    	{
    		system("cls");
    		close();
    	}
    	else
    	{
    		printf("\n\n  Invalid choice\n\n");
    		for(i=0;i<=32767;i++)
		{
			for(j=0;j<=32767;j++)
		    {
			    printf("");
		    }
	    }
    		system("cls");
    		goto login_try;
    	}
    }
    return 0;
}
