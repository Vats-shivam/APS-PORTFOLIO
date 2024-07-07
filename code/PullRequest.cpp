#include <iostream>
#include <string>
#include <vector>
#include <memory> // For smart pointers
using namespace std;
class Commit {
public:
    string id;
    string message;
    shared_ptr<Commit> parent;  // Use shared_ptr for automatic memory management

    Commit(const string& id, const string& message, shared_ptr<Commit> parent = nullptr)
        : id(id), message(message), parent(parent) {}
};

class PullRequest {
public:
    string id;
    string title;
    string description;
    shared_ptr<Commit> base;
    shared_ptr<Commit> head;

    PullRequest(const string& id, const string& title, const string& description, shared_ptr<Commit> base, shared_ptr<Commit> head)
        : id(id), title(title), description(description), base(base), head(head) {}
};

class GitHub {
public:
    void createCommit(const string& id, const string& message) {
        auto newCommit = make_shared<Commit>(id, message, head);
        head = newCommit;
    }

    void createPullRequest(const string& id, const string& title, const string& description) {
        auto pr = make_shared<PullRequest>(id, title, description, base, head);
        pullRequests.push_back(pr);
    }

    void mergePullRequest(const string& id) {
        for (auto& pr : pullRequests) {
            if (pr->id == id) {
                head = pr->head;
                cout << "Merged pull request: " << pr->title << endl;
                break; 
            }
        }
    }

    void printCommits() const {  // const for methods not modifying the object
        auto current = head;
        while (current) {
            cout << "Commit ID: " << current->id << ", Message: " << current->message << endl;
            current = current->parent;
        }
    }

private:
    shared_ptr<Commit> head = nullptr;
    shared_ptr<Commit> base = nullptr;  // Assuming a single branch (main/master) for simplicity
    vector<shared_ptr<Commit>> commits;
    vector<shared_ptr<PullRequest>> pullRequests; 
};

int main() {
    GitHub github;
    github.createCommit("1", "Initial commit");
    github.createCommit("2", "Added new feature");
    github.createPullRequest("PR1", "Feature merge", "Merging new feature to main");

    github.printCommits();
    github.mergePullRequest("PR1");
    github.printCommits();

    return 0;
}
