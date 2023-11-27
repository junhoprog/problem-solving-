#include<iostream>
#include<vector>
#include<sstream>
#include<map>
#include<algorithm>
using namespace std;

int devide_time(vector<string>time,int k)//�ð��� :�������� �ú� ������ ����
{
	string s="";
	int hour;
	int minute;
	int div_time;
	for (int i = 0; i < time[k].size(); i++)//�ҷ��� �ð� �����ŭ �ҷ���
	{
		if (time[k][i] == ':')//:�� ������
		{
			for (int j = 0; j < i; j++)
			{
				s += time[k][j];//�� �������������� i�� �������� s�� �߰�
			}
			hour = stoi(s);//string�� int�� ��ȯ�ؼ� ���� �־���
			//cout << hour;
			s = "";
			for (int j = i + 1; j < time[k].size(); j++)
			{
				s += time[k][j];//������ Ȯ���ؼ� : ���� ���� s�� ����
			}
			minute = stoi(s);
			break;//:���İ� �ʿ��������
		}

	}
	div_time = (60 * hour) + minute;//div_time�� �� ���� ����
	return div_time;
}

vector<int> solution(vector<int>fees, vector<string>records)
{
	vector<int>answer;
	int base_time = fees[0];
	int base_fee = fees[1];
	int after_time = fees[2];
	int after_fee = fees[3];

	vector<string>time;
	vector<string>num;
	vector<string>inout;
	map<string, int>m;//in�̸� ���� out�̸� ��� �� ����
	map<string, int>sum;//���� �� ���Ŀ� �� ���ð�

	string temp;
	int cnt = 0;
	for (int i = 0; i < records.size();i++) {
		stringstream ss(records[i]);//���ڿ� �ڸ��� �Լ��� records[i]�� �ִ� ���ڿ��� ����������� ������ ss�� ����
		while (ss >> temp)//ss���� ����������� ������ ���ڿ����� temp�� �ְ� �� temp�� ���
		{
			if (cnt == 0)
			{
				time.push_back(temp);//�ð��� ���
				cnt++;
			}
			else if (cnt == 1)
			{
				num.push_back(temp);//��ȣ�� ���
				cnt++;
			}
			else if (cnt == 2)
			{
				inout.push_back(temp);// ��,�� Ȯ��
				cnt = 0;
			}
		}

	}
	int div_time;
	vector<string>list;
	vector<string>uniq;
	for (int i = 0; i < num.size(); i++)
	{
		if (i == 0)
		{
			uniq.push_back(num[i]);//uniq���ڸ� ã��
		}
		else {
			for (int j = 0; j < uniq.size(); j++)
			{
				if (uniq[j] == num[i])//uniq���ڿ� ���� �� �ִٸ� �ݺ� ����
				{
					break;
				}
				else{
					if (j == uniq.size() - 1)//���� �������� ��
					{
						uniq.push_back(num[i]);//uniq���ڷ� ����
					}
				}
				
			}
		}
	}
	sort(uniq.begin(), uniq.end());
	
	for (int i = 0; i < records.size(); i++)
	{
		div_time=devide_time(time, i);//������ �ð��� ��Ƽ�
		if (inout[i] == "IN")
		{
			m[num[i]] = div_time;
			list.push_back(num[i]);
		}

		else if (inout[i] == "OUT")
		{
			for (int q = 0; q < list.size(); q++)
			{
				if (list[q] == num[i])
				{
					list.erase(list.begin() + q);
				}
			}

			m[num[i]] = div_time - m[num[i]];
			sum[num[i]] += m[num[i]];//0000:34����
			m.erase(num[i]);//�ش� Ű �����
		}
	}

	while (!m.empty())//������� ������ �ݺ�
	{
		for (int j = 0;j<list.size(); j++)//in���ְ� out ���� ��
		{
			m[list[j]] = 1439 - m[list[j]];
			sum[list[j]] += m[list[j]];
			m.erase(list[j]);

		}
	}
	
	int result = 0;
	vector<int>v;

	
	for (int j = 0; j < uniq.size(); j++) {
		result = 0;
		if (sum[uniq[j]] <= base_time)
		{
			result += base_fee;
		}
		else {
			sum[uniq[j]] -= base_time;
			result += base_fee;

			if (sum[uniq[j]] % after_time == 0)
			{
				result += (sum[uniq[j]] / after_time) * after_fee;
				//�ø��� �ʿ���� ��
			}
			else {//�ø��ϱ����� 
				result += ((sum[uniq[j]] / after_time) + 1) * after_fee;
			}
		}
		v.push_back(result);
	}
	answer = v;
	return answer;

}

int main()
{
	vector<string>records;
	vector<int>fees;
	records.push_back("05:34 5961 IN");
	records.push_back("06:00 0000 IN");
	records.push_back("06:34 0000 OUT");
	records.push_back("07:59 5961 OUT");
	records.push_back("07:59 0148 IN");
	records.push_back("18:59 0000 IN");
	records.push_back("19:09 0148 OUT");
	records.push_back("22:59 5961 IN");
	records.push_back("23:00 5961 OUT");

	fees.push_back(180);
	fees.push_back(5000);
	fees.push_back(10);
	fees.push_back(600);
	vector<int>temp;
	temp=solution(fees, records);
	for (int i = 0; i < temp.size(); i++)
	{
		cout << temp[i] << " ";
	}
}
