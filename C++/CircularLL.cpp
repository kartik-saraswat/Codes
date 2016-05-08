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


class CircularLL{
	
	public:
		Node *tail;
		CircularLL(){
			tail = NULL;
		}
		
		CircularLL(Node *tail){
			this->tail = tail;
		}
		
		bool isEmpty(){
			return tail == NULL;
		}
		
		Node* front(){
			return (!isEmpty())?(tail->next):NULL;
		}
		
		void insert(int data){
			Node* p = new Node(data);
			if(isEmpty()){
				tail = p;
				tail->next = tail;
			} else {
				p->next = tail->next;
				tail->next = p;
				tail = p;
			}
		}
		
		void remove(){
			if(isEmpty()){
				cout<<"\nERROR : EMPTY!!\n";
			} else if(tail->next == tail){
				delete tail;
				tail =  NULL;
			} else{
				Node* p = tail->next;
				tail->next = p->next;
				delete p;
			}
		}
		
		void display(string msg){
				cout<<"\n"<<msg<<" : ";
				if(tail!=NULL){
					for(Node *t = front(); t != tail; t=t->next){
						cout<<t->data<<" ";
					}
					cout<<tail->data<<" ";
				}
				cout<<"\n\n";
			}
			
		Node* split(){
			if(isEmpty()||tail->next == tail){
				return NULL;
			} else {
				Node *slow, *fast;
				slow = front();
				fast = slow;
				while(fast != tail&&fast->next!=tail){
					slow = slow->next;
					fast = fast->next->next;
				}
				Node *mid = slow;
				Node *start_1 =  front();
				Node *tail_2 = tail;
				tail->next = mid->next;
				mid->next = start_1;
				tail = mid;
				return tail_2;
			}
		}	
};

int main(){
	
	CircularLL listA;
	
	listA.insert(1);
	listA.insert(2);
	listA.insert(3);
	listA.insert(4);
	listA.insert(5);
	
	CircularLL listB(listA.split());
	listA.display("CList A");
	listB.display("CList B");
	return 0;
}