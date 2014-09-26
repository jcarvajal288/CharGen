from Functions import calculateBaseAttack, containName, getIndex, die
import Class

#=========== Base Class Definition ===========#

class Feat(object):
    Name = ""
    Source = ""
    FighterBonusFeat = False
    Metamagic = False
    
    def TryFeat(self, newChar):
        if self.CharNotHaveFeat(self, newChar) and self.meetPrerequesites(self, newChar):
            return True
    
    def CharNotHaveFeat(self, newChar):
        if self.Name not in newChar.Feats:
            return True
        else:
            return False
    
    def meetPrerequesites(self, newChar):
        return True
    
    def applyFeat(self, newChar):
        newChar.Feats.append(self.Name)
    
#========== End Base Class Definition =========#
    
class BlindFight(Feat):
    def __init__(self):
        self.Name = "Blind Fight"
        self.Source = "Core"
        self.FighterBonusFeat = True
    
class CombatCasting(Feat):
    def __init__(self):
        self.Name = "Combat Casting"
        self.Source = "Core"
    
class CombatExpertise(Feat):
    def __init__(self):
        self.Name = "Combat Expertise"
        self.Source = "Core"
        self.FighterBonusFeat = True
    
    def meetPrerequisites(self, newChar):
        if newChar.Int >= 13:
            return True
        else:
            return False
        
class ImprovedDisarm(Feat):
    def __init__(self):
        self.Name = "Improved Disarm"
        self.Source = "Core"
        self.FighterBonusFeat = True
    
    def meetPrerequisites(self, newChar):
        if "Combat Expertise" in newChar.Feats:
            return True
        else:
            return False
        
class ImprovedFeint(Feat):
    def __init__(self):
        self.Name = "Improved Feint"
        self.Source = "Core"
        self.FighterBonusFeat = True
    
    def meetPrerequisites(self, newChar):
        if "Combat Expertise" in newChar.Feats:
            return True
        else:
            return False
        
class ImprovedTrip(Feat):
    def __init__(self):
        self.Name = "Improved Trip"
        self.Source = "Core"
        self.FighterBonusFeat = True
    
    def meetPrerequisites(self, newChar):
        if "Combat Expertise" in newChar.Feats:
            return True
        else:
            return False
        
class WhirlwindAttack(Feat):
    def __init__(self):
        self.Name = "Whirlwind Attack"
        self.Source = "Core"
        self.FighterBonusFeat = True
        
    def meetPrerequisites(self, newChar):
        if newChar.Dex >= 13 \
        and "Combat Expertise" in newChar.Feats \
        and "Dodge" in newChar.Feats \
        and "Mobility" in newChar.Feats \
        and "Spring Attack" in newChar.Feats \
        and (calculateBaseAttack(newChar) >= 4):
            return True
        else:
            return False
        
class CombatReflexes(Feat):
    def __init__(self):
        self.Name = "Combat Reflexes"
        self.Source = "Core"
        self.FighterBonusFeat = True
        
class Dodge(Feat):
    def __init__(self):
        self.Name = "Dodge"
        self.Source = "Core"
        self.FighterBonusFeat = True
        
    def meetPrerequisites(self, newChar):
        if newChar.Dex >= 13:
            return True
        else:
            return False
        
class Mobility(Feat):
    def __init__(self):
        self.Name = "Mobility"
        self.Source = "Core"
        self.FighterBonusFeat = True
    
    def meetPrerequisites(self, newChar):
        if "Dodge" in newChar.Feats:
            return True
        else:
            return False
        
class SpringAttack(Feat):
    def __init__(self):
        self.Name = "Spring Attack"
        self.Source = "Core"
        self.FighterBonusFeat = True
    
    def meetPrerequisites(self, newChar):
        if "Mobility" in newChar.Feats \
        and (calculateBaseAttack(newChar) >= 4):
            return True
        else:
            return False
        
