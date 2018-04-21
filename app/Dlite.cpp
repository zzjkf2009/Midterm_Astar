/**
 * @Author: Zejiang Zeng <zzj>
 * @Date:   2018-03-27T09:48:02-04:00
 * @Email:  zzeng@terpmail.umd.edu
 * @Filename: DstarLite.cpp
 * @Last modified by:   zzj
 * @Last modified time: 2018-03-27T10:33:43-04:00
 * @Copyright: (C) 2017 Zejiang Zeng - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the BSD license.
 */

#include "DLite.h"
#include <stdio.h>
#include <math.h>
/**
 * [class constructor]
 */
DstarLite::DstarLite(int startX, int startY, int goalX, int goalY) {
        init(startX,startY,goalX,goalY);
        maxSteps = 80000; // node expansions before we give up
        C1       = 1; // cost of an unseen cell
}
/**
 * [DstarLite::init Initialize the search by giving the start and goal node]
 * @param sX [int]
 * @param sY [int]
 * @param gX [int]
 * @param gY [int]
 */
void DstarLite::init(int sX, int sY, int gX, int gY) {

// Make sure the hash table, openlist(priority_queue) and path are empty
        cellHash.clear();
        path.clear();
        openHash.clear();
        while(!openList.empty()) openList.pop();
// Initialize km is zero, k_m = h(s,s') as current state moves
        k_m = 0;
// Assign start and goal node
        s_start.x = sX;
        s_start.y = sY;
        s_goal.x  = gX;
        s_goal.y  = gY;

        cellInfo tmp;
        //  tmp.g = tmp.rhs =  0;
        tmp.rhs =  0;
        tmp.cost = C1;

        cellHash[s_goal] = tmp;

        //tmp.g = tmp.rhs = heuristic(s_start, s_goal);
        //  tmp.cost = C1;
        //  cellHash[s_start] = tmp;
        //  s_start = calculateKey(s_start);
        s_goal = calculateKey(s_goal);
        openList.push(s_goal);
        s_last = s_start;
}
/**
 * [DstarLite::heuristic return the estimated heiristic value]
 * @param  a [state]
 * @param  b [state]
 * @return   [double]
 */
double DstarLite::heuristic(state a, state b) {
        return std::sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

/**
 * [DstarLite::calculateKey assign the key value of the state]
 * @param  u [state]
 * @return   [state]
 */
state DstarLite::calculateKey(state u) {

        double val = fmin(getRHS(u),getG(u));

        u.k.first  = val + heuristic(u,s_start) + k_m;
        u.k.second = val;
        return u;
}
/**
 * [DstarLite::getRHS get the rhs value]
 * @param  u [state]
 * @return   [double]
 */
double DstarLite::getRHS(state u) {

        if (u == s_goal) return 0;

        if (cellHash.find(u) == cellHash.end())
                //        return heuristic(u,s_goal);
                return heuristic(u,s_start);
        return cellHash[u].rhs;
}
/**
 * [DstarLite::getG get the g value of the state]
 * @param  u [state]
 * @return   [double]
 */
double DstarLite::getG(state u) {

        if (cellHash.find(u) == cellHash.end())
                //return heuristic(u,s_start);
                return heuristic(u,s_goal);
        return cellHash[u].g;

}
/**
 * [DstarLite::computeShortestPath find the shortest path based on the current
 * state]
 * @return [int]
 */
int DstarLite::computeShortestPath() {

        list<state> s;
        list<state>::iterator i;

        if (openList.empty()) {
                printf("openlist is empyt\n");
                return -1;
        }

        int steps = 0;  // record the steps until it reaches the maxSteps
        while ((!openList.empty()) ||
               (openList.top() < (s_start = calculateKey(s_start))) ||
               (getRHS(s_start) != getG(s_start))) {

                if (steps++ > maxSteps) {
                        fprintf(stderr, "At maxsteps\n");
                        return -1;
                }

                state u = openList.top();
                openList.pop();
/**
                bool test = (getRHS(s_start) != getG(s_start));

                // lazy remove
                while(1) {
                        if (openList.empty()) return 1;
                        u = openList.top();
                        openList.pop();

                        if (!isValid(u)) continue;
                        if (!(u < s_start) && (!test)) return 2;
                        break;
                }

                ds_oh::iterator cur = openHash.find(u);
                openHash.erase(cur);
 **/
                state k_old = u;



                if (k_old < calculateKey(u)) { // u is out of date
                        insert(u);
                } else if (getG(u) > getRHS(u)) { // needs update (got better)
                        setG(u,getRHS(u));
                        getPred(u,s);
                        for (i=s.begin(); i != s.end(); i++) {
                                updateVertex(*i);
                        }
                } else { // g <= rhs, state has got worse
                        setG(u,INFINITY);
                        getPred(u,s);
                        for (i=s.begin(); i != s.end(); i++) {
                                updateVertex(*i);
                        }
                        updateVertex(u);
                }
        }
        return 0;
}

void DstarLite::insert(state u) {
        unordered_float::iterator cur;
        u    = calculateKey(u);
        cur  = openHash.find(u);
        float csum = keyHashCode(u);
        openHash[u] = csum;
        openList.push(u);
}

/**
 * [DstarLite::keyHashCode Returns the key hash code for the state u, this is used
 * to compare, state that have been updated, based on the x and y value]
 * @param  u [state]
 * @return   [float]
 */
float DstarLite::keyHashCode(state u) {

        return (float)(u.k.first + 1193*u.k.second);

}
/**
 * [DstarLite::setG set g value for a state]
 * @param u [state]
 * @param g [double]
 */
void DstarLite::setG(state u, double g) {
        makeNewCell(u);
        cellHash[u].g = g;
}
