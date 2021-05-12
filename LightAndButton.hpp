//
// Created by michael putong on 11/05/2021
//

#ifndef LOGIC_PRACTICE_LIGHTANDBUTTON_HPP
#define LOGIC_PRACTICE_LIGHTANDBUTTON_HPP


class LightAndButton {
	protected:
		long N;

	public:
		explicit LightAndButton(const long& n): N(n){};

		~LightAndButton(){
			this->N = 0;
		}

		string start(){
			long s = round(sqrt(this->N));

			if (s*s != this-> N){
				return "light off";
			} else {
				return "light on";
			}
		}
};

// UNIT TESTING
int LightAndButtonTest(){
	struct TestCase{
		string name;
		long input;
		string expect;
	};

	vector<TestCase> tCases = {
		{
			"light and button test1",
			4,
			"light on"
		},
		{
			"light and button test2",
			12,
			"light off"
		}
	};

	for (TestCase c:tCases){
		LightAndButton lb(c.input);

		string actual = lb.start();

		if (actual != c.expect) {
			cout << "Light and Button :" << endl;
			cout << "doesnt pass the " << c.name << ", expect: {" << c.expect << "}, got: {" << actual << "}" << endl;
			return 1;
		}

		cout << "pass the " << c.name << endl;
	}

	return 0;
}

#endif //LOGIC_PRACTICE_LIGHTANDBUTTON_HPP
