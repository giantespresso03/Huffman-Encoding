# Huffman Encoding

### Used IDE: Microsoft Visual Studio
### Used Language: C++

## Project Design:
In CSC 2431(Data Structures II) taught by Dr. Arias, I was tasked to create a program that encodes the message using the Huffman algorithm. The Coding Table gets outputted to the console and as a separate .txt file in a JSON-like format. This is the summarized version of the general steps that this program goes through:
1. Open the file for input and create the Frequency table.
1. Sort the Frequency Table on frequency.
1. Using the Frequency Table start creating the Huffman Tree from bottom up.
1. Once the tree is created, traverse it to create the code for each of the
symbols (character) found in the file. This will result in a Encoding Table.
1. Using the Encoding Table read the input file, and for each character use the table
to get the encoding and write the encoding into the output file.

## User Manual

Ideally the user should write a makefile, but the user can compile the following way:
```
g++ yoursource1.cpp yoursource2.cpp -o huffman -std=c++11 -Wall
```
This will result in an executable name `huffman`, remember to specify the name of the exacutable in case you make your own `makefile`. The program should work with command line parameters the following way:
- `./huffman -encode inputfile outputfile`       
  - It will encode the file `inpufile` and create a file `outputfile` with the huffman encoding of the first file       
- `./huffman -decode inputfile outputfile`
  - It will decode the `inputfile` and write the decoded information into the `outputfile`


