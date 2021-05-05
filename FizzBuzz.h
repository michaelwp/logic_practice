//
// Created by michael putong on 05/05/21.
//

void FizzBuzz(int n) {
    int i = 1;
    do {
        if (((i % 3) == 0) && ((i % 5) == 0)) {
            cout << "FizzBuzz" << endl;
        } else if ((i % 3) == 0) {
            cout << "Fizz" << endl;
        } else if ((i % 5) == 0) {
            cout << "Buzz" << endl;
        } else {
            cout << i << endl;
        }

        i++;
    } while (i <= n);
}
