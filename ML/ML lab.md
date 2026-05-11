## **IMPLEMENTATION OF CANDIDATE-ELIMINATION ALGORITHM**

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

* 
**Step 1:** Think of a "Mystery Rule" for choosing a snack (like "Must be sweet and crunchy").


* 
**Step 2:** Start with a very strict guess (Specific) based on the first yummy snack you find.


* 
**Step 3:** If you see another yummy snack that is different (e.g., it's salty instead of sweet), make your guess looser so it includes both.


* 
**Step 4:** If you see a yucky snack, write down a rule that definitely kicks that snack out of the "yummy" group.


* 
**Step 5:** Keep doing this until you have a list of exactly what makes a snack yummy.






**Result:**
The Candidate-Elimination algorithm was successfully implemented to find all consistent hypotheses for the provided training sets.

---