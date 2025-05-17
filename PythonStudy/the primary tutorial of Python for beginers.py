# python 入门课程链接 https://www.bilibili.com/video/BV1944y1x7SW
# python 标准库官网链接 https://docs.python.org/zh-cn/3/library/index.html

# 第一课：print及代码符号


print("——第一课：print及代码符号")
# python 代码为逐行读取，每行是一条指令，如需要换行读取同一条指令，需要换行符号
# 单双引号平时无区别，但是引用文本有单/双引号，引用符号就要用双/单引号，或者用反斜杠"\"讲后面符号识别为字符
print("他说:\"老\n"
      "板好！\"")  # 反斜杠“\”后面的标点符号被识别为字符
print('''君不见
黄河之水
天上
来，
奔流到
海
不复回''')  # 三个单/双引号自动换行
print('你好 这是一句代码 哈哈')
print('你好' + ' 这是一句代码' + ' 哈哈哈')
print('你好'' 这是一句代码'' 哈哈哈哈')
print('')  # 引号中间空着就是空白行，相当于换一行
print('Let\'s go')
print('\n')  # \n 后无文字换两行，有文字一行
print('我是第一行\
      我是第二行\n我是第三行\n哈哈哈哈哈')
print("用逗号连接", "有空格，" + "用加号连接" + "无空格")  # 用用逗号字符串可以与整数浮点数等其他类型数据连接，而加号不行

# 第二课：赋值
print("——第二课：赋值")

'''
greet = '您好，吃了吗， '
greet_chinese = greet
greet_english = greet
greet_english = 'Yo what\'up, '
print(greet + '张三')
print(greet + '李四')
print(greet + '王五')
print(greet_english + '小张')
print()
'''

# 第三课：变量命名规则
print("第三课：变量命名规则")
# 正确示范：zhang_3 只能由文字、数字、下划线组成
# 错误示范：zhang!3 不能有除下划线之外的符号，zhang 3 不能有空格，3zhang 不能数字开头
# 尽量不用拼音，拼音阅读速慢，最好用英文，英文兼容性好
# Python已经支持中文变量名，主流仍是英文，因为控制台或日志等编码不兼容，会出现乱码

print("Python变量名命名：\n一、下划线法：\n1，字母全部小写；\n2，不同单词用下划线分隔。例：user_age\n"
      "二、驼峰命名法：单词用首字母大写分隔。例：UserAge\n"
      "三、变量名大小写敏感，例user_age ≠ user_Age"
      "四、变量名不要占据Python关键字，例： print = 'u123' ")
print()

# 第四课：数学运算
print("——第四课：数学运算")
print("加引号为字符，不加为变量，例：'6'为字符串，6为整数，6.0为浮点数")
print("""+加，-减，*乘，/除
Python运算顺序，先括号（），再乘方**，再乘除* /，最后加减+ -；
乘方符号为双星号**，例：2的三次方，2**3;平方根相当于二分之一次方，可写作2**(1/2),也可以使用函数math.sqrt(x)。
进行复杂预算要导入 math函数库,导入方法：
文件最开始一行写入 import math,之后用 math.函数名（…）""")
'''
import math

print("计算数列的和:" + str(sum([1, -6, 23.6, 7])))  # sum([]) 计算数列的和

print("")
result = math.sqrt(4)
print(result)
print(math.sin(1))
print(math.log(2))
print(4 ** (1 / 2))
print(math.sqrt(4))
# 练习题：计算-x**2-2x+3=0,ax**2+bx+c=0(a≠0)
print("练习题答案")
a = -1
b = -2
c = 3
print((-b + math.sqrt(b ** 2 - 4 * a * c)) / (2 * a))
print((-b - math.sqrt(b ** 2 - 4 * a * c)) / (2 * a))
print("分部代码")
delta = math.sqrt(b ** 2 - 4 * a * c)
print((-b + delta) / (2 * a))
print((-b - delta) / (2 * a))
'''
print()

# 第五课：注释 # 我是一段注释， # 我是一段要被忽视的代码
print("——第五课：注释")
print("例如：#print((-b - delta) / (2 * a))")
print('先用鼠标左键框住一段或多段代码,再control 加 / ，可以快速加上#，\n'
      '同样方法可去掉#')
print("control 加 z 可以回退代码")
"""三引号也可以当做#忽略一段代码"""
print()

# 第六课：数据类型
print("——第六课：数据类型")
"""字符串 str 例："Hello" , "你"
   整数 int 6 , 32
   浮点数 float 6.0 , 10.05
   布尔类型 bool True , False, 第一个字母大写
   空值类型 NoneType None, 第一个字母大写 
   列表，字典，etc"""
print("字符串长度：")
print(len('Hello'))
print(len('你 好！'))  # len("字符串")可测量字符串长度,空格、数字、符号都占据一个长度
print(len('\'你 \n 吃了吗？\''))  # 反斜杠\ 完整转义后的符号才占一个长度，例如：\n \" 都只算一个长度
print("提取第几个字符")
print("Hello"[4])  # 第一个索引为0
print("Hello"[0])
print("Hello"[1 + 1])
print("None 不是0，不是空字符串''，不是False，表示完全没有值")
print("type 返回该对象类型")
print(type("Hello") is int)
print()

# 第七课：Python交互模式
print("——第七课：Python交互模式")
print("命令行模式:逐行读取运行代码\n"
      "交互模式：不需要创建任何Python文件就可以运行，不需要print就可以看到返回结果，交互模式命令不会被保存\n"
      "可以输入quit() 或 control 加 d 退出交互模式")
print()

# 第八课：input函数，input不论输入什么，返回的都是字符串
print("——第八课：input函数")
# 名字+年龄
"""user_name = input("请输入你的名字")
user_age = int(input("请输入你的年龄"))
user_age_after_10_years = user_age + 10
print("知道了，" + user_name + "，你今年" + "岁了，")
print("而你十年后是" + str(user_age + 10) + "岁。")"""
# BMI
'''print("请输入相关数据计算您的BMI指数")
user_hight = float(input("请输入您的身高（cm）")) / 100
user_weight = float(input("请输入您的体重（kg）"))
user_BMI = format(user_weight / user_hight ** 2, ".2f")
# fomat(数字, ".2f") 取小数点后面2位
# user_BMI = float(format(user_weight / (user_hight) ** 2, '.2f'))
# Python运算顺序，先括号（），再乘方**，再乘除* /，最后加减+ -；"""
print("您好，您的BMI指数为" + user_BMI + "m/kg²")
# print("您好，您的BMI指数为" + str(user_BMI) + "m/kg²" )'''
print()

# 第九课：Python条件语句,if 条件： 求出的值为布尔值（True，False）即成立
print("——第九课：Python条件语句")
is_happy = True
no_happy = False
if is_happy:  # if [条件]：  # 后面什么都不接，就到此结束
    print("我很快乐！")  # [执行语句]  四个空格
    print("我当然很快乐！")  # [多个执行语句]
elif no_happy:
    print("我很快乐")
else:
    print('我希望很快乐。')  # else： [执行语句]  # 条件为False时执行其他命令
# 比较运算符 == != < >
print(3 == 3)
print("a" == "b")
print(3 != 4)
print("练习题：")
'''mood_index = int(input("对象今天的心情指数是："))
if mood_index >= 60:
      print('恭喜，今晚应该可以打游戏，去吧皮卡丘！')
      print('哈哈哈哈！')
else:
      print('为了自个儿小命，还是别玩了。')'''
print()

# 第十课：Python嵌套/多条件判断
print("——第十课：Python嵌套/多条件判断")
print('嵌套条件')
"""if [条件1]:
    if [条件2]:  # 4空格
        [执行语句1]  # 4+4空格
    else:  #4空格
        [执行语句2]  # 4+4空格
else:
    [执行语句3]          
# 先满足条件1，再满足条件2则执行语句1，满足条件1不满足条件2则执行语句2，只要不满足条件1则执行语句3"""
'''print('练习：')
number_a = float(input("输入一个数字"))
if number_a > 10:
      if number_a >= 15:
            print("a大于15")
      else:
            print("a在10-15之间")
else:
      print("a小于等于10")'''
