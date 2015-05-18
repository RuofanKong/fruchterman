import numpy as np
import fruchterman_v3

#matrix = [[0]*5 for i in range(5)]


arr = np.array( [
        [1, 0, 0, 1, 1],
        [0, 1, 0, 0, 1],
        [0, 0, 1, 0, 0],
        [1, 0, 0, 1, 1],
        [1, 1, 0, 1, 1],
])

print "The original adjacency matrix is: "
print arr;

res = [[0] * len(arr) for i in range(3)];

res = fruchterman_v3.fruchterman_reingold_layout(arr, len(arr), 100, 100, 100);

print "The coordinate for each vertex is: "
print res;
