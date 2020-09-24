// Name: Kartikey Tewari
// Roll No.: 17MI551
// Computer Science and Engineering (Dual Degree)
// National Institute of Technology, Hamirpur
#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<char,char> subs_rule;
    cout << "Enter substitution rule:" << endl;
    int n;
    cout << "enter number of rules= ";
    cin >> n;

    // get rule for cipher
    for (int i=0;i<=n-1;i++)
    {
        char a, b;
        cout << "enter base character= ";
        cin >> a;
        cout << "enter final character= ";
        cin >> b;
        subs_rule[a]=b;
    }

    string s;
    cout << "enter string= ";
    cin >> s;

    // perform encryption/decryption
    for (int i=0;i<=(int)s.length()-1;i++)
    {
        for (auto it=subs_rule.begin();it!=subs_rule.end();it++)
        {
            if (s[i]==it->first)
            {
                s[i]=it->second;
            }
        }
    }

    cout << "Final Text= " << s << endl;
    return 0;
}