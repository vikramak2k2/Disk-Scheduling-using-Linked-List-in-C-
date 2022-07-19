#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}NODE;
NODE *root1=NULL;
int cylinder;
void fcfs()
{
	NODE *v,*t1=root1,*root=NULL;
	while(t1!=NULL)
	{
		NODE *temp=(NODE*)malloc(sizeof(NODE));
		temp->next=NULL;
		temp->prev=NULL;
		temp->data=t1->data;
		if(root==NULL)
			root=temp;
		else
		{
			v=root;
			while(v->next!=NULL)
				v=v->next;
			v->next=temp;
			temp->prev=v;
		}
		t1=t1->next;
	}

	printf("********************************************************************\n");
	printf("------------------------FCFS DISK SCHEDULING------------------------\n");
	printf("********************************************************************\n");
	int head,i,j,qsize=0;
	float diff,seek=0.0,avg=0.0;	
	NODE *temp=root,*temp1=root->next;
	while(temp->next!=NULL)
	{
		diff=abs(temp->data-temp1->data);
		seek+=diff;
		printf("DISK MOVING FROM %d TO %d WITH SEEK %f\n",temp->data,temp1->data,diff);
		temp=temp->next;
		temp1=temp1->next;
		qsize++;
	}
	printf("TOTAL SEEK TIME = %f\n",seek);
	avg=seek/qsize;
	printf("AVERAGE SEEK TIME IS %f\n",avg);
	printf("********************************************************************\n");
	
}
void sstf()
{
	NODE *v,*t1=root1,*root=NULL;
	while(t1!=NULL)
	{
		NODE *temp=(NODE*)malloc(sizeof(NODE));
		temp->next=NULL;
		temp->prev=NULL;
		temp->data=t1->data;
		if(root==NULL)
			root=temp;
		else
		{
			v=root;
			while(v->next!=NULL)
				v=v->next;
			v->next=temp;
			temp->prev=v;
		}
		t1=t1->next;
	}

	NODE *t=root->next;
	for(;t->next!=NULL;t=t->next)
	{
		for(t1=t->next;t1!=NULL;t1=t1->next)
		{
			if(t->data>t1->data)
			{
				int a=t->data;
				t->data=t1->data;
				t1->data=a;
			}
		}
	}
	printf("********************************************************************\n");
	printf("------------------------SSTF DISK SCHEDULING------------------------\n");
	printf("********************************************************************\n");
	int head,i,j,qsize=0;
	float diff,seek=0.0,avg=0.0;	
	NODE *temp=root,*temp1=root->next;
	while(temp->next!=NULL)
	{
		diff=abs(temp->data-temp1->data);
		seek+=diff;
		printf("DISK MOVING FROM %d TO %d WITH SEEK %f\n",temp->data,temp1->data,diff);
		temp=temp->next;
		temp1=temp1->next;
		qsize++;
	}
	printf("TOTAL SEEK TIME = %f\n",seek);
	avg=seek/qsize;
	printf("AVERAGE SEEK TIME IS %f\n",avg);
	printf("********************************************************************\n");
	
}
void scan()
{
	NODE *v,*t1=root1,*root=NULL;
	while(t1!=NULL)
	{
		NODE *temp=(NODE*)malloc(sizeof(NODE));
		temp->next=NULL;
		temp->prev=NULL;
		temp->data=t1->data;
		if(root==NULL)
			root=temp;
		else
		{
			v=root;
			while(v->next!=NULL)
				v=v->next;
			v->next=temp;
			temp->prev=v;
		}
		t1=t1->next;
	}

	NODE *t=root->next;
	for(;t->next!=NULL;t=t->next)
	{
		for(t1=t->next;t1!=NULL;t1=t1->next)
		{
			if(t->data>t1->data)
			{
				int a=t->data;
				t->data=t1->data;
				t1->data=a;
			}
		}
	}
	printf("********************************************************************\n");
	printf("------------------------SCAN DISK SCHEDULING------------------------\n");
	printf("********************************************************************\n");
	float seek=0;
	int i=0,j=0,qsize=0,diff;
	float avg=0.0;
	t=root;
	while(t!=NULL)
	{
		j++;
		t=t->next;
	}	
	NODE *temp=root->next,*temp1=temp,*p=(NODE*)malloc(sizeof(NODE)),*cur,*t2,*new;
	p->next=NULL;
	p->prev=NULL;
	p->data=root->data;
	while(temp!=NULL)
	{
		if(temp->data>root->data)
		{
			p->prev=temp->prev;
			p->next=temp;
			p->prev->next=p;
			temp->prev=p;
			cur=p;
			root=root->next;
			break;
		}
		temp=temp->next;
	}
	t=cur->prev;
	t1=cur->next;
	if(abs(t->data-cur->data)>abs(t1->data-cur->data))
	{
		t2=cur;
		while(t1!=NULL)
		{
			diff=abs(t2->data-t1->data);
			printf("DISK MOVING FROM %d -> %d WITH %d DIFFERENCE\n",t2->data,t1->data,diff);
			seek+=diff;
			new=t1;
			t1=t1->next;
			t2=t2->next;
		}
		t2=cur;
		int x=cylinder-1;
		diff=abs((cylinder-1)-new->data);
		printf("DISK MOVING FROM %d -> %d with %d DIFFERENCE\n",new->data,cylinder-1,diff);
		seek+=diff;
			while(t2!=root)
			{
				if(i==0)
				{
					diff=abs(new->data-t->data);
					printf("DISK MOVING FROM %d -> %d WITH %d DIFFERENCE\n",cylinder-1,t->data,diff);
					seek+=diff;
					i++;
					t=t->prev;
					t2=t2->prev;
				}
				else
				{
					diff=abs(t2->data-t->data);
					printf("DISK MOVING FROM %d -> %d WITH %d DIFFERENCE\n",t2->data,t->data,diff);
					seek+=diff;
					t=t->prev;
					t2=t2->prev;
				}
			}
	}
	else
	{
		t2=cur;
		while(t2!=root)
		{
			diff=abs(t2->data-t->data);
			printf("DISK MOVING FROM %d -> %d WITH %d DIFFERENCE\n",t2->data,t->data,diff);
			seek+=diff;
			new=t;
			t=t->prev;
			t2=t2->prev;
		}
		t2=cur;
		int x=0;
		diff=abs(new->data);
		printf("DISK MOVING FROM %d -> %d WITH %d DIFFERENCE\n",new->data,x,diff);
		seek+=diff;
		while(t1!=NULL)
		{
			if(i==0)
			{
				diff=abs(x-t1->data);
				printf("DISK MOVING FROM %d -> %d WITH %d DIFFERENCE\n",x,t1->data,diff);
				seek+=diff;
				i++;
				t1=t1->next;
				t2=t2->next;
			}
			else
			{
				diff=abs(t2->data-t1->data);
				printf("DISK MOVING FROM %d -> %d WITH %d DIFFERENCE\n",t2->data,t1->data,diff);
				seek+=diff;
				t1=t1->next;
				t2=t2->next;
			}
		}
	}
	printf("SEEK = %f\n",seek);
	printf("AVERAGE = %f\n",seek/j);
	printf("********************************************************************\n");
	
}	
void cscan()
{
	NODE *v,*t1=root1,*root=NULL;
	while(t1!=NULL)
	{
		NODE *temp=(NODE*)malloc(sizeof(NODE));
		temp->next=NULL;
		temp->prev=NULL;
		temp->data=t1->data;
		if(root==NULL)
			root=temp;
		else
		{
			v=root;
			while(v->next!=NULL)
				v=v->next;
			v->next=temp;
			temp->prev=v;
		}
		t1=t1->next;
	}
	NODE *t=root->next;
	for(;t->next!=NULL;t=t->next)
	{
		for(t1=t->next;t1!=NULL;t1=t1->next)
		{
			if(t->data>t1->data)
			{
				int a=t->data;
				t->data=t1->data;
				t1->data=a;
			}
		}
	}
	printf("********************************************************************\n");
	printf("-----------------------CSCAN DISK SCHEDULING------------------------\n");
	printf("********************************************************************\n");
	float seek=0;
	int i=0,j=0,qsize=0,diff;
	float avg=0.0;
	t=root;
	while(t!=NULL)
	{
		j++;
		t=t->next;
	}	
	NODE *temp=root->next,*temp1=temp,*p=(NODE*)malloc(sizeof(NODE)),*cur,*t2,*new;
	p->next=NULL;
	p->prev=NULL;
	p->data=root->data;
	while(temp!=NULL)
	{
		if(temp->data>root->data)
		{
			p->prev=temp->prev;
			p->next=temp;
			p->prev->next=p;
			temp->prev=p;
			cur=p;
			root=root->next;
			break;
		}
		temp=temp->next;
	}
	t=cur->prev;
	t1=cur->next;
	if(abs(t->data-cur->data)>abs(t1->data-cur->data))
	{
		t2=cur;
		while(t1!=NULL)
		{
			diff=abs(t2->data-t1->data);
			printf("DISK MOVING FROM %d -> %d WITH %d DIFFERENCE\n",t2->data,t1->data,diff);
			seek+=diff;
			new=t1;
			t1=t1->next;
			t2=t2->next;
		}
		diff=abs(new->data-cylinder-1);
		printf("DISK MOVING FROM %d -> %d WITH %d DIFFERENCE\n",new->data,cylinder-1,diff);
		seek+=diff;
		int x=0,y=cylinder-1;
	        t2=root;
		t1=t2->next;
		printf("DISK MOVING FROM %d -> %d WITH %d DIFFERENCE\n",y,x,y);
		seek+=y;
		diff=abs(x-t2->data);
		printf("DISK MOVING FROM %d -> %d WITH %d DIFFERENCE\n",x,t2->data,diff);
	        seek+=diff;	
       		while(t1!=cur)
		{
			diff=abs(t2->data-t1->data);
			printf("DISK MOVING FROM %d -> %d WITH %d DIFFERENCE\n",t2->data,t1->data,diff);		
			seek+=diff;
			t1=t1->next;
			t2=t2->next;
		}
	}
	else
	{
		t2=cur;
		while(t2!=root)
		{
			diff=abs(t2->data-t->data);
			printf("DISK MOVING FROM %d -> %d WITH %d DIFFERENCE\n",t2->data,t->data,diff);
			seek+=diff;
			new=t;
			t=t->prev;
			t2=t2->prev;
		}
		int x=0,y=cylinder-1;
		diff=root->data;
		seek+=diff;
		printf("DISK MOVING FROM %d -> %d WITH %d DIFFERENCE\n",root->data,x,diff);
		t=cur->next;
		for(;t->next!=NULL;t=t->next)
		{
			for(t1=t->next;t1!=NULL;t1=t1->next)
			{
				if(t->data<t1->data)
				{
					int a=t->data;
					t->data=t1->data;
					t1->data=a;
				}
			}
		}
		printf("DISK MOVING FROM %d -> %d WITH %d DIFFERENCE\n",x,y,y);
		seek+=y;
		t=cur;
		t1=cur->next;
		diff=(abs(y-cur->next->data));
		printf("DISK MOVING FROM %d -> %d WITH %d DIFFERENCE\n",y,cur->next->data,diff);
		t=t->next;
		t1=t1->next;
		seek+=diff;
		while(t1!=NULL)
		{
			diff=abs(t->data-t1->data);
			printf("DISK MOVING FROM %d -> %d WITH %d DIFFERENCE\n",t->data,t1->data,diff); 
			seek+=diff;
			t=t->next;
			t1=t1->next;
		}
	}
	printf("SEEK = %f\n",seek);
	printf("AVERAGE = %f\n",seek/j);
	printf("********************************************************************\n");
}
void look()
{
	NODE *v,*t1=root1,*root=NULL;
	while(t1!=NULL)
	{
		NODE *temp=(NODE*)malloc(sizeof(NODE));
		temp->next=NULL;
		temp->prev=NULL;
		temp->data=t1->data;
		if(root==NULL)
			root=temp;
		else
		{
			v=root;
			while(v->next!=NULL)
				v=v->next;
			v->next=temp;
			temp->prev=v;
		}
		t1=t1->next;
	}
	NODE *t=root->next;
	for(;t->next!=NULL;t=t->next)
	{
		for(t1=t->next;t1!=NULL;t1=t1->next)
		{
			if(t->data>t1->data)
			{
				int a=t->data;
				t->data=t1->data;
				t1->data=a;
			}
		}
	}
	printf("********************************************************************\n");
	printf("------------------------LOOK DISK SCHEDULING------------------------\n");
	printf("********************************************************************\n");
	float seek=0;
	int i=0,j=0,qsize=0,diff;
	float avg=0.0;
	t=root;
	while(t!=NULL)
	{
		j++;
		t=t->next;
	}	
	NODE *temp=root->next,*temp1=temp,*p=(NODE*)malloc(sizeof(NODE)),*cur,*t2,*new;
	p->next=NULL;
	p->prev=NULL;
	p->data=root->data;
	while(temp!=NULL)
	{
		if(temp->data>root->data)
		{
			p->prev=temp->prev;
			p->next=temp;
			p->prev->next=p;
			temp->prev=p;
			cur=p;
			root=root->next;
			break;
		}
		temp=temp->next;
	}
	t=cur->prev;
	t1=cur->next;
	if(abs(t->data-cur->data)>abs(t1->data-cur->data))
	{
		t2=cur;
		while(t1!=NULL)
		{
			diff=abs(t2->data-t1->data);
			printf("DISK MOVING FROM %d -> %d WITH %d DIFFERENCE\n",t2->data,t1->data,diff);
			seek+=diff;
			new=t1;
			t1=t1->next;
			t2=t2->next;
		}
		t2=cur;
		
			while(t2!=root)
			{
				if(i==0)
				{
					diff=abs(new->data-t->data);
					printf("DISK MOVING FROM %d -> %d WITH %d DIFFERENCE\n",new->data,t->data,diff);
					seek+=diff;
					i++;
					t=t->prev;
					t2=t2->prev;
				}
				else
				{
					diff=abs(t2->data-t->data);
					printf("DISK MOVING FROM %d -> %d WITH %d DIFFERENCE\n",t2->data,t->data,diff);
					seek+=diff;
					t=t->prev;
					t2=t2->prev;
				}
			}
		
	}
	else
	{
		t2=cur;
		while(t2!=root)
		{
			diff=abs(t2->data-t->data);
			printf("DISK MOVING FROM %d -> %d WITH %d DIFFERENCE\n",t2->data,t->data,diff);
			seek+=diff;
			new=t;
			t=t->prev;
			t2=t2->prev;
		}
		t2=cur;
		while(t1!=NULL)
		{
			if(i==0)
			{
				diff=abs(new->data-t1->data);
				printf("DISK MOVING FROM %d -> %d WITH %d DIFFERENCE\n",new->data,t1->data,diff);
				seek+=diff;
				i++;
				t1=t1->next;
				t2=t2->next;
			}
			else
			{
				diff=abs(t2->data-t1->data);
				printf("DISK MOVING FROM %d -> %d WITH %d DIFFERENCE\n",t2->data,t1->data,diff);
				seek+=diff;
				t1=t1->next;
				t2=t2->next;
			}
		}
	}
	printf("SEEK = %f\n",seek);
	printf("AVERAGE = %f\n",seek/j);
	printf("********************************************************************\n");
}	
void clook()
{
	NODE *v,*t1=root1,*root=NULL;
	while(t1!=NULL)
	{
		NODE *temp=(NODE*)malloc(sizeof(NODE));
		temp->next=NULL;
		temp->prev=NULL;
		temp->data=t1->data;
		if(root==NULL)
			root=temp;
		else
		{
			v=root;
			while(v->next!=NULL)
				v=v->next;
			v->next=temp;
			temp->prev=v;
		}
		t1=t1->next;
	}
	NODE *t=root->next;
	for(;t->next!=NULL;t=t->next)
	{
		for(t1=t->next;t1!=NULL;t1=t1->next)
		{
			if(t->data>t1->data)
			{
				int a=t->data;
				t->data=t1->data;
				t1->data=a;
			}
		}
	}
	printf("********************************************************************\n");
	printf("-----------------------CLOOK DISK SCHEDULING------------------------\n");
	printf("********************************************************************\n");
	float seek=0;
	int i=0,j=0,qsize=0,diff;
	float avg=0.0;
	t=root;
	while(t!=NULL)
	{
		j++;
		t=t->next;
	}	
	NODE *temp=root->next,*temp1=temp,*p=(NODE*)malloc(sizeof(NODE)),*cur,*t2,*new;
	p->next=NULL;
	p->prev=NULL;
	p->data=root->data;
	while(temp!=NULL)
	{
		if(temp->data>root->data)
		{
			p->prev=temp->prev;
			p->next=temp;
			p->prev->next=p;
			temp->prev=p;
			cur=p;
			root=root->next;
			break;
		}
		temp=temp->next;
	}
	t=cur->prev;
	t1=cur->next;
	if(abs(t->data-cur->data)>abs(t1->data-cur->data))
	{
		t2=cur;
		while(t1!=NULL)
		{
			diff=abs(t2->data-t1->data);
			printf("DISK MOVING FROM %d -> %d WITH %d DIFFERENCE\n",t2->data,t1->data,diff);
			seek+=diff;
			new=t1;
			t1=t1->next;
			t2=t2->next;
		}
		diff=abs(new->data-root->data);
		printf("DISK MOVING FROM %d -> %d WITH %d DIFFERENCE\n",new->data,root->data,diff);
		seek+=diff;
	        t2=root->next;
		t1=t2;
       		while(t1!=cur)
		{
			diff=abs(t2->prev->data-t1->data);
			printf("DISK MOVING FROM %d -> %d WITH %d DIFFERENCE\n",t2->prev->data,t1->data,diff);		
			seek+=diff;
			t1=t1->next;
			t2=t2->next;
		}
	}
	else
	{
		t2=cur;
		while(t2!=root)
		{
			diff=abs(t2->data-t->data);
			printf("DISK MOVING FROM %d -> %d WITH %d DIFFERENCE\n",t2->data,t->data,diff);
			seek+=diff;
			new=t;
			t=t->prev;
			t2=t2->prev;
		}
		t=cur->next;
		for(;t->next!=NULL;t=t->next)
		{
			for(t1=t->next;t1!=NULL;t1=t1->next)
			{
				if(t->data<t1->data)
				{
					int a=t->data;
					t->data=t1->data;
					t1->data=a;
				}
			}
		}
		t=cur;
		t1=cur->next;
		diff=(abs(new->data-cur->next->data));
		printf("DISK MOVING FROM %d -> %d WITH %d DIFFERENCE\n",new->data,cur->next->data,diff);
		t=t->next;
		t1=t1->next;
		seek+=diff;
		while(t1!=NULL)
		{
			diff=abs(t->data-t1->data);
			printf("DISK MOVING FROM %d -> %d WITH %d DIFFERENCE\n",t->data,t1->data,diff); 
			seek+=diff;
			t=t->next;
			t1=t1->next;
		}
	}
	printf("SEEK = %f\n",seek);
	printf("AVERAGE = %f\n",seek/j);
	printf("********************************************************************\n");
}	
int main()
{
	int ch;
	printf("ENTER THE SIZE OF CYLINDERS: ");
	scanf("%d",&cylinder);
	while(1)
	{
		NODE *t=(NODE*)malloc(sizeof(NODE));
		printf("1.INSERT------2.FCFS------3.SSTF------4.SCAN------5.CSCAN------6.LOOK------7.CLOOK------8.EXIT\nENTER CHOICE:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				if(root1==NULL)
				{
					printf("ENTER HEAD VALUE:");
					scanf("%d",&t->data);
					t->next=NULL;
					t->prev=NULL;
					root1=t;
				}
				else
				{
					printf("ENTER THE VALUE:");
					scanf("%d",&t->data);
					t->next=NULL;
					t->prev=NULL;
					NODE *p=root1;
					while(p->next!=NULL)
						p=p->next;
					p->next=t;
					t->prev=p;
				}
				break;
			case 2:
				fcfs();
				break;
			case 3:
				sstf();
				break;
			case 4:
				scan();
				break;
			case 5:
				cscan();
				break;
			case 6:
				look();
				break;
			case 7:
				clook();
				break;		
			case 8:
				printf("------THANK YOU!!------\n");
				exit(0);	
			default:
				printf("ENTER THE VALID OPTION !!!!\n");
		}
	}	
	return 0;	
}
	

