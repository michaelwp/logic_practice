//
// Created by michael putong on 05/05/21.
//

#include "string"
#include "iostream"
#include "vector"
#include "map"

using namespace std;

class Palindrome {
private:
    string str;
    map<char, int> mapRes;
    int strLen{};

    // transform string to uppercase
    void toUpper() {
        for_each(str.begin(), str.end(), [](char &c) {
            c = toupper(c);
        });
    }

    // if strlen value is even
    bool even() {
        map<char, int>::iterator it;

        for (it = mapRes.begin(); it != mapRes.end(); it++) {
            if ((it->second % 2) != 0) return false;
        }

        return true;
    }

    // if strlen value is odd
    bool odd() {
        map<char, int>::iterator it;
        int total = 0;

        for (it = mapRes.begin(); it != mapRes.end(); it++) {
            if ((it->second % 2) != 0) {
                total++;
                if (total > 1) return false;
            }
        }

        return true;
    }

    // set mapRes value, number of each character
    void setMap() {
        for (int i = 0; i <= (strLen - 1); i++) {
            mapRes[str[i]]++;
        }
    }

    // clear data;
    void clear() {
        str = "";
        mapRes = {};
        strLen = 0;
    }

public:
    void setStr(string &setStr) {
        str = setStr;
        toUpper();
        strLen = str.length();
    }

    bool isPalindrome() {
        setMap();
        bool result;

        // check if strLen is odd or even
        if ((strLen % 2) == 0) {
            result = even();
        } else {
            result = odd();
        }

        clear();
        return result;
    }
};

// unit test
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
    Palindrome p;

    for (int i = 0; i < tCasesLength; i++) {
        p.setStr(tCases[i].input);

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

