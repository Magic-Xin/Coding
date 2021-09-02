# coding=utf-8

from docx import Document
from pdf2docx import Converter
import os
import re
import sys
import datetime

trust_ratio = 0.7  # 单句重复率阈值全局变量


# 进度条类
class ProgressBar(object):
    DEFAULT = 'Progress: %(bar)s %(percent)3d%%'
    FULL = '%(bar)s %(current)d/%(total)d (%(percent)3d%%) %(remaining)d to go'

    def __init__(self, total, width=40, fmt=DEFAULT, symbol='=',
                 output=sys.stderr):
        assert len(symbol) == 1

        self.total = total
        self.width = width
        self.symbol = symbol
        self.output = output
        self.fmt = re.sub(r'(?P<name>%\(.+?\))d',
                          r'\g<name>%dd' % len(str(total)), fmt)

        self.current = 0

    def __call__(self):
        percent = self.current / float(self.total)
        size = int(self.width * percent)
        remaining = self.total - self.current
        bar = '[' + self.symbol * size + ' ' * (self.width - size) + ']'

        args = {
            'total': self.total,
            'bar': bar,
            'current': self.current,
            'percent': percent * 100,
            'remaining': remaining
        }
        print('\r' + self.fmt % args, file=self.output, end='')

    def done(self):
        self.current = self.total
        self()
        print('', file=self.output)


# 读取比对文件，通过 python-docx 分段落读取文件，放回段 List
def getText(filepath):
    d = Document(filepath)
    texts = []
    for para in d.paragraphs:
        texts.append(para.text)
    return texts


# 判断分词后是否为中文，舍弃英文单词比对
def is_Chinese(word):
    for ch in word:
        if '\u4e00' <= ch <= '\u9fff':
            return True
    return False


# 通过标点符号对段落进行分句
def msplit(s, seperators=',|\.|\?|，|。|？|！'):
    return re.split(seperators, s)


# 读取文件总函数
def readDocx(docfile, if_show=False):
    if if_show:
        print('加载', docfile)
    t1 = datetime.datetime.now()
    paras = getText(docfile)
    segs = []
    for p in paras:
        temp = []
        for s in msplit(p):
            if len(s) > 2:
                temp.append(s.replace(' ', ""))
        if len(temp) > 0:
            segs.append(temp)
    t2 = datetime.datetime.now()
    if if_show:
        print('加载完成，用时: ', t2 - t1)
        showInfo(segs, docfile)
    return segs


# 输出读取信息
def showInfo(doc, filename='filename'):
    chars = 0
    segs = 0
    for p in doc:
        for s in p:
            segs = segs + 1
            chars = chars + len(s)
    print('段落数: {0:>8d} 个。'.format(len(doc)))
    print('短句数: {0:>8d} 句。'.format(segs))
    print('字符数: {0:>8d} 个。'.format(chars))


# 比对算法核心函数
def compareParagraph(doc1, doc2, i, j, filename, min_segment=5):
    p1 = doc1[i]
    p2 = doc2[j]
    len1 = sum([len(s) for s in p1])
    len2 = sum([len(s) for s in p2])
    # 筛除过短句
    if len1 < 10 or len2 < 10:
        return

    temp = ""
    # 遍历原文件和数据库内论文，利用字符串查找算法高效比对单句内字符，相同率高于阈值时输出
    for ii in range(len(p1)):
        if len(p1[ii]) < min_segment or not is_Chinese(p1[ii]):
            continue
        for jj in range(len(p2)):
            if len(p2[jj]) < min_segment:
                continue
            if p2[jj] in p1[ii]:
                temp = p2[jj]
            elif p1[ii] in p2[jj]:
                temp = p1[ii]
            if temp != "":
                count = len(temp)
                ratio = float(count) / min(len(p1[ii]), len(p2[jj]))
                if count > 10 and ratio > trust_ratio:
                    print('发现相同内容 '.center(80, '*'))
                    print('原文件 第{0:0>4d}段第{1:0>4d}句'.format(i + 1, ii + 1))
                    print('文件 \"{2}\" 第{0:0>4d}段第{1:0>4d}句'.format(j + 1, jj + 1, filename))
                    print('相同内容：', temp)
                    print('相同字符比：{1:.2f}%\n相同字符数： {0}\n'.format(count, ratio * 100))
            temp = ""


# 主函数
def main():
    global trust_ratio

    # 读取参数信息，调整全局单句阈值
    if len(sys.argv) < 2:
        print("参数错误")
        exit(-1)
    if len(sys.argv) == 3:
        trust_ratio = float(sys.argv[2])

    # 读取需要进行比对的原文件
    filepath = sys.argv[1]
    filename, _type = os.path.splitext(filepath)
    # 对 pdf 文件先行进行格式转换
    if _type == '.pdf':
        convert_path = filename + '.docx'
        cv = Converter(filepath)
        cv.convert(convert_path, multi_processing=True)
        cv.close()
        filepath = convert_path
    doc1 = readDocx(filepath, True)

    # 读取本地数据库内的论文，并逐文件进行比对
    print("加载数据库...")
    path = '.\\database\\word'
    filename_list = os.listdir(path)
    print(f'数据库共 {len(filename_list)} 篇论文')
    progress = ProgressBar(len(filename_list), fmt=ProgressBar.FULL)
    t1 = datetime.datetime.now()
    print('开始比对...')
    for filename in filename_list:
        if filename.endswith('.docx'):
            doc2 = readDocx(os.path.join(path, filename))
            for i in range(len(doc1)):
                for j in range(len(doc2)):
                    compareParagraph(doc1, doc2, i, j, filename)
        progress.current += 1
        progress()
    t2 = datetime.datetime.now()
    progress.done()
    print('\n比对完成，总用时: ', t2 - t1)


if __name__ == '__main__':
    main()
