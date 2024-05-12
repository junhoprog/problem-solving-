#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm> 
using namespace std;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    string boom;
    cin >> boom;
    stack<char>st;

    for (int i = 0; i < s.length(); i++)
    {
        st.push(s[i]);

        if (s[i] == boom[boom.size() - 1] && st.size() >= boom.size())
        {
            string temp = "";
            for (int j = 0; j < boom.length(); j++)
            {
                temp += st.top();
                st.pop();
            }
            reverse(temp.begin(), temp.end());

            if (temp != boom)
            {
                for (int j = 0; j < temp.length(); j++)
                {
                    st.push(temp[j]);
                }
            }
        }
    }

    string answer;
    if (st.empty())
    {
        cout << "FRULA";
    }
    else {
        int size = st.size(); 
        for (int i = 0; i < size; i++)
        {
            answer += st.top();
            st.pop();
        }
        reverse(answer.begin(), answer.end());
        cout << answer;
    }
    return 0;
}
