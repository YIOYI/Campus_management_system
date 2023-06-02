#include <iostream>
#include <set>
#include <deque>
#include <algorithm>
#include <unordered_map>
#include <cstdlib>
#include <time.h>
#include "Building.h"

struct pair_hash
{
	template<class T1, class T2>
	std::size_t operator() (const std::pair<T1, T2>& p) const
	{
		auto h1 = std::hash<T1>{}(p.first);
		auto h2 = std::hash<T2>{}(p.second);
		return h1 ^ h2;
	}
};

bool cmp1(std::pair<int, int> lhs, std::pair<int, int> rhs)
{
	return lhs.second < rhs.second;
}

vector<pair<int, int>> Building::Dijkstra(Map& mp)
{
	std::set<int> st;
	vector<std::pair<int, int>> ret(Building_Number, make_pair(0, 0));
	vector<int> dist(Building_Number, INT_MAX);
	std::deque<std::pair<int, int>> path; //第一个是终点id,第二个是两点之间距离
	st.insert(id);
	ret[0] = { id,0 };
	ret[id] = { id,0 };
	dist[id] = 0;
    for (auto a : mp.Get_i_Building(id).Roads)
    {
        path.push_back(make_pair(a, mp.Get_i_Building(id).distance[a]));
        ret[a] = {id, mp.Get_i_Building(id).distance[a]};
        dist[a] = mp.Get_i_Building(id).distance[a];
    }
//	partial_sort(path.begin(), path.begin() + 1, path.end(), cmp1);
//	auto tmp = path.front();
//	ret[tmp.first] = { id, tmp.second };
//	dist[tmp.first] = tmp.second;
	

	while (!path.empty())
	{
		partial_sort(path.begin(), path.begin()+1, path.end(), cmp1);

		auto tmp = path.front();
		path.pop_front();
		if (st.count(tmp.first))
			continue;

		st.insert(tmp.first);
		for (auto road : mp.Get_i_Building(tmp.first).Roads)
		{
			if (!st.count(road) && dist[road] > dist[tmp.first] + mp.Get_i_Building(tmp.first).distance[road])
			{
				dist[road] = dist[tmp.first] + mp.Get_i_Building(tmp.first).distance[road];
				ret[road] = { tmp.first, mp.Get_i_Building(tmp.first).distance[road] };
				path.push_back({ road, dist[road] });
			}
		}
	}

	return ret;
}

int Building::Calculate_length(int end, vector<pair<int, int>>& tree)
{
	int ret = 0;
	int prev = tree[end].first;
	int next = end;

	while (next != id)
	{
		ret += tree[next].second;
		next = prev;
		prev = tree[next].first;
	}

	return ret;
}

deque<int> Building::ShortestPath(int end, Map& mp)
{
	auto tree = mp.Get_i_Building(id).Dijkstra(mp);
	auto ret = ShortestPath(end, tree);

	return ret;
}

deque<int> Building::ShortestPath(int end, vector<pair<int, int>>& tree)
{
	deque<int> ret;
	ret.push_front(end);
	int prev = tree[end].first;
	int next = end;

	while (next != id)
	{
		ret.push_front(prev);
		next = prev;
		prev = tree[next].first;
	}

	return ret;
}

/**
 * @brief 计算经过一组点的路程
 * @param road 一组建筑点
 * @param dists 一对点之间的路程
 * @return 得到的路程
*/
int Calculate_Score(vector<int> road, unordered_map<pair<int, int>, int, pair_hash>& dists);

/**
 * @brief 将种群繁殖到指定数量
 * @param race 种群数组
 * @param dists 一对点之间的路程
 * @param size 种群大小
*/
void Reproduce(vector<pair<vector<int>, int>>& race, unordered_map<pair<int, int>, int, pair_hash>& dists, const int size);

/**
 * @brief 交叉操作
 * @param first 第一个路径
 * @param second 第二个路径
 * @return 交叉完毕的路径
*/
vector<int> Cross(vector<int> first, vector<int> second);

/**
 * @brief 变异操作，将数组内随即一对建筑兑换
 * @param individual 源个体
 * @return 变异后的个体
*/
vector<int> Mutations(vector<int> individual);

bool cmp2(pair<vector<int>, int>& lhs, pair<vector<int>, int>& rhs)
{
	return lhs.second < rhs.second;
}

static int count1 = 0;
constexpr int time1 = 100;

