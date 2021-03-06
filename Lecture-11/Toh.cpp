// Toh
#include <iostream>
using namespace std;

void toh(int n,char source,char helper,char destination){
	// Base case
	if(n==0){
		return;
	}

	// Recursive case
	// A:source, B : Helper, C : Destination
	// Move n-1 disks from A to B
	toh(n-1,source,destination,helper);
	// Manually take nth disk from A to C
	cout<<"Taking disk "<<n<<" from "<<source<<" to "<<destination<<endl;
	// Move n-1 disks from B to C
	toh(n-1,helper,source,destination);
}


int main(){
	int n;
	cin>>n;

	toh(n,'A','B','C');


	return 0; 
}