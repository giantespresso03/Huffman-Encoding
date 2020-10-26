/*
Filename: main.cpp
Description: Declaration of the class HuffmanTree to represent the binary Huffman Tree
Author: McDonald Berger
Date: 05/29/2019
Course: Data Structures II
*/

#include "huffmantree.h"

using namespace std;

int main(int argc, char const *argv[]) {

	if (argc < 4) {
		cerr << "There's too little arguments. Ending the program." << endl;
		return -1;
	}
	else if (argc > 4) {
		cerr << "There's too many arguments. Ending the program." << endl;
		return -1;
	}

	Argument arguments;
	if (string(argv[1]) == "-encode"){
		arguments.SetEncode(true);

		string title;
		title = string(argv[2]);
		SetOutput(string(argv[3]));

		string textAll, line;
		ifstream inFile;
		inFile.open(title);

		if (inFile.fail()) {
			cerr << "No File" << endl;
			exit(1);
		}

		while (!inFile.eof()) {
			getline(inFile, line);
			textAll = textAll + line + '\n';
		}

		inFile.close();

		textAll.pop_back();

		HuffmanTree(textAll);
	}

	else if (string(argv[1]) == "-decode") {
		cout << "Found decode" << endl;
		arguments.SetDecode(true);

		string title;
		title = string(argv[2]);

		string textAll, line;
		ifstream inFile;
		inFile.open(title);

		if (inFile.fail()) {
			cerr << "No File" << endl;
			exit(1);
		}

		while (!inFile.eof()) {
			getline(inFile, textAll);
		}

		inFile.close();

		HuffmanTree(textAll);
	}

	return 0;
}

	