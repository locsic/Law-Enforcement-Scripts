import re
import sys
import os

#@Title:        PageFile Grep
#@Date:         06/06/12
#@Version:      .1
#@Author:       Loc
#@Description:  Input a file of line delimited regular expressions to be found in a pagefile.
#               Output 4K memory pages containing hits of the search term
#                   Create a directory for each search term
#                   Populate with memory pages
#                       Filename: pagenumber_
#                       Preprend Files with metainfo
#@TODO:         Add variable chunk_size
#

def read_in_chunks(file_object, chunk_size=4096):
    """Function to read a file piece by piece.
    Default chunk size: 4k."""
    while True:
        data = file_object.read(chunk_size)
        if not data:
            break
        yield data

if __name__=='__main__':
    if len(sys.argv) < 2:
        #print 'Usage: %s [pagefile] [line-delimited search list]' % sys.argv[0]
        print('Usage: %s [pagefile] [line-delimited search list]' % sys.argv[0])
        sys.exit(1)
    f = open(sys.argv[2], 'r')
    search_terms = f.readline().split('\n')
    f.close()
    foo = open(sys.argv[1])
    if not os.path.exists('output'):
        os.makedirs('output')
    page_count = 0

    try:
        for piece in read_in_chunks(foo):
            page_count = page_count+1
            #Process Data
            for line in piece:
                for item in search_terms:
                    if(item):
                        ##Check if search item exists in line
                        if item in line.lower():
                            if not os.path.exists("output/"+item):
                                os.makedirs("output/"+item)
                            page_out = "output/"+item+"/"+str(page_count).zfill(3)
                            if not os.path.exists(page_out):
                                writer = open(page_out, 'w')
                                writer.write(piece)
                                writer.close()
    except UnicodeDecodeError, err:
        print 'ERROR:', err
    else:
        print 'Read         :', repr(foo)
    foo.close()
