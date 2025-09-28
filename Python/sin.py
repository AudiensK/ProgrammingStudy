import numpy as np
import matplotlib.pyplot as plt

# 设置支持中文显示的字体
plt.rcParams["font.family"] = ["SimHei", "WenQuanYi Micro Hei", "Heiti TC"]
# 解决负号显示问题
plt.rcParams['axes.unicode_minus'] = False

# 创建一个从0到2π的100个点的数组
x = np.linspace(0, 2 * np.pi, 100)
# 计算正弦值
y_sin = np.sin(x)

# 创建图形
plt.figure(figsize=(10, 5))
plt.plot(x, y_sin, label='正弦曲线', color='b')
plt.title('正弦曲线y = sin(x)')
plt.xlabel('角度 (弧度)')
plt.ylabel('函数值')
plt.axhline(0, color='black', linewidth=0.5, ls='--')
plt.axvline(0, color='black', linewidth=0.5, ls='--')
plt.grid()
plt.legend()
plt.show()