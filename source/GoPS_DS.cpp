/*
 *  Author: Ricky Martinez
 *  Class: CSCI 373 Professor Liu
 *
 */

#include <iostream>
#include <map>
#include <vector>

struct Node{
    int streetnum;
    int avenuenum;

    Node *NStreet;
    Node *EAvenue;
    Node *SStreet;
    Node *WAvenue;
};

// Define array of node pointers
std::vector < Node *> nodeVect;

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

Node *searchNode(Node *cur_location){
    Node *relaventNode = NULL;
    for(int i = 0; i < nodeVect.size(); i++){
            if( nodeVect[i] -> streetnum == cur_location -> streetnum && \
                nodeVect[i] -> avenuenum == cur_location -> avenuenum){
                relaventNode = nodeVect[i];
            }else{
                continue;
            }

    }
    return relaventNode;
}

void create_graph(int streetnum, int avenuenum){
    Node *temp_location = new Node;
    temp_location -> streetnum = streetnum;
    temp_location -> avenuenum = avenuenum;

    // Add to vector of Node pointers
    nodeVect.push_back(temp_location);
    Node *found_location = searchNode(temp_location);

    // North increments, south decrements
    // found_location -> NStreet = streetnum+++ ;
    // found_location -> SStreet = streetnum--;

    // East decrements, West increments
    //temp_location -> EAvenue = avenuenum--;
    //temp_location -> WAvenue = avenuenum++;

    //if(head == NULL){
    //    head = temp_location;
    //    temp_location = NULL;
    //}else{
//        target_node = searchNode(Node *temp_location);
//    }
};

int main(){
    std::cout << "Hello World" << std::endl;
    create_graph(59, 10);   //Origin

    create_graph(60, 10);   //North
    create_graph(59, 9);    //East
    create_graph(58, 10);   //South
    create_graph(59, 11);   //West

    return 0;
};

