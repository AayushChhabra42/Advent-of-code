#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

bool is_safe(const vector<int>& report) {
    int rep_size = report.size();
    if (rep_size <= 1) return true; 
    bool decreasing = report[0] > report[1]; 
    for (int i = 1; i < rep_size; i++) {
        int diff = report[i] - report[i - 1];

        if (abs(diff) < 1 || abs(diff) > 3) {
            return false;
        }

        if ((decreasing && diff > 0) || (!decreasing && diff < 0)) {
            return false;
        }
    }
    return true;
}

// function to check if removing a single level makes the report safe
bool is_safe_with_dampener(const vector<int>& report) {
    int rep_size = report.size();
    if (rep_size <= 1) return true; 

    for (int i = 0; i < rep_size; i++) {
        vector<int> modified_report;
        for (int j = 0; j < rep_size; j++) {
            if (j != i) modified_report.push_back(report[j]);
        }
        if (is_safe(modified_report)) return true;
    }
    return false;
}

int main() {
    vector<vector<int>> list1;
    ifstream file1("input.txt");

    if (!file1) {
        cerr << "Error: Unable to open file tc.txt" << endl;
        return 1;
    }

    string line;
    while (getline(file1, line)) {
        stringstream ss(line);
        vector<int> temp;
        string val;
        while (ss >> val) {
            temp.push_back(stoi(val));
        }
        list1.push_back(temp);
    }

    int no_of_safe_reports = 0;

    for (const auto& report : list1) {
        if (is_safe(report) || is_safe_with_dampener(report)) {
            no_of_safe_reports++;
        }
    }

    cout << "safe " << no_of_safe_reports << endl;

    return 0;
}
