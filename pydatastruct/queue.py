# Implementation of a queue in Python

from linkedlist import ListNode

class Queue:
    def __init__(self):  # create an empty queue
        self.__data = None

    def enq(self, data):
        if self.__data is None:  # first time
            self.__data = ListNode(data)
        else:  # stuff at end of linked list
            tmpptr = self.__data
            while tmpptr.next is not None:
                tmpptr = tmpptr.next
            tmpptr.next = ListNode(data)

    def deq(self):  # remove and return value from first
        if self.__data is not None:
            ret = self.__data.data
            self.__data = self.__data.next
            return(ret)
        else:
            return(None)

