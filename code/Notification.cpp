#include <iostream>
#include <queue>
#include <string>
using namespace std;
class Notification {
public:
    int priority;
    string message;

    Notification(int priority, const string& message)
        : priority(priority), message(message) {}

    // Overloaded comparison operator for priority queue sorting.
    bool operator<(const Notification& other) const {
        return priority < other.priority; 
    }
};

class NotificationSystem {
public:
    void addNotification(int priority, const string& message) {
        notifications.push(Notification(priority, message));
    }

    void processNotifications() {
        while (!notifications.empty()) {
            Notification notification = notifications.top();
            notifications.pop();
            cout << "Notification: " << notification.message << endl;
        }
    }

private:
    priority_queue<Notification> notifications;
};

int main() {
    NotificationSystem system;
    system.addNotification(1, "New pull request");
    system.addNotification(3, "New issue opened");
    system.addNotification(2, "New commit pushed");

    system.processNotifications();

    return 0;
}
