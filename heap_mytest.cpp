#include "heap.h"
#include <iostream>
using namespace std;

int main(){

	Heap <int> min_heap(2); //Using the default constructor

	min_heap.push(5);
	std::cout<<"Just pushed 10"<<std::endl;
	min_heap.push(0);
	min_heap.push(10);


	std::cout<<"This order must be ascending since this is a Min Heap:"<<std::endl;
	while (!(min_heap.empty())){
		std::cout<<"Not Empty"<<std::endl;
		std::cout<<"Top"<< min_heap.top()<<" ";
		std::cout<<"Pop"<<std::endl;
		min_heap.pop();
	}
	std::cout<<std::endl;

	return 0;
}