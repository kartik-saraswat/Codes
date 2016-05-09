#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class Node{
	public:
		int data;
		Node *left;
		Node *right;
		Node(int data){
			this->data = data;
			this->left = this->right = NULL;
		}
		
		Node* addChild(int data){
			Node *child = new Node(data);
			if(this->left == NULL){
				this->left = child;
				return child;
			} else if(this->right == NULL){
				this->right = child;
				return child;
			} else{
				cout<<"\n"<<this->data<<"Already has both children";
				return NULL;
			}
		}
		
		bool isLeaf(){
			return (this->left == NULL&&this->right==NULL);
		}
		
		int height(){
			if(isLeaf()){
				return 1;
			} else {
				int leftHeight = (left == NULL)?0:left->height();
				int rightHeight = (right == NULL)?0:right->height();
				
				return (1 + max(leftHeight, rightHeight));
			}
		}
		
		int diameter(){
			if(isLeaf()){
				return 1;
			} else {
				
				int leftHeight = (left == NULL)?0:left->height();
				int rightHeight = (right == NULL)?0:right->height();
				int leftDiameter = (left == NULL)?0:left->diameter();
				int rightDiameter = (right == NULL)?0:right->diameter();
				
				return max(leftHeight + rightHeight + 1, max(leftDiameter, rightDiameter));
			}
		}
		
		static void width_recursive(Node *p, vector<int>& counter, int level){
			if(p!=NULL){
				counter[level]++;
				width_recursive(p->left, counter, level+1);
				width_recursive(p->right, counter, level+1);
			}
		}
		
		int width(){
			int h = height();
			vector<int> counter(h,0);
			width_recursive(this, counter, 0);
			return *max_element(counter.begin(), counter.end());
		}
};

class BinaryTree{
	public:
		Node *root;
		BinaryTree(){
			root=NULL;
		} 
		
		BinaryTree(Node *root){
			this->root=root;
		}
		
		int height(){
			return root->height();
		}
		
		int diameter(){
			return root->diameter();
		}
		
		int width(){
			root->width();
		}

		
		static void dfsTraversal(Node *root){
			if(root!=NULL){
				dfsTraversal(root->left);
							cout<<" "<<root->data;
				dfsTraversal(root->right);
			}
		}
		
		static void levelTraversal(Node *root){
			if(root!=NULL){
				queue<Node*> nodeQ;
					nodeQ.push(root);
					
					while(!nodeQ.empty()){
						Node *p = nodeQ.front();
						nodeQ.pop();
						cout<<" "<<p->data; 
						if(p->left!=NULL){
							nodeQ.push(p->left);
						}
						if(p->right!=NULL){
							nodeQ.push(p->right);
						}
					}
			}
		}
		
		static void inorderTraversal(Node* root){
			stack<Node*> nodeS;
			Node * p = root;
			nodeS.push(root);
			//cout<<"\n1. Pushed : "<<nodeS.top()->data;
			while(!nodeS.empty()){
				while(nodeS.top()->left != NULL){
					nodeS.push(nodeS.top()->left);
					//cout<<"\n2. Pushed : "<<nodeS.top()->data;
				}
				
				p = nodeS.top(); nodeS.pop();
				cout<<"\n3. Popped : "<<p->data;
				if(p->right != NULL){
					nodeS.push(p->right);
					//cout<<"\n4. Pushed : "<<nodeS.top()->data;
				} else if(!nodeS.empty()){
					p = nodeS.top(); 
					nodeS.pop();
					cout<<"\n5. Popped : "<<p->data;
					if(p->right != NULL){
						nodeS.push(p->right);
						//cout<<"\n6. Pushed : "<<nodeS.top()->data;
					}
				}
			}	
			cout<<"\n Done";
		}
		
	static void morrisInorderTraversal(Node *root){
		Node *p = root, *pred;
		while(p!=NULL){
			
			if(p->left == NULL){
				cout<<" "<<p->data;
				p = p->right;
			} else{
				pred = p->left;
				while(pred->right!=NULL && pred->right != p){
					pred = pred->right;
				}
				
				if(pred->right == NULL){
					pred->right = p;
					p = p->left;
				} else {
					pred->right = NULL;
					cout<<" "<<p->data;
					p = p-> right;
				}
			}
		}
	}

	static void morrisPreorderTraversal(Node *root){
		Node *p = root, *pred;
		while(p!=NULL){
			if(p->left==NULL){
				cout<<" "<<p->data;
				p = p->right;	
			} else {
				pred = p->left;
				while(pred->right!=NULL && pred->right!=p){
					pred = pred->right;
				}
				if(pred->right == NULL){
					pred->right = p;
					cout<<" "<<p->data;
					p = p->left;
				} else{
					pred->right = NULL;
					p = p-> right;
				}
			}
		}
	}
	
	static void morrisPostorderTraversal(Node *root){
		Node *dummyRoot = new Node(0);
		dummyRoot->left = root;
		Node *p = dummyRoot, *pred, *first, *middle, *last;
		while(p!=NULL){		
			if(p->left == NULL){
				p = p->right;
			} else{
				pred = p->left;
				while(pred->right!=NULL && pred->right != p){
					pred = pred->right;
				}
				
				if(pred->right == NULL){
					pred->right = p;
					p = p->left;
				} else {
					
					first = p;
					middle = p->left;
					while(middle!=p){
						last = middle->right;
						middle->right = first;
						first = middle;
						middle = last;
					}
					
					first = p;
					middle = pred;
					while(middle!=p){
						cout<<" "<<middle->data;
						last = middle->right;
						middle->right = first;
						first = middle;
						middle = last;
					}
					pred->right = NULL;
					p = p-> right;
				}
			}
		}	
	}
	
	static int search(const vector<int>& v, int i , int j, int item){
		while(i<=j){
			if(v[i]==item)
				return i;
			i++;
		}
	   return -1;	
	}
	
	static Node* construct( vector<int>& in,int v1, int v2, vector<int>& pre, int p1, int p2){		
		Node *root = new Node(pre[p1]);
		if(v1 < v2){
			int pos = search(in, v1, v2, pre[p1]);
			int x = pos-v1;	
			root->left = construct(in, v1, pos-1,pre, p1+1, p1+ x);
			root->right = construct(in, pos+1, v2,pre, p1+x+1, p2);
		}
		return root;
	}
};



int main(){
	// Binary Tree
	Node * root = new Node(1);
	Node * p = root->addChild(2);
	Node * q = root->addChild(3);
	Node * r = p->addChild(4);
	p->addChild(5);
	q->addChild(6);
	q->addChild(7);
	r->right = r->addChild(8);
	r->left = NULL;
	r->right->addChild(9);
	r->right->addChild(10);
	
	cout<<" "<<root->width();
	return 0;
}