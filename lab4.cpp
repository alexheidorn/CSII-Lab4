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
#include <list>
using namespace std;


class Paragraph {
protected:
    vector<string> words;
public: 
    void add(string s){
        words.push_back(s);
    }
    void 
    void display(){
        for (auto i : words){
            cout << i;
        }
    }
};

class Document {
protected:
    list<Paragraph> para;
    Document() {}
public:
    Document(string fileName) {
        ifstream myFileStrm(fileName);
        string theLine;
        if (myFileStrm.is_open()) {
            while (getline(myFileStrm,theLine,'\n')) {
                istringstream lineStringStrm(theLine);
                string word;
                Paragraph paragraph;
                para.push_back(paragraph);
                //cout << theLine.size() << endl;
                while (lineStringStrm >> word) {
                    paragraph.add(word);
                }
                
                // Rather than printing out the words, store them
                // by paragraphs (I highly suggest you implement a
                // Paragraph class to hold the words of a paragraph

               
            }
            myFileStrm.close();
        }
        else { cout << "file not found";}
    }
    void prettyPrint() {
        for(auto )
        
        string s;
        s.length(); //number of characters
        //check where s.length is <80
    }
};

int main() {
    Document myDoc("GettysburgAddress.txt");
    myDoc.prettyPrint();
    return 0;
}