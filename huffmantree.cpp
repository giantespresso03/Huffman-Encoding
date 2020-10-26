/*
Filename: huffmantree.cpp
Description: Implimentation of the functions that are required to create a huffman tree and encoding of the text
Author: Junwon Song
Date: 06/05/2019
Course: Data Structures II
*/

#include "huffmantree.h"
#include <algorithm>
using namespace std;

string output;

//Setting output for the ofstream
//Params: string form of output1, which is the name of the file
//Return: None
//Format ERROR: None
void SetOutput(string output1) {
	output = output1;
}

//Getting the output from the header 
//Params: None
//Return: String form of the name of the file
//Format ERROR: None
string GetOutput() {
	return output;
};

//Setting the bool value of decode 
//Params: bool form of true or false
//Return: None
//Format ERROR: None
void Argument::SetDecode(bool tf) {
	decode = tf;
}

//Setting the bool value of encode
//Params: bool form of true or false
//Return: None
//Format ERROR: None
void Argument::SetEncode(bool tf) {
	encode = tf;
}

//Getting the bool value of encode
//Params: None
//Return: None
//Format ERROR: None
bool Argument::GetEncode() {
	return encode;
}

//Getting the bool value of decode
//Params: None
//Return: None
//Format ERROR: None
bool Argument::GetDecode() {
	return decode;
}

//Encodes the individual characters
//Params: class of Node, string form of s, and map<char, string> 
//Return: None
//Format ERROR: None
void EncodedText(Node *root, string s, map<char, string> &encoded){
	if (root == nullptr) {
		return;
	}

	if (!root->left && !root->right) {
		encoded[root->data] = s;
	}

	EncodedText(root->left, s + "1", encoded);
	EncodedText(root->right, s + "0", encoded);
}

//Supposed to decode, but didn't get here yet for the lab
//Params: class of Node, string form of str, int for iteration
//Return: None
//Format ERROR: None
void DecodedText(Node* root, string str, int &iterate){
	if (root == nullptr) {
		return;
	}
	if (!root->left && !root->right)
	{
		cout << root->data;
		return;
	}
	iterate++;

	if (str[iterate] == '\0') {
		DecodedText(root->right, str, iterate);
	}
	else {
		DecodedText(root->left, str, iterate);
	}
}

//sorting function for the frequency table
//Params: None
//Return: bool
//Format ERROR: None
bool Sorting(const pair<char, int> &a, const pair<char, int>&b) {
	return (a.second > b.second);
}

//Function to get the frequency table, sort it, create a huffman table, encodes it, and creates a new file with encoded text
//Params: string form of the entire text
//Return: None
//Format ERROR: None
void HuffmanTree(string text) {
	priority_queue<Node*, vector<Node*>, Comparison> huffmanTable;
	map<char, int> letterCount;
	vector<pair<char, int>> pairs;

	for (char c : text) {
		letterCount[c]++;
	}

	letterCount['\n'] = letterCount['\n'] - 1;


	for (auto itr = letterCount.begin(); itr != letterCount.end(); itr++) {
		pairs.push_back(*itr);
	}

	sort(pairs.begin(), pairs.end(), Sorting);

	for (auto access : pairs) {
		//cout << access.first << " " << access.second << endl;
		Node* node = new Node;

		node->data = access.first;
		node->count = access.second;
		node->left = node->right = nullptr;

		huffmanTable.push(node);
	}

	while (huffmanTable.size() > 1) {
		Node* n = new Node();

		Node *left = huffmanTable.top();
		huffmanTable.pop();
		Node *right = huffmanTable.top();
		huffmanTable.pop();

		int sum = left->count + right->count;

		n->data = '\0';
		n->count = sum;
		n->left = left;
		n->right = right;

		huffmanTable.push(n);
	}

	Node *root = huffmanTable.top();

	map<char, string> huffmanCode;
	
	PreorderOutput(root, "", huffmanCode);
	BFT(root);

	ofstream outFile;
	outFile.open(GetOutput());

	string str = "";

	for (char ch : text) {
		str += huffmanCode[ch];
	}

	outFile << str << endl;

	outFile.close();
}

//Encodes each character of the text, and sets the huffmanCode's values so that it can create an encoded text file
//Params: class node, string form of code, and a map<char, string> of huffmanCode
//Return: None
//Format ERROR: None

void PreorderOutput(Node* root, string code, map<char, string> &huffmanCode ) {
	if (root == nullptr) {
		return;
	}

	if (!root->left && !root->right){
		huffmanCode[root->data] = code;
	}

	if (root->left != nullptr && root->right != nullptr) {

		PreorderOutput(root->right, code + "0", huffmanCode);
		PreorderOutput(root->left, code + "1", huffmanCode);
		return;
	}

	root->code = code;
}

//Iterates through the tree, and couts each of the characters and frequency in a JSON format
//Params: class node of root
//Return: None
//Format ERROR: None
void BFT(Node* root) {
	queue< Node* > q;

	if (root) {
		q.push(root);
	}

	while (!q.empty()){
		const Node* const temp = q.front();
		q.pop();
		if (temp->data == '\n') {
			cout << "{key: CR, code: " << temp->code << "}" << endl;
		}
		else if (temp->data == '\r') {
			cout << "{key: LF, code: " << temp->code << "}" << endl;
		}
		else if (temp->data != '\0') {
			cout << "{key:  " << temp->data << ", code: " << temp->code << '}' << "\n";
		}

		if (temp->left) {
			q.push(temp->right);
		}

		if (temp->right) {
			q.push(temp->left);
		}
	}


}