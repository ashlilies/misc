from linkedlist import ListNode

# set them up with data
n1 = ListNode("hi")
n2 = ListNode("how")
n3 = ListNode("are")
n4 = ListNode("you")

# chain them up
n1.next = n2
n2.next = n3
n3.next = n4

listhead = n1
while listhead is not None:
    print(listhead.data, end=' ')
    listhead = listhead.next

print('')  # newline