print()
print('多条件判断:逐一判断每个条件，这个条件语句写法更清晰直观\n'
      '缺点：判断第一个满足条件后执行第一个语句后就不会判断后面的条件')
"""number_b = float(input("输入一个数字"))
if 15 >= number_b > 10:  # 判断第一个满足条件后执行第一个语句后就不会判断后面的条件
    print("b 10-15")  # 可以使用嵌套，或者将限定范围，例如：if 15 >= number_b > 10
elif 20 >= number_b > 15:  # 20 >= number_b > 15:
    print("b 15-20")
elif 25 >= number_b > 20:  # 25 >= number_b > 20:
    print("b 20-25")
elif number_b > 25:
    print("b>25")
else:
    print("b<=10")"""
print()

# 第十一课：逻辑运算 与and， 或or， 非not， 可以用括号（）
print("——第十一课：逻辑运算")
"""not(x > 5 amd (x < 10 or x ==12))"""
print()

# 第十二课：列表list  # list可变； str、int、float、bool等不可变
print("——第十二课：列表list  # list可变")
shopping_list = ['键盘', '键帽']  # 寻求解答：shopping_list = list['键盘', '键帽'] 有什么区别？
print(str(shopping_list))
shopping_list.append('显示器')  # 补充:append意思是在数组添加一个元素,放在最后
print(str(shopping_list))
print("list可变； str、int、float、bool等不可变")
say_hi = "Hello"
print(say_hi.upper())  # [字符串].upper()  临时转换为大写
print(say_hi)  # 原字符串不变
# 如果要将字符串变为大写，需要将字符串重新赋值，例： s = s.upper()
shopping_list.append("KeyBoard".upper())  # append附加后列表内容已变
print(shopping_list)
'''shopping_list.remove("KeyBoard")  # 由于列表元素可变，KeyBoard已经转换为大写，去除元素不在列表中,导致报错
print(shopping_list)'''
shopping_list.remove("KEYBOARD")  # remove 去除列表元素
print(shopping_list)
print()
'''Python列表可以放不同类型数据，与其他语言不一样'''
list_test1 = ["Hello", 66.6, True, None]
print(list_test1)
'''列表可以通过len函数求长度，求出列表中元素数量'''
print(len(list_test1))  # len函数求出的是元素数量
'''可以通过索引获得某个位置的元素'''
print(shopping_list[0])  # 程序语言一般以0 开头，0 就是第一个元素
'''修改列表某个元素可以利用索引赋值修改'''
shopping_list[0] = 'Keyboard'.upper()
print(shopping_list)
'''其他列表函数'''
num_list = [1, 13, -7, 2, 96]
print(max(num_list))  # 打印列表里最大值
print(min(num_list))  # 打印列表里最小值
print(sorted(num_list))  # 升序排列，同时不改变原先列表 reverse=True
print(sorted(num_list, reverse=True))  # reverse=True 表示反转排序，即为降序排列
print("1", num_list)
list.sort(num_list)
print("2", num_list)
# list.sort( ) 函数会直接修改当前列表 ; sorted( )不会改变原来的list，而是会返回一个新的已经排好序的list
print("测试", num_list)

"""练习"""
print('')  # 以下代码有瑕疵，待解决；已部分解决
'''方案一：使用字典，再用sorted 函数排序'''
# shopping_list_1 = {input("请分别输入您想购买的物品：第一个 "): input("价格（元） "),
#                    input("第二个 "): input("价格（元） "),
#                    input("第三个 "): input("价格（元） ")}
shopping_list_1 = {"鼠标": 500,
                   "键盘": 200,
                   "电脑": 5000}
# print(shopping_list_1)
# price_1 = {input("请分别输入物品的价格（元）：第一个 "), input("第二个 "), input("第三个 ")}
# shopping_list_1_price_1 = zip(shopping_list_1, price_1)  # zip函数将物品和价格合并在一起
# shopping_list_1_sorted = sorted(shopping_list_1)  # 直接使用sorted函数会将字典转化为列表
print("您的购物清单为：")
for item_name_a, item_price_a in shopping_list_1.items():
    print(item_name_a + str(item_price_a) + "元")
print("其中最贵的为" + str(max(shopping_list_1.items(), key=lambda x: x[1])) + "元")
print("其中最便宜的为" + str(min(shopping_list_1.items(), key=lambda x: x[1])) + "元")
'''方案二：使用列表+元素进行排序'''  # 待解决

print()

# 第十三课：Python字典 dictionary
print("——第十三课：Python字典 dictionary")
"""字典 dictionary = {"键1":"值1",  # 字典用花括号表示
                 “键2”："值2"}  # 键和值之间用冒号，键和值的内容用引号包住，元素之间用逗号分隔
   键  ： 值  # 键用于查找值，  # 键的类型必须是不可变的（非变量），但是字典是可变的，可以添加和删除（更新）键值对
   key   value
   查询某个键的值，在字典名后["键"]，
   dictionary["键2"]"""
"""元组 tuple = ("元素1","元素2")  # 与列表相似，区别是列表方括号 list = ["元素1"，"元素2"]
                                # 元组不可变，不能添加和删除元素，而列表可以。"""
print("元组示例：")  # 元组无需换行符号自动换行
contacts_1 = {("张伟", 23): 15000000000,
              ("张伟", 33): 15000000001,
              ("张伟", 43): 15000000002, }
zhangwei23_phone_num = contacts_1[("张伟", 23)]
print(type(zhangwei23_phone_num))
print(zhangwei23_phone_num)
contacts_1["美女1"] = "18600000000"  # 在字典添加键值对到已有键值对后面，更新也是一样操作，比如已有键：美女1，则会覆盖后面的值
print("是否存在美女1的号码：", "美女1" in contacts_1)  # 检测在某字典是否存在某个键
# 检查字典是否存在某个值的方法较复杂，不能用 in 函数
print(contacts_1)
del contacts_1["美女1"]  # 删除键值对,如果删除的键值对本身不存在，则报错
print(contacts_1)
print("contacts_1 里面有", len(contacts_1), "组号码。")  # 测量有多少键值对
print()
print("练习：")
# slang_10_dict = {}
# '''slang_10_dict[input("请输入网络用语")] = input("请输入网络用语解释")
# print(slang_10_dict)'''
# slang_10_dict["i人" or "e人"] = "2023年，一款名为MBTI的测试在年轻人中火了起来，取代星座成为最流行的社交标签。"
# slang_10_dict["显眼包"] = "“显眼包”，原义是一个人过于张扬、爱出风头，甚至到了令人尴尬的地步。在互联网社交语境中，这个词却演变成褒义词，用来形容那些引人注目、个性鲜明的人或物。"
# slang_10_dict["特种兵旅游"] = "“特种兵旅游”，也作“特种兵式旅游”，指高强度的旅行方式，即在周末或节假日等有限的时间里，游览尽可能多的景点。其特点在于时间紧凑、"
# slang_10_dict["×门"] = "“×门”指一些人出于对某样东西超乎寻常的喜欢，遂聚集成一个虚拟阵营。"
# slang_10_dict["多巴胺"] = "“多巴胺 ××”是在2023年夏天走红的网络流行语，起源于“多巴胺穿搭”，指运用高饱和色彩展现鲜艳明亮的服装风格。"
# slang_10_dict["孔乙己文学"] = "“学历不但是敲门砖，也是我下不来的高台，更是孔乙己脱不下的长衫。”"
# slang_10_dict["公主/王子，请××"] = "“公主，请××”，源自抖音平台某博主的一个创作。“公主，请上车”这句话最早来自电影《罗马假日》记者乔·布莱德利邀请安妮公主时的台词。"
# slang_10_dict["你人还怪好的" or "你人还怪好的嘞"] = "“你人还怪好的（嘞）”，最早出自某视频博主。"
# slang_10_dict["挖呀挖呀挖"] = "“在小小的××里挖呀挖呀挖”，是由武汉幼师黄老师在抖音平台上传的童谣《花园种花》中的歌词句式。"
# # query_1 = input("请输入你想查询的网络用语网络用语")
# # if query_1 in slang_10_dict:
# #     print("你所查询的网络用语含义如下：",
# #           slang_10_dict[query_1])  # 括号包住的所以不需要\n换行,但是缩进要对齐
# # else:
# #     print("您所查询的网络用语暂未收录，请重新查询。")
# #     print("目前已收录网络用语" + str(len(slang_10_dict)) + "条。")  # len返回的是整数int,如果用+号连接就需转换为字符串str；
# #     print("目前已收录网络用语", len(slang_10_dict), "条。")  # 用逗号, 连接可以不用转化为字符串，但是整数前后都有空格
print("用逗号连接", "有空格，" + "用加号连接" + "无空格")
print()

