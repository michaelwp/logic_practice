//
// Created by michael putong on 06/05/21.
//

#ifndef LOGIC_PRACTICE_SORT_HPP
#define LOGIC_PRACTICE_SORT_HPP

class Sort {
protected:
    vector<int> numbers;
    int lengthOfNumbers{};
    vector<int>::iterator it;

public:
    //constructor
    explicit Sort(const vector<int> &numbers) :
            numbers(numbers), lengthOfNumbers(numbers.size()) {}

    // destructor
    virtual ~Sort() {
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

    // counting sort
    vector<int> counting() {
        const int max = *max_element(numbers.begin(), numbers.end());
        const int min = *min_element(numbers.begin(), numbers.end());
        const int range = (max - min) + 1;

        vector<int> count(range), output(lengthOfNumbers);

        // count total number of element in `numbers` array
        for (int number : numbers)
            count[number - min]++;

        // sum `count` array current element with previous element
        for (int i = 1; i < count.size(); ++i)
            count[i] += count[i - 1];

        // assign `numbers` element into `output` numbers
        for (int number : numbers) {
            output[count[number - min] - 1] = number;
            count[number - min]--;
        }

        return output;
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
                    .input = {5, 4, 2, 3, 1, 0, 2, 1},
                    .expect = {0, 1, 1, 2, 2, 3, 4, 5}
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

        // counting short
        Sort sortCounting(tCases[i].input);

        stringstream ssActCounting;
        string actCountingString;
        vector<int> actCounting = sortCounting.counting();

        for (int j : actCounting) ssActCounting << j << ",";
        actCountingString = ssActCounting.str();

        if (actCounting != exp) {
            cout << "Counting sort :" << endl;
            cout << "doesnt pass the " << name <<
                 ", expect: {" << expString <<
                 "}, got: {" << actCountingString << "}" << endl;
            return 1;
        }

        cout << "pass the " << name << endl;
    }

    return 0;
}

#endif //LOGIC_PRACTICE_SORT_HPP
