'''
You are given two strings a and b that consist of lowercase letters. In one operation, you can change any character in a or b to any lowercase letter.

Your goal is to satisfy one of the following three conditions:

Every letter in a is strictly less than every letter in b in the alphabet.
Every letter in b is strictly less than every letter in a in the alphabet.
Both a and b consist of only one distinct letter.

Return the minimum number of operations needed to achieve your goal.
'''



def minCharacters(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: int
        """
        cond_1 = 0
        cond_2 = 0
        cond_3 = 0

        max_a = max(a)
        max_b = max(b)
        max_freq_lett_a = check_max_character_appearance(a)
        max_freq_lett_b = check_max_character_appearance(b)
        for i in a:
                if i <= max_b:
                    cond_2 += 1
        for i in b: 
                if i <= max_a:
                    cond_1 += 1
        
        return(min(cond_1, cond_2, cond_3))



def check_max_character_appearance(S):
        all_freq = {}
        for i in S:
            if i in all_freq:
                all_freq[i] += 1
            else:
                all_freq[i] = 1
        return max(all_freq.values())



