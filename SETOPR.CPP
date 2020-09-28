#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
struct node
{
	int ele;
	struct node *link;
};

class Set
{
	public:
	struct node *start;
	Set()
	{
		start=NULL;
	}

	void showSet(struct node*);
	void addItem(struct node*);
	struct node * deleteItem(struct node*);
	struct node * deleteSet(struct node*);

	void Union(struct node*,struct node*);
	void Intersect(struct node*,struct node*);
	void Minus(struct node*,struct node*);

	int search(struct node*,float);
};

void main()
{
	Set s1,s2,s3;
	clrscr();
	int c,n,i;
	float itm;
	char ch='y';
	do
	{
		s1.start=s1.deleteSet(s1.start);
		s2.start=s2.deleteSet(s2.start);
		s3.start=s3.deleteSet(s3.start);

		printf("\n===== Enter 1st Set details =====\n");
		printf("How many items are in Set :\n");
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			printf("Enter %d element of set :",i+1);
			s1.addItem(s1.start);
		}
		printf("\n===== Enter 2nd Set details =====\n");
		printf("How many items are in Set :\n");
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			printf("Enter %d element of set :",i+1);
			s2.addItem(s2.start);
		}

		clrscr();

		printf("\n===== 1st Set is =====\n");
		s1.showSet(s1.start);
		printf("\n===== 2nd Set is =====\n");
		s2.showSet(s2.start);

		printf("\n\nWhat do you want \n1) Union Of Sets\n2) Intersection Of Sets");
		printf("\n3) Minus Of Sets \nEnter your choice : ");
		scanf("%d",&c);
		switch(c)
		{
			case 1:

				s3.Union(s1.start,s2.start);

				printf("\n===== 1st Set is =====\n");
				s1.showSet(s1.start);
				printf("\n===== 2nd Set is =====\n");
				s2.showSet(s2.start);

				printf("\n===== Union Of Sets =====\n");
				s3.showSet(s3.start);

				break;

			case 2:

				s3.Intersect(s1.start,s2.start);

				printf("\n===== 1st Set is =====\n");
				s1.showSet(s1.start);
				printf("\n===== 2nd Set is =====\n");
				s2.showSet(s2.start);

				printf("\n===== Intersection Of Sets =====\n");
				s3.showSet(s3.start);

				break;

			case 3:

				s3.Minus(s1.start,s2.start);

				printf("\n===== 1st Set is =====\n");
				s1.showSet(s1.start);
				printf("\n===== 2nd Set is =====\n");
				s2.showSet(s2.start);

				printf("\n===== Minus Of Sets =====\n");
				s3.showSet(s3.start);

				break;

			default:
				printf("\nWrong choice ");
				getch();
				clrscr();
				break;
		}

		printf("\n\nDO YOU WANT TO EXIT(Y/N)? : ");
		ch=getch();
		clrscr();

	}while(ch=='N' || ch=='n');

}

void Set::addItem(struct node *start)
{
	int n;
	int tt;

	struct node *temp;

	temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("\nOut of memory");
		getch();
		return;
	}
	if(start==NULL)
	{
		scanf("%d",&tt);
		n=search(this->start,tt);
		if(n==0)
		{
			temp->ele=tt;
			temp->link=NULL;
			start=temp;
			this->start=temp;
		}
		else
		{
			printf("\nElement (%d) already in set.\n",tt);
			free(temp);
		}
	}
	else
	{
		scanf("%d",&tt);
		n=search(this->start,tt);
		if(n==0)
		{
			struct node *pre=start;
			while(pre->link!=NULL)
			{
				pre=pre->link;
			}
			temp->ele=tt;
			temp->link=NULL;
			pre->link=temp;
		}
		else
		{
			printf("\nElement (%d) already in set.\n",tt);
			free(temp);
		}

	}
}

int Set::search(struct node *start,float itm)
{
	int fn=0;
	struct node *temp=start;
	while(temp!=NULL)
	{
		if(itm==temp->ele)
		{
			fn++;
		}
		temp=temp->link;
	}
	return fn;
}

struct node * Set::deleteSet(struct node *start)
{
	// to delete the given set elements

	struct node *next,*temp;
	temp=start;
	while(temp!=NULL)
	{
		next=temp->link;
		free(temp);
		temp=next;
	}
	start=NULL;
	return start;
}

