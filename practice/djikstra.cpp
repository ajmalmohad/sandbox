#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

string lowestnode(unordered_map<string,int> &costs, vector<string> &processed);

int main(){

    unordered_map<string,unordered_map<string, int>> graph;
    graph["S"] = {make_pair("A", 6), make_pair("B", 2)};
    graph["A"] = {make_pair("F", 1)};
    graph["B"] = {make_pair("A", 3), make_pair("F", 5)};
    graph["F"] = {};

    unordered_map<string, int> costs;
    costs["A"] = 6;
    costs["B"] = 2;
    costs["F"] = INT_MAX;

    unordered_map<string, string> parents;
    parents["A"] = "S";
    parents["B"] = "S";
    parents["F"] = "None";

    vector<string> processed;
    processed.reserve(4);

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
        processed.push_back(node);
        node = lowestnode(costs, processed);
    }


    for (auto cost : costs){
        cout<<cost.first<<" : "<<cost.second<<"\n";
    }
    
    string answer = "F";
    string child = "F";
    while(parents[child] != ""){
        answer += parents[child];
        child = parents[child];
    }

    cout<<"Path : ";
    for (int i=answer.size()-1; i>=0; i--){
        cout<<answer[i];
        if(i!= 0) cout<<" -> ";
    }

}

string lowestnode(unordered_map<string,int> &costs, vector<string> &processed){
    string minnode = "";
    int minvalue = INT_MAX;
    for (auto node : costs){
        int flag = 0;
        for (auto visited : processed){
            if(node.first == visited){
                flag = 1;
                break;
            }
        }
        if(flag) continue;
        if(minvalue > node.second){
            minvalue = node.second;
            minnode = node.first;
        }
    }
    return minnode;
}