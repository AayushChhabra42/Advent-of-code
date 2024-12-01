#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
using namespace std;

int main(){
    vector<int> list1;
    unordered_map<int,int> list2;
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
       list1.push_back(stoi(vals[0]));
       ++list2[stoi(vals[1])];
   }
    int similarity_score=0;
    for(int i=0;i<list1.size();i++){
        similarity_score += list1[i]*list2[list1[i]];
    }
    cout << "Similarity score is: " << similarity_score << endl;
}