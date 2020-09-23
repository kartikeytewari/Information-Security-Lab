# Name: Kartikey Tewari
# Roll No.: 17MI551
# Computer Science and Engineering (Dual Degree)
# National Institute of Technology, Hamirpur
import numpy as np

def encrypt (s, password):
    

def decrypt (s, password):
    print("string is " + s)
    print("password is " + password)

    return "hello"

print("Enter 1 for encryption")
print("Enter 2 for decryption")
a=int(input())

if (a==1):
    # encryption
    print("Enter string for encrypton:")
    s=str(input())
    n=len(s)
    print("Password should be " + str(n*3) + " letters long")
    print("Enter password: ")
    password=str(input())
    if (len(password)!=3*n):
        print("Programme terminating. Invalid length of string/password.")
    else:
        encrypted_string=encrypt(s,password)
        print("The encrypted string is " + encrypted_string)

if (a==2):
    # decryption
    print("Enter string for decryption:")
    s=str(input())
    n=len(s)
    print("Enter password: ")
    password=str(input())
    if (len(password)!=3*n):
        print("Process termination. Invalid length of string.")
    else:
        decrypted_string=decrypt(s,password)
        print("The decrypted string is " + decrypted_string)

