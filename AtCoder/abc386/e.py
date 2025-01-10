import sys

sys.setrecursionlimit(3 * 10**5)
N, K = map(int, input().split())
A = list(map(int, input().split()))
ans = 0


def func(xor, idx, c):
    global ans
    if c == 0:
        ans = max(ans, xor)
        return
    if idx == N:
        return
    func(xor ^ A[idx], idx + 1, c - 1)
    func(xor, idx + 1, c)


if K <= N - K:
    func(0, 0, K)
else:
    all_xor = 0
    for i in range(N):
        all_xor ^= A[i]
    func(all_xor, 0, N - K)
print(ans)
