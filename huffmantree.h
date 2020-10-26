/*
Filename: huffmantree.h
Description: Declaration of the class HuffmanTree to represent the binary Huffman Tree
Author: Junwon Song
Date: 06/05/2019
Course: Data Structures II
*/

#pragma once

#include <iostream>
#include <queue>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
	int count;
	char data;
	string code;
	Node *left, *right;
};

class Comparison {
public:
	bool operator() (const Node *first, const Node *second) {
		return first->count > second->count;
	}
};

class Argument {
public:
	void SetEncode(bool tf);
	void SetDecode(bool tf);
	bool GetEncode();
	bool GetDecode();

private:
	bool encode;
	bool decode;

};

extern string output;
string GetOutput();
void SetOutput(string output1);
void HuffmanTree(string text);
void EncodedText(Node *root, string s, map<char, string> &encoded);
void DecodedText(Node* root, int &index, string str);
bool Sorting(const pair<char, int> &a, const pair<char, int>&b);
void BFT(Node*);
void PreorderOutput(Node* root, string code, map<char, string> &huffmanCode);
void SetOutput(string output1);
