def f(x):
	if x < 2:
		return
	print x
	f(x-1)
def g(y):
	if y < 2  :
		return 
	print y
	f(y)
	g(y-1)
g(5)