class ExoticWeaponProficiency(Feat):
    def __init__(self):
        self.Name = "Exotic Weapon Proficiency"
        self.Source = "Core"
        self.FighterBonusFeat = True
        
    def meetPrerequisites(self, newChar):
        if newChar.Weapon1.Discipline == "Exotic": # in no cases will a character wield two different exotic weapons
            return True
        else:
            return False
        
    def applyFeat(self, newChar):
        newChar.Feats.append(self.Name + "(" + newChar.Weapon1.BaseName + ")")
    
class ExtraTurning(Feat):
    def __init__(self):
        self.Name = "Extra Turning"
        self.Source = "Core"
        
    def meetPrerequisites(self, newChar):
        if containName(newChar.Feats, "Turn or Rebuke Undead"):
            return True
        else:
            return False
        
    def applyFeat(self, newChar):
        newChar.Feats.append(self.Name)
        newChar.SpecialAbilities[getIndex(newChar.Feats, "Turn or Rebuke Undead")] = "Turn or Rebuke Undead" + "(" + (3 + newChar.ChaMod) + ")"
        
class GreatFortitude(Feat):
    def __init__(self):
        self.Name = "Great Fortitude"
        self.Source = "Core"
        
    def applyFeat(self, newChar):
        newChar.Feats.append(self.Name)
        newChar.FortSave.MiscBonus += 2
        
class ImprovedCounterspell(Feat):
    def __init__(self):
        self.Name = "Improved Counterspell"
        self.Source = "Core"
        
    def meetPrerequisites(self, newChar):
        if (newChar.SpellsPerDay):  # searches for a class spellcasting attribute to make sure the character is a caster
            return True
        else:
            return False
        
class ImprovedCritical(Feat):
    def __init__(self):
        self.Name = "Improved Critical"
        self.Source = "Core"
        self.FighterBonusFeat = True
        
    def CharNotHaveFeat(self, newChar):
        if "Improved Critical(" + newChar.Weapon1.BaseName + ")" not in newChar.Feats:
                return True
        elif (newChar.Weapon2):
            if "Improved Critical(" + newChar.Weapon2.BaseName + ")" not in newChar.Feats:
                return True
        
    def meetPrerequisites(self, newChar):
        if (calculateBaseAttack(newChar)) >= 8:
            return True
        else:
            return False
        
    def applyFeat(self, newChar):
        if "Improved Critical(" + newChar.Weapon1.BaseName + ")" not in newChar.Feats:
            newChar.Feats.append("Improved Critical(" + newChar.Weapon1.BaseName + ")")
            newChar.Weapon1.CritRange *= 2
        elif "Improved Critical(" + newChar.Weapon2.BaseName + ")" not in newChar.Feats:
            newChar.Feats.append("Improved Critical(" + newChar.Weapon2.BaseName + ")")
            newChar.Weapon2.CritRange *= 2
            
class ImprovedInitiative(Feat):
    def __init__(self):
        self.Name = "Improved Initiative"
        self.Source = "Core"
        self.FighterBonusFeat = True
        
    def applyFeat(self, newChar):
        newChar.Feats.append(self.Name)
        newChar.Init += 4
        
class ImprovedTurning(Feat):
    def __init__(self):
        self.Name = "Improved Turning"
        self.Source = "Core"
        
    def meetPrerequisites(self, newChar):
        if containName(newChar.Feats, "Turn or Rebuke Undead"):
            return True
        else:
            return False
        
class ImprovedUnarmedStrike(Feat):
    def __init__(self):
        self.Name = "Improved Unarmed Strike"
        self.Source = "Core"
        self.FighterBonusFeat = True
        
class ImprovedGrapple(Feat):
    def __init__(self):
        self.Name = "Improved Grapple"
        self.Source = "Core"
        self.FighterBonusFeat = True
        
    def applyFeat(self, newChar):
        newChar.Feats.append(self.Name)
        newChar.Grapple += 4
        
