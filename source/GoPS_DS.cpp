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

Node *searchNode(Node *cur_location){
    Node *relaventNode = NULL;
    std::cout << "Looking for: " << cur_location -> streetnum << "st " << cur_location -> avenuenum << std::endl;;

    for(int i = 0; i < nodeVect.size(); i++){
        //std::cout << "i: " << i << "  " << nodeVect[i] << std::endl;
        if( nodeVect[i] -> streetnum == cur_location -> streetnum && \
            nodeVect[i] -> avenuenum == cur_location -> avenuenum){
            
            break;
        }else{
            continue;
        }
    }
    return relaventNode;
}

Node *search_NS_Node(Node *cur_location){
    // Find the street north of cur_location
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
void create_graph(int streetnum, int avenuenum){
    Node *temp_location = new Node;
    // Iterator used to store the position  
    // of searched element 
    std::vector< Node* >::iterator it; 
    
    temp_location -> streetnum = streetnum;
    temp_location -> avenuenum = avenuenum;

    // Add to vector of Node pointers
    nodeVect.push_back(temp_location);
    //Node *found_location = searchNode(temp_location);

    // Search for NS node
    Node *found_location = search_NS_Node(temp_location);
    it = std::find(nodeVect.begin(), nodeVect.end(), found_location);
    // Check if node belongs to nodeVect
    if ( it != nodeVect.end() ) {
        std::cout << "Found location!" << std::endl;
        std::cout << found_location -> streetnum << std::endl;
        std::cout << found_location -> avenuenum << std::endl;
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
    create_graph(59, 10);   //Origin

    create_graph(60, 10);   //North
    create_graph(59, 9);    //East
    create_graph(58, 10);   //South
    create_graph(59, 11);   //West

    return 0;
};

