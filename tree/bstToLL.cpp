/* Inplace conversion of node to Doubly Linked List */
#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct Node
{
	int v;
	struct Node *r,*l;
}node;

node* push(node *head, int val)
{
	node *tmp = (node*)malloc(sizeof(node));
	tmp->v = val;
	tmp->r = tmp->l = NULL;

	if(head == NULL)
		return tmp;	

	node *p = head;

	while(p)
	{
		if(p->v == val)
		{
			cout << "DUPLICATE\n";
			return head;
		}
		else if(p->v > val)
		{
			if(p->l != NULL)
				p=p->l;
			else
			{
				p->l=tmp;
				return head;
			}
		}
		else
		{
			if(p->r != NULL)
				p=p->r;
			else
			{
				p->r=tmp;
				return head;
			}
		}
	}

	
}

node* pop(node *head, int val)
{

}

void display(node *head)
{
	if(head == NULL)
		return;
	cout << head->v << " ";
	display(head->l);
	//cout << head->v << " ";
	display(head->r);
}



void convertDLL(node *root, node **head)
{
	if(root == NULL)
		return;
	static node* pred = NULL; // keeps track of predecessor, global to all function calls
	// convert left subtree
	convertDLL(root->l, head);
	if(pred == NULL)
		*head = root;
	else
	{
		pred->r = root;
		root->l = pred;
	}
	pred = root;
	// convert right subtree
	convertDLL(root->r, head);

}
node* convert(node *head)
{
// Inorder traversal: Inorder Pred => left(prev), Successor => right(next)
	
	convertDLL(head,&head);
	return head;
}

void disp(node *head)
{
	for(node *p=head; p ; p=p->r)
		cout<<p->v << " ";
}


int main()
{
	node *T=NULL;

	T=push(T,5);
	T=push(T,2);
	T=push(T,10);
	T=push(T,1);
	T=push(T,7);

	display(T);
	T= convert(T);
	cout<<"\n LL : ";
	disp(T);
return 0;
}









