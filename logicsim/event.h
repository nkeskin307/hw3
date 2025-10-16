#ifndef EVENT_H
#define EVENT_H
#include "wire.h"

struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};

typedef struct EventLess {
        //write the operator() required to make this a functor that compares Events by time
			bool operator()(const Event *ev1, const Event *ev2) const{

				//First let's handle the nullptr cases
				if ((ev1==nullptr) || (ev1->time==ev2->time)){
					//If ev1 is a nullptr, ev2 should come before it so our operator small will return false
					//If ev1 and ev2 are equal, it essentially does not matter
					return false;
				}
				else if(ev2==nullptr){ 
					//If the first event is not a nullptr and the second is, this means that ev1 should come before ev2, so this fulfills our heap property
					return true; 
				}

				//This will return true if the first event is shorter than the second
				if (ev1->time < ev2->time){
					return true;
				}
				else{
					return false; //Else it will return false
				}
			}
				
} EventLess;
	

	
#endif