# 第十四课：for循环，可用于列表（各元素）、字典（各键或值）、字符串（各字符）等迭代
print("——第十四课：for循环")
'''for 变量名 in 可迭代对象：
   依次序对每个变量做一些事情1  # 注意缩进
   对每个变量做一些事情2'''
temperature_dict = {"01": 36.4, "02": 38.5, "03": 37.3, "04": 36.7, }
'''temperature_dict.keys()  # 返回所有键
temperature_dict.values()  # 返回所有值
temperature_dict.items()  # 返回所有键值对'''
print("写法1")
#      ("01", 36.4) 分别对应下一行的staff_id, temperature
for staff_id, temperature in temperature_dict.items():  # 此写法将元组的第一个元素赋予staff_id，而第二个元素赋予给temperature
    if temperature >= 38:
        print("发热的员工ID为" + str(staff_id) + "。")
for staff_id, temperature in temperature_dict:  # 如果不加.items() ，字符串第一个字符赋予staff_id，而第二个字符赋予给temperature
    print("员工ID为" + str(staff_id) + "。" + temperature)
for staff_id in temperature_dict:  # 不加.items()，将键赋予给staff_id
    print("所有员工ID为" + str(staff_id) + "。")
# 以下是打印键或值或键值对的方法
for key_a in temperature_dict:  # 省略 .keys() 默认返回键 
    print(key_a, "0")
for key_b in temperature_dict.keys():  # 返回的是键
    print(key_b, "1")
for value_a in temperature_dict.values():  # 返回的是值
    print(value_a, "2")
for item_a in temperature_dict.items():  # 返回的是键值对，item_a被赋值为键值对
    print(item_a, "3")
for item_k, item_v in temperature_dict.items():  # item_k, item_v 分别被赋值为键和值
    print(item_k, item_v, "4")

print("写法2")

for temperature_tuple in temperature_dict.items():
    staff_id = temperature_tuple[0]  # temperature_tuple[0] 意为元组第一个元素
    temperature = temperature_tuple[1]  # temperature_tuple[1] 意为元组第二个元素
    if temperature >= 38:
        print("发热的员工ID为" + str(staff_id) + "。")
print()
print("range用量表示整数数列")
'''range(5,10, 2)  # 括号内第一个数为起始值，最后一个数为结束值,第三个数字表示步长（即每次跨越几个数字）
                # 需要注意的是：结束值不在序列范围内。'''
for i_1 in range(2, 10, 2):  # 结束值不在序列范围内,步长不指明时默认为1
    print(i_1)  # 显示的数列为换行显示
print("练习：高斯的数学题，从1到2到3依次加到100")
total_1 = 0
for i_2 in range(1, 101):  # 最开始定义total_1为0，第一次for循环i_2被赋值为1，total_1变量被加1;
    total_1 = total_1 + i_2  # 第二次for循环i_2被赋值为2，此时的total_1变量(第一次循环后赋值为0 + 1 =1）被加2
print(total_1)  # 以此类推，最后循环结束后得出最终的total_1的值
print()

# 第十五课：while循环
print("——第十五课：while循环")
"""while 条件A：  # 先判断条件A，循环判断A执行B直到A为假结束函数
       行动B  # 条件A为真，执行行动B，再返回判断条件A"""
# 假定measure——brightness返回当天测量的天空亮度
# measure_brightness = input("相机自动测量的天空亮度")
# while measure_brightness() >= 500:
#     print("执行take_photo")  # 拍照片
'''很多时候for 与 while 可以互用'''
list_a = ["你", "在", "哪", "里", "？"]
print("1")
for char_a in list_a:  # for 有明确的循环对象次数
    print(char_a)
print("2")
for i_1 in range(len(list_a)):
    print(list_a[i_1])
print("3")
i_1 = 0
while i_1 < len(list_a):  # while 更简洁，更危险，循环次数未知
    print(list_a[i_1])
    i_1 = i_1 + 1  # 如果忘记写这行，程序会一直循环，需要注意
print()
print("练习：写一个求平均值的计算程序")
# user_input_a.isdigit()，变量.isdigit() 判断变量是否是纯数字格式
'''num_list_a = []
num_sum = 0
print("请输入用于求平均值的数，如果需要停止输入，请输入“q”：")
user_input_a = input()
if user_input_a is "q":
    print("程序结束")
else:
    while user_input_a != "q":
        num_list_a.append(user_input_a)
        num_sum += float(user_input_a)  # 相当于num_sum = num_sum + float(user_input_a)
        print("请继续输入用于求平均值的数，如果需要停止输入，请输入“q”：")
        user_input_a = input()
    num_ave = num_sum / len(num_list_a)
    print("平均值为：" + str(num_ave))'''
print()
print("练习答案：")
# print("哈喽啊！我是求平均值小程序。\n请依次输入数字，完成数字输入后，请输入q终止程序。")
# user_input_a = input("请输入数字：")
# sum_a = 0
# count_a = 0
# while user_input_a != "q":
#     sum_a += float(user_input_a)  # sum_a = sum_a + float(user_input_a)
#     count_a += 1  # count_a = count_a + 1
#     user_input_a = input("请继续输入数字或输入q开始计算：")
# if count_a == 0:
#     print("程序结束")
# else:
#     result_average = sum_a / count_a
#     print("您求的平均值为：", result_average)
print()


# 第十六课：格式化字符串 format函数
print("——第十六课：格式化\
       字符串")
print("——第十六课：格式化\n"
      "字符串")

contacts_2 = ["老徐", "老林", "老陈", "老曾", "老李", "老张", "老王", ]
for name_a in contacts_2:
    message_content = name_a + ":岁始之乐，点翠画柳喜开颜。\
    云开雾散，良辰美景共团圆。祝福" + name_a + \
                      "及家人新年快乐，平安顺遂，虎年大吉！！"
    #   send_message(name_a, message_content)  # 假设send_message为发送短信到联系人
    print(message_content)
print("")
year_a = "龙"
for name_a in contacts_2:
    message_content = """
    律回春渐，新元肇启。
    新岁甫至，福气东来。
    金""" + year_a + """贺岁，欢乐祥瑞。
    金""" + year_a + """敲门，五福临门。
    给""" + name_a + """及家人拜年啦！
    新春快乐，""" + year_a + """年大吉！"""
    #   send_message(name_a, message_content)  # 假设send_message为发送短信到联系人
    print(message_content)
print("")
print("使用format 函数更简洁的达成上述功能指令")

print("实例A")
name_b = 'Alice'
age_b = 25
formatted_string = "My name is {0} and I am {1} years old.".format(name_b, age_b)
# {0}表示被替换的位置，数字表示用format里面的第几个参数进行替换
print(formatted_string)

print("实例B")
message_content = """
律回春渐，新元肇启。
新岁甫至，福气东来。
金{0}贺岁，欢乐祥瑞。
金{0}敲门，五福临门。
给{1}及家人拜年啦！
新春快乐，{0}年大吉！
""".format(year_a, name_a)  # {}内要输入数字表示format里第几个参数
# python3.6以前没有f字符串
# f"字符串{参数}" 等于 "字符串{}".format(参数1, 参数2)
print(message_content)

