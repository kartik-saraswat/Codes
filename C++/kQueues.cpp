#include <iostream>

using namespace std;

class KQueue{
	int n, k;
	int *arr, *front, *rear, *next;
	int free;
	public:
		KQueue(int n, int k){
			arr = new int[n];
			next = new int[n];
			front = new int[k];
			rear = new int[k];
			free = 0;
			
			for(int i = 0; i < k; i++){
				front[i]=rear[i]=-1;
			}
			
			for(int j = 0; j < n-1; j++){
				next[j]=j+1;
			}
			next[n-1]=-1;
		}
		bool isFull(){
			return free==-1;
		}
		
		bool isEmpty(int qn){
			return front[qn]==-1;
		}
		
		void enqueue(int qn, int item){			
			if(isFull()){
				cout<<"\nOverFlow";
				return;
			} else{
				int i = free;
				free =  next[i];
				if(isEmpty(qn)){
					front[qn] = i;
				} else {
					next[ rear[qn] ] = i;	
				}
				rear[qn]=i;
				arr[i]=item;
			}
		}
		
		int dequeue(int qn){
			if(isEmpty(qn)){
				cout<<"\nUnderFlow\n";
				return -1;
			} else{
				int i = front[qn];
				front[qn] = next[i];
				next[i] = free;
				free = i;
				if(rear[qn]==i){
					rear[qn] = front[qn]=-1;
				}
				return arr[i];
			}
		}
};

int main(){
	KQueue kQ(10,3);
	
	kQ.enqueue(2,15);
	kQ.enqueue(2,45);
	
	kQ.enqueue(1,1);
	kQ.enqueue(1,2);
	kQ.enqueue(1,3);
	kQ.enqueue(1,4);
	
	cout<<kQ.dequeue(1)<<endl;
	cout<<kQ.dequeue(1)<<endl;
	cout<<kQ.dequeue(1)<<endl;
	cout<<kQ.dequeue(2)<<endl;
	cout<<kQ.dequeue(2)<<endl;
	cout<<kQ.dequeue(2)<<endl;
	
	
	
	return 0;
}