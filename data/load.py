import pickle
import numpy as np

file = r'/home/kurogawa/Desktop/.git/Vinny-the-Primate/data/data1.bin'
with open(file, 'rb') as f:
    characters = pickle.load(f)
    print('characters =', characters)
    questions = pickle.load(f)
    print('questions =', questions)
    Data = pickle.load(f)
    print('Data =', Data)
