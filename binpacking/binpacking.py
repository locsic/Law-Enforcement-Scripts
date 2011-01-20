# binpacking.py
#@Author Loc Nguyen
#@Date 01/14/11
#@Description
#@Version 0.1 01/14/11 - First Fit Decreasing
#Recursively collect a listing of all files and directories within an input path
#House in data structure
#Open and initate a base zip file [date]-[counter].zip
#While data structure is !empty
#Sort list from largest file to smallest
#Iterate through list
#If [zip size + i.size] <= input.capacity
#   append file to the zip
#   remove file path from data structure
#One iteration per zip
#Zipfile counter++
#open and initiate a new zip file [date]-[counter].zip
#
#-Retain Metadata information
#
#Note does not do empty directories


import os, glob, zipfile, sys
import time
strftime = time.strftime
zipMap = []
zipSize = 0;

def addFolderToZip(myZipFile, folder):
    folder = folder.encode('ascii') #convert path to ascii for ZipFile Method
    for file in glob.glob(folder+"/*"):
        if os.path.isfile(file):
            print file
            myZipFile.write(file, os.path.basename(file), zipfile.ZIP_DEFLATED)
        elif os.path.isdir(file):
            addFolderToZip(myZipFile, file)

def createZipFile(filename, files, folders):
    curTime = strftime("__%Y_%m_%d", time.localtime())
    filename = filename+curTime;
    print filename
    zipFilename = utils.getFileName("files", filename+".zip")
    myZipFile = zipfile.ZipFile( zipFilename, "w" ) # Open the zip file to write
    for file in files:
        file = file.encode('ascii') #convert path to ascii for zipfile method
        if os.path.isfile(file):
            (filepath, filename) = os.path.split(file)
            myZipFile.write( file, filename, zipfile.ZIP_DEFLATED )
    for folder in folders:
        addFolderToZip(myZipFile, folder)
    myZipFile.close()
    return (1, zipFilename)

'''Return a list of file names found in directory 'dir_name'
If 'subdir' is True, recursively access subdirectories under 'dir_name'.
Additional arguments, if any, are file extensions to match filenames. Matches
    file names are added to the list.
If there are no additional arguments, all files found in the directory are
    added to the list.
Example usage: fileList = dirEntries(r'H:\TEMP', False, 'txt', 'py')
    Only files with 'txt' and 'py' extensions will be added to the list.
Example usage: fileList = dirEntries(r'H:\TEMP', True)
    All files and all the files in subdirectories under H:\TEMP will be added
    to the list.
'''
def dirEntries(dir_name, subdir, *args):
    fileList = []
    for file in os.listdir(dir_name):
        dirfile = os.path.join(dir_name, file)
        if os.path.isfile(dirfile):
            if len(args) == 0:
                fileList.append(dirfile)
            else:
                if os.path.splitext(dirfile)[1][1:] in args:
                    fileList.append(dirfile)
        # recursively access file names in subdirectories
        elif os.path.isdir(dirfile) and subdir:
            print "Accessing directory:", dirfile
            fileList += dirEntries(dirfile, subdir, *args)
    return fileList


##########################################################
# MERGE SORT
##########################################################
def mergesort(list):
    if len(list) < 2:
        return list
    else:
        middle = len(list) / 2
        left = mergesort(list[:middle])
        right = mergesort(list[middle:])
        return merge(left, right)

def merge(left, right):
    result = []
    i, j = 0, 0
    while i < len(left) and j < len(right):
        # Get filesizes
        #leftFileSize = os.stat(left[i])[stat.ST_SIZE]
        leftFileSize = os.path.getsize(left[i])
        #rightFileSize = os.stat(right[i])[stat.ST_SIZE]
        rightFileSize = os.path.getsize(right[i])
        if leftFileSize <= rightFileSize:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    result += left[i:]
    result += right[j:]
    return result

#Generate zip file lists, append to global zipmap, remove files from fileList
def generateZipMapRec(fileList):
    print len(zipMap)
    if not fileList:
        return ""
    else:
        #tempList = list(fileList)
        zipList = []
        currentZipSize = 0;
        for file in fileList:
            print (os.path.getsize(file) + currentZipSize)
            print zipSize
            if (os.path.getsize(file) + currentZipSize) < int(zipSize):
                #append to zipList
                zipList.append(file)
                currentZipSize += os.path.getsize(file)
                fileList.remove(file)
        zipMap.append(zipList)
        return generateZipMapRec(fileList)

"""
'fileList' is a list of file names - full path each name
'archive' is the file name for the archive with a full path
"""
def makeArchive(fileList, archive):
    curTime = strftime("_%Y_%m_%d_", time.localtime())
    filename = archive+"_"+curTime
    print filename
    try:
        a = zipfile.ZipFile(filename + ".zip", 'w', zipfile.ZIP_DEFLATED)
        for f in fileList:
            f = f.encode('ascii') #convert path to ascii for zipfile method
            print "archiving file %s" % (f)
            a.write(f)
        a.close()
        return True
    except: return False

if __name__ == '__main__':
    folder = sys.argv[1]
    zipname = sys.argv[2]
    zipSize = sys.argv[3]
    #generateZipMapRec(mergesort(dirEntries(folder, True)))
    generateZipMapRec(dirEntries(folder, True))
    cur_idx = 0
    for zip in zipMap:
        makeArchive(zip, str(cur_idx) + "_" + zipname)
        cur_idx += 1
    #makeArchive(dirEntries(folder, True), zipname)
