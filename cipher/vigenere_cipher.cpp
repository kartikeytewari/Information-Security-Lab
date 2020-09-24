// Name: Kartikey Tewari
// Roll No.: 17MI551
// Computer Science and Engineering (Dual Degree)
// National Institute of Technology, Hamirpur
#include <bits/stdc++.h>
using namespace std;

string encrypt (string s, string password)
{
    int n=s.length();
    int m=password.length();

    string encrypted_string="";
    for (int i=0;i<=n-1;i++)
    {
        int a=int(s[i])-int('a');
        int b=int(password[i%m])-int('a');
        int c=(a+b)%26;
        c+=int('a');

        encrypted_string+=char(c);
    }

    return encrypted_string;
}

string decrypt (string s, string password)
{
    int n=s.length();
    int m=password.length();
    
    string plain_text="";
    for (int i=0;i<=n-1;i++)
    {
        int a=int(s[i])-int('a');
        int b=int(password[i%m])-int('a');
        int c=(a-b+26)%26;
        c+=int('a');

        plain_text+=c;
    }

    return plain_text;
}

int main()
{
    int toggle;
    cout << "Enter 1 for encryption" << endl;
    cout << "Enter 2 for decryption" << endl;
    cin >> toggle;


    if (toggle==1)
    {
        // encryption
        string s, password;
        cout << "Enter string for encryption: ";
        cin >> s;
        cout << "Enter password: ";
        cin >> password;

        string encrypted_string=encrypt(s,password);
        cout << "The encypted string is: " << encrypted_string << endl;
    }
    else
    {
        // decryption
        string s, password;
        cout << "Enter string for decryption: ";
        cin >> s;
        cout << "Enter password: ";
        cin >> password;
        
        string plain_text=decrypt(s,password);
        cout << "The decrypted string is: " << plain_text << endl;
    }

    return 0;
}