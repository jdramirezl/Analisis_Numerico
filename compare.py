import os
import matplotlib.pyplot as plt

# Define the paths to the directories containing the files
results_dir = '.\\optimal'
# data_dir = '.\\output\\greedy'
# data_dir = '.\\output\\bruteForce'
data_dir = '.\\output\\nearestNeighbor'

# Create empty lists to hold the time data and the actual results
times = []
actual_results = []
results = []

interval = 5  # Set the interval percentage
results_dict = {}

scores = [0 for i in range(7)]
# Iterate over each file in the data directory
for filename in os.listdir(data_dir):
    # print("filename: ", filename)
    # Construct the full path to the file
    filepath = os.path.join(data_dir, filename)
    result_filepath = os.path.join(results_dir, filename)
    result_filepath = result_filepath.replace('.tsp', '.optimal')
    
    if not os.path.exists(result_filepath):
        continue 

    # Read the time data from the file
    # print("filepath: ", filepath)
    with open(filepath, 'r') as f:
        point = float(f.readline().strip().split()[0])
        time = float(f.readline().strip().split()[-1])
        results.append(point)
        times.append((filename, time))  # Store the filename along with the time

    # Read the actual result from the corresponding file in the results directory
    # print("result_filepath: ", result_filepath)
    with open(result_filepath, 'r') as f:
        actual_result = float(f.readline().strip())
        actual_results.append(actual_result)
    print("filename: ", filename)
    print("Result: ", point, "Actual Result: ", actual_result)
    print("dif",(abs((actual_result - point) / actual_result)) * 100)
    
    # Calculate the percentage differential between the actual and predicted results
    percent_diff = (abs((actual_result - point) / actual_result)) * 100
    percent_diff_range = f"{int(percent_diff / interval) * interval}-{int(percent_diff / interval) * interval + interval - 1}%"
    
    # Add the result to the dictionary based on the percentage differential range
    if percent_diff_range not in results_dict:
        results_dict[percent_diff_range] = 1
    else:
        results_dict[percent_diff_range] += 1

print("scores: ", [i for i in sorted(results_dict.items(), key=lambda x: int(x[0].split('-')[0]))])

# Sort the times in ascending order
times.sort(key=lambda x: x[1])

# Create a plot of the time data
plt.figure()
plt.bar([t[0] for t in times], [t[1] for t in times])
plt.xticks(rotation=90)
plt.title('Times')
plt.xlabel('File Name')
plt.ylabel('Time (s)')
plt.show()

# Create a plot of the actual results vs the predicted results
plt.figure()
colors = ['r' if p > a else 'g' for p, a in zip(results, actual_results)]  # Determine the color for each bar
plt.bar([t[0] for t in times], results, color='r')
plt.bar([t[0] for t in times], actual_results, color='g')
plt.xticks(rotation=90)
plt.title('Actual Results vs Predicted Results')
plt.xlabel('File Index')
plt.ylabel('Result')
plt.show()