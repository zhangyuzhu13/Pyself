def mywhile():
	i = 10
	while (i > 0):
		i -= 1
		if (i < 3):
			break
	for i in range(10):
		try:
			x = 3
		except IOError:
			print("x")


