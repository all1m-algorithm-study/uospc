import random as r

txt = open(r"TC-PATH", 'wb')

def Write(content):
    print(content, end = '')
    txt.write(content.encode("utf-8"))

#chCount = r.randrange(3, 1000)
chCount = 1000
#memCount = r.randrange(2, min((chCount, 1000)))
memCount = 1000

Write("{0} {1}\n".format(chCount, memCount))

for i in range(0, chCount):
    Write("{0} ".format(r.randrange(1, 10000 + 1)))

Write("\n")

txt.close()