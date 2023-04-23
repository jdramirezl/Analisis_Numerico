import os
import subprocess

adjecency_graph_folder = './adjecency_graph/'

output_directory = './output/bruteForce/'

script = "./algorithms/bruteForce/bruteForce"

for file in os.listdir(adjecency_graph_folder):
    with open(f"{output_directory}{file}", "w") as outfile:
        p = subprocess.Popen([script, adjecency_graph_folder + str(file)], stdout=outfile)
        p.wait()