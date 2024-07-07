#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

class Commit {
public:
    string id;
    string message;
    shared_ptr<Commit> parent; 

    Commit(const string& id, const string& message, shared_ptr<Commit> parent = nullptr)
        : id(id), message(message), parent(parent) {}
};

class VersionControl {
public:
    void commit(const string& id, const string& message) {
        auto newCommit = make_shared<Commit>(id, message, head);
        head = newCommit;
    }

    void printHistory() const { 
        auto current = head;
        while (current) {
            cout << "Commit ID: " << current->id << ", Message: " << current->message << endl;
            current = current->parent;
        }
    }

private:
    shared_ptr<Commit> head = nullptr; 
};

int main() {
    VersionControl vc;
    vc.commit("1", "Initial commit");
    vc.commit("2", "Added new feature");

    vc.printHistory();
    return 0;
}
