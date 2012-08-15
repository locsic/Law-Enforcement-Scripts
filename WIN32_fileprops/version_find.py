import os
from shutil import copy2
from win32api import GetFileVersionInfo, LOWORD, HIWORD

my_path="C:\\"

def get_version(filename):
	try:
		info = GetFileVersionInfo(filename, "\\")
		ms = info['FileVersionMS']
		ls = info['FileVersionLS']
		return HIWORD (ms), LOWORD (ms), HIWORD (ls), LOWORD (ls)
	except:
		return 0,0,0,0
		
def file_recurse(path):
	for root, dirs, files in os.walk(path):
		for file in files:
			file = file.lower()
			if (file.count('.exe') or file.count('.dll') or file.count('.conf')):
				fullPathToFile=os.path.join(root,file)
				major,minor,subminor,revision=get_version(fullPathToFile)
				#print root
				#print "Filename: %s \t Version: %s.%s.%s.%s" % (file,major,minor,subminor,revision)
				if (major == 1 and minor == 0 and subminor == 0 and revision == 1):
					print root
					print "Filename: %s \t Version: %s.%s.%s.%s" % (file,major,minor,subminor,revision)
					
if __name__ == '__main__':
	file_recurse(my_path)
	#print ".".join ([str(i) for i in get_version(filename)])
	#if not os.path.exists(dir):
	#	os.makedirs(dir)