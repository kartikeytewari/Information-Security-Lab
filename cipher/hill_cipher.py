# Name: Kartikey Tewari
# Roll No.: 17MI551
# Computer Science and Engineering (Dual Degree)
# National Institute of Technology, Hamirpur
import numpy as np

def encrypt (s, password):
    n=len(s)
    
    plain_text=np.arange(n).reshape(n,1)
    for i in range(0,n):
        plain_text[i][0]=ord(s[i])-ord('a')

    key=np.arange(n*n).reshape(n,n)
    for i in range(0,n):
        for j in range(0,n):
            key[i][j]=ord(password[(n*i)+j])-ord('a')

    encrypted_text=key.dot(plain_text)

    ans=""
    for i in range(0,n):
        # print(encrypted_text[i])
        ans+=chr((encrypted_text[i][0]%26)+ord('a'))
    
    return ans

def decrypt (s, password):
    n=len(s)

    encrypted_text=np.arange(n).reshape(n,1)
    for i in range(0,n):
        encrypted_text[i][0]=ord(s[i])-ord('a')

    key=np.arange(n*n).reshape(n,n)
    for i in range(0,n):
        for j in range(0,n):
            key[i][j]=ord(password[(n*i)+j])-ord('a')


    inverse_key=np.linalg.inv(np.matrix(key))
    plain_text=inverse_key.dot(encrypted_text)

    ans=""
    for i in range(0,n):
        ans+=chr((plain_text[i][0]%26)+ord('a'))

    return ans

print("Enter 1 for encryption")
print("Enter 2 for decryption")
a=int(input())

if (a==1):
    # encryption
    print("Enter string for encrypton:")
    s=str(input())
    n=len(s)
    print("Password should be " + str(n*n) + " letters long")
    print("Enter password: ")
    password=str(input())
    if (len(password)!=n*n):
        print("Programme terminating. Invalid length of string/password.")
    else:
        encrypted_string=encrypt(s,password)
        print("The encrypted string is: " + encrypted_string)

if (a==2):
    # decryption
    print("Enter string for decryption:")
    s=str(input())
    n=len(s)
    print("Enter password: ")
    password=str(input())
    if (len(password)!=n*n):
        print("Process termination. Invalid length of string.")
    else:
        decrypted_string=decrypt(s,password)
        print("The decrypted string is " + decrypted_string)

