#include <iostream>
#include <queue>
#include <string>
using namespace std;

class WebhookEvent {
public:
    string eventType;
    string payload;

    WebhookEvent(const string& eventType, const string& payload)
        : eventType(eventType), payload(payload) {}
};

class WebhookQueue {
public:
    void addEvent(const string& eventType, const string& payload) {
        queue.push(WebhookEvent(eventType, payload));
    }

    void processEvents() {
        while (!queue.empty()) {
            WebhookEvent event = queue.front();
            queue.pop();
            cout << "Processing event: " << event.eventType << ", Payload: " << event.payload << endl;
        }
    }

private:
    queue<WebhookEvent> queue;
};

int main() {
    WebhookQueue webhookQueue;
    webhookQueue.addEvent("push", "{ \"ref\": \"refs/heads/main\" }");
    webhookQueue.addEvent("pull_request", "{ \"action\": \"opened\" }");

    webhookQueue.processEvents();

    return 0;
}
