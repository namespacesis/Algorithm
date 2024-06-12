#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string hong, fan = ":fan:";
	cin >> hong;
	cout << fan << fan << fan << endl;
	cout << fan << ':' << hong << ':' << fan << endl;
	cout << fan << fan << fan << endl;
}