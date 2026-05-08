[?1034h[24bcs170@mepcolinux ex7]$cat h.cpp
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

map<char, string> huffmanMap;

void storeCodes(Node* root, string code) {
    if (!root) return;
    if (root->ch != '$')
        huffmanMap[root->ch] = code;
    storeCodes(root->left, code + "0");
    storeCodes(root->right, code + "1");
}

void HuffmanCodes(vector<char> &data, vector<int> &freq) {
    priority_queue<Node*, vector<Node*>, compare > pq;

    for (size_t i = 0; i < data.size(); i++)
        pq.push(new Node(data[i], freq[i]));

    while (pq.size() > 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();
        Node *merged = new Node('$', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        pq.push(merged);
    }
    storeCodes(pq.top(), "");
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    vector<char> data(n);
    vector<int> freq(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter character " << i+1 << ": ";
        cin >> data[i];
        cout << "Enter frequency for " << data[i] << ": ";
        cin >> freq[i];
    }

    HuffmanCodes(data, freq);

    cout << "\n--- Huffman Table ---\n";
    for (map<char, string>::iterator it = huffmanMap.begin(); it != huffmanMap.end(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }

    string inputStr;
    cout << "\nEnter string to encode: ";
    cin >> inputStr;

    string encodedStr = "";
    for (size_t i = 0; i < inputStr.length(); i++) {
        encodedStr += huffmanMap[inputStr[i]];
    }

    cout << "Encoded Output: " << encodedStr << endl;

    return 0;
}

[24bcs170@mepcolinux ex7]$g++ h.cpp
[24bcs170@mepcolinux ex7]$./a.out
Enter number of characters: 5
Enter character 1: a
Enter frequency for a: 10
Enter character 2: b
Enter frequency for b: 25
Enter character 3: c
Enter frequency for c: 69
Enter character 4: d
Enter frequency for d: 78
Enter character 5: e
Enter frequency for e: 33

--- Huffman Table ---
a: 1010
b: 1011
c: 11
d: 0
e: 100

Enter string to encode: dad
Encoded Output: 010100
[24bcs170@mepcolinux ex7]$exit
exit
