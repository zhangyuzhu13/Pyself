def mytry():
	try:
		x = 1
		y = 2
	except:
		x = 0
		y = 1
		for i in range(10):
			print(i)
			if i == 3:
				break
def mytf():
	try:
		x = 1
	except:
		x = 3
		for i in range(10):
			if i == 3:
				break
	finally:
		x = 5;
		if x == 4:
			print(x)
	for i in range(10):
		if i == 2:
			break
