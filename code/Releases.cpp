#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Release {
public:
    string version;
    string description;

    Release(const string& version, const string& description)
        : version(version), description(description) {}
};

class GitHubReleases {
public:
    void createRelease(const string& version, const string& description) {
        releases.push_back(Release(version, description));
    }

    void listReleases() {
        for (const auto& release : releases) {
            cout << "Version: " << release.version << ", Description: " << release.description << endl;
        }
    }

private:
    vector<Release> releases;
};

int main() {
    GitHubReleases github;
    github.createRelease("v1.0.0", "Initial release");
    github.createRelease("v1.1.0", "Added new features");

    github.listReleases();
    return 0;
}
