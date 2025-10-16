#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T> //Private inheritance since we do not want 3rd parties t be able to use vector implementations on our stacks
{
public:
    Stack(): std::vector<T>(){};
    ~Stack(){}; //since we inherit from vector class, we don't need another destructor

    bool empty() const{ //This checks if the stack is empty, inheriting from vector empty() function
			return std::vector<T>::empty();
		};
		
    size_t size() const{ //This returns the size of our stack, inheriting from vector size() function
			return std::vector<T>::size();
		};

    void push(const T& item){ //This pushes an element to the back of our stack , inheriting from vector push_back() function
			std::vector<T>::push_back(item);
		};

    void pop(){ //This removes from the back, as must be done in stacks with LIFO structure, inheriting from vector pop_back() function
			if (!(std::vector<T>::empty())){  
				std::vector<T>::pop_back();
			}
			else{			// throws std::underflow_error if empty
				throw std::underflow_error("This is an empty stack, we can't perform pop() function");
			}

		}; 


    const T& top() const{ //This will return the top item on the list, since it is LIFO, the last element is on the top, so we can inherit the back() function from vectors
			if (!(std::vector<T>::empty())){
				return std::vector<T>::back();
			}
			else{
				throw std::underflow_error("This is an empty stack, we can't perform top() function");
			}; // throws std::underflow_error if empty
		};
    // Add other members only if necessary
};


#endif