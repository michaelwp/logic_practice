//
// Created by michael putong on 06/05/21.
//

#ifndef LOGIC_PRACTICE_SORT_H
#define LOGIC_PRACTICE_SORT_H

class Sort {
protected:
    vector<int> numbers;
    int lengthOfNumbers;

public:
    //constructor
    explicit Sort(vector<int> &n) {
        this->numbers = n;
        this->lengthOfNumbers = n.size();
    }

    // destructor
    ~Sort() {
        this->numbers.clear();
        this->lengthOfNumbers = 0;
    }

    // bubble sort
    vector<int> bubble() {
        for (int i = 1; i < this->lengthOfNumbers; ++i) {
            if (numbers[i] < numbers[i - 1]) {
                int tmp = numbers[i];
                numbers[i] = numbers[i - 1];
                numbers[i - 1] = tmp;

                i = 0;
            }
        }
        return numbers;
    }

    // insertion sort
    vector<int> insertion() {
        for (int i = 1; i < this->lengthOfNumbers; ++i) {
            bool isReorder = false;
            int tmp, tmpNext;

            for (int j = 0; j <= i; ++j) {
                if (isReorder) {
                    tmpNext = numbers[j];
                    numbers[j] = tmp;
                    tmp = tmpNext;
                }

                if (numbers[i] < numbers[j] && !isReorder) {
                    tmp = numbers[j];
                    numbers[j] = numbers[i];
                    isReorder = true;
                }
            }
        }
        return numbers;
    }
};

// UNIT TESTING
int SortTest() {
    struct testCase {
        string name;
        vector<int> input;
        vector<int> expect;
    };

    testCase tCases[] = {
            {
                    .name = "sort test1",
                    .input = {5, 4, 2, 3, 1, 0},
                    .expect = {0, 1, 2, 3, 4, 5}
            },
            {
                    .name = "sort test2",
                    .input = {60, 20, 10, 40, 30},
                    .expect = {10, 20, 30, 40, 60}
            },
            {
                    .name = "sort test3",
                    .input = {100, 101, 102, 103, 104},
                    .expect = {100, 101, 102, 103, 104}
            }
    };

    int tCasesLength = (sizeof(tCases) / sizeof(*tCases));

    for (int i = 0; i < tCasesLength; i++) {
        vector<int> exp = tCases[i].expect;
        string name = tCases[i].name;
        string expString;
        stringstream ssExp;

        for (int k : exp) ssExp << k << ",";
        expString = ssExp.str();

        // bubble short
        Sort sortBubble(tCases[i].input);

        stringstream ssActBubble;
        string actBubbleString;
        vector<int> actBubble = sortBubble.bubble();

        for (int j : actBubble) ssActBubble << j << ",";
        actBubbleString = ssActBubble.str();

        if (actBubble != exp) {
            cout << "Bubble sort :" << endl;
            cout << "doesnt pass the " << name <<
                 ", expect: {" << expString <<
                 "}, got: {" << actBubbleString << "}" << endl;
            return 1;
        }


        // insertion short
        Sort sortInsertion(tCases[i].input);

        stringstream ssActInsertion;
        string actInsertionString;
        vector<int> actInsertion = sortInsertion.insertion();

        for (int j : actInsertion) ssActInsertion << j << ",";
        actInsertionString = ssActInsertion.str();

        if (actInsertion != exp) {
            cout << "Insertion sort :" << endl;
            cout << "doesnt pass the " << name <<
                 ", expect: {" << expString <<
                 "}, got: {" << actInsertionString << "}" << endl;
            return 1;
        }

        cout << "pass the " << name << endl;
    }

    return 0;
}

#endif //LOGIC_PRACTICE_SORT_H
