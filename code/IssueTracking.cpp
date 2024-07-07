#include <iostream>
#include <unordered_map>
#include <string>
#include <optional>
using namespace std;
class Issue {
public:
    int id;
    string title;
    string description;

    Issue(int id, const string& title, const string& description)
        : id(id), title(title), description(description) {}
};

class IssueTracker {
public:
    void createIssue(int id, const string& title, const string& description) {
        issues.emplace(id, Issue(id, title, description));
    }

    optional<Issue> getIssue(int id) const {
        auto it = issues.find(id);
        if (it != issues.end()) {
            return it->second; 
        } else {
            return nullopt; 
        }
    }

private:
    unordered_map<int, Issue> issues; 
};

int main() {
    IssueTracker tracker;
    tracker.createIssue(1, "Sample Issue", "This is a sample issue.");

    optional<Issue> issue = tracker.getIssue(1);
    if (issue.has_value()) {
        cout << "Issue ID: " << issue->id << ", Title: " << issue->title << endl; 
    } else {
        cout << "Issue not found" << endl; 
    }

    return 0;
}
