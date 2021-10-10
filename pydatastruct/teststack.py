# test stack.py

from stack import Stack

# constants used by handle_cmd
CMD_NUM  = 0
CMD_QUIT = 1
CMD_FAIL = 2
CMD_POP  = 3
CMD_HELP = 4
CMD_PEEK = 5

def handle_cmd(cmd: str):
    if cmd.isdecimal():
        return(CMD_NUM)
    if cmd == 'q':
        return(CMD_QUIT)
    if cmd == 'p':
        return(CMD_POP)
    if cmd == 'P':
        return(CMD_PEEK)
    if cmd == '?':
        return(CMD_HELP)
    return(CMD_FAIL)

st = Stack()  # create empty stack

print("(Type ? for help)")
while 1:
    cmdresult = handle_cmd(command := input("command: "))
    
    if (cmdresult == CMD_QUIT):
        print("Quitting...")
        break
    if (cmdresult == CMD_FAIL):
        print("Unknown command %s" % command)
    if (cmdresult == CMD_HELP):
        print("Valid commands: \n"
              "\tq - Quit\n"
              "\tp - Pop last item off stack\n"
              "\tP - Peek at last item")
    if (cmdresult == CMD_NUM):
        print("pushing %s" % command)
        st.push(command)
    if (cmdresult == CMD_POP):
        print("popped %s" % st.pop())
    if (cmdresult == CMD_PEEK):
        print("peeking %s" % st.peek())

del st