class DeflectArrows(Feat):
    def __init__(self):
        self.Name = "Deflect Arrows"
        self.Source = "Core"
        self.FighterBonusFeat = True
        
    def meetRequirements(self, newChar):
        if newChar.Dex >= 13 \
        and "Improved Unarmed Strike" in newChar.Feats:
            return True
        else:
            return False
        
class SnatchArrows(Feat):
    def __init__(self):
        self.Name = "Snatch Arrows"
        self.Source = "Core"
        self.FighterBonusFeat = True
        
    def meetRequirements(self, newChar):
        if newChar.Dex >= 15 \
        and "Deflect Arrows" in newChar.Feats:
            return True
        else:
            return False
        
class StunningFist(Feat):
    def __init__(self):
        self.Name = "Stunning Fist"
        self.Source = "Core"
        self.FighterBonusFeat = True
        
    def meetRequirements(self, newChar):
        if newChar.Dex >= 13 \
        and newChar.Dex >= 15 \
        and "Improved Unarmed Strike" in newChar.Feats \
        and calculateBaseAttack(newChar) >= 8:
            return True
        else:
            return False
        
    def applyFeat(self, newChar):
        if isinstance(newChar, Class.Monk):
            newChar.Feats.append("Stunning Fist(" + newChar.Level + "/ day)")
        else:
            newChar.Feats.append("Stunning Fist(" + (newChar.Level/4) + "/ day)")
        
class LightningReflexes(Feat):
    def __init__(self):
        self.Name = "Lightning Reflexes"
        self.Source = "Core"
        
    def applyFeat(self, newChar):
        newChar.Feats.append(self.Name)
        newChar.RefSave.MiscBonus += 2
        
class NaturalSpell(Feat):
    def __init__(self):
        self.Name = "Natural Spell"
        self.Source = "Core"
        
    def meetRequirements(self, newChar):
        if newChar.Wis >= 13 \
        and containName(newChar.SpecialAbilities, "Wild Shape"):
            return True
        else:
            return False
        
class PointBlankShot(Feat):
    def __init__(self):
        self.Name = "Point Blank Shot"
        self.Source = "Core"
        self.FighterBonusFeat = True
        
    def meetRequirements(self, newChar):
        if newChar.Weapon1.Class == "Ranged":
            return True
        else:
            return False
        
class FarShot(Feat):
    def __init__(self):
        self.Name = "Far Shot"
        self.Source = "Core"
        
    def meetRequirements(self, newChar):
        if "Point Blank Shot" in newChar.Feats:
            return True
        else:
            return False
    
    def applyFeat(self, newChar):
        if (newChar.Weapon1.Throwing):
            newChar.Weapon1.Range *= 2
        else:
            newChar.Weapon1.Range += (newChar.Weapon1.Range/2)
    
class RapidShot(Feat):
    def __init__(self):
        self.Name = "Far Shot"
        self.Source = "Core"
        self.FighterBonusFeat = True
        
    def meetRequirements(self, newChar):
        if "Point Blank Shot" in newChar.Feats \
        and newChar.Dex >= 13:
            return True
        else:
            return False
        
class Manyshot(Feat):
    def __init__(self):
        self.Name = "Manyshot"
        self.Source = "Core"
        self.FighterBonusFeat = True
        
    def meetRequirements(self, newChar):
        if newChar.Dex >= 17 \
        and "Rapid Shot" in newChar.Feats \
        and calculateBaseAttack(newChar) >= 6:
            return True
        else:
            return False
        
    def applyFeat(self, newChar):
        num = ((calculateBaseAttack(newChar) - 1) / 5) + 1 # messy, but this should work (2 arrows at +6, 3 at +11, 4 at +16)
        if num > 4:
            num = 4 
        newChar.Feats.append("Manyshot(" + num + " arrows)")
        
