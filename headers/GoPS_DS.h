#include <iostream>
#include <map>
#include <vector>

class GoPS_Map{
    private:
        struct Node{
            int streetnum;
            int avenuenum;

            Node *NStreet;
            Node *EAvenue;
            Node *SStreet;
            Node *WAvenue;
        };

    public:
        // Find the street NORTH of cur_location
        // NOTE: North streets increments
        GoPS_Map::Node *search_NS_Node( GoPS_Map::Node *cur_location );

        // Find the street EAST of cur_location
        // NOTE: East Avenues decrements
        GoPS_Map::Node *search_EA_Node( GoPS_Map::Node *cur_location );
        
        // Find the street SOUTH of cur_location
        // NOTE: South streets decrements
        GoPS_Map::Node *search_SS_Node( GoPS_Map::Node *cur_location );
        
        // Find the street WEST of cur_location
        // NOTE: West Avenues decrements
        GoPS_Map::Node *search_WA_Node( GoPS_Map::Node *cur_location );

        // Call the above functions to search all relavent nodes.
        GoPS_Map::Node *searchAllNodes( GoPS_Map::Node *cur_location );

        // Create a node. If auto_add is true, searchAllNodes is called.
        void create_node(int streetnum, int avenuenum, bool auto_add = false);

        // All nodes are saved into this vector for later search.
        std::vector < GoPS_Map::Node * > nodeVect;
    };
