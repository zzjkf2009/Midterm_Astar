
#include <pair>
#include <vector>
#include <queue>
#include <tr1/unordered_map>
#include "BuildingMap.h"

class Node {
int x;
int y;
int index;
double g;
double rhs;
double min_cost_succ;
std::pair<double,double> k;
int parent_index;
bool operator == (const Node &s2) const {
        return ((x == s2.x) && (y == s2.y));
}

bool operator != (const Node &s2) const {
        return ((x != s2.x) || (y != s2.y));
}

bool operator > (const Node &s2) const {
        if (k.first-0.00001 > s2.k.first) return true;
        else if (k.first < s2.k.first-0.00001) return false;
        return k.second > s2.k.second;
}

bool operator <= (const Node &s2) const {
        if (k.first < s2.k.first) return true;
        else if (k.first > s2.k.first) return false;
        return k.second < s2.k.second + 0.00001;
}


bool operator < (const Node &s2) const {
        if (k.first + 0.000001 < s2.k.first) return true;
        else if (k.first - 0.000001 > s2.k.first) return false;
        return k.second < s2.k.second;
}
};

class DstarLite {
// Constructor
DstarLite(Buildingmap::gridMatrix gridmap,ROW,COL,int start_x,int start_y,int goal_x,int goal_y);
std::vector<int> map_info;
Node start_node;
Node goal_node;
Node last_node;

private:
double km = 0;
std::priority_queue<Node,std::vector<Node>,greater<Node> > open_list;
std::tr1::unordered_map<int, Node > open_hash;
std::tr1::unordered_map<int, NOde > node_map;

std::vector<Node> successor_node_list(Node currentnode);
std::vector<Node> predecessor_node_list(Node currentnode);
double cost_between_nodes(Node a, Node b);
double heuristic(Node a, Node b);
std::vector<int> computeShortestPath();
Node Find_min_Node(const std::vector<Node>& successor_nodes)

void calculateKey(Node currentnode);
void calculateIndex(Node currentnode);
void updateVertex(Node currentnode);
};
