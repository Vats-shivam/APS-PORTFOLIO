#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>
using namespace std;
// Function to create an inverted index from a list of documents (strings).
unordered_map<string, vector<string>> createInvertedIndex(const vector<string>& documents) {
    unordered_map<string, vector<string>> index;

    // Iterate through each document in the collection.
    for (const auto& doc : documents) {
        // Create a stringstream to extract words from the document.
        istringstream stream(doc);
        string word;

        // Extract each word from the stringstream.
        while (stream >> word) {
            // Add the document to the list of documents associated with the word in the index.
            index[word].push_back(doc);
        }
    }

    // Return the completed inverted index.
    return index;
}

// Function to search the inverted index for a given keyword.
vector<string> searchInvertedIndex(const unordered_map<string, vector<string>>& index, const string& keyword) {
    // Check if the keyword exists in the index.
    if (index.find(keyword) != index.end()) {
        // If found, return the list of documents associated with the keyword.
        return index.at(keyword);
    }

    // If the keyword is not found, return an empty vector.
    return {};
}

int main() {
    // Example documents to create the index from.
    vector<string> documents = {
        "int main() { return 0; }",
        "void function() { int a = 10; }",
        "int add(int a, int b) { return a + b; }"
    };

    // Create the inverted index from the documents.
    auto index = createInvertedIndex(documents);

    // Search for the keyword "int" in the index.
    string query = "int";
    auto results = searchInvertedIndex(index, query);

    // Print out the results of the search.
    for (const auto& result : results) {
        cout << result << endl;
    }

    return 0;
}
