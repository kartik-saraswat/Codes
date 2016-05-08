#include <iostream>
#include <queue>

using namespace std;

class QStack{
	private:
		int x;
		queue<int> Q[2];
	public:
	    QStack(){x=0;}
		
		void push(int data){
			Q[x].push(data);
		}
		
		int pop(){
			int r = -1;
			if(!Q[x].empty()){
				int y = (x+1)%2;
				int size = Q[x].size();
				while(size>1){
					Q[y].push(Q[x].front());
					Q[x].pop();
					size--;
				}
				r = Q[x].front();
				x = y;
			}
			return r;
		}
};

int main(){
	
	QStack suQ;
	
	suQ.push(1);
	suQ.push(2);
	suQ.push(3);
	cout<<suQ.pop()<<endl;
	cout<<suQ.pop()<<endl;
	cout<<suQ.pop()<<endl;
	
	return 0;
}