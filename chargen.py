#!usr/bin/env python2

import cPickle
import char
import die
import makechar
import os
import re


def _cat(name):
    """Displays the full stats of the given character.  The user can either input
    the character's name, or an integer index."""
    if name.isdigit(): # if 'name is in fact an integer index
        count = int(name)
        for filename in os.listdir('./.characters'):
            if filename.endswith('.chr'): # if this is a character file
                if count <= 0:
                    savefile = open('./.characters/' + filename, 'r')
                    character = cPickle.load(savefile)
                    character.display()
                    break
                count -= 1
        else:
            print "Integer reference out of bounds."
    else:
        name = name.replace(' ', '_')
        savefile = open('./.characters/' + name + '.chr', 'r')
        character = cPickle.load(savefile)
        character.display()


def _help(command=""):
    """Displays the help screen for the program."""
    print "Command List (Enter 'help [command name]' to learn more about a specific command)"
    print ""
    print "\tcat        : display a character"
    print "\tchar       : create a character"
    print "\texit       : quit program"
    print "\tls         : list all characters"
    print "\trm         : delete a character"
    print "\trollScores : roll a set of ability scores"
    print "\tquit       : quit program"
    print "\ttreasure   : start treasure generator"
    print "\tEnter a die expression to evaluate it (e.g. 5d6+2)"


def _ls():
    """Similar to the Unix command, this function lists all the characters that exist
    in the characters folder."""
    count = 0
    for name in os.listdir('./.characters'):
        if name.endswith('.chr'): # if this is a character file
            savefile = open('./.characters/' + name, 'r')
            character = cPickle.load(savefile)
            print '[%d]' % (count),
            character.summarize()
            count += 1


def _rm(name):
    """Similar to the Unix command, this function removes the character specified.  If
    the specified name is 'all', it will remove every character.  If given an integer,
    it will delete the character of that index."""
    if name.isdigit(): # if 'name' is in fact an integer index
        count = int(name)
        for filename in os.listdir('./.characters'):
            if filename.endswith('.chr'):
                if count <= 0:
                    os.system('rm ./.characters/' + filename)
                    break
                count -= 1
        else:
            print "Integer reference out of bounds."
    else: # if 'name' is a string
        name = name.replace(' ', '_')
        if(name == 'all'):
            for name in os.listdir('./.characters'):
                if name.find('.chr') != -1: # if this is a character file
                    os.system('rm ./.characters/' + name)
        else:
            os.system('rm ./.characters/' + name)



class CharGen(object):
    lastcmd = None


    def getCommand(this):
        return raw_input("> ")


    def execute(this, cmd):
        # if the user pressed enter, execute the last command
        if(cmd == ""):
            cmd = this.lastcmd
        else: # otherwise, store this command as the last command
            this.lastcmd = cmd

        # Process other commands
        if(not cmd):
            print "No previous command to copy."

        elif(cmd == "quit" or cmd == "exit"):
            quit()

        elif(re.match('cat', cmd)):
            name = cmd.replace('cat ', '', 1)
            _cat(name)

        elif(re.match('char', cmd)):
            cmd = cmd.replace('char', '', 1)
            os.system('python makechar.py ' + cmd)

        elif(re.match(die.die_re, cmd)):
            os.system('python die.py ' + cmd)

        elif(re.match('help', cmd)):
            _help()

        elif(cmd == 'ls'):
            _ls()

        elif(re.match('rm', cmd)):
            name = cmd.replace('rm ', '', 1)
            _rm(name)

        elif(cmd == "rollscores"):
            print char.rollAbilityScores(4)

        elif(re.match('treasure', cmd)):
            cmd = cmd.replace('treasure', '', 1)
            os.system('./treasure ' + cmd)

        else:
            print "Unrecognized command '%s'." % (cmd)


    def start(this):
        print " D&D 3.5 Character Generator"
        print " version 0.0.1 Aug 9, 2010"
        print " written by Max Carvajal"
        print ""
        while(True):
            this.execute(this.getCommand())



if __name__ == '__main__':
    cg = CharGen()
    cg.start()
