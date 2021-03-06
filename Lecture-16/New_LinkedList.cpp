// New_LinkedList
// LinkedList
#include <iostream>
using namespace std;

class node{
public:
	int data;
	node* next;
	node(int d):data(d),next(NULL){}
};

void InsertAtFront(node* &head,int data){
	if(head == NULL){
		node* n = new node(data);
		head = n;
	}
	else{
		node* n = new node(data);
		n->next = head;
		head =n;
	}
}

void Print(node* head){
	while(head){
		cout<<head->data<<"-->";
		head = head->next;
	}
	cout<<endl;
}

int length(node* head){
	int count=0;
// NULL == 0
	while(head){
		count++;
		head=head->next;
	}
	return count;
}

node* mid(node* head){
	if(head == NULL || head->next == NULL){
		return head;
	}
	node* fast = head->next;
	node* slow = head;

	while(fast!=NULL && fast->next!=NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

node* search(node* head,int key){
	while(head){
		if(head->data == key){
			return head;
		}
		head=head->next;
	}
	return NULL;
}

void BubbleSortLL(node* &head){
	node* c;
	node* n;
	node* p;
	int iterations = length(head)-1;
	for(int i=0;i<=iterations;i++){
		c = head;
		p = NULL;
		while(c && c->next){
			n = c->next;
			if(c->data>n->data){
				// Swapping
				if(p == NULL){
					// Head will change
					c->next = n->next;
					n->next = c;
					head = p = n;
				}
				else{
					// head wont change
					c->next = n->next;
					n->next = c;
					p->next = n;
					p = n;
				}
			}
			else{
				// No swapping
				p = c;
				c = c->next;
			}
		}
	}

}

void ReverseLL(node* &head){
	node* c= head;
	node* p = NULL;
	node* n;

	while(c){
		n = c->next;
		c->next = p;
		p = c;
		c = n;
	}
	head = p;
}

node* merge(node* a,node* b){
	if(a==NULL){
		return b;
	}
	if(b==NULL){
		return a;
	}
	node* c;
	if(a->data<b->data){
		c = a;
		c->next = merge(a->next,b);
	}
	else{
		c = b;
		c->next = merge(a,b->next);
	}
	return c;
}

node* MergeSortLL(node* head){
	// Base case
	if(head == NULL || head->next == NULL){
		return head;
	}
	// Divide
	node* m = mid(head);
	node* a = head;
	node* b = m->next;
	m->next = NULL;
	
	// Sort
	a = MergeSortLL(a);
	b = MergeSortLL(b);
	// Merge
	node* newHead = merge(a,b);
	return newHead;
}


int main(){
	node* head=NULL;
	node* head1=NULL;

	InsertAtFront(head,0);
	InsertAtFront(head,2);
	InsertAtFront(head,4);
	InsertAtFront(head,6);
	InsertAtFront(head,4);
	InsertAtFront(head,5);
	InsertAtFront(head,6);
	InsertAtFront(head,7);
	Print(head);
	head = MergeSortLL(head);
	Print(head);

	// InsertAtFront(head1,9);
	// InsertAtFront(head1,7);
	// InsertAtFront(head1,5);
	// InsertAtFront(head1,3);
	// InsertAtFront(head1,1);
	// InsertAtFront(head1,0);
	// Print(head1);
	// head = merge(head,head1);
	// Print(head);
	// BubbleSortLL(head);
	// Print(head);
	// ReverseLL(head);
	// Print(head);
	// ReverseLL(head);
	// Print(head);

	// node* ans = search(head,60);
	// if(ans!=NULL){
	// 	cout<<"Found :"<<ans->data<<endl;
	// }
	// else{
	// 	cout<<"Not Found"<<endl;
	// }

	// cout<<"Length : "<<length(head)<<endl;
	// node* m = mid(head);
	// cout<<m->data<<endl;

	return 0;
}