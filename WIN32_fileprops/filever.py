import os
from win32api import GetFileVersionInfo, LOWORD, HIWORD

myPath="C:\\path\\to\\check"

def get_version(filename):
  try:
    info = GetFileVersionInfo(filename, "\\")
    ms = info['FileVersionMS']
    ls = info['FileVersionLS']
    return HIWORD (ms), LOWORD (ms), HIWORD (ls), LOWORD (ls)
  except:
    return 0,0,0,0

if __name__ == '__main__':
  filename = os.environ["COMSPEC"]
  print ".".join ([str (i) for i in get_version_number (filename)])
