import random
import sys

## Generates a random dense matrix
## Use: python randomMatrix.py M N

if (len(sys.argv) > 1):

  M = int(sys.argv[1])
  N = M

  ans = [ 0 for i in range(M) ]
  b = [ 0 for i in range(M) ]
  table2 = [ [ 0 for i in range(N) ] for j in range(M) ]

  for i in range(M):
	ans[i] = random.random()
	b[i] = 0
  
  for i in range(M):
    for j in range(N):
		if i <= j:
			table2[i][j] = random.random()
			if i < j:
				if random.random() < 0.95 :
					table2[i][j] = 0
			table2[j][i] = table2[i][j]

  f = open('matrix','w');
  for i in range(M):
    for j in range(N):
		##table2[i][j] = random.random()
		f.write(str(table2[i][j]))
		f.write('\t')
		b[i] += table2[i][j] * ans[j]
    f.write('\n')
		
  for i in range(M):
	f.write(str(b[i]))
	f.write('\n')
  f.close()

  f = open('ans', 'w')
  for i in range(M):
	f.write(str(ans[i]))
	f.write('\n')
  f.close()




else:

  print "please input a number"

