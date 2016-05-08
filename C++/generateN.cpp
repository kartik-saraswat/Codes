#include <iostream>
#include <queue>
#include <string>

using namespace std;

void printQ(string msg, queue<int> q){
	cout<<"\n"<<msg<<" : ";
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<"\n";
}

void print(int n){
	queue< string > Q;
	Q.push("1");
	for(int i = 1; i <= n; i++){
		cout<<Q.front()<<endl;
	
		Q.push(string(Q.front()).append("0"));
		Q.push(string(Q.front()).append("1"));
		Q.pop();
	}
}
int main(){
	print(10);
	return 0;
}