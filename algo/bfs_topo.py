

class Node:
    def __init__(self, label, children=[]):
        self.label = label
        self.children = children
        self.visited = False

    def __str__(self):
        return self.label


def top_bfs(start_node):
    queue = [start_node]
    stack = []
    while len(queue) > 0:
        node = queue[0]; queue = queue[1:]
        if not node.visited:
            node.visited = True
            stack += [node]
            [queue.append(c) for c in node.children]
    stack.reverse()
    return stack

leaves = [Node('a'), Node('b')]
inner0 = [Node('c', leaves), Node('d', [leaves[0]])]
inner1 = [Node('e', inner0)]

def test():
    xs = top_bfs(inner1[0])
    print [str(x) for x in xs]
