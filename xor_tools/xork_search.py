import sys
#@Title:        XOR search
#@Date:         08/06/12
#@Version:      .1
#@Author:       Loc
#@Description:  Encodes a known keyword, then searches for its existence in a file to determine XOR key
#               KEY MASK: 0-255
#@TODO:         
#
def xor_search(key, *arg):
    #Per filea
    found_key = -100
    for x in range(len(arg[0])):
      b = bytearray(open(arg[0][x], 'rb').read())
      #b = bytearray(open('README.md', 'rb').read())
      #Calculate keyword xor key
      for k in range(0, 255):
        # To convert form a string to bytes/bytearray, you must use the string's encode() method
        # or provide an encoding to the constructor of the bytes or btyearrayobject
        bytkey = bytearray(key, 'ascii')
        #bytkey = map(ord,key)
        for e in range(len(bytkey)):
          bytkey[e] ^= k
          if(bytkey in b):
            found_key = k
            break
      if found_key < 0:
        print("XOR KEY: NOT FOUND, FILE:%s" % arg[0][x])
      else:
        print("XOR KEY: %s, FILE:%s" % found_key, arg[0][x])

if __name__=='__main__':
    if len(sys.argv) < 2:
        print('Usage: %s [KEYWORD] [FILE ...]' % sys.argv[0])
        sys.exit(1)
    xor_search(sys.argv[1], sys.argv[2:])