print("实例C")
# curren_year = "龙年"
# receiver_name = "老张"
message_content = """
律回春渐，新元肇启。
新岁甫至，福气东来。
金{curren_year}贺岁，欢乐祥瑞。
金{curren_year}敲门，五福临门。
给{receiver_name}及家人拜年啦！
新春快乐，{curren_year}年大吉！  
""".format(receiver_name=name_a,
           curren_year=year_a)  # 只要看关键字，即等号前面的
print(message_content)

print("实例D")
message_content = """
律回春渐，新元肇启。  
新岁甫至，福气东来。
金{year_a}贺岁，欢乐祥瑞。
金{year_a}敲门，五福临门。
给{name_a}及家人拜年啦！
新春快乐，{year_a}年大吉！  
""".format(name_a=name_a, year_a=year_a)  # 等号前面为关键字，对应{}内的关键字，等号后面为参数值
print(message_content)

print("实例E： f字符串")  # 字符串前加前缀f,{}里内容会被直接求值，添加到字符串内
year_a = "老林"
name_a = "龙"
message_content = f"""  
律回春渐，新元肇启。
新岁甫至，福气东来。
金{year_a}贺岁，欢乐祥瑞。
金{year_a}敲门，五福临门。
给{name_a}及家人拜年啦！
新春快乐，{year_a}年大吉！  
"""
print(message_content)

print("实例F： 其他字符串格式化方式")
print()
gpa_dict = {"小明": 3.251, "小花": 3.869, "小李": 2.683, "小张": 3.999}
for name_a, gpa in gpa_dict.items():
    print("{0}您好，您当前的绩点为：{1}".format(name_a, gpa))  # 不需要手动转换为字符串，format返回的是字符串
print()
for name_a, gpa in gpa_dict.items():
    print("{0}您好，您当前的绩点为：{1:.2f}".format(name_a, gpa))
    # {1:2f} format函数可以用 :.2f 指定浮点数转换字符串是保留几位小数，四舍五入
print()
for name_a, gpa in gpa_dict.items():
    print(f"{name_a}您好，您当前的绩点为：{gpa:.2f}")
    # {1:2f} f字符串 同样可以用 :.2f 指定浮点数转换字符串是保留几位小数，四舍五入
print()

# 第十七课（DRY原则，Don't Repeat Yourself）
print("——第十七课（DRY原则，Don't Repeat Yourself）")
print("自定义函数")

print("示例A")


def calculate_sector_1():  # def 函数名字():
    # 接下来是一些定义函数的代码,注意缩进；
    central_angle_1 = 160
    radius_1 = 30
    sector_area_1 = central_angle_1 / 360 * 3.1415926 * radius_1 ** 2
    print(f"此扇形的面积为：{sector_area_1}")


calculate_sector_1()  # 定义函数时，里面的代码不会被执行，只有调用函数时才会被执行
print("示例B")


def calculate_sector(central_angle, radius):  # 括号内输入变量名
    # central_angle = 160  #有变量后就不需要额外赋值了
    # radius = 30
    sector_area = central_angle / 360 * 3.1415926 * radius ** 2
    print(f"此扇形的面积为：{sector_area}")


calculate_sector(160, 30)  # 分别对应central_angle, radius
calculate_sector(60, 15)
calculate_sector(12, 30)

print()
print("作用域：函数里面定义的变量是局部变量，在函数外就无法访问了")  # 函数内变量是存在栈上的，函数结束就释放了
"""例如：
def func():
    a = 3
    print(a)  # 此时a 为局部变量，只作用于函数内
print(a)   # 函数外，运行函数前，无法访问
func()
print(a)   # 函数外，运行函数后，也无法访问
"""
print("return语句可以解决局部变量无法访问的问题")


def func():
    a_a = 3
    print(a_a)
    return a_a  # 在函数完成调用后返回变量值
    # 没写return 默认为return None


return_value_1 = func()  # 给return返回的变量赋值
print("一", func())  # return返回的变量可以赋值打印或者其他操作，进行各项操作前会先运行这个函数，比如这个函数有print，就会先把值打印出来
print(return_value_1)
'''

def func_a():
    a_aa = 4
    print(a_aa)
    # 没写return 默认为return None 空值


return_value_2 = func_a()  # 虽然return None， 但是赋值时会先运行一次func_a()，func_a()内有print（a_aa）
print("二", return_value_2)  # 同上，先运行一次函数，所以打印出a_aa，而因为没有return,所以函数外的print打印出了None

'''
"""print，append 实际上都是返回值None的函数，所以一般直接调用，不进行赋值。
而len,sum 这些都是带返回值的函数，所以需要赋值使用"""

print()
print("练习题：BMI计算程序")
"""
写一个计算BMI的函数，函数名为calculate_BMI。
1.可以计算任意体重和升高的BMI值
2.执行过程中打印一句话，“您的BMI分类为：xx”

BMI = 体重 / (身高 ** 2)

BMI分类
偏瘦：BMI <= 18.5
正常：18.5 < BMI <= 25
偏胖：25 < BMI  <= 30
肥胖：BMI>30
"""

print("作业：")
'''

def calculate_BMI():
    height_user = float(input("请输入您的身高（cm）"))
    weight_user = float(input("请输入您的体重（kg）"))
    BMI_user = weight_user / (height_user /100 ) ** 2
    print("您的BMI值为:" + format(BMI_user, ".2f") + "M/KG²；")  # str(BMI_user)
    return(BMI_user)


print("BMI计算程序:请输入q启动程序")
start_input = input()
if start_input is "q":
    print("请依照指示输入相关数据。")
    BMI_user_a = calculate_BMI()
    if BMI_user_a <= 18.5:
        print("您的BMI分类为：偏瘦。")
    elif 18.5 < BMI_user_a <= 25:  
        print("您的BMI分类为：正常。") 
    elif 25 < BMI_user_a <= 30:
        print("您的BMI分类为：偏胖。")
    else:
        print("您的BMI分类为：肥胖。")  
else:
    print("退出程序")       

'''
print("标准答案：")
'''

def calculate_bmi(height_user, weight_user):
    bmi_user = weight_user / (height_user / 100) ** 2
    if bmi_user <= 18.5:
        bmi_category = "偏瘦。"
    elif bmi_user <= 25:
        bmi_category = "正常。"
    elif bmi_user <= 30:
        bmi_category = "偏胖。"
    else:
        bmi_category = "肥胖。"
    print(f"您好，您的BMI值为：{bmi_user:.2f}，分类为：{bmi_category}。")
    return bmi_user


print("BMI计算小程序")
# height_user = float(input("请输入您的身高（cm）："))
# weight_user = float(input("请输入您的体重（kg）："))
# BMI_result = calculate_bmi()
BMI_result = calculate_bmi(float(input("请输入您的身高（cm）：")), float(input("请输入您的体重（kg）：")))
print(BMI_result)

'''
print()


