#include <iostream>
#include <vector>

using namespace std;


class Heap{

	protected:	
	int parent(int i){return (i+1)/2 -1;}
	int left(int i){return 2*i+1;}
	int right(int i){return 2*i+2;}

	void heapify(vector<int>& heap, int i, bool maxHeap){
		
		int l = left(i);
		int r = right(i);
		
		int index = i;
		if(l < heap.size() && (((maxHeap)&&(heap[index] < heap[l]))||((!maxHeap)&&(heap[index] > heap[l]))) ){
			index = l;
		}
		
		if(r < heap.size() && (((maxHeap)&&(heap[index] < heap[r]))||((!maxHeap)&&(heap[index] > heap[r]))) ){
			index = r;
		}
		
		if(index != i){
			swap(heap[i],heap[index]);
			heapify(heap, index, maxHeap);
		}
	}
};

class PriorityQueue: protected Heap{
	
	bool maxPriority;
	
	vector<int> queue;
	
	
	public:
	
	PriorityQueue(bool maxPriority){
		this->maxPriority =  maxPriority;	
	}
	
	int front(){
		return queue[0];
	}
	
	void extract(){
		if(queue.size()<1){
			cout<<"\n UnderFlow\n";
			return;
		} else{
			queue[0]=queue[queue.size()-1];
			queue.pop_back();
			heapify(queue,0,maxPriority);
		}
	}
	
	void changeKey(int i, int key){
		if((maxPriority&&queue[i]>key)||((!maxPriority)&&queue[i]<key)){
			cout<<"\n Error Change Key";
			return;
		} else{
			queue[i] = key;
			while((i>0)&&
				((maxPriority&&(queue[ parent(i) ] < queue[i])) 
					|| 
				(!maxPriority&&(queue[ parent(i) ] > queue[i])))){
				swap(queue[ parent(i) ], queue[i]);
				i = parent(i);
			}
		}
	}
	
	void insert(int key){
		queue.push_back(key);
		changeKey(queue.size()-1, key);
	}
};


void display(string msg, vector<int> v){
	cout<<"\n"<<msg<<" : ";
	for(int i =0; i< v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<"\n";
}

int main(){
	
	PriorityQueue pQ(true);
	
	pQ.insert(4);
	pQ.insert(1);
	pQ.insert(3);
	pQ.insert(2);
	pQ.insert(16);
	pQ.insert(9);
	pQ.insert(10);
	pQ.insert(14);
	pQ.insert(8);
	pQ.insert(7);
	
	cout<<pQ.front()<<endl; pQ.extract();
	cout<<pQ.front()<<endl; pQ.extract();
	cout<<pQ.front()<<endl; pQ.extract();
	cout<<pQ.front()<<endl; pQ.extract();
	cout<<pQ.front()<<endl; pQ.extract();
	cout<<pQ.front()<<endl; pQ.extract();
	cout<<pQ.front()<<endl; pQ.extract();
	cout<<pQ.front()<<endl; pQ.extract();
	cout<<pQ.front()<<endl; pQ.extract();
	cout<<pQ.front()<<endl; pQ.extract();
	return 0;
}