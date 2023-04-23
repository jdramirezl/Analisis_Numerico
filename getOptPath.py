import os
import tsplib95

test_case_folder = './testcases/'

adjecency_graph_folder = './adjecency_graph/'

for file in os.listdir(test_case_folder):
    filename, file_extention = file.split(sep='.')[0], file.split(sep='.')[1]
    if file_extention != 'opt':
        continue
    problem = tsplib95.load(test_case_folder + filename + '.tsp')
    solution = tsplib95.load(test_case_folder + file)
    optimum = 0
    solution = solution.as_dict()['tours'][0]
    try:
        for i in range(len(solution) - 1):
            optimum += problem.get_weight(solution[i], solution[i + 1])
        with open(f"./optimal/{filename}.optimal", "a") as outfile:
            print(optimum)
            outfile.write(str(optimum))
    except:
        pass
    