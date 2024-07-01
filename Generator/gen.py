from random import randint, shuffle

t = randint(1, 1000)
print(t)

while t:
    y = randint(100, 200)
    x = randint(1, y)
    print('%d %d' % (x, y))
    t -= 1