# 第十八课（引用，不要重复造轮子）
print("——第十八课（引用，不要重复造轮子）")
print("Python内置函数官方文档：https://docs.python.org/zh-cn/3/library/functions.html")
print("示例a：不使用statistics模块里的median函数计算数列中位数")
'''

def median(num_list):
    sorted_list = sorted(num_list)
    n = len(num_list)
    # 如果一共有奇数个数字，取中间那个
    if n % 2 == 1:
        return sorted_list[n // 2]
    # 如果一共有偶数个数字，取中间两个的平均值
    else:
        return(sorted_list[n // 2 - 1] + sorted_list[n // 2]) / 2
    

print("此数列中位数为：", median([69, 124, -32, 27, 217]))
'''
'''
print()


print("示例b：使用statistics模块里的median函数计算数列中位数")

import statistics

print("此数列中位数为：", statistics.median([69, 124, -32, 27, 217]))
'''
print()
print("引入模块：")
'''
# 按住control加鼠标左键模块名，可以查看模块内容
# import语句

import statistics  # import 需要引入的模块

print(statistics.median([69, 124, -32, 27, 217]))  # 模块名.函数（）
print(statistics.mean([69, 124, -32, 27, 217]))

# from...import...语句

from statistics import median, mean  # from 模块名 import 函数1, 函数2   ，引用多个函数用逗号分隔

print(median([69, 124, -32, 27, 217]))  # 函数（） ，相较于前一种引入方式不需要带上模块名字
print(mean([69, 124, -32, 27, 217]))

# from...import *
# 此方法不推荐使用，如果引入两个模块且这两个模块内有名字相同的函数，容易发生冲突
from statistics import *  # 表示引入模块内所有函数

print(median([69, 124, -32, 27, 217]))  # 函数（） ，不需要带上模块名字
print(mean([69, 124, -32, 27, 217]))

"""官方模块不够用，可以引入第三方模块，但是引入前需要下载安装
网站pypi.org可以针对第三方库进行搜索。
安装时进入终端，输入： pip install 库名字
安装成功后即可使用 import 引入"""
'''
print()


# 第十九课：面向对象编程OOP:Object,Oriented,Programming
print("——第十九课：面向对象编程OOP:Object,Oriented,Programming")
"""
面向 过程 编程  # 过程时负责完成某个具体任务的代码（基本可以理解为函数）
            # 核心是把要实现的事情，拆分为一个个步骤，依次完成
            # 比如ATM机程序，如时间、金额、银行、纸币编号等各种数据容易混杂一起，不利于理解具体含义，随着程序长度和罗技复杂度增加，代码清晰度由此下降
面向对象编程  # 相比过程，它以对象为核心
            # 比如ATM机程序，面向对象并不会聚焦于第一步存钱或取钱，而是模拟真实世界，先考虑各个对象有什么性质，能做什么事情
            # 优点：1.能让参数更少，2.用对象把相关属性绑定一起，利于让程序逻辑更加清晰
# 面向对象编程：（举例理解，非能运行的代码）
#定义ATM类  # 类和对象的关系：类是创建对象的模板（可以想象成制造具体对象的图纸），对象是类的实例
class ATM:
    def __init__(self, 编号, 银行, 支行):
        self.编号 = 编号   # 属性
        self.银行 = 银行   # 属性
        self.支行 = 支行   # 属性
        
# 创建两个ATM对象
atm1 = ATM("001", "招商银行", "南苑支行")  # 属性
atm1 = ATM("002", "中国银行", "北苑支行")  # 属性


#定义纸币类  # 同上方式定义纸币类
class 纸币：
    def __init__(self, 编号, 面值, 发行年份):
        self.编号 = 编号   # 属性
        self.面值 = 面值   # 属性
        self.发行年份 = 发行年份   # 属性
        
# 创建两个ATM实例  # 在python编程中,实例是指一个类的具体实现,也就是一个类的一个具体对象。
atm1 = ATM("AA000001", "50", "2015  # 属性
atm1 = ATM("AA000002", "100", "2020")  # 属性

# 参数更少
存钱(atm1, 纸币1)  
取钱(atm2, 纸币2)        

# 更清楚属性所属的对象是什么
print(atm1.编号)  
print(纸币1.编号) 

# 直接通过对象获取与它绑定的属性
def 打印记录(交易类型, ATM对象, 纸币对象):  
    ...
    
def 存钱(ATM对象, 纸币对象)：
    打印记录("存钱", ATM对象, 纸币对象):
    ...
    
def 取钱钱(ATM对象, 纸币对象)：
    打印记录("取钱", ATM对象, 纸币对象):
    ...       

# 对象除了能绑定属性（对象的性质，或者说是放在类里面的变量）之外，还能绑定方法（对象能做些什么，或者说是放在类立面的函数）  
# 比如面对对象编程洗衣服程序
class 人：
    def 放(self, 被放的物品, 放入的物品):
    ...
    
    def 开机(self, 机器):
    
class 洗衣机:
    def __init__(self, 容量):  # 比如洗衣机的方法需要用到容量这个信息，在对象被创建时设置这个属性
        self.容量 = 容量
        
    def 清洗(self, 需要清洗的物品)
        # 需要通过容量计算清洗时长
        self.容量 = 容量  # 后面不管是那个方法需要用到容量，这个信息都不需要作物参数再被传入
    ...
    
    def 烘干(self, 需要烘干的物品)
        # 需要通过容量计算烘干时长
        self.容量 = 容量  # 作为自身属性可以直接被获取到
    ...

我 = 人()
我的洗衣机 = 洗衣机()

# 相比于面向过程编程直接聚焦于按步骤执行，面向对象编程把事物先 分解到对象身上，描述各个对象的作用，然后才是它们之间的交互
# 面向过程时编年体，面向对象是纪传体
我.放("衣服", 我的洗衣机)
我.放("洗衣粉", 我的洗衣机)
我.开机(我的洗衣机)
我的洗衣机.清洗("衣服")
我的洗衣机.烘干("衣服")

# 面向对象其他特性：封装，继承，多态
# 封装：写类的人直接将内部实现细节隐藏起来，使用类的人只通过外部接口访问和使用
    # 接口可以被大致理解为提供使用的方法
继承：面对对象编程允许创建有层次的类（就像现实中的儿子继承父亲，父亲继承爷爷），类可以有子类和父类来表示从属关系
    # 比如小学生、中学生、大学生都是学生，都有学号、年级的属性，都要去学校
        因此可以创建一个叫学生的父类，包含小学生、中学生、大学生等子类，让这些子类继承这个父类，
        这样父类的属性和方法都可以，不需要反复定义，减少代码冗余
# 多态：同样的接口，因为对象具体内容的不同，而有不同表现
    # 比如小学生、大学生都有作业要写，但是作业内容的难度不一样，
      因此写作业的方法不能直接定义在父类里面，而是要分别定义在子类里面
    # 比如你是一个大学生和一个小学生家长，你要求他们写作业，你可以一直同仁，都调用写作业的方法
      而他们会由于所属类不同，执行不同的写作业方法

# 面向对象 和 面向过程各有优劣，具体情况具体分析。
# 纯面向过程的语言：C语言（也可以面向对象）；纯面向对象的语言：JAVA      
"""
print()


# 第二十课：创建类
print("——第二十课：创建类")
"""
class Name0fClass:   # class 类的名字：
    # 接下来是一些定义类的代码
    # ...
    
# 下划线命名法（适用于变量名） 例如： user_name
# Pascal命名法（适用于类名） 例如： UserAccount, CustomerOrder, PaymentDate (首字母大写来分隔单词)

"""
print("示例")
# 类有个特殊的方法，主要作用是定义实例对象的属性
#  必须被命名为__init__(self): 前后得有两个下划线，括号内可以放任意数量的参数，
#  但是第一个参数永远是被占用的,用于表示对象自身self,它能帮你把属性的值绑定在实例对象上
'''
class CuteCat:
    def __init__(self):
        self.name_a = "Maomao"  # 这种写法表示是对象的name属性的值
        name_a = "Maomao"  #这种写法只是在给普通的name变量赋值，不会把这个值看成是对象的属性
    
    def speak(self):  # 和__init__一样，第一个参数被占用，表示对象自身self,可以让我们在方法里获取或修改对象绑定的属性。
        print("喵" * self.age)  # 字符串 乘以* 数字，表示把字符串重复那么多次；这样实现了方法调用结果，更具属性的不同而改变。


cat1 = CuteCat()  # 创建对象 类名(参数) ，这样__init__方法会被调用，并返回一个对象；调用__init__时，self不需要手动传入
print("cat1的名字：", cat1.name_a)  # 返回对象cat1绑定的name_a属性的值
# 但并不是所有CuteCate 都叫 Maomao，所以应该给__init__更加灵活的属性赋值
cat1.speak()  # 同上，也不需要手动把self传入
'''


