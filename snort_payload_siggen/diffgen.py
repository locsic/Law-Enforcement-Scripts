import difflib
import operator
import sys

def diff_siggen(file1, file2):
  d = difflib.Differ()
  f1 = open('file1')
  f2 = open('file2')
  b1 = []
  b2 = []

  for n, lines in enumerate(zip(f1,f2)):
    if not (n % 100 == 0):
      b1.append(lines[0])
      b2.append(lines[1])
    else:
      diff = d.compare("".join(b1), "".join(b2))
      b1 = []
      b2 = []
      print ''.join(list(diff))
  diff = d.compare("".join(b1), "".join(b2))
  print ''.join(list(diff))
  f1.close()
  f2.close()

def sub_siggen(file1, file2):
  d = difflib.Differ()
  f1 = open('file1')
  f2 = open('file2')
  b1 = []
  b2 = []

  for n, lines in enumerate(zip(f1,f2)):
    if not (n % 100 == 0):
      b1.append(lines[0])
      b2.append(lines[1])
    else:
      diff = d.compare("".join(b1), "".join(b2))
      b1 = []
      b2 = []
      print ''.join(list(diff))
  diff = d.compare("".join(b1), "".join(b2))
  print ''.join(list(diff))
  f1.close()
  f2.close()

def xor(pw, str1):
  c = 0
  liste = []
  for k in xrange(len(str1)):
    if c > len(pw)-1:
      c = 0
      fi = ord(pw[c])
      c += 1
                                                              se = ord(str1[k])
                                                                      fin = operator.xor(fi, se)
                                                                              liste += [chr(fin)]
                                                                                  return liste

                                                                                def encrypt(passw, string):
                                                                                  ret = xor(passw, string)
                                                                                          print "Ecnrypted form:",
                                                                                              for k in ret:
                                                                                                print ord(k),

                                                                                                         def decrypt(passw, ret):
                                                                                                           finale = xor(passw, ret)
                                                                                                                   print "Decrypted form:",
                                                                                                                       print "".join(finale)


def xor_payload(data, key):
  from itertools import izip, cycle
  import base64
  decrypt = base64.decodestring(data)
  xored = ''.join(chr(ord(x) ^ ord(y)) for (x,y) in izip(data, cycle(key)))

if __name__ == '__main__':