class ShotOnTheRun(Feat):
    def __init__(self):
        self.Name = "Shot on the Run"
        self.Source = "Core"
        self.FighterBonusFeat = True
        
    def meetRequirements(self, newChar):
        if newChar.Dex >= 13 \
        and "Dodge" in newChar.Feats \
        and "Mobility" in newChar.Feats \
        and "Point Blank Shot" in newChar.Feats \
        and calculateBaseAttack(newChar) >= 4:
            return True
        else:
            return False
        
class ImprovedPreciseShot(Feat):
    def __init__(self):
        self.Name = "Improved Precise Shot"
        self.Source = "Core"
        self.FighterBonusFeat = True
        
    def meetRequirements(self, newChar):
        if newChar.Dex >= 19 \
        and "Point Blank Shot" in newChar.Feats \
        and "Rapid Shot" in newChar.Feats \
        and calculateBaseAttack(newChar) >= 11:
            return True
        else:
            return False
        
class PowerAttack(Feat):
    def __init__(self):
        self.Name = "Power Attack"
        self.Source = "Core"
        self.FighterBonusFeat = True
        
    def meetRequirements(self, newChar):
        if newChar.Str >= 13 \
        and newChar.Weapon1.Class != "Ranged":
            return True
        else:
            return False
        
class Cleave(Feat):
    def __init__(self):
        self.Name = "Cleave"
        self.Source = "Core"
        self.FighterBonusFeat = True
        
    def meetRequirements(self, newChar):
        if "Power Attack" in newChar.Feats:
            return True
        else:
            return False
        
class GreatCleave(Feat):
    def __init__(self):
        self.Name = "Great Cleave"
        self.Source = "Core"
        self.FighterBonusFeat = True
        
    def meetRequirements(self, newChar):
        if "Cleave" in newChar.Feats \
        and calculateBaseAttack(newChar) >= 4:
            return True
        else:
            return False
        
class ImprovedBullRush(Feat):
    def __init__(self):
        self.Name = "Improved Bull Rush"
        self.Source = "Core"
        self.FighterBonusFeat = True
        
    def meetRequirements(self, newChar):
        if "Power Attack" in newChar.Feats:
            return True
        else:
            return False
        
class ImprovedOverrun(Feat):
    def __init__(self):
        self.Name = "Improved Overrun"
        self.Source = "Core"
        self.FighterBonusFeat = True
        
    def meetRequirements(self, newChar):
        if "Power Attack" in newChar.Feats:
            return True
        else:
            return False
        
class ImprovedSunder(Feat):
    def __init__(self):
        self.Name = "Improved Sunder"
        self.Source = "Core"
        self.FighterBonusFeat = True
        
    def meetRequirements(self, newChar):
        if "Power Attack" in newChar.Feats:
            return True
        else:
            return False
        
class QuickDraw(Feat):
    def __init__(self):
        self.Name = "Quick Draw"
        self.Source = "Core"
        self.FighterBonusFeat = True
        
    def meetRequirements(self, newChar):
        if calculateBaseAttack(newChar) >= 1:
            return True
        else:
            return False
        
class RapidReload(Feat):
    def __init__(self):
        self.Name = "Rapid Reload"
        self.Source = "Core"
        self.FighterBonusFeat = True
        
    def meetRequirements(self, newChar):
        if "Crossbow" in newChar.Weapon1.BaseName:
            return True
        else:
            return False
        
class SpellFocus(Feat):
    def __init__(self):
        self.Name = "Spell Focus"
        self.Source = "Core"
        
    def meetRequirements(self, newChar):
        if (newChar.Class.SpellsPerDay):
            return True
        else:
            return False
        
    def applyFeat(self, newChar):
        if (newChar.SpecialSchool):
            newChar.Feats.append("Spell Focus(" + newChar.SpecialSchool + ")")
        else:
            d8 = die(8,1)
            if   d8 == 1:
                newChar.Feats.append("Spell Focus(Abjuration)")
            elif d8 == 2:
                newChar.Feats.append("Spell Focus(Conjuration)")
            elif d8 == 3:
                newChar.Feats.append("Spell Focus(Divination)")
            elif d8 == 4:
                newChar.Feats.append("Spell Focus(Enchantment)")
            elif d8 == 5:
                newChar.Feats.append("Spell Focus(Evocation)")
            elif d8 == 6:
                newChar.Feats.append("Spell Focus(Illusion)")
            elif d8 == 7:
                newChar.Feats.append("Spell Focus(Necromancy)")
            elif d8 == 8:
                newChar.Feats.append("Spell Focus(Transmutation)")
                
