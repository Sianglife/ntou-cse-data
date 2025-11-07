arr = [3, 2, 5, 4, 1]
n = len(arr)

def merge(L, R):
    merged = []
    lcnt, rcnt = 0, 0
    while lcnt < len(L) and rcnt < len(R):
        if L[lcnt] <= R[rcnt]:
            merged.append(L[lcnt])
            lcnt += 1
        else:
            merged.append(R[rcnt])
            rcnt += 1
    while lcnt < len(L):
        merged.append(L[lcnt])
        lcnt += 1
    while rcnt < len(R):
        merged.append(R[rcnt])
        rcnt += 1
    return merged

def merge_sort(arr, n):
    if n <= 1:
        return arr
    L = merge_sort(arr[0:int(n/2)], int(n/2))
    R = merge_sort(arr[int(n/2):n], n - int(n/2))
    return merge(L, R)

sorted_arr = merge_sort(arr, n)
print(sorted_arr)
