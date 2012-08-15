import pefile
import peutils
import os
import sys
from shutil import copy2

my_path="C:\\"
control=[]

def file_recurse(path):
	for root, dirs, files in os.walk(path):
		for file in files:
			file = file.lower()
			if (file.count('.exe')):
				fullPathToFile = os.path.join(root,file)
				print fullPathToFile
				try:
					pe = pefile.PE(fullPathToFile, fast_load=True)
					for section in pe.sections:
						print "SHA-1	hash: %s" % section.get_hash_sha1()
				except pefile.PEFormatError:
					print "dun goofed"

def is_packed(path):
	pe = pefile.PE(path, fast_load=True)
	return peutils.is_probable_packed(pe)
	
def generate_control_hash(path):
	list = []
	try:
		pe = pefile.PE(path, fast_load=True)
		for section in pe.sections:
			list.append(section.get_hash_sha1())
	catch pefile.PEFormatError:
		print "dun goofed"
	return list

if __name__ == '__main__':
	control = generate_control_hash(sys.argv[1])
	file_recurse(my_path)