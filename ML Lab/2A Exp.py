import numpy as np
import math
import csv

def read_data(filename):
    with open(filename, "r") as csvfile:
        datareader = csv.reader(csvfile)
        headers = next(datareader)
        data = [row for row in datareader]
    return np.array(headers), np.array(data)

class Node:
    def __init__(self, attribute=None):
        self.attribute = attribute
        self.children = {}
        self.answer = None

    def __str__(self):
        return str(self.attribute)

def subtables(data, col, delete=True):
    values = np.unique(data[:, col])
    tables = {}
    for value in values:
        rows = data[data[:, col] == value]
        if delete:
            rows = np.delete(rows, col, axis=1)
        tables[value] = rows
    return values, tables

def entropy(labels):
    values, counts = np.unique(labels, return_counts=True)
    total = labels.size
    e = 0
    for count in counts:
        p = count / total
        e -= p * math.log2(p)
    return e

def gain_ratio(data, col):
    total_entropy = entropy(data[:, -1])
    values, tables = subtables(data, col, delete=False)
    total = data.shape[0]
    gain = total_entropy
    split_info = 0
    for value in values:
        subset = tables[value]
        ratio = subset.shape[0] / total
        gain -= ratio * entropy(subset[:, -1])
        split_info -= ratio * math.log2(ratio)
    if split_info == 0:
        return 0
    return gain / split_info

def create_tree(data, metadata):
    labels = data[:, -1]
    if len(np.unique(labels)) == 1:
        leaf = Node()
        leaf.answer = labels[0]
        return leaf
    if data.shape[1] == 1:
        leaf = Node()
        leaf.answer = max(set(labels), key=list(labels).count)
        return leaf
    gains = [gain_ratio(data, i) for i in range(data.shape[1] - 1)]
    split = np.argmax(gains)
    root = Node(metadata[split])
    new_metadata = np.delete(metadata, split)
    values, tables = subtables(data, split)
    for value in values:
        child = create_tree(tables[value], new_metadata)
        root.children[value] = child
    return root

def print_tree(node, level=0):
    indent = "  " * level
    if node.answer is not None:
        print(f"{indent}→ {node.answer}")
        return
    print(f"{indent}[{node.attribute}]")
    for value, child in node.children.items():
        print(f"{indent}  ({value})")
        print_tree(child, level + 2)

if __name__ == "__main__":
    metadata, data = read_data("data.csv")
    tree = create_tree(data, metadata)
    print_tree(tree)

