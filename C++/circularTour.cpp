#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class PetrolPump{
	
	public:
		int petrol,distance;
		PetrolPump(int petrol, int distance){
			this->petrol = petrol;
			this->distance = distance;
		}
};

bool isFull(int front, int rear,int size){
	return (front==0&&rear==(size-1))||(rear == front-1);
}

void printQ(string msg, queue<int> q){
	cout<<"\n"<<msg<<" : ";
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<"\n";
}

void getFirst(vector<PetrolPump> petrolPump){
	bool tourCompleted = false;
	queue<int> Q;
	int i = 0;
	int currentPetrol = 0;
	do{
		currentPetrol = currentPetrol + petrolPump[i].petrol;
		Q.push(i%petrolPump.size());
		i++;
		while((!Q.empty())&&((currentPetrol - petrolPump[Q.back()].distance) < 0)){
			cout<<"\n "<<currentPetrol;
			printQ("Negative At Q", Q);
			currentPetrol -= (petrolPump[Q.front()].petrol - petrolPump[Q.front()].distance);
			Q.pop();
		}
	}while((i<2*petrolPump.size())&&(Q.size() < petrolPump.size()));
	
	if(Q.size() == petrolPump.size()){
		cout<<"\n Tour from "<<Q.front();
	}
}

int main(){
	vector<PetrolPump> petrolPump;
	petrolPump.push_back( PetrolPump(4,6));
	petrolPump.push_back( PetrolPump(6,5));
	petrolPump.push_back( PetrolPump(7,3));
	petrolPump.push_back( PetrolPump(4,5));
	
	getFirst(petrolPump);
	return 0;
}