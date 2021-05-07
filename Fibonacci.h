//
// Created by michael putong on 06/05/21.
//

#ifndef LOGIC_PRACTICE_FIBONACCI_H
#define LOGIC_PRACTICE_FIBONACCI_H

#include <sstream>

class Fibonacci {
private:
    int iter;
    vector<int> fib;
public:
    explicit Fibonacci(int &i) {
        this->iter = i;
    }

    ~Fibonacci() {
        this->iter = 0;
        this->fib.clear();
    }

    vector<int> start() {
        for (int i = 0; i < this->iter; ++i) {
            if (i > 1) {
                int f = fib[i - 1] + fib[i - 2];
                this->fib.push_back(f);
            } else {
                this->fib.push_back(i);
            };
        }

        return this->fib;
    }
};

// UNIT TESTING
int FibonacciTest() {
    struct testCase {
        string name;
        int input;
        vector<int> expect;
    };

    testCase tCases[] = {
            {
                    "fibonacci test1",
                    10,
                    {0, 1, 1, 2, 3, 5, 8, 13, 21, 34}
            },
            {
                    "fibonacci test2",
                    7,
                    {0, 1, 1, 2, 3, 5, 8}
            },
    };

    int tCasesLength = (sizeof(tCases) / sizeof(*tCases));

    for (int i = 0; i < tCasesLength; i++) {
        Fibonacci f(tCases[i].input);

        vector<int> act = f.start();
        vector<int> exp = tCases[i].expect;
        string name = tCases[i].name;

        string actString;
        string expString;
        stringstream ssAct, ssExp;

        for (int j : act) ssAct << j << ",";
        for (int k : exp) ssExp << k << ",";

        actString = ssAct.str();
        expString = ssExp.str();

        if (act != exp) {
            cout << "doesnt pass the " << name <<
                 ", expect: {" << expString <<
                 "}, got: {" << actString << "}" << endl;
            return 1;
        }
        cout << "pass the " << name << endl;
    }

    return 0;
}

#endif //LOGIC_PRACTICE_FIBONACCI_H
