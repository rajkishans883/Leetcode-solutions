class Solution:
    def minElement(self, nums: List[int]) -> int:
        length_list=len(nums)
        min_value=sys.maxsize

        for digit in nums:
            sum=0
            i=0
            while digit>0:
                sum=sum+(10**i)*(digit%10)
                digit=int(digit/10)
            min_value=min(sum,min_value)
        
        return min_value

