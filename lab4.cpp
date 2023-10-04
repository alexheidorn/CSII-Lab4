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
protected:
    vector<string> words;
};

class Document:public Paragraph {
protected:
    Document() {}
    vector<string> doc;
public:
    Document(string fileName) {
        ifstream myFileStrm(fileName);
        string theLine;
        if (myFileStrm.is_open()) {
            while (getline(myFileStrm,theLine,'\n')) {
                istringstream lineStringStrm(theLine);
                string word;
                Paragraph para;
                int i;
                cout << theLine.size() << endl;
                while (lineStringStrm >> word) {
                    cout << "Word: " << word << endl;
                }
                para.push_back(word);
                
                // Rather than printing out the words, store them
                // by paragraphs (I highly suggest you implement a
                // Paragraph class to hold the words of a paragraph

               
            }
            myFileStrm.close();
        }
        else { cout << "file not found";}
    }
    void prettyPrint() {
        // print out the document, making sure that
        // no line of a paragraph is longer than 80 chars
        
        
        
    }
};

int main() {
    Document myDoc("GettysburgAddress.txt");
    myDoc.prettyPrint();
    return 0;
}