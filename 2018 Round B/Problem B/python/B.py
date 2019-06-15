def do_case():
	# input()
	# int(input())
	N, K, P = list(map(int, input().split()))

	constraints = []
	for i in range(K):
		A, B, C = list(map(int, input().split()))
		constraints.append([A, B, C])
	
	# small
	out = [None] * N
	for A, B, C in constraints:
		assert A == B
		out[A-1] = str(C)

	nones = sum(i is None for i in out)
	zeroes = bin(P-1)[2:].zfill(nones)

	c = 0
	for i in range(N):
		if out[i] is None:
			out[i] = zeroes[c]
			c += 1

	assert c == nones


	return "".join(out)

T = int(input())
for case in range(T):
	ans = do_case()
	print("Case #{}: {}".format(case+1, ans))
