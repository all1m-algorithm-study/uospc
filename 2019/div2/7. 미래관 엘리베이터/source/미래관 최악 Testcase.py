txt = open(r"TC-PATH", 'wb')

def Write(content):
    print(content, end = '')
    txt.write(content.encode("utf-8"))

print("F = ", end='')
F = int(input())
print("E = ", end='')
E = int(input())
G = F

Write("{0} {1} {2}\n".format(F, E, G))
for e in range(0, E):
    Write("1 {0}\n".format(F))
    for i in range(1, F + 1):
        Write("{0} ".format(i))
    Write("\n")