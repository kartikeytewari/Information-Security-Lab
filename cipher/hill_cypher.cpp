// Name: Kartikey Tewari
// Roll No.: 17MI551
// Computer Science and Engineering (Dual Degree)
// National Institute of Technology, Hamirpur
#include <bits/stdc++.h>
using namespace std;

string encrypt (string s, string password)
{
    int n=s.length();
    int plain_text[n];
    for (int i=0;i<=n-1;i++)
    {
        plain_text[i]=int(s[i])-int('a');
    }

    int key[n][n];
    for (int i=0;i<=n-1;i++)
    {
        for (int j=0;j<=n-1;j++)
        {
            int location=(n*i)+j;
            key[i][j]=int(password[location])-int('a');
        }
    }

    // (key*plain_text)%26=cipher_text
    int cipher_text[n];
    for (int i=0;i<=n-1;i++)
    {
        cipher_text[i]=0;
        for (int j=0;j<=n-1;j++)
        {
            cipher_text[i]+=key[i][j]*plain_text[j];
        }
        cipher_text[i]%=26;
    }

    string ans="";
    for (int i=0;i<=n-1;i++)
    {
        cout << "cipher_text= " << cipher_text[i] << endl;
        ans+=char(cipher_text[i]+97);
    }

    return ans;
}

string decrypt (string s, string password)
{
    int n=s.length();
    int cipher_text[n];
    for (int i=0;i<=n-1;i++)
    {
        cipher_text[i]=int(s[i])-int('a');
    }

    int key[n][n];
    for (int i=0;i<=n-1;i++)
    {
        for (int j=0;j<=n-1;j++)
        {
            int location=(i*n)+j;
            key[i][j]=int(s[location])-int('a');
        }
    }

    int inverse_key[n][n];
    // generate inverse_key 

    int plain_text[n];
    for (int i=0;i<=n-1;i++)
    {
        plain_text[i]=0;
        for (int j=0;j<=n-1;j++)
        {
            plain_text[i]+=inverse_key[i][j]*cipher_text[j];
        }
        plain_text[i]%=26;
    }

    string ans="";
    for (int i=0;i<=n-1;i++)
    {
        ans+=char(plain_text[i]+97);
    }
    return ans;
}

int main()
{
    int enc_bit;
    cout << "Enter 1 for encryption" << endl;
    cout << "Enter 2 for decryption" << endl << endl;
    cin >> enc_bit;

    if (enc_bit==1)
    {
        // encryption
        string s, password;
        cout << "Enter string for enryption: ";
        cin >> s;
    
        cout << "Enter a password: " << endl;
        cout << "Password length should be " << s.length()*3 << " characters: ";
        cin >> password;
        if (password.length()!=3*s.length())
        {
            cout << "Incorrect password length. System terminating." << endl;
        }
        else
        {
            cout << "Encrypted string: " << encrypt(s,password) << endl;
        }
    }
    else
    {
        // decrption
        string s, password;
        cout << "Enter the string to decrypt= ";
        cin >> s;
        cout << "Enter the password= ";
        cin >> password;

        if (password.length()!=3*s.length())
        {
            cout << "Incorrect password length. System Terminating." << endl;
        }
        else
        {
            cout << "Decrypted String: " << decrypt(s,password) << endl;
        }
    }

    return 0;
}