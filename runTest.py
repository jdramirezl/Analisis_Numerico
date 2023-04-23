import os
import subprocess

test_case_folder = './testcases/'

adjecency_graph_folder = './adjecency_graph/'

for file in os.listdir(adjecency_graph_folder):
    with open(f"./output/{file}", "w") as outfile:
        p = subprocess.Popen(["./algorithms/nearest-neighbor", adjecency_graph_folder + str(file)], stdout=outfile)
        p.wait()