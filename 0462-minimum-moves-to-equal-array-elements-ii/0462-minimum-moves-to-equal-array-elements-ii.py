class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        kitneBande = len(nums)

        if kitneBande == 1:
            return 0

        nums.sort()
        beechWalaBhai = nums[kitneBande // 2]
        totalKalesh = 0

        for ekBanda in nums:
            totalKalesh += abs(ekBanda - beechWalaBhai)

        return totalKalesh