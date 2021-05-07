//
// Created by michael putong on 05/05/21.
//

#ifndef LOGIC_PRACTICE_PALINDROME_H
#define LOGIC_PRACTICE_PALINDROME_H

#include "string"
#include "iostream"
#include "vector"
#include "map"

using namespace std;

class Palindrome {
private:
    string str;
    map<char, int> mapRes;
    int strLen;

    // transform string to uppercase
    string toUpper(string &s) {
        for_each(s.begin(), s.end(), [](char &c) {
            c = toupper(c);
        });

        return s;
    }

    // if strlen value is even
    bool even() {
        map<char, int>::iterator it;

        for (it = this->mapRes.begin(); it != this->mapRes.end(); it++) {
            if ((it->second % 2) != 0) return false;
        }

        return true;
    }

    // if strlen value is odd
    bool odd() {
        map<char, int>::iterator it;
        int total = 0;

        for (it = this->mapRes.begin(); it != this->mapRes.end(); it++) {
            if ((it->second % 2) != 0) {
                total++;
                if (total > 1) return false;
            }
        }

        return true;
    }

    // set mapRes value, number of each character
    void setMap() {
        for (int i = 0; i <= (this->strLen - 1); i++) {
            this->mapRes[this->str[i]]++;
        }
    }

public:
    // constructor
    explicit Palindrome(string &s) {
        this->str = this->toUpper(s);
        this->strLen = s.length();
    }

    // destructor
    ~Palindrome() {
        this->str.erase();
        this->mapRes.clear();
        this->strLen = 0;
    }

    bool isPalindrome() {
        setMap();
        bool result;

        // check if strLen is odd or even
        if ((this->strLen % 2) == 0) {
            result = even();
        } else {
            result = odd();
        }

        return result;
    }
};

// UNIT TESTING
int PalindromeTest() {
    struct testCase {
        string name;
        string input;
        bool expect;
    };

    testCase tCases[] = {
            {
                    "palindrome test1",
                    "Ktaka",
                    true
            },
            {
                    "palindrome test2",
                    "KaKa",
                    true
            },
            {
                    "palindrome test3",
                    "Kaki",
                    false
            }
    };

    int tCasesLength = (sizeof(tCases) / sizeof(*tCases));

    for (int i = 0; i < tCasesLength; i++) {
        Palindrome p(tCases[i].input);

        bool act = p.isPalindrome();
        bool exp = tCases[i].expect;
        string name = tCases[i].name;

        if (act != exp) {
            cout << "doesnt pass the " << name <<
                 ", expect: " << exp << ", got: " << to_string(act) << endl;
            return 1;
        }
        cout << "pass the " << name << endl;
    }

    return 0;
}


#endif //LOGIC_PRACTICE_PALINDROME1_H
