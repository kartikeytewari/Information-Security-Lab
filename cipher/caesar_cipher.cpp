// Name: Kartikey Tewari
// Roll No.: 17MI551
// Computer Science and Engineering (Dual Degree)
// National Institute of Technology, Hamirpur
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int offset;
    cout << "enter string= ";
    cin >> s;
    cout << "enter offser value= ";
    cin >> offset;
    // decryption_offset=-1*encryption_offset

    int n=s.length();
    for (int i=0;i<=n-1;i++)
    {
        int a=char(s[i]);
        a-=97;
        a=(a+offset+26)%26;
        a+=97;
        cout << char(a);
    }
    cout << endl;

    return 0;
}