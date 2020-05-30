frodo = '-male-fiction-book-magic-frodo'
boza = '-male-real-student-math-boza'
amy = '-female-fiction-wife-criminal-amy'


characters = [frodo, boza, amy]

def search(trait):
    
    characters_new = []

    for i in characters:
        if trait in i:
            characters_new.append(i)

    return characters_new

x=input('Is your character real?')
if x=='y':
    characters=search('-real-')
else:
    characters=search('-fiction-')

x=input('Is your character male?')
if x=='y':
    characters=search('-male-')
else:
    characters=search('-female-')

print(characters)
