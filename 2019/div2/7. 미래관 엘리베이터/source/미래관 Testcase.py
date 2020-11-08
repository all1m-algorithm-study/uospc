import random as r

txt = open(r"TC-PATH", 'wb')

def Write(content):
    print(content, end = '')
    txt.write(content.encode("utf-8"))

F = 15
#F = r.randrange(2, 15 + 1)
E = 4
#E = r.randrange(1, 4 + 1)
G = 14
#G = r.randrange(2, F + 1)

Write("{0} {1} {2}\n".format(F, E, G))

for i in range(0, E):
    n = r.randrange(2, F)
    ableToGo = r.sample(range(1, F + 1), n)
    ableToGo.sort()
    f = r.choice(ableToGo)
    Write("{0} {1}\n".format(f, n))
    for fToPr in ableToGo:
        Write("{0} ".format(fToPr))
    Write('\n')