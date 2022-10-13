

def solution(elements):
    answer = 0
    total = sum(elements)
    sum_of_elements = set()
    for i in range(len(elements)):
        sub_total = total
        for element in elements:
            sub_total -= element
            sum_of_elements.add(sub_total)
        elements.insert(0, elements.pop())
    return len(sum_of_elements)