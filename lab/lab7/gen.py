import random

# Function to generate random edges for a graph with 1000 nodes
def generate_random_edges(num_nodes, num_edges):
    edges = set()  # Using set to avoid duplicate edges
    while len(edges) < num_edges:
        # Randomly select two nodes
        node1 = random.randint(0, num_nodes - 1)
        node2 = random.randint(0, num_nodes - 1)
        
        # Avoid self-loops and duplicate edges (regardless of direction)
        edge = (node1, node2)
        edges.add(edge)
    
    return list(edges)

# Generate random edges for a 1000-node graph with 2000 edges
num_nodes = 100
num_edges = 2000 
random_edges = generate_random_edges(num_nodes, num_edges)
print(num_nodes)
print(1)
for i in random_edges:
    print(str(i[0])+" "+str(i[1]))
print(-1)

