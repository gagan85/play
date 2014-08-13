#
# Author: Sam Zhao <sam@cs.brown.edu>
#
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
        else:
            bubbledNode = stack.pop(stack.index(node))
            stack += [bubbledNode]
    stack.reverse()
    return stack

b0 = Node('b0')
c0 = Node('c0', [b0])
a0 = Node('a0', [b0, c0])

c1 = Node('c1')
b1 = Node('b1', [c1])
a1 = Node('a1', [b1, c1])

def test():
    for n in [a0, a1]:
        xs = top_bfs(n)
        print [str(x) for x in xs]
