#include <bits/stdc++.h>
#include <iostream>
#include <climits>
using namespace std;

int calcMaxPathSum(vector<int>& v, int i, int len, int& maxSum) {
    if (i >= len || v[i] == -1)
        return 0;

    int lc = 2 * i + 1;
    int rc = 2 * i + 2;

    int leftSum = max(0, calcMaxPathSum(v, lc, len, maxSum));
    int rightSum = max(0, calcMaxPathSum(v, rc, len, maxSum));

    maxSum = max(maxSum, leftSum + rightSum + v[i]);

    return v[i] + max(leftSum, rightSum);
}

int maxPathSum(vector<int>& tree) {
    int maxSum = INT_MIN;
    int len = tree.size();
    calcMaxPathSum(tree, 0, len, maxSum);

    return maxSum;
}

int main() {
    vector<int> v;
    string t;
    int len = 0;
    int node;
    cout << "Enter values: ";
    
    getline(cin, t);
    istringstream iss(t);
    while (iss >> t) {
        if(t=="-1") node = INT_MIN;
        else node = stoi(t);
        v.push_back(node);
        len++;
    }
    for(int i = 0; i<len; i++) cout<<v[i]<<" ";
    // cout << maxPathSum(v);
    return 0;
}
