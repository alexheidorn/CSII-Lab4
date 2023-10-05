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
                Paragraph paragraph;
                while (lineStringStrm >> word) {
                    paragraph.add(word);
                } 
                //must populate paras vector AFTER filling paragraph with words
                paras.push_back(paragraph);
            }
            myFileStrm.close();
        }
        else { cout << "File \"GettysburgAddress.txt\" not found";}
    }
    void prettyPrint() {
        int j = 0; //counter variable to access elements in vector of Paragraphs

        //iterate through each element in the vector of Paragraphs
        for (auto itr = paras.begin(); itr != paras.end(); itr++, j++){
            int charCount = 0; //counts characters for a line (resets for each paragraph)
            //if there is an empty paragraph, create a new line
            if (paras[j].wordCount() == 0 ) {
                cout << endl;
            }
            for (int i = 0; i < paras[j].wordCount(); i++)
            {
                /* count the characters for each word in the line,
                * +1 for each succeeding space after a word
                */
                charCount += paras[j].wordLength(i) + 1; 

                /* if most recent word puts count over 80,
                * end line, reset count, and re-add most recent word because it's
                * the start of the next line
                */
                if (charCount >= 80){ 
                    cout << endl;
                    charCount = 0;
                    charCount += paras[j].wordLength(i) + 1;
                }
                cout << paras[j].display(i) << " ";
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