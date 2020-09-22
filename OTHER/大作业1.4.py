# -*-coding:utf-8-*-
import requests
import re
import json
import os           #导入库文件

headers = {
    'Content-Type': 'application/x-www-form-urlencoded',
    'Origin': 'https://maoyan.com',
    'Referer': 'https://maoyan.com/board/4',
    'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_14_5) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/75.0.3770.100 Safari/537.36'
}

def get_one_page(url, headers):
    response = requests.get(url, headers=headers)   #获取网页，向服务器请求资源
    if response.status_code == 200:      #http请求的返回状态，200表示连接成功
        return response.text
    return None

def parse_one_page(html):
    pattern = re.compile('<dd>.*?board-index.*?>(\d+)</i>.*?data-src="(.*?)".*?name"><a'+ '.*?>(.*?)</a>.*?star">(.*?)</p>.*?releasetime">(.*?)</p>.*?integer">(.*?)</i>.*?fraction">(.*?)</i>.*?</dd>',re.S)  #正则表达式
    items = re.findall(pattern, html)   #返回一个元组组成的列表
    for item in items:   #遍历列表，用一个生成器来存储遍历到的结果
        yield {         # 返回一个迭代值
            'index': item[0],    #调取列表内容
            'image': item[1],
            'title': item[2],
            'actor': item[3].strip()[3:],
            'time': item[4].strip()[5:],
            'score': item[5] + item[6]
        }


def write_to_file(content):    #写入文本
    with open('maoyan.txt', 'a', encoding='utf-8') as f:
        f.write(json.dumps(content, ensure_ascii=False) + '\n')   #将字典转化为字符串
        f.close()

def save_image_file(url, path):     #保存图片到文件夹
    jd = requests.get(url)
    if jd.status_code == 200:       #200表示连接成功
        with open(path, 'wb') as f:
            f.write(jd.content)     #写入
            f.close()

def main(offset):
    url = "http://maoyan.com/board/4?offset=" + str(offset)
    html = get_one_page(url, headers)
    if not os.path.exists('Maoyan_Images'):       #判断是否存在
        os.mkdir('Maoyan_Images')             #创建
    for item in parse_one_page(html):
        print(item)
        write_to_file(item)
        save_image_file(item['image'], './Maoyan_Images/' + '1' + '_' +item['index']+ item['title'] + '.jpg')


if __name__ == '__main__':
    for i in range(10):
        main(i * 10)