void Set::showSet(struct node *start)
{
	struct node *temp=start;
	if(start==NULL)
	{
		printf("\n===== No terms in Polynomial =====\n");
	}
	else
	{
		printf("\n[");

		do
		{
			if(temp->link!=NULL)
			{
				printf(" %d,",temp->ele);
			}
			else
			{
				printf(" %d",temp->ele);
			}
			temp=temp->link;
		}while(temp!=NULL);

		printf("]\n");
	}
}

void Set::Union(struct node* s1,struct node* s2)
{
	float tt;
	int n=0;
	struct node *s3,*temp=NULL,*pre,*pr;

	s3=NULL;

	while(s1!=NULL)
	{
		temp=(struct node*)malloc(sizeof(struct node));
		if(temp==NULL)
		{
			printf("\nOut of memory");
			getch();
			return;
		}
		if(s3==NULL)
		{
			temp->ele=s1->ele;
			temp->link=NULL;
			s3=temp;
			s1=s1->link;
		}
		else
		{
			pre=s3;
			pr=s3;
			while(pr!=NULL)
			{
				if(pr->ele==s1->ele)
				{
					n=1;
					break;
				}
				if(pre->link!=NULL)
				{
					pre=pre->link;
				}
				pr=pr->link;
			}
			if(n==0)
			{
				temp->ele=s1->ele;
				temp->link=NULL;
				pre->link=temp;
				s1=s1->link;
			}
			else
			{
				free(temp);
				n=0;
				s1=s1->link;
			}
		}

	}

	while(s2!=NULL)
	{
		temp=(struct node*)malloc(sizeof(struct node));
		if(temp==NULL)
		{
			printf("\nOut of memory");
			getch();
			return;
		}
		if(s3==NULL)
		{
			temp->ele=s2->ele;
			temp->link=NULL;
			s3=temp;
			s2=s2->link;

		}
		else
		{
			pre=s3;
			pr=s3;
			while(pr!=NULL)
			{
				if(pr->ele==s2->ele)
				{
					n=1;
					break;
				}
				if(pre->link!=NULL)
				{
					pre=pre->link;
				}
				pr=pr->link;
			}
			if(n==0)
			{
				temp->ele=s2->ele;
				temp->link=NULL;
				pre->link=temp;
				s2=s2->link;
			}
			else
			{
				free(temp);
				n=0;
				s2=s2->link;
			}
		}
	}
	this->start=s3;
}

void Set::Intersect(struct node* ts1,struct node* ts2)
{
	float tt;
	int n=0;
	struct node *s3,*temp=NULL,*pre,*pr;
	struct node *s1,*s2;
	
	s1=ts1;
	s2=ts2;
	s3=NULL;

	while(s1!=NULL)
	{
		temp=(struct node*)malloc(sizeof(struct node));
		if(temp==NULL)
		{
			printf("\nOut of memory");
			getch();
			return;
		}
		s2=ts2;
		while(s2!=NULL)
		{
			if(s1->ele==s2->ele)
			{
				if(s3==NULL)
				{
					temp->ele=s1->ele;
					temp->link=NULL;
					s3=temp;
				}
				else
				{
					pre=s3;
					while(pre->link!=NULL)
					{
						pre=pre->link;
					}		
					temp->ele=s1->ele;
					temp->link=NULL;
					pre->link=temp;
				}
				n=1;
				break;
			}
			s2=s2->link;
		}
		if(n==0)
		{
			free(temp);	
		}
		n=0;
		s1=s1->link;
	}

	this->start=s3;
}

void Set::Minus(struct node* ts1,struct node* ts2)
{
	float tt;
	int n=0;
	struct node *s3,*temp=NULL,*pre,*pr;
	struct node *s1,*s2;
	
	s1=ts1;
	s2=ts2;
	s3=NULL;

	while(s1!=NULL)
	{
		temp=(struct node*)malloc(sizeof(struct node));
		if(temp==NULL)
		{
			printf("\nOut of memory");
			getch();
			return;
		}
		s2=ts2;
		while(s2!=NULL)
		{
			if(s1->ele==s2->ele)
			{
				n=1;
				break;
			}
			s2=s2->link;
		}
		if(n==0)
		{
			if(s3==NULL)
			{
				temp->ele=s1->ele;
				temp->link=NULL;
				s3=temp;
			}
			else
			{
				pre=s3;
				while(pre->link!=NULL)
				{
					pre=pre->link;
				}		
				temp->ele=s1->ele;
				temp->link=NULL;
				pre->link=temp;
			}	
		}
		else
		{
			free(temp);
		}
		n=0;
		s1=s1->link;
	}

	this->start=s3;
}