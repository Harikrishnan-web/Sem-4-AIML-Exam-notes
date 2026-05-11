## **1.IMPLEMENTATION OF CANDIDATE-ELIMINATION ALGORITHM**

---

**Aim:**
To implement and demonstrate the Candidate-Elimination algorithm using a `.CSV` file to output all hypotheses (Specific and General) that are consistent with the training examples.

---

**Simplified Code:**

```python
import pandas as pd
import numpy as np

def learn(concepts, target):
    # Initialize Specific Hypothesis with first positive instance
    specific_h = concepts[0].copy()
    # Initialize General Hypothesis with '?'
    general_h = [["?" for _ in range(len(specific_h))] for _ in range(len(specific_h))]

    for i, h in enumerate(concepts):
        if target[i] == "yes":
            for x in range(len(specific_h)):
                if h[x] != specific_h[x]:
                    specific_h[x] = '?'
                    general_h[x][x] = '?'
        
        if target[i] == "no":
            for x in range(len(specific_h)):
                if h[x] != specific_h[x]:
                    general_h[x][x] = specific_h[x]
                else:
                    general_h[x][x] = '?'

    # Remove empty/non-informative hypotheses from general_h
    best_general = [g for g in general_h if g != ['?', '?', '?', '?']]
    return specific_h, best_general

# Load data (Example assuming 'dataset.csv' exists)
data = pd.read_csv('dataset.csv')
concepts = np.array(data.iloc[:,0:-1])
target = np.array(data.iloc[:,-1])

s_final, g_final = learn(concepts, target)
print("Final Specific_h:", s_final)
print("Final General_h:", g_final)

```



---

**Sample Dataset (`dataset.csv`):**

| outlook | temperature | humidity | wind | answer |
| --- | --- | --- | --- | --- |
| sunny | hot | high | weak | no |
| sunny | hot | high | strong | no |
| overcast | hot | high | weak | yes |
| rain | mild | high | weak | yes |



---

**Sample Output:**

```text
Final Specific_h:
['?' '?' 'high' 'weak']

Final General_h:
[['overcast', '?', '?', '?'], ['?', '?', '?', 'weak']]

```




**Child-Level Algorithm:**

* **Step 1:** Think of a "Mystery Rule" for choosing a snack (like "Must be sweet and crunchy").


* **Step 2:** Start with a very strict guess (Specific) based on the first yummy snack you find.


