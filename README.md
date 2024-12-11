# Consistent Hashing Simulation

This repository demonstrates the concept of **consistent hashing**, a key technique used in distributed systems to efficiently manage and scale data across multiple storage nodes. Inspired by the insights of [Arpit Bhayani](https://arpitbhayani.me/), this project implements the fundamental ideas of consistent hashing, showcasing how it addresses challenges in dynamic environments like scale-ups and scale-downs.

## Key Features
- **Basic Hashing Mechanism**: Stores and retrieves data based on a hash function.
- **Consistent Hashing**: Associates keys with storage nodes using a modular hash space.
- **Dynamic Scaling**:
  - Scale up: Add more storage nodes and calculate the number of keys migrated.
  - Scale down: Remove storage nodes and calculate the number of keys migrated.
- **Collision Handling**: Handles key collisions and overwrites values where necessary.

## How It Works
1. **Hash Function**:
   The hash function computes a unique index for each key by summing the ASCII values of the characters and taking the modulus with the total number of nodes.
2. **Data Storage**:
   Keys are mapped to storage nodes based on the computed hash index.
3. **Scaling**:
   - When nodes are added or removed, keys are re-hashed to their new storage nodes. The system calculates and displays the amount of migrated data.
4. **Collision Handling**:
   If multiple keys hash to the same node, the value is overwritten.

## Simulation Steps
1. Define the initial number of storage nodes.
2. Insert key-value pairs to store data in nodes.
3. Fetch values using the key to demonstrate data retrieval.
4. Scale up or scale down nodes dynamically and observe the number of migrated keys.


## Acknowledgment
Concepts and inspiration from [Arpit Bhayani](https://arpitbhayani.me/).
