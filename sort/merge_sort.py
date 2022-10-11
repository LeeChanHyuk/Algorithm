from sys import stdin

# 계속 나누고, 합칠 때는 두 개의 배열 중 낮은 것 부터 채우면서 합치기.

target_array = [10, 5, 1, 2, 3]
temp_array = [0] * len(target_array)

def merge(start, end):
    mid = (start + end) // 2
    idx_l = start
    idx_r = mid

    for i in range(start, end, 1):
        if idx_l >= mid:
            temp_array[i] = target_array[idx_r]
            idx_r += 1
        elif idx_r >= end:
            temp_array[i] = target_array[idx_l]
            idx_l += 1
        elif target_array[idx_l] < target_array[idx_r]:
            temp_array[i] = target_array[idx_l]
            idx_l += 1
        else:
            temp_array[i] = target_array[idx_r]
            idx_r += 1
    for i in range(start, end, 1):
        target_array[i] = temp_array[i]


def merge_sort(start, end):
    if end-start == 1:
        return
    else:
        mid = (start + end) // 2
        merge_sort(start, mid)
        merge_sort(mid, end)
        merge(start, end)
    
merge_sort(0, len(target_array))
print(target_array)
