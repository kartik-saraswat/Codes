#include <iostream>
#include <stack>

using namespace std;

class MinStack{
	
	private:
	stack<int> mainStack, auxStack;
	
	public:
	void push(int data){
		mainStack.push(data);
		if((auxStack.empty())||(auxStack.top()>data)){
			auxStack.push(data);
		}
	}
	
	void pop(){
		if(!mainStack.empty()){
			if(mainStack.top() == auxStack.top()){
				auxStack.pop();
			}
			mainStack.pop();
		}
	}
	
	int top(){
		return mainStack.top();
	}
	
	int getMin(){
		if(!auxStack.empty()){
			return auxStack.top();
		} else {
			return -1;
		}
	}
};

int main(){
	MinStack S;
	S.push(10);
	S.push(20);
	S.push(30);
	cout<<S.getMin()<<endl;
	S.push(5);
	cout<<S.getMin()<<endl;
}