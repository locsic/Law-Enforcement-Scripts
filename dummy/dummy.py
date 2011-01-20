import csv
import os
import sys
from os import mkdir

# Dummy File Directory and File Generator
# @Author Loc Nguyen
# @Date 10/22/10
# @Description
# Using the dummycsv script to analyze a directory setup, you can take
# the csv and input it into this script to output dummy files that
# still carry the name and size characteristics of the original
# but the data within remains random so there is 0 possibility
# for retrieving the original content.
#
# Alternatively one can also produce their own CSV file
# to create custom dummy files
#
# Seek Method
# Quicker to seek to the filesize location and put an end filler
# than to arbitrarily fill the file with random data
#

# Read in CSV file and create Directory or File in accordance to the name
# and filesize.
# Fill newly created file with arbitrary data up to the indicated size

# Initiate file then fill the file
# up to the buffered filesize
#
#
# Usage: python dummy.py [file.csv] [/destinationpath/]
def create_dummy_file(path, size):
    fh = open(sys.argv[2] + path, 'wb')
    fh.seek(int(size) - 1)
    fh.write('\0')
    fh.close()

reader = csv.reader(open(sys.argv[1], "rb"))
for row in reader:
    if row[0] == "DIR":
        print row[1]
        #Create Directory
        d = os.path.dirname(os.path.join(sys.argv[2] + row[1]))
        print d
        if not os.path.exists(d):
            os.makedirs(d)
        mkdir(sys.argv[2] + row[1])
    else:
        #Open and write dummy file
        create_dummy_file(row[1], row[2])
    print row
