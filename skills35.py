import char

class Skill(object):
    """
    Skills are stored in the character object by using a dictionary, where the skill's
    name references a Skill object.
    """
    def __init__(self, keyAbility, armorCheck=False, synergies=[]):
        self.keyAbility = keyAbility # integer index to an ability list
        self.synergies = synergies # list of skills which add a synergy bonus to this skill
                                  # (only non-situational synergies apply)
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
        # add synergies
        for skill in self.synergies:
            if currentChar.Skills[skill].ranks >= 5:
                bonus += 2
        # add any miscellaneous bonuses
        bonus += self.miscBonus
        return bonus


# construct Skill dictionary that all characters will adopt
skillDict = {
        "Appraise": Skill(3),
        "Balance": Skill(1, True, ["Tumble"]),
        "Bluff": Skill(5),
        "Climb": Skill(0, True),
        "Concentration": Skill(2),
        "Craft": Skill(3),
        "Decipher Script": Skill(3),
        "Diplomacy": Skill(5, False, ["Bluff", "Knowledge(nobility and royalty)", "Sense Motive"]),
        "Disable Device": Skill(1),
        "Disguise": Skill(5),
        "Escape Artist": Skill(1, True),
        "Forgery": Skill(3),
        "Gather Information": Skill(5, False, ["Knowledge(local)"]),
        "Handle Animal": Skill(5),
        "Heal": Skill(4),
        "Hide": Skill(1, True),
        "Intimidate": Skill(5, False, ["Bluff"]),
        "Jump": Skill(0, True, ["Tumble"]),
        "Knowledge(arcana)": Skill(3),
        "Knowledge(architecture and engineering)": Skill(3),
        "Knowledge(dungeoneering)": Skill(3),
        "Knowledge(geography)": Skill(3),
        "Knowledge(history)": Skill(3),
        "Knowledge(local)": Skill(3),
        "Knowledge(nature)": Skill(3, False, ["Survival"]),
        "Knowledge(nobility and royalty)": Skill(3),
        "Knowledge(religion)": Skill(3),
        "Knowledge(the planes)": Skill(3),
        "Listen": Skill(4),
        "Move Silently": Skill(4, True),
        "Open lock": Skill(1),
        "Perform": Skill(5),
        "Profession": Skill(4),
        "Ride": Skill(1, False, ["Handle Animal"]),
        "Search": Skill(3),
        "Sense Motive": Skill(4),
        "Sleight of Hand": Skill(1, True, ["Bluff"]),
        "Spellcraft": Skill(3, False, ["Knowledge(arcana)"]),
        "Spot": Skill(4),
        "Survival": Skill(4),
        "Swim": Skill(0, True),
        "Tumble": Skill(1, True),
        "Use Magic Device": Skill(5),
        "Use Rope": Skill(1)
    }



