n = int(input())
a = list(map(int,input().strip().split()))[:n]
# sum = 0
# for i in a:
# 	sum += i
print(int(n*(n+1)/2-sum(a)))
# print(sum)
 
# 1 2 3 4 5