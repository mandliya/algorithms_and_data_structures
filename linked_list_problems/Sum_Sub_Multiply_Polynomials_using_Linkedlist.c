#include<stdio.h>
#include<stdlib.h>

struct node
{

int coef;
int expo;
struct node *next;

};


void createPoly(struct node **);
void createPoly1(struct node **,int ,int);
void sumPoly(struct node **,struct node **);
void subPoly(struct node **,struct node **);
void mulPoly(struct node **,struct node **);
void display(struct node **);


struct node * createNode()
{

struct node *new;
new=(struct node*)malloc(sizeof(struct node));
return new;
}


void createPoly(struct node **head)
{
struct node *temp,*t;
temp=createNode();
printf("\nEnter coefficient:");
scanf("%d",&temp->coef);
printf("\nEnter exponent:");
scanf("%d",&temp->expo);
temp->next=NULL;

if(*head==NULL)
{
	*head=temp;	
}
else
{
	t=*head;
	while(t->next!=NULL)
	{
	t=t->next;	

	}
	t->next=temp;

	t=temp;
}


}

void createPoly1(struct node **head,int x,int y)
{
struct node *temp,*t;
temp=createNode();
temp->coef=x;
temp->expo=y;
temp->next=NULL;

if(*head==NULL)
{
	*head=temp;	
}
else
{
	t=*head;
	while(t->next!=NULL)
	{
	t=t->next;	

	}
	t->next=temp;

	t=temp;
}


}

void display(struct node **head)
{

struct node *t;
t=*head;

while(t!=NULL)
{

printf("(%dx^%d)+",t->coef,t->expo);
t=t->next;
}


}


void sumPoly(struct node **head1,struct node **head2)
{
struct node *t1=*head1;
struct node *t2=*head2;
struct node *head3=NULL;

while(t1!=NULL&&t2!=NULL)
{	

	if(t1->expo==t2->expo)
	{
		if((t1->coef+t2->coef)!=0)
		{
		createPoly1(&head3,t1->coef+t2->coef,t1->expo);
		t1=t1->next;
		t2=t2->next;	
		}
		else
		{
		t1=t1->next;
		t2=t2->next;		
		}

	}

	
	
	
	else if(t1->expo<t2->expo)
	{
	
	createPoly1(&head3,t2->coef,t2->expo);
	t2=t2->next;
			
	}	
	else
	{
			
	createPoly1(&head3,t1->coef,t1->expo);
	t1=t1->next;	
	}
	
	
	


}

while(t1!=NULL)
{
createPoly1(&head3,t1->coef,t1->expo);
t1=t1->next;
}

while(t2!=NULL)
{
createPoly1(&head3,t2->coef,t2->expo);
t2=t2->next;
}
display(&head3);

}





void subPoly(struct node **head1,struct node **head2)
{
struct node *t1=*head1;
struct node *t2=*head2;
struct node *head3=NULL;

while(t1!=NULL&&t2!=NULL)
{	

	if(t1->expo==t2->expo)
	{
		if((t1->coef-t2->coef)!=0)
		{
		createPoly1(&head3,t1->coef-t2->coef,t1->expo);
		t1=t1->next;
		t2=t2->next;	
		}
		else
		{
		t1=t1->next;
		t2=t2->next;		
		}

	}

	
	
	
	else if(t1->expo<t2->expo)
	{
	
	createPoly1(&head3,t2->coef,t2->expo);
	t2=t2->next;
			
	}	
	else
	{
			
	createPoly1(&head3,t1->coef,t1->expo);
	t1=t1->next;	
	}
	
	
	


}

while(t1!=NULL)
{
createPoly1(&head3,t1->coef,t1->expo);
t1=t1->next;
}

while(t2!=NULL)
{
createPoly1(&head3,t2->coef,t2->expo);
t2=t2->next;
}
display(&head3);

}

void mulPoly(struct node **head1,struct node **head2)
{
struct node *t1=*head1;
struct node *t2=*head2;
struct node *head3=NULL;

for(t1=*head1;t1!=NULL;t1=t1->next)
{
for(t2=*head2;t2!=NULL;t2=t2->next)
{
createPoly1(&head3,t1->coef*t2->coef,t1->expo+t2->expo);
}
}


display(&head3);

}

int main()
{
struct node *head1=NULL;
struct node *head2=NULL;

int no;
printf("\nEnter the number of terms in polynomial 1:");
scanf("%d",&no);
printf("Enter polynomial 1:\n");

for(int i=0;i<no;i++)
createPoly(&head1);

printf("\nEnter the number of terms in polynomial 2:");
scanf("%d",&no);
printf("Enter polynomial 2:\n");

for(int i=0;i<no;i++)
createPoly(&head2);


printf("\nPolynomial 1:");
display(&head1);
printf("\nPolynomial 2:");
display(&head2);

printf("\nAddition of the two polynomials: ");
sumPoly(&head1,&head2);


printf("\n");

printf("\nSubtraction of the two polynomials: ");
subPoly(&head1,&head2);

printf("\n");

printf("\nMultiplication of the two polynomials: ");
mulPoly(&head1,&head2);
return 0;
}
