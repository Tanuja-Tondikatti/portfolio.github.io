## The Microsoft Matrix

**Course Name:** Algorithmic Problem Solving  
**Course Code:** 24ECSE309  
**Name:** Tanuja Tondikatti  
**SRN:** 01FE22BCS182  
**Course Instructor:** Prakash Hegade  
**University:** KLE Technological University, Hubballi-31  
**Domain:** Microsoft



### Introduction
<img src="microsoft.jpg" alt="Microsoft logo" width="800" height="350"/>
**Microsoft** is the world's largest vendor of computer software and a leading provider of cloud computing services, video games, computer and gaming hardware, search and other online services. Through its comprehensive suite of services and products, Microsoft empowers businesses and individuals to achieve more, innovate, and enhance their digital experience. From A to Z, Microsoft delivers it all—cloud power with Azure, productivity through Microsoft 365, and smart tools like Copilot. Whether it's coding, collaboration, security, or gaming, Microsoft has a solution for every need, everywhere.




### Exploring the Range of Microsoft Services
- **Azure ☁️**: Cloud computing platform for hosting apps, data, and services.
- **Bing 🔍**: Search engine powered by AI for finding information online.
- **Cortana 🗣️**: Virtual assistant integrated with Microsoft products.
- **Dynamics 365 📈**: Enterprise resource planning (ERP) and customer relationship management (CRM) services.
- **Edge 🌐**: Web browser built for speed and security.
- **GitHub 🧑‍💻**: Platform for version control and collaboration on code.
- **HoloLens 🕶️**: Mixed reality headset for immersive experiences.
- **Intune 🔒**: Mobile device management and security platform.
- **LinkedIn 💼**: Professional networking and career development platform (owned by Microsoft).
- **Microsoft 365 🖥️**: Productivity suite with Word, Excel, PowerPoint, and more.
- **Microsoft Teams 💬**: Communication and collaboration platform for teams.
- **Microsoft Stream 📹**: Video sharing service for businesses and educational content.
- **OneDrive 💾**: Cloud storage for files and synchronization across devices.
- **Outlook 📧**: Email and calendar service for managing communication and schedules.
- **Power Apps 🛠️**: Low-code platform for app development.
- **Power Automate 🔄**: Service to automate workflows and tasks.
- **Power BI 📊**: Business analytics tool for data visualization and insights.
- **Skype 📞**: Video calling and messaging platform.
- **Visual Studio 💻**: Integrated development environment (IDE) for building applications across platforms.
- **Windows 🖥️**: Operating system for personal computers, laptops, and servers.
- **Xbox 🎮**: Gaming console and online gaming service.

## Business Cases
<img src="Statistics.jpeg" alt="Number of Users" width="600" height="300"/>

This Bar graph illustrates the current competitive landscape of desktop browsers. Despite being built on the same Chromium engine, Google Chrome vastly dominates, while Microsoft Edge, though second, captures only about 1/5 of Chrome's market. Despite being faster and more integrated with Windows 11, Edge is not widely adopted. This exposes both a challenge and a business opportunity for Microsoft. If Edge wins even 10% of Chrome’s share, it would gain ~6.5%, increasing its total to ~20%. This makes Edge a major challenger brand, opening monetization opportunities (e.g., Bing Ads, shopping tools).

To achieve this objective, it is essential to identify and resolve critical technical bottlenecks that hinder both user adoption and browser performance. By Leveraging advanced data structures and algorithms can enhance the browser’s speed, responsiveness, and resource management.

# 1. Autofill System 

### 🔍 Autocomplete with Trie
Uses a **prefix tree (Trie)** to quickly find form entries that match user input as they type.  
**Example:** Typing `tan` instantly suggests `tanuja@example.com`.

### 🔡 Typo Correction via BK-Tree
Implements a **BK-Tree (Burkhard-Keller Tree)** for fuzzy string matching using edit distance.  
**Example:** If a user types `emial`, it still suggests `email`.