class GreaterSpellFocus(Feat):
    def __init__(self):
        self.Name = "Greater Spell Focus"
        self.Source = "Core"
        
    def meetRequirements(self, newChar):
        if containName(newChar.Feats, "Spell Focus"):
            return True
        else:
            return False
        
    def applyFeat(self, newChar):
        newChar.Feats[getIndex(newChar.Feats, "Spell Focus")] = "Greater " + getIndex(newChar.Feats, "Spell Focus")
        
class SpellPenetration(Feat):
    def __init__(self):
        self.Name = "Spell Penetration"
        self.Source = "Core"
        
    def meetRequirements(self, newChar):
        if (newChar.SpellsPerDay):
            return True
        else:
            return False
        
class GreaterSpellPenetration(Feat):
    def __init__(self):
        self.Name = "Greater Spell Penetration"
        self.Source = "Core"
        
    def meetRequirements(self, newChar):
        if "Spell Penetration" in newChar.Feats:
            return True
        else:
            return False
        
    def applyFeat(self, newChar):
        newChar.Feats[getIndex(newChar.Feats, "Spell Penetration")] = "Greater Spell Penetration"
        
class TwoWeaponFighting(Feat):
    def __init__(self):
        self.Name = "Two-Weapon Fighting"
        self.Source = "Core"
        self.FighterBonusFeat = True
        
    def meetRequirements(self, newChar):
        if newChar.Style == "Dual-Wield" \
        and newChar.Dex >= 15:
            return True
        else:
            return False
        
class TwoWeaponDefense(Feat):
    def __init__(self):
        self.Name = "Two-Weapon Defense"
        self.Source = "Core"
        self.FighterBonusFeat = True
        
    def meetRequirements(self, newChar):
        if "Two-Weapon Fighting" in newChar.Feats \
        and newChar.Dex >= 15:
            return True
        else:
            return False
        
    def applyFeat(self, newChar):
        newChar.Feats.append(self.Name)
        newChar.AC.ShieldBonus += 1
        
class ImprovedTwoWeaponFighting(Feat):
    def __init__(self):
        self.Name = "Improved Two-Weapon Fighting"
        self.Source = "Core"
        self.FighterBonusFeat = True
        
    def meetRequirements(self, newChar):
        if  newChar.Dex >= 17 \
        and "Two-Weapon Fighting" in newChar.Feats \
        and calculateBaseAttack(newChar) >= 6:
            return True
        else:
            return False
        
class GreaterTwoWeaponFighting(Feat):
    def __init__(self):
        self.Name = "Greater Two-Weapon Fighting"
        self.Source = "Core"
        self.FighterBonusFeat = True
        
    def meetRequirements(self, newChar):
        if  newChar.Dex >= 19 \
        and "Improved Two-Weapon Fighting" in newChar.Feats \
        and calculateBaseAttack(newChar) >= 11:
            return True
        else:
            return False
        
class WeaponFinesse(Feat):
    def __init__(self):
        self.Name = "Weapon Finesse"
        self.Source = "Core"
        self.FighterBonusFeat = True
        
    def meetRequirements(self, newChar):
        if newChar.DexMod >= newChar.StrMod \
        and (newChar.Shield == False) \
        and (newChar.Weapon1.Class == "Light" \
             or newChar.Weapon.BaseName == "Rapier" \
             or newChar.Weapon.BaseName == "Whip" \
             or newChar.Weapon.BaseName == "Spiked Chain"):
            return True
        else:
            return False
        
