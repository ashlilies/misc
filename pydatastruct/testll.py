from linkedlist import ListNode

# set them up with data
# n1 = ListNode("hi")
# n2 = ListNode("how")
# n3 = ListNode("are")
# n4 = ListNode("you")

# chain them up
# n1.next = n2
# n2.next = n3
# n3.next = n4
# n2.connect_aft(n1)
# n3.connect_aft(n2)
# n4.connect_aft(n3)

listhead = None

print("(Type quit to stop)")
while 1:
    tempdata = input("Enter some words: ")
    if tempdata.lower() == "quit":
        break
    node = ListNode(tempdata)
    if listhead is None:  # first round
        listhead = node
    else:
        tempptr = listhead
        while tempptr.next is not None:
            tempptr = tempptr.next
        tempptr.next = node

nodec = 0
while listhead is not None:
    print("[Node %d] %s" % (nodec := nodec+1, listhead.data))
    listhead = listhead.next