deque<int> Building::ShortestPath(vector<int> point, Map& mp)
{
	unordered_map<int, vector<pair<int, int>>> trees;
	unordered_map<pair<int, int>, int, pair_hash> dists;
	point.push_back(id);
	for (auto point : point)
		trees[point] = mp.Get_i_Building(point).Dijkstra(mp);
	for (int i = 0; i < point.size(); i++)
		for (int j = 0; j < point.size(); j++)
			dists[{point[i], point[j]}] = mp.Get_i_Building(point[i]).Calculate_length(point[j], trees[point[i]]);
	point.insert(point.begin(), id);

	count1 = 0;
	int min_score = INT_MAX;
	constexpr int size = 10000;
	vector<pair<decltype(point), int>> race;
	race.push_back({ point, Calculate_Score(point, dists) });

	srand((unsigned)time(NULL));
	while (race.size() < size/2)
	{
		vector<int> tmp(point.begin() + 1, point.end() - 1);
		vector<int> newind;
		newind.push_back(id);
		while (tmp.size())
		{
			int sel = rand() % tmp.size();
			newind.push_back(tmp[sel]);
			tmp.erase(tmp.begin() + sel);
		}
		newind.push_back(id);
		race.push_back({ newind, Calculate_Score(newind, dists) });
	}
	sort(race.begin(), race.end(), cmp2);
	
	while (count1 <= time1)
	{
		Reproduce(race, dists, size);
		auto mid = race.begin() + race.size() / 2;
		partial_sort(race.begin(), mid, race.end(), cmp2);
		race.erase(mid, race.end());
		if (race[0].second < min_score)
		{
			min_score = race[0].second;
			count1 = 0;
		}
		else
			count1++;
		std::cout << race[0].second << " ";
	}

	deque<int> ret;
	auto& shortest = race[0].first;
	for (int i = 0; i < shortest.size() - 1; i++)
	{
		auto tmp = mp.Get_i_Building(shortest[i]).ShortestPath(shortest[i + 1], trees[shortest[i]]);
		tmp.pop_back();
		ret.insert(ret.end(), tmp.begin(), tmp.end());
	}
	ret.push_back(id);

	return ret;
}

int Calculate_Score(vector<int> road, unordered_map<pair<int, int>, int, pair_hash>& dists)
{
	int ret = 0;

	for (int i = 0; i < road.size() - 1; i++)
		ret += dists[{road[i], road[i + 1]}];

	return ret;
}

void Reproduce(vector<pair<vector<int>, int>>& race, unordered_map<pair<int, int>, int, pair_hash>& dists, const int size)
{
	srand((unsigned)time(NULL));

	for (int i = 0; i < size/4; i++)
	{
		auto newind = Cross(race[i].first, race[size/2-i-1].first);
		race.push_back({ newind, Calculate_Score(newind, dists) });
	}

	while (race.size() < size)
	{
			int sel = rand() % race.size();
			auto newind = Mutations(race[sel].first);
			int a = 0;
			if (count1 > time1/2)
				a = 20;
			for (int i = 0; i < a; i++)
				newind = Mutations(newind);
			race.push_back({ newind, Calculate_Score(newind, dists) });
	}
}

vector<int> Mutations(vector<int> individual)
{
	srand((unsigned)time(NULL));

	vector<int> ret(individual);
	int a = rand() % (individual.size() - 2) + 1;
	int b = rand() % (individual.size() - 2) + 1;
	swap(ret[a], ret[b]);

	return ret;
}

vector<int> Cross(vector<int> first, vector<int> second)
{
	vector<int> father(first.begin() + 1, first.end() - 1);
	vector<int> mather(second.begin() + 1, second.end() - 1);

	srand((unsigned)time(NULL));
	int r1 = rand() % father.size();
	int r2 = rand() % father.size();
	int s = min(r1, r2);
	int e = max(r1, r2);
	for (int i = s; i < e; i++)
	{
		int tmp = father[i];
		father[i] = mather[i];
		mather[i] = tmp;
		auto it1 = find(father.begin(), father.end(), father[i]);
		if ((it1 - father.begin()) == i)
			it1 = find(it1 + 1, father.end(), father[i]);
		if (it1 != father.end())
			*it1 = mather[i];
		auto it2 = find(mather.begin(), mather.end(), mather[i]);
		if ((it2 - mather.begin()) == i)
			it2 = find(it2 + 1, mather.end(), mather[i]);
		if (it2 != mather.end())
			*it2 = father[i];
	}
	vector<int> ret;
	ret.push_back(first[0]);
	ret.insert(ret.end(), father.begin(), father.end());
	ret.push_back(first[0]);

	return ret;
}
