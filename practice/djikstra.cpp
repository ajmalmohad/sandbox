#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

string lowestnode(unordered_map<string,int> &costs, unordered_map<string,bool> &processed);

int main(){

    //Finding Shortest Path from 'S' to 'F'

    unordered_map<string,unordered_map<string, int>> graph;
    graph["S"] = {make_pair("A", 5), make_pair("D", 2)};
    graph["A"] = {make_pair("B", 4),make_pair("C", 2)};
    graph["B"] = {make_pair("F", 3), make_pair("C", 6)};
    graph["C"] = {make_pair("F", 1)};
    graph["D"] = {make_pair("A", 8), make_pair("C", 7)};
    graph["F"] = {};

    unordered_map<string, int> costs;
    costs["A"] = 5;
    costs["D"] = 2;
    costs["B"] = INT_MAX;
    costs["C"] = INT_MAX;
    costs["F"] = INT_MAX;

    unordered_map<string, string> parents;
    parents["A"] = "S";
    parents["D"] = "S";
    parents["B"] = "None";
    parents["C"] = "None";
    parents["F"] = "None";

    unordered_map<string,bool> processed;

    string node = lowestnode(costs, processed);
    while(node != ""){
        int cost = costs[node];
        unordered_map<string, int> neighbours;
        neighbours = graph[node];
        for (auto neighbour : neighbours){
            int newcost = cost + neighbour.second;
            if(costs[neighbour.first] > newcost){
                costs[neighbour.first] = newcost;
                parents[neighbour.first] = node;
            }
        }
        processed[node] = true;
        node = lowestnode(costs, processed);
    }

    cout<<"Costs : ";
    for (auto cost : costs){
        cout<<"[ "<<cost.first<<":"<<cost.second<<" ] ";
    }
    
    //'F' is the final Destination
    string answer = "F";
    string child = "F";
    while(parents[child] != ""){
        answer += parents[child];
        child = parents[child];
    }

    cout<<"\nPath : ";
    for (int i=answer.size()-1; i>=0; i--){
        cout<<answer[i];
        if(i!= 0) cout<<" -> ";
    }

}

string lowestnode(unordered_map<string,int> &costs, unordered_map<string,bool> &processed){
    string minnode = "";
    int minvalue = INT_MAX;
    for (auto node : costs){
        if(processed[node.first]) continue;
        
        if(minvalue > node.second){
            minvalue = node.second;
            minnode = node.first;
        }
    }
    return minnode;
}