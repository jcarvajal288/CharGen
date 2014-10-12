#!usr/bin/env python

import char
import curses
import die
import os
import re

def main(screen):
    screen.clear()
    dieroller = DieRoller(screen)    
    dieroller.start()

    while True:
        cmd = getCommand(screen)
        print(cmd)

def getCommand(screen):
    cmd = ""
    while True:
        char = screen.getch() 
        if char is '\r' or char is '\n':
            return cmd
        else:
            cmd += char 


def _help(command=""):
    """Displays the help screen for the program."""
    print("Command List (Enter 'help [command name]' to learn more about a specific command)")
    print("")
    print("\trollscores : roll a set of ability scores")
    print("\tquit       : quit program")
    print("\texit       : quit program")
    print("\tEnter a die expression to evaluate it (e.g. 5d6+2)")


class DieRoller(object):
    def __init__(this, screen):
        this.screen = screen


#    def getCommand(this):
#        return input("> ")
#
#
#    def execute(this, cmd):
#        # if the user pressed enter, execute the last command
#        if(cmd == ""):
#            cmd = this.lastcmd
#        else: # otherwise, store this command as the last command
#            this.lastcmd = cmd
#
#        # Process other commands
#        if(not cmd):
#            print("No previous command to copy.")
#
#        elif(cmd == "quit" or cmd == "exit"):
#            quit()
#
#        elif(re.match(die.die_re, cmd)):
#            os.system('python die.py ' + cmd)
#
#        elif(re.match('help', cmd)):
#            _help()
#
#        elif(cmd == "rollscores"):
#            print(char.rollAbilityScores(4))
#
#        else:
#            print("Unrecognized command '%s'." % (cmd))
#
#
    def start(this):
        print("in start")
        this.screen.addstr(0, 0, " Die Roller")
        this.screen.addstr(1, 0, " ----------")
        this.screen.addstr(2, 0, " ")
        this.screen.refresh()
        #while(True):
        #    this.execute(this.getCommand())


if __name__ == '__main__':
    curses.wrapper(main)
