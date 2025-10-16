#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include <functional>
#include <iostream>
#include <stdexcept>

template <typename T, typename PComparator = std::less<T> >
class Heap: private std::vector<T>
{
public: 
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator()): ary_ness(m), comparator(c){}; //Setting the constructor with either default or non-default values

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap(){};

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below

  PComparator comparator; 
  int ary_ness;

	std:: vector<T> heap_;

};

// Add implementation of member functions here




// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    throw std::underflow_error ("This is an empty heap, we can't access the top element. ");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  else{
      return heap_.at(0); //This returns the top element of the heap
  }

}



template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){

	//Since this is a heap, we will push back and trickle up, according to the comparator that is passed
	heap_.push_back(item);

	//std::cout<<"pushed "<<item<<std::endl;
  size_t curr= (heap_.size())-1; //This is the current index that we inserted at the end

  //Keeps looping till it reaches the top of list, if it doesn't break before
  while(curr>0){
    size_t parent= ((curr-1)/ary_ness); //Getting the parent node's index

    //Using the comparator function
    if (comparator(heap_[curr], heap_[parent])){
      //std::cout<<"swapping"<<std::endl;
      //If the property is true, we swap
      std::swap(heap_[curr], heap_[parent]);
			//std::cout<<heap_[curr]<<heap_[parent]<<std::endl;
      curr=parent;
    }else{break;} //We stop when our heap meets conditions

  }

}



// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(heap_.empty()){
    throw std::underflow_error ("This is an empty heap, we can't perform the pop() function since there is no top element");
  }

  else{
		std::swap(heap_.back(), heap_.front()); //We switch the root node with the last leaf
		heap_.pop_back(); //We remove the last leaf node, which just became the value of our root node
		//Now we go down


		size_t size_heap= heap_.size();

		//I am starting at root node
		size_t curr=0;

		//I will loop while the current node still has children
		while(size_heap> (curr*ary_ness +1) ){

			//We will create our first child
			size_t child = curr*ary_ness +1;
			
			//I will set this as the default best value
			size_t best=child;

			//I will now check whether the other children of the node have higher priority to swap
			for (size_t i=1; i<ary_ness; i++){
				size_t next= child+i;

				//I am checking whether the next node is valid
				if (next<size_heap){
					//If my next node has higher priority order, I will now set the new best node to the next child
					if(comparator(heap_[next], heap_[best])){
						best=next;
					}
				}
			}
		
		//I will compare the best child to swap (the one with highest priority) to the current node
		if ( comparator(heap_[best], heap_[curr])){
				//If it satisfies our condition, we swap
				std::swap(heap_[curr],heap_[best]);
				curr=best;
		}else{break;}
	}
	}
}




//This will return a bool, 0 or 1 whether empty or not
template <typename T, typename PComparator>
bool Heap<T,PComparator>:: empty() const{
  return heap_.empty(); 

}

//This will return the size of the heap
template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{
  return heap_.size(); 
}





#endif

