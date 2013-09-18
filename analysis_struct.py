# coding=utf-8
__author__ = 'Administrator'


def readDefine(fname):
    """
    读取头文件中的宏定义，存入宏定义字典
    :param fname: 头文件名，全路径
    """

def readStruct(fname):
    """
    读取头文件中struct定义，存入结构定义字典
    :param fname: 头文件名，全路径
    """


def createConf(fname):
    """
    生成每个结构体的struct模块format定义
    :param fname: 生成的fmt配置文件名
    """

def main():
    """
    main函数
    """
    fname = raw_input('Please Input Head Filename:')
    print 'Filename is: %s' % fname

    readDefine(fname)
    readStruct(fname)

    confname = 'zimpay_struct_fmt.conf'
    createConf(confname)

if __name__ == '__main__':
    main()

