#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
class ReviewComment {
public:
    int id;
    string content;

    ReviewComment(int id, const string& content) : id(id), content(content) {}
};

class PullRequest {
public:
    int id;
    string title;
    vector<ReviewComment> comments;

    PullRequest(int id, const string& title) : id(id), title(title) {}
};

class Repository {
public:
    void createPullRequest(int id, const string& title) {
        pullRequests[id] = PullRequest(id, title);
    }

    void addReviewComment(int prId, int commentId, const string& content) {
        if (pullRequests.find(prId) != pullRequests.end()) {
            pullRequests[prId].comments.emplace_back(commentId, content);
        }
    }

    void printComments(int prId) {
        if (pullRequests.find(prId) != pullRequests.end()) {
            const PullRequest& pr = pullRequests[prId];
            cout << "Comments for PR: " << pr.title << endl;
            for (const auto& comment : pr.comments) {
                cout << "- " << comment.content << endl;
            }
        }
    }

private:
    unordered_map<int, PullRequest> pullRequests;
};

int main() {
    Repository repo;
    repo.createPullRequest(1, "Add new feature");
    repo.addReviewComment(1, 101, "Looks good overall.");
    repo.addReviewComment(1, 102, "Consider refactoring this part.");

    repo.printComments(1);
    return 0;
}
