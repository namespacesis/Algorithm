from hashlib import sha256

S = str(input()) 
print(sha256(S.encode()).hexdigest())