#include <string>
#include <vector>
#include<map>
#include<set>
#include<iostream>
#include<algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) { //v원소는 pair이기때문에  나올 매개변수또한 pair로

	return a.second > b.second;//두번째 값만 비교해주면됨
}

int solution(int k, vector<int> tangerine) {
	int answer = 0;
	map<int, int>m;//key가 나온 개수만큼 value를 증가시킬것임
	set<int>s;
	int size = tangerine.size();

	for (int i = 0; i < size; i++)
	{
		m[tangerine[i]]++;//나온 개수만큼 증가
		s.insert(tangerine[i]);//집합을 이용해서 유니크한 것들만 고름
	}
	vector<pair<int, int>>v;//m에 있는 값을 vector로 옮겨서 이후 sort할 수 있게 만듦
	for (auto i : s) {//집합 내부 원소를 가져오기 위해 
		v.push_back({ i,m[i] });
	}
	sort(v.begin(), v.end(), compare);
	
	int cnt = 0;
	for (int i = 0; i < v.size(); i++)//모든 벡터를 확인하는데
	{
		cnt++;//접근한 횟수
		if (k-v[i].second > 0)//갯수만큼빼도 0보다 크면 k를 갯수만큼빼기만하고
		{
			k -= v[i].second;
		}
		else {//더 작거나 같으면 끝냄
			break;
		}
	}
	answer = cnt;//횟수가 즉 답
	return answer;
}
int main()
{
	vector<int> arr = {1, 3, 2, 5, 4, 5, 2, 3};
	cout<<solution(4,arr);
	return 0;
}

/*
k개를 골라 상자하나에 담아 판매
크기별로 분류했을 때 서로 다른 종류의 수 최소화
if 6개 판매하고싶다면 크기가 1,4인 귤제외하고 여섯개의 귤을 상자에 담아 귤의 크기가 2,3,5만듦
1 22 33 4 55
//
*/