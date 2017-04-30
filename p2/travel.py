import csv

def solve(fname):
    '''
    fname - string - a path to a file containing a problem description
                     according to the spec

    returns - int - the most money that can be made, visiting each city once
    '''
    ####### loading in problem #######
    
    problem = [x for x in csv.reader(open(fname), delimiter=' ')]
    
    num_cities = int(problem[0][0])
    num_edges  = int(problem[1][0])
    city_names = problem[2]
    earnings   = [int(x) for x in problem[3]]
    
    edges = {}
    
    for x in problem[4:]:
        edges[(x[0], x[1])] = int(x[2])
    
    
    
    ####### setting up datastructures #######
    
    city_earnings = dict(zip(city_names, earnings))
    
    graph = {'S2': []}
    
    for e in edges.keys():
    
        if not graph.has_key(e[0]):
            graph[e[0]] = []
    
        graph[e[0]].append(e[1])
    
    ###### traversing tree #################
    
    def traverse(city, money, visited):
    
        if (city == 'S2'):
            return money
    
        if (visited.has_key(city)):
            return float('-inf')
    
        visited[city] = money
        l = [float('-inf')]
        for child in graph[city]:
    
            diff = edges[(city,child)] + city_earnings[child]
            l.append(traverse(child, money + diff, visited))
    
        visited.pop(city)
        return max(l)
    
    return traverse('S1', city_earnings['S1'], {})

res = solve('example2.txt')
