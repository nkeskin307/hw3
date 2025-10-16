#include "llrec.h"
#include <iostream>
using namespace std;

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){

	//This is my base case
	if (head==NULL){ //I am checking whether head is empty, if true setting others to nullptrs
		smaller=larger=NULL; 
		return;
		}

	Node *temp= head; //Allocating a temporary head

	
	head=head->next; //Each time it recurses, goes on the next value


	if ((temp->val)<=pivot){  //if value is smaller or equal, adds onto the smaller list recursively
		smaller=temp; 
		llpivot(head,(smaller->next),larger, pivot); //Recurses with the pointer to the rest of the smaller list
	}
	else{//if value is larger, adds onto the larger list recursively
		larger=temp;
		llpivot(head,smaller,(larger->next), pivot); //Recurses with the pointer to the rest of the larger list
	}

	 head=NULL; //This is in order to return an empty head list as specified by the guides
	 //std::cout<<"Recursing now"<<std::endl;
}