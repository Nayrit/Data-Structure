#include <bits/stdc++.h>
using namespace std;

struct Activity {
    int id;
    int start;
    int finish;
    string name;
};

bool compareActivities(const Activity& a, const Activity& b) {
    return a.finish < b.finish;
}

bool compareSolutions(const vector<Activity>& a, const vector<Activity>& b) {
    int totalDurationA = 0, totalDurationB = 0;
    for (const Activity& activity : a) {
        totalDurationA += activity.finish - activity.start;
    }
    for (const Activity& activity : b) {
        totalDurationB += activity.finish - activity.start;
    }
    
    if (totalDurationA != totalDurationB) {
        return totalDurationA < totalDurationB;
    } else {
        return a[0].start < b[0].start;
    }
}

int main() {
    int n;
    cout << "Enter the number of activities: ";
    cin >> n;

    vector<Activity> activities(n);

    cout << "Enter start and finish times for each activity: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> activities[i].start >> activities[i].finish;
        activities[i].name = "a" + to_string(i + 1);
    }

    sort(activities.begin(), activities.end(), compareActivities);

    vector<vector<Activity>> solutions;
    vector<Activity> selectedActivities;

    function<void(int)> findMaxActivities = [&](int index) {
        if (index >= n) {
            solutions.push_back(selectedActivities);
            return;
        }

        // Exclude current activity
        findMaxActivities(index + 1);

        // Include current activity if it doesn't conflict
        if (selectedActivities.empty() || activities[index].start >= selectedActivities.back().finish) {
            selectedActivities.push_back(activities[index]);
            findMaxActivities(index + 1);
            selectedActivities.pop_back();
        }
    };

    findMaxActivities(0);

    sort(solutions.begin(), solutions.end(), compareSolutions);

    for (const auto& solution : solutions) {
        for (const Activity& activity : solution) {
            cout << activity.name << " ";
        }
        cout << endl;
    }

    return 0;
}
/*
2 4
1 4
0 6
5 7
3 9
5 9
6 10
8 11
8 12
2 14
12 16

*/