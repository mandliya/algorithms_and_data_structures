import copy
from prettytable import PrettyTable

inputMatrix = [[1, 2, 3], [4, 6, 0], [7, 5, 8]]
outputMatrix = [[1, 2, 3], [4, 5, 6], [7, 8, 0]]


class Astar:

	def __init__(self):                                 # Object containing matrix, flag(loc of swap), and elements
		self.grid = []                                  # of the exp f = g + h initialized to zero
		self.flag = ""
		self.gCost = 0
		self.hCost = 0
		self.fCost = 0


def generateNeighbours(inMatrix):                       # Generating neighbours
	slot = ()                                           # 1. Finding the void place of the current matrix
	neighbours = []                                     # 2. Checking and swapping values to generate neighbours
	for i in range(0, len(inMatrix.grid)):
		for j in range(0, len(inMatrix.grid)):
			if inMatrix.grid[i][j] == 0:
				slot = (i, j)
				break

	x, y = slot

	if inMatrix.flag == "":
		if x + 1 <= len(inMatrix.grid) - 1:
			tobj = Astar()
			tobj.grid = copy.deepcopy(inMatrix.grid)
			tobj.grid[x][y], tobj.grid[x + 1][y] = tobj.grid[x + 1][y], tobj.grid[x][y]
			tobj.flag = "up"
			tobj.gCost = inMatrix.gCost + 1
			tobj.hCost = findHeuristicValue(tobj.grid)
			tobj.fCost = tobj.gCost + tobj.hCost
			neighbours.append(tobj)

		if x - 1 >= 0:
			tobj = Astar()
			tobj.grid = copy.deepcopy(inMatrix.grid)
			tobj.grid[x][y], tobj.grid[x - 1][y] = tobj.grid[x - 1][y], tobj.grid[x][y]
			tobj.flag = "down"
			tobj.gCost = inMatrix.gCost + 1
			tobj.hCost = findHeuristicValue(tobj.grid)
			tobj.fCost = tobj.gCost + tobj.hCost
			neighbours.append(tobj)

		if y - 1 >= 0:
			tobj = Astar()
			tobj.grid = copy.deepcopy(inMatrix.grid)
			tobj.grid[x][y], tobj.grid[x][y - 1] = tobj.grid[x][y - 1], tobj.grid[x][y]
			tobj.flag = "left"
			tobj.gCost = inMatrix.gCost + 1
			tobj.hCost = findHeuristicValue(tobj.grid)
			tobj.fCost = tobj.gCost + tobj.hCost
			neighbours.append(tobj)

		if y + 1 <= len(inMatrix.grid) - 1:
			tobj = Astar()
			tobj.grid = copy.deepcopy(inMatrix.grid)
			tobj.grid[x][y], tobj.grid[x][y + 1] = tobj.grid[x][y + 1], tobj.grid[x][y]
			tobj.flag = "right"
			tobj.gCost = inMatrix.gCost + 1
			tobj.hCost = findHeuristicValue(tobj.grid)
			tobj.fCost = tobj.gCost + tobj.hCost
			neighbours.append(tobj)

	if inMatrix.flag == "up":
		if x + 1 <= len(inMatrix.grid) - 1:
			tobj = Astar()
			tobj.grid = copy.deepcopy(inMatrix.grid)
			tobj.grid[x][y], tobj.grid[x + 1][y] = tobj.grid[x + 1][y], tobj.grid[x][y]
			tobj.flag = "up"
			tobj.gCost = inMatrix.gCost + 1
			tobj.hCost = findHeuristicValue(tobj.grid)
			tobj.fCost = tobj.gCost + tobj.hCost
			neighbours.append(tobj)

		if y - 1 >= 0:
			tobj = Astar()
			tobj.grid = copy.deepcopy(inMatrix.grid)
			tobj.grid[x][y], tobj.grid[x][y - 1] = tobj.grid[x][y - 1], tobj.grid[x][y]
			tobj.flag = "left"
			tobj.gCost = inMatrix.gCost + 1
			tobj.hCost = findHeuristicValue(tobj.grid)
			tobj.fCost = tobj.gCost + tobj.hCost
			neighbours.append(tobj)

		if y + 1 <= len(inMatrix.grid) - 1:
			tobj = Astar()
			tobj.grid = copy.deepcopy(inMatrix.grid)
			tobj.grid[x][y], tobj.grid[x][y + 1] = tobj.grid[x][y + 1], tobj.grid[x][y]
			tobj.flag = "right"
			tobj.gCost = inMatrix.gCost + 1
			tobj.hCost = findHeuristicValue(tobj.grid)
			tobj.fCost = tobj.gCost + tobj.hCost
			neighbours.append(tobj)

	if inMatrix.flag == "down":
		if x - 1 >= 0:
			tobj = Astar()
			tobj.grid = copy.deepcopy(inMatrix.grid)
			tobj.grid[x][y], tobj.grid[x - 1][y] = tobj.grid[x - 1][y], tobj.grid[x][y]
			tobj.flag = "down"
			tobj.gCost = inMatrix.gCost + 1
			tobj.hCost = findHeuristicValue(tobj.grid)
			tobj.fCost = tobj.gCost + tobj.hCost
			neighbours.append(tobj)

		if y - 1 >= 0:
			tobj = Astar()
			tobj.grid = copy.deepcopy(inMatrix.grid)
			tobj.grid[x][y], tobj.grid[x][y - 1] = tobj.grid[x][y - 1], tobj.grid[x][y]
			tobj.flag = "left"
			tobj.gCost = inMatrix.gCost + 1
			tobj.hCost = findHeuristicValue(tobj.grid)
			tobj.fCost = tobj.gCost + tobj.hCost
			neighbours.append(tobj)

		if y + 1 <= len(inMatrix.grid) - 1:
			tobj = Astar()
			tobj.grid = copy.deepcopy(inMatrix.grid)
			tobj.grid[x][y], tobj.grid[x][y + 1] = tobj.grid[x][y + 1], tobj.grid[x][y]
			tobj.flag = "right"
			tobj.gCost = inMatrix.gCost + 1
			tobj.hCost = findHeuristicValue(tobj.grid)
			tobj.fCost = tobj.gCost + tobj.hCost
			neighbours.append(tobj)

	if inMatrix.flag == "left":
		if x + 1 <= len(inMatrix.grid) - 1:
			tobj = Astar()
			tobj.grid = copy.deepcopy(inMatrix.grid)
			tobj.grid[x][y], tobj.grid[x + 1][y] = tobj.grid[x + 1][y], tobj.grid[x][y]
			tobj.flag = "up"
			tobj.gCost = inMatrix.gCost + 1
			tobj.hCost = findHeuristicValue(tobj.grid)
			tobj.fCost = tobj.gCost + tobj.hCost
			neighbours.append(tobj)

		if x - 1 >= 0:
			tobj = Astar()
			tobj.grid = copy.deepcopy(inMatrix.grid)
			tobj.grid[x][y], tobj.grid[x - 1][y] = tobj.grid[x - 1][y], tobj.grid[x][y]
			tobj.flag = "down"
			tobj.gCost = inMatrix.gCost + 1
			tobj.hCost = findHeuristicValue(tobj.grid)
			tobj.fCost = tobj.gCost + tobj.hCost
			neighbours.append(tobj)

		if y - 1 >= 0:
			tobj = Astar()
			tobj.grid = copy.deepcopy(inMatrix.grid)
			tobj.grid[x][y], tobj.grid[x][y - 1] = tobj.grid[x][y - 1], tobj.grid[x][y]
			tobj.flag = "left"
			tobj.gCost = inMatrix.gCost + 1
			tobj.hCost = findHeuristicValue(tobj.grid)
			tobj.fCost = tobj.gCost + tobj.hCost
			neighbours.append(tobj)

	if inMatrix.flag == "right":
		if x + 1 <= len(inMatrix.grid) - 1:
			tobj = Astar()
			tobj.grid = copy.deepcopy(inMatrix.grid)
			tobj.grid[x][y], tobj.grid[x + 1][y] = tobj.grid[x + 1][y], tobj.grid[x][y]
			tobj.flag = "up"
			tobj.gCost = inMatrix.gCost + 1
			tobj.hCost = findHeuristicValue(tobj.grid)
			tobj.fCost = tobj.gCost + tobj.hCost
			neighbours.append(tobj)

		if x - 1 >= 0:
			tobj = Astar()
			tobj.grid = copy.deepcopy(inMatrix.grid)
			tobj.grid[x][y], tobj.grid[x - 1][y] = tobj.grid[x - 1][y], tobj.grid[x][y]
			tobj.flag = "down"
			tobj.gCost = inMatrix.gCost + 1
			tobj.hCost = findHeuristicValue(tobj.grid)
			tobj.fCost = tobj.gCost + tobj.hCost
			neighbours.append(tobj)

		if y + 1 <= len(inMatrix.grid) - 1:
			tobj = Astar()
			tobj.grid = copy.deepcopy(inMatrix.grid)
			tobj.grid[x][y], tobj.grid[x][y + 1] = tobj.grid[x][y + 1], tobj.grid[x][y]
			tobj.flag = "right"
			tobj.gCost = inMatrix.gCost + 1
			tobj.hCost = findHeuristicValue(tobj.grid)
			tobj.fCost = tobj.gCost + tobj.hCost
			neighbours.append(tobj)

	return neighbours


