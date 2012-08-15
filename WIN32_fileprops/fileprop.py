import win32api

def getFileProperties(filename):
  propNames = ('Comments', 'InternalName', 'ProductName',
      'CompanyName', 'LegalCopyright', 'ProductVersion',
      'FileDescription', 'LegalTrademarks', 'PrivateBuild',
      'FileVersion', 'OriginalFilename', 'SpecialBuild')
  props = {'FixedFileInfo': None, 'StringFileInfo': None, 'FileVersion': None}

  try:
    fixedInfo = win32api.GetFileVersionInfo(fname, '\\')
    props['FixedFileInfo'] = fixedInfo
    props['FileVersion'] = "%d.%d.%d.%d" % (fixedInfo['FileVersionMS'] / 65536,
    fixedInfo['FileVersionMS'] % 65536, fixedInfo['FileVersionLS'] / 65536,
    fixedInfo['FileVersionLS'] % 65536)

    # \VarFileInfo\Translation returns list of available (language, codepage)
    # pairs that can be used to retreive string info. We are using only the first pair.
    lang, codepage = win32api.GetFileVersionInfo(fname, '\\VarFileInfo\\Translation')[0]

    # any other must be of the form \StringfileInfo\%04X%04X\parm_name, middle
    # two are language/codepage pair returned from above

    strInfo = {}
    for propName in propNames:
      strInfoPath = u'\\StringFileInfo\\%04X%04X\\%s' % (lang, codepage, propName)
      ## print str_info
      strInfo[propName] = win32api.GetFileVersionInfo(fname, strInfoPath)

      props['StringFileInfo'] = strInfo
  except:
    pass

  return props
