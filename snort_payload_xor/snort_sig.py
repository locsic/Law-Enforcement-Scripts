import datetime
import MySQLdb
import csv

# @Author Loc Nguyen
# @Version .1
# @Python 3.x
# @todo
#   Assumption is made that the signature size is the same as the keysize. 
#   Account for differing signature and key sizes.
#
#

KEY_SIZE = 8
HEX_DECODE = 16

#
# Decode chunk at offset using XOR key, return if matches signature
#
def d_payload(data, sig, offset):
  key = int(data[:KEY_SIZE],HEX_DECODE)
  print("key: %d" % key)
  presig = int(data[int(offset):int(offset)+KEY_SIZE],HEX_DECODE)
  print("presig: %s" % presig)
  print("xor: %s" % (presig ^ key))
  if(int(sig,HEX_DECODE) - (presig ^ key) == 0):
    return 1
  else:
    return 0

#
# Decode chunk at offset using XOR key, return if matches signature
# Calculation performed on a rolling basis - If one does not know the exact offset
#
#
def r_payload(data, sig, offset):
  #Check oversize offset condition
  if(int(offset)-KEY_SIZE-len(data)) < 0:
    return 2
  #No implementation for negative offset yet
  elif(int(offset) < 0):
    return 3
  key = int(data[:KEY_SIZE],HEX_DECODE)
  for x in range(int(offset), len(data)-KEY_SIZE):
    presig = int(data[x:x+KEY_SIZE],HEX_DECODE)
    if(int(sig,HEX_DECODE) - (presig ^ key) == 0):
      return 1
    #else:
    #  return 0
  #Base case
  return 0

if __name__ == '__main__':
  if len(sys.arv) < 2:
    print('Usage: %s [signature.csv] [outputfile]' % sys.argv[0])
    sys.exit(1)
  db = MySQLdb.connect(host = "localhost",
      user = "lnguyen",
      passwd="",
      db="")
  cur = db.cursor()
  ifile = sys.argv[1]
  sigcsv = csv.reader(open(ifile))
  ofile = open(sys.argv[2], 'wb')
  ofile_writer = csv.writer(ofile, dialect='excel')
  try:
    cur.execute("SELECT sid, signature, timestamp, ip_src, ip_dst, data_payload, FROM snort_archive.event_den where signature = %s", (sig))
    rows = cur.fetchall()
    for row in rows:
      if row[5] is not None: #Ignore payloads that are null
        for entry in sigcsv:
          #Check to see if payload is at least the size of the signature offset + keysize
          if(len(row[5]) >= int(entry[1])+KEY_SIZE) and (d_payload(row[5], entry[0], entry[1]) == 1): 
              ofile_writer.writerow(row)
  #except MySQLdb.Error, e:
  except MySQLdb.Error:
    try:
      print("MySQL Error [%d]: %s" % (e.args[0], e.args[1]))
    except IndexError:
      print("MySQL Error: %s" % str(e))
  cur.close()
  db.close()
  ofile.close()
