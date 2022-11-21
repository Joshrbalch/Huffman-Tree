#include "huffman.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int binaryStoi(char c) {
    if(c == 48) {
        return 0;
    }

    else {
        return 1;
    }
}

Node* newNode(int val) {
    Node* node = new Node;
    node->num = val;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

int search(vector<int> inOrder, vector<int> levOrder, int inStart, int inEnd) {
    int min = levOrder.size() - 1;
    int temp{};

    if(inStart == inEnd) {
        return inStart;
    }

    for(int i = inStart; i < inEnd; i++) {
        temp = inOrder.at(i);
        for(int j = 0; j < levOrder.size(); j++) {
            if(levOrder.at(j) == temp) {
                if(j < min) {
                    min = j;
                    break;
                }
            }
        }
    }

    temp = levOrder.at(min);

    for(int i = 0; i < inOrder.size(); i++) {
        if(temp == inOrder.at(i)) {
            return i;
        }
    }

    return -1;
}

Node* buildTree(vector<int>& inOrder, vector<int>& levelOrder, int inStart, int inEnd) {
    if(inStart > inEnd) {
        return nullptr;
    }

    int inIndex = search(inOrder, levelOrder, inStart, inEnd);

    // cout << inIndex << endl;
    // cout << inStart << " " << inEnd << endl;

    Node* n = newNode(inOrder.at(inIndex));

    if(inStart == inEnd) {
        return n;
    }

    n->left = buildTree(inOrder, levelOrder, inStart, inIndex - 1);
    n->right = buildTree(inOrder, levelOrder, inIndex + 1, inEnd);
    return n;
}

void traverseTree(vector<int> encoded, Node* root) {
    Node* curr = root;

    for(int i = 0; i < encoded.size(); i++) {
        if(encoded.at(i) == 0) {
            if(curr->left == nullptr) {
                cout << char(curr->num);
                curr = root;
            }

            curr = curr->left;
        }

        else if(encoded.at(i) == 1) {
            if(curr->right == nullptr) {
                cout << char(curr->num);
                curr = root;
            }

            curr = curr->right;
        }
    }

    cout << char(curr->num);
}