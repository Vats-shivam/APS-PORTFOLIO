#include <iostream>
#include <unordered_map>
#include <string>
#include <optional>
using namespace std;
class Repository {
public:
    string name;
    string owner;

    Repository(const string& name, const string& owner)
        : name(name), owner(owner) {}
};

class GitHub {
public:
    void createRepository(const string& name, const string& owner) {
        repositories.emplace(name, Repository(name, owner)); 
    }

    optional<Repository> getRepository(const string& name) const { 
        auto it = repositories.find(name);
        if (it != repositories.end()) {
            return it->second; 
        } else {
            return nullopt; 
        }
    }

private:
    unordered_map<string, Repository> repositories;
};

int main() {
    GitHub github;
    github.createRepository("SampleRepo", "User1");

    optional<Repository> repo = github.getRepository("SampleRepo");

    if (repo.has_value()) {
        cout << "Repository: " << repo->name << ", Owner: " << repo->owner << endl;
    } else {
        cout << "Repository not found" << endl;
    }

    return 0;
}