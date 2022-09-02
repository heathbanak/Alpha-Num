//
//  main.cpp
//  Alpha-Num
//
//  Created by Heath Banak on 8/21/22.
//
// Convert plain text to numerical text and vice versa

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void popVectors(vector<char> &plainChars, vector<string> &numStrings);
string textToNum(string plain, vector<char> &plainChars, vector<string> &numStrings);
string numToText(string numText, vector<char> &plainChars, vector<string> &numStrings);

int main() {
    vector<char> plainChars;
    vector<string> numStrings;
    string plainText;
    string numText;
    int actionChoice;
    int counter = 0;
    
    popVectors(plainChars, numStrings);
    
    cout << "Enter 1 to convert plain text to numerical text, or enter 2 to convert numerical text to plain text. Enter 3 to quit." << endl;
    
    cin >> actionChoice;
    
    
    while (actionChoice != 3) {
        try {
            switch (actionChoice) {
                case 1:
                    cout << "\nEnter plain text message:" << endl;
                    cin.ignore();
                    getline(cin, plainText);
                    numText = textToNum(plainText, plainChars, numStrings);
                    cout << "\nMessage converted to numerical text:" << endl;
                    cout << numText << endl;
                    break;
                case 2:
                    cout << "\nEnter numerical text message:" << endl;
                    cin.ignore();
                    getline(cin, numText);
                    plainText = numToText(numText, plainChars, numStrings);
                    cout << "\nMessage converted to plain text:" << endl;
                    cout << plainText << endl;
                    break;
                default:
                    throw 6;
                    break;
            }
            cout << "\nEnter 1 to convert plain text to numerical text, or enter 2 to convert numerical text to plain text. Enter 3 to quit." << endl;
            cin >> actionChoice;
            
            counter = 1;
        }
        catch (int err) {
            cout << "\nInvalid entry." << endl;
            cout << "\nEnter 1 to convert plain text to numerical text, or enter 2 to convert numerical text to plain text. Enter 3 to quit." << endl;
            cin >> actionChoice;
            
            counter = 1;
        }
    }
    
    cout << "\nGoodbye." << endl;

    return 0;
}

void popVectors(vector<char> &plainChars, vector<string> &numStrings) {
    int i;
    string addZero = "0";
    
    for (i = 0; i < 26; i++) {
        char addChar = i + 97;
        int addInt = i + 1;
        string addString = to_string(addInt);
        
        if (addString.size() == 1) {
            addString = addZero + addString;
        }
        
        plainChars.push_back(addChar);
        numStrings.push_back(addString);
    }
    
    for (i = 0; i < 33; i++) {
        char addChar = i + 32;
        int addInt = addChar;
        string addString = to_string(addInt);
        
        plainChars.push_back(addChar);
        numStrings.push_back(addString);
        
    }
    
    for (i = 0; i < 6; i++) {
        char addChar = i + 91;
        int addInt = addChar;
        string addString = to_string(addInt);
        
        plainChars.push_back(addChar);
        numStrings.push_back(addString);
        
    }
    
    for (i = 0; i < 4; i++) {
        char addChar = i + 123;
        int addInt = addChar;
        string addString = to_string(addInt);
        
        plainChars.push_back(addChar);
        numStrings.push_back(addString);
        
    }
}


string textToNum(string plain, vector<char> &plainChars, vector<string> &numStrings) {
    string output = "";
    int i;
    int j;
    
    for (i = 0; i < plain.size(); i++) {
        char curr = plain.at(i);
        
        if ((curr >= 65) && (curr <= 90)) {
            curr = tolower(curr);
        }
        
        for (j = 0; j < plainChars.size(); j++) {
            if (curr == plainChars.at(j)) {
                output += numStrings.at(j);
                if (i != plain.size() - 1) {
                    output += " ";
                }
            }
        }
    }
    
    
    return output;
}

string numToText(string numText, vector<char> &plainChars, vector<string> &numStrings) {
    string output = "";
    int i;
    int j;
    string newNum = "";
    
    for (i = 0; i < numText.size(); i++) {
        if (numText.at(i) != ' ') {
            newNum += numText.at(i);
        }
    }
        
    for (i = 0; i < newNum.size(); i += 2) {
        string curr;
        curr += newNum.at(i);
        curr += newNum.at(i + 1);

        for (j = 0; j < numStrings.size(); j++) {
            if (curr == numStrings.at(j)) {
                output += plainChars.at(j);
            }
        }
    }
    
    return output;
}
