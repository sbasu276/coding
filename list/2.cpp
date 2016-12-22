/* Get Nth node from Last 
	Test cases: 
	1)	5 nodes 
		N = 1 , 2, 3, -1, 0, 10
	2)	1 node
		N = 1, 2, -1, 0
	3)	0 node
		N = -1, 0 , 1 
		
Algorithm:
1. Set i to the Nth node from start, j=head
2. Now increase i and j. Till i becomes the tail. 
*/

#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct node {
	int v;
	struct node *next;
}LL;

LL* push_back(LL* head, int val)
{
	LL *tmp = (LL*)malloc(sizeof(LL));
	if(tmp==NULL)
	{
		cout<<"Error creating node";
		return head;
	}
	tmp->v = val;
	tmp->next = NULL;
	if(head==NULL)
	{
		head = tmp;
		return head;
	}
	LL *i;
	for(i=head;i->next;i=i->next);
	i->next = tmp;
	return head;
}

LL* getNth(LL*head, int N)
{
	if(N>0)
	{
		if(head==NULL)
			return NULL;
		LL *i,*j;
		i=j=head;
		int count = 1;
		while(i!=NULL)
		{
			if(count == N)
				break;
			i=i->next;
			count++;
		}
		if(i==NULL)
			return NULL;
		while(i->next != NULL)
		{
			j=j->next;
			i=i->next;
		}
		return j;
	}
	return NULL;
}

int main()
{
	LL* list = NULL;
	LL* Nth;
	int limit, N;
	cin >> limit >> N;
	for(int i=1;i<=limit;i++)
		list = push_back(list,(i*rand()%100));
	
	for(LL *i=list ; i ; i=i->next)
		cout<<i->v<<" ";
	
	cout <<"\n";
	Nth = getNth(list,N);
	if ( Nth!=NULL)
	cout << Nth->v <<"\n";
return 0;
}
