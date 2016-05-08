#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isAlpha(char c){
	return (c>='A'&&c<='Z')||(c>='a'&&c<='z')||(c>='0'&&c<='9');
}

int rank(char c){
	switch(c){
		case '+': 
		case '-': return 1;
		case '*': 
		case '/': return 2;
		case '^': return 3;
		default: return 0;
	};


void infixToPostfix(string infix){
	infix.push_back(')');
	cout<<"\n Infix : "<<infix;
	string postfix; 
	stack<char> mystack;
	mystack.push('(');
	int r,s;
	for(int i = 0; i < infix.length(); i++){
		if(isAlpha(infix[i])){
			postfix.push_back(infix[i]);
		} else if((r=rank(infix[i]))>0){
				while(!mystack.empty() && (rank(mystack.top()) > r)){
					postfix.push_back(mystack.top());
					mystack.pop();
				}
			mystack.push(infix[i]);	
		} else if( infix[i] == '('){
			mystack.push('(');
		} else if( infix[i]==')'){
			while(!mystack.empty() && (mystack.top() != '(')){
					postfix.push_back(mystack.top());
					mystack.pop();
				}
			if(mystack.top() == '('){
				mystack.pop();
			}	
		}
	}
	
	cout<<"\n Postfix : "<<postfix;
	
}


int main(){

	string infix;
	
	cout<<"\n Enter Infix: ";
	getline(cin,infix);
	
	infixToPostfix(infix);
	
	return 0;
}