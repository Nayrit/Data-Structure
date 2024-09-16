#include <bits/stdc++.h>
using namespace std;
void findAllLCS(string str1, string str2, int m, int n, vector<vector<int>>& dp, string current, set<string>& result) {
    if (m == 0 || n == 0) {
        reverse(current.begin(), current.end());
        result.insert(current);
        return;
    }

    if (str1[m - 1] == str2[n - 1]) {
        findAllLCS(str1, str2, m - 1, n - 1, dp, str1[m - 1] + current, result);
    } else {
        if (dp[m - 1][n] >= dp[m][n - 1]) {
            findAllLCS(str1, str2, m - 1, n, dp, current, result);
        }

        if (dp[m][n - 1] >= dp[m - 1][n]) {
            findAllLCS(str1, str2, m, n - 1, dp, current, result);
        }
    }
}

vector<string> LCS(string str1, string str2) {
    int m = str1.length();
    int n = str2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    set<string> result;
    findAllLCS(str1, str2, m, n, dp, "", result);

    return vector<string>(result.begin(), result.end());
}

int main() {
    string str1, str2;
    cout << "Enter the first string: ";
    cin >> str1;
    cout << "Enter the second string: ";
    cin >> str2;

    vector<string> lcsList = LCS(str1, str2);

    if (lcsList.empty()) {
        cout << "No Longest Common Subsequence found." << endl;
    } else {
        cout << "All Unique Longest Common Subsequences: " << endl;
        for (const string& lcs : lcsList) {
            cout << lcs << endl;
        }
    }

    return 0;
}
