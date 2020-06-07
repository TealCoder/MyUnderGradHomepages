#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::rand;
using std::srand;
using std::time;

const int inputs = 25;

class nn
{
  public:
	nn(double r = .1);
	double evaluate(double input[inputs]);
	void adjust(double input[inputs], double);
	void print();
  private:
	const double rate;
	double weight[inputs];
};

int main()
{
	const int shapec = 4;
	char shape[shapec][9] = { "diamond", "square",
		"triangle", "garbage"};
	double input[shapec][inputs]={{0,0,1,0,0,
				0,1,0,1,0,
				1,0,0,0,1,
				0,1,0,1,0,
				0,0,1,0,0	},
			{	0,0,0,0,0,
				0,1,1,1,0,
				0,1,0,1,0,
				0,1,1,1,0,
				0,0,0,0,0	},
			 {	0,0,0,0,0,
				0,0,1,0,0,
				0,1,0,1,0,
				1,1,1,1,1,
				0,0,0,0,0	},
			{	1,0,1,0,1,
				0,1,0,1,0,
				1,0,1,0,1,
				0,1,0,1,0,
				1,0,1,0,1	}	};
	srand(time(0));
	nn tri(.05);
	int i, a;
	for (i = 0; i < 20; i++)
		tri.adjust(input[i%shapec], double((i%shapec==2)?1:0));
	for (i = 0; i < shapec; i++)
	{
		cout << "What is a " << shape[i] << "?\n";
		a = (int)(100*tri.evaluate(input[i]));
		cout << a << "\% Triangle\n";
	}
	//tri.print();
	return 0;
}

void nn::print()
{
	int i, j;
	cout << "\nweights:\n";
	for (i = 0; i < inputs; i++)
	{
		cout << weight[i] << ' ';
	}
}
nn::nn(double r = .1) : rate(r)
{
	for (int i = 0; i < inputs; i++)
	{
			weight[i]=0;
	}
}

double nn::evaluate(double input[inputs])
{
	double sum = 0;
	for (int i = 0; i < inputs; i++)
	{
		sum+=weight[i]*input[i];
	}
	return sum;
}

void nn::adjust(double input[inputs], double val)
{	
	double dif = val - evaluate(input);
	for (int i = 0; i < inputs; i++)
	{
		weight[i]+=rate*dif*input[i];
	}
}
