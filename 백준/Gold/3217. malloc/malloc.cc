#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <map>
#include <list>
using namespace std;

list<pair<int, int>> li; //(할당할 수 있는 위치, 해당 위치에서 할당 가능한 공간)
list<pair<int, int>>::iterator it;
map<string, pair<int, int>> check; //(변수,(할당된 위치, 할당된 공간))
int n;

//check_size만큼 공간 할당이 가능하면 공간할당을 하고 변수에 대한 정보 저장
//불가능하면 변수에 대한 정보 0으로 저장
void Add(string var, int check_size)
{
	for (list<pair<int, int>>::iterator i = li.begin(); i != li.end(); i++)
	{
		//i에서 check_size만큼 공간할당이 가능할때
		if ((*i).second >= check_size)
		{
			if (check.count(var) != 0)
				check[var] = make_pair((*i).first, check_size);

			else
				check.insert(make_pair(var, make_pair((*i).first, check_size))); //해당 변수가 어디에 얼만큼 할당되는지 따로 저장해둔다

			int before_point = (*i).first;
			int before_size = (*i).second;

			//해당 공간에 할당하고 나서 공간이 남지 않을때
			if (before_size == check_size)
			{
				li.erase(i);
			}

			else
			{
				(*i) = make_pair(before_point + check_size, before_size - check_size);
			}

			return;
		}
	}

	//할당가능한 공간이 없을때
	if (check.count(var) != 0)
		check[var] = make_pair(0, 0);
	else
		check.insert(make_pair(var, make_pair(0, 0)));

	return;
}

void Delete(string var)
{
	int var_point = check[var].first;
	int var_size = check[var].second;

	//해당변수가 할당되지 않았을때
	if (var_point == 0)
		return;

	check[var].first = 0; //0을 저장
	check[var].second = 0;

	for (list<pair<int, int>>::iterator i = li.begin(); i != li.end(); i++)
	{
		int this_point = (*i).first;
		int this_size = (*i).second;

		if (var_point < this_point)
		{
			list<pair<int, int>>::iterator inserted_it = li.insert(i, make_pair(var_point, var_size));

			//앞뒤로 연결된거 있는지 확인

			//앞쪽확인
			if (inserted_it != li.begin()) //들어간 위치가 제일 앞이 아닐때
			{
				list<pair<int, int>>::iterator inserted_it_before = inserted_it;
				inserted_it_before--; //들어간 위치앞쪽

				//앞쪽이랑 연결이 될때
				if ((*inserted_it_before).first + (*inserted_it_before).second == (*inserted_it).first)
				{
					(*inserted_it_before).second += (*inserted_it).second; //앞쪽이랑 합치고
					li.erase(inserted_it); //합쳐진거 지운다

					inserted_it = inserted_it_before;
				}
			}

			//뒤쪽확인
			list<pair<int, int>>::iterator inserted_it_after = inserted_it;
			inserted_it_after++;
			if (inserted_it_after != li.end()) //삽입된 위치가 가장 마지막이 아닐때
			{
				//뒤쪽이랑 연결이 될때
				if ((*inserted_it).first + (*inserted_it).second == (*inserted_it_after).first)
				{
					(*inserted_it).second += (*inserted_it_after).second; //뒤쪽것을 합치고
					li.erase(inserted_it_after); //합쳐진거 지운다
				}
			}


			return;
		}
	}

	//제일 마지막 위치일때

	li.push_back(make_pair(var_point, var_size));

	//앞쪽에 연결된거 있는지 확인
	list<pair<int, int>>::iterator inserted_it = li.end();
	inserted_it--;

	//리스트에 하나 이상으로 있을때 (앞에쪽이 있을때)
	if (inserted_it != li.begin())
	{
		list<pair<int, int>>::iterator inserted_it_before = inserted_it;
		inserted_it_before--; //들어간 위치앞쪽

		//앞쪽이랑 연결이 될때
		if ((*inserted_it_before).first + (*inserted_it_before).second == (*inserted_it).first)
		{
			(*inserted_it_before).second += (*inserted_it).second; //앞쪽이랑 합치고
			li.erase(inserted_it); //합쳐진거 지운다
		}
	}

	return;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	li.push_back(make_pair(1, 100000));
	it = li.begin();

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;

		//공간할당일때
		if (input.find("=") != string::npos)
		{
			int point1 = input.find("=");
			int point2 = input.find("(", point1 + 1);
			int point3 = input.find(")", point2 + 1);

			string var = input.substr(0, point1);
			string check_size_s = input.substr(point2 + 1, point3 - (point2 + 1));
			int check_size = stoi(check_size_s);

			Add(var, check_size);
		}

		//할당해제일때
		else if (input.find("free(") != string::npos)
		{
			int point1 = input.find("(");
			int point2 = input.find(")", point1 + 1);
			string var = input.substr(point1 + 1, point2 - (point1 + 1));

			Delete(var);
		}

		//출력일때
		else
		{
			int point1 = input.find("(");
			int point2 = input.find(")", point1 + 1);
			string var = input.substr(point1 + 1, point2 - (point1 + 1));

			cout << check[var].first << "\n";
		}
	}


	return 0;
}