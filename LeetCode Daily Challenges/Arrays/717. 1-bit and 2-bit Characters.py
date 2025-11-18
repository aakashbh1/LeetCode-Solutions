class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        i = 0
        n = len(bits)
        
        while i < n - 1:        # stop at second last index
            if bits[i] == 1:
                i += 2          # 2-bit character
            else:
                i += 1          # 1-bit character
                
        # If you end exactly at the last bit, it's a 1-bit character
        return i == n - 1
