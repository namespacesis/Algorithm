x = input()
y = ''
for i in x:
    if i in 'ABC':
        y += chr(ord(i) +23)
    else:
        y += chr(ord(i) - 3)
print(y)