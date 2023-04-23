import os
import numpy as np
import matplotlib.pyplot as plt

# Define the paths to the directories containing the files
data_dir3 = '.\\output\\greedy'
data_dir2 = '.\\output\\bruteForce'
data_dir = '.\\output\\nearestNeighbor'

dirs = [data_dir, data_dir2, data_dir3]
colors = ['b', 'g', 'r'] # color for each directory

# Create empty lists to hold the time data and the actual results
times = []
actual_results = []

# Iterate over each directory
for i, data_dir in enumerate(dirs):
    # Create empty lists for the times and results for this directory
    dir_times = []
    dir_results = []
    # Iterate over each file in the directory
    for filename in os.listdir(data_dir):
        # Construct the full path to the file
        filepath = os.path.join(data_dir, filename)
        # Read the time and result data from the file
        with open(filepath, 'r') as f:
            point = float(f.readline().strip().split()[0])
            time = float(f.readline().strip().split()[-1])
        # Add the time and result data to the lists for this directory
        dir_times.append(time)
        dir_results.append(point)
    # Add the lists of times and results for this directory to the overall lists
    times.append(dir_times)
    actual_results.append(dir_results)

# Create a bar plot of the time data for each directory
fig, ax = plt.subplots()
width = 0.25 # width of the bars
x = np.arange(len(times[0]))
for i, dir_times in enumerate(times):
    ax.bar(x + i*width, dir_times, width, color=colors[i], label=f"Directory {i+1}")
import os
import numpy as np
import matplotlib.pyplot as plt

# Define the paths to the directories containing the files
data_dir3 = '.\\output\\greedy'
data_dir2 = '.\\output\\bruteForce'
data_dir = '.\\output\\nearestNeighbor'

dirs = [data_dir, data_dir2, data_dir3]
colors = ['b', 'g', 'r'] # color for each directory

# Create empty lists to hold the time data and the actual results
times = []
actual_results = []

# Iterate over each directory
for i, data_dir in enumerate(dirs):
    # Create empty lists for the times and results for this directory
    dir_times = []
    dir_results = []
    # Iterate over each file in the directory
    for filename in os.listdir(data_dir):
        # Construct the full path to the file
        filepath = os.path.join(data_dir, filename)
        # Read the time and result data from the file
        with open(filepath, 'r') as f:
            point = float(f.readline().strip().split()[0])
            time = float(f.readline().strip().split()[-1])
        # Add the time and result data to the lists for this directory
        dir_times.append(time)
        dir_results.append(point)
    # Add the lists of times and results for this directory to the overall lists
    times.append(dir_times)
    actual_results.append(dir_results)

# Create a bar plot of the time data for each directory
fig, ax = plt.subplots()
width = 0.25 # width of the bars
x = np.arange(len(times[0]))
for i, dir_times in enumerate(times):
    ax.bar(x + i*width, dir_times, width, color=colors[i], label=f"Directory {i+1}")
plt.xticks(rotation=90)
ax.set_xticks(x + width / 2)
ax.set_xticklabels([filename.split('.')[0] for filename in os.listdir(data_dir)])
ax.legend()
ax.set_xlabel('Testcase')
ax.set_ylabel('Time (s)')
ax.set_title('Comparison of Times across Directories')
plt.show()

# Create a bar plot of the actual results vs the predicted results for each directory
fig, ax = plt.subplots()
width = 0.25 # width of the bars
x = np.arange(len(actual_results[0]))
for i, dir_results in enumerate(actual_results):
    ax.bar(x + i*width, dir_results, width, color=colors[i], label=f"Directory {i+1}")
plt.xticks(rotation=90)
ax.set_xticks(x + width / 2)
ax.set_xticklabels([filename.split('.')[0] for filename in os.listdir(data_dir)])
ax.legend()
ax.set_xlabel('Testcase')
ax.set_ylabel('Result')
ax.set_title('Comparison of Results across Directories')
plt.show()
