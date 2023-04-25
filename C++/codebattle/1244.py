def dfs(d, cnt):
    global ret
    if cnt == n:
        ret = max(int("".join(nums)), ret)
        return
    for i in range(d, l):
        for j in range(i + 1 , l):
            if nums[i] <= nums[j]:
                nums[i], nums[j] = nums[j], nums[i]
                dfs(i, cnt + 1)
                nums[i], nums[j] = nums[j], nums[i]

T = int(input())

for test_case in range(1, T + 1):
    nums, n = input().split()
    nums = list(nums)
    numbers = nums[:]
    n = int(n)
    l = len(nums)
    ret = 0
    flag = 0
    if len(nums) == 2 or nums == sorted(nums, reverse=True):
        cnt = 0
        while cnt != n:
            numbers[-1], numbers[-2] = numbers[-2], numbers[-1]
            cnt += 1
        flag = int("".join(numbers))
    cnt = 0
    dfs(0, cnt)
    if ret == 0:
        ret = flag
    print("#" + str(test_case) + " " + str(ret))