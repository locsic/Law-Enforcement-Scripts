import sys,binascii
#@Title:        XOR File
#@Date:         08/06/12
#@Version:      .1
#@Author:       Loc
#@Description:  Encode/Decode a file using a XOR with a mask.
#               MASK: 0-255
#@TODO:         
#
key = ""
ignorek = ""
def decode_filelist(*arg):
    for x in range(len(arg[0])):
      b = bytearray(open(arg[0][x], 'rb').read())
      for i in range(len(b)):
        if not b[i] == ord(ignorek):
          b[i] ^= binascii.unhexlify(sys.argv[1])
        #else: we don't do anything
      #Assuming the filename has a dot
      open(arg[0][x].split('.')[0]+".xcoded",'wb').write(b)

if __name__=='__main__':
    if len(sys.argv) < 2:
        print('Usage: %s [MASK] [IGNORE] [FILE ...]' % sys.argv[0])
        sys.exit(1)
    key = binascii.unhexlify(sys.argv[1])
    ignorek = binascii.unhexlify(sys.argv[2])
    decode_filelist(sys.argv[2:])