class WeaponFocus(Feat):
    def __init__(self):
        self.Name = "Weapon Focus"
        self.Source = "Core"
        self.FighterBonusFeat = True
        
    def CharNotHaveFeat(self, newChar):
        if "Weapon Focus(" + newChar.Weapon1.BaseName + ")" not in newChar.Feats:
                return True
        elif (newChar.Weapon2):
            if "Weapon Focus(" + newChar.Weapon2.BaseName + ")" not in newChar.Feats:
                return True
        
    def meetPrerequisites(self, newChar):
        if calculateBaseAttack(newChar) >= 1:
            return True
        else:
            return False
        
    def applyFeat(self, newChar):
        if "Weapon Focus(" + newChar.Weapon1.BaseName + ")" not in newChar.Feats:
            newChar.Feats.append("Weapon Focus(" + newChar.Weapon1.BaseName + ")")
            newChar.Weapon1.Attack[0] += 1
        elif "Weapon Focus(" + newChar.Weapon2.BaseName + ")" not in newChar.Feats:
            newChar.Feats.append("Weapon Focus(" + newChar.Weapon2.BaseName + ")")
            newChar.Weapon2.Attack[0] += 1
        else:
            print "ERROR: Attempted to apply Weapon Focus when it had already been applied the maximum amount of times."
            
class WeaponSpecialization(Feat):
    def __init__(self):
        self.Name = "Weapon Specialization"
        self.Source = "Core"
        self.FighterBonusFeat = True
        
    def CharNotHaveFeat(self, newChar):
        if "Weapon Specialization(" + newChar.Weapon1.BaseName + ")" not in newChar.Feats:
                return True
        elif (newChar.Weapon2):
            if "Weapon Specialization(" + newChar.Weapon2.BaseName + ")" not in newChar.Feats:
                return True
        
    def meetPrerequisites(self, newChar):
        if isinstance(newChar.Class, Class.Fighter) \
        and "Weapon Focus" in newChar.Feats \
        and calculateBaseAttack(newChar) >= 4:
            return True
        else:
            return False
        
    def applyFeat(self, newChar):
        if "Weapon Specialization(" + newChar.Weapon1.BaseName + ")" not in newChar.Feats:
            newChar.Feats.append("Weapon Specialization(" + newChar.Weapon1.BaseName + ")")
            newChar.Weapon1.DamageBonus += 2
        elif "Weapon Specialization(" + newChar.Weapon2.BaseName + ")" not in newChar.Feats:
            if "Weapon Focus(" + newChar.Weapon2.BaseName + ")" not in newChar.Feats: # if the second weapon does not have Weapon Focus,
                newChar.Feats.append("Weapon Focus(" + newChar.Weapon1.BaseName + ")")# this replaces Weapon Specialization with Weapon Focus
                newChar.Weapon2.Attack[0] += 1
            else:
                newChar.Feats.append("Weapon Specialization(" + newChar.Weapon2.BaseName + ")")
                newChar.Weapon2.DamageBonus += 2
        else:
            print "ERROR: Attempted to apply Weapon Specialization when it had already been applied the maximum amount of times."
            
