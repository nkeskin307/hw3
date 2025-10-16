#include <iostream>
using namespace std;
#include "stack.h"
#include <vector>
#include <stdexcept>


int main(){

	Stack <int> tempS;

	if (tempS.empty()){
		std::cout<<"The stack is empty, now pushing back"<<std::endl;
		tempS.push(5);
		tempS.push(4);
		tempS.push(1);
	}

	std::cout<<"We pushed some items"<<std::endl;
	std::cout<<"The current size of stack is: "<<tempS.size()<<std::endl;

	std::cout<<"This is the top item in the Stack: "<<tempS.top()<<std::endl;

	std::cout<<"Removing an item from the top now"<<std::endl;
	tempS.pop();
	std::cout<<"This is the size after popping: "<<tempS.size()<<std::endl;

	std::cout<<"Removing an item from the top now"<<std::endl;
	tempS.pop();
	std::cout<<"This is the size after popping: "<<tempS.size()<<std::endl;

	std::cout<<"Removing an item from the top now"<<std::endl;
	tempS.pop();
	std::cout<<"This is the size after popping: "<<tempS.size()<<std::endl;
	
	std::cout<<"Removing an item from the top now"<<std::endl;
	tempS.pop();


	return 0;
}