def findHeuristicValue(inMatrix):           # Comparing position of values of current matrix to the ones of desired matrix
	h = 0
	for i in range(0, len(inMatrix)):
		for j in range(0, len(inMatrix)):
			if inMatrix[i][j] != outputMatrix[i][j]:
				h += 1
	return h


def findBestMatrix(openList):               # Select best matrix from open list and return it
	bestmatrix = Astar()
	mincost = float("inf")
	for matrix in openList:
		if matrix.fCost <= mincost:
			mincost = matrix.fCost
			bestmatrix = matrix
	return bestmatrix


def printMatrix(matrix):                    # Formatting matrices
	p = PrettyTable()
	for row in matrix:
		p.add_row(row)
	return p.get_string(header=False, border=False)


def pathFinder():
	openList = []
	closedList = []
	current = Astar()
	current.grid = inputMatrix
	openList.append(current)
	steps = 0

	print("Input Matrix -->")           # Printing Input Matrix
	print(printMatrix(current.grid))
	print("Output Matrix -->")          # Printing Output Matrix
	print(printMatrix(outputMatrix))
	print()
	print()

	while True:
		current = findBestMatrix(openList)
		openList.remove(current)
		closedList.append(current)

		print("Step {0}:".format(str(steps)))  # Printing steps
		print(printMatrix(current.grid))       # Printing matrices
		print()

		if findHeuristicValue(current.grid) == 0:
			exit(0)

		neighbourList = generateNeighbours(current)     # Generating neighbours from the selected matrix
		for neighbour in neighbourList:
			if neighbour not in openList:
				openList.append(neighbour)              # Appending neighbours in the open list
		steps += 1                                      # Incrementing steps


pathFinder()
