#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>

using namespace std;

class Task {
public:
    string name;
    vector<string> dependencies;

    Task(const string& name, const vector<string>& dependencies)
        : name(name), dependencies(dependencies) {}
};

class Workflow {
public:
    void addTask(const string& name, const vector<string>& dependencies) {
        tasks[name] = Task(name, dependencies);
    }

    void run() {
        unordered_map<string, int> indegree;
        for (const auto& pair : tasks) {
            indegree[pair.first] = 0;
        }
        for (const auto& pair : tasks) {
            for (const auto& dep : pair.second.dependencies) {
                indegree[dep]++;
            }
        }

        queue<string> q;
        for (const auto& pair : indegree) {
            if (pair.second == 0) {
                q.push(pair.first);
            }
        }

        while (!q.empty()) {
            string current = q.front();
            q.pop();
            cout << "Running task: " << current << endl;
            for (const auto& dep : tasks[current].dependencies) {
                if (--indegree[dep] == 0) {
                    q.push(dep);
                }
            }
        }
    }

private:
    unordered_map<string, Task> tasks;
};

int main() {
    Workflow workflow;
    workflow.addTask("Build", {});
    workflow.addTask("Test", {"Build"});
    workflow.addTask("Deploy", {"Test"});

    workflow.run();
    return 0;
}
