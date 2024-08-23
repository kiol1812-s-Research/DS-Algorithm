#include<iostream>
using namespace std;

void swap(int &a,int &b){
	//實作swap
	int temp=a;
	a = b;
	b = temp;
}
void copy(int* begin,int* end,int* result){
	//實作copy
	// int *test=new int[end-begin+1]{0};
	int index=0;
	for(int* p=begin; p!=end; p++){
		*(result+index++) = *p;
	}
	*(result+index) = 0;
}

int main(){
	int aa=1, bb=2;
	cout<<"aa: "<<aa<<",bb: "<<bb<<"\n";
	swap(aa, bb);
	cout<<"aa: "<<aa<<",bb: "<<bb<<"\n------------------\n";

	int array[10]={0}, array2[11]={0};
	for(int i=0; i<10; i++) array[i]=i;
	cout<<"array: ";
	for(auto &a:array) cout<<a<<" ";
	cout<<"\n";
	copy(array, array+10, array2);
	cout<<"array2: ";
	for(auto &a:array2) cout<<a<<" ";

	return 0;
}
