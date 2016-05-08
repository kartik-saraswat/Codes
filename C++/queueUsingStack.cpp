#include <iostream>
#include <stack>
using namespace std;

class SQueue{
	
	private:
		stack<int> S[2];
		
	public:
		void enqueue(int data){
			S[0].push(data);
		}
		
		
		
		int dequeue(){
			if(S[0].empty()&&S[1].empty()){
				cout<<"\nUnderFlow\n";
				return -1;
			} else {
				if(S[1].empty()){
					while(!S[0].empty()){
						S[1].push(S[0].top());
						S[0].pop();
					}
				}
				int r = S[1].top();
				S[1].pop();
				return r;
			}
		}
};

int main(){
	
	SQueue quS;
	
	quS.enqueue(1);
	quS.enqueue(2);
	quS.enqueue(3);
	quS.enqueue(4);
	quS.enqueue(5);
	
	cout<<quS.dequeue()<<endl;
	cout<<quS.dequeue()<<endl;
	cout<<quS.dequeue()<<endl;
	cout<<quS.dequeue()<<endl;
	cout<<quS.dequeue()<<endl;
	
	return 0;
}