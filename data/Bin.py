list = [12, 34, 200, 255]

file = r'/home/kurogawa/Desktop/.git/Vinny-the-Primate/data/data1.txt'
buffer = bytes(list)

with open(file, 'bw') as f:
    f.write(buffer)
print('done!')
