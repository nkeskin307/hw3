#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------

bool isEven(int num);

bool isEven(int num){
	if (num%2==0){
		return true;
	}
	else{
		return false;
	}

}


int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
    Node* head_pivot = readList(argv[1]);
    cout << "Original list: ";
    print(head_pivot);

    // Test out your linked list code
		//Let's test the pivot function:

		Node* larger=nullptr;
		Node* smaller=nullptr;

		int pivot =9;

		cout<<"Now testing the pivot function with using the provided input file and pivot: "<<pivot<<endl;
		llpivot (head_pivot, smaller, larger, pivot);

		cout<<"These are the smaller or equal to values: "<<endl;
		print(smaller);

		cout<<"These are the larger values: "<<endl;
		print(larger);


    dealloc(smaller);
		dealloc(larger);

		Node* head_filter = readList(argv[1]);
    cout << "Original list: ";
    print(head_filter);

		cout<<"Now testing the filter function with using the provided input file and the predicate function: "<<endl;
		Node* filtered= llfilter(head_filter, isEven);
		print(filtered);

		dealloc(filtered);





    return 0;

}
