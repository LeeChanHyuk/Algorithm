from sys import stdin

target_array = [1, -5, 2, 3, 4]

def swap(idx_l, idx_r):
    temp = target_array[idx_l]
    target_array[idx_l] = target_array[idx_r]
    target_array[idx_r] = temp

def quick_sort(start, end):
    if end-start == 1:
        return
    else:
        pivot = target_array[start]
        idx_l = start + 1
        idx_r = end - 1
        while idx_l <= idx_r:
            while target_array[idx_l] < pivot and idx_l <= idx_r:
                idx_l += 1
            while target_array[idx_r] > pivot and idx_l <= idx_r:
                idx_r -= 1
            if idx_l < idx_r:
                swap(idx_l, idx_r)
        swap(start, idx_r)
        quick_sort(start, idx_r)
        quick_sort(idx_r+1, end)