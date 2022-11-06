'''
                            Problem Definition
Given an integer n representing the number of courses and an array prerequisites
where prerequisities[i] = [a,b] means that you firt need to take the course b before taking the course a, determine
if it's possible to finish all the courses.
'''
def dfs_with_checking_cycles(graph,vertex,path,order,visited):
    path.append(vertex)
    for neighbor in graph[vertex]:
        if neighbor in path:
            return False
        if neighbor not in visited:
            visited.add(neighbor)
            if not dfs_with_checking_cycles(graph,neighbor,path,order,visited):
                return False
    order.append(path.pop())
    return True

graph = {
   "a" : ["b"],
   "b" : ["d"],
   "c" : ["a", "d"],
   "d" : ["e"],
   "e" : []
}
visited = set()
print(dfs_with_checking_cycles(graph,'a',[],[],visited))
