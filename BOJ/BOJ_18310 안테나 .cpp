#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int N;
	cin >> N;
	vector<int>v;
	int x,min_num=200000,sum=0;

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		v.push_back(x);//집이 있는 위치
	}
	sort(v.begin(), v.end());//정렬

	int result=0;
	int mid = (0 + v.size()) / 2;//중간 값을 찾는다.
	//중간값 활용
	//홀수면 가운데값 
	//짝수면 왼쪽오른쪽 비교
	if (v.size() % 2 == 1)
	{
		cout << v[mid];//가운데 값이므로
	}
	else {//짝수일 때 왼쪽과 오른쪽을 구분
		int left = mid - 1;
		sum = 0;
		for (int i = 0; i < v.size(); i++)
		{
			sum += abs(v[i] - v[left]);//왼쪽값의 합
		}
		int sum2 = 0;
		int right = mid;
		for (int i = 0; i < v.size(); i++)
		{
			sum2 += abs(v[i] - v[right]);//오른쪽값의 합
		}
		if (sum < sum2)//비교하고
		{
			cout << v[left];
		}
		else if(sum>sum2){
			cout << v[right];
		}
		else if (sum == sum2)//같을 경우 무조건 작은값부터니까 left출력
		{
			cout << v[left];
		}
	}

	return 0;

}
