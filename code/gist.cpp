#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Gist {
public:
    int id;
    string content;
    vector<string> tags;

    Gist(int id, const string& content) : id(id), content(content) {}
};

class GitHub {
public:
    void createGist(int id, const string& content, const vector<string>& tags) {
        Gist gist(id, content);
        gist.tags = tags;
        gists[id] = gist;
        for (const auto& tag : tags) {
            tagIndex[tag].push_back(id);
        }
    }

    vector<int> searchGistsByTag(const string& tag) {
        if (tagIndex.find(tag) != tagIndex.end()) {
            return tagIndex[tag];
        }
        return {};
    }

    void printGist(int id) {
        if (gists.find(id) != gists.end()) {
            const Gist& gist = gists[id];
            cout << "Gist ID: " << gist.id << endl;
            cout << "Content: " << gist.content << endl;
            cout << "Tags: ";
            for (const auto& tag : gist.tags) {
                cout << tag << " ";
            }
            cout << endl;
        }
    }

private:
    unordered_map<int, Gist> gists;
    unordered_map<string, vector<int>> tagIndex;
};

int main() {
    GitHub github;
    github.createGist(1, "Hello World in Python", {"python", "example"});
    github.createGist(2, "Hello World in C++", {"cpp", "example"});

    cout << "Gists with tag 'example':" << endl;
    for (int id : github.searchGistsByTag("example")) {
        github.printGist(id);
    }

    return 0;
}
