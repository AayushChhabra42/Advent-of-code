import re

with open("Advent-of-code\day3\input.txt","r") as f:
    data = f.read()
    pattern = r"mul\(\d*,\d*\)"
    string=re.findall(pattern,data)
    print(len(string))
    res=0
    for i in string:
        num_pairs=i[4:-1].split(",")
        num_pairs = [int(x) for x in num_pairs]
        res+=num_pairs[0]*num_pairs[1]
    print(res)