class GreaterWeaponFocus(Feat):
    def __init__(self):
        self.Name = "Greater Weapon Focus"
        self.Source = "Core"
        self.FighterBonusFeat = True
        
    def CharNotHaveFeat(self, newChar):
        if "Greater Weapon Focus(" + newChar.Weapon1.BaseName + ")" not in newChar.Feats:
                return True
        elif (newChar.Weapon2):
            if "Greater Weapon Focus(" + newChar.Weapon2.BaseName + ")" not in newChar.Feats:
                return True
        
    def meetPrerequisites(self, newChar):
        if isinstance(newChar.Class, Class.Fighter) \
        and "Weapon Focus" in newChar.Feats \
        and calculateBaseAttack(newChar) >= 8:
            return True
        else:
            return False
        
    def applyFeat(self, newChar):
        if "Greater Weapon Focus(" + newChar.Weapon1.BaseName + ")" not in newChar.Feats:
            newChar.Feats.append("Greater Weapon Focus(" + newChar.Weapon1.BaseName + ")")
            newChar.Weapon1.Attack[0] += 1
        elif "Greater Weapon Focus(" + newChar.Weapon2.BaseName + ")" not in newChar.Feats:
            if "Weapon Focus(" + newChar.Weapon2.BaseName + ")" not in newChar.Feats:
                newChar.Feats.append("Weapon Focus(" + newChar.Weapon1.BaseName + ")")
                newChar.Weapon2.Attack[0] += 1
            else:
                newChar.Feats.append("Greater Weapon Focus(" + newChar.Weapon2.BaseName + ")")
                newChar.Weapon2.Attack[0] += 1
        else:
            print "ERROR: Attempted to apply Greater Weapon Focus when it had already been applied the maximum amount of times."
            
class GreaterWeaponSpecialization(Feat):
    def __init__(self):
        self.Name = "Greater Weapon Specialization"
        self.Source = "Core"
        self.FighterBonusFeat = True
        
    def CharNotHaveFeat(self, newChar):
        if "Greater Weapon Specialization(" + newChar.Weapon1.BaseName + ")" not in newChar.Feats:
                return True
        elif (newChar.Weapon2):
            if "Greater Weapon Specialization(" + newChar.Weapon2.BaseName + ")" not in newChar.Feats:
                return True
        
    def meetPrerequisites(self, newChar):
        if isinstance(newChar.Class, Class.Fighter) \
        and "Greater Weapon Focus" in newChar.Feats \
        and "Weapon Specialization" in newChar.Feats \
        and calculateBaseAttack(newChar) >= 12:
            return True
        else:
            return False
        
    def applyFeat(self, newChar):
        if "Greater Weapon Specialization(" + newChar.Weapon1.BaseName + ")" not in newChar.Feats:
            newChar.Feats.append("Greater Weapon Specialization(" + newChar.Weapon1.BaseName + ")")
            newChar.Weapon1.DamageBonus += 2
        elif "Greater Weapon Specialization(" + newChar.Weapon2.BaseName + ")" not in newChar.Feats:
            if "Weapon Focus(" + newChar.Weapon2.BaseName + ")" not in newChar.Feats: # if the second weapon does not have Weapon Focus,
                newChar.Feats.append("Weapon Focus(" + newChar.Weapon1.BaseName + ")")# this replaces Greater Weapon Specialization with Weapon Focus
                newChar.Weapon1.Attack[0] += 1
            elif "Weapon Specialization(" + newChar.Weapon2.BaseName + ")" not in newChar.Feats: # does the same for Weapon Specialization
                newChar.Feats.append("Weapon Specialization(" + newChar.Weapon2.BaseName + ")")
                newChar.Weapon1.DamageBonus += 2
            else:
                newChar.Feats.append("Greater Weapon Specialization(" + newChar.Weapon2.BaseName + ")")
                newChar.Weapon2.DamageBonus += 2
        else:
            print "ERROR: Attempted to apply Greater Weapon Specialization when it had already been applied the maximum amount of times."
        
class EmpowerSpell(Feat):
    def __init__(self):
        self.Name = "Empower Spell"
        self.Source = "Core"
        self.Metamagic = True
        
    def meetRequirements(self, newChar):
        if (newChar.SpellsPerDay):
            return True
        else:
            return False
        
class EnlargeSpell(Feat):
    def __init__(self):
        self.Name = "Enlarge Spell"
        self.Source = "Core"
        self.Metamagic = True
        
    def meetRequirements(self, newChar):
        if (newChar.SpellsPerDay):
            return True
        else:
            return False
        
class ExtendSpell(Feat):
    def __init__(self):
        self.Name = "Extend Spell"
        self.Source = "Core"
        self.Metamagic = True
        
    def meetRequirements(self, newChar):
        if (newChar.SpellsPerDay):
            return True
        else:
            return False
        
