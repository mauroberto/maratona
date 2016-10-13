s = input()

c = 0
media = 0

for e in s:
    if e >= '1' and e <= '9':
        media += int (e)
        c+=1
    else:
        media += 9


media = media/c

print ("%.2f" % media)
