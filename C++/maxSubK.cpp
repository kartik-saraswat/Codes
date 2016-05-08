#include <iostream>
#include <queue>

using namespace std;

void printQ(string msg, queue<int> q){
	cout<<"\n"<<msg<<" : ";
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<"\n";
}

void printMaxK(vector<int> v, int k){
	queue<int> Q;
	int i =0;
	Q.push(v[0]);
	for(i=1;i<k;i++){
		if(Q.back()<v[i]){
			Q.push(v[i]);
			Q.pop();
		}
	}
	printQ("Q",Q);
	
	for(i = k; i < v.size(); i++){
		if(Q.back()<v[i]){
			Q.push(v[i]);
			Q.pop();
		}
		printQ("Q",Q);	
	}
}

int main(){
	vector<int> v;
	v.push_back(8);
	v.push_back(5);
	v.push_back(10);
	v.push_back(7);
	v.push_back(9);
	v.push_back(4);
	v.push_back(15);
	v.push_back(12);
	v.push_back(90);
	v.push_back(13);
	printMaxK(v, 4);
	return 0;
}