class HeightenSpell(Feat):
    def __init__(self):
        self.Name = "Heighten Spell"
        self.Source = "Core"
        self.Metamagic = True
        
    def meetRequirements(self, newChar):
        if (newChar.SpellsPerDay):
            return True
        else:
            return False
        
class MaximizeSpell(Feat):
    def __init__(self):
        self.Name = "Maximize Spell"
        self.Source = "Core"
        self.Metamagic = True
        
    def meetRequirements(self, newChar):
        if (newChar.SpellsPerDay):
            return True
        else:
            return False 
        
class QuickenSpell(Feat):
    def __init__(self):
        self.Name = "Quicken Spell"
        self.Source = "Core"
        self.Metamagic = True
        
    def meetRequirements(self, newChar):
        if (newChar.SpellsPerDay):
            return True
        else:
            return False    
        
class SilentSpell(Feat):
    def __init__(self):
        self.Name = "Empower Spell"
        self.Source = "Core"
        self.Metamagic = True
        
    def meetRequirements(self, newChar):
        if (newChar.SpellsPerDay):
            return True
        else:
            return False
        
class StillSpell(Feat):
    def __init__(self):
        self.Name = "Still Spell"
        self.Source = "Core"
        self.Metamagic = True
        
    def meetRequirements(self, newChar):
        if (newChar.SpellsPerDay):
            return True
        else:
            return False
        
class WidenSpell(Feat):
    def __init__(self):
        self.Name = "Widen Spell"
        self.Source = "Core"
        self.Metamagic = True
        
    def meetRequirements(self, newChar):
        if (newChar.SpellsPerDay):
            return True
        else:
            return False
        
def compileBaseFeatList():
    BaseFeatList = (BlindFight(),\
                    CombatCasting(),\
                    CombatExpertise(),\
                    ImprovedDisarm(),\
                    ImprovedFeint(),\
                    ImprovedTrip(),\
                    WhirlwindAttack(),\
                    CombatReflexes(),\
                    Dodge(),\
                    Mobility(),\
                    SpringAttack(),\
                    ExoticWeaponProficiency(),\
                    ExtraTurning(),\
                    GreatFortitude(),\
                    ImprovedCounterspell(),\
                    ImprovedCritical(),\
                    ImprovedInitiative(),\
                    ImprovedTurning(),\
                    ImprovedUnarmedStrike(),\
                    ImprovedGrapple(),\
                    DeflectArrows(),\
                    SnatchArrows(),\
                    StunningFist(),\
                    LightningReflexes(),\
                    NaturalSpell(),\
                    PointBlankShot(),\
                    FarShot(),\
                    RapidShot(),\
                    Manyshot(),\
                    ShotOnTheRun(),\
                    ImprovedPreciseShot(),\
                    PowerAttack(),\
                    Cleave(),\
                    GreatCleave(),\
                    ImprovedBullRush(),\
                    ImprovedOverrun(),\
                    ImprovedSunder(),\
                    QuickDraw(),\
                    RapidReload(),\
                    SpellFocus(),\
                    GreaterSpellFocus(),\
                    SpellPenetration(),\
                    GreaterSpellPenetration(),\
                    TwoWeaponFighting(),\
                    TwoWeaponDefense(),\
                    ImprovedTwoWeaponFighting(),\
                    GreaterTwoWeaponFighting(),\
                    WeaponFinesse(),\
                    WeaponFocus(),\
                    WeaponSpecialization(),\
                    GreaterWeaponFocus(),\
                    GreaterWeaponSpecialization(),\
                    EmpowerSpell(),\
                    EnlargeSpell(),\
                    ExtendSpell(),\
                    HeightenSpell(),\
                    MaximizeSpell(),\
                    QuickenSpell(),\
                    SilentSpell(),\
                    StillSpell(),\
                    WidenSpell()) 
    return BaseFeatList