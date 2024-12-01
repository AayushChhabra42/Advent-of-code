#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <queue>
using namespace std;


int main() {
    priority_queue<int,vector<int>,greater<int>> list1;
    priority_queue<int,vector<int>,greater<int>> list2;
    ifstream file1("input.txt");
    string line;
    string val1;
   while(getline(file1, line, '\n')) {
        stringstream ss(line);
        vector<string> vals;
        while(getline(ss,val1,' ')){
            if(val1 == ""){
                continue;
            }
            vals.push_back(val1);
        }
       list1.push(stoi(vals[0]));
       list2.push(stoi(vals[1]));
   }
   int total_distance=0;
    while(!list1.empty()){
        cout<<list1.top()<<" "<<list2.top()<<endl;
         total_distance += abs(list1.top()-list2.top());
         list1.pop();
         list2.pop();
    }
    cout << "Total distance is: " << total_distance << endl;
}  