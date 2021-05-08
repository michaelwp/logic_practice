//
// Created by michael putong on 05/05/21.
//

#ifndef LOGIC_PRACTICE_FIZZBUZZ_HPP
#define LOGIC_PRACTICE_FIZZBUZZ_HPP

class FizzBuzz {
protected:
    int iter;
public:
    explicit FizzBuzz(const int& i): iter(i) {}

    ~FizzBuzz() {
        this->iter = 0;
    }

    string isFizzBuzz(int& i) {
        if (((i % 3) == 0) && ((i % 5) == 0)) {
            return "FizzBuzz";
        } else if ((i % 3) == 0) {
            return "Fizz";
        } else if ((i % 5) == 0) {
            return "Buzz";
        } else {
            return to_string(i);
        }
    }

    void start() {
        int i = 1;
        do {
            cout << this->isFizzBuzz(i) << endl;
            i++;
        } while (i <= this->iter);
    }

};

// UNIT TESTING
int FizzBuzzTest() {
    struct testCase {
        string name;
        int input;
        string expect;
    };

    testCase tCases[] = {
            {
                    "fizzBuzz test1",
                    3,
                    "Fizz"
            },
            {
                    "fizzBuzz test2",
                    5,
                    "Buzz"
            },
            {
                    "fizzBuzz test3",
                    15,
                    "FizzBuzz"
            },
            {
                    "fizzBuzz test4",
                    7,
                    "7"
            }
    };

    int tCasesLength = (sizeof(tCases) / sizeof(*tCases));

    for (int i = 0; i < tCasesLength; i++) {
        FizzBuzz f(tCases[i].input);

        string act = f.isFizzBuzz(tCases[i].input);
        string exp = tCases[i].expect;
        string name = tCases[i].name;

        if (act != exp) {
            cout << "doesnt pass the " << name <<
                 ", expect: " << exp << ", got: " << act << endl;
            return 1;
        }
        cout << "pass the " << name << endl;
    }

    return 0;
}


#endif //LOGIC_PRACTICE_FIZZBUZZ_HPP