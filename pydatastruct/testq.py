# test stack.py

from queue import Queue

# constants used by handle_cmd
CMD_NUM  = 0
CMD_QUIT = 1
CMD_FAIL = 2
CMD_DEQ  = 3
CMD_HELP = 4

def handle_cmd(cmd: str):
    if cmd.isdecimal():
        return(CMD_NUM)
    if cmd == 'q':
        return(CMD_QUIT)
    if cmd == 'd':
        return(CMD_DEQ)
#    if cmd == 'P':
#        return(CMD_PEEK)
    if cmd == '?':
        return(CMD_HELP)
    return(CMD_FAIL)

q = Queue()  # create empty queue

print("(Type ? for help)")
while 1:
    cmdresult = handle_cmd(command := input("command: "))
    
    if (cmdresult == CMD_QUIT):
        print("Quitting...")
        break
    if (cmdresult == CMD_FAIL):
        print("Unknown command %s" % command)
    if (cmdresult == CMD_HELP):
        print("Enter a number to enqueue, or enter a command.")
        print("Valid commands: \n"
              "\tq - Quit\n"
              "\td - Dequeue")
    if (cmdresult == CMD_NUM):
        print("enqueueing %s" % command)
        q.enq(command)
    if (cmdresult == CMD_DEQ):
        print("dequeued %s" % q.deq())

del q
