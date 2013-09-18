# coding=utf-8

__author__ = 'Administrator'

define_dict = {}
struct_dict = {}
struct_flag = 0
type_dict = dict(BYTE = "B", UINT8 = "s", INT8 = "s", WORD = "h", WORD16 = "h", UINT16 = "h", INT16 = "h", WORD32 = "i",
                 UINT32 = "i", INT32 = "i")


def parseDefine(line):
    """
    解析宏定义，取出宏名字和宏值，写入字典
    :param line:
    :return:
    """
    if line == "":
        return

    tmp = line.split
    define_dict[tmp[1]] = tmp[2]


def readFile(fname):
    """
    读取头文件中的宏定义，存入宏定义字典
    :param fname: 头文件名，全路径
    """
    structcontent = ""
    try:
        fd = open(fname, "r", 0)
        for line in fd:
            if line == "":
                continue

            idx = line.index("#define")
            if idx >= 0:
                parseDefine(line)
            else:
                # 去空格
                tmp = line.replace(' ', '')
                idx = tmp.index("typedefstruct")
                if idx >= 0:
                    struct_flag = 1
                    structcontent += line

                idx = line.index('}')
                if idx >= 0:
                    struct_flag = 0
                    structcontent += line
                    parseStruct(structcontent)

                if struct_flag == 1:
                    structcontent += line

        fd.close()
    except IOError:
        pass


def parseStruct(structcontent):
    """
    读取头文件中struct定义，存入结构定义字典
    :param fname: 头文件名，全路径
    """
    if structcontent == "":
        return

    for line in structcontent:


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

        readFile(fname)

        confname = 'zimpay_struct_fmt.conf'
        createConf(confname)


    if __name__ == '__main__':
        main()

