frodo = '-male-fiction-book-magic-frodo'
boza = '-male-real-student-math-boza'
amy = '-female-fiction-wife-criminal-amy'
# Suggestion: characters should be a a class on its own, with its data
# stored within a separate file for faster loading.

characters = [frodo, boza, amy]

def search(trait):

    characters_new = []

    for i in characters:
        if trait in i:
            characters_new.append(i)

    return characters_new

def nsearch(trait):

    characters_new = []

    for i in characters:
        if trait not in i:
            characters_new.append(i)

    return characters_new

questions=[]
attributes=[]

f=open("questions.txt", "r")
if f.mode == 'r':
    for i in f.readlines():
        questions.append(i[0:53].strip())
        attributes.append(i[53:].strip())


for i in range(0, len(questions)):
    x=input(questions[i])
    if x=='y':
        characters=search(attributes[i])
    else:
        characters=nsearch(attributes[i])

print(characters)
