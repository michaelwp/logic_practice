//
//Created by michael putong 12/05/2021
//

#ifndef LOGIC_PRACTICE_PRIMENUMBER_HPP
#define LOGIC_PRACTICE_PRIMENUMBER_HPP


class PrimeNumber{
	protected:
		int N;

	public:
		explicit PrimeNumber(const int& n): N(n){};

		~PrimeNumber(){
			this->N = 0;
		}

		vector<int> start(){
			bool isPrime;
			vector<int> primeNumber;

			for(int i=2;i < this->N;i++){
				isPrime = this->isPrimeNumber(i);

				if (isPrime==true) 
					primeNumber.push_back(i); 
			}

			return primeNumber;
		}

		bool isPrimeNumber(int n){
			bool isPrime = true;

			for(int i=2;i<=n/2;i++){
				if (n % i == 0){
					isPrime = false;
					break;	
				}
			}
			
			return isPrime;
		}
};

//UNIT TESTING
int PrimeNumberTest(){
	cout << "\nPrime Number :" << endl;

	struct TestCase{
		string name;
		int input;
		vector<int> expect;
	};

	vector<TestCase> tCases = {
		{
			"prime number test1",
			10,
			{2,3,5,7}
		}
	};

	for(TestCase c:tCases){
		PrimeNumber p(c.input);
		
		vector<int> actual = p.start();

		if(c.expect != actual){
			cout << "doesnt pass the " << c.name << endl;
			return 1;
		}

		cout << "pass the " << c.name << endl;
	}

	return 0;

}

#endif //LOGIC_PRACTICE_PRIMENUMBER_HPP
