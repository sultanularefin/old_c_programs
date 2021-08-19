#include <iostream>
#include <algorithm>
#include <iterator>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;

map<string, int> visit, strtLine;
map<string, vector<string> > graph;

int bfs(string start, string End)
{
	int i;

	queue<string>Q;

	visit[start] = 1;
	Q.push(start);

	cout << "start city: " << start << endl;

	while (Q.empty() == false)
	{
		string u, nxtCity;
		u = Q.front();
		Q.pop();

		if (u == End)
		{
			return visit[u];
		}
		int l = graph[u].size(), minCost = 99999;

		cout << "     edge city: ";
		for (i = 0; i<l; i++)
		{
			string v = graph[u][i];

			cout << v << " ( " << strtLine[v] << " )" << "      ";

			if (visit[v] != 1 && strtLine[v] < minCost)
			{
				nxtCity = v;
				minCost = strtLine[v];

			}

			visit[v] = 1;
		}
		Q.push(nxtCity);

		cout << endl << endl;


		cout << "next city: " << nxtCity << endl;
	}
	return -1;
}
int main()
{

	freopen("input.txt", "r", stdin);
	//   freopen("output.txt","w",stdout);


	int n, i, t = 0, x;

	cin >> n;

	for (i = 0; i<n; i++)
	{
		string city;
		int cost;

		cin >> city >> cost;


		strtLine[city] = cost;
	}

	cin >> n;

	for (i = 0; i<n; i++)
	{
		string city, city2;
		int cost;

		cin >> city >> city2 >> cost;

		graph[city].push_back(city2);
		graph[city2].push_back(city);

		visit[city] = -1;
		visit[city2] = -1;
	}


	string city, city2;

	cin >> city >> city2;

	bfs(city, city2);

	visit.clear();
	graph.clear();

	return 0;
}
