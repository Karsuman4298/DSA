import heapq

def dijkstra(graph,start,end):
    queue = [(0,start,[start])]
    visited = set()


    while queue:
        cost,node,path= heapq.heappop(queue)


        if node== end:
            return cost,path


        if node in visited:
            continue

        visited.add(node)

        for neighbor, weight in graph.get(node,[]):
            if neighbor not in visited:
                heapq.heappush(queue,(cost + weight,neighbor,path+[neighbor]))


    return(float("inf"),[])




graph = {
    'A': [('B', 2), ('C', 4)],
    'B': [('D', 7), ('E', 3)],
    'C': [('F', 1)],
    'D': [],
    'E': [('F', 2)],
    'F': []
}

path= dijkstra(graph,'A','F')
print(path)
print("Total cost:",path[0])

