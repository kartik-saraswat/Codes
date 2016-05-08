#include <iostream>
#include <stack>
using namespace std;

void push_bottom(stack<int>& S, int key){
	
	if(!S.empty()){
		int temp = S.top();
		S.pop();
		push_bottom(S,key);

		S.push(temp);
	} else{
		S.push(key);
	}
	
}
void reverse_stack(stack<int>& S){
	if(!S.empty()){
		int temp = S.top();
		S.pop();
		reverse_stack(S);
		push_bottom(S,temp);
	}
}

void push_sorted(stack<int>& S, int key){
	if(!S.empty() && S.top() < key){
		int temp = S.top();
		S.pop();
		push_sorted(S,key);
		S.push(temp);
	} else{
		S.push(key);
	}
}

void sort_stack(stack<int>& S){
	if(!S.empty()){
		int temp = S.top();
		S.pop();
		sort_stack(S);
		push_sorted(S,temp);
	}
}

void display(string msg, stack<int> S){
	cout<<"\n "<<msg<<" : ";
	while(!S.empty()){
		cout<<S.top()<<" ";
		S.pop();
	}
	cout<<"\n";
}

int main(){
	
	stack<int> S;
	S.push(5);
	S.push(3);
	S.push(7);
	S.push(2);
	S.push(4);
	display("Stack S",S);
	sort_stack(S);
	display("Stack S",S);
	
	return 0;
}