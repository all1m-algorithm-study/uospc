B = int(input())
N = int(input())
C = list(map(int, input().split()))
if B - sum(C) >= 40:
    print("possible")
else:
    print("impossible")