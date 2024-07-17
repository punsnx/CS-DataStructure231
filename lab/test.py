import random

# Set the range for x and y
min_val = -10**5
max_val = 10**5

# Generate 1000 sets of (x, y) coordinates
coordinates = [(random.randint(min_val, max_val), random.randint(min_val, max_val)) for _ in range(1000)]

# Print the first few sets to verify
for i in range(10):
    print(coordinates[i])

# Save the coordinates to a text file
with open('coordinates.txt', 'w') as file:
    for coord in coordinates:
        file.write(f"{coord[0]} {coord[1]}\n")