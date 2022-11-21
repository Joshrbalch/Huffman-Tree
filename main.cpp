#include <iostream>
#include <fstream>
#include <vector>
#include "huffman.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cout << "Usage: ./a.out inorder.txt levelOrder.txt encoded.txt" << endl;
        return 1;
    }

    string filename = argv[1];
    ifstream file(filename);

    int temp{};
    vector<int> in;

    while(file >> temp) {
        in.push_back(temp);
    }

    file.close();

    vector<int> level;
    filename = argv[2];
    file.open(filename);

    while(file >> temp) {
        level.push_back(temp);
    }

    file.close();

    vector<int> encoded;
    filename = argv[3];
    file.open(filename);

    char c;

    while(file >> c) {
        encoded.push_back(binaryStoi(c));
    }

    Node* head;
    head = buildTree(in, level, 0, in.size() - 1);

    traverseTree(encoded, head);

    return 0;
}
