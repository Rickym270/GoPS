/*
 *  Author: Ricky Martinez
 *  Class: CSCI 373 Professor Liu
 *
 */

#include <iostream>
#include <map>

struct Node{
    int streetnum;
    int avenuenum;

    Node *NStreet;
    Node *EAvenue;
    Node *SStreet;
    Node *WAvenue;
};

class street_list{
    private:
        Node *head, *north, *east, *south, *west;;
    public:
        street_list(){
            head = NULL;

            north = NULL;
            east = NULL;
            south = NULL;
            west = NULL;
        }
};

//Node *searchNode(Node *cur_location){
//
//
//}

void create_graph(int streetnum, int avenum){
    Node *temp_location = new Node;
    temp_location -> streetnum = streetnum;
    temp_location -> avenuenum = avenum;

    // North increments, south decrements
    temp_location -> NStreet = streetnum++;
    temp_location -> SStreet = streetnum--;

    // East decrements, West increments
    temp_location -> EStreet = streetnum--
    temp_location -> WStreet = streetnum++;

    if(head == NULL){
        head = temp_location;
        temp_location = NULL;
    }//else{
//        target_node = searchNode(Node *temp_location);
//    }
};

int main(){
    std::cout << "Hello World" << std::endl;

    return 0;
};

