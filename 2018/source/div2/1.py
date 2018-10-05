###################################
# editorial_ppascii_xor_cipher.py #
# 2018-08-22 23:47:56             #
# tested with Python 3.7.0        #
# written by r4k0nb4k0n           #
###################################

from itertools import cycle

def isPrime(n):
  i = 2
  while i * i <= n:
    if n % i == 0:
      return False
    i += 1
  return True

def xorStrings(s, t):
  return bytes([a ^ b for a, b in zip(s, cycle(t))])

def main():
  key = ""

  for i in range(32, 127):
    if isPrime(i) is True:
      key += str(chr(i))

  print(key)
  key = key.encode('ascii') # key = '%)+/5;=CGIOSYaegkmq'

  encrypted = None
  with open('./encrypted.txt', 'rb') as f:
    encrypted = f.read()

  decrypted = xorStrings(encrypted, key)

  print(decrypted.decode('ascii'))

if __name__ == "__main__":
  main()
