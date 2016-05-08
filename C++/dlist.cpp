#include <iostream>

using namespace std;

class Node{
	
	public: int data;
			Node * next;
			Node * previous;
			Node(int data){
				this->data = data; 
				this->next =  NULL;
				this->previous =  NULL;
			}
};

class DList{
	
	Node *head;
	public: DList(){head = NULL;}
			void insert_beg(int data){
				Node * p = new Node(data);
				if(head == NULL){
					head = p;
				} else {
					p->next=head;
					head->previous = p;
					head = p;
				}
				
			}
			void insert_end(int data){
				Node *p = new Node(data);
				if(head == NULL){
					head = p;
				} else {
					Node *t = head;
					while(t->next!=NULL){
						t=t->next;
					}
					t->next = p;
					p->previous = t;
				}
			}
			
			void insert_sorted(int data){
				Node *p = new Node(data);
				if(head == NULL){
					head = p;
				} else if( data < head->data){
					p->next = head;
					head->previous = p;
					head = p;
				}
				else {
					Node *t = head;
					while(t->next!=NULL && data > t->next->data){
						t=t->next;
					}
					p->next = t->next;
					if(t->next!=NULL){
						t->next->previous = p;
					}
					t->next = p;
					p->previous = t;
				}
			}
			
			void display(string msg){
				cout<<"\n"<<msg<<" : ";
				for(Node *t = head; t != NULL; t=t->next){
					cout<<t->data<<" ";
				}
				cout<<"\n\n";
			}
			
			void remove(int key){
					if(isEmpty()){
						cout<<"\nEMPTY!!!\n";
						return;
					} else if(head->data == key){
						Node * p = head;
						head =  head->next;
						if(head!=NULL){
							head->previous = NULL;
						}
						delete p;
					} else {
						Node * p = head;
						while(p->next!=NULL && p->next->data != key){
							p=p->next;
						}
						if((p->next!=NULL) && (p->next->data == key)){
							Node * q = p->next;
							p->next = q->next;
							if(q->next!=NULL){
								q->next->previous = p;
							}
							delete q;
						}
					}
			}
			
			bool isEmpty(){
				return head == NULL;
			}
			
			void reverse(){
				if(head == NULL || head->next == NULL){
					return;
				} else {
					Node *p = head,*q=p;;
					while(p!=NULL){
						q=p;
						swapNodes(&(p->next), &(p->previous));
						p = p->previous;
					}
					head = q;
				}
		}
			

		private:
		void swapNodes(Node **x, Node** y){
			Node *t = *x;
			*x = *y;
			*y = t;
		}
};

int main(){
	DList listA, listB;
	listA.insert_sorted(1);
	listA.insert_sorted(2);
	listA.insert_sorted(3);
	listA.insert_sorted(4);
	listA.reverse();
	listA.display("List A");
	
	//listA.reverse_list_size(3);
	//listA.display("List A");
	
	
	return 0;
}