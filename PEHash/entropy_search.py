import pefile
import peutils
import os
import sys
from shutil import copy2
from win32api import GetFileVersionInfo, LOWORD, HIWORD

my_path="C:\\"
control=dict()
hits=[]
output="PE_Output\\"

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
			if (file.count('.exe') or file.count('.dll')):
				fullPathToFile = os.path.join(root,file)
				print fullPathToFile
				try:
					pe = pefile.PE(fullPathToFile, fast_load=True)
					#Think of a more effecient/effective way of doing this
					#because this is downright dirty
					counter = 0
					for section in pe.sections:
						try:
							if(control[section.Name]-.4 <= section.get_entropy() <= control[section.Name]+.4):
								counter += 1
						except KeyError:
							print "It's ok about keyerror"
					major,minor,subminor,revision=get_version(fullPathToFile)
					if (major == 1 and minor == 0 and subminor == 0 and revision == 1):
						print "Filename: %s \t Version: %s.%s.%s.%s" % (file,major,minor,subminor,revision)
						counter +=1
					if counter == 3:
						hits.append(fullPathToFile)
				except pefile.PEFormatError:
					print "dun goofed"

def control_entropy(path):
	try:
		pe = pefile.PE(path, fast_load=True)
		for section in pe.sections:
			if("text" in section.Name or "rsrc" in section.Name):
				control[section.Name] = section.get_entropy()
				#control.append(section.Name +','+str(section.get_entropy()))
				print (section.Name)
				print ('Entropy: %f (min=0.0, max=8.0)' % section.get_entropy())
		#print "text" in control[0]
		print control
	except pefile.PEFormatError:
		print "dun goofed"
	
def test_entropy(path):
	try:
		pe = pefile.PE(path, fast_load=True)
		for section in pe.sections:
			print (section.Name)
			print ('Entropy: %f (min=0.0, max=8.0)' % section.get_entropy())
	except pefile.PEFormatError:
		print "dun goofed"

def copy_floppy(paths):
	if not os.path.exists(output):
		os.makedirs(output)
	for item in hits:
		try:
			copy2(item, output)
		except:
			print "same file?"
			print item

if __name__ == '__main__':
	control_entropy(sys.argv[1])
	output = sys.argv[2]
	file_recurse(my_path)
	copy_floppy(hits)
	f = open(output+"hits.txt", 'wb')
	for item in hits:
		f.write(item)
		f.write('\n')
	f.close()