#!usr/bin/env python2

import argparse
import random
import re

die_re = re.compile(r"[+|-]?\d*d?\d+")



def _parseArgs():
    parser = argparse.ArgumentParser(description='Dice roller')
    parser.add_argument('expression', 
                        help="a valid dice roll expression, such as 'd8', '2d4+7', etc.")
    parser.add_argument('-v', '--verbose', dest='verbose', action='store_true', default=False, 
                        help='prints the results of every roll in the expression')
    args = parser.parse_args()
    print(roll(args.expression, args.verbose))



def _die(input):
    """
    searches the input string for all matches for the die_re regular expression.
    It rolls each die expression, and returns the results as a list of integers
    """
    matches = re.findall(die_re, input)
    # evaluate each match
    for match in matches:
        nums = re.split('d', match)
        if(len(nums) == 2): # this is a die roll
            try: lhs = int(nums[0]) # if this throws, this is just a sign
            except ValueError: lhs = int(nums[0] + '1')
            for i in range(lhs):
                yield random.randint(1, int(nums[1]))
        else: # this is an addition
            yield int(nums[0])



def printRolls(results):
    """
    prints individual die rolls in the form
    <result> (+/-) result (+/-) result ... = <total>
    """
    print(results[0], end=" ")
    for result in results[1:]:
        if result > 0: print("+", end=" ")
        else: print("-", end=" ")
        print(result, end=" ")
    print("=", end=" ")



def roll(input, verbose=False):
    """
    evaluates the given die roll expression. Some valid die roll expressions are
    'd8', '2d4', 5d7+3d4-54', etc.

    if the 'verbose' tag is true, it will print out each die roll before the total.
    """
    results = []
    for result in _die(input): results.append(result)
    if(verbose):
        printRolls(results)
    return sum(results)



if __name__ == '__main__':
    _parseArgs()



