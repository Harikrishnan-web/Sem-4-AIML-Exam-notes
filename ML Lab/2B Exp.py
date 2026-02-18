import numpy as np
import csv

def read_data(filename):
    with open(filename, 'r') as csvfile:
        datareader = csv.reader(csvfile, delimiter=',')
        headers = next(datareader)
        traindata = [row for row in datareader]
    return np.array(headers), np.array(traindata, dtype=object)

class Node:
    def __init__(self, attribute):
        self.attribute = attribute
        self.children = []
        self.answer = ""

def subtables(data, col, delete):
    items = np.unique(data[:, col])
    table_dict = {}
    for item in items:
        subset = data[data[:, col] == item]
        if delete:
            subset = np.delete(subset, col, axis=1)
        table_dict[item] = subset
    return items, table_dict

def entropy(S):
    items, counts = np.unique(S, return_counts=True)
    probs = counts / counts.sum()
    return -np.sum(probs * np.log2(probs))

def information_gain(data, col):
    total_entropy = entropy(data[:, -1])
    items, table_dict = subtables(data, col, delete=False)
    weighted_entropy = 0
    for item in items:
        subset = table_dict[item]
        weighted_entropy += (len(subset) / len(data)) * entropy(subset[:, -1])
    return total_entropy - weighted_entropy

def create_node(data, metadata):
    if len(np.unique(data[:, -1])) == 1:
        leaf = Node("")
        leaf.answer = data[0, -1]
        return leaf

    if data.shape[1] == 1:
        leaf = Node("")
        counts = np.unique(data[:, -1], return_counts=True)
        leaf.answer = counts[0][np.argmax(counts[1])]
        return leaf

    gains = [information_gain(data, col) for col in range(data.shape[1] - 1)]
    split = np.argmax(gains)
    
    node = Node(metadata[split])
    items, table_dict = subtables(data, split, delete=True)
    new_metadata = np.delete(metadata, split)
    
    for item in items:
        child = create_node(table_dict[item], new_metadata)
        node.children.append((item, child))
    return node

def print_tree(node, level=0):
    if node.answer != "":
        print("  " * level + "ANS: " + node.answer)
        return
    print("  " * level + str(node.attribute))
    for value, child in node.children:
        print("  " * (level + 1) + f"[{value}]")
        print_tree(child, level + 2)

metadata, data = read_data("tennis.csv")
tree = create_node(data, metadata)
print_tree(tree)
