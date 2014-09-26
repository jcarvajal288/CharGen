#!usr/bin/env python

import argparse
import char
import cPickle



def _parseArgs():
    """This function parses the command string, and makes a character based on those
    commands.  It then pickles the character and puts it in the 'character' folder."""
    parser = makeParser()
    newChar = char.Character(parser.parse_args())
    newChar.summarize()
    savename = './.characters/%s.chr' % (newChar.Name.replace(' ', '_'))
    savefile = open(savename, 'w')
    cPickle.dump(newChar, savefile, cPickle.HIGHEST_PROTOCOL)


def makeParser():
    parser = argparse.ArgumentParser(description='Character Generator')
    parser.add_argument('--abilities', 
                        dest='abilities', 
                        choices = ['stdarray', 'low', 'normal', 'high'],
                        action='store', 
                        default='normal',
                        help="""determines how highly powered the character's ability score
                        rolls will be. 'low' sets each die roll to 3d6, 'normal' to 4d6 and
                        drop the lowest die, and 'high' to 5d6 and drop the lowest two.
                        'stdarray' sets the ability array to the standard array for NPCs,
                        which is [15,14,13,12,10,8].""")
    parser.add_argument('-c', '--class',
                        dest='_class',
                        action='store',
                        default='random',
                        help="""determines the character's class.  Leave this option off to
                        randomly determine class.""")
    parser.add_argument('--male',
                        dest='gender',
                        default='random',
                        action='store_const',
                        const='male',
                        help="""include this flag to guarantee the character will be male.
                        If absent, a character has a 3:4 chance of being male.""")
    parser.add_argument('--female',
                        dest='gender',
                        action='store_const',
                        const='female',
                        help="""include this flag to guarantee the character will be female.
                        If absent, a character has a 1:4 chance of being female.""")
    parser.add_argument('-l', '--level',
                        type=int,
                        dest='level',
                        choices=range(1,21),
                        action='store',
                        default=1,
                        help="""specifies the character's level.  This must be an integer
                        between 1 and 20.""")
    parser.add_argument('-n', '--name',
                        dest='name',
                        action='store',
                        default=None,
                        help="""Set the character's name.  If absent, the character's name will
                        be randomly generated based on race and gender.""")
    parser.add_argument('-r','--race',
                        dest='race',
                        action='store',
                        default='random',
                        help="""determines the character's race.  Leave this option off to
                        randomly determine race.""")
    return parser



if __name__ == '__main__':
    _parseArgs()
