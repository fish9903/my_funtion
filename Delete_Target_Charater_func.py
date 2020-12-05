s = input()

s_split1 = s.split()
s_split2 = s_split1

count = 0

for i in range(len(s_split1)):
    s_split2[i] = s_split1[i].strip('., ')

for i in range(len(s_split2)):
    if s_split2[i] == 'the':
        count += 1

print(count)
