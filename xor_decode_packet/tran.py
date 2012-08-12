import datetime
import MySQLdb

def d_payload(data, sig):
  key = int(data[:8],16)
  print("key: %d" % key)
  presig = int(a[8:16],16)
  print("presig: %s" % presig)
  print("xor: %s" % (presig ^ key))
  if(int(sig,16) - (presig ^ key) == 0):
    return 1
  else:
    return 0

if __name__ == '__main__':
  if len(sys.arv) < 2:
    print 'Usage: %s [signature]' % sys.argv[0]
    sys.exit(1)
  db = MySQLdb.connect(host = "localhost",
      user = "lnguyen",
      passwd="",
      db="")
  cur = db.cursor()
  try:
    cur.execute("SELECT sid, signature, timestamp, ip_src, ip_dst, data_payload, FROM snort_archive.event_den where signature = %s", (sig))
    rows = cur.fetchall()
  except MySQLdb.Error, e:
    try:
      print "MySQL Error [%d]: %s" % (e.args[0], e.args[1])
    except IndexError:
      print "MySQL Error: %s" % str(e)
  #for row in rows:
    #print(row[5])
    #if row[3].encode("hex") ^ key == 
    #for col in rows:
      #print "%s," % col
    #print "\n"
  if (rows):
    print rows[0][5]
  cur.close()
  db.close()
