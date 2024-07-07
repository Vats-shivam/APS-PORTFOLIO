#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
class Branch {
public:
    std::string name;
    bool protectedBranch;

    Branch(const std::string& name, bool protectedBranch = false)
        : name(name), protectedBranch(protectedBranch) {}
};

class Repository {
public:
    void createBranch(const std::string& name, bool protectedBranch = false) {
        branches[name] = Branch(name, protectedBranch);
    }

    bool isBranchProtected(const std::string& name) {
        return branches.find(name) != branches.end() && branches[name].protectedBranch;
    }

    void protectBranch(const std::string& name) {
        if (branches.find(name) != branches.end()) {
            branches[name].protectedBranch = true;
        }
    }

private:
    std::unordered_map<std::string, Branch> branches;
};

int main() {
    Repository repo;
    repo.createBranch("main", true);
    repo.createBranch("dev");

    std::cout << "Is 'main' branch protected? " << (repo.isBranchProtected("main") ? "Yes" : "No") << std::endl;
    std::cout << "Is 'dev' branch protected? " << (repo.isBranchProtected("dev") ? "Yes" : "No") << std::endl;

    repo.protectBranch("dev");
    std::cout << "Is 'dev' branch protected now? " << (repo.isBranchProtected("dev") ? "Yes" : "No") << std::endl;

    return 0;
}
