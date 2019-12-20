#include<iostream>
using namespace std;
//문제 링크 https://www.acmicpc.net/problem/1946
class Person
{
	
public:
	int rank1;
	int rank2;

};

int main() {
	int Tc = 0;
	int P = 0;
	
	cout << "Type in the number of Test case:";
	scanf("%d", &Tc);
	cout << endl;
	int* Pass = new int[Tc];
	for (int i = 0; i < Tc; i++)
	{
		Pass[i] = 0;
	}

	for (int i = 0; i < Tc; i++)
	{
		int Lowest1 = 0, Lowest2 = 0;
		cout << "Type in the number of Applicants:";
		//cin >> P;
		scanf("%d", &P);
		cout << endl;
		Person* PersonList = new Person[P];
		Pass[i] = P;
		cout << "Type in the 2 scores of Applicants" << endl;
		for (int j = 0; j < P; j++)
		{
			scanf("%d %d", &PersonList[j].rank1, &PersonList[j].rank2);
		}

		for (int k = 0; k < P; k++)
		{
			int temp1 = PersonList[0].rank1;
			PersonList[0].rank1 = PersonList[k].rank1;
			PersonList[k].rank1 = temp1;

			int temp2 = PersonList[0].rank2;
			PersonList[0].rank2 = PersonList[k].rank2;
			PersonList[k].rank2 = temp2;


			for (int q = 1; q < P; q++)
			{
				if (PersonList[0].rank1 > PersonList[q].rank1 && PersonList[0].rank2 > PersonList[q].rank2)
				{
					Pass[i] --;
					break;
				}
			}
		}
		
		delete[]PersonList;
	}

	cout << endl << endl;
	for (int i = 0; i < Tc; i++)
	{
		cout << Pass[i] << endl;
	}

	delete[]Pass;
	return 0;
}