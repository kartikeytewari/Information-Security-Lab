# Name: Kartikey Tewari
# Roll No.: 17MI551
# Computer Science and Engineering (Dual Degree)
# National Institute of Technology, Hamirpur
import numpy as np
import sympy
from sympy import Matrix

# encrypt the string s using the string password 
def encrypt (s, password):
    n=len(s)
    
    # make plain text matrix
    plain_text=np.arange(n).reshape(n,1)
    for i in range(0,n):
        plain_text[i][0]=ord(s[i])-ord('a')

    # make key matrix
    key=np.arange(n*n).reshape(n,n)
    for i in range(0,n):
        for j in range(0,n):
            key[i][j]=ord(password[(n*i)+j])-ord('a')

    # get encrypted matrix
    encrypted_text=key.dot(plain_text)

    # generate encrypted string
    ans=""
    for i in range(0,n):
        ans+=chr((encrypted_text[i][0]%26)+ord('a'))
    
    return ans


# decrypt s using password
def decrypt (s, password):
    n=len(s)

    # get encrypted matrix
    encrypted_text=np.arange(n).reshape(n,1)
    for i in range(0,n):
        encrypted_text[i][0]=ord(s[i])-ord('a')

    # get key matrix
    key=np.arange(n*n).reshape(n,n)
    for i in range(0,n):
        for j in range(0,n):
            key[i][j]=ord(password[(n*i)+j])-ord('a')


    # inverse key matrix to inverse_key (for generating decryption key)
    inverse_key=Matrix(key).inv_mod(26)
    np.inverse_key=np.array(inverse_key)
    plain_text=inverse_key*encrypted_text

    # generate plaintext string
    ans=""
    for i in range(0,n):
        ans+=chr((plain_text[i]%26)+ord('a'))

    return ans


# get choice
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
