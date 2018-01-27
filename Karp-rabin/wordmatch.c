#include <cstdio>
#include <cmath>

#define PRIME 101
#define BASE 128

int hash(int n)
{
	return n%PRIME;
}

class RollingHash
{	
	private:
		int magic = hash(int(pow(BASE,  5)));
		char start;
		unsigned long long int sum=0;
	public:
		int hashvalue=0;
		RollingHash(char initstring[], int size)
		{
			for (int i = 0; i<5; ++i)
			{
				sum += hash(double(initstring[i]))*int(pow(BASE,i));
			}
			hashvalue = sum%PRIME;

		}

		void moveWindow(char front, char back)
		{
			hashvalue = ((hashvalue*BASE - int(front)*magic + int(back)) % PRIME );
		}				 
};

int main()
{
	char word[] = "hello";
	char test[] = "jjkj hello sfj jjjh hello";
	unsigned long long int sum = 0;
	for (int i = 0; word[i]!='\0'; ++i)
	{
		sum += (hash(int(word[i]))*int(pow(BASE,i)));
	}
	int hashinit = hash(sum);
	RollingHash R(test,5);
	for (int i = 0; test[i]!='\0' && i<int(sizeof(test)-5); ++i)
	{
		R.moveWindow(test[i],test[i+5]);
		if(hashinit == R.hashvalue)
		{
			printf("Found");
			break;
		}
	}
}