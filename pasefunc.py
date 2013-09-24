__author__ = 'Administrator'

def parse_enum(structcontent):
    """
    解析枚举
    """

    pass



def parse_struct(structcontent):
    """
    读取头文件中struct定义，存入结构定义字典
    :param structcontent:
    """
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
        except:
            # 去掉;号后面部分的注释
            line = line[:line.index(';')]
            line_list = line.split()
            fieldtype = line_list[0]
            fieldtype = fieldtype.replace(' ','')

            try:
                idx = line.index('[')
                if idx >= 0:
                    #字符串
                    fieldname = line_list[1][:line_list[1].index('[')]
                    fieldlen_str = line[line.index('[') + 1:line.index(']')]
                    fieldlen = CalcFieldLen(fieldlen_str)
            except:
                pass

            #直接从type_dict中获取长度
            try:
                if type_dict.has_key(fieldtype):
                    fieldlen = type_dict[fieldtype]['len']

                fieldname = line_list[1]
            except NameError:
                continue

            tmp_dict[fieldtype] = [fieldname, fieldlen]