class CuteCat:
    def __init__(self, cat_name_a, cat_age_a, cat_color_a):
        self.name_a = cat_name_a
        self.age_a = cat_age_a
        self.color = cat_color_a

    def speak(self):
        print("喵" * self.age_a)

    def think(self, content_a):
        print(f"小猫{self.name_a}在思考{content_a}……")


cat1 = CuteCat("Jojo", 2, "橙色")
cat1.think("现在去抓沙发还是去斯纸箱")
cat1.speak()
# cat2 = CuteCat("Maomao")  # 由于有多个属性，所以也需要输入多个属性，否则报错
cat2 = CuteCat("Maomao", 3, "白色")
cat2.speak()
print(cat1.name_a + "和" + cat2.name_a)
print(f"小猫{cat1.name_a}的年龄是{cat1.age_a}岁，花色是{cat1.color}")
print()
print("""
练习题：定义一个学生类
要求：1.属性包括学生姓名、学号以及语数英三科的成绩
2.能够设置学生某科的成绩
3.能够打印出该学生的所有科目成绩

""")
print("作业")


class StudentsInfo:
    def __init__(self, student_name, student_num):
        self.student_name = student_name
        self.student_num = student_num
        self.stuednt_scores = {"语文": 0, "数学": 0, "英语": 0}

    def set_score(self, course, score):  # 更新某科目分数
        if course in self.stuednt_scores:
            self.stuednt_scores[course] = score
        else:
            print("您输入的科目不存在，请重新输入：")

    # 以下添加新科目方法一次只能给一个对象添加新科目
    def set_course(self, course):  # 设置新的科目（默认成绩0）
        if course in self.stuednt_scores.keys():
            print("您添加的科目已经存在，请重新输入：")
        else:
            self.stuednt_scores[course] = 0

    def print_score(self):  # 查询学生全部科目成绩
        print(f"学生{self.student_name}（学号{self.student_num}）的成绩为：")
        for course in self.stuednt_scores:  # for 键 in 字典：  将变量赋值为某字典的键，详键for循环章节
            print(f"{course}：{self.stuednt_scores[course]}分")
        # 另一种写法：    
        # for course, score in self.stuednt_scores.items():  
        #     print(f"{course}：{score}分")    


zhangsan = StudentsInfo("张三", "10086")
zhangsan.set_score("语文", 99)
zhangsan.set_score("数学", 98)
zhangsan.set_score("英语", 97)
admin01 = StudentsInfo("管理员", "00000")
admin01.set_course("化学")
zhangsan.print_score()
admin01.print_score()


# print("请输入您的名字或者学号查询成绩：")
# student_input = input()
# if student_input.isdecimal():
#     print(f"{student1.student_name}同学您好！您的成绩为"
#           f"语文：{student1.student_chinese_score}分；"
#           f"数学：{student1.student_math_score}分；"
#           f"英语：{student1.student_english_score}分。")
#
# else:
#     student_name = StudentsInfo()
#
# print(f"{student_name}您的成绩为：\n"
#       f"")

print()
print("答案")


class Student:
    def __init__(self, name, student_id):  # 参数name, student_id 要用于后面的变量赋值，所以要写在括号内，self.grades = 确定的参数，grade 不用在括号内
        self.name = name
        self.student_id = student_id
        self.grades = {"语文": 0, "数学": 0, "英语": 0}  # 科目成绩有科目名和分数两个变量且一一对应，因此使用字典会更加简洁方便

    def set_grade(self, course, grade):  # 设置这个函数的两个参数
        if course in self.grades:
            self.grades[course] = grade  # 字典名[键] （返回course的值） = grade （将值赋予给变量grade） ，具体查看十三课字典更新
        else:
            print("输入的科目名错误，请重新输入。")

    def print_grade(self):  # 学生成绩可直接从字典self.grades获取，所以这个函数不需要设置参数
        print(f"学生{self.name}（学号：{self.student_id}）的成绩为：")
        for course in self.grades:  # .keys() 可省略, 省略 .keys() 默认返回键
            print(course + "：" + str(self.grades[course]) + "分")  # self.grades[course] 相当于返回self.grades字典中[course]的值
            # print(f"{course}:{self.grades[course]}分")  # 另外一种写法


chen = Student("小陈", "10086")
chen.set_grade("语文", 99)
chen.set_grade("数学", 99)
chen.set_grade("英语", 99)
chen.print_grade()
zeng = Student("小曾", "10021")
print(zeng.name)
zeng.set_grade("数学", 95)
print(zeng.grades)
print()


# 第二十一课：类继承
print("——第二十一课：类继承")
"""
拿人和猫举例，人和猫都是哺乳动物，
人有名字、性别、两只眼睛的属性，猫也有，猫还有尾巴这个属性；
人和猫都会吃饭，睡觉，拉屎等方法，但是人还会阅读，猫还会抓老鼠；
因此在以人和猫这两个对象建立类时，可以建立一个哺乳动物的父类（包含名字、性别、两只眼睛等属性,吃饭，睡觉，拉屎等方法）
让后再分别建立人和猫的子类（属于哺乳动物这个父类），然后继承父类的属性和方法，但是人和猫各有自己独有的属性和方法；

属性继承：子类在运行时优先调用所属类的构造方法（属性），导致只有子类的属性，
         因此可以用super().__init__(参数1,参数2) 调用父类构造函数（继承父类属性）；super()会返回当前父类，括号内不需要self
方法继承：子类在运行时优先调用所属类的方法，如果没有就往上调用父类同名的方法。
"""
print("例子：")


# 父类
class Mammal:
    def __init__(self, name, sex):
        self.name = name
        self.sex = sex
        self.num_eyes = 2

    def breathe(self):
        print(self.name + "在呼吸~")

    def poop(self):
        print(self.name + "在拉屎~")


# 子类1
class Human(Mammal):  # 注意子类类名()内要写入父类名，表示子类属于哪个父类
    def __init__(self, name, sex, clothing):
        super().__init__(name, sex)  # super()会返回当前父类，相当于引用父类的init,所以括号内不需要self
        self.color = clothing
        self.has_tail = False

    def read(self):
        print(self.name + "在阅读~")


# 子类2
class Cat(Mammal):  # 注意子类类名()内要写入父类名，表示子类属于哪个父类
    def __init__(self, name, sex, color):
        super().__init__(name, sex)  # super()会返回当前父类，相当于引用父类的init,所以括号内不需要self
        self.clothing = color
        self.has_tail = True

    def scratch_sofa(self):
        print(self.name + "在抓沙发~")


cat_a = Cat("Jojo", "男", "橘色")
print(cat_a.name)
cat_a.breathe()
print()

"""什么时候使用继承？例如：
A是B    class A(B):
人类是动物    class Human(Animal):
新能源车是车    class ElectricCar(Car):
"""

print("""类继承练习题：人力系统
      1，员工分为两类：全职员工 FullTimeEmployee、兼职员工 PartTimeEmployee。
      2，全职和兼职都有"姓名 name"、"工号 id"属性。
      3，都具有"打印信息 print_info"（打印姓名、工号）方法。
      4，全职有"月薪 monthly_salary"属性，
         兼职有"日薪 daily_salary"属性、"每月工作天数 work_days"属性。
      5，全职和兼职都有"计算月薪 calculate_monthly_pay"的方法，但具体计算过程不一样。   
      """)
print()

print("作业：")


# 员工
class Staff:
    def __init__(self, name, id_a):
        self.name = name
        self.id_a = id_a

    def print_info(self):
        print(f"员工姓名:{self.name}，工号：{self.id_a}；")


class FullTimeEmployee(Staff):
    def __init__(self, name, id_a, monthly_salary):
        super().__init__(name, id_a)  # 父类有的属性必须全部写进括号内，否则报错
        self.monthly_salary = monthly_salary

    def calculate_monthly_pay(self):
        print(f"您本月的工资（全职）为：{self.monthly_salary}元")
        return self.monthly_salary  # 可用return 直接返回月薪值，后面用print函数打印出月薪值


