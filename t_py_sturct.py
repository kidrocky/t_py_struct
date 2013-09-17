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
        print repr(data)
        (magic, spno, rpno, busi,) = struct.unpack(fmt, data)
        print busi

        libBcd = cdll.LoadLibrary(os.getcwd() + '/bcd.so')
        libbcd.iBcdToAsc(busi, business, 16)
        print business

tcpCliSock.close()
tcpServSock.close()
