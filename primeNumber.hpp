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
			vector<int> primeNumber;

			//for(int i=2;i < this->N;i++){
			//	if (this->isPrimeNumber(i)) 
			//		primeNumber.push_back(i); 
			//}
			
			int i=2;

			while(i<this->N){
				if(this->isPrimeNumber(i))
					primeNumber.push_back(i);
				i++;
			}

			return primeNumber;
		}

		bool isPrimeNumber(int n){
			//bool isPrime = true;

			//for(int i=2;i<=n/2;i++){
			//	if (n % i == 0){
					//isPrime = false;
			//		return false;
					//break;	
			//	}
			//}
			
			//return isPrime;
			
			int i=2;

			while(i<=n/2){
				if(n%i == 0) return false;
				i++;
			}

			return true;
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
