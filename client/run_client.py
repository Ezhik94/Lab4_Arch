
import time
import sys
import os

os.system("cd .build")

start_time = time.time()
os.system("./client -m testmessagetoconvert")
print "---%s seconds---\n" % (time.time() - start_time)

start_time = time.time()
os.system("./client -m testmessagetoconvertnewasdasfdfkjkjgkjjkgkdjklgdjkgdkjfgkdfkjgdjkfgfdgjkldfgjljkhf")
print "---%s seconds---\n" % (time.time() - start_time)

start_time = time.time()
os.system("./client -m testmessagetoconvertfdskfksdkfsdkhfgoitoitoicccccccccglvngfddfmeoiwroiewioroiweroiweoiroiweoriwe")
print "---%s seconds---\n" % (time.time() - start_time)