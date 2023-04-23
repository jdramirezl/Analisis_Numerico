import tsplib95

import os

test_case_folder = './testcases/'

adjecency_graph_folder = './adjecency_graph/'

for file in os.listdir(test_case_folder):
    file_extention = file.split(sep='.')[1]
    num = ""
    for c in file:
        if c.isdigit():
            num += c

    if num == '' or int(num) > 1000 or file_extention == 'opt':
        continue
    print(file)
    problem = tsplib95.load(test_case_folder + file)
    

    with open(adjecency_graph_folder + file, "w") as file:
        file.write(str(num) + '\n')
        for key, adjecent in problem.get_graph().adjacency():
            for node in adjecent:
                file.write(str(adjecent[node]['weight']) + ' ')
            file.write('\n')




