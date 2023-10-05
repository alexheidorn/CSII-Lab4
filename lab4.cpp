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
                Paragraph paragraph;
                paras.push_back(paragraph);
                //cout << theLine.size() << endl;
                while (lineStringStrm >> word) {
                    paragraph.add(word);
                } 
            }
            myFileStrm.close();
        }
        else { cout << "file not found";}
    }
    Paragraph getPara(int loc){
        return paras[loc];
    }



    void prettyPrint(Document paras) {
        int charCount = 0;
        for (auto itr = paras.begin(); itr != paras.end(); ++itr;){
            for (int i = 0; i < paras.getPara(itr).wordCount(); i++)
            {
                charCount += paras.getPara(itr).wordLength(i);
                if (charCount > 80){
                    cout << "\n";
                    charCount = 0;
                }
                cout << paras.getPara(itr).display(i) << " ";
            }
        }
    }
};

int main() {
    Document myDoc("GettysburgAddress.txt");
    myDoc.prettyPrint();
    return 0;
}