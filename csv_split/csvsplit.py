#Loc Nguyen
#01/18/11
#Description Takes a CSV and splits it uniquely into seperate files based on each unique within a column (Per Unique User)
#
#

import csv, sys

csvReader = csv.reader(open(sys.argv[1], 'rb'), delimiter=',', quotechar='|')
firstRec = True
curRec = ''
for row in csvReader:
    if firstRec:
        fieldNames = row
        firstRec = False
    else:
        if curRec != row[4]:
            print row[4]
            curRec = row[4]
            f = open(row[4]+'.csv', 'wb')
            f.write(fieldNames[0]+','+fieldNames[3]+','+fieldNames[4]+','+fieldNames[7]+','+fieldNames[9] + "\n")
            f.write(row[0]+','+row[3]+','+row[4]+','+row[7]+','+row[9] +"\n")
            f.close()
        else:
            f = open(row[4]+'.csv', 'ab')
            f.write(row[0]+','+row[3]+','+row[4]+','+row[7]+','+row[9]+"\n")
            f.close()