### 📈 Suggestion Ranking with Min/Max Heaps
Uses **heaps** (priority queues) to prioritize autofill suggestions based on **recency** or **frequency** of use.  
**Example:** Emails or names used more often appear at the top of suggestions.

### 👤 Session-Based Isolation with Disjoint Set Union
Uses **Disjoint Set Union (DSU)** to isolate autofill data between normal and incognito sessions.  
**Example:** No suggestions from regular mode appear in private mode.

### 🧩 Flexible Form Mapping via Bipartite Graphs
Matches form input fields to their correct labels using **bipartite graph algorithms**.  
**Useful when:** Websites use non-standard form layouts or custom naming conventions.


| Feature               | Data Structure           | Purpose                                        |
|-----------------------|---------------------------|------------------------------------------------|
| Input Prediction      | Trie                      | Fast prefix matching                           |
| Typo Correction       | BK-Tree                   | Fuzzy search using edit distance               |
| Suggestion Ranking    | Heap / Priority Queue     | Recent/Frequent entry prioritization           |
| Session Isolation     | Disjoint Set Union (DSU)  | Prevent autofill leaks across private sessions |
| Form Field Matching   | Bipartite Graph           | Maps form fields to labels                     |


---
## Data Structure And Algorithm analysis
###  Trie
<img src="Images\Triedatastructure1.png" alt="Trie" width="500" height="400"/>

Tries enhance search functionality by providing predictive text suggestions as users type queries in Edge. Also known as submission throttling.  
Tree data structure, Prefix tree

- **Time Complexity**: O(L) for insertion, deletion, and lookup operations, where L is the length of the key (typically a word)  
- **Space Complexity**: O(ALPHABET_SIZE × L), where ALPHABET_SIZE is the number of possible characters and L is the length of the key

[View code here](codes\Trie.cpp)

###   BK-Tree
<img src="Images\BK.jpg" alt="BK" width="500" height="400"/>

BK-Trees support typo-resilient search by allowing approximate matches based on edit distances.  
Commonly used for spelling correction, fuzzy matching, and autofill systems (e.g., suggesting “email” when user types “emial”).  
Tree data structure built using metric spaces (like Levenshtein distance).

- **Time Complexity**: O(log N) for search in a balanced BK-Tree, where N is the number of words  
- **Space Complexity**: O(N × L), where N is the number of stored words and L is the average word length

[View code here](codes\BK.cpp)

###  Priority Queue

Used for ranking autofill suggestions by recency or frequency. Efficiently retrieve top suggestions (e.g., most frequently used form input).
- **Time Complexity:** O(log N) for insertion and deletion
- **Space Complexity:** O(N)

[View code here](codes\Heap.cpp)
### Disjoint Set Union (DSU)

Used to isolate sessions, such as incognito windows in browsers. Efficient group tracking and isolation, avoiding interference between user sessions.

- **Time Complexity:** O(α(N)) per operation (almost constant)
- **Space Complexity:** O(N)


### Bipartite Graph
<img src="Images\bi.png" alt="Bipartite" width="500" height="400"/>

Used to map dynamic form fields (e.g., autofill label ↔ field). Ensure that label-to-field mapping is valid, even in irregular HTML layouts.

- **Time Complexity:** O(V + E)
- **Space Complexity:** O(V)

  ---
# 2. Page Loading Optimization

Page loading is a critical factor in browser performance. Efficient use of data structures and algorithms improves rendering speed, responsiveness, and perceived performance. Improve the speed at which a webpage is parsed, resources are fetched, and content is rendered.



## 🔧 Data Structures & Algorithms

| Data Structure / Algorithm | Purpose |
|----------------------------|---------|
| **Event Queue / Min Heap** | Efficient scheduling of tasks like scripts, animations, and painting frames |
| **Dependency Graph**       | Manage resource loading order (e.g., CSS before JS execution) |
| **Trie / HashMap**         | Fast URL resolution, DNS prefetching, and cache lookup |
| **LRU Cache**              | Efficient memory management of recently used resources (images, scripts) |
| **Segment Trees**          | Manage layout recalculations or animations across DOM sections |

