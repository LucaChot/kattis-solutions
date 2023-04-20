#https://open.kattis.com/contests/xjhzmw/problems/recount

candidates = {}
name = str(input())
while name != "***":
  candidates[name] = 1 + candidates.setdefault(name, 0)
  name = str(input())

result = list(candidates.items())
result.sort(key=lambda x: x[1],reverse=True)
if result[0][1] == result[1][1]:
  print("Runoff!")
else:
  print(result[0][0])
