#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>
#include <thread>
#include <chrono>
using namespace std;
class APIRequest {
public:
    int id;
    string endpoint;

    APIRequest(int id, const string& endpoint) : id(id), endpoint(endpoint) {}
};

class GitHubAPI {
public:
    void sendRequest(const string& endpoint) {
        int id = nextRequestId++;
        requestQueue.push(APIRequest(id, endpoint));
        cout << "Request " << id << " sent to " << endpoint << endl;
    }

    void processRequests() {
        while (!requestQueue.empty()) {
            APIRequest request = requestQueue.front();
            requestQueue.pop();
            cout << "Processing request " << request.id << " to " << request.endpoint << endl;
            this_thread::sleep_for(chrono::milliseconds(100)); 
        }
    }

private:
    int nextRequestId = 1;
    queue<APIRequest> requestQueue;
};

int main() {
    GitHubAPI api;
    api.sendRequest("/repos/octocat/Hello-World/issues");
    api.sendRequest("/repos/octocat/Hello-World/pulls");

    cout << "Processing API requests:" << endl;
    api.processRequests();

    return 0;
}
