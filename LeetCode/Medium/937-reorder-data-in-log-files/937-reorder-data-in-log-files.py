class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        digit_logs , letter_logs = [] , []
        for log in logs:
            if log.split()[1].isdigit():
                digit_logs.append(log)
            else:
                letter_logs.append(log)
        
        letter_logs.sort(key= lambda letter_log : (letter_log.split()[1:], letter_log.split()[0]))
        return letter_logs + digit_logs