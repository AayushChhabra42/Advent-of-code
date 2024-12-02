#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <queue>
using namespace std;

int main()
{
    vector<vector<int>> list1;
    int no_of_safe_rep = 0;
    ifstream file1("input.txt");
    string line;
    string val1;
    while (getline(file1, line, '\n'))
    {
        stringstream ss(line);
        vector<int> temp;
        while (getline(ss, val1, ' '))
        {
            if (val1 == "")
            {
                continue;
            }
            temp.push_back(stoi(val1));
        }
        list1.push_back(temp);
    }
    for (const auto &it : list1) {
        int rep_size = it.size();
        if (rep_size <= 1) {
            no_of_safe_rep++;
            continue;
        }
        bool is_safe = true;
        bool decreasing = it[0] > it[1]; 

        for (int i = 1; i < rep_size; i++) {
            int diff = it[i] - it[i - 1];
            if (abs(diff) < 1 || abs(diff) > 3) {
                is_safe = false;
                break;
            }
            if ((decreasing && diff > 0) || (!decreasing && diff < 0)) {
                is_safe = false;
                break;
            }
        }

        if (is_safe) {
            no_of_safe_rep++; 
        }
    }
  cout << "safe:" << no_of_safe_rep << endl;
}