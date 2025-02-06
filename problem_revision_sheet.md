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

This format is structured for quick revision. More problems can be added below in the same format!
