#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    // Min heap to prioritize tasks based on execution priority (lower = higher priority)
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> taskQueue;

    taskQueue.push({3, "Render Frame"});
    taskQueue.push({1, "Parse HTML"});
    taskQueue.push({2, "Load CSS"});
    taskQueue.push({5, "Execute JavaScript"});
    taskQueue.push({4, "Load Images"});

    while (!taskQueue.empty()) {
        auto [priority, task] = taskQueue.top();
        taskQueue.pop();
        cout << "Executing Task: " << task << " with priority " << priority << endl;
    }

    return 0;
}
