/*
* Alex Heidorn
* Created: 9-28-23
* CS 2 Lab 4
*  
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


class Paragraph {
private:
    string para;
public:
    string getPara() { return para; };
    string setPara(string line) { para = line; };
};

class Document {
private:
    Document() {}
public:
    Document(string fileName) {
        ifstream myFileStrm(fileName);
        string theLine;
        if (myFileStrm.is_open()) {
            vector<Paragraph> words;
            while (getline(myFileStrm,theLine,'\n')) {
                /*
                istringstream lineStringStrm(theLine);
                string word;
                cout << theLine.size() << endl;
                while (lineStringStrm >> word) {
                    cout << "Word: " << word << endl;
                }
                */
                
                // Rather than printing out the words, store them
                // by paragraphs (I highly suggest you implement a
                // Paragraph class to hold the words of a paragraph

                int i;
                new string
                words[i].setPara(new theLine);
            }
            myFileStrm.close();
        }
        else { cout << "file not found";}
    }
    void prettyPrint() {
        // print out the document, making sure that
        // no line of a paragraph is longer than 80 chars
        /* TEMP*/
        words
    }
};

int main() {
    Document myDoc("GettysburgAddress.txt");
    myDoc.prettyPrint();
    return 0;
}