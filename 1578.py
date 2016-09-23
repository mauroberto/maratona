n = int(input())

matriz = []

cont = 4
for i in range(n):
	m = int(input())
	for i in range(m):
		l = input()
		matriz.append(l.split(" "))
		
	matrizTamanho = []
	for i in range(m):
		matrizTamanho.append(0)

	for j in range(m):
		for i in range(m):
			v = (int(matriz[j][i]) * int(matriz[j][i]))
			matriz[j][i] = v
			t = len(str(v))
			if t > matrizTamanho[i]:
				matrizTamanho[i] = t

	print("Quadrado da matriz #"+str(cont)+":")

	cont += 1
	for i in range(m):
		for j in range(m):
			v = matriz[i][j]
			t = matrizTamanho[j] - len(str(v))
			for k in range(t):
				print(" ", end="")
			print(str(v)+" ", end="")
		print("")				
