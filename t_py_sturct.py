__author__ = 'Administrator'

from socket import *
import struct
from ctypes import *
import os

HOST = ''
PORT = 21567
BUFSIZ = 1024
ADDR = (HOST, PORT)

fmt = '!hccs8s8s10s8ccchhis5s5s8s4s3c'

tcpServSock = socket(AF_INET, SOCK_STREAM)
tcpServSock.bind(ADDR)
tcpServSock.listen(5)

while True:
    print 'Waiting for connection...'
    tcpCliSock, addr = tcpServSock.accept()
    print '...Connected from :', addr

    while True:
        data = tcpCliSock.recv(BUFSIZ)
        if not data:
            break

        print len(data)
        print struct.calcsize(fmt)
        print 'fmt = %s, len = %d' % (fmt, struct.calcsize(fmt))
        xxx = struct.unpack(fmt, data)
        print xxx

        curdir = os.getcwd()
        bcdso = curdir + '/bcd.dll'
        try:
            libBcd = windll.LoadLibrary(bcdso)
        except (TypeError, ValueError):
            print "Error"
            exit

        business = ''
        libBcd.iBcdToAsc(xxx[3], business, 16)
        print business

tcpServSock.close()
