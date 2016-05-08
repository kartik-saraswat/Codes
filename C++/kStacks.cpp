#include <iostream>

using namespace std;

class KStack{
	
	int *arr, *topList, *next;
	int k, n;
	int free;

	public: 
	KStack(int k, int n){
		this->k = k;
		this->n = n;
		arr = new int[n];
		topList = new int[k];
		next = new int[n];
		
		free = 0;
		for(int i = 0; i < k; i++){
			topList[i] = -1;
		}
		
		for(int j = 0; j < n-1; j++){
			next[j] = j+1;
		}
		next[n-1]=-1;
	}
	
	bool isFull(){
		return free==-1;
	}
	
	bool isEmpty(int stackNumber){
		return topList[stackNumber]==-1;
	}
	
	int top(int stackNumber){
		if(topList[stackNumber] != -1)
			return arr[ topList[stackNumber] ];
		else
			return -1;	
	}
	
	void push(int stackNumber, int item){
		if(isFull()){
			cout<<"\nOverFlow\n";
			return;
		} else{
			int i = free;
			free = next[i];
			next[i]=topList[stackNumber];
			topList[stackNumber]=i;
			arr[i]=item;
		}
	}
	
	int pop(int stackNumber){
		if(isEmpty(stackNumber)){
			cout<<"\nUnderFlow\n";
			return -1;
		} else{
			int i = topList[stackNumber];
			topList[stackNumber] =  next[i];
			next[i] = free;
			free = i;
		    return arr[i];
		}
	}
};

int main(){
	
	KStack kS(3,6);
	
	kS.push(2,1);
	kS.push(2,2);
	kS.push(2,3);
	
	kS.push(1,4);
	kS.push(1,5);
	kS.push(1,6);
	
	cout<<kS.pop(1)<<endl;
	cout<<kS.pop(1)<<endl;
	cout<<kS.pop(1)<<endl;
	
	cout<<kS.pop(2)<<endl;
	cout<<kS.pop(2)<<endl;
	cout<<kS.pop(2)<<endl;
	return 0;
}