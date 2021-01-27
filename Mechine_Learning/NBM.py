import math
import random
cla_all_num = 0
cla_num = {}
cla_tag_num = {}
landa = 0.6


def train(taglist, cla):
    global cla_all_num
    cla_all_num += 1
    if cla in cla_num:
        cla_num[cla] += 1
    else:
        cla_num[cla] = 1
    if cla not in cla_tag_num:
        cla_tag_num[cla] = {}
    tmp_tags = cla_tag_num[cla]
    for tag in taglist:
        if tag in tmp_tags:
            tmp_tags[tag] += 1
        else:
            tmp_tags[tag] = 1


def P_C(cla):
    return cla_num[cla] / cla_all_num


def P_W_C(tag, cla):
    tmp_tags = cla_tag_num[cla]
    if tag not in cla_tag_num[cla]:
        return landa / (cla_num[cla] + len(tmp_tags) * landa)
    return (tmp_tags[tag] + landa) / (cla_num[cla] + len(tmp_tags) * landa)


def test(test_tags):
    res = ''
    res_P = None
    for cla in cla_num.keys():
        log_P_W_C = 0
        for tag in test_tags:
            log_P_W_C += math.log(P_W_C(tag, cla), 2)
        tmp_P = log_P_W_C + math.log(P_C(cla), 2)
        if res_P is None:
            res = cla
            res_P = tmp_P
        if tmp_P > res_P:
            res = cla
            res_P = tmp_P
    return res, res_P


def create_MarriageData():
    p0 = ['青绿', '乌黑', '浅白']
    p1 = ['蜷缩', '稍蜷', '硬挺']
    p2 = ['浊响', '沉闷', '清脆']
    p3 = ['清晰', '稍糊', '模糊']
    p4 = ['凹陷', '稍凹', '平坦']
    p5 = ['硬滑', '软粘']
    dataset = []
    dataset.append(random.choice(p0))
    dataset.append(random.choice(p1))
    dataset.append(random.choice(p2))
    dataset.append(random.choice(p3))
    dataset.append(random.choice(p4))
    dataset.append(random.choice(p5))
    print("随机产生西瓜为:", dataset)
    return dataset


def beyesi():
    data = [['青绿', '蜷缩', '浊响', '清晰', '凹陷', '硬滑', '是'],
            ['乌黑', '蜷缩', '沉闷', '清晰', '凹陷', '硬滑', '是'],
            ['乌黑', '蜷缩', '浊响', '清晰', '凹陷', '硬滑', '是'],
            ['青绿', '蜷缩', '沉闷', '清晰', '凹陷', '硬滑', '是'],
            ['浅白', '蜷缩', '浊响', '清晰', '凹陷', '硬滑', '是'],
            ['青绿', '稍蜷', '浊响', '清晰', '稍凹', '软粘', '是'],
            ['乌黑', '稍蜷', '浊响', '稍糊', '稍凹', '软粘', '是'],
            ['乌黑', '稍蜷', '浊响', '清晰', '稍凹', '硬滑', '是'],
            ['乌黑', '稍蜷', '沉闷', '稍糊', '稍凹', '硬滑', '否'],
            ['青绿', '硬挺', '清脆', '清晰', '平坦', '软粘', '否'],
            ['浅白', '硬挺', '清脆', '模糊', '平坦', '硬滑', '否'],
            ['浅白', '蜷缩', '浊响', '模糊', '平坦', '软粘', '否'],
            ['浅白', '稍蜷', '浊响', '稍糊', '凹陷', '硬滑', '否'],
            ['浅白', '稍蜷', '沉闷', '稍糊', '凹陷', '硬滑', '否'],
            ['乌黑', '稍蜷', '沉闷', '稍糊', '稍凹', '软粘', '否'],
            ['浅白', '蜷缩', '浊响', '模糊', '平坦', '硬滑', '否'],
            ['青绿', '蜷缩', '沉闷', '稍糊', '稍凹', '硬滑', '否']]
    for x in data:
        train(x[0:6], x[-1])


if __name__ == '__main__':
    beyesi()
    testcs = ['青绿', '蜷缩', '浊响', '清晰', '凹陷', '硬滑']
    print("单例测试为：", testcs)
    print('测试结果：', test(testcs))
    for i in range(1, 20):
        print('测试结果：', test(create_MarriageData()))
