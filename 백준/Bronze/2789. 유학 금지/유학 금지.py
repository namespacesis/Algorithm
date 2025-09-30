data = ['C', 'A', 'M', 'B', 'R', 'I', 'D', 'G', 'E']

value = input()
for i in range(len(value)) :
  if value[i] not in data :
    print(value[i], end='')