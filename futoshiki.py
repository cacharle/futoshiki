import numpy as np

def is_full(square):
    return all([x != 0 for row in square for x in row])

def next_empty(square):
    for i in range(len(square)):
        for j in range(len(square)):
            if square[i, j] == 0:
                return i, j
    return None, None

def valid(square, row, col, n):
    for i in range(len(square)):
        if square[col][i] == n or square[i][row] == n:
            return False
    return True

def solve(square, comparisons):
    # print("rec")
    print(square)
    print()

    if is_full(square):
        # print("full")
        # print(square)
        return False

    i, j = next_empty(square)
    print(i, j)
    for n in range(1, len(square) + 1):
        if not valid(square, i, j, n):
            continue
        # print("n:", n)
        square_copy = square.copy()
        square_copy[i, j] = n
        # print(square_copy)
        if solve(square_copy, comparisons):
            return False
    # return False






if __name__ == '__main__':
    # init_square = np.array([
    #     [4, 0, 0, 2],
    #     [0, 1, 0, 0],
    #     [0, 0, 0, 0],
    #     [0, 0, 0, 4]
    # ])
    init_square = np.array([
        [0, 0, 0, 0],
        [0, 0, 0, 0],
        [0, 0, 0, 0],
        [0, 0, 0, 0]
    ])
    init_square = np.array([
        [0, 0], [0, 0]])
    init_comparisons = []
    solve(init_square, init_comparisons)
