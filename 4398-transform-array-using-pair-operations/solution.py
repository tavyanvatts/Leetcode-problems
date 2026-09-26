class Solution:
    def canTransform(self, source: list[int], target: list[int]) -> bool:
        sum1 = sum(source)
        sum2 = sum(target)
        return (sum1 == sum2)
