import numpy as np
from scipy import optimize as op


def arr():
    z = np.array([2, 3, -5])
    aeq = np.array([[1, 1, 1]])
    beq = np.array([7])
    print("这是一个中文测试")
    print("测试merge是否正常")
    print("测试merge是否正常2")
    print("测试merge是否正常3")
    a = np.array([[-2, 5, -1], [1, 3, 1]])
    b = np.array([-10, 12])
    x1, x2, x3 = (0, None), (0, None), (0, None)
    res = op.linprog(-z, a, b, aeq, beq, bounds=(x1, x2, x3), method='highs')
    print(res)
    print("这句话是第二句在ipad完成的")
    print("这句话是第三句在ipad完成的")
# 测试用户名改动
arr()