class PartTimeEmployee(Staff):
    def __init__(self, name, id_a, daily_salary, work_days):
        super().__init__(name, id_a)  # 如果不想继承父类某个属性，可以不用spuer()函数，直接构造子类属性
        self.daily_salary = daily_salary
        self.work_days = work_days

    def calculate_monthly_pay(self):
        print(f"您本月的工作日为：{self.work_days}天，工资（兼职）为：{self.daily_salary * self.work_days}元")
        return self.daily_salary * self.work_days  # 可用return 直接返回月薪值，后面用print函数打印出月薪值


chen_fulltime = FullTimeEmployee("陈", "001", 10000)
liu_parttime = PartTimeEmployee("刘", "002", 500, 20)
chen_fulltime.print_info()
chen_fulltime.calculate_monthly_pay()
print(chen_fulltime.calculate_monthly_pay())
liu_parttime.print_info()
liu_parttime.calculate_monthly_pay()
print(liu_parttime.calculate_monthly_pay())
print("答案同上")
print()


# 第二十二课：文件路径
print("——第二十二课：文件路径")
# print('''目录结构
# 类Unix操作系统（Linux、MacOS等），树根状：
#     根节点根目录用 以/ 斜杠表示，一起文件都存放在根目录下
# Windows操作系统：
#     每个磁盘分区都有自己的根目录，用反斜杠表示。
# 定位文件位置都可以用两种方法：绝对路径 和 相对路径
# 绝对路径是从根目录出来的路径：
#     对于类Unix系统，根目录以/斜杠开头，斜杠分隔，目标文件结尾，例：  /home/date/a.py
#     对于Windows系统，以分区名加\反斜杠开头，反斜杠分隔，目标文件结尾，例：  C:\home\data\a.py”
# 相对路径则是从一个参照位置出发，表示从某个位置来看，其他文件处于什么位置
#     使用相对位置时，用.点来表示参照文件当前所在的目录，
#     用..点点来表示上一层的父目录，
#     往上走，就用../..或..\.. ，表示当前文件所属目录的父目录的父目录
#     往下走，同样以斜杠或反斜杆来分隔路径中的目录
#     ./点斜杠可以省略，在同一目录下的文件想要相互找到彼此，可以直接使用文件名
# # 许多编辑器比如Pycharm可以直接复制文件名，右键文件，选择复制路径/引用，获得该文件觉得路径 以及以最顶层项目目录为参考的相对路径
# ''')
print()


# 第二十三课：文件操作
print("——第二十三课：文件操作")
"""
open("./data.txt")  # open("文件路径", "模式")，可以是绝对路径也可以相路径
open("/user/demo/date/txt", "r" ,encoding="utf-8")  
# 上行代码第二个参数是模式，为字符串  # 第三个参数encoding为可选参数，表示编码方式，现在文件一般的编码方式都是UTF-8，具体可查询编码方式
# 常见模式 "r" 只读模式； "w" 只写入模式,文件如果不存在则创建，存在则覆盖；"r+" 读写模式；"a" 附加模式；不写模式默认只读模式r
"w" 只写入模式,文件如果不存在则创建，存在则覆盖，会清空文件；可以使用"x" 写模式创建新文件，如果文件已存在则失败。
# 读取模式下，程序找不到你传入的文件名的话，会报一个叫FileNotFoundError的错误，提示文件不存在
# open函数执行成功会返回一个文件对象，可以后续对它进行读取或写入操作
abc = open("/user/demo/date/txt", "r" ,encoding="utf-8")
print(abc.read())  # 使用read方法读取文件对象，就会一次性读取文件里面所有内容，并以字符串形式进行返回；
# 以文本格式为例，代码喜欢txt这种纯文本，可直接转换里面内容为字符串，而不是word这种有字体、颜色的各种格式
# read一个文本一次以后再次read，会返回空值，因为第一次阅读已经读到结尾了，第二次read后面没有内容了
# 注意：文件过大的情况下不要使用read读取，read读出来的内容会占用很大内存
# 不想一次读完整个文件，可以传入一个数字，例如：
print(f.test_a.read(10)) 
# readline函数只会读取一行内容，会根据换行符来判断什么时候本行结尾，注意：“换行符”也会被当成读到的内容的一部分读取并打印
# readlines则是一次性读取文件中的所有行，并将它们存储为一个字符串列表，每个元素代表文件中的一行内容
# 读完后关闭文件的方法，文件名.close()
# 如果文本文件和程序文件处于同一级，可以使用相对路径是代码更加简洁

"""

print("文件操作1：读文件")

# test_a = open("E:\\Files\\pythonProject\\test_a.txt", "r", encoding="utf-8")  # 单斜杠会触发转义或无效转义，可以用双反斜杠
# print("1.1", test_a.read())  # 第一次，会读全部的文件内容，打印
# print("1.2", test_a.read())  # 第二次，只会读空字符，打印。因为第一次已经读到最后了
#
# test_b = open("E:\\Files\\pythonProject\\test_b.txt", "r", encoding="utf-8")
# print("2.1", test_b.read(10))   # 只会读第1-10个字节的文件内容
# print("2.2", test_b.read(10))   # 第二次会只会读第11-20个字节的文件内容
#
# test_b = open("E:\\Files\\pythonProject\\test_b.txt", "r", encoding="utf-8")  # 重新打开文件，又会从开头读取，也可用方法close关闭文件，释放资源
# print("3.1", test_b.readline())  # 只会读取一行文件，并打印，会根据换行符来判断什么时候本行结尾，注意：“换行符”也会被当成读到的内容的一部分读取并打印
# print("3.2", test_b.readline())  # 第二次读取第二行，读到结尾，也会返回空字符
# print("3.3", test_b.readlines())  # readlines则是一次性读取文件阅读起点后面的所有行，并将它们存储为一个字符串列表，每个元素代表文件中的一行内容

# 使用while循环加readline
# test_a = open("E:\\Files\\pythonProject\\test_a.txt", "r", encoding="utf-8")
# line = test_a.read()  # 读第一行
# while line != "":  # 判断当前行是否为空
#     print("4.1", line)  # 不为空则打印当前行
#     line = test_a.read()  # 读取下一行
#
# test_b = open("E:\\Files\\pythonProject\\test_b.txt", "r", encoding="utf-8")
# lines = test_b.readlines()  # 把每行内容储存到列表里
# for line in lines:  # 遍历每行内容
#     print("5.1", line)  # 打印当前行

# 关闭文件释放资源
# 方法一
# test_b.close()  # 关闭文件，释放资源；每次使用完文件后都应该关闭文件
# test_a.close()
# # 方法二可一自动关闭，with open("文件位置") as 文件名:
# with open("..\\.\\test_b.txt", "r", encoding="utf-8") as test_b:  # 相对路径：.\\为当前文件（可省略），..\\意为程序文件上一级的文件a
#     # 注意vscode相对路径设置和pycharm不一样，可在vscode里修改，文件-首选项-设置-扩展-Python-勾线Terminal:Execute In File Dir
#     print("6.1", test_b.read())  # 对文件的操作，缩进行都执行完后，文件会被自动关闭
#
# print("文件操作2：写文件")
# # 写入也要先打开文件可以with open as,也可直接open，但是记得关闭,open时，如果文件不存在存在就创建新文件，已存在就覆盖，注意慎重使用w模式
# with open("..\\test_c.txt", "w", encoding="utf-8") as test_c:  # 第一个参数文件名，第二个模式，第三个编码方式
#     test_c.write("Hello!")  # 变量名.write("字符串") 写入
#     test_c.write("Yoooo！")  # write不会默认换行，需要换行加入换行符 \n
#
# with open("..\\test_c.txt", "r", encoding="utf-8") as test_c:
#     print("1.1", test_c.read())
#
# # 如果仍使用w模式会覆盖，可以a （append）模式附加，a和w一样，如果文件不存在，则创建一个，不覆盖
# with open("..\\test_c.txt", "r+", encoding="utf-8") as test_c:  # a+文件不存在先创建，不覆盖，追加在末尾
#     print("1.2", test_c.read())  # a/a+模式从文末开始，read返回是空值；r/r+模式从开头开始
#     test_c.write("\n2Hello!")
#     test_c.write("2Yoooo！")  # write 后，文本已写到最后一行
#     print("1.3", test_c.read())  # 所以后面read返回也是空值
    
