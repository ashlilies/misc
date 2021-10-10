# lifo stack using Python lists

class Stack:
    def __init__(self):  # creates an empty stack
        self.__data = []
        self.__listptr = 0  # next free space

    def push(self, data):
        self.__data.append(data)
        self.__listptr += 1

    def pop(self):
        if (self.__listptr-1 >= 0):
            temp = self.__data[self.__listptr-1]
            self.__listptr -= 1
            del self.__data[self.__listptr]
            return(temp)
        else:
            return(None)

    def peek(self):
        self.push(data := self.pop())
        return(data)

