# Problem Revision Sheet

## [CSES - Apartments](https://cses.fi/problemset/task/1084/)

### **Problem Summary:**
- **Two Lists:** You have two lists of numbers (list **a** with **n** items and list **b** with **m** items).
- **Matching Items:** You need to match items from the first list with items from the second list.
- **Valid Match:** A match is valid if the absolute difference between the two numbers is at most **k**.
  - (For example, if the number is **x**, then a valid match from the other list must be in the range **[x - k, x + k]**.)
- **One-Time Use:** Each item can only be matched once.

### **Key Approach:**
1. **Sort Both Lists:** Sorting the lists orders the numbers, making the matching process systematic.
2. **Two-Pointers Method:** Use two pointers to traverse the sorted lists efficiently.
3. **Why It Works:** Sorting allows the two-pointers method to greedily and optimally find the closest available matches without unnecessary comparisons.

### **Example Input & Output:**

### **Input Format:**
1. The first line contains three integers **n**, **m**, and **k**:
   - **n**: Number of elements in the first list.
   - **m**: Number of elements in the second list.
   - **k**: Maximum allowed difference for a valid match.
2. The second line contains **n** integers representing the first list.
3. The third line contains **m** integers representing the second list.

#### **Input:**
```
3 5 1
60 45 80
30 60 75 90 150
```
#### **Output:**
```
2
```

---

## [CSES - Ferris Wheel](https://cses.fi/problemset/task/1090/)

### **Problem Summary:**
- **Given:** `n` people with weights and a gondola that can carry at most `x` weight.
- **Goal:** Find the **minimum number of gondolas** needed.
- **Constraint:** Each gondola can carry **at most 2 people**.

### **Key Approach:**
1. **Sort the List** (Ascending Order) – This allows efficient pairing.
2. **Two-Pointer Technique:**
   - Start with the **lightest (`i = 0`) and heaviest (`j = n-1`)** person.
   - If `p[i] + p[j] <= x`, pair them and move both pointers (`i++`, `j--`).
   - Otherwise, send `p[j]` alone (`j--`).
   - Repeat until all are assigned.
3. **Why It Works?** Greedily eliminating the heaviest first ensures minimal gondolas.

### **Example Input & Output:**

#### **Input Format:**
1. First line: `n x` (number of people, weight limit per gondola).
2. Second line: `n` space-separated integers (weights of people).

#### **Input:**
```
4 10
7 2 3 9
```

#### **Output:**
```
3
```

### **New Variants & Extensions:**
1. **Allowing More Than 2 People per Gondola:**
   - Use a **greedy packing strategy**: Always try to fill the gondola as much as possible before sending it.
   - Process from **heaviest to lightest**, fitting as many as possible until the sum exceeds `x`.

2. **Only Weight Constraint (No Limit on Number of People):**
   - Start from the **heaviest person** and keep adding people until the gondola reaches the weight limit.
   - When exceeded, start a new gondola.

### **Core Concept & Idea:**
- **Sorting & Greedy Approach** ensures we minimize wasted space.
- **Two-Pointer Strategy** efficiently pairs people to minimize the number of gondolas.
- **If more than 2 people were allowed,** a **greedy bin-packing approach** works best.

---

This format is structured for quick revision. More problems can be added below in the same format!

---

# Notes
- #### **Making All Values Equal to `x` with Zero Sum Change** 

### **Steps:**:
1. Ensure at least one value is already `x` (or modify one to be `x` if needed).
2. Adjust the sum by setting the value which was changed to x or was already x to `x - (sum of others)`.
3. Modify all remaining values to reach `x` by adding the required differences.