'''
r : 读取文件，若文件不存在则会报错
w: 写入文件，若文件不存在则会先创建再写入，会覆盖原文件(删除所有内容，并重新写入新的内容)
a : 写入文件，若文件不存在则会先创建再写入，但不会覆盖原文件，而是追加在文件末尾
rb,wb：分别于r,w类似，但是用于读写二进制文件
r+ : 可读、可写，文件不存在也会报错，写操作时会覆盖
w+ : 可读，可写，文件不存在先创建，会覆盖原文件(删除所有内容，并重新写入新的内容)，慎用
a+ ：可读、可写，文件不存在先创建，不会覆盖，追加在末尾   
'''
print()

    
# 第二十四课：异常处理
print("——第二十四课：异常处理")
print('''
异常类型：
1.用长度范围之外的索引：IndexError索引错误
2.数字除以0：ZeroDivisionError除零错误
3.打开文件不存在：FileNotFoundError找不到文件错误
4.错误的数据类型，比如两个字符串做加减乘除：TypeError类型错误
等等……
捕捉异常：try except
''')
# try:  # 注意，try except 从上往下运行，如果第一个excerpt已经捕捉到错误，后面的except都不会运行
#     user_weight = float(input("请输入您的体重（单位：kg）："))
#     user_height = float(input("请输入您的身高（单位：m）："))
#     user_BMI = user_weight / user_height ** 2
# except ValueError:  # 值错误：传递给函数的参数不符合函数所预期的类型或范围而引起。因此，当值无法转换或不符合预期时，python就会引发valueerror。
#     print("输入不为合理数字，请重新运行程序，并输入正确数字。")
# except ZeroDivisionError:
#     print("身高不能为0，请重新运行程序，并输入正确数字。")
# except:  # except后面不接错误类型，即为忽略所哟错误类型
#     print("发生了未知错误，请重新运行程序。")
# else:  # 没有错误时执行的语句
#     print(f"您的BMI值为：{user_BMI:.2f}KG/M²")
# finally:  # 无论错误发生与否，最终都会执行的语句
#     print("程序结束运行。")
print()


# 第二十五课：Python测试
print("——第二十五课：Python测试")
"""
assert后面接任何布尔表达式(bool)
测试时候在assert 后跟上我们认为应该为True的表达式，如果求出的值为True，无事发生，如果为False，就会产生AssertionError断言错误；
不过出现断言错误时，程序就直接停止了，所以可以专门做测试的库，一次跑多个测试用例，并且能更直观地展现哪些测试用例通过了，哪些没有。
常用Python单元测试库：unittest （自带），需要import unittest引入到测试程序里
单元测试：对软件中最小可测试单元进行验证
一般测试时会把测试代码放到独立文件里，分为实现代码和测试代码。


例如：   
# 测试文件和被测试文件处于同一文件夹下
# 实现代码  my_calculator.py
def my_adder(x, y):
    return x+ y
    
# 测试代码  test_my_calculator.py
import unittest
from my_calculator import my_adder  # from 文件名 import 函数名/类名

class TestMyAdder(unittest.Testcase):  # 创建一个类作为unittest.Testcase的子类，就能使用继承至unittest.Testcase的各种测试功能
    
    def test_positive_with_positive(self):  # 在这个类下面定义不同的测试用例，每个测试用例都是类下面的一个方法
        self.assertEqual(my_adder(5, 3), 8)  # unittest测试库里TestMyAdder类assertEqual方法，第一个参数或第二个参数相等，则通过测试，如果未通过，程序也不会炸
        
    def test_negative_with_positive(self):  # 测试用例名字必须以test_开头，unittest库会自动搜索这个开头的方法且只把这个开头的当成测试用例
        ...  # 写测试用例前，先想一想预期的my_adder行为是怎么样的
        
# 写好测试用例后，在编辑器终端输入 python -m unittest  表示运行unittest，这个库会自动搜索所有继承了unittest库里TestCase类的子类，运行它们所有以test_开头的方法，
# 然后展示测试结果；它会显示共运行了几个测试，上面的..点点，每个点都代表一个测试通过，不通过的点会变成F，同时还会详细显示是哪个文件下哪个方法造成测试失败以及失败原因

"""
print("""
unitest.TestCase类的常见测试方法：
方法                     类似于
assertEqual(A,B)        assert A == B
assertTrue(A)           asset A is True
assertIn(A,B)           assert A in B
assertNotEqual(A,B)     assert A != B
assertFalse(A)          assert A is False
assertNotIn(A,B)        assert A not in B
# assertTrue可以代替所有这些方法，但是更推荐有针对性的方法，有针对性的方法会给出更详细的失败原因
assertTrue(2 not in [1,3 - 1])    assertNotIn(2,[1,3-1])    验证2是否不在[1,3-1]这个列表里
""")
print("""
unitest.TestCase类setUp方法：  # 可以减少测试中的重复代码
运行各个测试方法前，setUp方法会被先运行一次
只需要在setUp方法里把测试对象创建好，作物当前测试类的一个属性，然后在各个方法里，就可以通过属性火球已创建好的对象，去写测试语句
""")
print("测试例子具体见shopping_list.py和test_shopping_list.py两个文件")
print()

# 第二十六课：高阶和匿名函数
print("——第二十六课：高阶和匿名函数")
print("高阶函数")


# 高阶函数：函数可以被传入函数，这种被传入的函数被称为高阶函数
def calculate_and_print(num, calculator, formatter):  # 这里把后面定义的函数作物参数传入函数
    result = calculator(num)
    formatter(num, result)
    # print(f"""
    # | 数字参数 | {num} |
    # | 计算结果 | {result} |""")


def print_wint_vertical_bar(num, result):
    print(f"""
    | 数字参数 | {num} |
    | 计算结果 | {result} |""")


def calculate_square(num):
    return num * num


def calculate_cube(num):
    return num * num * num


def calculate_plus_10(num):
    return num + 10


def calculate_times_5(num):
    return num * 5


# calculate_and_print(3, calculate_square)  # 被传入的函数直接用函数名传入，表示其本身，不用带括号的参数
# calculate_and_print(7, calculate_plus_10())  # 如果有括号，函数就被调用了，传入的就是执行结果，而不是函数本身
calculate_and_print(7, calculate_times_5, print_wint_vertical_bar)  # 这里把格式打印函数也传入作物参数,这样就可以拓展除不同打印格式

print()
print("匿名函数")
# 比如高阶函数中，有些作物参数的函数使用很少，为此需要专门定义出来且占用一个命名
# 匿名函数lambda，不需要给它命名，如同一次性物品，即用即扔

calculate_and_print(7, lambda num: num * 5, print_wint_vertical_bar)
# 使用匿名函数时，直接在调用高阶函数的括号里放上关键字lambda 变量名： 函数表达式
#                       冒号前面的变量名表示传给匿名函数的参数，冒号后面直接写要返回的结果（匿名函数不需要return）
# 有多个参数的匿名函数：  lambda num1, num2: num1 + num2
# 匿名函数能减少代码占用行数，不用起名，不用换行缩进，时候只需要一次性调用的场景
print((lambda num1, num2: num1 + num2)(2, 3))  # 匿名函数也可以被定义好后直接调用，匿名函数被括号框住，后面括号写参数
# 匿名函数局限性，    冒号后面没法写多个语句或表达式，只适用于比较简单的场景
print((lambda a: a)({1: 1}))
