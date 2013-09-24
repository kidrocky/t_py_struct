# coding=utf-8

__author__ = 'Administrator'
import string
import sys
import os

define_dict = {}
struct_dict = {}
type_dict = {'BYTE': {'len': 1, 's_type': "B"},
             'UINT8': {'len': 1, 's_type': "s"},
             'INT8': {'len': 1, 's_type': "s"},
             'WORD': {'len': 2, 's_type': "h"},
             'WORD16': {'len': 2, 's_type': "h"},
             'UINT16': {'len': 2, 's_type': "h"},
             'INT16': {'len': 2, 's_type': "h"},
             'WORD32': {'len': 4, 's_type': "i"},
             'UINT32': {'len': 4, 's_type': "i"},
             'INT32': {'len': 4, 's_type': "i"},
             'time_t': {'len': 4, 's_type': "i"},
             'PID': {'len': 5, 's_type': "i"}}


def parseDefine(line):
    """
    解析宏定义，取出宏名字和宏值，写入字典
    :param line:
    :return:
    """
    if line == "":
        return

    tmp = line.split()
    if len(tmp) < 3:
        return

    define_dict[tmp[1]] = tmp[2]


def readFile(fname):
    """
    读取头文件中的宏定义，存入宏定义字典
    :rtype : NULL
    :param fname: 头文件名，全路径
    """
    global fd
    type_name = ""
    structcontent = ""
    struct_flag = 0

    try:
        fd = open(fname, "r", 0)
        for line in fd:
            if line == "":
                continue

            #解析defile
            try:
                idx = line.index("#define")
            except ValueError:
                idx = -1

            if idx >= 0:
                parseDefine(line)
                continue

            #解析enum，struct
            try:
                idx = line.index("typedef")
            except ValueError:
                continue

            if idx >= 0:
                struct_flag = 1
                # 获取是enum还是struct
                type_name = line.split()[1].replace(' ', '')
                structcontent += line
                continue

            if 1 == struct_flag:
                structcontent += line

            try:
                idx = line.index('}')
            except ValueError:
                continue

            if idx >= 0:
                if struct_flag == 0:
                    continue
                else:
                    struct_flag = 0

                structcontent += line
                if type_name == 'enum':
                    parse_enum(structcontent)
                elif type_name == 'struct':
                    parse_struct(structcontent)

        fd.close()
    except IOError:
        fd.close()
        pass


def parse_enum(structcontent):
    """
    解析枚举
    :rtype : object
    :param structcontent:
    """
    lines = structcontent.split('\n')
    for line in lines:
        try:
            idx = line.index('}')
            if idx >= 0:
                structname = line.split('}')[1].replace(' ', '')
                type_dict[structname] = 4
                break
        except ValueError:
            continue


def parse_struct(structcontent):
    """
    读取头文件中struct定义，存入结构定义字典
    :rtype : NULL
    :param structcontent:
    """
    global fieldlen
    if structcontent == "":
        return

    tmp_dict = {}
    lines = structcontent.split('\n')
    for line in lines:
        try:
            idx = line.index('typedef')
        except ValueError:
            idx = -1

        if idx >= 0:
            continue

        if line == '{':
            continue

        try:
            idx = line.index('}')
            if idx >= 0:
                structname = line.split('}').replace(' ', '')
                struct_dict[structname] = tmp_dict
                break
        except ValueError:
            # 去掉;号后面部分的注释
            line = line[:line.index(';')]

            #解析
            line_list = line.split()
            fieldtype = line_list[0]
            fieldtype = fieldtype.replace(' ', '')

            try:
                idx = line.index('[')
            except ValueError:
                pass

            if idx >= 0:
                #字符串
                fieldname = line_list[1][:line_list[1].index('[')]
                fieldlen_str = line[line.index('[') + 1:line.index(']')]
                fieldlen = CalcFieldLen(fieldlen_str)
            else:
                #直接从type_dict中获取长度
                try:
                    if fieldtype in type_dict.keys():
                        fieldlen = type_dict[fieldtype]['len']

                    fieldname = line_list[1]
                except NameError:
                    continue

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

    result = len_define + len_int
    return result


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

    # 初始化
    cur_path = os.getcwd()
    sys.path.append(cur_path)

    # 分析头文件
    readFile(fname)

    # 写头文件解析结果
    confname = 'zimpay_struct_fmt.conf'
    createConf(confname)


if __name__ == '__main__':
    main()