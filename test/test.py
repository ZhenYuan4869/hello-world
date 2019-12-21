
sum = 0
for i in range(1,n+1):
    h = 1
    for j in range (1,m+1):
        sum = sum+((-1)**(h))*i
        if j == m+1:
            j = 1
print(sum)