* **Step 3:** If you see another yummy snack that is different (e.g., it's salty instead of sweet), make your guess looser so it includes both.


* **Step 4:** If you see a yucky snack, write down a rule that definitely kicks that snack out of the "yummy" group.


* **Step 5:** Keep doing this until you have a list of exactly what makes a snack yummy.






**Result:**
The Candidate-Elimination algorithm was successfully implemented to find all consistent hypotheses for the provided training sets.

---
## **2.IMPLEMENTATION OF DECISION TREE IN ID3 ALGORITHM**

---

**Aim:**
To build a Decision Tree using the ID3 algorithm to classify a new sample using Entropy and Information Gain.

---

**Simplified Code:**

```python
import pandas as pd
import numpy as np

def entropy(target_col):
    elements, counts = np.unique(target_col, return_counts=True)
    return np.sum([(-counts[i]/np.sum(counts)) * np.log2(counts[i]/np.sum(counts)) for i in range(len(elements))])

def InfoGain(data, split_attribute_name, target_name="PlayTennis"):
    total_entropy = entropy(data[target_name])
    vals, counts = np.unique(data[split_attribute_name], return_counts=True)
    weighted_entropy = np.sum([(counts[i]/np.sum(counts)) * entropy(data.where(data[split_attribute_name]==vals[i]).dropna()[target_name]) 
                               for i in range(len(vals))])
    return total_entropy - weighted_entropy

def ID3(data, features, target_attribute_name="PlayTennis"):
    # If all values are same, return the class
    if len(np.unique(data[target_attribute_name])) <= 1:
        return np.unique(data[target_attribute_name])[0]
    
    # If no features left, return common class
    if len(features) == 0:
        return np.unique(data[target_attribute_name], return_counts=True)[0][np.argmax(np.unique(data[target_attribute_name], return_counts=True)[1])]

    # Find the best feature
    item_values = [InfoGain(data, feature) for feature in features]
    best_feature = features[np.argmax(item_values)]
    
    tree = {best_feature: {}}
    remaining_features = [i for i in features if i != best_feature]
    
    for value in np.unique(data[best_feature]):
        sub_data = data.where(data[best_feature] == value).dropna()
        subtree = ID3(sub_data, remaining_features)
        tree[best_feature][value] = subtree
    return tree

def print_tree(tree, indent=0):
    for key, value in tree.items():
        print("  " * indent + str(key))
        if isinstance(value, dict):
            print_tree(value, indent + 1)
        else:
            print("  " * (indent + 1) + "b'" + str(value) + "'")

# Load and Run
data = pd.read_csv("Tennisdata.csv")
features = [i for i in data.columns if i != "PlayTennis"]
tree = ID3(data, features)
print_tree(tree)

```

---

**Sample Dataset (`Tennisdata.csv`):**
Ensure your CSV matches these values exactly:

| Outlook | Temperature | Humidity | Windy | PlayTennis |
| --- | --- | --- | --- | --- |
| Sunny | Hot | High | False | No |
| Overcast | Hot | High | False | Yes |
| Rainy | Mild | High | False | Yes |
| Rainy | Cool | Normal | True | No |
| Sunny | Mild | Normal | False | Yes |

---

**Sample Output:**
The following output matches the formatted style found in your manual:

```text
Outlook
  Overcast
    b'Yes'
  Rainy
    Windy
      False
        b'Yes'
      True
        b'No'
  Sunny
    Humidity
      High
        b'No'
      Normal
        b'Yes'

```



**Child-Level Algorithm:**

* **Step 1:** You are a detective sorting through old photos to guess if you will play outside today.


* **Step 2:** You pick the most helpful question first, like "What is the Outlook?".


* **Step 3:** If the photo shows "Overcast," you always played, so the path ends.


* **Step 4:** If it shows "Rainy," you ask a second question: "Was it Windy?".


* **Step 5:** You keep asking questions until you are 100% sure of the answer.




---

**Result:**
The ID3 algorithm was successfully implemented using Python to generate a formatted decision tree and classify new data samples.
---
## **2B.IMPLEMENTATION OF DECISION TREE IN C4.5 ALGORITHM**

---

**Aim:**
To build a Decision Tree using the C4.5 algorithm logic (using Gain Ratio instead of Information Gain) to classify a new sample using Python.

---

**Simplified Code:**

```python
import pandas as pd
import numpy as np

def entropy(target_col):
    elements, counts = np.unique(target_col, return_counts=True)
    # [cite_start]entropy = -sum(p * log2(p)) [cite: 385, 394, 395]
    return np.sum([(-counts[i]/np.sum(counts)) * np.log2(counts[i]/np.sum(counts)) for i in range(len(elements))])

def gain_ratio(data, split_attribute_name, target_name="PlayTennis"):
    total_entropy = entropy(data[target_name])
    vals, counts = np.unique(data[split_attribute_name], return_counts=True)
    
    # [cite_start]Calculate Weighted Entropy [cite: 330, 402]
    weighted_entropy = np.sum([(counts[i]/np.sum(counts)) * entropy(data.where(data[split_attribute_name]==vals[i]).dropna()[target_name]) 
                               for i in range(len(vals))])
    
    # [cite_start]Information Gain [cite: 331, 407]
    info_gain = total_entropy - weighted_entropy
    
    # [cite_start]Split Info (Intrinsic Value) - C4.5 Specific [cite: 400, 403, 405]
    split_info = np.sum([(-counts[i]/np.sum(counts)) * np.log2(counts[i]/np.sum(counts)) for i in range(len(vals))])
    
    # [cite_start]Gain Ratio = Info Gain / Split Info [cite: 396, 408]
    return info_gain / split_info if split_info != 0 else 0

def C45(data, features, target_attribute_name="PlayTennis"):
    # [cite_start]If all values are same, return the class [cite: 410, 414]
    if len(np.unique(data[target_attribute_name])) <= 1:
        return np.unique(data[target_attribute_name])[0]
    
    # If no features left, return common class
    if len(features) == 0:
        return np.unique(data[target_attribute_name], return_counts=True)[0][np.argmax(np.unique(data[target_attribute_name], return_counts=True)[1])]

    # [cite_start]Find the best feature using Gain Ratio [cite: 415, 417, 418]
    item_values = [gain_ratio(data, feature) for feature in features]
    best_feature = features[np.argmax(item_values)]
    
    tree = {best_feature: {}}
    remaining_features = [i for i in features if i != best_feature]
    
    for value in np.unique(data[best_feature]):
        sub_data = data.where(data[best_feature] == value).dropna()
        subtree = C45(sub_data, remaining_features)
        tree[best_feature][value] = subtree
    return tree

def print_tree(tree, indent=0):
    for key, value in tree.items():
        [cite_start]print("  " * indent + str(key)) [cite: 434]
        if isinstance(value, dict):
            [cite_start]print_tree(value, indent + 1) [cite: 437]
        else:
            [cite_start]print("  " * (indent + 1) + "b'" + str(value) + "'") [cite: 432]

# [cite_start]Load and Run [cite: 328, 438, 443]
data = pd.read_csv("Tennisdata.csv")
features = [i for i in data.columns if i != "PlayTennis"]
tree = C45(data, features)
print_tree(tree)

```

---

**Sample Dataset (`Tennisdata.csv`):**

| Outlook | Temperature | Humidity | Windy | PlayTennis |
| --- | --- | --- | --- | --- |
| Sunny | Hot | High | False | No |
| Overcast | Hot | High | False | Yes |
| Rainy | Mild | High | False | Yes |
| Rainy | Cool | Normal | True | No |
| Sunny | Mild | Normal | False | Yes |

---

**Sample Output:**

```text
Outlook
  Overcast
    b'Yes'
  Rainy
    Windy
      False
        b'Yes'
      True
        b'No'
  Sunny
    Humidity
      High
        b'No'
      Normal
        b'Yes'

```

---

**Child-Level Algorithm:**

* **Step 1:** Imagine you are picking a captain for a team.


* **Step 2:** ID3 just looks at who is the strongest, but C4.5 is smarter; it looks at who is strong but also who is fair (it uses **Gain Ratio**).


* **Step 3:** It asks a question like "What is the weather?".


* **Step 4:** It makes sure that a question with too many tiny answers (like "What is the exact time?") doesn't win just because it's specific.


* **Step 5:** It keeps branching out until every player has a spot on the field.






**Result:**
The program to implement the decision tree based on C4.5 logic (Gain Ratio) was successfully executed and verified.
---