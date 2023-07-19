import matplotlib.pyplot as plt
import matplotlib.animation as animation
import numpy as np

def read_grid_from_file(filename):
    with open(filename, 'r') as file:
        grid = [line.strip().split() for line in file]
    return grid

def read_traversal_sequence_from_file(filename):
    with open(filename, 'r') as file:
        arr = [tuple(map(int, line.strip().split())) for line in file]
    return arr

def visualize_bfs(grid, start, traversal_sequence):
    fig, ax = plt.subplots()
    rows, cols = len(grid), len(grid[0])

    # Set up the grid plot
    ax.set_xticks(np.arange(-.5, cols, 1), minor=True)
    ax.set_yticks(np.arange(-.5, rows, 1), minor=True)
    ax.grid(which='minor', color='black', linestyle='-', linewidth=2)

    # Plot the grid with numbers
    for i in range(rows):
        for j in range(cols):
            ax.text(j, i, grid[i][j], ha='center', va='center', fontsize=12)

    def update(frame):
        row, col = traversal_sequence[frame]
        ax.add_patch(plt.Rectangle((col - 0.5, row - 0.5), 1, 1, color='red', alpha=0.5))

    ani = animation.FuncAnimation(fig, update, frames=len(traversal_sequence), blit=False, repeat=False)
    plt.show()


# Read grid from opt.txt
grid_filename = 'opt.txt'
grid = read_grid_from_file(grid_filename)

# Read traversal sequence (arr) from output.txt
arr_filename = 'output.txt'
arr = read_traversal_sequence_from_file(arr_filename)

# Starting point (source cell) for BFS
start_point = arr[0]  # The first coordinate in arr is the starting point

# Visualize BFS traversal on the grid
visualize_bfs(grid, start_point, arr)
