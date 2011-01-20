import csv
import os
import sys

# Dummy CSV Generator
#
# @Author Loc Nguyen
# @Date 10/21/10
# @Input Directory
# @Output CSV containing dir/files, file size
# @Description For use with the dummy file generator

# Do a line by line scan through the directory listing
#Change listing.csv to possible [date]-dummy.csv
# os.listdir()

#f = open(sys.argv[1], 'wt')
f = open("out.csv", 'wt')
#Open up csv writer
try:
    #Crawl through directories indicated
    writer = csv.writer(f)
    for dirname, dirnames, filenames, in os.walk(sys.argv[1]):
        for subdirname in dirnames:
            print os.path.join(dirname, subdirname)
            x = ["DIR", os.path.join(dirname, subdirname), "0"]
            writer.writerow(x)
        for filename in filenames:
            print os.path.join(dirname, filename)
            x = ["FIL", os.path.join(dirname, filename), os.path.getsize(os.path.join(dirname, filename))]
            writer.writerow(x)
    #For each directory/file we will create
finally:
    f.close()
