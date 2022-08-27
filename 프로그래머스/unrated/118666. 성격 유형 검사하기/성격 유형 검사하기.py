def solution(surveys, choices):
    answer = ''
    character = ["RT","CF","JM","AN"]
    character_type = {1:"RT", 2:"CF", 3:"JM", 4:"AN"}
    exam_character_type = { c:0 for ch in character for c in ch}
    for choice, survey in zip(choices, surveys):
        if choice == 4:
            continue
        
        if choice < 4:
            exam_character_type[survey[0]]+= (4 - choice)
        else:
            exam_character_type[survey[1]]+= (choice - 4)

    for idx, tp in character_type.items():
        if exam_character_type[tp[0]] >= exam_character_type[tp[1]]:
            answer += tp[0]
        else:
            answer += tp[1]
    
    return answer