---

### 🧠 Concepts
- **Critical Path Rendering**: Prioritize essential resources (HTML, CSS) using Dependency Graphs.
- **Lazy Loading**: Delays loading non-visible content using LRU strategy.
- **Preloading / Prefetching**: Use Tries and HashMaps to resolve likely next resources.

---

### Event Queue / Min Heap
<img src="Images\Min-Heap.webp" alt="Trie" width="500" height="400"/>
Min Heaps are used for scheduling tasks in the correct order of execution based on priority. For example, scripts that must run before rendering, layout recalculations, or frame paint tasks can be prioritized and executed using a min-heap task scheduler.

- **Time Complexity**: O(log N) for insertion and deletion
- **Space Complexity**: O(N)
  
[View code here](codes\Segment.cpp)
### Dependency Graph
Dependency graphs represent the interdependencies among resources (scripts, stylesheets, etc.). This helps the browser determine the optimal load and execution order to minimize render-blocking and maximize performance.

- **Time Complexity**: O(V + E)
- **Space Complexity**: O(V + E)

[View code here](codes\Dependency.cpp)
### Trie 
Tries and HashMaps are used to accelerate search operations such as DNS lookups, cache resolution, and preloading suggestions. Tries support efficient prefix matching while HashMaps allow constant-time lookups.

- **Time Complexity (Trie)**: O(L)
- **Space Complexity**: O(ALPHABET_SIZE × L)
  
[View code here](codes\Trie.cpp)

### LRU Cache
<img src="Images\LRU.jpg" alt="Trie" width="500" height="400"/>

Least Recently Used (LRU) Cache is applied for caching assets like images, scripts, or pages. It keeps the most recently accessed content readily available while evicting older, less-used resources when memory is constrained.

- **Time Complexity**: O(1) for get/put using hashmap + doubly linked list
- **Space Complexity**: O(N)
[View code here](codes\LRU.cpp)
### Segment Tree
<img src="Images\segment.png" alt="Trie" width="500" height="400"/>

Segment Trees allow efficient range updates and queries. They are useful when dynamically updating or querying DOM regions, animations, or styles in real-time as the user interacts with the page.

- **Time Complexity**: O(log N) for update/query
- **Space Complexity**: O(N)

[View code here](codes\Segment.cpp)

---
# Optimizing Network Traffic in Microsoft Services
<img src="Images\Max.png" alt="BK" width="500" height="400"/>

Microsoft manages vast networks of servers and data centers to deliver its services. The Max Flow algorithms can be used to optimize network traffic flow, ensuring efficient data transmission and minimizing congestion. Max flow algorithms, such as Karger’s, Dinic’s, and Ford-Fulkerson, can assist in determining optimal routes and balancing the load across servers, improving system performance and reliability.

## Algorithms, Design Techniques, and Performance Analysis

### 1. Ford-Fulkerson Algorithm
- **Approach:** Uses augmenting path method with a greedy approach to iteratively find paths from source to sink that can carry more flow.
- **Design Techniques:** Residual graph, BFS for path search (Edmonds-Karp variant).
- **Time Complexity:** O(E * V²), where E = number of edges, V = number of vertices.
- **Space Complexity:** O(V²).

### 2. Dinic’s Algorithm
- **Approach:** Uses a layered network to find blocking flows, speeding up the max flow computation compared to Ford-Fulkerson.
- **Design Techniques:** Level graph construction via BFS, blocking flow calculation via DFS.
- **Performance:** More efficient in practice, especially for dense graphs.

### 3. Karger’s Algorithm
- **Approach:** A randomized contraction algorithm based on the min-cut max-flow theorem.
- **Design Techniques:** Randomly contracts edges while preserving minimum cuts.
- **Performance:** Probabilistic guarantees, useful for min-cut problems and network reliability analysis.
  
These algorithms provide foundational tools for optimizing network traffic, enabling large-scale infrastructures like Google’s data centers to operate efficiently under heavy loads.

[View code here](codes\Maxflow.cpp)

[About Me](About.md)






