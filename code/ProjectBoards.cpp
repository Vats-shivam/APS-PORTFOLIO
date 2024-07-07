#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Task {
public:
    int id;
    string title;
    string status;

    Task(int id, const string& title, const string& status) : id(id), title(title), status(status) {}
};

class ProjectBoard {
public:
    void addTask(int id, const string& title, const string& status) {
        tasks[id] = Task(id, title, status);
        statusLists[status].push_back(id);
    }

    void moveTask(int id, const string& newStatus) {
        if (tasks.find(id) != tasks.end()) {
            string oldStatus = tasks[id].status;
            tasks[id].status = newStatus;

            auto& oldList = statusLists[oldStatus];
            oldList.erase(remove(oldList.begin(), oldList.end(), id), oldList.end());
            statusLists[newStatus].push_back(id);
        }
    }

    void printBoard() {
        for (const auto& pair : statusLists) {
            cout << pair.first << " column:" << endl;
            for (const auto& taskId : pair.second) {
                cout << "- " << tasks[taskId].title << endl;
            }
        }
    }

private:
    unordered_map<int, Task> tasks;
    unordered_map<string, vector<int>> statusLists;
};

int main() {
    ProjectBoard board;
    board.addTask(1, "Design new feature", "To Do");
    board.addTask(2, "Implement feature", "In Progress");
    board.addTask(3, "Test feature", "Done");

    cout << "Initial Board:" << endl;
    board.printBoard();

    board.moveTask(1, "In Progress");

    cout << "Updated Board:" << endl;
    board.printBoard();

    return 0;
}
