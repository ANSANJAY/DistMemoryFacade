# DistMemoryFacade
Distributed system offering unified memory access across multiple nodes, providing an illusion of a single, large memory chunk. Inspired by models like Hadoop's DFS. Built primarily in C with socket programming.

# Distributed Transparent Memory 🌐💽

## Description 📝

Distributed system offering unified memory access across multiple nodes. Users experience the illusion of accessing a large contiguous memory space, even though it's distributed across several machines.
# Problem Statement: Distributed Transparent Memory

**Objective:**  
To develop a distributed system that offers a unified memory access experience across multiple nodes. Despite the memory being scattered across different physical machines, the end user should perceive it as a single, contiguous chunk of memory.

**Background:**  
In today's data-driven world, there's an increasing need to store and manage vast amounts of data. Traditional single-machine memory models often don't suffice for the voluminous data storage needs. Distributed memory models, such as the one used by the Hadoop Distributed File System (HDFS), allow data to be stored across several machines, taking advantage of combined storage capacities.

**Challenges:**  
1. **Distributed Architecture**: Memory is fragmented across different physical machines, and accessing it in a unified manner is a challenge.
  
2. **Transparency**: The end user should remain unaware of the underlying distribution of data. They should not need to track where particular chunks of their data reside.

3. **Network Overhead**: Since the memory access occurs over a network, there can be latency and other network-related challenges to address.

4. **Consistency**: Ensuring data consistency in such distributed environments, especially with concurrent access, can be challenging.

**Specifications:**  
1. **Language**: The primary language of choice is C due to its efficiency in memory management and low-level operations. However, other languages with socket programming knowledge, such as C++, Python, and Java, are also permissible.

2. **Nodes**: Consider a scenario with four physical machines, each having a hard drive of 2 GB. The user should perceive this as a single 8 GB memory chunk, even though it's distributed.

3. **User Interaction**: There will be a network layer between the user and the memory storage. The user interacts with this network layer, which in turn communicates with the distributed nodes.

4. **Data Retrieval**: The system should ensure swift data retrieval without the user needing to know from which physical machine the data is fetched.

**End Goal:**  
To present the end user with the illusion that they're accessing a large, unified memory chunk, even though the memory is distributed across multiple physical nodes.



## Features 🌟

- **Unified Memory Access** 🚀: Seamless experience for users accessing distributed memory.
  
- **Socket Programming** 🛠️: Built primarily in C, leveraging socket programming for communication.

- **Scalability** ⬆️: Easily add more nodes to increase memory capacity.

- **Fault Tolerance** 🔄: Gracefully handle node failures with minimal disruption.

## Installation & Setup 📦

1. Clone the repository:
   \```
   git clone [[repository-url]](https://github.com/ANSANJAY/DistMemoryFacade/)
   \```
2. Navigate to the project directory:
   \```
   cd DistributedTransMemory
   \```
3. Compile and run the source code.

## Contribution Guidelines 🤝

Interested in contributing? We welcome pull requests, bug fixes, and issue reports. Before proposing a change, discuss it via issues.

## License 📄

This project is licensed under the MIT License. See `LICENSE` for more information.

## Acknowledgments 👏

Inspired by data distribution models like Hadoop's DFS.

---

Made with ❤️ by Anamika
