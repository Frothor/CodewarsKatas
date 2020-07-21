def max_sequence(arr):
    best = 0
    sum = 0
    for e in arr:
        sum = max(e, sum + e)
        best = max(best, sum)
    return best
