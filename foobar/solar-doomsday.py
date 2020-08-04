def solution(area):
    list = []
    while area != 0:
        list.append((int(area ** 0.5)*int(area ** 0.5)))
        area -= (int(area ** 0.5)*int(area ** 0.5))
    return list
