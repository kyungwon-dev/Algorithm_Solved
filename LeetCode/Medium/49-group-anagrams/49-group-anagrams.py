
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagram = {}
        for s in strs:
            sort_str = "".join(sorted(s))
            if sort_str not in anagram:
                anagram[sort_str] = [s]
            else:
                anagram[sort_str].append(s)
                
        # return sorted([v for _, v in anagram.items()], key=len)
        return [v for _, v in anagram.items()]