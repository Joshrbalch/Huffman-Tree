#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <fstream>
#include <vector>
#include "huffman.h"

using namespace std;

class Node {
    public:
    Node* left;
    Node* right;
    int num;
};

Node* newNode(int val); 
// creates a new Node

int search(vector<int> inOrder, vector<int> levOrder, int inStart, int inEnd);
// returns the inOrder index of the minimum levOrder index in the range inStart to inEnd

Node* buildTree(vector<int>& inOrder, vector<int>& levelOrder, int inStart, int inEnd);
// recursive function to build a binary tree from the given level-order and in-order traversals

void traverseTree(vector<int> encoded, Node* root);
// traverses the tree using the instructions in the vector encoded. If there is a 0, it goes left, and if there is a 1, it goes right. 
// once it reaches a leaf node, it prints the ASCII value

int binaryStoi(char c);
// takes in a char '0' or '1' and returns the int version

#endif