#include <iostream>
#include <vector>

using namespace std;

double buffNumber, answer;
char buffOperation;

int main()
{
	cout << "Enter the exprassion: " << endl;
	vector <double> numbers{};
	vector <char> operation{};
	vector <double> numbers2{};

	while (buffOperation != '=')
	{
		cin >> buffNumber;
		numbers.push_back(buffNumber);
		cin >> buffOperation;
		if (buffOperation != '=')
		{
			operation.push_back(buffOperation);
		}
		else
		{
			break;
		}
	}

	for (int i = 0; i < numbers.size() - 1; i++)
	{
		if (operation[i] == '*')
		{
			numbers2.push_back(numbers[i] * numbers[i + 1]);
			operation.erase(operation.begin() + i);
			i++;
		}
		else if (operation[i] == '/')
		{
			numbers2.push_back(numbers[i] / numbers[i + 1]);
			operation.erase(operation.begin() + i);
			i++;
		}
		else if (operation[i] == '+')
		{
			numbers2.push_back(numbers[i]);
		}
		else if (operation[i] == '-')
		{
			numbers2.push_back(numbers[i]);
		}
	}

	for (int i = 0; i < operation.size(); i++)
	{	
		if (i == 0)
		{
			answer += numbers2[0];
		}
		if (operation[i] == '+')
		{
			answer += numbers2[i+1];
		}
		else if (operation[i] == '-')
		{
			answer -= numbers2[i+1];
		}
	}

	cout << answer;

	return 0;
}