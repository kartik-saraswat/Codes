#include <iostream>
#include <vector>

using namespace std;


class Queue{
	vector<int> queue;
	int front, rear;
	int size;
	public: 
	Queue(int size){
		front = rear = -1;
		this->size = size;
		queue = vector<int>(size,0);
	}

	bool isEmpty(){
		return front == -1;
	}
	bool isFull(){
		return (front==0&&rear==size-1)||(rear == front-1);
	}
	
	void insert(int data){
		if(isFull()){
			cout<<"\nOverFlow\n";
		}else if( isEmpty() ) {
			front = rear = 0;
			queue[rear] = data;
		} else{
			rear = (rear + 1)%size;
			queue[rear] = data;
		}
	}
	
	void remove(){
		 if(isEmpty()){
			 cout<<"\nUnderflow\n";
		 } else if(front==rear){
			 front = rear = -1;
		 } else{
			 front = (front + 1)%size;
		 }
	}
	
	int getFront(){
		return queue[front];
	}
};

int main(){
	
	Queue Q(5);
	
	Q.insert(1);
	Q.insert(2);
	Q.insert(3);
	Q.insert(4);
	
	cout<<Q.getFront()<<endl; Q.remove();
	cout<<Q.getFront()<<endl; Q.remove();
	cout<<Q.getFront()<<endl; Q.remove();	
	cout<<Q.getFront()<<endl; Q.remove();
	
	
	return 0;
}