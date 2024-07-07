#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm> // for std::find
using namespace std;
class Issue {
public:
    int id;
    string title;
    vector<string> labels;

    Issue(int id, const string& title) : id(id), title(title) {}
};

class Repository {
public:
    void createIssue(int id, const string& title) {
        issues[id] = Issue(id, title);
    }

    void addLabel(int id, const string& label) {
        if (issues.find(id) != issues.end()) {
            issues[id].labels.push_back(label);
        }
    }

    void printIssuesWithLabel(const string& label) {
        for (const auto& pair : issues) {
            const Issue& issue = pair.second;
            if (find(issue.labels.begin(), issue.labels.end(), label) != issue.labels.end()) {
                cout << "Issue ID: " << issue.id << ", Title: " << issue.title << endl;
            }
        }
    }

private:
    unordered_map<int, Issue> issues;
};

int main() {
    Repository repo;
    repo.createIssue(1, "First issue");
    repo.createIssue(2, "Second issue");

    repo.addLabel(1, "bug");
    repo.addLabel(2, "enhancement");
    repo.addLabel(2, "bug");

    cout << "Issues with label 'bug':" << endl;
    repo.printIssuesWithLabel("bug");

    return 0;
}
