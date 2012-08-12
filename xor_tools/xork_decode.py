import sys
#@Title:        XOR File
#@Date:         08/06/12
#@Version:      .1
#@Author:       Loc
#@Description:  Encode/Decode a file using a XOR with a mask.
#               MASK: 0-255
#@TODO:         
#
def decode_filelist(*arg):
    for x in range(len(arg)):
      b = bytearray(open(arg[x], 'rb').read())
      for i in range(len(b)):
        b[i] ^= sys.argv[1]
      open(sys.argv[2].split('.')[0]+".xcoded",'wb').write(b)

if __name__=='__main__':
    if len(sys.argv) < 2:
        print('Usage: %s [MASK] [FILE ...]' % sys.argv[0])
        sys.exit(1)
    decode_filelist(sys.argv[1:])
