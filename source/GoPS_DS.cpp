/*
 *  Author: Ricky Martinez
 *  Class: CSCI 373 Professor Liu
 *
 */

#include <iostream>
#include <map>
#include <vector>
#include "../headers/GoPS_DS.h"

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

Node *search_NS_Node(Node *cur_location){
    // Find the street NORTH of cur_location. NORTH incrememnts.
    Node *relaventNode = NULL;
    std::cout << "Looking for: " << cur_location -> streetnum << "st " \
              << cur_location -> avenuenum \
                      << " North Street" << std::endl;

    // TODO: Loop through all the nodes in nodeVect
    for(int i = 0; i < nodeVect.size(); i++){
        // Condition:
        //      if streetnumproperty is equal to streetnum + 1 and avenue is the same, return the node
        if( nodeVect[i] -> streetnum == (cur_location -> streetnum) + 1 &&\
            nodeVect[i] -> avenuenum == cur_location -> avenuenum){
            relaventNode = nodeVect[i];
            break;
        }else{
            continue;
        }
    }
    return relaventNode;
}

Node *search_EA_Node(Node *cur_location){
    // Find the street EAST of cur_location, EAST decrements
    Node *relaventNode = NULL;
    std::cout << "Looking for: " << cur_location -> streetnum << "st " \
              << cur_location -> avenuenum \
              << " East Ave" << std::endl;

    // TODO: Loop through all the nodes in nodeVect
    for(int i = 0; i < nodeVect.size(); i++){
        // Condition:
        //      if streetnumproperty is equal to avenuenum - 1 and avenue is the same, return the node
        if( nodeVect[i] -> streetnum == (cur_location -> avenuenum) - 1 &&\
            nodeVect[i] -> avenuenum == cur_location -> streetnum){
            relaventNode = nodeVect[i];
            break;
        }else{
            continue;
        }
    }
    return relaventNode;
}

Node *search_SS_Node(Node *cur_location){
    // Find the street SOUTH of cur_location, SOUTH increments
    Node *relaventNode = NULL;
    std::cout << "Looking for: " << cur_location -> streetnum << "st " \
              << cur_location -> avenuenum \
              << " South Street" << std::endl;

    // TODO: Loop through all the nodes in nodeVect
    for(int i = 0; i < nodeVect.size(); i++){
        // Condition:
        //      if streetnum property is equal to streetnum + 1 and avenue is the same, return the node
        if( nodeVect[i] -> streetnum == (cur_location -> streetnum) - 1 &&\
            nodeVect[i] -> avenuenum == cur_location -> avenuenum){
            relaventNode = nodeVect[i];
            break;
        }else{
            continue;
        }
    }
    return relaventNode;
}

Node *search_WA_Node(Node *cur_location){
    // Find the Avenue WEST of cur_location, WEST increments
    Node *relaventNode = NULL;
    std::cout << "Looking for: " << cur_location -> streetnum << "st " \
              << cur_location -> avenuenum \
              << " West Avenue" << std::endl;;

    // TODO: Loop through all the nodes in nodeVect
    for(int i = 0; i < nodeVect.size(); i++){
        // Condition:
        //      if streetnumproperty is equal to avenue + 1 and avenue is the same, return the node
        if( nodeVect[i] -> streetnum == (cur_location -> avenuenum) + 1 &&\
            nodeVect[i] -> avenuenum == cur_location -> streetnum){
            relaventNode = nodeVect[i];
            break;
        }else{
            continue;
        }
    }
    return relaventNode;
}

Node *searchAllNode(Node *cur_location){
    std::cout << "Looking for: " << cur_location -> streetnum << "st " \
              << cur_location -> avenuenum << std::endl;;
    Node *NSNode, *EANode, *SSNode, *WANode;
    std::string err = "";
    try{
        NSNode = search_NS_Node(cur_location);
        EANode = search_EA_Node(cur_location);
        SSNode = search_SS_Node(cur_location);
        WANode = search_WA_Node(cur_location);

        if( !NSNode){
            throw "NSNode";
        }if(!EANode){
            throw "EANode";
        }if(!SSNode){
            throw "SSNode";
        }if(!WANode){
            throw "WANode";
        }
    }catch(const char *x){
        std::cout << "\n\nException raised:" << std::endl;
        std::cout << x << " couldn't be found. Check that it exists for: \n" \
                              + std::to_string(cur_location -> streetnum) + "st "\
                              + std::to_string(cur_location -> avenuenum) + "ave "\
                              + "\n\n" << std::endl;;

    }
    
    // If no link can be adequately established, throw StreetNotFound Exception.
    if( NSNode && EANode && SSNode && WANode ){
        cur_location -> NStreet = NSNode;
        cur_location -> EAvenue = EANode;
        cur_location -> SStreet = SSNode;
        cur_location -> WAvenue = WANode;
    }
    
    return cur_location;
};
    
void create_node(int streetnum, int avenuenum, bool auto_add = false){
    Node *temp_location = new Node;
    // Iterator used to store the position  
    // of searched element 
    std::vector< Node* >::iterator it; 
    
    temp_location -> streetnum = streetnum;
    temp_location -> avenuenum = avenuenum;

    // Add to vector of Node pointers
    nodeVect.push_back(temp_location);
    //Node *found_location = searchNode(temp_location);

    if( auto_add ) {
        // Search for all relavent streets/avcenues of a node
        Node *found_location = searchAllNode(temp_location);
        // Create an iterator
        it = std::find(nodeVect.begin(), nodeVect.end(), found_location);
        // Check if nodeVect contains found_location
        if ( it != nodeVect.end() ) {
            std::cout << "Found all locations for " << temp_location-> streetnum << "st "\
                                                    << temp_location -> avenuenum << "ave"\
            << std::endl;
            std::cout << "Done." << std::endl;
        }
    }
};

int main(){
    std::cout << "Running GoPS_DS.cpp" << std::endl;
    bool auto_add;
    create_node(59, 10, auto_add = true);   //Origin

    create_node(60, 10);   //North
    create_node(59, 9);    //East
    create_node(58, 10);   //South
    create_node(59, 11);   //West

    return 0;
};

