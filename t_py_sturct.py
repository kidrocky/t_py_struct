__author__ = 'Administrator'

from socket import *
from time import ctime
import struct
from ctypes import *
import os

HOST = ''
PORT = 21567
BUFSIZ = 1024
ADDR = (HOST,PORT)
fmt = '!hBB8s8s10s8sBBBhhi5s5s8s4s3sc'

business = create_string_buffer('\000', 32)
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
        print 'fmt = %s, len = %d' % (fmt, struct.calcsize(fmt))
        xxx = struct.unpack(fmt, data)
        print xxx

        libbcd = cdll.LoadLibrary('bcd.so')
        libbcd.iBcdToAsc(xxx[3], byref(business), 8)
        print repr(business.value)

tcpServSock.close()