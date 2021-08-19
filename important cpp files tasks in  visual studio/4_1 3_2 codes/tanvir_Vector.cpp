#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector< pair<string, int> >v;
int main()
{
	string ss = "mississippi";
	for (int i = 0; i<ss.size(); i++)
	{
		v.push_back({ ss.substr(i), i });
	}

	
	sort(v.begin(), v.end());
	for (int i = 0; i<v.size(); i++)
	{
		cout << v[i].second << v[i].first;
		
	}
	return 0;
}