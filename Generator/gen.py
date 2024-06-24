from random import randint, shuffle

t = randint(1, 1)

print(t)

def work():
    n = randint(20, 20)
    print(n)
    for i in range(n):
        x, y = randint(-1000000000, 1000000000), randint(-1000000000, 1000000000)
        print('%d %d' % (x, y))
while t:
    work()
    t -= 1