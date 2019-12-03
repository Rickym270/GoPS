/*
 *  Author: Ricky Martinez
 *  Purpose: Build a DS for to work the future GPS to build
 *
 */

#include "../headers/GoPS_DS.h"

GoPS_Map::Node *GoPS_Map::search_NS_Node(Node *cur_location){
    Node *relaventNode = NULL;
    std::cout << "Looking for: " << (cur_location -> streetnum) + 1 << "st " \
              << cur_location -> avenuenum \
              << " North Street... ";

    // TODO: Loop through all the nodes in nodeVect
    for(int i = 0; i < nodeVect.size(); i++){
        // Condition:
        //      if streetnumproperty is equal to streetnum + 1 and avenue is the same, return the node
        if( nodeVect[i] -> streetnum == (cur_location -> streetnum) + 1 &&\
            nodeVect[i] -> avenuenum == cur_location -> avenuenum){
            std::cout << "Found!" << std::endl;
            relaventNode = nodeVect[i];
            break;
        }else{
            continue;
        }
    }
    return relaventNode;
}

GoPS_Map::Node *GoPS_Map::search_EA_Node(Node *cur_location){
    Node *relaventNode = NULL;
    std::cout << "Looking for: " << cur_location -> streetnum << "st " \
              << (cur_location -> avenuenum) - 1 \
              << " East Ave... ";

    // TODO: Loop through all the nodes in nodeVect
    for(int i = 0; i < nodeVect.size(); i++){
        // Condition:
        //      if streetnumproperty is equal to avenuenum - 1 and avenue is the same, return the node
        // std::cout << (cur_location -> avenuenum) - 1 << "St" << cur_location -> street
        if( nodeVect[i] -> avenuenum == (cur_location -> avenuenum) - 1 &&\
            nodeVect[i] -> streetnum == cur_location -> streetnum){
            std::cout << "Found!" << std::endl;
            relaventNode = nodeVect[i];
            break;
        }else{
            continue;
        }
    }
    return relaventNode;
}

GoPS_Map::Node *GoPS_Map::search_SS_Node(Node *cur_location){
    Node *relaventNode = NULL;
    std::cout << "Looking for: " << (cur_location -> streetnum) - 1 << "st " \
              << cur_location -> avenuenum \
              << " South Street... ";

    // Loop through all the nodes in nodeVect
    for(int i = 0; i < nodeVect.size(); i++){
        // Condition:
        //      if streetnum property is equal to streetnum + 1 and avenue is the same, return the node
        if( nodeVect[i] -> streetnum == (cur_location -> streetnum) - 1 &&\
            nodeVect[i] -> avenuenum == cur_location -> avenuenum){
            std::cout << "Found!" << std::endl;
            relaventNode = nodeVect[i];
            break;
        }else{
            continue;
        }
    }
    return relaventNode;
}

GoPS_Map::Node *GoPS_Map::search_WA_Node(Node *cur_location){
    Node *relaventNode = NULL;
    std::cout << "Looking for: " << cur_location -> streetnum << "st " \
              << (cur_location -> avenuenum) + 1\
              << " West Avenue... ";

    // TODO: Loop through all the nodes in nodeVect
    for(int i = 0; i < nodeVect.size(); i++){
        // Condition:
        //      if streetnumproperty is equal to avenue + 1 and avenue is the same, return the node
        if( nodeVect[i] -> avenuenum == (cur_location -> avenuenum) + 1 &&\
            nodeVect[i] -> streetnum == cur_location -> streetnum){
            std::cout << "Found!" << std::endl;
            relaventNode = nodeVect[i];
            break;
        }else{
            continue;
        }
    }
    return relaventNode;
}

GoPS_Map::Node *GoPS_Map::searchAllNodes(Node *cur_location){
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
    
void GoPS_Map::create_node(int streetnum, int avenuenum, bool auto_add ){
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
        Node *found_location = searchAllNodes(temp_location);
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

    GoPS_Map GoPSMap;
    GoPSMap.create_node(60, 10);   //North
    GoPSMap.create_node(59, 9);    //East
    GoPSMap.create_node(58, 10);   //South
    GoPSMap.create_node(59, 11);   //West

    GoPSMap.create_node(59, 10, auto_add = true);   //Origin


    return 0;
};

