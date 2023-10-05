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
    string display(int i){
        return words[i];
    }
    int wordCount(){
        return words.size();
    }
    int wordLength(int i){
        return words[i].length();
    }
};

class Document {
protected:
    vector<Paragraph> paras;
    Document() {}
public:
    Document(string fileName) {
        ifstream myFileStrm(fileName);
        string theLine;
        if (myFileStrm.is_open()) {
            while (getline(myFileStrm,theLine,'\n')) {  
                istringstream lineStringStrm(theLine);
                string word;
                vector<Paragraph> p;
                Paragraph paragraph;
                
                /* cout << theLine.size() << endl;
                int i = 0;
                int j = 0;
                */
                while (lineStringStrm >> word) {
                    paragraph.add(word);
                    /* testing vector access here
                    //cout << "Word: " << paras[j].display(i) << endl;
                    cout << "Word: " << paragraph.display(i) << endl;
                    i++;
                    */
                } 
                //must populate paras vector AFTER filling paragraph with words
                paras.push_back(paragraph);
                //j++;
            }
            myFileStrm.close();
        }
        else { cout << "file not found";}
    }
    //i think this is useless, but its a remnant from an idea i had on a previous change
    int paraCount(){
        return paras.size();
    }
    void prettyPrint() {
        int charCount = 0; //counts characters for a line
        int j = 0;
        for (auto itr = paras.begin(); itr != paras.end(); itr++, j++){
            /* Tests that j & word count are lining up
            cout << "j: " << j << endl;
            cout << "Word count: " << paras[j].wordCount() << endl;
            */
            //if there is an empty paragraph, create a new line & reset charCount.
            if (paras[j].wordCount() == 0 ) {
                cout << endl; 
                charCount = 0;
            };
            for (int i = 0; i < paras[j].wordCount(); i++)
            {
                if (charCount >= 80){
                    cout << "\n";
                    charCount = 0;
                }
                charCount += paras[j].wordLength(i);
                cout << paras[j].display(i) << " ";
                charCount += 1;
                /* tests that j & i were working properly
                cout << "j: " << j
                    << " i: " << i << endl;
                */
            } 
            //end line after a paragraph
            cout << endl;
        }
    }
};

int main() {
    Document myDoc("GettysburgAddress.txt");
    myDoc.prettyPrint();
    return 0;
}