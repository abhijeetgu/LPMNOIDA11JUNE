// BinaryTrees
#include <iostream>
using namespace std;

class node{
public:	
	int data;
	node* left;
	node* right;

	node(int d){
		data = d;
		left = right = NULL;
	}
};

node* CreateTree(){
	int data;
	cin>>data;
	if(data == -1){
		return NULL;
	}

	node* root = new node(data);
	root->left = CreateTree();
	root->right = CreateTree();

	return root;
}

void PreOrder(node* root){
	if(root == NULL){
		return;
	}

	cout<<root->data<<" ";
	PreOrder(root->left);
	PreOrder(root->right);
}

void InOrder(node* root){
	if(root == NULL){
		return;
	}

	InOrder(root->left);
	cout<<root->data<<" ";
	InOrder(root->right);
}

void PostOrder(node* root){
	if(root == NULL){
		return;
	}

	PostOrder(root->left);
	PostOrder(root->right);
	cout<<root->data<<" ";
}

int CountNodes(node* root){
	if(root == NULL){
		return 0;
	}

	return CountNodes(root->left)+CountNodes(root->right)+1;
}

int Height(node* root){
	if(root == NULL){
		return 0;
	}

	int left = Height(root->left);
	int right = Height(root->right);
	return max(left,right)+1;
}

int Diameter(node* root){
	if(root == NULL){
		return 0;
	}

	int op1 = Height(root->left) + Height(root->right);
	int op2 = Diameter(root->left);
	int op3 = Diameter(root->right);
	return max(op1,max(op2,op3));
}

class Pair{
public:
	int height;
	int diameter;
};

Pair FastDiameter(node* root){
	Pair p;
	if(root == NULL){
		p.height = p.diameter = 0;
		return p;
	}

	Pair left = FastDiameter(root->left);
	Pair right= FastDiameter(root->right);

	p.height = max(left.height,right.height)+1;

	int op1 = left.height + right.height;
	int op2 = left.diameter;
	int op3 = right.diameter;
	p.diameter = max(op1,max(op2,op3));
	return p;
}

int main(){
	node* root = NULL;
	root = CreateTree();

	PreOrder(root);
	cout<<endl;
	InOrder(root);
	cout<<endl;
	PostOrder(root);
	cout<<endl;
	cout<<"Number of Nodes : "<<CountNodes(root)<<endl;
	cout<<"Height of Tree : "<<Height(root)<<endl;
	cout<<"Diameter of Tree : "<<Diameter(root)<<endl;

	Pair p =FastDiameter(root);
	cout<<"Height of Tree : "<<p.height<<endl;
	cout<<"Diameter of Tree : "<<p.diameter<<endl;	

	return 0;
}