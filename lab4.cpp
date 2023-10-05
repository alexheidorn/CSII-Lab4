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
                int j = 0;
                istringstream lineStringStrm(theLine);
                string word;
                Paragraph paragraph;
                paras.push_back(paragraph);
                cout << theLine.size() << endl;
                int i = 0;
                while (lineStringStrm >> word) {
                    paragraph.add(word);
                    cout << "Word: " << paras[j].display(i) << endl;
                    i++;
                } 
                j++;
            }
            myFileStrm.close();
        }
        else { cout << "file not found";}
    }
    int paraCount(){
        return paras.size();
    }
    void prettyPrint() {
        int charCount = 0;
        int j = 0;
        auto itr = paras.begin();
        for (itr; itr != paras.end();){
            for (int i = 0; i < paras[j].wordCount(); i++)
            {
                //charCount += paras[j].wordLength(i);
                if (charCount > 80){
                    cout << "\n";
                    charCount = 0;
                }
                cout << paras[j].display(i) << " ";
                cout << "j: " << j
                    << " i: " << i << endl;
            } 
            j++;
        }
    }
};

int main() {
    Document myDoc("GettysburgAddress.txt");
    myDoc.prettyPrint();
    return 0;
}