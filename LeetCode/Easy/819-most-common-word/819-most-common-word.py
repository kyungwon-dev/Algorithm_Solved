from collections import Counter
import re

class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        paragraph = [param for param in re.sub(r'[^\w]', ' ', paragraph).lower().split() if param not in banned]
        return Counter(paragraph).most_common(1)[0][0]
        