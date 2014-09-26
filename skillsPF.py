"""
Skill specifications for Pathfinder
"""
import char

class Skill(object):
    """
    Skills are stored in the character object by using a dictionary, where the skill's
    name references a Skill object.
    """
    def __init__(self, keyAbility, armorCheck=False, synergies=[]):
        self.keyAbility = keyAbility # integer index to an ability list
        self.armorCheck = armorCheck
        self.miscBonus = 0
        self.ranks = 0


    def bonus(self, currentChar):
        """
        calculates a skill's total bonus for the given character.
        """
        bonus = 0
        # add ability modifier
        bonus += char.Character.mod(currentChar.AbilityScores[self.keyAbility])
        # subtract armor check if applicable
        if(self.armorCheck):
            # TODO: put Armor and Shield armor check code here
            pass
        # add ranks
        bonus += self.ranks
        # add any miscellaneous bonuses
        bonus += self.miscBonus
        return bonus


# construct Skill dictionary that all characters will adopt
skillDict = {
        "Acrobatics" : Skill(1, True),
        "Appraise": Skill(3),
        "Bluff": Skill(5),
        "Climb": Skill(0, True),
        "Craft": Skill(3),
        "Diplomacy": Skill(5, False),
        "Disable Device": Skill(1),
        "Disguise": Skill(5),
        "Escape Artist": Skill(1, True),
        "Fly": Skill(1, True),
        "Handle Animal": Skill(5),
        "Heal": Skill(4),
        "Intimidate": Skill(5, False),
        "Knowledge(arcana)": Skill(3),
        "Knowledge(dungeoneering)": Skill(3),
        "Knowledge(engineering)": Skill(3),
        "Knowledge(geography)": Skill(3),
        "Knowledge(history)": Skill(3),
        "Knowledge(local)": Skill(3),
        "Knowledge(nature)": Skill(3, False),
        "Knowledge(nobility)": Skill(3),
        "Knowledge(planes)": Skill(3),
        "Knowledge(religion)": Skill(3),
        "Linguistics": Skill(3),
        "Perception" : Skill(4),
        "Perform": Skill(5),
        "Profession": Skill(4),
        "Ride": Skill(1, True),
        "Sense Motive": Skill(4),
        "Sleight of Hand": Skill(1, True),
        "Spellcraft": Skill(3, False),
        "Stealth": Skill(1, True),
        "Survival": Skill(4),
        "Swim": Skill(0, True),
        "Use Magic Device": Skill(5)
    }




