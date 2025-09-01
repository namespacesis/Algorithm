lst,n= [], int(input())
for i in range(1,n+1):
    lst.append(i)
    if i % 6 == 0 or i == n: lst.append("Go!")

[print(lst[i], end = " ") for i in range(len(lst))]