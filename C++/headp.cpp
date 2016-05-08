#include <iostream>
#include <vector>

using namespace std;

class Heap{
	
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
	
	void build_heap(vector<int>& heap, bool maxHeap){		
		int nonLeafNode = (heap.size()-1)/2;
		for(int i = nonLeafNode; i >= 0; i--){
			heapify(heap,i, maxHeap);
		}
	}
	
	public:
	vector<int> heapSort(vector<int>& heap, bool maxHeap){	
		vector<int> sortedHeap;
		build_heap(heap, maxHeap);
		int size = heap.size();
		for(int i = size-1; i >= 0; i-- ){
			swap(heap[0],heap[i]);
			sortedHeap.push_back(heap[i]);
			heap.pop_back();
			heapify(heap,0,maxHeap);
		}
		
		return sortedHeap;
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
	
	vector<int> heap;
	heap.push_back(4);
	heap.push_back(1);
	heap.push_back(3);
	heap.push_back(2);
	heap.push_back(16);
	heap.push_back(9);
	heap.push_back(10);
	heap.push_back(14);
	heap.push_back(8);
	heap.push_back(7);
	
	display("Heap",heap);
	
	Heap Sorter;
	vector<int> sorted = Sorter.heapSort(heap, false);
	display("Heap",sorted);
	return 0;
}