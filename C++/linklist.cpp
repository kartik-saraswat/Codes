#include <iostream>

using namespace std;

class Node{
	
	public: int data;
			Node * next;
			Node(int data){
				this->data = data; 
				this->next =  NULL;
			}
};

class List{
	
	Node *head;
	public: List(){head = NULL;}
			void insert_beg(int data){
				Node * p = new Node(data);
				if(head == NULL){
					head = p;
				} else {
					p->next=head;
					head = p;
				}
				
			}
			void insert_end(int data){
				if(head == NULL){
					head = new Node(data);
				} else {
					Node *t = head;
					while(t->next!=NULL){
						t=t->next;
					}
					t->next = new Node(data);
				}
			}
			
			void insert_sorted(int data){
				Node *p = new Node(data);
				if(head == NULL){
					head = p;
				} else if( data < head->data){
					p->next = head;
					head = p;
				}
				else {
					Node *t = head;
					while(t->next!=NULL && data > t->next->data){
						t=t->next;
					}
					p->next = t->next;
					t->next = p;
				}
			}
			
			void display(string msg){
				cout<<"\n"<<msg<<" : ";
				for(Node *t = head; t != NULL; t=t->next){
					cout<<t->data<<" ";
				}
				cout<<"\n\n";
			}
			
			void delete_node(int key){
					if(isEmpty()){
						cout<<"\nEMPTY!!!\n";
						return;
					} else if(head->data == key){
						Node * p = head;
						head =  head->next;
						delete p;
					} else {
						Node * p = head;
						while(p->next!=NULL && p->next->data != key){
							p=p->next;
						}
						if((p->next!=NULL) && (p->next->data == key)){
							Node * q = p->next;
							p->next = q->next;
							delete q;
						}
					}
			}
			
			bool isEmpty(){
				return head == NULL;
			}
			
		static List* merge_sort(List* listA, List* listB){
			List* listC = new List();
			Node *p = listA->head;
			Node *q = listB->head;
			while( p!=NULL && q!=NULL){
				if(p->data<=q->data){
					listC->insert_end(p->data);
					p=p->next;
				} else {
					listC->insert_end(q->data);
					q=q->next;
				}
			}
			
			while(p!=NULL){
				listC->insert_end(p->data);
				p=p->next;
			}

			while(q!=NULL){
				listC->insert_end(q->data);
				q=q->next;
			}
			
			return listC;
		}
		
		void reverse_list_size(int size){
			head = reverse_size(head,size);
		}
		
		private:
		
		static Node* reverse_size(Node *head, int size){
				if(head == NULL || head->next == NULL){
					return head;
				} else {
					int c = 1;
					Node * p = head,*q,*r;
					q=p->next;
					while(q!=NULL&&c<size){
						cout<<"q="<<q->data<<"\n";
						r = q->next;
						q->next=p;
						p=q;
						q=r;
						c++;
					}
					
					if(q != NULL){
						head->next = reverse_size(q, size);
					} else{
						head->next = NULL;
					}
					
					return p;
				}
		}
		
};

int main(){
	List listA, listB;
	listA.insert_sorted(1);
	listA.insert_sorted(2);
	listA.insert_sorted(3);
	listA.insert_sorted(4);
	listA.insert_sorted(5);
	listA.insert_sorted(6);
	listA.insert_sorted(7);
	listA.insert_sorted(5);
	listA.display("List A");
	
	listA.reverse_list_size(3);
	listA.display("List A");
	
	
	return 0;
}