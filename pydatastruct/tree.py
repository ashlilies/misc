# Binary trees

class TreeNode:
    def __init__(self, data):
        self.data  = data
        self.left  = None
        self.right = None

    def attachl(self, left_child):  # attach a new left child
        self.left = left_child

    def attachr(self, right_child):
        self.right = right_child
