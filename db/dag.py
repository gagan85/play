from itertools import chain

class Node:
    def __init__(self, node_id, children=[], thing=None):
        self.node_id = node_id
        self.children = children
        self.thing = thing

    def __eq__(self, other):
        return self.node_id == other.node_id

    def __hash__(self):
        return hash(node_id)

    def __str__(self):
        return "Node[{node_id}]".format(node_id=self.node_id)


def topologicalOrder(nodes):
    order = []
    for n in nodes:
        if n not in order:
            order += _topoOrderOnTree(n)
    return order


def _topoOrderOnTree(root):
    if root.children == []:
        return [root]
    else:
        os = [_topoOrderOnTree(c) for c in root.children]
        return [root] + list(chain.from_iterable(os))


def buildDag(nodes):
    return Dag(topologicalOrder(nodes))


class Dag:
    def __init__(self, nodes):
        self.nodes = nodes


#
# Test
#

def testNodes():
    ns = [Node(i) for i in range(0,6)]
    ns[0].children = []
    ns[1].children = []
    ns[2].children = [ns[0]]
    ns[3].children = [ns[2]]
    ns[4].children = [ns[2]]
    ns[5].children = [ns[1],ns[4]]
    return ns
