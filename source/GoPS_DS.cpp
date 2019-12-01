/*
 *  Author: Ricky Martinez
 *  Purpose: To build a working simple navigation system. Goal is to practice data structures, building, linking and
 *           working with thm
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

Node *search_NS_Node(Node *cur_location){
    // Find the street NORTH of cur_location. NORTH incrememnts.
    Node *relaventNode = NULL;
    std::cout << "Looking for: " << cur_location -> streetnum << "st " << cur_location -> avenuenum << std::endl;;

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
    std::cout << "Looking for: " << cur_location -> streetnum << "st " << cur_location -> avenuenum << std::endl;;

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
    std::cout << "Looking for: " << cur_location -> streetnum << "st " << cur_location -> avenuenum << std::endl;;

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
    std::cout << "Looking for: " << cur_location -> streetnum << "st " << cur_location -> avenuenum << std::endl;;

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
    Node *relaventNode = NULL;
    std::cout << "Looking for: " << cur_location -> streetnum << "st " \
              << cur_location -> avenuenum << std::endl;;

    try{
        NSNode = search_NS_Node(cur_location);
        EANode = search_EA_Node(cur_location);
        SSNode = search_SS_Node(cur_location);
        WANode = search_WA_Node(cur_location);
    }catch(StreetNotFound snf){
        std::cout << "Exception raised:\n\
                      One or more streets/avenues couldn't be found. \
                      Check that they all exist." << std::endl;
    }
    
    // If no link can be adequately established, throw StreetNotFound Exception.
    if( NSNode && EANode && SSNode && WANode ){
            cur_location ->
        return relaventNode;
    }else{
        throw StreetNotFound( std::cout << " Exception raise:\n 
                                             One or more streets/avenues couldn't be found. \
                                             Check that they all exist." std::endl;);
}

void create_node(int streetnum, int avenuenum, bool auto_add = false;){
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
        Node *found_location = searchAllNode(temp_location, location = "NS");
        // Create an iterator
        it = std::find(nodeVect.begin(), nodeVect.end(), found_location);
        // Check if nodeVect contains found_location
        if ( it != nodeVect.end() ) {
            std::cout << "Found NS location! Linking...";
            temp_location -> NStreet = found_location; 
            //std::cout << found_location -> streetnum << std::endl;
            //std::cout << found_location -> avenuenum << std::endl;
            std::cout << "Done." << std::endl;
        }
    }
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
    create_node(59, 10, auto_add = true);   //Origin

    create_node(60, 10);   //North
    create_node(59, 9);    //East
    create_node(58, 10);   //South
    create_node(59, 11);   //West

    return 0;
};

