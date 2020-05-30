import numpy as np
import pickle

characters = ['Frodo', 'Boza', 'Amy', 'Your Mum']
questions = ['Is your character male?', 'Is your character real?']

Data = np.array([[1, 0], [1, 1], [0, 0], [0, 1]], dtype="float32")

file = r'/home/kurogawa/Desktop/.git/Vinny-the-Primate/data/data1.bin'

pickle.dump(characters, open(file, 'wb'))
with open(file, 'ab') as f:
    pickle.dump(questions, f)
    pickle.dump(Data, f)
