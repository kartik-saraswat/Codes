#include <iostream>

using namespace std;

class Node{
	public:
		int data;
		Node *parent;
		Node *left;
		Node *right_sibling;
		Node(int data){
			this->data = data;
			this->parent = this->left = this->right_sibling = NULL;
		}
		
		Node* addChild(int data){
			Node *child = new Node(data);
			//cout<<"\nO->"<<data;
			child->parent = this;
			if(this->left == NULL){
				this->left = child;
			} else {
				Node *p=this->left;
				while(p->right_sibling!=NULL){
				//	cout<<" #"<<p->data;
					p = p->right_sibling;
				}
				//cout<<" #"<<p->data;
				p->right_sibling = child;
			}
		    return child;	
		}
};

class Tree{
	public:
	Node *root;
	Tree(){root = NULL;}
	Tree(Node *root){
		this->root = root;
	}
	
	static void traverse(Node *node){
		char c;
		if(node!=NULL){
			cout<<" "<<node->data;
			
			if(node->left!=NULL){
				traverse(node->left);
			}
			
			if(node->right_sibling!=NULL){
				traverse(node->right_sibling);
			}
		}
	}
};

int main(){
	
	Node *root =  new Node(1);
    root->addChild(2)->addChild(6)->addChild(7);
	root->addChild(3)->addChild(8)->addChild(9);
	root->addChild(4)->addChild(10)->addChild(11);
	root->addChild(5)->addChild(12)->addChild(13);
	
	Tree::traverse(root);
	

	return 0;
}