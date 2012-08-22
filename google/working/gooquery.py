import sys
from search import GoogleSearch, SearchError

def search(a):
  try:
    gs = GoogleSearch(a)
    gs.results_per_page = 100
    results = gs.get_results()
    for res in results:
      print res.title.encode("utf8")
      print res.desc.encode("utf8")
      print res.url.encode("utf8")
      print
  except SearchError, e:
    print "Search failed:"

if __name__== '__main__':
  search(sys.argv[1])
