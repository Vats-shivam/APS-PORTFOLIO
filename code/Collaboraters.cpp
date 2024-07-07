#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Collaborator {
public:
    string username;
    string role;

    Collaborator(const string& username, const string& role) : username(username), role(role) {}
};

class Repository {
public:
    void addCollaborator(const string& username, const string& role) {
        collaborators[username] = Collaborator(username, role);
    }

    void removeCollaborator(const string& username) {
        collaborators.erase(username);
    }

    void printCollaborators() {
        for (const auto& pair : collaborators) {
            cout << "Username: " << pair.second.username << ", Role: " << pair.second.role << endl;
        }
    }

private:
    unordered_map<string, Collaborator> collaborators;
};

int main() {
    Repository repo;
    repo.addCollaborator("User1", "Admin");
    repo.addCollaborator("User2", "Contributor");

    repo.printCollaborators();
    repo.removeCollaborator("User2");

    repo.printCollaborators();
    return 0;
}
