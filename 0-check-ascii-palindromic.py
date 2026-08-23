class Solution:
    def isPalindromic(self, s: str) -> bool:
        ascii_str = ""
        ascii_str_list = []
        for ch in s:
            ascii_ch = format(ord(ch), '08b')
            ascii_str_list.append(ascii_ch)

        ascii_str = ''.join(ascii_str_list)

        return ascii_str == ascii_str[::-1]