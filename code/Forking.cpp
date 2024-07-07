#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
class Repository {
public:
    string name;
    vector<Repository*> forks;

    Repository(const string& name) : name(name) {}
};

class GitHub {
public:
    void createRepository(const string& name) {
        repositories[name] = new Repository(name);
    }

    void forkRepository(const string& original, const string& fork) {
        if (repositories.find(original) != repositories.end()) {
            Repository* originalRepo = repositories[original];
            Repository* forkRepo = new Repository(fork);
            originalRepo->forks.push_back(forkRepo);
            repositories[fork] = forkRepo;
        }
    }

    void listForks(const string& name) {
        if (repositories.find(name) != repositories.end()) {
            Repository* repo = repositories[name];
            cout << "Forks of " << repo->name << ":" << endl;
            for (const auto& fork : repo->forks) {
                cout << "- " << fork->name << endl;
            }
        }
    }

private:
    unordered_map<string, Repository*> repositories;
};

int main() {
    GitHub github;
    github.createRepository("OriginalRepo");
    github.forkRepository("OriginalRepo", "ForkedRepo1");
    github.forkRepository("OriginalRepo", "ForkedRepo2");

    github.listForks("OriginalRepo");
    return 0;
}
