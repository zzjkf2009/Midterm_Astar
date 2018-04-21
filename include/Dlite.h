/**
 * @Author: Zejiang Zeng <zzj>
 * @Date:   2018-03-27T10:19:23-04:00
 * @Email:  zzeng@terpmail.umd.edu
 * @Filename: Dlite.h
 * @Last modified by:  zzj
 * @Last modified time: 2018-03-27T10:19:56-04:00
 * @Copyright: (C) 2017 Zejiang Zeng - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the BSD license.
 */


 #ifndef DLITE_H
 #define DLITE_H


 #include <math.h>
 #include <stack>
 #include <queue>
 #include <list>
 #include <ext/hash_map>
 #include <tr1/unordered_map>

/**
 * [Create a state class that contains the x, y, and key value as state info]
 */
class state {
public:
int x;
int y;
std::pair<double,double> k;

bool operator == (const state &s2) const {
        return ((x == s2.x) && (y == s2.y));
}

bool operator != (const state &s2) const {
        return ((x != s2.x) || (y != s2.y));
}

bool operator > (const state &s2) const {
        if (k.first-0.00001 > s2.k.first) return true;
        else if (k.first < s2.k.first-0.00001) return false;
        return k.second > s2.k.second;
}

bool operator <= (const state &s2) const {
        if (k.first < s2.k.first) return true;
        else if (k.first > s2.k.first) return false;
        return k.second < s2.k.second + 0.00001;
}


bool operator < (const state &s2) const {
        if (k.first + 0.000001 < s2.k.first) return true;
        else if (k.first - 0.000001 > s2.k.first) return false;
        return k.second < s2.k.second;
}
};


struct cellInfo {
        double g;
        double rhs;
        double cost;

};

class state_hash {
public:
size_t operator()(const state &s) const {
        return s.x + 34245*s.y;
}
};

typedef std::priority_queue<state, std::vector<state>, std::greater<state> > priority_queue;
typedef std::tr1::unordered_map<state, cellInfo, state_hash, std::equal_to<state> > unordered_cell;
typedef std::tr1::unordered_map<state, float, state_hash, std::equal_to<state> > unordered_float;


class DstarLite {
public:
/**
 * [DstarLite Constructor of the class,inicite the D*lite search and set parameters]
 * @param startX [int]
 * @param startY [int]
 * @param goalX  [int]
 * @param goalY  [int]
 */
DstarLite(int startX, int startY, int goalX, int goalY);

priority_queue openList;
unordered_cell cellHash;
unordered_float openHash;
private:
double heuristic(state a, state b);
state calculateKey(state u);
double getRHS(state u);
double getG(state u);
int computeShortestPath();
void insert(state u);
float keyHashCode(state u);
void setG(state u, double g);
};

#endif
