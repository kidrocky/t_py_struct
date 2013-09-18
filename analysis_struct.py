# coding=utf-8

__author__ = 'Administrator'
import string

define_dict = {}
struct_dict = {}
type_dict = {'BYTE': "B", 'UINT8': "s", 'INT8': "s", 'WORD': "h", 'WORD16': "h", 'UINT16': "h", 'INT16': "h",
             'WORD32': "i", 'UINT32': "i", 'INT32': "i"}


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
    struct_flag = 0

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

                if 1 == struct_flag:
                    structcontent += line

        fd.close()
    except IOError:
        pass


def parseStruct(structcontent):
    """
    读取头文件中struct定义，存入结构定义字典
    :param structcontent:
    """
    if structcontent == "":
        return

    tmp_dict = {}
    lines = structcontent.split('\n')
    for line in lines:
        idx = line.index('typedef')
        if idx >= 0:
            continue

        idx = line.index('}')
        if idx >= 0:
            structname = line.split('}').replace(' ', '')
            struct_dict[structname] = tmp_dict
            break

        # 去掉;号后面部分的注释
        line = line[:line.index(';')]
        line_list = line.split()
        fieldtype = line_list[0]
        fieldname = line_list[1][:line_list[1].index('[')]
        fieldlen_str = line[line.index('[') + 1:line.index(']')]
        fieldlen = CalcFieldLen(fieldlen_str)
        tmp_dict[fieldtype] = [fieldname, fieldlen]


def CalcFieldLen(fieldlen_str):
    """

    :param fieldlen_str:
    :return:
    """
    len_define = 0
    len_int = 0
    if fieldlen_str == "":
        return -1

    for item in fieldlen_str.split():
        if item in define_dict:
            len_define = define_dict[item]
            continue

        try:
            len_int = string.atoi(item)
        except ValueError:
            len_int = 0

    return len_define + len_int


def createConf(fname):
    """
    生成每个结构体的struct模块format定义
    :param fname: 生成的fmt配置文件名
    """
    try:
        fd = open(fname, "w", 0)
        fd.close()
    except IOError:
        pass


def main():
    """
    main函数
    """
    fname = raw_input('Please Input Head Filename:')
    print 'Filename is: %s' % fname

    # 分析头文件
    readFile(fname)

    # 写头文件解析结果
    confname = 'zimpay_struct_fmt.conf'
    createConf(confname)


if __name__ == '__main__':
    main()