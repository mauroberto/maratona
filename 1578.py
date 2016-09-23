n = int(input())

cont = 4
for h in range(0, n):
	matriz = []
	m = int(input())
	for i in range(0,m):
		l = input()
		matriz.append(l.split(" "))
		
	matrizTamanho = []
	for i in range(0,m):
		matrizTamanho.append(0)

	for j in range(0,m):
		for i in range(0,m):
			it = int(matriz[j][i])
			v = it*it
			matriz[j][i] = v
			t = len(str(v))
			if t > matrizTamanho[i]:
				matrizTamanho[i] = t

	print("Quadrado da matriz #"+str(cont)+":")

	cont += 1
	for i in range(0,m):
		for j in range(0,m):
			v = matriz[i][j]
			t = matrizTamanho[j] - len(str(v))
			for k in range(t):
				print(" ", end="")
			if(j != m-1):
				print(str(v)+" ", end="")
			else:
				print(str(v), end="")
		print("")
	if(h != n-1):
		print("")				
