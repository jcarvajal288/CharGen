/////////////////////////////////////////////////////
// D&D Random Treasure Generator
// Author: Max Carvajal
// Version 1.2
//
// This program reproduces the Random Treasure by Level Table and Random Magic Item Generation Table found
// in the 3.5 Dungeon Master's Guide.  
//
// Changes from the official version include the addition of the Maul (a Large warhammer) 
// to the Common Weapons Table, and moved the nunchaku, kama, and siangham to the Uncommon 
// Weapons Table from the Common Table. These weapons were replaced by the battleaxe, warhammer, 
// and morningstar in the Common Table.
//
// I wrote this code after I had taken my first C++ course in college.  I know it's horrible.
// Please don't judge.
/////////////////////////////////////////////////////
// Log:
// 06/28/2008		Began editing 1.0
// 06/28/2008		Fixed faulty random number generators
// 06/29/2008		Implemented Weapon class 
//						Modified relevant Weapon functions
// 06/30/2008		Expanded Weapon class to include range and throwing data 
//						Edited weapon ability functions
// 08/28/2010       Fixed code to compile under g++, changed main to use an integer
//                      argument that specifies which level of treasure to generate.
/////////////////////////////////////////////////////

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <unistd.h>
using namespace std;

class Weapon
{
public:
	string name;
	char type; //types are listed as 'b', 'p', or 's', for bludgeoning, piercing, and slashing respectively. For weapons with no type, such as a net, a '-' is used.
			   //weapons with two types (such as morningstars) only have the most relevant type listed. Usually this results in piercing being omitted, because there are no relevant rules are abilities for piercing weapons.
	char range;//range is whether the weapon is melee or ranged. 'r' or 'm' respectively.
	bool throwing;//whether the weapon can be thrown or not
	Weapon() : name(""), type('-'), range('-'), throwing(false) {}
	Weapon(string s, char c, char h, bool b) : name(s), type(c), range(h), throwing(b) {}
	friend ostream& operator << (ostream& os, const Weapon& w) 
	{
		os << w.name;
		return os;
	}
	Weapon& operator=(const Weapon& w)
	{
		name = w.name;
		type = w.type;
		range = w.range;
		throwing = w.throwing;
        return *this;
	}
//double headed weapons are treated as single weapons for the purpose of this program. Treat the properties of a double headed weapon as applying to both heads.
//if this results in an illegal weapon head (such as the spear end of a Vorpal Dwarven Urgrosh), then the property only applies to the legal head.
};

void Level_1();
void Level_2();
void Level_3();
void Level_4();
void Level_5();
void Level_6();
void Level_7();
void Level_8();
void Level_9();
void Level_10();
void Level_11();
void Level_12();
void Level_13();
void Level_14();
void Level_15();
void Level_16();
void Level_17();
void Level_18();
void Level_19();
void Level_20();

void gem();
void art();

void mundaneItem();
void minorItem();
void mediumItem();
void majorItem();

void mundaneArmor();
void minorArmor();
void mediumArmor();
void majorArmor();
string randomArmor();
string randomShield();
void minorSpecificArmor();
void mediumSpecificArmor();
void majorSpecificArmor();
void minorSpecificShield();
void mediumSpecificShield();
void majorSpecificShield();
string minorArmorAbility(int);
string mediumArmorAbility(int);
string majorArmorAbility(int);
string minorShieldAbility(int);
string mediumShieldAbility(int);
string majorShieldAbility(int);

Weapon randomWeapon();
	Weapon commonWeapon();
	Weapon uncommonWeapon();
	Weapon rangedWeapon();
void minorWeapon();
void mediumWeapon();
void majorWeapon();
void minorSpecificWeapon();
void mediumSpecificWeapon();
void majorSpecificWeapon();
string minorWeaponAbility(Weapon, int);
string mediumWeaponAbility(Weapon, int);
string majorWeaponAbility(Weapon, int);

void minorPotion();
void mediumPotion();
void majorPotion();

void minorRing();
void mediumRing();
void majorRing();

void mediumRod();
void majorRod();

void minorScrollType();
void mediumScrollType();
void majorScrollType();
void minorAScroll();
void mediumAScroll();
void majorAScroll();
	void ASpell_0();
	void ASpell_1();
	void ASpell_2();
	void ASpell_3();
	void ASpell_4();
	void ASpell_5();
	void ASpell_6();
	void ASpell_7();
	void ASpell_8();
	void ASpell_9();
void minorDScroll();
void mediumDScroll();
void majorDScroll();
	void DSpell_0();
	void DSpell_1();
	void DSpell_2();
	void DSpell_3();
	void DSpell_4();
	void DSpell_5();
	void DSpell_6();
	void DSpell_7();
	void DSpell_8();
	void DSpell_9();

void mediumStaff();
void majorStaff();

void minorWand();
void mediumWand();
void majorWand();

void minorWondrousItem();
void mediumWondrousItem();
void majorWondrousItem();

int main(int argc, char** argv)
{
    int seed = (int)time(0);
    srand(seed);
    if(argc != 2)
    {
        cerr << "Wrong number of arguments. Specify one integer argument." << endl;
    }
    else
    {
        switch(atoi(argv[1]))
        {
            case 1: Level_1(); break;
            case 2: Level_2(); break;
            case 3: Level_3(); break;
            case 4: Level_4(); break;
            case 5: Level_5(); break;
            case 6: Level_6(); break;
            case 7: Level_7(); break;
            case 8: Level_8(); break;
            case 9: Level_9(); break;
            case 10: Level_10(); break;
            case 11: Level_11(); break;
            case 12: Level_12(); break;
            case 13: Level_13(); break;
            case 14: Level_14(); break;
            case 15: Level_15(); break;
            case 16: Level_16(); break;
            case 17: Level_17(); break;
            case 18: Level_18(); break;
            case 19: Level_19(); break;
            case 20: Level_20(); break;
            default:
                cerr << "Invalid argument.  Specify an integer between 1 and 20." << endl;
        }
    }
}

void Level_1()
{
	int d100, value;
	/*******************
	Coins
	*******************/
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 14))
	{
		cout << "No coins" << endl;
	}
	else if((15 <= d100) && (d100 <= 29))
	{
		value=rand()%6+1;
		cout << value*1000 << " cp" << endl;
	}
	else if((30 <= d100) && (d100 <= 52))
	{
		value=rand()%8+1;
		cout << value*100 << " sp" << endl;
	}
	else if((53 <= d100) && (d100 <= 95))
	{
		value=rand()%15+2;
		cout << value*10 << " gp" << endl;
	}
	else
	{
		value=rand()%4+1;
		cout << value*10 << " pp" << endl;
	}
	cout << endl;
	/*******************
	Goods
	*******************/
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 90))
	{
		cout << "No goods" << endl;
	}
	else
	{
		value = rand()%2;
		if(value)
			gem();
		else
			art();
	}
	cout << endl;
	/*******************
	Items
	*******************/
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 71))
	{
		cout << "No items" << endl;
	}
	else if((72 <= d100) && (d100 <= 95))
	{
		mundaneItem();
	}
	else
	{
		minorItem();
	}
}

void Level_2()
{
	int d100, value;
	/*******************
	Coins
	*******************/
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 13))
	{
		cout << "No coins" << endl;
	}
	else if((14 <= d100) && (d100 <= 23))
	{
		value=rand()%10+1;
		cout << value*1000 << " cp" << endl;
	}
	else if((24 <= d100) && (d100 <= 43))
	{
		value=rand()%9+2;
		cout << value*100 << " sp" << endl;
	}
	else if((44 <= d100) && (d100 <= 95))
	{
		value=rand()%37+4;
		cout << value*10 << " gp" << endl;
	}
	else
	{
		value=rand()%15+2;
		cout << value*10 << " pp" << endl;
	}
	cout << endl;
	/*******************
	Goods
	*******************/
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 81))
	{
		cout << "No goods" << endl;
	}
	else
	{
		int d3 = rand()%4+1;
		for(int i=0; i<d3; i++)
		{
			value = rand()%2;
			if(value)
				gem();
			else
				art();
		}
	}
	cout << endl;
	/*******************
	Items
	*******************/
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 49))
	{
		cout << "No items" << endl;
	}
	else if((50 <= d100) && (d100 <= 85))
	{
		mundaneItem();
	}
	else
	{
		minorItem();
	}
}

void Level_3()
{
	int d100, value;
	/*******************
	Coins
	*******************/
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 11))
	{
		cout << "No coins" << endl;
	}
	else if((12 <= d100) && (d100 <= 21))
	{
		value=rand()%19+2;
		cout << value*1000 << " cp" << endl;
	}
	else if((22 <= d100) && (d100 <= 41))
	{
		value=rand()%29+4;
		cout << value*100 << " sp" << endl;
	}
	else if((42 <= d100) && (d100 <= 95))
	{
		value=rand()%4+1;
		cout << value*100 << " gp" << endl;
	}
	else
	{
		value=rand()%10+1;
		cout << value*10 << " pp" << endl;
	}
	cout << endl;
	/*******************
	Goods
	*******************/
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 77))
	{
		cout << "No goods" << endl;
	}
	else
	{
		int d3 = rand()%3+1;
		for(int i=0; i<d3; i++)
		{
			value = rand()%2;
			if(value)
				gem();
			else
				art();
		}
	}
	cout << endl;
	/*******************
	Items
	*******************/
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 49))
	{
		cout << "No items" << endl;
	}
	else if((50 <= d100) && (d100 <= 79))
	{
		int d3 = rand()%3+1;
		for(int i=0; i<d3; i++)
		{
			mundaneItem();
		}
	}
	else
	{
		minorItem();
	}
}

void Level_4()
{
	int d100, value;
	/*******************
	Coins
	*******************/
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 11))
	{
		cout << "No coins" << endl;
	}
	else if((12 <= d100) && (d100 <= 21))
	{
		value=rand()%28+3;
		cout << value*1000 << " cp" << endl;
	}
	else if((22 <= d100) && (d100 <= 41))
	{
		value=rand()%45+4;
		cout << value*100 << " sp" << endl;
	}
	else if((42 <= d100) && (d100 <= 95))
	{
		value=rand()%6+1;
		cout << value*100 << " gp" << endl;
	}
	else
	{
		value=rand()%8+1;
		cout << value*10 << " pp" << endl;
	}
	cout << endl;
	/*******************
	Goods
	*******************/
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 70))
	{
		cout << "No goods" << endl;
	}
	else if((71 <= d100) && (d100 <= 95))
	{
		int d4 = rand()%4+1;
		for(int i=0; i<d4; i++)
		{
			gem();
		}
	}
	else
	{
		int d3 = rand()%3+1;
		for(int i=0; i<d3; i++)
		{
			art();
		}
	}
	cout << endl;
	/*******************
	Items
	*******************/
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 42))
	{
		cout << "No items" << endl;
	}
	else if((43 <= d100) && (d100 <= 62))
	{
		int d4 = rand()%4+1;
		for(int i=0; i<d4; i++)
		{
			mundaneItem();
		}
	}
	else
	{
		minorItem();
	}
}

void Level_5()
{
	int d100, value;
	/*******************
	Coins
	*******************/
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 10))
	{
		cout << "No coins" << endl;
	}
	else if((11 <= d100) && (d100 <= 19))
	{
		value=rand()%4+1;
		cout << value*10000 << " cp" << endl;
	}
	else if((20 <= d100) && (d100 <= 38))
	{
		value=rand()%6+1;
		cout << value*1000 << " sp" << endl;
	}
	else if((39 <= d100) && (d100 <= 95))
	{
		value=rand()%8+1;
		cout << value*100 << " gp" << endl;
	}
	else
	{
		value=rand()%10+1;
		cout << value*10 << " pp" << endl;
	}
	cout << endl;
	/*******************
	Goods
	*******************/
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 70))
	{
		cout << "No goods" << endl;
	}
	else if((71 <= d100) && (d100 <= 95))
	{
		int d4 = rand()%4+1;
		for(int i=0; i<d4; i++)
		{
			gem();
		}
	}
	else
	{
		int d3 = rand()%3+1;
		for(int i=0; i<d3; i++)
		{
			art();
		}
	}
	cout << endl;
	/*******************
	Items
	*******************/
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 42))
	{
		cout << "No items" << endl;
	}
	else if((43 <= d100) && (d100 <= 62))
	{
		int d4 = rand()%4+1;
		for(int i=0; i<d4; i++)
		{
			mundaneItem();
		}
	}
	else
	{
		minorItem();
	}
}

void Level_6()
{
	int d100 = rand()%100+1;
	int value;
	/*********************
	Coins
	*********************/
	if(d100 <= 10)
	{
		cout << "No coins" << endl;
	}
	else if((11 <= d100) && (d100 <= 18))
	{
		value = rand()%6+1;
		cout << value*10000 << " cp" << endl;
	}
	else if((19 <= d100) && (d100 <= 37))
	{
		value = rand()%8+1;
		cout << value*1000 << " sp" << endl;
	}
	else if((38 <= d100) && (d100 <=95))
	{
		value = rand()%10+1;
		cout << value*100 << " gp" << endl;
	}
	else
	{
		value = rand()%12+1;
		cout << value*10 << " pp" << endl;
	}
	cout << endl;
	/*********************
	Goods
	*********************/
	d100 = rand()%100+1;
	if(d100 <= 56)
	{
		cout << "No goods" << endl;
	}
	else if((57 <= d100) && (d100 <= 92))
	{
		int d4 = rand()%4+1;
		for(int i=0; i<d4; i++)
		{
			gem();
		}
	}
	else
	{
		int d4 = rand()%4+1;
		for(int i=0; i<d4; i++)
		{
			art();
		}
	}
	cout << endl;
	/*********************
	Items
	*********************/
	d100 = rand()%100+1;
	if(d100 <= 54)
	{
		cout << "No items" << endl;
	}
	else if((55 <= d100) && (d100 <= 59))
	{
		int d4 = rand()%4+1;
		for(int i=0; i<d4; i++)
		{
			mundaneItem();
		}
	}
	else if((60 <= d100) && (d100 <= 99))
	{
		int d3 = rand()%3+1;
		for(int i=0; i<d3; i++)
		{
			minorItem();
		}
	}
	else
	{
		mediumItem();
	}
}

void Level_7()
{
	int d100 = rand()%100+1;
	int value;
	/*********************
	Coins
	*********************/
	if(d100 <= 11)
	{
		cout << "No coins" << endl;
	}
	else if((12 <= d100) && (d100 <= 18))
	{
		value = rand()%10+1;
		cout << value*10000 << " cp" << endl;
	}
	else if((19 <= d100) && (d100 <= 35))
	{
		value = rand()%12+1;
		cout << value*1000 << " sp" << endl;
	}
	else if((36 <= d100) && (d100 <= 93))
	{
		value = rand()%11+2;
		cout << value*100 << " gp" << endl;
	}
	else
	{
		value = rand()%10+3;
		cout << value*10 << " pp" << endl;
	}
	cout << endl;
	/*********************
	Goods
	*********************/
	d100 = rand()%100+1;
	if(d100 <= 48)
	{
		cout << "No goods" << endl;
	}
	else if((49 <= d100) && (d100 <= 88))
	{
		int d4 = rand()%4+1;
		for(int i=0; i<d4; i++)
		{
			gem();
		}
	}
	else
	{
		int d4 = rand()%4+1;
		for(int i=0; i<d4; i++)
		{
			art();
		}
	}
	cout << endl;
	/*********************
	Items
	*********************/
	d100 = rand()%100+1;
	if(d100 <= 51)
	{
		cout << "No items" << endl;
	}
	else if((52 <= d100) && (d100 <= 97))
	{
		int d3 = rand()%3+1;
		for(int i=0; i<d3; i++)
		{
			minorItem();
		}
	}
	else
	{
		mediumItem();
	}
}

void Level_8()
{
	int d100 = rand()%100+1;
	int value;
	/*********************
	Coins
	*********************/
	if(d100 <= 10)
	{
		cout << "No coins" << endl;
	}
	else if((11 <= d100) && (d100 <= 15))
	{
		value = rand()%12+1;
		cout << value*10000 << " cp" << endl;
	}
	else if((16 <= d100) && (d100 <= 29))
	{
		value = rand()%11+2;
		cout << value*1000 << " sp" << endl;
	}
	else if((30 <= d100) && (d100 <= 87))
	{
		value = rand()%15+2;
		cout << value*100 << " gp" << endl;
	}
	else
	{
		value = rand()%16+3;
		cout << value*10 << " pp" << endl;
	}
	cout << endl;
	/*********************
	Goods
	*********************/
	d100 = rand()%100+1;
	if(d100 <= 45)
	{
		cout << "No goods" << endl;
	}
	else if((46 <= d100) && (d100 <= 85))
	{
		int d6 = rand()%6+1;
		for(int i=0; i<d6; i++)
		{
			gem();
		}
	}
	else
	{
		int d4 = rand()%4+1;
		for(int i=0; i<d4; i++)
		{
			art();
		}
	}
	cout << endl;
	/*********************
	Items
	*********************/
	d100 = rand()%100+1;
	if(d100 <= 48)
	{
		cout << "No items" << endl;
	}
	else if((49 <= d100) && (d100 <= 96))
	{
		int d4 = rand()%4+1;
		for(int i=0; i<d4; i++)
		{
			minorItem();
		}
	}
	else
	{
		mediumItem();
	}
}

void Level_9()
{
	int d100 = rand()%100+1;
	int value;
	/*********************
	Coins
	*********************/
	if(d100 <= 10)
	{
		cout << "No coins" << endl;
	}
	else if((11 <= d100) && (d100 <= 15))
	{
		value = rand()%11+2;
		cout << value*10000 << " cp" << endl;
	}
	else if((16 <= d100) && (d100 <= 29))
	{
		value = rand()%15+2;
		cout << value*1000 << " sp" << endl;
	}
	else if((30 <= d100) && (d100 <= 85))
	{
		value = rand()%16+5;
		cout << value*100 << " gp" << endl;
	}
	else
	{
		value = rand()%11+2;
		cout << value*10 << " pp" << endl;
	}
	cout << endl;
	/*********************
	Goods
	*********************/
	d100 = rand()%100+1;
	if(d100 <= 40)
	{
		cout << "No goods" << endl;
	}
	else if((41 <= d100) && (d100 <= 80))
	{
		int d8 = rand()%8+1;
		for(int i=0; i<d8; i++)
		{
			gem();
		}
	}
	else
	{
		int d4 = rand()%4+1;
		for(int i=0; i<d4; i++)
		{
			art();
		}
	}
	cout << endl;
	/*********************
	Items
	*********************/
	d100 = rand()%100+1;
	if(d100 <= 43)
	{
		cout << "No items" << endl;
	}
	else if((44 <= d100) && (d100 <= 91))
	{
		int d4 = rand()%4+1;
		for(int i=0; i<d4; i++)
		{
			minorItem();
		}
	}
	else
	{
		mediumItem();
	}
}

void Level_10()
{
	int d100 = rand()%100+1;
	int value;
	/*********************
	Coins
	*********************/
	if(d100 <= 10)
	{
		cout << "No coins" << endl;
	}
	else if((11 <= d100) && (d100 <= 24))
	{
		value = rand()%9+2;
		cout << value*1000 << " sp" << endl;
	}
	else if((25 <= d100) && (d100 <= 79))
	{
		value = rand()%19+6;
		cout << value*100 << " gp" << endl;
	}
	else
	{
		value = rand()%26+5;
		cout << value*10 << " pp" << endl;
	}
	cout << endl;
	/*********************
	Goods
	*********************/
	d100 = rand()%100+1;
	if(d100 <= 35)
	{
		cout << "No goods" << endl;
	}
	else if((36 <= d100) && (d100 <= 79))
	{
		int d8 = rand()%8+1;
		for(int i=0; i<d8; i++)
		{
			gem();
		}
	}
	else
	{
		int d6 = rand()%6+1;
		for(int i=0; i<d6; i++)
		{
			art();
		}
	}
	cout << endl;
	/*********************
	Items
	*********************/
	d100 = rand()%100+1;
	if(d100 <= 40)
	{
		cout << "No items" << endl;
	}
	else if((41 <= d100) && (d100 <= 88))
	{
		int d4 = rand()%4+1;
		for(int i=0; i<d4; i++)
		{
			minorItem();
		}
	}
	else if((89 <= d100) && (d100 <= 99))
	{
		mediumItem();
	}
	else
	{
		majorItem();
	}
}

void Level_11()
{
	int d100 = rand()%100+1;
	int value;
	/*********************
	Coins
	*********************/
	if(d100 <= 8)
	{
		cout << "No coins" << endl;
	}
	else if((9 <= d100) && (d100 <= 14))
	{
		value = rand()%28+3;
		cout << value*1000 << " sp" << endl;
	}
	else if((15 <= d100) && (d100 <= 75))
	{
		value = rand()%29+4;
		cout << value*100 << " gp" << endl;
	}
	else
	{
		value = rand()%37+4;
		cout << value*10 << " pp" << endl;
	}
	cout << endl;
	/*********************
	Goods
	*********************/
	d100 = rand()%100+1;
	if(d100 <= 24)
	{
		cout << "No goods" << endl;
	}
	else if((25 <= d100) && (d100 <= 74))
	{
		int d10 = rand()%10+1;
		for(int i=0; i<d10; i++)
		{
			gem();
		}
	}
	else
	{
		int d6 = rand()%6+1;
		for(int i=0; i<d6; i++)
		{
			art();
		}
	}
	cout << endl;
	/*********************
	Items
	*********************/
	d100 = rand()%100+1;
	if(d100 <= 31)
	{
		cout << "No items" << endl;
	}
	else if((32 <= d100) && (d100 <= 84))
	{
		int d4 = rand()%4+1;
		for(int i=0; i<d4; i++)
		{
			minorItem();
		}
	}
	else if((85 <= d100) && (d100 <= 98))
	{
		mediumItem();
	}
	else
	{
		majorItem();
	}
}

void Level_12()
{
	int d100 = rand()%100+1;
	int value;
	/*********************
	Coins
	*********************/
	if(d100 <= 8)
	{
		cout << "No coins" << endl;
	}
	else if((9 <= d100) && (d100 <= 14))
	{
		value = rand()%34+3;
		cout << value*1000 << " sp" << endl;
	}
	else if((15 <= d100) && (d100 <= 75))
	{
		value = rand()%4+1;
		cout << value*1000 << " gp" << endl;
	}
	else
	{
		value = rand()%4+1;
		cout << value*100 << " pp" << endl;
	}
	cout << endl;
	/*********************
	Goods
	*********************/
	d100 = rand()%100+1;
	if(d100 <= 17)
	{
		cout << "No goods" << endl;
	}
	else if((18 <= d100) && (d100 <= 70))
	{
		int d10 = rand()%10+1;
		for(int i=0; i<d10; i++)
		{
			gem();
		}
	}
	else
	{
		int d8 = rand()%8+1;
		for(int i=0; i<d8; i++)
		{
			art();
		}
	}
	cout << endl;
	/*********************
	Items
	*********************/
	d100 = rand()%100+1;
	if(d100 <= 27)
	{
		cout << "No items" << endl;
	}
	else if((28 <= d100) && (d100 <= 82))
	{
		int d6 = rand()%6+1;
		for(int i=0; i<d6; i++)
		{
			minorItem();
		}
	}
	else if((83 <= d100) && (d100 <= 97))
	{
		mediumItem();
	}
	else
	{
		majorItem();
	}
}

void Level_13()
{
	int d100 = rand()%100+1;
	int value;
	/*********************
	Coins
	*********************/
	if(d100 <= 8)
	{
		cout << "No coins" << endl;
	}
	else if((9 <= d100) && (d100 <= 75))
	{
		value = rand()%4+1;
		cout << value*1000 << " gp" << endl;
	}
	else
	{
		value = rand()%10+1;
		cout << value*100 << " pp" << endl;
	}
	cout << endl;
	/*********************
	Goods
	*********************/
	d100 = rand()%100+1;
	if(d100 <= 11)
	{
		cout << "No goods" << endl;
	}
	else if((12 <= d100) && (d100 <= 66))
	{
		int d12 = rand()%12+1;
		for(int i=0; i<d12; i++)
		{
			gem();
		}
	}
	else
	{
		int d10 = rand()%10+1;
		for(int i=0; i<d10; i++)
		{
			art();
		}
	}
	cout << endl;
	/*********************
	Items
	*********************/
	d100 = rand()%100+1;
	if(d100 <= 19)
	{
		cout << "No items" << endl;
	}
	else if((20 <= d100) && (d100 <= 73))
	{
		int d6 = rand()%6+1;
		for(int i=0; i<d6; i++)
		{
			minorItem();
		}
	}
	else if((74 <= d100) && (d100 <= 95))
	{
		mediumItem();
	}
	else
	{
		majorItem();
	}
}

void Level_14()
{
	int d100 = rand()%100+1;
	int value;
	/*********************
	Coins
	*********************/
	if(d100 <= 8)
	{
		cout << "No coins" << endl;
	}
	else if((9 <= d100) && (d100 <= 75))
	{
		value = rand()%6+1;
		cout << value*1000 << " gp" << endl;
	}
	else
	{
		value = rand()%12+1;
		cout << value*100 << " pp" << endl;
	}
	cout << endl;
	/*********************
	Goods
	*********************/
	d100 = rand()%100+1;
	if(d100 <= 11)
	{
		cout << "No goods" << endl;
	}
	else if((12 <= d100) && (d100 <= 66))
	{
		int d12 = rand()%15+2;
		for(int i=0; i<d12; i++)
		{
			gem();
		}
	}
	else
	{
		int d10 = rand()%11+2;
		for(int i=0; i<d10; i++)
		{
			art();
		}
	}
	cout << endl;
	/*********************
	Items
	*********************/
	d100 = rand()%100+1;
	if(d100 <= 19)
	{
		cout << "No items" << endl;
	}
	else if((20 <= d100) && (d100 <= 58))
	{
		int d6 = rand()%6+1;
		for(int i=0; i<d6; i++)
		{
			minorItem();
		}
	}
	else if((59 <= d100) && (d100 <= 92))
	{
		mediumItem();
	}
	else
	{
		majorItem();
	}
}

void Level_15()
{
	int d100 = rand()%100+1;
	int value;
	/*********************
	Coins
	*********************/
	if(d100 <= 3)
	{
		cout << "No coins" << endl;
	}
	else if((4 <= d100) && (d100 <= 74))
	{
		value = rand()%8+1;
		cout << value*1000 << " gp" << endl;
	}
	else
	{
		value = rand()%10+3;
		cout << value*100 << " pp" << endl;
	}
	cout << endl;
	/*********************
	Goods
	*********************/
	d100 = rand()%100+1;
	if(d100 <= 9)
	{
		cout << "No goods" << endl;
	}
	else if((10 <= d100) && (d100 <= 65))
	{
		int d12 = rand()%19+2;
		for(int i=0; i<d12; i++)
		{
			gem();
		}
	}
	else
	{
		int d10 = rand()%15+2;
		for(int i=0; i<d10; i++)
		{
			art();
		}
	}
	cout << endl;
	/*********************
	Items
	*********************/
	d100 = rand()%100+1;
	if(d100 <= 11)
	{
		cout << "No items" << endl;
	}
	else if((12 <= d100) && (d100 <= 46))
	{
		int d6 = rand()%10+1;
		for(int i=0; i<d6; i++)
		{
			minorItem();
		}
	}
	else if((47 <= d100) && (d100 <= 90))
	{
		mediumItem();
	}
	else
	{
		majorItem();
	}
}

void Level_16()
{
	int d100 = rand()%100+1;
	int value;
	/*********************
	Coins
	*********************/
	if(d100 <= 3)
	{
		cout << "No coins" << endl;
	}
	else if((4 <= d100) && (d100 <= 74))
	{
		value = rand()%12+1;
		cout << value*1000 << " gp" << endl;
	}
	else
	{
		value = rand()%10+3;
		cout << value*100 << " pp" << endl;
	}
	cout << endl;
	/*********************
	Goods
	*********************/
	d100 = rand()%100+1;
	if(d100 <= 7)
	{
		cout << "No goods" << endl;
	}
	else if((8 <= d100) && (d100 <= 64))
	{
		int d12 = rand()%21+4;
		for(int i=0; i<d12; i++)
		{
			gem();
		}
	}
	else
	{
		int d10 = rand()%19+2;
		for(int i=0; i<d10; i++)
		{
			art();
		}
	}
	cout << endl;
	/*********************
	Items
	*********************/
	d100 = rand()%100+1;
	if(d100 <= 40)
	{
		cout << "No items" << endl;
	}
	else if((41 <= d100) && (d100 <= 46))
	{
		int d10 = rand()%10+1;
		for(int i=0; i<d10; i++)
		{
			minorItem();
		}
	}
	else if((47 <= d100) && (d100 <= 90))
	{
		int d3 = rand()%3+1;
		for(int i=0; i<d3; i++)
		{
			mediumItem();
		}
	}
	else
	{
		majorItem();
	}
}

void Level_17()
{
	int d100 = rand()%100+1;
	int value;
	/*********************
	Coins
	*********************/
	if(d100 <= 3)
	{
		cout << "No coins" << endl;
	}
	else if((4 <= d100) && (d100 <= 68))
	{
		value = rand()%10+3;
		cout << value*1000 << " gp" << endl;
	}
	else
	{
		value = rand()%19+2;
		cout << value*100 << " pp" << endl;
	}
	cout << endl;
	/*********************
	Goods
	*********************/
	d100 = rand()%100+1;
	if(d100 <= 4)
	{
		cout << "No goods" << endl;
	}
	else if((5 <= d100) && (d100 <= 63))
	{
		int d12 = rand()%29+4;
		for(int i=0; i<d12; i++)
		{
			gem();
		}
	}
	else
	{
		int d10 = rand()%22+3;
		for(int i=0; i<d10; i++)
		{
			art();
		}
	}
	cout << endl;
	/*********************
	Items
	*********************/
	d100 = rand()%100+1;
	if(d100 <= 33)
	{
		cout << "No items" << endl;
	}
	else if((34 <= d100) && (d100 <= 86))
	{
		int d3 = rand()%3+1;
		for(int i=0; i<d3; i++)
		{
			mediumItem();
		}
	}
	else
	{
		majorItem();
	}
}

void Level_18()
{
	int d100 = rand()%100+1;
	int value;
	/*********************
	Coins
	*********************/
	if(d100 <= 2)
	{
		cout << "No coins" << endl;
	}
	else if((3 <= d100) && (d100 <= 65))
	{
		value = rand()%16+3;
		cout << value*1000 << " gp" << endl;
	}
	else
	{
		value = rand()%16+5;
		cout << value*100 << " pp" << endl;
	}
	cout << endl;
	/*********************
	Goods
	*********************/
	d100 = rand()%100+1;
	if(d100 <= 4)
	{
		cout << "No goods" << endl;
	}
	else if((5 <= d100) && (d100 <= 54))
	{
		int d12 = rand()%34+3;
		for(int i=0; i<d12; i++)
		{
			gem();
		}
	}
	else
	{
		int d10 = rand()%28+3;
		for(int i=0; i<d10; i++)
		{
			art();
		}
	}
	cout << endl;
	/*********************
	Items
	*********************/
	d100 = rand()%100+1;
	if(d100 <= 24)
	{
		cout << "No items" << endl;
	}
	else if((25 <= d100) && (d100 <= 80))
	{
		int d4 = rand()%4+1;
		for(int i=0; i<d4; i++)
		{
			mediumItem();
		}
	}
	else
	{
		majorItem();
	}
}

void Level_19()
{
	int d100 = rand()%100+1;
	int value;
	/*********************
	Coins
	*********************/
	if(d100 <= 2)
	{
		cout << "No coins" << endl;
	}
	else if((3 <= d100) && (d100 <= 65))
	{
		value = rand()%22+3;
		cout << value*1000 << " gp" << endl;
	}
	else
	{
		value = rand()%28+3;
		cout << value*100 << " pp" << endl;
	}
	cout << endl;
	/*********************
	Goods
	*********************/
	d100 = rand()%100+1;
	if(d100 <= 3)
	{
		cout << "No goods" << endl;
	}
	else if((4 <= d100) && (d100 <= 50))
	{
		int d12 = rand()%31+6;
		for(int i=0; i<d12; i++)
		{
			gem();
		}
	}
	else
	{
		int d10 = rand()%31+3;
		for(int i=0; i<d10; i++)
		{
			art();
		}
	}
	cout << endl;
	/*********************
	Items
	*********************/
	d100 = rand()%100+1;
	if(d100 <= 4)
	{
		cout << "No items" << endl;
	}
	else if((5 <= d100) && (d100 <= 70))
	{
		int d4 = rand()%4+1;
		for(int i=0; i<d4; i++)
		{
			mediumItem();
		}
	}
	else
	{
		majorItem();
	}
}

void Level_20()
{
	int d100 = rand()%100+1;
	int value;
	/*********************
	Coins
	*********************/
	if(d100 <= 2)
	{
		cout << "No coins" << endl;
	}
	else if((3 <= d100) && (d100 <= 65))
	{
		value = rand()%29+4;
		cout << value*1000 << " gp" << endl;
	}
	else
	{
		value = rand()%37+4;
		cout << value*100 << " pp" << endl;
	}
	cout << endl;
	/*********************
	Goods
	*********************/
	d100 = rand()%100+1;
	if(d100 <= 2)
	{
		cout << "No goods" << endl;
	}
	else if((3 <= d100) && (d100 <= 38))
	{
		int d12 = rand()%37+4;
		for(int i=0; i<d12; i++)
		{
			gem();
		}
	}
	else
	{
		int d10 = rand()%36+7;
		for(int i=0; i<d10; i++)
		{
			art();
		}
	}
	cout << endl;
	/*********************
	Items
	*********************/
	d100 = rand()%100+1;
	if(d100 <= 25)
	{
		cout << "No items" << endl;
	}
	else if((26 <= d100) && (d100 <= 65))
	{
		int d4 = rand()%4+1;
		for(int i=0; i<d4; i++)
		{
			mediumItem();
		}
	}
	else
	{
		int d3 = rand()%3+1;
		for(int i=0; i<d3; i++)
		{
			majorItem();
		}
	}
}

void gem()
{
	int d100, value, value2;
	string gem;
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 25))
	{
		value=rand()%13+4;
		value2=rand()%10+1;
		switch(value2)
		{
			case 1:
				gem="banded, eye, or moss agate";
					break;
			case 2:
				gem="azurite gem";
					break;
			case 3:
				gem="blue quartz crystal";
					break;
			case 4:
				gem="hermatite gem";
					break;
			case 5:
				gem="lapis lazuli gem";
					break;
			case 6:
				gem="malachite gem";
					break;
			case 7:
				gem="obsidian crystal";
					break;
			case 8:
				gem="rhodochrosite gem";
					break;
			case 9:
				gem="tiger eye turquoise gem";
					break;
			case 10:
				gem="freshwater pearl";
		}
		cout << value << " gp " << gem << endl;
	}
	else if((26 <= d100) && (d100 <= 50))
	{
		value=(rand()%7+2)*10;
		value2=rand()%13+1;
		switch(value2)
		{
			case 1:
				gem="bloodstone";
					break;
			case 2:
				gem="carnelian gem";
					break;
			case 3:
				gem="chalcedony gem";
					break;
			case 4:
				gem="chrysoprase gem";
					break;
			case 5:
				gem="citrine gem";
					break;
			case 6:
				gem="jasper iolite gem";
					break;
			case 7:
				gem="moonstone";
					break;
			case 8:
				gem="onyx gem";
					break;
			case 9:
				gem="peridot gem";
					break;
			case 10:
				gem="rock crystal (clear quartz)";
					break;
			case 11:
				gem="sardonyx gem";
					break;
			case 12:
				gem="rose, smoky, or star rose quartz";
					break;
			case 13:
				gem="zircon gem";
		}
		cout << value << " gp " << gem << endl;
	}
	else if((51 <= d100) && (d100 <= 70))
	{
		value=(rand()%13+4)*10;
		value2=rand()%11+1;
		switch(value2)
		{
			case 1:
				gem="amber crystal";
					break;
			case 2:
				gem="amythyst";
					break;
			case 3:
				gem="chrysoberyl";
					break;
			case 4:
				gem="coral gem";
					break;
			case 5:
				gem="red or brown-green garnet";
					break;
			case 6:
				gem="piece of jade";
					break;
			case 7:
				gem="jet crystal";
					break;
			case 8:
				gem="white, golden, pink or silver pearl";
					break;
			case 9:
				gem="red spinel";
					break;
			case 10:
				gem="red-brown or deep green spinel";
					break;
			case 11:
				gem="tourmaline";
		}
		cout << value << " gp " << gem << endl;
	}
	else if((71 <= d100) && (d100 <= 90))
	{
		value=(rand()%7+2)*1000;
		value2=rand()%6+1;
		switch(value2)
		{
			case 1:
				gem="alexandrite gem";
					break;
			case 2:
				gem="aquamarine gem";
					break;
			case 3:
				gem="violet garnet";
					break;
			case 4:
				gem="black pearl";
					break;
			case 5:
				gem="deep blue spinel";
					break;
			case 6:
				gem="golden yellow topaz";
					
		}
		cout << value << " gp " << gem << endl;
	}
	else if((91 <= d100) && (d100 <= 99))
	{
		value=(rand()%13+4)*100;
		value2=rand()%6+1;
		switch(value2)
		{
			case 1:
				gem="emerald";
					break;
			case 2:
				gem="white, black or fire opal";
					break;
			case 3:
				gem="blue sapphire";
					break;
			case 4:
				gem="fiery yellow or rich purple corundum gem";
					break;
			case 5:
				gem="blue or black star sapphire";
					break;
			case 6:
				gem="star ruby";
					
		}
		cout << value << " gp " << gem << endl;
	}
	else
	{
		value=(rand()%7+2)*1000;
		value2=rand()%6+1;
		switch(value2)
		{
			case 1:
				gem="flawless bright green emerald";
					break;
			case 2:
				gem="blue white diamond";
					break;
			case 3:
				gem="pink diamond";
					break;
			case 4:
				gem="blue diamond";
					break;
			case 5:
				gem="king's tears gem";
					break;
			case 6:
				gem="rogue stone";
					
		}
		cout << value << " gp " << gem << endl;
	}
}

void art()
{
	int d100, value;
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 10))
	{
		value=(rand()%10+1)*10;
		cout << value << " gp art object (silver ewer; carved bone or ivory statuette; finely wrought small gold bracelet)" << endl;
	}
	else if((11 <= d100) && (d100 <= 25))
	{
		value=(rand()%16+3)*10;
		cout << value << " gp art object (cloth of gold vestments; black velvet mask w/ citrines; silver chalice with gems)" << endl;
	}
	else if((26 <= d100) && (d100 <= 40))
	{
		value=(rand()%6+1)*100;
		cout << value << " gp art object (large well-done wool tapestry; brass mug with jade inlays)" << endl;
	}
	else if((41 <= d100) && (d100 <= 50))
	{
		value=(rand()%10+1)*100;
		cout << value << " gp art object (silver comb w/ gems, silver plated ceremonial weapon with jewelled hilt)" << endl;
	}
	else if((51 <= d100) && (d100 <= 60))
	{
		value=(rand()%11+2)*100;
		cout << value << " gp art object (carved harp of exotic wood with ivory inlay and gems; solid gold idol (10 lb.))" << endl;
	}
	else if((61 <= d100) && (d100 <= 70))
	{
		value=(rand()%16+3)*100;
		cout << value << " gp art object (gold dragon comb with red garnet eye; gold and topaz bottle cork; ceremonial electrum dagger with star ruby in the pommel)" << endl;
	}
	else if((71 <= d100) && (d100 <= 80))
	{
		value=(rand()%21+4)*100;
		cout << value << " gp art object (eyepatch with mock eye of sapphire and moonstone; fire opal pendant on a fine gold chain; old masterpiece painting)" << endl;
	}
	else if((81 <= d100) && (d100 <= 85))
	{
		value=(rand()%26+5)*100;
		cout << value << " gp art object (embroidered silk and velvet mantle with numerous gems; saphhire pendant on gold chain)" << endl;
	}
	else if((86 <= d100) && (d100 <= 90))
	{
		value=(rand()%4+1)*1000;
		cout << value << " gp art object (embroidered and bejeweled glove; jeweled anklet; gold music box)" << endl;
	}
	else if((91 <= d100) && (d100 <= 95))
	{
		value=(rand()%6+1)*1000;
		cout << value << " gp art object (golden circlet with aquamarines; pink pearl necklace)" << endl;
	}
	else if((95 <= d100) && (d100 <= 99))
	{
		value=(rand()%7+2)*1000;
		cout << value << " gp art object (jeweled gold crown; jeweled electrum ring)" << endl;
	}
	else
	{
		value=(rand()%11+2)*1000;
		cout << value << " gp art object (gold and ruby ring; rogue stone earring; gold cup set with emeralds)" << endl;
	}
	cout << endl;
}

void mundaneItem()
{
	int d100;
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 17))
	{
		d100=rand()%100+1;
		if((1 <= d100) && (d100 <= 12))
		{
			cout << "1d4 Alchemist's fire flasks (20 gp each)" << endl;
		}
		else if((13 <= d100) && (d100 <= 24))
		{
			cout << "2d4 Acid flasks (10 gp each)" << endl;
		}
		else if((25 <= d100) && (d100 <= 36))
		{
			cout << "1d4 Smokesticks (20 gp each)" << endl;
		}
		else if((37 <= d100) && (d100 <= 48))
		{
			cout << "1d4 Holy water flasks (25 gp each)" << endl;
		}
		else if((49 <= d100) && (d100 <= 62))
		{
			cout << "1d4 Antitoxin doses (50 gp each)" << endl;
		}
		else if((63 <= d100) && (d100 <= 74))
		{
			cout << "Everburning torch" << endl;
		}
		else if((75 <= d100) && (d100 <= 88))
		{
			cout << "1d4 Tanglefoot bags (50 gp each)" << endl;
		}
		else
		{
			cout << "1d4 Thunderstones (30 gp each)" << endl;
		}
	}
	else if((18 <= d100) && (d100 <= 50))
	{
		mundaneArmor();
	}
	else if((51 <= d100) && (d100 <= 83))
	{
		randomWeapon();
	}
	else
	{
		d100=rand()%100+1;
		if((1 <= d100) && (d100 <= 3))
		{
			cout << "Empty backpack (2 gp)" << endl;
		}
		else if((4 <= d100) && (d100 <= 6))
		{
			cout << "Crowbar (2 gp)" << endl;
		}
		else if((7 <= d100) && (d100 <= 11))
		{
			cout << "Bullseye lantern (12 gp)" << endl;
		}
		else if((12 <= d100) && (d100 <= 16))
		{
			cout << "Simple Lock (20 gp)" << endl;
		}
		else if((17 <= d100) && (d100 <= 21))
		{
			cout << "Average Lock (40 gp)" << endl;
		}
		else if((22 <= d100) && (d100 <= 28))
		{
			cout << "Good Lock (80 gp)" << endl;
		}
		else if((29 <= d100) && (d100 <= 35))
		{
			cout << "Superior Lock (150 gp)" << endl;
		}
		else if((36 <= d100) && (d100 <= 40))
		{
			cout << "Masterwork manacles (50 gp)" << endl;
		}
		else if((41 <= d100) && (d100 <= 43))
		{
			cout << "Small steel mirror (10 gp)" << endl;
		}
		else if((44 <= d100) && (d100 <= 46))
		{
			cout << "Silk rope (50 ft.)(10 gp)" << endl;
		}
		else if((47 <= d100) && (d100 <= 53))
		{
			cout << "Spyglass (1,000 gp)" << endl;
		}
		else if((54 <= d100) && (d100 <= 58))
		{
			cout << "Masterwork Artisan's tools" << endl;
		}
		else if((59 <= d100) && (d100 <= 63))
		{
			cout << "Climber's kit (80 gp)" << endl;
		}
		else if((64 <= d100) && (d100 <= 68))
		{
			cout << "Disguise kit (50 gp)" << endl;
		}
		else if((69 <= d100) && (d100 <= 73))
		{
			cout << "Healer's kit (50 gp)" << endl;
		}
		else if((74 <= d100) && (d100 <= 77))
		{
			cout << "Silver Holy symbol (25 gp)" << endl;
		}
		else if((78 <= d100) && (d100 <= 81))
		{
			cout << "Hourglass (25 gp)" << endl;
		}
		else if((82 <= d100) && (d100 <= 88))
		{
			cout << "Magnifying glass (100 gp)" << endl;
		}
		else if((89 <= d100) && (d100 <= 96))
		{
			cout << "Masterwork musical instrument (100 gp)" << endl;
		}
		else
		{
			cout << "Masterwork thieves' tools (50 gp)" << endl;
		}
	}
}

void minorItem()
{
	int d100;
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 4))
	{
		minorArmor();
	}
	else if((5 <= d100) && (d100 <= 9))
	{
		minorWeapon();
	}
	else if((10 <= d100) && (d100 <= 44))
	{
		minorPotion();
	}
	else if((45 <= d100) && (d100 <= 46))
	{
		minorRing();
	}
	else if((47 <= d100) && (d100 <= 81))
	{
		d100=rand()%100+1;
		if((1 <= d100) && (d100 <= 70))
			minorAScroll();
		else
			minorDScroll();
	}
	else if((82 <= d100) && (d100 <= 91))
	{
		minorWand();
	}
	else
	{
		minorWondrousItem();
	}
}
void mediumItem()
{
	int d100;
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 10))
	{
		mediumArmor();
	}
	else if((11 <= d100) && (d100 <= 20))
	{
		mediumWeapon();
	}
	else if((21 <= d100) && (d100 <= 30))
	{
		mediumPotion();
	}
	else if((31 <= d100) && (d100 <= 40))
	{
		mediumRing();
	}
	else if((41 <= d100) && (d100 <= 50))
	{
		mediumRod();
	}
	else if((51 <= d100) && (d100 <= 65))
	{
		d100=rand()%100+1;
		if((1 <= d100) && (d100 <= 70))
			mediumAScroll();
		else
			mediumDScroll();
	}
	else if((66 <= d100) && (d100 <= 68))
	{
		mediumStaff();
	}
	else if((69 <= d100) && (d100 <= 83))
	{
		mediumWand();
	}
	else
	{
		mediumWondrousItem();
	}
}
void majorItem()
{
	int d100;
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 10))
	{
		majorArmor();
	}
	else if((11 <= d100) && (d100 <= 20))
	{
		majorWeapon();
	}
	else if((21 <= d100) && (d100 <= 25))
	{
		majorPotion();
	}
	else if((26 <= d100) && (d100 <= 35))
	{
		majorRing();
	}
	else if((36 <= d100) && (d100 <= 45))
	{
		majorRod();
	}
	else if((46 <= d100) && (d100 <= 55))
	{
		d100=rand()%100+1;
		if((1 <= d100) && (d100 <= 70))
			majorAScroll();
		else
			majorDScroll();
	}
	else if((56 <= d100) && (d100 <= 75))
	{
		majorStaff();
	}
	else if((76 <= d100) && (d100 <= 80))
	{
		majorWand();
	}
	else
	{
		majorWondrousItem();
	}
}

void mundaneArmor()
{
	int d100;
	d100=rand()%100+1;
	if(d100 <= 40) //Armor
	{
		d100=rand()%100+1;
		if((1 <= d100) && (d100 <= 3))
		{
			d100=rand()%100+1;
			if(d100 <= 70)
				cout << "Padded Armor" << endl;
			else
				cout << "Masterwork Padded Armor" << endl;
		}
		else if((4 <= d100) && (d100 <= 10))
		{
			d100=rand()%100+1;
			if(d100 <= 70)
				cout << "Leather Armor" << endl;
			else
				cout << "Masterwork Leather Armor" << endl;
		}
		else if((11 <= d100) && (d100 <= 20))
		{
			d100=rand()%100+1;
			if(d100 <= 70)
				cout << "Studded Leather Armor" << endl;
			else
				cout << "Masterwork Studded Leather Armor" << endl;
		}
		else if((21 <= d100) && (d100 <= 32))
		{
			d100=rand()%100+1;
			if(d100 <= 70)
				cout << "Chain Shirt" << endl;
			else
				cout << "Masterwork Chain Shirt" << endl;
		}
		else if((33 <= d100) && (d100 <= 38))
		{
			d100=rand()%100+1;
			if(d100 <= 70)
				cout << "Hide Armor" << endl;
			else
				cout << "Masterwork Hide Armor" << endl;
		}
		else if((39 <= d100) && (d100 <= 45))
		{
			d100=rand()%100+1;
			if(d100 <= 70)
				cout << "Scale Mail Armor" << endl;
			else
				cout << "Masterwork Scale Mail Armor" << endl;
		}
		else if((46 <= d100) && (d100 <= 50))
		{
			d100=rand()%100+1;
			if(d100 <= 70)
				cout << "Chainmail Armor" << endl;
			else
				cout << "Masterwork Chainmail Armor" << endl;
		}
		else if((51 <= d100) && (d100 <= 65))
		{
			d100=rand()%100+1;
			if(d100 <= 70)
				cout << "Breastplate" << endl;
			else
				cout << "Masterwork Breastplate" << endl;
		}
		else if((66 <= d100) && (d100 <= 70))
		{
			d100=rand()%100+1;
			if(d100 <= 70)
				cout << "Banded Mail Armor" << endl;
			else
				cout << "Masterwork Banded Mail Armor" << endl;
		}
		else if((71 <= d100) && (d100 <= 75))
		{
			d100=rand()%100+1;
			if(d100 <= 70)
				cout << "Half-Plate Armor" << endl;
			else
				cout << "Masterwork Half-Plate Armor" << endl;
		}
		else
		{
			d100=rand()%100+1;
			if(d100 <= 70)
				cout << "Plate Mail Armor" << endl;
			else
				cout << "Masterwork Plate Mail Armor" << endl;
		}
	}
	else //Shields
	{
		d100=rand()%100+1;
		if((1 <= d100) && (d100 <= 10))
		{
			d100=rand()%100+1;
			if(d100 <= 70)
				cout << "Buckler" << endl;
			else
				cout << "Masterwork Buckler" << endl;
		}
		else if((11 <= d100) && (d100 <= 15))
		{
			d100=rand()%100+1;
			if(d100 <= 70)
				cout << "Light Wooden Shield" << endl;
			else
				cout << "Masterwork Light Wooden Shield" << endl;
		}
		else if((16 <= d100) && (d100 <= 25))
		{
			d100=rand()%100+1;
			if(d100 <= 70)
				cout << "Light Steel Shield" << endl;
			else
				cout << "Masterwork Light Steel Shield" << endl;
		}
		else if((26 <= d100) && (d100 <= 40))
		{
			d100=rand()%100+1;
			if(d100 <= 70)
				cout << "Heavy Wooden Shield" << endl;
			else
				cout << "Masterwork Heavy Wooden Shield" << endl;
		}
		else if((41 <= d100) && (d100 <= 90))
		{
			d100=rand()%100+1;
			if(d100 <= 70)
				cout << "Heavy Steel Shield" << endl;
			else
				cout << "Masterwork Heavy Shield" << endl;
		}
		else
		{
			d100=rand()%100+1;
			if(d100 <= 70)
				cout << "Tower Shield" << endl;
			else
				cout << "Masterwork Tower Shield" << endl;
		}
	}
}

string randomArmor()
{
	int d100;
	string item;
	d100=rand()%100+1;
	if(1 == d100)
	{
		return item = "Padded Armor";
	}
	else if((2 <= d100) && (d100 <= 7))
	{
		return item = "Leather Armor";
	}
	else if((8 <= d100) && (d100 <= 17))
	{
		return item = "Studded Leather Armor";
	}
	else if((18 <= d100) && (d100 <= 32))
	{
		return item = "Chain Shirt";
	}
	else if((33 <= d100) && (d100 <= 42))
	{
		return item = "Hide Armor";
	}
	else if((43 <= d100) && (d100 <= 45))
	{
		return item = "Scale Mail";
	}
	else if((46 <= d100) && (d100 <= 50))
	{
		return item = "Chainmail";
	}
	else if((51 <= d100) && (d100 <= 57))
	{
		return item = "Breastplate";
	}
	else if((58 <= d100) && (d100 <= 60))
	{
		return item = "Splint Mail Armor";
	}
	else if((61 <= d100) && (d100 <= 65))
	{
		return item = "Banded Mail Armor";
	}
	else if((66 <= d100) && (d100 <= 70))
	{
		return item = "Half-Plate Armor";
	}
	else
	{
		return item = "Full Plate";
	}
}

string randomShield()
{
	int d100;
	string item;
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 10))
	{
		return item = "Buckler";
	}
	else if((11 <= d100) && (d100 <= 15))
	{
		return item = "Light Wooden Shield";
	}
	else if((16 <= d100) && (d100 <= 20))
	{
		return item = "Light Steel Shield";
	}
	else if((21 <= d100) && (d100 <= 30))
	{
		return item = "Heavy Wooden Shield";
	}
	else if((31 <= d100) && (d100 <= 90))
	{
		return item = "Heavy Steel Shield";
	}
	else
	{
		return item = "Tower Shield";
	}
}

void minorArmor()
{
	int d100, bonus, shieldSwitch=0;
	string item, ability;
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 60))
	{
		item = randomShield();
		cout << "+1 " << item << endl;
	}
	else if((61 <= d100) && (d100 <= 80))
	{
		item = randomArmor();
		cout << "+1 " << item << endl;
	}
	else if((81 <= d100) && (d100 <= 85))
	{
		item = randomShield();
		cout << "+2 " << item << endl;
	}
	else if((86 <= d100) && (d100 <= 87))
	{
		item = randomArmor();
		cout << "+2 " << item << endl;
	}
	else if((88 <= d100) && (d100 <= 89))
	{
		minorSpecificArmor();
	}
	else if((90 <= d100) && (d100 <= 91))
	{
		minorSpecificShield();
	}
	else
	{
		d100=rand()%87+1;
		while(d100 <= 87)
		{
			if((1 <= d100) && (d100 <= 60))
			{
				item = randomShield();
				cout << "+1 " << item;
				bonus=1;
				shieldSwitch=1;
			}
			else if((61 <= d100) && (d100 <= 80))
			{
				item = randomArmor();
				cout << "+1 " << item;
				bonus=1;
			}
			else if((81 <= d100) && (d100 <= 85))
			{
				item = randomShield();
				cout << "+2 " << item;
				bonus=2;
				shieldSwitch=1;
			}
			else if((86 <= d100) && (d100 <= 87))
			{
				item = randomArmor();
				cout << "+2 " << item;
				bonus=2;
			}
		}	
		if(shieldSwitch == 0)
		{
			ability = minorArmorAbility(bonus);
		}
		else
		{
			ability = minorShieldAbility(bonus);
		}
		cout << " of " << ability << endl;
	}
}
void mediumArmor()
{
	int d100, bonus, shieldSwitch=0;
	string item, ability;
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 5))
	{
		item = randomShield();
		cout << "+1 " << item << endl;
	}
	else if((6 <= d100) && (d100 <= 10))
	{
		item = randomArmor();
		cout << "+1 " << item << endl;
	}
	else if((11 <= d100) && (d100 <= 20))
	{
		item = randomShield();
		cout << "+2 " << item << endl;
	}
	else if((21 <= d100) && (d100 <= 30))
	{
		item = randomArmor();
		cout << "+2 " << item << endl;
	}
	else if((31 <= d100) && (d100 <= 40))
	{
		item = randomShield();
		cout << "+3 " << item << endl;
	}
	else if((41 <= d100) && (d100 <= 50))
	{
		item = randomArmor();
		cout << "+3 " << item << endl;
	}
	else if((51 <= d100) && (d100 <= 55))
	{
		item = randomShield();
		cout << "+4 " << item << endl;
	}
	else if((56 <= d100) && (d100 <= 57))
	{
		item = randomArmor();
		cout << "+4 " << item << endl;
	}
	else if((58 <= d100) && (d100 <= 60))
	{
		mediumSpecificArmor();
	}
	else if((61 <= d100) && (d100 <= 63))
	{
		mediumSpecificShield();
	}
	else//abilities
	{
		d100=rand()%57+1;
		if((1 <= d100) && (d100 <= 5))
		{
			item = randomShield();
			cout << "+1 " << item;
			bonus=1;
			shieldSwitch=1;
		}
		else if((6 <= d100) && (d100 <= 10))
		{
			item = randomArmor();
			cout << "+1 " << item;
			bonus=1;
		}
		else if((11 <= d100) && (d100 <= 20))
		{
			item = randomShield();
			cout << "+2 " << item;
			bonus=2;
			shieldSwitch=1;
		}
		else if((21 <= d100) && (d100 <= 30))
		{
			item = randomArmor();
			cout << "+2 " << item;
			bonus=2;
		}
		else if((31 <= d100) && (d100 <= 40))
		{
			item = randomShield();
			cout << "+3 " << item;
			bonus=3;
			shieldSwitch=1;
		}
		else if((41 <= d100) && (d100 <= 50))
		{
			item = randomArmor();
			cout << "+3 " << item;
			bonus=3;
		}
		else if((51 <= d100) && (d100 <= 55))
		{
			item = randomShield();
			cout << "+4 " << item;
			bonus=4;
			shieldSwitch=1;
		}
		else if((56 <= d100) && (d100 <= 57))
		{
			item = randomArmor();
			cout << "+4 " << item;
			bonus=4;
		}
		if(shieldSwitch == 0)
		{
			ability = mediumArmorAbility(bonus);
		}
		else
		{
			ability = mediumShieldAbility(bonus);
		}
		cout << " of " << ability << endl;
	}
}
void majorArmor()
{
	int d100, bonus, shieldSwitch=0;
	string item, ability;
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 8))
	{
		item = randomShield();
		cout << "+3 " << item << endl;
	}
	else if((9 <= d100) && (d100 <= 16))
	{
		item = randomArmor();
		cout << "+3 " << item << endl;
	}
	else if((17 <= d100) && (d100 <= 27))
	{
		item = randomShield();
		cout << "+4 " << item << endl;
	}
	else if((28 <= d100) && (d100 <= 38))
	{
		item = randomArmor();
		cout << "+4 " << item << endl;
	}
	else if((39 <= d100) && (d100 <= 49))
	{
		item = randomShield();
		cout << "+5 " << item << endl;
	}
	else if((50 <= d100) && (d100 <= 57))
	{
		item = randomArmor();
		cout << "+5 " << item << endl;
	}
	else if((58 <= d100) && (d100 <= 60))
	{
		majorSpecificArmor();
	}
	else if((61 <= d100) && (d100 <= 63))
	{
		majorSpecificShield();
	}
	else//abilities
	{
		d100=rand()%57+1;
		if((1 <= d100) && (d100 <= 8))
		{
			item = randomShield();
			cout << "+3 " << item;
			bonus=3;
			shieldSwitch=1;
		}
		else if((9 <= d100) && (d100 <= 16))
		{
			item = randomArmor();
			cout << "+3 " << item;
			bonus=3;
		}
		else if((17 <= d100) && (d100 <= 27))
		{
			item = randomShield();
			cout << "+4 " << item;
			bonus=4;
			shieldSwitch=1;
		}
		else if((28 <= d100) && (d100 <= 38))
		{
			item = randomArmor();
			cout << "+4 " << item;
			bonus=4;
		}
		else if((39 <= d100) && (d100 <= 49))
		{
			item = randomShield();
			cout << "+5 " << item;
			bonus=5;
			shieldSwitch=1;
		}
		else if((50 <= d100) && (d100 <= 57))
		{
			item = randomArmor();
			cout << "+5 " << item;
			bonus=5;
		}
		if(shieldSwitch == 0)
		{
			ability = majorArmorAbility(bonus);
		}
		else
		{
			ability = majorShieldAbility(bonus);
		}
		cout << " of " << ability << endl;
	}
}
void minorSpecificArmor()
{
	int d100;
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 50))
	{
		cout << "Mithral Shirt (Specific Armor)" << endl;
	}
	else if((51 <= d100) && (d100 <= 80))
	{
		cout << "Dragonhide Plate (Specific Armor)" << endl;
	}
	else
	{
		cout << "Elven Chain (Specific Armor)" << endl;
	}
}
void mediumSpecificArmor()
{
	int d100;
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 25))
	{
		cout << "Mithral Shirt (Specific Armor)" << endl;
	}
	else if((26 <= d100) && (d100 <= 45))
	{
		cout << "Dragonhide Plate (Specific Armor)" << endl;
	}
	else if((46 <= d100) && (d100 <= 57))
	{
		cout << "Elven Chain (Specific Armor)" << endl;
	}
	else if((58 <= d100) && (d100 <= 67))
	{
		cout << "Rhino Hide (Specific Armor)" << endl;
	}
	else if((68 <= d100) && (d100 <= 82))
	{
		cout << "Adamantine Breastplate (Specific Armor)" << endl;
	}
	else if((83 <= d100) && (d100 <= 97))
	{
		cout << "Dwarven Plate (Specific Armor)" << endl;
	}
	else
	{
		cout << "Banded Mail of Luck (Specific Armor)" << endl;
	}
}
void majorSpecificArmor()
{
	int d100;
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 10))
	{
		cout << "Adamantine Breastplate (Specific Armor)" << endl;
	}
	else if((11 <= d100) && (d100 <= 20))
	{
		cout << "Dwarven Plate (Specific Armor)" << endl;
	}
	else if((21 <= d100) && (d100 <= 32))
	{
		cout << "Banded Mail of Luck (Specific Armor)" << endl;
	}
	else if((33 <= d100) && (d100 <= 50))
	{
		cout << "Celestial Armor (Specific Armor)" << endl;
	}
	else if((51 <= d100) && (d100 <= 60))
	{
		cout << "Plate Armor of the Deep (Specific Armor)" << endl;
	}
	else if((61 <= d100) && (d100 <= 75))
	{
		cout << "Breastplate of Command (Specific Armor)" << endl;
	}
	else if((76 <= d100) && (d100 <= 90))
	{
		cout << "Mithral Full Plate of Speed (Specific Armor)" << endl;
	}
	else
	{
		cout << "Demon Armor (Specific Armor)" << endl;
	}
}
void minorSpecificShield()
{
	int d100;
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 30))
	{
		cout << "Darkwood Buckler (Specific Shield)" << endl;
	}
	else if((31 <= d100) && (d100 <= 80))
	{
		cout << "Darkwood Shield (Specific Shield)" << endl;
	}
	else if((81 <= d100) && (d100 <= 95))
	{
		cout << "Mithral Heavy Shield (Specific Shield)" << endl;
	}
	else
	{
		cout << "Caster's Shield (Specific Shield)" << endl;
	}
}
void mediumSpecificShield()
{
	int d100;
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 20))
	{
		cout << "Darkwood Buckler (Specific Shield)" << endl;
	}
	else if((21 <= d100) && (d100 <= 45))
	{
		cout << "Darkwood Shield (Specific Shield)" << endl;
	}
	else if((46 <= d100) && (d100 <= 70))
	{
		cout << "Mithral Heavy Shield (Specific Shield)" << endl;
	}
	else if((71 <= d100) && (d100 <= 85))
	{
		cout << "Caster's Shield (Specific Shield)" << endl;
	}
	else if((86 <= d100) && (d100 <= 90))
	{
		cout << "Spined Shield (Specific Shield)" << endl;
	}
	else if((91 <= d100) && (d100 <= 95))
	{
		cout << "Lion's Shield (Specific Shield)" << endl;
	}
	else
	{
		cout << "Winged Shield (Specific Shield)" << endl;
	}
}
void majorSpecificShield()
{
	int d100;
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 20))
	{
		cout << "Caster's Shield (Specific Shield)" << endl;
	}
	else if((21 <= d100) && (d100 <= 40))
	{
		cout << "Spined Shield (Specific Shield)" << endl;
	}
	else if((41 <= d100) && (d100 <= 60))
	{
		cout << "Lion's Shield (Specific Shield)" << endl;
	}
	else if((61 <= d100) && (d100 <= 90))
	{
		cout << "Winged Shield (Specific Shield)" << endl;
	}
	else
	{
		cout << "Absorbing Shield (Specific Shield)" << endl;
	}
}
string minorArmorAbility(int bonus)
{
	int d100;
	string ability;
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 25))
	{
		return "Glamer";
	}
	else if((26 <= d100) && (d100 <= 32))
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			return "Light Fortification";	
		}
		else
			return "";
	}
	else if((33 <= d100) && (d100 <= 52))
	{
		return "Slickness";
	}
	else if((53 <= d100) && (d100 <= 72))
	{
		return "Shadow";
	}
	else if((73 <= d100) && (d100 <= 92))
	{
		return "Silent Moves";
	}
	else if((93 <= d100) && (d100 <= 96))
	{
		if((bonus+2) <= 10)
		{
			bonus+=2;
			return "Spell Resistance (13)";
		}
		else
			return "";
	}
	else if(d100 == 97)
	{
		return "Improved Slickness";
	}
	else if(d100 == 98)
	{
		return "Improved Shadow";
	}
	else if(d100 == 99)
	{
		return "Improved Silent Moves";
	}
	else
	{
		string ability2 = minorArmorAbility(bonus);
		return ability + ", " + ability2;
	}
}
string mediumArmorAbility(int bonus)
{
	int d100;
	string ability;
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 5))
	{
		return "Glamer";
	}
	else if((6 <= d100) && (d100 <= 8))
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			return "Light Fortification";	
		}
		else
			return "";
	}
	else if((9 <= d100) && (d100 <= 11))
	{
		return "Slickness";
	}
	else if((12 <= d100) && (d100 <= 14))
	{
		return "Shadow";
	}
	else if((15 <= d100) && (d100 <= 17))
	{
		return "Silent Moves";
	}
	else if((18 <= d100) && (d100 <= 19))
	{
		if((bonus+2) <= 10)
		{
			bonus+=2;
			return "Spell Resistance (13)";
		}
		else
			return "";;
	}
	else if((20 <= d100) && (d100 <= 29))
	{
		return "Improved Slickness";
	}
	else if((30 <= d100) && (d100 <= 39))
	{
		return "Improved Shadow";
	}
	
	else if((40 <= d100) && (d100 <= 49))
	{
		return "Improved Silent Moves";
	}
	else if((50 <= d100) && (d100 <= 54))
	{
		return "Acid Resistance";
	}
	else if((55 <= d100) && (d100 <= 59))
	{
		return "Cold Resistance";
	}
	else if((60 <= d100) && (d100 <= 64))
	{
		return "Electricity Resistance";
	}
	else if((65 <= d100) && (d100 <= 69))
	{
		return "Fire Resistance";
	}
	else if((70 <= d100) && (d100 <= 74))
	{
		return "Sonic Resistance";
	}
	else if((75 <= d100) && (d100 <= 79))
	{
		if((bonus+3) <= 10)
		{
			bonus+=3;
			return "Ghost Touch";
		}
		else
			return "";
	}
	else if((80 <= d100) && (d100 <= 84))
	{
		if((bonus+3) <= 10)
		{
			bonus+=3;
			return "Invulnerability";
		}
		else
			return "";
	}
	else if((85 <= d100) && (d100 <= 89))
	{
		if((bonus+3) <= 10)
		{
			bonus+=3;
			return "Moderate Fortification";
		}
		else
			return "";
	}
	else if((90 <= d100) && (d100 <= 94))
	{
		if((bonus+3) <= 10)
		{
			bonus+=3;
			return "Spell Resistance (15)";
		}
		else
			return "";
	}
	else if((95 <= d100) && (d100 <= 99))
	{
		if((bonus+3) <= 10)
		{
			bonus+=3;
			return "the Wild";
		}
		else
			return "";
	}
	else
	{
		string ability2 = mediumArmorAbility(bonus);
		return ability + ", " + ability2;
	}
}
string majorArmorAbility(int bonus)
{
	int d100;
	string ability;
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 3))
	{
		return "Glamer";
	}
	else if(d100 == 4)
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			return "Light Fortification";	
		}
		else
			return "";
	}
	else if((5 <= d100) && (d100 <= 7))
	{
		return "Improved Slickness";
	}
	else if((8 <= d100) && (d100 <= 10))
	{
		return "Improved Shadow";
	}
	
	else if((11 <= d100) && (d100 <= 13))
	{
		return "Improved Silent Moves";
	}
	else if((14 <= d100) && (d100 <= 16))
	{
		return "Acid Resistance";
	}
	else if((17 <= d100) && (d100 <= 19))
	{
		return "Cold Resistance";
	}
	else if((20 <= d100) && (d100 <= 22))
	{
		return "Electricity Resistance";
	}
	else if((23 <= d100) && (d100 <= 25))
	{
		return "Fire Resistance";
	}
	else if((26 <= d100) && (d100 <= 28))
	{
		return "Sonic Resistance";
	}
	else if((29 <= d100) && (d100 <= 33))
	{
		if((bonus+3) <= 10)
		{
			bonus+=3;
			return "Ghost Touch";
		}
		else
			return "";
	}
	else if((34 <= d100) && (d100 <= 35))
	{
		if((bonus+3) <= 10)
		{
			bonus+=3;
			return "Invulnerability";
		}
		else
			return "";
	}
	else if((36 <= d100) && (d100 <= 40))
	{
		if((bonus+3) <= 10)
		{
			bonus+=3;
			return "Moderate Fortification";
		}
		else
			return "";
	}
	else if((41 <= d100) && (d100 <= 42))
	{
		if((bonus+3) <= 10)
		{
			bonus+=3;
			return "Spell Resistance (15)";
		}
		else
			return "";
	}
	else if(d100 == 43)
	{
		if((bonus+3) <= 10)
		{
			bonus+=3;
			return "the Wild";
		}
		else
			return "";
	}
	else if((44 <= d100) && (d100 <= 48))
	{
		return "Greater Slickness";
	}
	else if((49 <= d100) && (d100 <= 53))
	{
		return "Greater Shadow";
	}
	else if((54 <= d100) && (d100 <= 58))
	{
		return "Greater Silent Moves";
	}
	else if((59 <= d100) && (d100 <= 63))
	{
		return "Improved Acid Resistance";
	}
	else if((64 <= d100) && (d100 <= 68))
	{
		return "Improved Cold Resistance";
	}
	else if((69 <= d100) && (d100 <= 73))
	{
		return "Improved Electricity Resistance";
	}
	else if((74 <= d100) && (d100 <= 79))
	{
		return "Improved Fire Resistance";
	}
	else if((80 <= d100) && (d100 <= 83))
	{
		return "Improved Sonic Resistance";
	}
	else if((84 <= d100) && (d100 <= 88))
	{
		if((bonus+4) <= 10)
		{
			bonus+=4;
			return "Spell Resistance (17)";
		}
		else
			return "";
	}
	else if(d100 == 89)
	{
		return "Etherealness";
	}
	else if(d100 == 90)
	{
		return "Undead Controlling";
	}
	else if((91 <= d100) && (d100 <= 92))
	{
		return "Heavy Fortification";
	}
	else if((93 <= d100) && (d100 <= 94))
	{
		return "Spell Resistance (19)";
	}
	else if(d100 == 95)
	{
		return "Greater Acid Resistance";
	}
	else if(d100 == 96)
	{
		return "Greater Cold Resistance";
	}
	else if(d100 == 97)
	{
		return "Greater Electricity Resistance";
	}
	else if(d100 == 98)
	{
		return "Greater Fire Resistance";
	}
	else if(d100 == 99)
	{
		return "Greater Sonic Resistance";
	}
	else
	{
		string ability2 = majorArmorAbility(bonus);
		return ability + ", " + ability2;
	}
}
string minorShieldAbility(int bonus)
{
	int d100;
	string ability;
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 20))
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			return "Arrow Catching";
		}
		else
			return "";
	}
	else if((21 <= d100) && (d100 <= 40))
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			return "Bashing";	
		}
		else
			return "";
	}
	else if((41 <= d100) && (d100 <= 50))
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			return "Blinding";
		}
		else
			return "";
	}
	else if((51 <= d100) && (d100 <= 75))
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			return "Light Fortification";
		}
		else
			return "";
	}
	else if((76 <= d100) && (d100 <= 92))
	{
		if((bonus+2) <= 10)
		{
			bonus+=2;
			return "Arrow Deflection";
		}
		else
			return "";
	}
	else if((93 <= d100) && (d100 <= 97))
	{
		if((bonus+2) <= 10)
		{
			bonus+=2;
			return "Animation";
		}
		else
			return "";
	}
	else if((98 <= d100) && (d100 <= 99))
	{
		if((bonus+2) <= 10)
		{
			bonus+=2;
			return "Spell Resistance (13)";
		}
		else
			return "";
	}
	else
	{
		string ability2 = minorShieldAbility(bonus);
		return ability + ability2;
	}
}
string mediumShieldAbility(int bonus)
{
	int d100;
	string ability;
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 10))
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			return "Arrow Catching";
		}
		else
			return "";
	}
	else if((11 <= d100) && (d100 <= 20))
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			return "Bashing";	
		}
		else
			return "";
	}
	else if((21 <= d100) && (d100 <= 25))
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			return "Blinding";
		}
		else
			return "";
	}
	else if((26 <= d100) && (d100 <= 40))
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			return "Light Fortification";
		}
		else
			return "";
	}
	else if((41 <= d100) && (d100 <= 50))
	{
		if((bonus+2) <= 10)
		{
			bonus+=2;
			return "Arrow Deflection";
		}
		else
			return "";
	}
	else if((51 <= d100) && (d100 <= 57))
	{
		if((bonus+2) <= 10)
		{
			bonus+=2;
			return "Animation";
		}
		else
			return "";
	}
	else if((58 <= d100) && (d100 <= 59))
	{
		if((bonus+2) <= 10)
		{
			bonus+=2;
			return "Spell Resistance (13)";
		}
		else
			return "";
	}
	else if((60 <= d100) && (d100 <= 63))
	{
		return "Acid Resistance";
	}
	else if((64 <= d100) && (d100 <= 67))
	{
		return "Cold Resistance";
	}
	else if((68 <= d100) && (d100 <= 71))
	{
		return "Electricity Resistance";
	}
	else if((72 <= d100) && (d100 <= 75))
	{
		return "Fire Resistance";
	}
	else if((76 <= d100) && (d100 <= 79))
	{
		return "Sonic Resistance";
	}
	else if((80 <= d100) && (d100 <= 85))
	{
		if((bonus+3) <= 10)
		{
			bonus+=3;
			return "Ghost Touch";
		}
		else
			return "";
	}
	else if((86 <= d100) && (d100 <= 95))
	{
		if((bonus+3) <= 10)
		{
			bonus+=3;
			return "Moderate Fortification";
		}
		else
			return "";
	}
	else if((96 <= d100) && (d100 <= 98))
	{
		if((bonus+3) <= 10)
		{
			bonus+=3;
			return "Spell Resistance (15)";
		}
		else
			return "";
	}
	else if(d100 == 99)
	{
		if((bonus+3) <= 10)
		{
			bonus+=3;
			return "the Wild";
		}
		else
			return "";
	}
	else
	{
		string ability2 = mediumShieldAbility(bonus);
		return ability + ability2;
	}
}
string majorShieldAbility(int bonus)
{
	int d100;
	string ability;
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 5))
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			return "Arrow Catching";
		}
		else
			return "";
	}
	else if((6 <= d100) && (d100 <= 8))
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			return "Bashing";	
		}
		else
			return "";
	}
	else if((9 <= d100) && (d100 <= 10))
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			return "Blinding";
		}
		else
			return "";
	}
	else if((11 <= d100) && (d100 <= 15))
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			return "Light Fortification";
		}
		else
			return "";
	}
	else if((16 <= d100) && (d100 <= 20))
	{
		if((bonus+2) <= 10)
		{
			bonus+=2;
			return "Arrow Deflection";
		}
		else
			return "";
	}
	else if((21 <= d100) && (d100 <= 25))
	{
		if((bonus+2) <= 10)
		{
			bonus+=2;
			return "Animation";
		}
		else
			return "";
	}
	else if((26 <= d100) && (d100 <= 28))
	{
		return "Acid Resistance";
	}
	else if((29 <= d100) && (d100 <= 31))
	{
		return "Cold Resistance";
	}
	else if((32 <= d100) && (d100 <= 34))
	{
		return "Electricity Resistance";
	}
	else if((35 <= d100) && (d100 <= 37))
	{
		return "Fire Resistance";
	}
	else if((38 <= d100) && (d100 <= 40))
	{
		return "Sonic Resistance";
	}
	else if((41 <= d100) && (d100 <= 46))
	{
		if((bonus+3) <= 10)
		{
			bonus+=3;
			return "Ghost Touch";
		}
		else
			return "";
	}
	else if((47 <= d100) && (d100 <= 56))
	{
		if((bonus+3) <= 10)
		{
			bonus+=3;
			return "Moderate Fortification";
		}
		else
			return "";
	}
	else if((57 <= d100) && (d100 <= 58))
	{
		if((bonus+3) <= 10)
		{
			bonus+=3;
			return "Spell Resistance (15)";
		}
		else
			return "";
	}
	else if(d100 == 59)
	{
		if((bonus+3) <= 10)
		{
			bonus+=3;
			return "the Wild";
		}
		else
			return "";
	}
	else if((60 <= d100) && (d100 <= 64))
	{
		return "Improved Acid Resistance";
	}
	else if((65 <= d100) && (d100 <= 69))
	{
		return "Improved Cold Resistance";
	}
	else if((70 <= d100) && (d100 <= 74))
	{
		return "Improved Electricity Resistance";
	}
	else if((75 <= d100) && (d100 <= 79))
	{
		return "Improved Fire Resistance";
	}
	else if((80 <= d100) && (d100 <= 84))
	{
		return "Improved Sonic Resistance";
	}
	else if((85 <= d100) && (d100 <= 86))
	{
		if((bonus+4) <= 10)
		{
			bonus+=4;
			return "Spell Resistance (17)";
		}
		else
			return "";
	}
	else if(d100 == 87)
	{
		return "Undead Controlling";
	}
	else if((88 <= d100) && (d100 <= 91))
	{
		if((bonus+5) <= 10)
		{
			bonus+=5;
			return "Heavy Fortification";
		}
		else
			return "";
	}
	else if((92 <= d100) && (d100 <= 93))
	{
		if((bonus+5) <= 10)
		{
			bonus+=5;
			return "Reflecting";
		}
		else
			return "";
	}
	else if(d100 == 94)
	{
		return "Greater Acid Resistance";
	}
	else if(d100 == 95)
	{
		return "Greater Cold Resistance";
	}
	else if(d100 == 96)
	{
		return "Greater Electricity Resistance";
	}
	else if(d100 == 97)
	{
		return "Greater Fire Resistance";
	}
	else if(d100 == 98)
	{
		return "Greater Sonic Resistance";
	}
	else
	{
		string ability2 = majorShieldAbility(bonus);
		return ability + ability2;
	}
}

Weapon randomWeapon()
{
	int d100;
	Weapon newWeapon;
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 70))
	{
		return commonWeapon();
	}
	else if((71 <= d100) && (d100 <= 80))
	{
		return uncommonWeapon();
	}
	else
	{
		return rangedWeapon();
	}
}
Weapon commonWeapon()
{
	int d100;
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 4))
	{
		return Weapon("Dagger", 'p', 'm', true);
	}
	else if((5 <= d100) && (d100 <= 14))
	{
		return Weapon("Greataxe", 's', 'm', false);
	}
	else if((15 <= d100) && (d100 <= 24))
	{
		return Weapon("Greatsword", 's', 'm', false);
	}
	else if((25 <= d100) && (d100 <= 28))
	{
		return Weapon("Battleaxe", 's', 'm', false);
	}
	else if((29 <= d100) && (d100 <= 41))
	{
		return Weapon("Longsword", 's', 'm', false);
	}
	else if((42 <= d100) && (d100 <= 45))
	{
		return Weapon("Light Mace", 'b', 'm', false);
	}
	else if((46 <= d100) && (d100 <= 50))
	{
		return Weapon("Heavy Mace", 'b', 'm', false);
	}
	else if((51 <= d100) && (d100 <= 52))
	{
		return Weapon("Warhammer", 'b', 'm', false);
	}
	else if((53 <= d100) && (d100 <= 54))
	{
		return Weapon("Maul", 'b', 'm', false);
	}
	else if((55 <= d100) && (d100 <= 57))
	{
		return Weapon("Quarterstaff", 'b', 'm', false);
	}
	else if((58 <= d100) && (d100 <= 61))
	{
		return Weapon("Rapier", 'p', 'm', false);
	}
	else if((62 <= d100) && (d100 <= 66))
	{
		return Weapon("Scimitar", 's', 'm', false);
	}
	else if((67 <= d100) && (d100 <= 70))
	{
		return Weapon("Shortspear", 'p', 'm', true);
	}
	else if((71 <= d100) && (d100 <= 74))
	{
		return Weapon("Morningstar", 'b', 'm', false);
	}
	else if((75 <= d100) && (d100 <= 84))
	{
		return Weapon("Bastard Sword", 's', 'm', false);
	}
	else if((85 <= d100) && (d100 <= 89))
	{
		return Weapon("Short Sword", 'p', 'm', false);
	}
	else
	{
		return Weapon("Dwarven Waraxe", 's', 'm', false);
	}
}
Weapon uncommonWeapon()
{
	int d100;
	Weapon w1;
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 3))
	{
		return Weapon("Orc Double Axe", 's', 'm', false);
	}
	else if((4 <= d100) && (d100 <= 7))
	{
		return Weapon("Kama", 's', 'm', false);
	}
	else if((8 <= d100) && (d100 <= 10))
	{
		return Weapon("Spiked Chain", 'p', 'm', false);
	}
	else if((11 <= d100) && (d100 <= 12))
	{
		return Weapon("Club", 'b', 'm', false);
	}
	else if((13 <= d100) && (d100 <= 16))
	{
		return Weapon("Hand Crossbow", 'p', 'm', false);
	}
	else if((17 <= d100) && (d100 <= 19))
	{
		int d2 = rand()%2+1;
		if(d2 == 1)
		{
			return Weapon("Light Repeating Crossbow", 'p', 'r', false);
		}
		else
		{
			return Weapon("Heavy Repeating Crossbow", 'p', 'r', false);
		}
	}
	else if((20 <= d100) && (d100 <= 21))
	{
		return Weapon("Punching Dagger", 'p', 'm', false);
	}
	else if((22 <= d100) && (d100 <= 23))
	{
		return Weapon("Falchion", 's', 'm', false);
	}
	else if((24 <= d100) && (d100 <= 26))
	{
		return Weapon("Dire Flail", 'b', 'm', false);
	}
	else if((27 <= d100) && (d100 <= 31))
	{
		return Weapon("Heavy Flail", 'b', 'm', false);
	}
	else if((32 <= d100) && (d100 <= 35))
	{
		return Weapon("Light Flail", 'b', 'm', false);
	}
	else if((36 <= d100) && (d100 <= 37))
	{
		return Weapon("Gauntlet", 'b', 'm', false);
	}
	else if((38 <= d100) && (d100 <= 39))
	{
		return Weapon("Spiked Gauntlet", 'p', 'm', false);
	}
	else if((40 <= d100) && (d100 <= 41))
	{
		return Weapon("Glaive", 's', 'm', false);
	}
	else if((42 <= d100) && (d100 <= 43))
	{
		return Weapon("Greatclub", 'b', 'm', false);
	}
	else if((44 <= d100) && (d100 <= 45))
	{
		return Weapon("Guisarme", 's', 'm', false);
	}
	else if((46 <= d100) && (d100 <= 48))
	{
		return Weapon("Halberd", 's', 'm', false);
	}
	else if((49 <= d100) && (d100 <= 51))
	{
		return Weapon("Halfspear", 'p', 'm', true);
	}
	else if((52 <= d100) && (d100 <= 54))
	{
		return Weapon("Gnome Hooked Hammer", 'b', 'm', false);
	}
	else if((55 <= d100) && (d100 <= 56))
	{
		return Weapon("Light Hammer", 'b', 'm', true);
	}
	else if((57 <= d100) && (d100 <= 58))
	{
		return Weapon("Handaxe", 's', 'm', false);
	}
	else if((59 <= d100) && (d100 <= 61))
	{
		return Weapon("Kukri", 's', 'm', false);
	}
	else if((62 <= d100) && (d100 <= 64))
	{
		return Weapon("Lance", 'p', 'm', false);
	}
	else if((65 <= d100) && (d100 <= 67))
	{
		return Weapon("Longspear", 'p', 'm', false);
	}
	else if((68 <= d100) && (d100 <= 70))
	{
		return Weapon("Nunchaku", 'b', 'm', false);
	}
	else if((71 <= d100) && (d100 <= 72))
	{
		return Weapon("Net", '-', 'm', false);
	}
	else if((73 <= d100) && (d100 <= 74))
	{
		return Weapon("Heavy Pick", 'p', 'm', false);
	}
	else if((75 <= d100) && (d100 <= 76))
	{
		return Weapon("Light Pick", 'p', 'm', false);
	}
	else if((77 <= d100) && (d100 <= 78))
	{
		return Weapon("Ranseur", 'p', 'm', false);
	}
	else if((79 <= d100) && (d100 <= 80))
	{
		return Weapon("Sap", 'b', 'm', false);
	}
	else if((81 <= d100) && (d100 <= 82))
	{
		return Weapon("Scythe", 's', 'm', false);
	}
	else if((83 <= d100) && (d100 <= 84))
	{
		return Weapon("Shuriken (20)", 'p', 'r', true);
	}
	else if((85 <= d100) && (d100 <= 86))
	{
		return Weapon("Sickle", 's', 'm', false);
	}
	else if((87 <= d100) && (d100 <= 89))
	{
		return Weapon("Two-Bladed Sword", 's', 'm', false);
	}
	else if((90 <= d100) && (d100 <= 91))
	{
		return Weapon("Trident", 'p', 'm', false);
	}
	else if((92 <= d100) && (d100 <= 94))
	{
		return Weapon("Dwarven Urgrosh", 's', 'm', false);
	}
	else if((95 <= d100) && (d100 <= 97))
	{
		return Weapon("Siangham", 'p', 'm', false);
	}
	else
	{
		return Weapon("Whip", 's', 'm', false);
	}
}
Weapon rangedWeapon()
{
	int d100;
	Weapon w1;
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 5))
	{
		return Weapon("Arrows(50)", '-', 'r', false);
	}
	else if((6 <= d100) && (d100 <= 8))
	{
		return Weapon("Bolts (50)", '-', 'r', false);
	}
	else if((9 <= d100) && (d100 <= 10))
	{
		return Weapon("Bullets (50)", '-', 'r', false);
	}
	else if((11 <= d100) && (d100 <= 15))
	{
		return Weapon("Throwing Axe", 's', 'r', true);
	}
	else if((16 <= d100) && (d100 <= 25))
	{
		return Weapon("Heavy Crossbow", 'p', 'r', false);
	}
	else if((26 <= d100) && (d100 <= 35))
	{
		return Weapon("Light Crossbow", 'p', 'r', false);
	}
	else if((36 <= d100) && (d100 <= 39))
	{
		return Weapon("Dart", 'p', 'r', true);
	}
	else if((40 <= d100) && (d100 <= 41))
	{
		return Weapon("Javelin", 'p', 'r', true);
	}
	else if((42 <= d100) && (d100 <= 46))
	{
		return Weapon("Shortbow", 'p', 'r', false);
	}
	else if((47 <= d100) && (d100 <= 51))
	{
		return Weapon("Composite Shortbow", 'p', 'r', false);
	}
	else if((52 <= d100) && (d100 <= 56))
	{
		return Weapon("Composite Shortbow (+1 Str bonus)", 'p', 'r', false);
	}
	else if((57 <= d100) && (d100 <= 61))
	{
		return Weapon("Composite Shortbow (+2 Str bonus)", 'p', 'r', false);
	}
	else if((62 <= d100) && (d100 <= 65))
	{
		return Weapon("Sling", 'b', 'r', false);
	}
	else if((66 <= d100) && (d100 <= 75))
	{
		return Weapon("Longbow", 'p', 'r', false);
	}
	else if((76 <= d100) && (d100 <= 80))
	{
		return Weapon("Composite Longbow", 'p', 'r', false);
	}
	else if((81 <= d100) && (d100 <= 85))
	{
		return Weapon("Composite Longbow (+1 Str bonus)", 'p', 'r', false);
	}
	else if((86 <= d100) && (d100 <= 90))
	{
		return Weapon("Composite Longbow (+2 Str bonus)", 'p', 'r', false);
	}
	else if((91 <= d100) && (d100 <= 95))
	{
		return Weapon("Composite Longbow (+3 Str bonus)", 'p', 'r', false);
	}
	else
	{
		return Weapon("Composite Longbow (+4 Str bonus)", 'p', 'r', false);
	}
}
void minorWeapon()
{
	int d100, bonus=0;
	Weapon newWeapon;
	string ability;
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 70))
	{
		cout << "+1 " << randomWeapon() << endl;
	}
	else if((71 <= d100) && (d100 <= 85))
	{
		cout << "+2 " << randomWeapon() << endl;
	}
	else if((86 <= d100) && (d100 <= 90))
	{
		minorSpecificWeapon();
	}
	else
	{
		d100=rand()%85+1;
		if((1 <= d100) && (d100 <= 70))
		{
			Weapon newWeapon = randomWeapon();
			bonus = 1;
			cout << "+1 ";
		}
		else
		{
			Weapon newWeapon = randomWeapon();
			bonus = 2;
			cout << "+2 ";
		}
		ability = minorWeaponAbility(newWeapon, bonus);
		cout << ability << " " << newWeapon << endl;
	}
}
void mediumWeapon()
{
	int d100, bonus=0;
	string ability;
	Weapon newWeapon;
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 10))
	{
		newWeapon = randomWeapon();
		cout << "+1 " << newWeapon << endl;
	}
	else if((11 <= d100) && (d100 <= 29))
	{
		newWeapon = randomWeapon();
		cout << "+2 " << newWeapon << endl;
	}
	else if((30 <= d100) && (d100 <= 58))
	{
		newWeapon = randomWeapon();
		cout << "+3 " << newWeapon << endl;
	}
	else if((59 <= d100) && (d100 <= 62))
	{
		newWeapon = randomWeapon();
		cout << "+4 " << newWeapon << endl;
	}
	else if((63 <= d100) && (d100 <= 68))
	{
		mediumSpecificWeapon();
	}
	else
	{
		d100=rand()%62+1;
		if((1 <= d100) && (d100 <= 10))
		{
			newWeapon = randomWeapon();
			bonus = 1;
			cout << "+1 ";
		}
		else if((11 <= d100) && (d100 <= 29))
		{
			newWeapon = randomWeapon();
			bonus = 2;
			cout << "+2 ";
		}
		else if((30 <= d100) && (d100 <= 58))
		{
			newWeapon = randomWeapon();
			bonus = 3;
			cout << "+3 ";
		}
		else if((59 <= d100) && (d100 <= 62))
		{
			newWeapon = randomWeapon();
			bonus = 4;
			cout << "+4 ";
		}
		ability = mediumWeaponAbility(newWeapon, bonus);
		cout << ability << " " << newWeapon << endl;
	}
}
void majorWeapon()
{
	int d100, bonus=0;
	string ability;
	Weapon newWeapon;
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 20))
	{
		newWeapon = randomWeapon();
		cout << "+3 " << newWeapon << endl;
	}
	else if((21 <= d100) && (d100 <= 38))
	{
		newWeapon = randomWeapon();
		cout << "+4 " << newWeapon << endl;
	}
	else if((39 <= d100) && (d100 <= 49))
	{
		newWeapon = randomWeapon();
		cout << "+5 " << newWeapon << endl;
	}
	else if((50 <= d100) && (d100 <= 63))
	{
		majorSpecificWeapon();
	}
	else
	{
		d100=rand()%49+1;
		if((1 <= d100) && (d100 <= 20))
		{
			newWeapon = randomWeapon();
			bonus = 3;
			cout << "+3 ";
		}
		else if((21 <= d100) && (d100 <= 38))
		{
			newWeapon = randomWeapon();
			bonus = 4;
			cout << "+4 ";
		}
		else if((39 <= d100) && (d100 <= 49))
		{
			newWeapon = randomWeapon();
			bonus = 5;
			cout << "+5 ";
		}
		ability = majorWeaponAbility(newWeapon, bonus);
		cout << ability << " " << newWeapon << endl;
	}
}
void minorSpecificWeapon()
{
	int d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 15))
	{
		cout << "Sleep Arrow (Specific Weapon)" << endl;
	}
	else if((16 <= d100) && (d100 <= 25))
	{
		cout << "Screaming Bolt (Specific Weapon)" << endl;
	}
	else if((26 <= d100) && (d100 <= 45))
	{
		cout << "Masterwork Silver Dagger (Specific Weapon)" << endl;
	}
	else if((46 <= d100) && (d100 <= 65))
	{
		cout << "Masterwork Cold Iron Longsword (Specific Weapon)" << endl;
	}
	else if((66 <= d100) && (d100 <= 75))
	{
		cout << "Javelin of Lightning (Specific Weapon)" << endl;
	}
	else if((76 <= d100) && (d100 <= 80))
	{
		d100=rand()%100+1;
		if((1 <= d100) && (d100 <= 5))
			cout << "Slaying Arrow (Aberrations) (Specific Weapon)" << endl;
		else if((6 <= d100) && (d100 <= 9))
			cout << "Slaying Arrow (Animals) (Specific Weapon)" << endl;
		else if((10 <= d100) && (d100 <= 16))
			cout << "Slaying Arrow (Constructs) (Specific Weapon)" << endl;
		else if((17 <= d100) && (d100 <= 22))
			cout << "Slaying Arrow (Dragons) (Specific Weapon)" << endl;
		else if((23 <= d100) && (d100 <= 27))
			cout << "Slaying Arrow (Elementals) (Specific Weapon)" << endl;
		else if((28 <= d100) && (d100 <= 32))
			cout << "Slaying Arrow (Fey) (Specific Weapon)" << endl;
		else if((33 <= d100) && (d100 <= 39))
			cout << "Slaying Arrow (Giants) (Specific Weapon)" << endl;
		else if(d100 == 40)
			cout << "Slaying Arrow (Aquatic Humanoids) (Specific Weapon)" << endl;
		else if((41 <= d100) && (d100 <= 42))
			cout << "Slaying Arrow (Dwarves) (Specific Weapon)" << endl;
		else if((43 <= d100) && (d100 <= 44))
			cout << "Slaying Arrow (Elves) (Specific Weapon)" << endl;
		else if(d100 == 45)
			cout << "Slaying Arrow (Gnolls) (Specific Weapon)" << endl;
		else if(d100 == 46)
			cout << "Slaying Arrow (Gnomes) (Specific Weapon)" << endl;
		else if((47 <= d100) && (d100 <= 49))
			cout << "Slaying Arrow (Goblinoids) (Specific Weapon)" << endl;
		else if(d100 == 50)
			cout << "Slaying Arrow (Halflings) (Specific Weapon)" << endl;
		else if((51 <= d100) && (d100 <= 54))
			cout << "Slaying Arrow (Humans) (Specific Weapon)" << endl;
		else if((55 <= d100) && (d100 <= 57))
			cout << "Slaying Arrow (Reptilian Humanoids) (Specific Weapon)" << endl;
		else if((58 <= d100) && (d100 <= 60))
			cout << "Slaying Arrow (Orcs) (Specific Weapon)" << endl;
		else if((61 <= d100) && (d100 <= 65))
			cout << "Slaying Arrow (Magical Beasts) (Specific Weapon)" << endl;
		else if((66 <= d100) && (d100 <= 70))
			cout << "Slaying Arrow (Monstrous Humanoids) (Specific Weapon)" << endl;
		else if((71 <= d100) && (d100 <= 72))
			cout << "Slaying Arrow (Oozes) (Specific Weapon)" << endl;
		else if(d100 == 73)
			cout << "Slaying Arrow (Air Outsiders) (Specific Weapon)" << endl;
		else if((74 <= d100) && (d100 <= 76))
			cout << "Slaying Arrow (Chaotic Outsiders) (Specific Weapon)" << endl;
		else if(d100 == 77)
			cout << "Slaying Arrow (Earth Outsiders) (Specific Weapon)" << endl;
		else if((78 <= d100) && (d100 <= 80))
			cout << "Slaying Arrow (Evil Outsiders) (Specific Weapon)" << endl;
		else if(d100 == 81)
			cout << "Slaying Arrow (Fire Outsiders) (Specific Weapon)" << endl;
		else if((82 <= d100) && (d100 <= 84))
			cout << "Slaying Arrow (Good Outsiders) (Specific Weapon)" << endl;
		else if((85 <= d100) && (d100 <= 87))
			cout << "Slaying Arrow (Lawful Outsiders) (Specific Weapon)" << endl;
		else if(d100 == 88)
			cout << "Slaying Arrow (Water Outsiders) (Specific Weapon)" << endl;
		else if((89 <= d100) && (d100 <= 90))
			cout << "Slaying Arrow (Plants) (Specific Weapon)" << endl;
		else if((91 <= d100) && (d100 <= 98))
			cout << "Slaying Arrow (Undead) (Specific Weapon)" << endl;
		else
			cout << "Slaying Arrow (Vermin) (Specific Weapon)" << endl;
	}
	else if((81 <= d100) && (d100 <= 90))
	{
		cout << "Adamantine Dagger (Specific Weapon)" << endl;
	}
	else
	{
		cout << "Adamantine Battleaxe (Specific Weapon)" << endl;
	}
}
void mediumSpecificWeapon()
{
	int d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 9))
	{
		cout << "Javelin of Lightning (Specific Weapon)" << endl;
	}
	else if((10 <= d100) && (d100 <= 15))
	{
		d100=rand()%100+1;
		if((1 <= d100) && (d100 <= 5))
			cout << "Slaying Arrow (Aberrations) (Specific Weapon)" << endl;
		else if((6 <= d100) && (d100 <= 9))
			cout << "Slaying Arrow (Animals) (Specific Weapon)" << endl;
		else if((10 <= d100) && (d100 <= 16))
			cout << "Slaying Arrow (Constructs) (Specific Weapon)" << endl;
		else if((17 <= d100) && (d100 <= 22))
			cout << "Slaying Arrow (Dragons) (Specific Weapon)" << endl;
		else if((23 <= d100) && (d100 <= 27))
			cout << "Slaying Arrow (Elementals) (Specific Weapon)" << endl;
		else if((28 <= d100) && (d100 <= 32))
			cout << "Slaying Arrow (Fey) (Specific Weapon)" << endl;
		else if((33 <= d100) && (d100 <= 39))
			cout << "Slaying Arrow (Giants) (Specific Weapon)" << endl;
		else if(d100 == 40)
			cout << "Slaying Arrow (Aquatic Humanoids) (Specific Weapon)" << endl;
		else if((41 <= d100) && (d100 <= 42))
			cout << "Slaying Arrow (Dwarves) (Specific Weapon)" << endl;
		else if((43 <= d100) && (d100 <= 44))
			cout << "Slaying Arrow (Elves) (Specific Weapon)" << endl;
		else if(d100 == 45)
			cout << "Slaying Arrow (Gnolls) (Specific Weapon)" << endl;
		else if(d100 == 46)
			cout << "Slaying Arrow (Gnomes) (Specific Weapon)" << endl;
		else if((47 <= d100) && (d100 <= 49))
			cout << "Slaying Arrow (Goblinoids) (Specific Weapon)" << endl;
		else if(d100 == 50)
			cout << "Slaying Arrow (Halflings) (Specific Weapon)" << endl;
		else if((51 <= d100) && (d100 <= 54))
			cout << "Slaying Arrow (Humans) (Specific Weapon)" << endl;
		else if((55 <= d100) && (d100 <= 57))
			cout << "Slaying Arrow (Reptilian Humanoids) (Specific Weapon)" << endl;
		else if((58 <= d100) && (d100 <= 60))
			cout << "Slaying Arrow (Orcs) (Specific Weapon)" << endl;
		else if((61 <= d100) && (d100 <= 65))
			cout << "Slaying Arrow (Magical Beasts) (Specific Weapon)" << endl;
		else if((66 <= d100) && (d100 <= 70))
			cout << "Slaying Arrow (Monstrous Humanoids) (Specific Weapon)" << endl;
		else if((71 <= d100) && (d100 <= 72))
			cout << "Slaying Arrow (Oozes) (Specific Weapon)" << endl;
		else if(d100 == 73)
			cout << "Slaying Arrow (Air Outsiders) (Specific Weapon)" << endl;
		else if((74 <= d100) && (d100 <= 76))
			cout << "Slaying Arrow (Chaotic Outsiders) (Specific Weapon)" << endl;
		else if(d100 == 77)
			cout << "Slaying Arrow (Earth Outsiders) (Specific Weapon)" << endl;
		else if((78 <= d100) && (d100 <= 80))
			cout << "Slaying Arrow (Evil Outsiders) (Specific Weapon)" << endl;
		else if(d100 == 81)
			cout << "Slaying Arrow (Fire Outsiders) (Specific Weapon)" << endl;
		else if((82 <= d100) && (d100 <= 84))
			cout << "Slaying Arrow (Good Outsiders) (Specific Weapon)" << endl;
		else if((85 <= d100) && (d100 <= 87))
			cout << "Slaying Arrow (Lawful Outsiders) (Specific Weapon)" << endl;
		else if(d100 == 88)
			cout << "Slaying Arrow (Water Outsiders) (Specific Weapon)" << endl;
		else if((89 <= d100) && (d100 <= 90))
			cout << "Slaying Arrow (Plants) (Specific Weapon)" << endl;
		else if((91 <= d100) && (d100 <= 98))
			cout << "Slaying Arrow (Undead) (Specific Weapon)" << endl;
		else
			cout << "Slaying Arrow (Vermin) (Specific Weapon)" << endl;
	}
	else if((16 <= d100) && (d100 <= 24))
	{
		cout << "Adamantine Dagger (Specific Weapon)" << endl;
	}
	else if((25 <= d100) && (d100 <= 33))
	{
		cout << "Adamantine Battleaxe (Specific Weapon)" << endl;
	}
	else if((34 <= d100) && (d100 <= 37))
	{
		d100=rand()%100+1;
		if((1 <= d100) && (d100 <= 5))
			cout << "Greater Slaying Arrow (Aberrations) (Specific Weapon)" << endl;
		else if((6 <= d100) && (d100 <= 9))
			cout << "Greater Slaying Arrow (Animals) (Specific Weapon)" << endl;
		else if((10 <= d100) && (d100 <= 16))
			cout << "Greater Slaying Arrow (Constructs) (Specific Weapon)" << endl;
		else if((17 <= d100) && (d100 <= 22))
			cout << "Greater Slaying Arrow (Dragons) (Specific Weapon)" << endl;
		else if((23 <= d100) && (d100 <= 27))
			cout << "Greater Slaying Arrow (Elementals) (Specific Weapon)" << endl;
		else if((28 <= d100) && (d100 <= 32))
			cout << "Greater Slaying Arrow (Fey) (Specific Weapon)" << endl;
		else if((33 <= d100) && (d100 <= 39))
			cout << "Greater Slaying Arrow (Giants) (Specific Weapon)" << endl;
		else if(d100 == 40)
			cout << "Greater Slaying Arrow (Aquatic Humanoids) (Specific Weapon)" << endl;
		else if((41 <= d100) && (d100 <= 42))
			cout << "Greater Slaying Arrow (Dwarves) (Specific Weapon)" << endl;
		else if((43 <= d100) && (d100 <= 44))
			cout << "Greater Slaying Arrow (Elves) (Specific Weapon)" << endl;
		else if(d100 == 45)
			cout << "Greater Slaying Arrow (Gnolls) (Specific Weapon)" << endl;
		else if(d100 == 46)
			cout << "Greater Slaying Arrow (Gnomes) (Specific Weapon)" << endl;
		else if((47 <= d100) && (d100 <= 49))
			cout << "Greater Slaying Arrow (Goblinoids) (Specific Weapon)" << endl;
		else if(d100 == 50)
			cout << "Greater Slaying Arrow (Halflings) (Specific Weapon)" << endl;
		else if((51 <= d100) && (d100 <= 54))
			cout << "Greater Slaying Arrow (Humans) (Specific Weapon)" << endl;
		else if((55 <= d100) && (d100 <= 57))
			cout << "Greater Slaying Arrow (Reptilian Humanoids) (Specific Weapon)" << endl;
		else if((58 <= d100) && (d100 <= 60))
			cout << "Greater Slaying Arrow (Orcs) (Specific Weapon)" << endl;
		else if((61 <= d100) && (d100 <= 65))
			cout << "Greater Slaying Arrow (Magical Beasts) (Specific Weapon)" << endl;
		else if((66 <= d100) && (d100 <= 70))
			cout << "Greater Slaying Arrow (Monstrous Humanoids) (Specific Weapon)" << endl;
		else if((71 <= d100) && (d100 <= 72))
			cout << "Greater Slaying Arrow (Oozes) (Specific Weapon)" << endl;
		else if(d100 == 73)
			cout << "Greater Slaying Arrow (Air Outsiders) (Specific Weapon)" << endl;
		else if((74 <= d100) && (d100 <= 76))
			cout << "Greater Slaying Arrow (Chaotic Outsiders) (Specific Weapon)" << endl;
		else if(d100 == 77)
			cout << "Greater Slaying Arrow (Earth Outsiders) (Specific Weapon)" << endl;
		else if((78 <= d100) && (d100 <= 80))
			cout << "Greater Slaying Arrow (Evil Outsiders) (Specific Weapon)" << endl;
		else if(d100 == 81)
			cout << "Greater Slaying Arrow (Fire Outsiders) (Specific Weapon)" << endl;
		else if((82 <= d100) && (d100 <= 84))
			cout << "Greater Slaying Arrow (Good Outsiders) (Specific Weapon)" << endl;
		else if((85 <= d100) && (d100 <= 87))
			cout << "Greater Slaying Arrow (Lawful Outsiders) (Specific Weapon)" << endl;
		else if(d100 == 88)
			cout << "Greater Slaying Arrow (Water Outsiders) (Specific Weapon)" << endl;
		else if((89 <= d100) && (d100 <= 90))
			cout << "Greater Slaying Arrow (Plants) (Specific Weapon)" << endl;
		else if((91 <= d100) && (d100 <= 98))
			cout << "Greater Slaying Arrow (Undead) (Specific Weapon)" << endl;
		else
			cout << "Greater Slaying Arrow (Vermin) (Specific Weapon)" << endl;
	}
	else if((38 <= d100) && (d100 <= 40))
	{
		cout << "Shatterspike (Longsword) (Specific Weapon)" << endl;
	}
	else if((41 <= d100) && (d100 <= 46))
	{
		cout << "Dagger of Venom (Specific Weapon)" << endl;
	}
	else if((47 <= d100) && (d100 <= 51))
	{
		cout << "Trident of Warning (Specific Weapon)" << endl;
	}
	else if((52 <= d100) && (d100 <= 57))
	{
		cout << "Assassin's Dagger (Specific Weapon)" << endl;
	}
	else if((58 <= d100) && (d100 <= 62))
	{
		cout << "Shifter's Sorrow (Two-Bladed Sword) (Specific Weapon)" << endl;
	}
	else if((63 <= d100) && (d100 <= 66))
	{
		cout << "Trident of Fish Command (Specific Weapon)" << endl;
	}
	else if((67 <= d100) && (d100 <= 74))
	{
		cout << "Flame Tongue (Longsword) (Specific Weapon)" << endl;
	}
	else if((75 <= d100) && (d100 <= 79))
	{
		cout << "Luck Blade (0 wishes) (Short Sword) (Specific Weapon)" << endl;
	}
	else if((80 <= d100) && (d100 <= 86))
	{
		cout << "Sword of Subtlety (Short Sword) (Specific Weapon)" << endl;
	}
	else if((87 <= d100) && (d100 <= 91))
	{
		cout << "Sword of the Planes (Longsword) (Specific Weapon)" << endl;
	}
	else if((92 <= d100) && (d100 <= 95))
	{
		cout << "Nine Lives Stealer (Longsword) (Specific Weapon)" << endl;
	}
	else if((96 <= d100) && (d100 <= 98))
	{
		cout << "Sword of Life Stealing (Specific Weapon)" << endl;
	}
	else
	{
		cout << "Oathbow (Composite Longbow) (Specific Weapon)" << endl;
	}
}
void majorSpecificWeapon()
{
	int d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 4))
	{
		cout << "Assassin's Dagger (Specific Weapon)" << endl;
	}
	else if((5 <= d100) && (d100 <= 7))
	{
		cout << "Shifter's Sorrow (Two-Bladed Sword) (Specific Weapon)" << endl;
	}
	else if((8 <= d100) && (d100 <= 9))
	{
		cout << "Trident of Fish Command (Specific Weapon)" << endl;
	}
	else if((10 <= d100) && (d100 <= 13))
	{
		cout << "Flame Tongue (Longsword) (Specific Weapon)" << endl;
	}
	else if((14 <= d100) && (d100 <= 17))
	{
		cout << "Luck Blade (0 wishes) (Short Sword) (Specific Weapon)" << endl;
	}
	else if((18 <= d100) && (d100 <= 24))
	{
		cout << "Sword of Subtlety (Short Sword) (Specific Weapon)" << endl;
	}
	else if((25 <= d100) && (d100 <= 31))
	{
		cout << "Sword of the Planes (Longsword) (Specific Weapon)" << endl;
	}
	else if((32 <= d100) && (d100 <= 37))
	{
		cout << "Nine Lives Stealer (Longsword) (Specific Weapon)" << endl;
	}
	else if((38 <= d100) && (d100 <= 42))
	{
		cout << "Sword of Life Stealing (Specific Weapon)" << endl;
	}
	else if((43 <= d100) && (d100 <= 46))
	{
		cout << "Oathbow (Composite Longbow) (Specific Weapon)" << endl;
	}
	else if((47 <= d100) && (d100 <= 51))
	{
		cout << "Mace of Terror (Specific Weapon)" << endl;
	}
	else if((52 <= d100) && (d100 <= 57))
	{
		cout << "Life Drinker (Greataxe) (Specific Weapon)" << endl;
	}
	else if((58 <= d100) && (d100 <= 62))
	{
		cout << "Sylvan Scimitar (Specific Weapon)" << endl;
	}
	else if((63 <= d100) && (d100 <= 67))
	{
		cout << "Rapier of Puncturing (Specific Weapon)" << endl;
	}
	else if((68 <= d100) && (d100 <= 73))
	{
		cout << "Sun Blade (Bastard Sword) (Specific Weapon)" << endl;
	}
	else if((74 <= d100) && (d100 <= 79))
	{
		cout << "Frost Brand (Specific Weapon)" << endl;
	}
	else if((80 <= d100) && (d100 <= 84))
	{
		cout << "Dwarven Thrower (Warhammer) (Specific Weapon)" << endl;
	}
	else if((85 <= d100) && (d100 <= 91))
	{
		cout << "Luck Blade (1 wish) (Short Sword) (Specific Weapon)" << endl;
	}
	else if((92 <= d100) && (d100 <= 95))
	{
		cout << "Mace of Smiting (Specific Weapon)" << endl;
	}
	else if((96 <= d100) && (d100 <= 97))
	{
		cout << "Luck Blade (2 wishes) (Short Sword) (Specific Weapon)" << endl;
	}
	else if((98 <= d100) && (d100 <= 99))
	{
		cout << "Holy Avenger (Longsword) (Specific Weapon)" << endl;
	}
	else
	{
		cout << "Luck Blade (3 wishes) (Short Sword) (Specific Weapon)" << endl;
	}
}
string minorWeaponAbility(Weapon w1, int bonus)
{
	int d100;
	string ability;
	d100=rand()%131+1;//range for the d100 is increased to include the three exclusively ranged weapon abilities, consolidating the melee and ranged ability tables.
	if((1 <= d100) && (d100 <= 10))
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			d100=rand()%100+1;
			if((1 <= d100) && (d100 <= 5))
				return ability = "Aberration Bane";
			else if((6 <= d100) && (d100 <= 9))
				return ability = "Animal Bane";
			else if((10 <= d100) && (d100 <= 16))
				return ability = "Construct Bane";
			else if((17 <= d100) && (d100 <= 22))
				return ability = "Dragon Bane";
			else if((23 <= d100) && (d100 <= 27))
				return ability = "Elemental Bane";
			else if((28 <= d100) && (d100 <= 32))
				return ability = "Fey Bane";
			else if((33 <= d100) && (d100 <= 39))
				return ability = "Giant Bane";
			else if(d100 == 40)
				return ability = "Aquatic Humanoid Bane";
			else if((41 <= d100) && (d100 <= 42))
				return ability = "Dwarf Bane";
			else if((43 <= d100) && (d100 <= 44))
				return ability = "Elf Bane";
			else if(d100 == 45)
				return ability = "Gnoll Bane";
			else if(d100 == 46)
				return ability = "Gnome Bane";
			else if((47 <= d100) && (d100 <= 49))
				return ability = "Goblinoid Bane";
			else if(d100 == 50)
				return ability = "Halfling Bane";
			else if((51 <= d100) && (d100 <= 54))
				return ability = "Human Bane";
			else if((55 <= d100) && (d100 <= 57))
				return ability = "Reptilian Humanoid Bane";
			else if((58 <= d100) && (d100 <= 60))
				return ability = "Orc Bane";
			else if((61 <= d100) && (d100 <= 65))
				return ability = "Magical Beast Bane";
			else if((66 <= d100) && (d100 <= 70))
				return ability = "Monstrous Humanoid Bane";
			else if((71 <= d100) && (d100 <= 72))
				return ability = "Ooze Bane";
			else if(d100 == 73)
				return ability = "Air Outsider Bane";
			else if((74 <= d100) && (d100 <= 76))
				return ability = "Chaotic Outsider Bane";
			else if(d100 == 77)
				return ability = "Earth Outsider Bane";
			else if((78 <= d100) && (d100 <= 80))
				return ability = "Evil Outsider Bane";
			else if(d100 == 81)
				return ability = "Fire Outsider Bane";
			else if((82 <= d100) && (d100 <= 84))
				return ability = "Good Outsider Bane";
			else if((85 <= d100) && (d100 <= 87))
				return ability = "Lawful Outsider Bane";
			else if(d100 == 88)
				return ability = "Water Outsider Bane";
			else if((89 <= d100) && (d100 <= 90))
				return ability = "Plant Bane";
			else if((91 <= d100) && (d100 <= 98))
				return ability = "Undead Bane";
			else
				return ability = "Vermin Bane";
		}
		else
			return ability = "";
	}
	else if((11 <= d100) && (d100 <= 17))
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			return ability = "Defending";	
		}
		else
			return ability = "";
	}
	else if((18 <= d100) && (d100 <= 27))
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			return ability = "Flaming";	
		}
		else
			return ability = "";
	}
	else if((28 <= d100) && (d100 <= 37))
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			return ability = "Frost";	
		}
		else
			return ability = "";
	}
	else if((38 <= d100) && (d100 <= 47))
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			return ability = "Shocking";	
		}
		else
			return ability = "";
	}
	else if((48 <= d100) && (d100 <= 56))
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			return ability = "Ghost Touch";	
		}
		else
			return ability = "";
	}
	else if((57 <= d100) && (d100 <= 67))
	{
		if(((bonus+1) <= 10) && (w1.type != 'b'))
		{
			bonus++;
			return ability = "Keen";	
		}
		else if(w1.type == 'b')
		{
			return ability = minorWeaponAbility(w1, bonus);
		}
		else
			return ability = "";
	}
	else if((68 <= d100) && (d100 <= 71))
	{
		if(((bonus+1) <= 10) && (w1.range == 'm'))
		{
			bonus++;
			return ability = "Ki Focus";	
		}
		else if(w1.range == 'r')
		{
			return ability = minorWeaponAbility(w1, bonus);
		}
		else
			return ability = "";
	}
	else if((72 <= d100) && (d100 <= 75))
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			return ability = "Merciful";	
		}
		else
			return ability = "";
	}
	else if((76 <= d100) && (d100 <= 82))
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			return ability = "Mighty Cleaving";	
		}
		else
			return ability = "";
	}
	else if((83 <= d100) && (d100 <= 87))
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			return ability = "Spell Storing";	
		}
		else
			return ability = "";
	}
	else if((88 <= d100) && (d100 <= 91))
	{
		if(((bonus+1) <= 10) && (w1.range == 'm'))
		{
			bonus++;
			return ability = "Throwing";	
		}
		else if(w1.range == 'r')
		{
			return ability = minorWeaponAbility(w1, bonus);
		}
		else
			return ability = "";
	}
	else if((92 <= d100) && (d100 <= 95))
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			return ability = "Thundering";	
		}
		else
			return ability = "";
	}
	else if((96 <= d100) && (d100 <= 99))
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			return ability = "Vicious";	
		}
		else
			return ability = "";
	}
	else if(d100 == 100)
	{
		string ability2 = minorWeaponAbility(w1, bonus);
		return ability = ability + " " + ability2;
	}
	else if((101 <= d100) && (d100 <= 113))
	{
		if(((bonus+1) <= 10) && ((w1.range == 'r') || (w1.throwing == true)))
		{
			bonus++;
			return ability = "Distance";
		}
		else if(w1.range == 'm')
		{
			return ability = minorWeaponAbility(w1, bonus);
		}
		else
			return ability = "";
	}
	else if((114 <= d100) && (d100 <= 121))
	{
		if(((bonus+1) <= 10) && (w1.throwing == true))
		{
			bonus++;
			return ability = "Returning";
		}
		else if(w1.throwing == false)
		{
			return ability = minorWeaponAbility(w1, bonus);
		}
		else
			return ability = "";
	}
	else
	{
		if(((bonus+1) <= 10) && ((w1.range == 'r') || (w1.throwing == true)))
		{
			bonus++;
			return ability = "Seeking";
		}
		else if(w1.range == 'm')
		{
			return ability = minorWeaponAbility(w1, bonus);
		}
		else
			return ability = "";
	}
}
string mediumWeaponAbility(Weapon w1, int bonus)
{
	int d100;
	string ability;
	d100=rand()%117+1;
	if((1 <= d100) && (d100 <= 6))
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			d100=rand()%100+1;
			if((1 <= d100) && (d100 <= 5))
				return ability = "Aberration Bane";
			else if((6 <= d100) && (d100 <= 9))
				return ability = "Animal Bane";
			else if((10 <= d100) && (d100 <= 16))
				return ability = "Construct Bane";
			else if((17 <= d100) && (d100 <= 22))
				return ability = "Dragon Bane";
			else if((23 <= d100) && (d100 <= 27))
				return ability = "Elemental Bane";
			else if((28 <= d100) && (d100 <= 32))
				return ability = "Fey Bane";
			else if((33 <= d100) && (d100 <= 39))
				return ability = "Giant Bane";
			else if(d100 == 40)
				return ability = "Aquatic Humanoid Bane";
			else if((41 <= d100) && (d100 <= 42))
				return ability = "Dwarf Bane";
			else if((43 <= d100) && (d100 <= 44))
				return ability = "Elf Bane";
			else if(d100 == 45)
				return ability = "Gnoll Bane";
			else if(d100 == 46)
				return ability = "Gnome Bane";
			else if((47 <= d100) && (d100 <= 49))
				return ability = "Goblinoid Bane";
			else if(d100 == 50)
				return ability = "Halfling Bane";
			else if((51 <= d100) && (d100 <= 54))
				return ability = "Human Bane";
			else if((55 <= d100) && (d100 <= 57))
				return ability = "Reptilian Humanoid Bane";
			else if((58 <= d100) && (d100 <= 60))
				return ability = "Orc Bane";
			else if((61 <= d100) && (d100 <= 65))
				return ability = "Magical Beast Bane";
			else if((66 <= d100) && (d100 <= 70))
				return ability = "Monstrous Humanoid Bane";
			else if((71 <= d100) && (d100 <= 72))
				return ability = "Ooze Bane";
			else if(d100 == 73)
				return ability = "Air Outsider Bane";
			else if((74 <= d100) && (d100 <= 76))
				return ability = "Chaotic Outsider Bane";
			else if(d100 == 77)
				return ability = "Earth Outsider Bane";
			else if((78 <= d100) && (d100 <= 80))
				return ability = "Evil Outsider Bane";
			else if(d100 == 81)
				return ability = "Fire Outsider Bane";
			else if((82 <= d100) && (d100 <= 84))
				return ability = "Good Outsider Bane";
			else if((85 <= d100) && (d100 <= 87))
				return ability = "Lawful Outsider Bane";
			else if(d100 == 88)
				return ability = "Water Outsider Bane";
			else if((89 <= d100) && (d100 <= 90))
				return ability = "Plant Bane";
			else if((91 <= d100) && (d100 <= 98))
				return ability = "Undead Bane";
			else
				return ability = "Vermin Bane";
		}
		else
			return ability = "";
	}
	else if((7 <= d100) && (d100 <= 12))
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			return ability = "Defending";	
		}
		else
			return ability = "";
	}
	else if((13 <= d100) && (d100 <= 19))
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			return ability = "Flaming";	
		}
		else
			return ability = "";
	}
	else if((20 <= d100) && (d100 <= 26))
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			return ability = "Frost";	
		}
		else
			return ability = "";
	}
	else if((27 <= d100) && (d100 <= 33))
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			return ability = "Shocking";	
		}
		else
			return ability = "";
	}
	else if((34 <= d100) && (d100 <= 38))
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			return ability = "Ghost Touch";	
		}
		else
			return ability = "";
	}
	else if((39 <= d100) && (d100 <= 44))
	{
		if(((bonus+1) <= 10) && (w1.type != 'b'))
		{
			bonus++;
			return ability = "Keen";	
		}
		else if(w1.type == 'b')
		{
			return ability = mediumWeaponAbility(w1, bonus);
		}
		else
			return ability = "";
	}
	else if((45 <= d100) && (d100 <= 48))
	{
		if(((bonus+1) <= 10) && (w1.range == 'm'))
		{
			bonus++;
			return ability = "Ki Focus";	
		}
		else if(w1.range == 'r')
		{
			return ability = mediumWeaponAbility(w1, bonus);
		}
		else
			return ability = "";
	}
	else if((49 <= d100) && (d100 <= 50))
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			return ability = "Merciful";	
		}
		else
			return ability = "";
	}
	else if((51 <= d100) && (d100 <= 54))
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			return ability = "Mighty Cleaving";	
		}
		else
			return ability = "";
	}
	else if((55 <= d100) && (d100 <= 59))
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			return ability = "Spell Storing";	
		}
		else
			return ability = "";
	}
	else if((60 <= d100) && (d100 <= 63))
	{
		if(((bonus+1) <= 10) && (w1.range == 'm'))
		{
			bonus++;
			return ability = "Throwing";	
		}
		else if(w1.range == 'r')
		{
			return ability = mediumWeaponAbility(w1, bonus);
		}
		else
			return ability = "";
	}
	else if((64 <= d100) && (d100 <= 65))
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			return ability = "Thundering";	
		}
		else
			return ability = "";
	}
	else if((66 <= d100) && (d100 <= 69))
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			return ability = "Vicious";	
		}
		else
			return ability = "";
	}
	else if((70 <= d100) && (d100 <= 72))
	{
		if((bonus+2) <= 10)
		{
			bonus+=2;
			return ability = "Anarchic";	
		}
		else
			return ability = "";
	}
	else if((73 <= d100) && (d100 <= 75))
	{
		if((bonus+2) <= 10)
		{
			bonus+=2;
			return ability = "Axiomatic";	
		}
		else
			return ability = "";
	}
	else if((76 <= d100) && (d100 <= 78))
	{
		if(((bonus+2) <= 10) && (w1.type == 'b'))
		{
			bonus+=2;
			return ability = "Disruption";	
		}
		else if(w1.type != 'b')
		{
			return ability = mediumWeaponAbility(w1, bonus);
		}
		else
			return ability = "";
	}
	else if((79 <= d100) && (d100 <= 81))
	{
		if((bonus+2) <= 10)
		{
			bonus+=2;
			return ability = "Flaming Burst";	
		}
		else
			return ability = "";
	}
	else if((82 <= d100) && (d100 <= 84))
	{
		if((bonus+2) <= 10)
		{
			bonus+=2;
			return ability = "Icy Burst";	
		}
		else
			return ability = "";
	}
	else if((85 <= d100) && (d100 <= 87))
	{
		if((bonus+2) <= 10)
		{
			bonus+=2;
			return ability = "Holy";	
		}
		else
			return ability = "";
	}
	else if((88 <= d100) && (d100 <= 90))
	{
		if((bonus+2) <= 10)
		{
			bonus+=2;
			return ability = "Shocking Burst";	
		}
		else
			return ability = "";
	}
	else if((91 <= d100) && (d100 <= 93))
	{
		if((bonus+2) <= 10)
		{
			bonus+=2;
			return ability = "Unholy";	
		}
		else
			return ability = "";
	}
	else if((94 <= d100) && (d100 <= 95))
	{
		if((bonus+2) <= 10)
		{
			bonus+=2;
			return ability = "Wounding";	
		}
		else
			return ability = "";
	}
	else if(d100 == 100)
	{
		string ability2 = mediumWeaponAbility(w1, bonus);
		return ability = ability + " " + ability2;
	}
	else if((101 <= d100) && (d100 <= 108))
	{
		if(((bonus+1) <= 10) && ((w1.range == 'r') || (w1.throwing == true)))
		{
			bonus++;
			return ability = "Distance";
		}
		else if(w1.range == 'm')
		{
			return ability = mediumWeaponAbility(w1, bonus);
		}
		else
			return ability = "";
	}
	else if((109 <= d100) && (d100 <= 113))
	{
		if(((bonus+1) <= 10) && (w1.throwing == true))
		{
			bonus++;
			return ability = "Returning";
		}
		else if(w1.throwing == false)
		{
			return ability = mediumWeaponAbility(w1, bonus);
		}
		else
			return ability = "";
	}
	else
	{
		if(((bonus+1) <= 10) && ((w1.range == 'r') || (w1.throwing == true)))
		{
			bonus++;
			return ability = "Seeking";
		}
		else if(w1.range == 'm')
		{
			return ability = mediumWeaponAbility(w1, bonus);
		}
		else
			return ability = "";
	}
}
string majorWeaponAbility(Weapon w1, int bonus)
{
	int d100;
	string ability;
	d100=rand()%111+1;
	if((1 <= d100) && (d100 <= 3))
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			d100=rand()%100+1;
			if((1 <= d100) && (d100 <= 5))
				return ability = "Aberration Bane";
			else if((6 <= d100) && (d100 <= 9))
				return ability = "Animal Bane";
			else if((10 <= d100) && (d100 <= 16))
				return ability = "Construct Bane";
			else if((17 <= d100) && (d100 <= 22))
				return ability = "Dragon Bane";
			else if((23 <= d100) && (d100 <= 27))
				return ability = "Elemental Bane";
			else if((28 <= d100) && (d100 <= 32))
				return ability = "Fey Bane";
			else if((33 <= d100) && (d100 <= 39))
				return ability = "Giant Bane";
			else if(d100 == 40)
				return ability = "Aquatic Humanoid Bane";
			else if((41 <= d100) && (d100 <= 42))
				return ability = "Dwarf Bane";
			else if((43 <= d100) && (d100 <= 44))
				return ability = "Elf Bane";
			else if(d100 == 45)
				return ability = "Gnoll Bane";
			else if(d100 == 46)
				return ability = "Gnome Bane";
			else if((47 <= d100) && (d100 <= 49))
				return ability = "Goblinoid Bane";
			else if(d100 == 50)
				return ability = "Halfling Bane";
			else if((51 <= d100) && (d100 <= 54))
				return ability = "Human Bane";
			else if((55 <= d100) && (d100 <= 57))
				return ability = "Reptilian Humanoid Bane";
			else if((58 <= d100) && (d100 <= 60))
				return ability = "Orc Bane";
			else if((61 <= d100) && (d100 <= 65))
				return ability = "Magical Beast Bane";
			else if((66 <= d100) && (d100 <= 70))
				return ability = "Monstrous Humanoid Bane";
			else if((71 <= d100) && (d100 <= 72))
				return ability = "Ooze Bane";
			else if(d100 == 73)
				return ability = "Air Outsider Bane";
			else if((74 <= d100) && (d100 <= 76))
				return ability = "Chaotic Outsider Bane";
			else if(d100 == 77)
				return ability = "Earth Outsider Bane";
			else if((78 <= d100) && (d100 <= 80))
				return ability = "Evil Outsider Bane";
			else if(d100 == 81)
				return ability = "Fire Outsider Bane";
			else if((82 <= d100) && (d100 <= 84))
				return ability = "Good Outsider Bane";
			else if((85 <= d100) && (d100 <= 87))
				return ability = "Lawful Outsider Bane";
			else if(d100 == 88)
				return ability = "Water Outsider Bane";
			else if((89 <= d100) && (d100 <= 90))
				return ability = "Plant Bane";
			else if((91 <= d100) && (d100 <= 98))
				return ability = "Undead Bane";
			else
				return ability = "Vermin Bane";
		}
		else
			return ability = "";
	}
	else if((4 <= d100) && (d100 <= 6))
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			return ability = "Flaming";	
		}
		else
			return ability = "";
	}
	else if((7 <= d100) && (d100 <= 9))
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			return ability = "Frost";	
		}
		else
			return ability = "";
	}
	else if((10 <= d100) && (d100 <= 12))
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			return ability = "Shocking";	
		}
		else
			return ability = "";
	}
	else if((13 <= d100) && (d100 <= 15))
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			return ability = "Ghost Touch";	
		}
		else
			return ability = "";
	}
	else if((16 <= d100) && (d100 <= 19))
	{
		if(((bonus+1) <= 10) && (w1.range == 'm'))
		{
			bonus++;
			return ability = "Ki Focus";	
		}
		else if(w1.range == 'r')
		{
			return ability = majorWeaponAbility(w1, bonus);
		}
		else
			return ability = "";
	}
	else if((20 <= d100) && (d100 <= 21))
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			return ability = "Mighty Cleaving";	
		}
		else
			return ability = "";
	}
	else if((22 <= d100) && (d100 <= 24))
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			return ability = "Spell Storing";	
		}
		else
			return ability = "";
	}
	else if((25 <= d100) && (d100 <= 28))
	{
		if(((bonus+1) <= 10) && (w1.range == 'm'))
		{
			bonus++;
			return ability = "Throwing";	
		}
		else if(w1.range == 'r')
		{
			return ability = majorWeaponAbility(w1, bonus);
		}
		else
			return ability = "";
	}
	else if((29 <= d100) && (d100 <= 32))
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			return ability = "Thundering";	
		}
		else
			return ability = "";
	}
	else if((33 <= d100) && (d100 <= 36))
	{
		if((bonus+1) <= 10)
		{
			bonus++;
			return ability = "Vicious";	
		}
		else
			return ability = "";
	}
	else if((37 <= d100) && (d100 <= 41))
	{
		if((bonus+2) <= 10)
		{
			bonus+=2;
			return ability = "Anarchic";	
		}
		else
			return ability = "";
	}
	else if((42 <= d100) && (d100 <= 46))
	{
		if((bonus+2) <= 10)
		{
			bonus+=2;
			return ability = "Axiomatic";	
		}
		else
			return ability = "";
	}
	else if((47 <= d100) && (d100 <= 49))
	{
		if(((bonus+2) <= 10) && (w1.type == 'b'))
		{
			bonus+=2;
			return ability = "Disruption";	
		}
		else if(w1.type != 'b')
		{
			return ability = majorWeaponAbility(w1, bonus);
		}
		else
			return ability = "";
	}
	else if((50 <= d100) && (d100 <= 54))
	{
		if((bonus+2) <= 10)
		{
			bonus+=2;
			return ability = "Flaming Burst";	
		}
		else
			return ability = "";
	}
	else if((55 <= d100) && (d100 <= 59))
	{
		if((bonus+2) <= 10)
		{
			bonus+=2;
			return ability = "Icy Burst";	
		}
		else
			return ability = "";
	}
	else if((60 <= d100) && (d100 <= 64))
	{
		if((bonus+2) <= 10)
		{
			bonus+=2;
			return ability = "Holy";	
		}
		else
			return ability = "";
	}
	else if((65 <= d100) && (d100 <= 69))
	{
		if((bonus+2) <= 10)
		{
			bonus+=2;
			return ability = "Shocking Burst";	
		}
		else
			return ability = "";
	}
	else if((70 <= d100) && (d100 <= 74))
	{
		if((bonus+2) <= 10)
		{
			bonus+=2;
			return ability = "Unholy";	
		}
		else
			return ability = "";
	}
	else if((75 <= d100) && (d100 <= 78))
	{
		if((bonus+2) <= 10)
		{
			bonus+=2;
			return ability = "Wounding";	
		}
		else
			return ability = "";
	}
	else if((79 <= d100) && (d100 <= 83))
	{
		if((bonus+3) <= 10)
		{
			bonus+=3;
			return ability = "Speed";	
		}
		else
			return ability = "";
	}
	else if((84 <= d100) && (d100 <= 86))
	{
		if((bonus+4) <= 10)
		{
			bonus+=4;
			return ability = "Brilliant Energy";	
		}
		else
			return ability = "";
	}
	else if((87 <= d100) && (d100 <= 88))
	{
		if((bonus+4) <= 10)
		{
			bonus+=4;
			return ability = "Dancing";	
		}
		else
			return ability = "";
	}
	else if((89 <= d100) && (d100 <= 90))
	{
		if(((bonus+5) <= 10) && (w1.type == 's'))
		{
			bonus+=5;
			return ability = "Vorpal";	
		}
		else if(w1.type != 's')
		{
			return ability = majorWeaponAbility(w1, bonus);
		}
		else
			return ability = "";
	}
	else if(d100 == 100)
	{
		string ability2 = majorWeaponAbility(w1, bonus);
		return ability = ability + " " + ability2;
	}
	else if((101 <= d100) && (d100 <= 104))
	{
		if(((bonus+1) <= 10) && ((w1.range == 'r') || (w1.throwing == true)))
		{
			bonus++;
			return ability = "Distance";
		}
		else if(w1.range == 'm')
		{
			return ability = majorWeaponAbility(w1, bonus);
		}
		else
			return ability = "";
	}
	else if((105 <= d100) && (d100 <= 109))
	{
		if(((bonus+1) <= 10) && (w1.throwing == true))
		{
			bonus++;
			return ability = "Returning";
		}
		else if(w1.throwing == false)
		{
			return ability = majorWeaponAbility(w1, bonus);
		}
		else
			return ability = "";
	}
	else
	{
		if(((bonus+1) <= 10) && ((w1.range == 'r') || (w1.throwing == true)))
		{
			bonus++;
			return ability = "Seeking";
		}
		else if(w1.range == 'm')
		{
			return ability = majorWeaponAbility(w1, bonus);
		}
		else
			return ability = "";
	}
}

void minorPotion()
{
	int d100;
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 10))
	{
		cout << "Potion of Cure Light Wounds" << endl;
	}
	else if((11 <= d100) && (d100 <= 13))
	{
		cout << "Potion of Endure Elements" << endl;
	}
	else if((14 <= d100) && (d100 <= 15))
	{
		cout << "Potion of Hide from Animals" << endl;
	}
	else if((16 <= d100) && (d100 <= 17))
	{
		cout << "Potion of Hide from Undead" << endl;
	}
	else if((18 <= d100) && (d100 <= 19))
	{
		cout << "Potion of Jump" << endl;
	}
	else if((20 <= d100) && (d100 <= 22))
	{
		cout << "Potion of Mage Armor" << endl;
	}
	else if((23 <= d100) && (d100 <= 25))
	{
		cout << "Potion of Magic Fang" << endl;
	}
	else if(d100 == 26)
	{
		cout << "Oil of Magic Stone" << endl;
	}
	else if((27 <= d100) && (d100 <= 29))
	{
		cout << "Oil of Magic Weapon" << endl;
	}
	else if(d100 == 30)
	{
		cout << "Potion of Pass Without Trace" << endl;
	}
	else if((31 <= d100) && (d100 <= 32))
	{
		int d4=rand()%4+1;
		if(d4 == 1)
		{
			cout << "Potion of Protection from Good" << endl;
		}
		else if(d4 == 2)
		{
			cout << "Potion of Protection from Evil" << endl;
		}
		else if(d4 == 3)
		{
			cout << "Potion of Protection from Law" << endl;
		}
		else
		{
			cout << "Potion of Protection from Chaos" << endl;
		}
	}
	else if((33 <= d100) && (d100 <= 34))
	{
		cout << "Potion of Remove Fear" << endl;
	}
	else if(d100 == 35)
	{
		cout << "Potion of Sanctuary" << endl;
	}
	else if((36 <= d100) && (d100 <= 38))
	{
		cout << "Potion of Shield of Faith +2" << endl;
	}
	else if(d100 == 39)
	{
		cout << "Potion of Shillelagh" << endl;
	}
	else if((40 <= d100) && (d100 <= 41))
	{
		cout << "Oil of Bless Weapon" << endl;
	}
	else if((42 <= d100) && (d100 <= 44))
	{
		cout << "Potion of Enlarge Person" << endl;
	}
	else if(d100 == 45)
	{
		cout << "Potion of Reduce Person" << endl;
	}
	else if((46 <= d100) && (d100 <= 47))
	{
		cout << "Potion of Aid" << endl;
	}
	else if((48 <= d100) && (d100 <= 50))
	{
		cout << "Potion of Barkskin +2" << endl;
	}
	else if((51 <= d100) && (d100 <= 53))
	{
		cout << "Potion of Bear's Endurance" << endl;
	}
	else if((54 <= d100) && (d100 <= 56))
	{
		cout << "Potion of Blur" << endl;
	}
	else if((57 <= d100) && (d100 <= 59))
	{
		cout << "Potion of Bull's Strength" << endl;
	}
	else if((60 <= d100) && (d100 <= 62))
	{
		cout << "Potion of Cat's Grace" << endl;
	}
	else if((63 <= d100) && (d100 <= 67))
	{
		cout << "Potion of Cure Moderate Wounds" << endl;
	}
	else if(d100 == 68)
	{
		cout << "Oil of Darkness" << endl;
	}
	else if((69 <= d100) && (d100 <= 71))
	{
		cout << "Potion of Darkvision" << endl;
	}
	else if((72 <= d100) && (d100 <= 74))
	{
		cout << "Potion of Delay Poison" << endl;
	}
	else if((75 <= d100) && (d100 <= 76))
	{
		cout << "Potion of Eagle's Splendor" << endl;
	}
	else if((77 <= d100) && (d100 <= 78))
	{
		cout << "Potion of Fox's Cunning" << endl;
	}
	else if((79 <= d100) && (d100 <= 80))
	{
		cout << "Potion of Invisibility" << endl;
	}
	else if(d100 == 81)
	{
		cout << "Oil of Invisibility" << endl;
	}
	else if((82 <= d100) && (d100 <= 84))
	{
		cout << "Potion of Lesser Restoration" << endl;
	}
	else if(d100 == 85)
	{
		cout << "Potion of Levitate" << endl;
	}
	else if(d100 == 86)
	{
		cout << "Oil of Levitate" << endl;
	}
	else if(d100 == 87)
	{
		cout << "Potion of Misdirection" << endl;
	}
	else if((88 <= d100) && (d100 <= 89))
	{
		cout << "Potion of Owl's Wisdom" << endl;
	}
	else if((90 <= d100) && (d100 <= 91))
	{
		cout << "Potion of Protection from Arrows (10/magic)" << endl;
	}
	else if((92 <= d100) && (d100 <= 93))
	{
		cout << "Potion of Remove Paralysis" << endl;
	}
	else if((94 <= d100) && (d100 <= 96))
	{
		int d4=rand()%4+1;
		if(d4 == 1)
		{
			cout << "Potion of Resist Fire 10" << endl;
		}
		else if(d4 == 2)
		{
			cout << "Potion of Resist Cold 10" << endl;
		}
		else if(d4 == 3)
		{
			cout << "Potion of Resist Electricity 10" << endl;
		}
		else
		{
			cout << "Potion of Resist Sonic 10" << endl;
		}
	}
	else if(d100 == 97)
	{
		cout << "Potion of Shield of Faith +3" << endl;
	}
	else if((98 <= d100) && (d100 <= 99))
	{
		cout << "Potion of Spider Climb" << endl;
	}
	else
	{
		cout << "Potion of Undetectable Alignment" << endl;
	}
}
void mediumPotion()
{
	int d100;
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 2))
	{
		cout << "Oil of Bless Weapon" << endl;
	}
	else if((3 <= d100) && (d100 <= 4))
	{
		cout << "Potion of Enlarge Person" << endl;
	}
	else if(d100 == 5)
	{
		cout << "Potion of Reduce Person" << endl;
	}
	else if(d100 == 6)
	{
		cout << "Potion of Aid" << endl;
	}
	else if(d100 == 7)
	{
		cout << "Potion of Barkskin +2" << endl;
	}
	else if((8 <= d100) && (d100 <= 10))
	{
		cout << "Potion of Bear's Endurance" << endl;
	}
	else if((11 <= d100) && (d100 <= 13))
	{
		cout << "Potion of Blur" << endl;
	}
	else if((14 <= d100) && (d100 <= 16))
	{
		cout << "Potion of Bull's Strength" << endl;
	}
	else if((17 <= d100) && (d100 <= 19))
	{
		cout << "Potion of Cat's Grace" << endl;
	}
	else if((20 <= d100) && (d100 <= 27))
	{
		cout << "Potion of Cure Moderate Wounds" << endl;
	}
	else if(d100 == 28)
	{
		cout << "Oil of Darkness" << endl;
	}
	else if((29 <= d100) && (d100 <= 30))
	{
		cout << "Potion of Darkvision" << endl;
	}
	else if(d100 == 31)
	{
		cout << "Potion of Delay Poison" << endl;
	}
	else if((32 <= d100) && (d100 <= 33))
	{
		cout << "Potion of Eagle's Splendor" << endl;
	}
	else if((34 <= d100) && (d100 <= 35))
	{
		cout << "Potion of Fox's Cunning" << endl;
	}
	else if(d100 == 36)
	{
		cout << "Potion of Invisibility" << endl;
	}
	else if(d100 == 37)
	{
		cout << "Oil of Invisibility" << endl;
	}
	else if(d100 == 38)
	{
		cout << "Potion of Lesser Restoration" << endl;
	}
	else if(d100 == 39)
	{
		int d2 = rand()%2+1;
		if(d2 == 1)
			cout << "Potion of Levitate" << endl;
		else
			cout << "Oil of Levitate" << endl;
	}
	else if(d100 == 40)
	{
		cout << "Potion of Misdirection" << endl;
	}
	else if((41 <= d100) && (d100 <= 42))
	{
		cout << "Potion of Owl's Wisdom" << endl;
	}
	else if(d100 == 43)
	{
		cout << "Potion of Protection from Arrows (10/magic)" << endl;
	}
	else if(d100 == 44)
	{
		cout << "Potion of Remove Paralysis" << endl;
	}
	else if((45 <= d100) && (d100 <= 46))
	{
		int d4=rand()%4+1;
		if(d4 == 1)
		{
			cout << "Potion of Resist Fire 10" << endl;
		}
		else if(d4 == 2)
		{
			cout << "Potion of Resist Cold 10" << endl;
		}
		else if(d4 == 3)
		{
			cout << "Potion of Resist Electricity 10" << endl;
		}
		else
		{
			cout << "Potion of Resist Sonic 10" << endl;
		}
	}
	else if((47 <= d100) && (d100 <= 48))
	{
		cout << "Potion of Shield of Faith +3" << endl;
	}
	else if(d100 == 49)
	{
		cout << "Potion of Spider Climb" << endl;
	}
	else if(d100 == 50)
	{
		cout << "Potion of Undetectable Alignment" << endl;
	}
	else if(d100 == 51)
	{
		cout << "Potion of Barkskin +3" << endl;
	}
	else if(d100 == 52)
	{
		cout << "Potion of Shield of Faith +4" << endl;
	}
	else if((53 <= d100) && (d100 <= 55))
	{
		int d4=rand()%4+1;
		if(d4 == 1)
		{
			cout << "Potion of Resist Fire 20" << endl;
		}
		else if(d4 == 2)
		{
			cout << "Potion of Resist Cold 20" << endl;
		}
		else if(d4 == 3)
		{
			cout << "Potion of Resist Electricity 20" << endl;
		}
		else
		{
			cout << "Potion of Resist Sonic 20" << endl;
		}
	}
	else if((56 <= d100) && (d100 <= 60))
	{
		cout << "Potion of Cure Serious Wounds" << endl;
	}
	else if(d100 == 61)
	{
		cout << "Oil of Daylight" << endl;
	}
	else if((62 <= d100) && (d100 <= 64))
	{
		cout << "Potion of Displacement" << endl;
	}
	else if(d100 == 65)
	{
		cout << "Oil of Flame Arrow" << endl;
	}
	else if((66 <= d100) && (d100 <= 68))
	{
		cout << "Potion of Fly" << endl;
	}
	else if(d100 == 69)
	{
		cout << "Potion of Gaseous Form" << endl;
	}
	else if((70 <= d100) && (d100 <= 71))
	{
		cout << "Potion of Greater Magic Fang +1" << endl;
	}
	else if((72 <= d100) && (d100 <= 73))
	{
		cout << "Oil of Greater Magic Weapon +1" << endl;
	}
	else if((74 <= d100) && (d100 <= 75))
	{
		cout << "Potion of Haste" << endl;
	}
	else if((76 <= d100) && (d100 <= 78))
	{
		cout << "Potion of Heroism" << endl;
	}
	else if((79 <= d100) && (d100 <= 80))
	{
		cout << "Oil of Keen Edge" << endl;
	}
	else if(d100 == 81)
	{
		int d4=rand()%4+1;
		if(d4 == 1)
		{
			cout << "Potion of Magic Circle Against Good" << endl;
		}
		else if(d4 == 2)
		{
			cout << "Potion of Magic Circle Against Evil" << endl;
		}
		else if(d4 == 3)
		{
			cout << "Potion of Magic Circle Against Law" << endl;
		}
		else
		{
			cout << "Potion of Magic Circle Against Chaos" << endl;
		}
	}
	else if((82 <= d100) && (d100 <= 83))
	{
		cout << "Oil of Magic Vestment +1" << endl;
	}
	else if((84 <= d100) && (d100 <= 86))
	{
		cout << "Potion of Neutralize Poison" << endl;
	}
	else if((87 <= d100) && (d100 <= 88))
	{
		cout << "Potion of Nondetection" << endl;
	}
	else if((89 <= d100) && (d100 <= 91))
	{
		int d4=rand()%4+1;
		if(d4 == 1)
		{
			cout << "Potion of Protection from Energy (Fire)" << endl;
		}
		else if(d4 == 2)
		{
			cout << "Potion of Protection from Energy (Cold)" << endl;
		}
		else if(d4 == 3)
		{
			cout << "Potion of Protection from Energy (Electricity)" << endl;
		}
		else
		{
			cout << "Potion of Protection from Energy (Sonic)" << endl;
		}
	}
	else if((92 <= d100) && (d100 <= 93))
	{
		cout << "Potion of Rage" << endl;
	}
	else if(d100 == 94)
	{
		cout << "Potion of Remove Blindness/Deafness" << endl;
	}
	else if(d100 == 95)
	{
		cout << "Potion of Remove Curse" << endl;
	}
	else if(d100 == 96)
	{
		cout << "Potion of Remove Disease" << endl;
	}
	else if(d100 == 97)
	{
		cout << "Potion of Tongues" << endl;
	}
	else if((98 <= d100) && (d100 <= 99))
	{
		cout << "Potion of Water Breathing" << endl;
	}
	else
	{
		cout << "Potion of Water Walk" << endl;
	}
}
void majorPotion()
{
	int d100;
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 2))
	{
		cout << "Potion of Blur" << endl;
	}
	else if((3 <= d100) && (d100 <= 7))
	{
		cout << "Potion of Cure Moderate Wounds" << endl;
	}
	else if((8 <= d100) && (d100 <= 9))
	{
		cout << "Potion of Darkvision" << endl;
	}
	else if(d100 == 10)
	{
		cout << "Potion of Invisibility" << endl;
	}
	else if(d100 == 11)
	{
		cout << "Oil of Invisibility" << endl;
	}
	else if(d100 == 12)
	{
		cout << "Potion of Lesser Restoration" << endl;
	}
	else if(d100 == 13)
	{
		cout << "Potion of Remove Paralysis" << endl;
	}
	else if(d100 == 14)
	{
		cout << "Potion of Shield of Faith +3" << endl;
	}
	else if(d100 == 15)
	{
		cout << "Potion of Undetectable Alignment" << endl;
	}
	else if(d100 == 16)
	{
		cout << "Potion of Barkskin +3" << endl;
	}
	else if((17 <= d100) && (d100 <= 18))
	{
		cout << "Potion of Shield of Faith +4" << endl;
	}
	else if((19 <= d100) && (d100 <= 20))
	{
		int d4=rand()%4+1;
		if(d4 == 1)
		{
			cout << "Potion of Resist Fire 20" << endl;
		}
		else if(d4 == 2)
		{
			cout << "Potion of Resist Cold 20" << endl;
		}
		else if(d4 == 3)
		{
			cout << "Potion of Resist Electricity 20" << endl;
		}
		else
		{
			cout << "Potion of Resist Sonic 20" << endl;
		}
	}
	else if((21 <= d100) && (d100 <= 28))
	{
		cout << "Potion of Cure Serious Wounds" << endl;
	}
	else if(d100 == 29)
	{
		cout << "Oil of Daylight" << endl;
	}
	else if((30 <= d100) && (d100 <= 32))
	{
		cout << "Potion of Displacement" << endl;
	}
	else if(d100 == 33)
	{
		cout << "Oil of Flame Arrow" << endl;
	}
	else if((34 <= d100) && (d100 <= 38))
	{
		cout << "Potion of Flight" << endl;
	}
	else if(d100 == 39)
	{
		cout << "Potion of Gaseous Form" << endl;
	}
	else if((40 <= d100) && (d100 <= 41))
	{
		cout << "Potion of Haste" << endl;
	}
	else if((42 <= d100) && (d100 <= 44))
	{
		cout << "Potion of Heroism" << endl;
	}
	else if((45 <= d100) && (d100 <= 46))
	{
		cout << "Oil of Keen Edge" << endl;
	}
	else if(d100 == 47)
	{
		int d4=rand()%4+1;
		if(d4 == 1)
		{
			cout << "Potion of Magic Circle Against Good" << endl;
		}
		else if(d4 == 2)
		{
			cout << "Potion of Magic Circle Against Evil" << endl;
		}
		else if(d4 == 3)
		{
			cout << "Potion of Magic Circle Against Law" << endl;
		}
		else
		{
			cout << "Potion of Magic Circle Against Chaos" << endl;
		}
	}
	else if((48 <= d100) && (d100 <= 50))
	{
		cout << "Potion of Neutralize Poison" << endl;
	}
	else if((51 <= d100) && (d100 <= 52))
	{
		cout << "Potion of Nondetection" << endl;
	}
	else if((53 <= d100) && (d100 <= 54))
	{
		int d4=rand()%4+1;
		if(d4 == 1)
		{
			cout << "Potion of Protection from Energy (Fire)" << endl;
		}
		else if(d4 == 2)
		{
			cout << "Potion of Protection from Energy (Cold)" << endl;
		}
		else if(d4 == 3)
		{
			cout << "Potion of Protection from Energy (Electricity)" << endl;
		}
		else
		{
			cout << "Potion of Protection from Energy (Sonic)" << endl;
		}
	}
	else if(d100 == 55)
	{
		cout << "Potion of Rage" << endl;
	}
	else if(d100 == 56)
	{
		cout << "Potion of Remove Blindness/Deafness" << endl;
	}
	else if(d100 == 57)
	{
		cout << "Potion of Remove Curse" << endl;
	}
	else if(d100 == 58)
	{
		cout << "Potion of Remove Disease" << endl;
	}
	else if(d100 == 59)
	{
		cout << "Potion of Tongues" << endl;
	}
	else if(d100 == 60)
	{
		cout << "Potion of Water Breathing" << endl;
	}
	else if(d100 == 61)
	{
		cout << "Potion of Water Walk" << endl;
	}
	else if((62 <= d100) && (d100 <= 63))
	{
		cout << "Potion of Barkskin +4" << endl;
	}
	else if(d100 == 64)
	{
		cout << "Potion of Shield of Faith +5" << endl;
	}
	else if(d100 == 65)
	{
		cout << "Potion of Good Hope" << endl;
	}
	else if((66 <= d100) && (d100 <= 68))
	{
		int d4=rand()%4+1;
		if(d4 == 1)
		{
			cout << "Potion of Resist Fire 30" << endl;
		}
		else if(d4 == 2)
		{
			cout << "Potion of Resist Cold 30" << endl;
		}
		else if(d4 == 3)
		{
			cout << "Potion of Resist Electricity 30" << endl;
		}
		else
		{
			cout << "Potion of Resist Sonic 30" << endl;
		}
	}
	else if(d100 == 69)
	{
		cout << "Potion of Barkskin +5" << endl;
	}
	else if((70 <= d100) && (d100 <= 73))
	{
		cout << "Potion of Greater Magic Fang +2" << endl;
	}
	else if((74 <= d100) && (d100 <= 77))
	{
		cout << "Potion of Greater Magic Weapon +2" << endl;
	}
	else if((78 <= d100) && (d100 <= 81))
	{
		cout << "Oil of Magic Vestment +2" << endl;
	}
	else if(d100 == 82)
	{
		cout << "Protection from Arrows 15/magic" << endl;
	}
	else if((83 <= d100) && (d100 <= 85))
	{
		cout << "Potion of Greater Magic Fang +3" << endl;
	}
	else if((86 <= d100) && (d100 <= 88))
	{
		cout << "Potion of Greater Magic Weapon +3" << endl;
	}
	else if((89 <= d100) && (d100 <= 91))
	{
		cout << "Oil of Magic Vestment +3" << endl;
	}
	else if((92 <= d100) && (d100 <= 93))
	{
		cout << "Potion of Greater Magic Fang +4" << endl;
	}
	else if((94 <= d100) && (d100 <= 95))
	{
		cout << "Potion of Greater Magic Weapon +4" << endl;
	}
	else if((96 <= d100) && (d100 <= 97))
	{
		cout << "Oil of Magic Vestment +4" << endl;
	}
	else if(d100 == 98)
	{
		cout << "Potion of Greater Magic Fang +5" << endl;
	}
	else if(d100 == 99)
	{
		cout << "Potion of Greater Magic Weapon +5" << endl;
	}
	else
	{
		cout << "Oil of Magic Vestment +5" << endl;
	}
}

void minorRing()
{
	int d100;
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 18))
	{
		cout << "Ring of Protection +1" << endl;
	}
	else if((19 <= d100) && (d100 <= 28))
	{
		cout << "Ring of Feather Falling" << endl;
	}
	else if((29 <= d100) && (d100 <= 36))
	{
		cout << "Ring of Sustenance" << endl;
	}
	else if((37 <= d100) && (d100 <= 44))
	{
		cout << "Ring of Climbing" << endl;
	}
	else if((45 <= d100) && (d100 <= 52))
	{
		cout << "Ring of Jumping" << endl;
	}
	else if((53 <= d100) && (d100 <= 60))
	{
		cout << "Ring of Swimming" << endl;
	}
	else if((61 <= d100) && (d100 <= 70))
	{
		cout << "Ring of Counterspells" << endl;
	}
	else if((71 <= d100) && (d100 <= 75))
	{
		cout << "Ring of Mind Shielding" << endl;
	}
	else if((76 <= d100) && (d100 <= 80))
	{
		cout << "Ring of Protection +2" << endl;
	}
	else if((81 <= d100) && (d100 <= 85))
	{
		cout << "Ring of Force Shield" << endl;
	}
	else if((86 <= d100) && (d100 <= 90))
	{
		cout << "Ring of the Ram" << endl;
	}
	else if((91 <= d100) && (d100 <= 93))
	{
		cout << "Ring of Animal Friendship" << endl;
	}
	else if((94 <= d100) && (d100 <= 96))
	{
		cout << "Ring of Minor Energy Resistance" << endl;
	}
	else if((97 <= d100) && (d100 <= 98))
	{
		cout << "Ring of Chameleon Power" << endl;
	}
	else
	{
		cout << "Water Walking" << endl;
	}
}
void mediumRing()
{
	int d100;
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 5))
	{
		cout << "Ring of Counterspells" << endl;
	}
	else if((6 <= d100) && (d100 <= 8))
	{
		cout << "Ring of Mind Shielding" << endl;
	}
	else if((9 <= d100) && (d100 <= 18))
	{
		cout << "Ring of Protection +2" << endl;
	}
	else if((19 <= d100) && (d100 <= 23))
	{
		cout << "Ring of Force Shield" << endl;
	}
	else if((24 <= d100) && (d100 <= 28))
	{
		cout << "Ring of the Ram" << endl;
	}
	else if((29 <= d100) && (d100 <= 34))
	{
		cout << "Ring of Improved Climbing" << endl;
	}
	else if((35 <= d100) && (d100 <= 40))
	{
		cout << "Ring of Improved Jumping" << endl;
	}
	else if((41 <= d100) && (d100 <= 46))
	{
		cout << "Ring of Improved Swimming" << endl;
	}
	else if((47 <= d100) && (d100 <= 51))
	{
		cout << "Ring of Animal Friendship" << endl;
	}
	else if((52 <= d100) && (d100 <= 56))
	{
		cout << "Ring of Minor Energy Resistance" << endl;
	}
	else if((57 <= d100) && (d100 <= 61))
	{
		cout << "Ring of Chameleon Power" << endl;
	}
	else if((62 <= d100) && (d100 <= 66))
	{
		cout << "Ring of Water Walking" << endl;
	}
	else if((67 <= d100) && (d100 <= 71))
	{
		cout << "Ring of Protection +3" << endl;
	}
	else if((72 <= d100) && (d100 <= 76))
	{
		cout << "Ring of Minor Spell Turning" << endl;
	}
	else if((77 <= d100) && (d100 <= 81))
	{
		cout << "Ring of Invisibility" << endl;
	}
	else if((82 <= d100) && (d100 <= 85))
	{
		cout << "Ring of Wizardry I" << endl;
	}
	else if((86 <= d100) && (d100 <= 90))
	{
		cout << "Ring of Evasion" << endl;
	}
	else if((91 <= d100) && (d100 <= 93))
	{
		cout << "Ring of X-Ray Vision" << endl;
	}
	else if((94 <= d100) && (d100 <= 97))
	{
		cout << "Ring of Blinking" << endl;
	}
	else
	{
		cout << "Ring of Major Energy Resistance" << endl;
	}
}
void majorRing()
{
	int d100;
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 2))
	{
		cout << "Ring of Minor Energy Resistance" << endl;
	}
	else if((3 <= d100) && (d100 <= 7))
	{
		cout << "Ring of Protection +3" << endl;
	}
	else if((8 <= d100) && (d100 <= 10))
	{
		cout << "Ring of Minor Spell Storing" << endl;
	}
	else if((11 <= d100) && (d100 <= 15))
	{
		cout << "Ring of Invisibility" << endl;
	}
	else if((16 <= d100) && (d100 <= 19))
	{
		cout << "Ring of Wizardry I" << endl;
	}
	else if((20 <= d100) && (d100 <= 25))
	{
		cout << "Ring of Evasion" << endl;
	}
	else if((26 <= d100) && (d100 <= 28))
	{
		cout << "Ring of X-Ray Vision" << endl;
	}
	else if((29 <= d100) && (d100 <= 32))
	{
		cout << "Ring of Blinking" << endl;
	}
	else if((33 <= d100) && (d100 <= 39))
	{
		cout << "Ring of Major Energy Resistance" << endl;
	}
	else if((40 <= d100) && (d100 <= 49))
	{
		cout << "Ring of Protection +4" << endl;
	}
	else if((50 <= d100) && (d100 <= 55))
	{
		cout << "Ring of Wizardry II" << endl;
	}
	else if((56 <= d100) && (d100 <= 60))
	{
		cout << "Ring of Freedom of Movement" << endl;
	}
	else if((61 <= d100) && (d100 <= 63))
	{
		cout << "Ring of Greater Energy Resistance" << endl;
	}
	else if((64 <= d100) && (d100 <= 65))
	{
		cout << "Ring of Friend Shield (pair)" << endl;
	}
	else if((66 <= d100) && (d100 <= 70))
	{
		cout << "Ring of Protection +5" << endl;
	}
	else if((71 <= d100) && (d100 <= 74))
	{
		cout << "Ring of Shooting Stars" << endl;
	}
	else if((75 <= d100) && (d100 <= 79))
	{
		cout << "Ring of Spell Storing" << endl;
	}
	else if((80 <= d100) && (d100 <= 83))
	{
		cout << "Ring of Wizardry III" << endl;
	}
	else if((84 <= d100) && (d100 <= 86))
	{
		cout << "Ring of Telekinesis" << endl;
	}
	else if((87 <= d100) && (d100 <= 88))
	{
		cout << "Ring of Regeneration" << endl;
	}
	else if(d100 == 89)
	{
		cout << "Ring of Three Wishes" << endl;
	}
	else if((90 <= d100) && (d100 <= 92))
	{
		cout << "Ring of Spell Turning" << endl;
	}
	else if((93 <= d100) && (d100 <= 94))
	{
		cout << "Ring of Wizardry IV" << endl;
	}
	else if(d100 == 95)
	{
		cout << "Ring of Djinni Calling" << endl;
	}
	else if(d100 == 96)
	{
		cout << "Ring of Elemental Command (Air)" << endl;
	}
	else if(d100 == 97)
	{
		cout << "Ring of Elemental Command (Earth)" << endl;
	}
	else if(d100 == 98)
	{
		cout << "Ring of Elemental Command (Fire)" << endl;
	}
	else if(d100 == 99)
	{
		cout << "Ring of Elemental Command (Water)" << endl;
	}
	else
	{
		cout << "Ring of Major Spell Storing" << endl;
	}
}

void mediumRod()
{
	int d100;
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 7))
	{
		cout << "Rod of Metamagic (Lesser Enlarge)" << endl;
	}
	else if((8 <= d100) && (d100 <= 14))
	{
		cout << "Rod of Metamagic (Lesser Extend)" << endl;
	}
	else if((15 <= d100) && (d100 <= 21))
	{
		cout << "Rod of Metamagic (Lesser Silent)" << endl;
	}	
	else if((22 <= d100) && (d100 <= 28))
	{
		cout << "Immovable Rod" << endl;
	}
	else if((29 <= d100) && (d100 <= 35))
	{
		cout << "Rod of Metamagic (Lesser Empower" << endl;
	}
	else if((36 <= d100) && (d100 <= 42))
	{
		cout << "Rod of Metal and Mineral Detection" << endl;
	}
	else if((43 <= d100) && (d100 <= 53))
	{
		cout << "Rod of Cancellation" << endl;
	}
	else if((54 <= d100) && (d100 <= 57))
	{
		cout << "Rod of Metamagic (Enlarge)" << endl;
	}
	else if((58 <= d100) && (d100 <= 61))
	{
		cout << "Rod of Metamagic (Extend)" << endl;
	}	
	else if((62 <= d100) && (d100 <= 65))
	{
		cout << "Rod of Metamagic (Silent)" << endl;
	}
	else if((66 <= d100) && (d100 <= 71))
	{
		cout << "Rod of Wonder" << endl;
	}
	else if((72 <= d100) && (d100 <= 79))
	{
		cout << "Python Rod" << endl;
	}
	else if((80 <= d100) && (d100 <= 83))
	{
		cout << "Rod of Metamagic (Lesser Maximize)" << endl;
	}
	else if((84 <= d100) && (d100 <= 89))
	{
		cout << "Rod of Flame Extinguishing" << endl;
	}
	else if((90 <= d100) && (d100 <= 97))
	{
		cout << "Rod of the Viper" << endl;
	}
	else if((98 <= d100) && (d100 <= 99))
	{
		cout << "Rod of Metamagic (Empower)" << endl;
	}
	else
	{
		cout << "Rod of Metamagic (Lesser Quicken)" << endl;
	}
}
void majorRod()
{
	int d100;
	d100=rand()%100+1;
	if((1 <= d100) && (d100 <= 4))
	{
		cout << "Rod of Cancellation" << endl;
	}
	else if((5 <= d100) && (d100 <= 6))
	{
		cout << "Rod of Metamagic (Enlarge)" << endl;
	}
	else if((7 <= d100) && (d100 <= 8))
	{
		cout << "Rod of Metamagic (Extend)" << endl;
	}
	else if((9 <= d100) && (d100 <= 10))
	{
		cout << "Rod of Metamagic (Silent)" << endl;
	}
	else if((11 <= d100) && (d100 <= 14))
	{
		cout << "Rod of Wonder" << endl;
	}
	else if((15 <= d100) && (d100 <= 18))
	{
		cout << "Python Rod" << endl;
	}
	else if((19 <= d100) && (d100 <= 21))
	{
		cout << "Rod of Flame Extinguishing" << endl;
	}
	else if((22 <= d100) && (d100 <= 25))
	{
		cout << "Rod of the Viper" << endl;
	}
	else if((26 <= d100) && (d100 <= 30))
	{
		cout << "Rod of Enemy Detection" << endl;
	}
	else if((31 <= d100) && (d100 <= 36))
	{
		cout << "Rod of Metamagic (Greater Enlarge)" << endl;
	}
	else if((37 <= d100) && (d100 <= 42))
	{
		cout << "Rod of Metamagic (Greater Extend)" << endl;
	}
	else if((43 <= d100) && (d100 <= 48))
	{
		cout << "Rod of Metamagic (Greater Silent)" << endl;
	}
	else if((49 <= d100) && (d100 <= 53))
	{
		cout << "Rod of Splendor" << endl;
	}
	else if((54 <= d100) && (d100 <= 58))
	{
		cout << "Rod of Withering" << endl;
	}
	else if((59 <= d100) && (d100 <= 64))
	{
		cout << "Rod of Metamagic (Empower)" << endl;
	}
	else if((65 <= d100) && (d100 <= 69))
	{
		cout << "Rod of Thunder and Lightning" << endl;
	}
	else if((70 <= d100) && (d100 <= 73))
	{
		cout << "Rod of Metamagic (Lesser Quicken)" << endl;
	}
	else if((74 <= d100) && (d100 <= 77))
	{
		cout << "Rod of Negation" << endl;
	}
	else if((78 <= d100) && (d100 <= 80))
	{
		cout << "Rod of Absorption" << endl;
	}
	else if((81 <= d100) && (d100 <= 84))
	{
		cout << "Rod of Flailing" << endl;
	}
	else if((85 <= d100) && (d100 <= 86))
	{
		cout << "Rod of Metamagic (Maximize)" << endl;
	}
	else if((87 <= d100) && (d100 <= 88))
	{
		cout << "Rod of Rulership" << endl;
	}
	else if((89 <= d100) && (d100 <= 90))
	{
		cout << "Rod of Security" << endl;
	}
	else if((91 <= d100) && (d100 <= 92))
	{
		cout << "Rod of Lordly Might" << endl;
	}
	else if((93 <= d100) && (d100 <= 94))
	{
		cout << "Rod of Metamagic (Greater Empower)" << endl;
	}
	else if((95 <= d100) && (d100 <= 96))
	{
		cout << "Rod of Metamagic (Quicken)" << endl;
	}
	else if((97 <= d100) && (d100 <= 98))
	{
		cout << "Rod of Alertness" << endl;
	}
	else if(d100 == 99)
	{
		cout << "Rod of Metamagic (Greater Maximize)" << endl;
	}
	else
	{
		cout << "Rod of Metamagic (Greater Quicken)" << endl;
	}
}

void minorScrollType()
{
	int d100 = rand()%100+1;
	if(d100 <= 70)
	{
		minorAScroll();
	}
	else
	{
		minorDScroll();
	}
}
void mediumScrollType()
{
	int d100 = rand()%100+1;
	if(d100 <= 70)
	{
		mediumAScroll();
	}
	else
	{
		mediumDScroll();
	}
}
void majorScrollType()
{
	int d100 = rand()%100+1;
	if(d100 <= 70)
	{
		majorAScroll();
	}
	else
	{
		majorDScroll();
	}
}

void minorAScroll()
{
	int d3 = rand()%3+1;
	int d100;
	for(int x=0; x<d3; x++)
	{
		d100 = rand()%100+1;
		if((1 <= d100) && (d100 <= 5))
		{
			ASpell_0();
		}
		else if((6 <= d100) && (d100 <= 50))
		{
			ASpell_1();
		}
		else if((51 <= d100) && (d100 <= 95))
		{
			ASpell_2();
		}
		else
		{
			ASpell_3();
		}
	}
}
void mediumAScroll()
{
	int d4 = rand()%4+1;
	int d100;
	for(int x=0; x<d4; x++)
	{
		d100 = rand()%100+1;
		if((1 <= d100) && (d100 <= 5))
		{
			ASpell_2();
		}
		else if((6 <= d100) && (d100 <= 65))
		{
			ASpell_3();
		}
		else if((66 <= d100) && (d100 <= 95))
		{
			ASpell_4();
		}
		else
		{
			ASpell_5();
		}
	}	
}
void majorAScroll()
{
	int d6 = rand()%6+1;
	int d100;
	for(int x=0; x<d6; x++)
	{
		d100 = rand()%100+1;
		if((1 <= d100) && (d100 <= 5))
		{
			ASpell_4();
		}
		else if((6 <= d100) && (d100 <= 50))
		{
			ASpell_5();
		}
		else if((51 <= d100) && (d100 <= 70))
		{
			ASpell_6();
		}
		else if((71 <= d100) && (d100 <= 85))
		{
			ASpell_7();
		}
		else if((86 <= d100) && (d100 <= 94))
		{
			ASpell_8();
		}
		else
		{
			ASpell_9();
		}
	}
}
	void ASpell_0()
	{
		int d100;
		d100=rand()%100+1;
		if((1 <= d100) && (d100 <= 4))
		{
			cout << "Arcane Scroll of Acid Splash (Caster level 1)" << endl;
		}
		else if((5 <= d100) && (d100 <= 8))
		{
			cout << "Arcane Scroll of Arcane Mark (Caster level 1)" << endl;
		}
		else if((9 <= d100) && (d100 <= 13))
		{
			cout << "Arcane Scroll of Dancing Lights (Caster level 1)" << endl;
		}
		else if((14 <= d100) && (d100 <= 17))
		{
			cout << "Arcane Scroll of Daze (Caster level 1)" << endl;
		}
		else if((18 <= d100) && (d100 <= 24))
		{
			cout << "Arcane Scroll of Detect Magic (Caster level 1)" << endl;
		}
		else if((25 <= d100) && (d100 <= 28))
		{
			cout << "Arcane Scroll of Detect Poison (Caster level 1)" << endl;
		}
		else if((29 <= d100) && (d100 <= 32))
		{
			cout << "Arcane Scroll of Disrupt Undead (Caster level 1)" << endl;
		}
		else if((33 <= d100) && (d100 <= 37))
		{
			cout << "Arcane Scroll of Flare (Caster level 1)" << endl;
		}
		else if((38 <= d100) && (d100 <= 42))
		{
			cout << "Arcane Scroll of Ghost Sound (Caster level 1)" << endl;
		}
		else if((43 <= d100) && (d100 <= 44))
		{
			cout << "Arcane Scroll of Know Direction (Caster level 1)" << endl;
		}
		else if((45 <= d100) && (d100 <= 50))
		{
			cout << "Arcane Scroll of Light (Caster level 1)" << endl;
		}
		else if((51 <= d100) && (d100 <= 52))
		{
			cout << "Arcane Scroll of Lullaby (Caster level 1)" << endl;
		}
		else if((53 <= d100) && (d100 <= 57))
		{
			cout << "Arcane Scroll of Mage Hand (Caster level 1)" << endl;
		}
		else if((58 <= d100) && (d100 <= 62))
		{
			cout << "Arcane Scroll of Mending (Caster level 1)" << endl;
		}
		else if((63 <= d100) && (d100 <= 67))
		{
			cout << "Arcane Scroll of Message (Caster level 1)" << endl;
		}
		else if((68 <= d100) && (d100 <= 72))
		{
			cout << "Arcane Scroll of Open/Close (Caster level 1)" << endl;
		}
		else if((73 <= d100) && (d100 <= 77))
		{
			cout << "Arcane Scroll of Prestidigitation (Caster level 1)" << endl;
		}
		else if((78 <= d100) && (d100 <= 81))
		{
			cout << "Arcane Scroll of Ray of Frost (Caster level 1)" << endl;
		}
		else if((82 <= d100) && (d100 <= 87))
		{
			cout << "Arcane Scroll of Read Magic (Caster level 1)" << endl;
		}
		else if((88 <= d100) && (d100 <= 94))
		{
			cout << "Arcane Scroll of Resistance (Caster level 1)" << endl;
		}
		else if((95 <= d100) && (d100 <= 96))
		{
			cout << "Arcane Scroll of Summon Instrument (Caster level 1)" << endl;
		}
		else
		{
			cout << "Arcane Scroll of Touch of Fatigue (Caster level 1)" << endl;
		}
	}
	void ASpell_1()
	{
		int d100;
		d100=rand()%100+1;
		if((1 <= d100) && (d100 <= 3))
		{
			cout << "Arcane Scroll of Alarm (Caster level 1)" << endl;
		}
		else if((4 <= d100) && (d100 <= 5))
		{
			cout << "Arcane Scroll of Animate Rope (Caster level 1)" << endl;
		}
		else if((6 <= d100) && (d100 <= 7))
		{
			cout << "Arcane Scroll of Burning Hands (Caster level 1)" << endl;
		}
		else if((8 <= d100) && (d100 <= 9))
		{
			cout << "Arcane Scroll of Cause Fear (Caster level 1)" << endl;
		}
		else if((10 <= d100) && (d100 <= 12))
		{
			cout << "Arcane Scroll of Charm Person (Caster level 1)" << endl;
		}
		else if((13 <= d100) && (d100 <= 14))
		{
			cout << "Arcane Scroll of Chill Touch (Caster level 1)" << endl;
		}
		else if((15 <= d100) && (d100 <= 16))
		{
			cout << "Arcane Scroll of Color Spray (Caster level 1)" << endl;
		}
		else if((17 <= d100) && (d100 <= 19))
		{
			cout << "Arcane Scroll of Comprehend Languages (Caster level 1)" << endl;
		}
		else if(d100 == 20)
		{
			cout << "Arcane Scroll of Lesser Confusion (Caster level 1)" << endl;
		}
		else if(d100 == 21)
		{
			cout << "Arcane Scroll of Cure Light Wounds (Caster level 1)" << endl;
		}
		else if((22 <= d100) && (d100 <= 24))
		{
			cout << "Arcane Scroll of Detect Secret Doors (Caster level 1)" << endl;
		}
		else if((25 <= d100) && (d100 <= 26))
		{
			cout << "Arcane Scroll of Detect Undead (Caster level 1)" << endl;
		}
		else if((27 <= d100) && (d100 <= 29))
		{
			cout << "Arcane Scroll of Disguise Self (Caster level 1)" << endl;
		}
		else if((30 <= d100) && (d100 <= 32))
		{
			cout << "Arcane Scroll of Endure Elements (Caster level 1)" << endl;
		}
		else if((33 <= d100) && (d100 <= 35))
		{
			cout << "Arcane Scroll of Enlarge Person (Caster level 1)" << endl;
		}
		else if((36 <= d100) && (d100 <= 37))
		{
			cout << "Arcane Scroll of Erase (Caster level 1)" << endl;
		}
		else if((38 <= d100) && (d100 <= 40))
		{
			cout << "Arcane Scroll of Expeditious Retreat (Caster level 1)" << endl;
		}
		else if(d100 == 41)
		{
			cout << "Arcane Scroll of Feather Fall (Caster level 1)" << endl;
		}
		else if((42 <= d100) && (d100 <= 43))
		{
			cout << "Arcane Scroll of Grease (Caster level 1)" << endl;
		}
		else if((44 <= d100) && (d100 <= 45))
		{
			cout << "Arcane Scroll of Hold Portal (Caster level 1)" << endl;
		}
		else if((46 <= d100) && (d100 <= 47))
		{
			cout << "Arcane Scroll of Hypnotism (Caster level 1)" << endl;
		}
		else if((48 <= d100) && (d100 <= 49))
		{
			cout << "Arcane Scroll of Identify (Caster level 1)" << endl;
		}
		else if((50 <= d100) && (d100 <= 51))
		{
			cout << "Arcane Scroll of Jump (Caster level 1)" << endl;
		}
		else if((52 <= d100) && (d100 <= 54))
		{
			cout << "Arcane Scroll of Mage Armor (Caster level 1)" << endl;
		}
		else if(d100 == 55)
		{
			cout << "Arcane Scroll of Magic Missile (Caster level 1)" << endl;
		}
		else if(d100 == 56)
		{
			cout << "Arcane Scroll of Magic Missile (Caster level 3)" << endl;
		}
		else if((57 <= d100) && (d100 <= 59))
		{
			cout << "Arcane Scroll of Magic Weapon (Caster level 1)" << endl;
		}
		else if((60 <= d100) && (d100 <= 62))
		{
			cout << "Arcane Scroll of Mount (Caster level 1)" << endl;
		}
		else if((63 <= d100) && (d100 <= 64))
		{
			cout << "Arcane Scroll of Nystul's Magic Aura (Caster level 1)" << endl;
		}
		else if((65 <= d100) && (d100 <= 66))
		{
			cout << "Arcane Scroll of Obscuring Mist (Caster level 1)" << endl;
		}
		else if((67 <= d100) && (d100 <= 74))
		{
			int d4 = rand()%4+1;
			switch(d4)
			{
			case 1: cout << "Arcane Scroll of Protection from Chaos (Caster Level 1)" << endl;
				break;
			case 2: cout << "Arcane Scroll of Protection from Evil (Caster Level 1)" << endl;
				break;
			case 3: cout << "Arcane Scroll of Protection from Good (Caster Level 1)" << endl;
				break;
			case 4: cout << "Arcane Scroll of Protection from Law (Caster Level 1)" << endl;
				break;
			}
		}
		else if((75 <= d100) && (d100 <= 76))
		{
			cout << "Arcane Scroll of Ray of Enfeeblement (Caster level 1)" << endl;
		}
		else if((77 <= d100) && (d100 <= 78))
		{
			cout << "Arcane Scroll of Reduce Person (Caster level 1)" << endl;
		}
		else if((79 <= d100) && (d100 <= 80))
		{
			cout << "Arcane Scroll of Remove Fear (Caster level 1)" << endl;
		}
		else if((81 <= d100) && (d100 <= 82))
		{
			cout << "Arcane Scroll of Shield (Caster level 1)" << endl;
		}
		else if((83 <= d100) && (d100 <= 84))
		{
			cout << "Arcane Scroll of Shocking Grasp (Caster level 1)" << endl;
		}
		else if((85 <= d100) && (d100 <= 86))
		{
			cout << "Arcane Scroll of Silent Image (Caster level 1)" << endl;
		}
		else if((87 <= d100) && (d100 <= 88))
		{
			cout << "Arcane Scroll of Sleep (Caster level 1)" << endl;
		}
		else if((89 <= d100) && (d100 <= 90))
		{
			cout << "Arcane Scroll of Summon Monster I (Caster level 1)" << endl;
		}
		else if((91 <= d100) && (d100 <= 93))
		{
			cout << "Arcane Scroll of Tenser's Floating Disk (Caster level 1)" << endl;
		}
		else if((94 <= d100) && (d100 <= 95))
		{
			cout << "Arcane Scroll of True Strike (Caster level 1)" << endl;
		}
		else if(d100 == 96)
		{
			cout << "Arcane Scroll of Undetectable Alignment (Caster level 1)" << endl;
		}
		else if((97 <= d100) && (d100 <= 98))
		{
			cout << "Arcane Scroll of Unseen Servant (Caster level 1)" << endl;
		}
		else
		{
			cout << "Arcane Scroll of Ventriloquism (Caster level 1)" << endl;
		}
	}
	void ASpell_2()
	{
		int d100 = rand()%100+1;
		if(d100 == 1)
		{
			cout << "Arcane Scroll of Animal Messenger (Caster Level 3)" << endl;
		}
		else if(d100 == 2)
		{
			cout << "Arcane Scroll of Animal Trance (Caster Level 3)" << endl;
		}
		else if(d100 == 3)
		{
			cout << "Arcane Scroll of Arcane Lock (Caster Level 3)" << endl;
		}
		else if((4 <= d100) && (d100 <= 6))
		{
			cout << "Arcane Scroll of Bear's Endurance (Caster level 3)" << endl;
		}
		else if((7 <= d100) && (d100 <= 8))
		{
			cout << "Arcane Scroll of Blindness/Deafness (Caster level 3)" << endl;
		}
		else if((9 <= d100) && (d100 <= 10))
		{
			cout << "Arcane Scroll of Blur (Caster level 3)" << endl;
		}
		else if((11 <= d100) && (d100 <= 13))
		{
			cout << "Arcane Scroll of Bull's Strength (Caster level 3)" << endl;
		}
		else if(d100 == 14)
		{
			cout << "Arcane Scroll of Calm Emotions (Caster level 3)" << endl;
		}
		else if((15 <= d100) && (d100 <= 17))
		{
			cout << "Arcane Scroll of Cat's Grace (Caster level 3)" << endl;
		}
		else if((18 <= d100) && (d100 <= 19))
		{
			cout << "Arcane Scroll of Command Undead (Caster level 3)" << endl;
		}
		else if(d100 == 20)
		{
			cout << "Arcane Scroll of Continual Flame (Caster level 3)" << endl;
		}
		else if(d100 == 21)
		{
			cout << "Arcane Scroll of Cure Moderate Wounds (Caster level 3)" << endl;
		}
		else if(d100 == 22)
		{
			cout << "Arcane Scroll of Darkness (Caster level 3)" << endl;
		}
		else if((23 <= d100) && (d100 <= 25))
		{
			cout << "Arcane Scroll of Darkvision (Caster level 3)" << endl;
		}
		else if(d100 == 26)
		{
			cout << "Arcane Scroll of Darkness (Caster level 3)" << endl;
		}
		else if(d100 == 27)
		{
			cout << "Arcane Scroll of Delay Poison (Caster level 3)" << endl;
		}
		else if((28 <= d100) && (d100 <= 29))
		{
			cout << "Arcane Scroll of Detect Thoughts (Caster level 3)" << endl;
		}
		else if((30 <= d100) && (d100 <= 31))
		{
			cout << "Arcane Scroll of Disguise Self (Caster level 3)" << endl;
		}
		else if((32 <= d100) && (d100 <= 34))
		{
			cout << "Arcane Scroll of Eagle's Splendor (Caster level 3)" << endl;
		}
		else if(d100 == 35)
		{
			cout << "Arcane Scroll of Enthrall (Caster level 3)" << endl;
		}
		else if((36 <= d100) && (d100 <= 37))
		{
			cout << "Arcane Scroll of False Life (Caster level 3)" << endl;
		}
		else if((38 <= d100) && (d100 <= 39))
		{
			cout << "Arcane Scroll of Flaming Sphere (Caster level 3)" << endl;
		}
		else if(d100 == 40)
		{
			cout << "Arcane Scroll of Fog Cloud (Caster level 3)" << endl;
		}
		else if((41 <= d100) && (d100 <= 43))
		{
			cout << "Arcane Scroll of Fox's Cunning (Caster level 3)" << endl;
		}
		else if(d100 == 44)
		{
			cout << "Arcane Scroll of Ghoul Touch (Caster level 3)" << endl;
		}
		else if((45 <= d100) && (d100 <= 46))
		{
			cout << "Arcane Scroll of GlitterDust (Caster level 3)" << endl;
		}
		else if(d100 == 47)
		{
			cout << "Arcane Scroll of Gust of Wind (Caster level 3)" << endl;
		}
		else if((48 <= d100) && (d100 <= 49))
		{
			cout << "Arcane Scroll of Hypnotic Pattern (Caster level 3)" << endl;
		}
		else if((50 <= d100) && (d100 <= 52))
		{
			cout << "Arcane Scroll of Invisibility (Caster level 3)" << endl;
		}
		else if((53 <= d100) && (d100 <= 55))
		{
			cout << "Arcane Scroll of Knock (Caster level 3)" << endl;
		}
		else if(d100 == 56)
		{
			cout << "Arcane Scroll of Leomund's Trap (Caster level 3)" << endl;
		}
		else if((57 <= d100) && (d100 <= 58))
		{
			cout << "Arcane Scroll of Levitate (Caster level 3)" << endl;
		}
		else if(d100 == 59)
		{
			cout << "Arcane Scroll of Locate Object (Caster level 3)" << endl;
		}
		else if(d100 == 60)
		{
			cout << "Arcane Scroll of Magic Mouth (Caster level 3)" << endl;
		}
		else if((61 <= d100) && (d100 <= 62))
		{
			cout << "Arcane Scroll of Melf's Acid Arrow (Caster level 3)" << endl;
		}
		else if(d100 == 63)
		{
			cout << "Arcane Scroll of Minor Image (Caster level 3)" << endl;
		}
		else if((64 <= d100) && (d100 <= 65))
		{
			cout << "Arcane Scroll of Mirror Image (Caster level 3)" << endl;
		}
		else if(d100 == 66)
		{
			cout << "Arcane Scroll of Misdirection (Caster level 3)" << endl;
		}
		else if(d100 == 67)
		{
			cout << "Arcane Scroll of Obscure Object (Caster level 3)" << endl;
		}
		else if((68 <= d100) && (d100 <= 70))
		{
			cout << "Arcane Scroll of Owl's Wisdom (Caster level 3)" << endl;
		}
		else if((71 <= d100) && (d100 <= 73))
		{
			cout << "Arcane Scroll of Protection from Arrows (Caster level 3)" << endl;
		}
		else if((74 <= d100) && (d100 <= 75))
		{
			cout << "Arcane Scroll of Pyrotechnics (Caster level 3)" << endl;
		}
		else if((76 <= d100) && (d100 <= 78))
		{
			cout << "Arcane Scroll of Resist Energy (Caster level 3)" << endl;
		}
		else if(d100 == 79)
		{
			cout << "Arcane Scroll of Rope Trick (Caster level 3)" << endl;
		}
		else if(d100 == 80)
		{
			cout << "Arcane Scroll of Scare (Caster level 3)" << endl;
		}
		else if((81 <= d100) && (d100 <= 82))
		{
			cout << "Arcane Scroll of Scorching Ray (Caster level 3)" << endl;
		}
		else if((83 <= d100) && (d100 <= 85))
		{
			cout << "Arcane Scroll of See Invisibility (Caster level 3)" << endl;
		}
		else if(d100 == 86)
		{
			cout << "Arcane Scroll of Shatter (Caster level 3)" << endl;
		}
		else if(d100 == 87)
		{
			cout << "Arcane Scroll of Silence (Caster level 3)" << endl;
		}
		else if(d100 == 88)
		{
			cout << "Arcane Scroll of Sound Burst (Caster level 3)" << endl;
		}
		else if(d100 == 89)
		{
			cout << "Arcane Scroll of Spectral Hand (Caster level 3)" << endl;
		}
		else if((90 <= d100) && (d100 <= 91))
		{
			cout << "Arcane Scroll of Spider Climb (Caster level 3)" << endl;
		}
		else if((92 <= d100) && (d100 <= 93))
		{
			cout << "Arcane Scroll of Summon Monster II (Caster level 3)" << endl;
		}
		else if((94 <= d100) && (d100 <= 95))
		{
			cout << "Arcane Scroll of Summon Swarm (Caster level 3)" << endl;
		}
		else if(d100 == 96)
		{
			cout << "Arcane Scroll of Tasha's Hideous Laughter (Caster level 3)" << endl;
		}
		else if(d100 == 97)
		{
			cout << "Arcane Scroll of Touch of Idiocy (Caster level 3)" << endl;
		}
		else if((98 <= d100) && (d100 <= 99))
		{
			cout << "Arcane Scroll of Web (Caster level 3)" << endl;
		}
		else
		{
			cout << "Arcane Scroll of Whispering Wind (Caster level 3)" << endl;
		}
	}
	void ASpell_3()
	{
		int d100 = rand()%100+1;
		if((1 <= d100) && (d100 <= 2))
		{
			cout << "Arcane Scroll of Arcane Light (Caster level 5)" << endl;
		}
		else if((3 <= d100) && (d100 <= 4))
		{
			cout << "Arcane Scroll of Blink (Caster level 5)" << endl;
		}
		else if((5 <= d100) && (d100 <= 6))
		{
			cout << "Arcane Scroll of Clairaudience/Clairvoyance (Caster level 5)" << endl;
		}
		else if(d100 == 7)
		{
			cout << "Arcane Scroll of Cure Serious Wounds (Caster level 5)" << endl;
		}
		else if((8 <= d100) && (d100 <= 10))
		{
			cout << "Arcane Scroll of Daylight (Caster level 5)" << endl;
		}
		else if((11 <= d100) && (d100 <= 12))
		{
			cout << "Arcane Scroll of Deep Slumber (Caster level 5)" << endl;
		}
		else if((13 <= d100) && (d100 <= 15))
		{
			cout << "Arcane Scroll of Dispel Magic (Caster level 5)" << endl;
		}
		else if((16 <= d100) && (d100 <= 17))
		{
			cout << "Arcane Scroll of Displacement (Caster level 5)" << endl;
		}
		else if(d100 == 18)
		{
			cout << "Arcane Scroll of Explosive Runes (Caster level 5)" << endl;
		}
		else if(d100 == 19)
		{
			cout << "Arcane Scroll of Fireball (Caster level 5)" << endl;
		}
		else if(d100 == 20)
		{
			cout << "Arcane Scroll of Fireball (Caster level 7)" << endl;
		}
		else if((21 <= d100) && (d100 <= 22))
		{
			cout << "Arcane Scroll of Flame Arrow (Caster level 5)" << endl;
		}
		else if((23 <= d100) && (d100 <= 25))
		{
			cout << "Arcane Scroll of Fly (Caster level 5)" << endl;
		}
		else if((26 <= d100) && (d100 <= 27))
		{
			cout << "Arcane Scroll of Gaseous Form (Caster level 5)" << endl;
		}
		else if((28 <= d100) && (d100 <= 29))
		{
			cout << "Arcane Scroll of Gentle Repose (Caster level 5)" << endl;
		}
		else if(d100 == 30)
		{
			cout << "Arcane Scroll of Glibness (Caster level 5)" << endl;
		}
		else if(d100 == 31)
		{
			cout << "Arcane Scroll of Good Hope (Caster level 5)" << endl;
		}
		else if((32 <= d100) && (d100 <= 33))
		{
			cout << "Arcane Scroll of Halt Undead (Caster level 5)" << endl;
		}
		else if((34 <= d100) && (d100 <= 36))
		{
			cout << "Arcane Scroll of Haste (Caster level 5)" << endl;
		}
		else if((37 <= d100) && (d100 <= 38))
		{
			cout << "Arcane Scroll of Heroism (Caster level 5)" << endl;
		}
		else if((39 <= d100) && (d100 <= 40))
		{
			cout << "Arcane Scroll of Hold Person (Caster level 5)" << endl;
		}
		else if(d100 == 41)
		{
			cout << "Arcane Scroll of Illusory Script (Caster level 5)" << endl;
		}
		else if((42 <= d100) && (d100 <= 44))
		{
			cout << "Arcane Scroll of Invisibility Sphere (Caster level 5)" << endl;
		}
		else if((45 <= d100) && (d100 <= 47))
		{
			cout << "Arcane Scroll of Keen Edge (Caster level 5)" << endl;
		}
		else if((48 <= d100) && (d100 <= 49))
		{
			cout << "Arcane Scroll of Leomund's Tiny Hut (Caster level 5)" << endl;
		}
		else if((50 <= d100) && (d100 <= 51))
		{
			cout << "Arcane Scroll of Lightning Bolt (Caster level 5)" << endl;
		}
		else if((52 <= d100) && (d100 <= 53))
		{
			cout << "Arcane Scroll of Magic Circle Against Chaos (Caster level 5)" << endl;
		}
		else if((54 <= d100) && (d100 <= 55))
		{
			cout << "Arcane Scroll of Magic Circle Against Law (Caster level 5)" << endl;
		}
		else if((56 <= d100) && (d100 <= 57))
		{
			cout << "Arcane Scroll of Magic Circle Against Good (Caster level 5)" << endl;
		}
		else if((58 <= d100) && (d100 <= 59))
		{
			cout << "Arcane Scroll of Magic Circle Against Evil (Caster level 5)" << endl;
		}
		else if((60 <= d100) && (d100 <= 62))
		{
			cout << "Arcane Scroll of Greater Magic Weapon (Caster level 5)" << endl;
		}
		else if((63 <= d100) && (d100 <= 64))
		{
			cout << "Arcane Scroll of Major Image (Caster level 5)" << endl;
		}
		else if((65 <= d100) && (d100 <= 66))
		{
			cout << "Arcane Scroll of Nondetection (Caster level 5)" << endl;
		}
		else if((67 <= d100) && (d100 <= 68))
		{
			cout << "Arcane Scroll of Phantom Steed (Caster level 5)" << endl;
		}
		else if((69 <= d100) && (d100 <= 71))
		{
			cout << "Arcane Scroll of Protection from Energy (Caster level 5)" << endl;
		}
		else if((72 <= d100) && (d100 <= 73))
		{
			cout << "Arcane Scroll of Rage (Caster level 5)" << endl;
		}
		else if((74 <= d100) && (d100 <= 75))
		{
			cout << "Arcane Scroll of Ray of Exhaustion (Caster level 5)" << endl;
		}
		else if(d100 == 76)
		{
			cout << "Arcane Scroll of Sculpt Sound (Caster level 5)" << endl;
		}
		else if(d100 == 77)
		{
			cout << "Arcane Scroll of Secret Page (Caster level 5)" << endl;
		}
		else if(d100 == 78)
		{
			cout << "Arcane Scroll of Sepia Snake Sigil (Caster level 5)" << endl;
		}
		else if(d100 == 79)
		{
			cout << "Arcane Scroll of Shrink Item (Caster level 5)" << endl;
		}
		else if((80 <= d100) && (d100 <= 81))
		{
			cout << "Arcane Scroll of Sleet Storm (Caster level 5)" << endl;
		}
		else if((82 <= d100) && (d100 <= 83))
		{
			cout << "Arcane Scroll of Slow (Caster level 5)" << endl;
		}
		else if(d100 == 84)
		{
			cout << "Arcane Scroll of Speak With Animals (Caster level 5)" << endl;
		}
		else if((85 <= d100) && (d100 <= 86))
		{
			cout << "Arcane Scroll of Stinking Cloud (Caster level 5)" << endl;
		}
		else if((87 <= d100) && (d100 <= 88))
		{
			cout << "Arcane Scroll of Suggestion (Caster level 5)" << endl;
		}
		else if((89 <= d100) && (d100 <= 90))
		{
			cout << "Arcane Scroll of Summon Monster III (Caster level 5)" << endl;
		}
		else if((91 <= d100) && (d100 <= 93))
		{
			cout << "Arcane Scroll of Tongues (Caster level 5)" << endl;
		}
		else if((94 <= d100) && (d100 <= 95))
		{
			cout << "Arcane Scroll of Vampiric Touch (Caster level 5)" << endl;
		}
		else if((96 <= d100) && (d100 <= 98))
		{
			cout << "Arcane Scroll of Water Breathing (Caster level 5)" << endl;
		}
		else
		{
			cout << "Arcane Scroll of Wind Wall (Caster level 5)" << endl;
		}
	}
	void ASpell_4()
	{
		int d100 = rand()%100+1;
		if((1 <= d100) && (d100 <= 2))
		{
			cout << "Arcane Scroll of Animate Dead (Caster level 7)" << endl;
		}
		else if((3 <= d100) && (d100 <= 5))
		{
			cout << "Arcane Scroll of Arcane Eye (Caster level 7)" << endl;
		}
		else if((6 <= d100) && (d100 <= 7))
		{
			cout << "Arcane Scroll of Bestow Curse (Caster level 7)" << endl;
		}
		else if((8 <= d100) && (d100 <= 10))
		{
			cout << "Arcane Scroll of Charm Monster (Caster level 7)" << endl;
		}
		else if((11 <= d100) && (d100 <= 13))
		{
			cout << "Arcane Scroll of Confusion (Caster level 7)" << endl;
		}
		else if((14 <= d100) && (d100 <= 15))
		{
			cout << "Arcane Scroll of Contagion (Caster level 7)" << endl;
		}
		else if((16 <= d100) && (d100 <= 17))
		{
			cout << "Arcane Scroll of Crushing Despair (Caster level 7)" << endl;
		}
		else if(d100 == 18)
		{
			cout << "Arcane Scroll of Cure Critical Wounds (Caster level 7)" << endl;
		}
		else if(d100 == 19)
		{
			cout << "Arcane Scroll of Detect Scrying (Caster level 7)" << endl;
		}
		else if((20 <= d100) && (d100 <= 23))
		{
			cout << "Arcane Scroll of Dimension Door (Caster level 7)" << endl;
		}
		else if((24 <= d100) && (d100 <= 26))
		{
			cout << "Arcane Scroll of Dimensional Anchor (Caster level 7)" << endl;
		}
		else if((27 <= d100) && (d100 <= 28))
		{
			cout << "Arcane Scroll of Enervation (Caster level 7)" << endl;
		}
		else if((29 <= d100) && (d100 <= 30))
		{
			cout << "Arcane Scroll of Mass Enlarge Person (Caster level 7)" << endl;
		}
		else if((31 <= d100) && (d100 <= 32))
		{
			cout << "Arcane Scroll of Evard's Black Tentacles (Caster level 7)" << endl;
		}
		else if((33 <= d100) && (d100 <= 34))
		{
			cout << "Arcane Scroll of Fear (Caster level 7)" << endl;
		}
		else if((35 <= d100) && (d100 <= 37))
		{
			cout << "Arcane Scroll of Fire Shield (Caster level 7)" << endl;
		}
		else if((38 <= d100) && (d100 <= 39))
		{
			cout << "Arcane Scroll of Fire Trap (Caster level 7)" << endl;
		}
		else if((40 <= d100) && (d100 <= 42))
		{
			cout << "Arcane Scroll of Freedom of Movement (Caster level 7)" << endl;
		}
		else if(d100 == 43)
		{
			cout << "Arcane Scroll of Lesser Geas (Caster level 7)" << endl;
		}
		else if((44 <= d100) && (d100 <= 46))
		{
			cout << "Arcane Scroll of Lesser Globe of Invulnerability (Caster level 7)" << endl;
		}
		else if((47 <= d100) && (d100 <= 48))
		{
			cout << "Arcane Scroll of Hallucinatory Terrain (Caster level 7)" << endl;
		}
		else if((49 <= d100) && (d100 <= 50))
		{
			cout << "Arcane Scroll of Ice Storm (Caster level 7)" << endl;
		}
		else if((51 <= d100) && (d100 <= 52))
		{
			cout << "Arcane Scroll of Illusory Wall (Caster level 7)" << endl;
		}
		else if((53 <= d100) && (d100 <= 55))
		{
			cout << "Arcane Scroll of Greater Invisibility (Caster level 7)" << endl;
		}
		else if((56 <= d100) && (d100 <= 57))
		{
			cout << "Arcane Scroll of Leomund's Secure Shelter (Caster level 7)" << endl;
		}
		else if(d100 == 58)
		{
			cout << "Arcane Scroll of Locate Creature (Caster level 7)" << endl;
		}
		else if((59 <= d100) && (d100 <= 60))
		{
			cout << "Arcane Scroll of Minor Creation (Caster level 7)" << endl;
		}
		else if(d100 == 61)
		{
			cout << "Arcane Scroll of Modify Memory (Caster level 7)" << endl;
		}
		else if(d100 == 62)
		{
			cout << "Arcane Scroll of Neutralize Poison (Caster level 7)" << endl;
		}
		else if((63 <= d100) && (d100 <= 64))
		{
			cout << "Arcane Scroll of Otiluke's Resilient Sphere (Caster level 7)" << endl;
		}
		else if((65 <= d100) && (d100 <= 66))
		{
			cout << "Arcane Scroll of Phantasmal Killer (Caster level 7)" << endl;
		}
		else if((67 <= d100) && (d100 <= 68))
		{
			cout << "Arcane Scroll of Polymorph (Caster level 7)" << endl;
		}
		else if((69 <= d100) && (d100 <= 70))
		{
			cout << "Arcane Scroll of Rainbow Pattern (Caster level 7)" << endl;
		}
		else if(d100 == 71)
		{
			cout << "Arcane Scroll of Rary's Mnemonic Enhancer (Caster level 7)" << endl;
		}
		else if((72 <= d100) && (d100 <= 73))
		{
			cout << "Arcane Scroll of Mass Reduce Person (Caster level 7)" << endl;
		}
		else if((74 <= d100) && (d100 <= 76))
		{
			cout << "Arcane Scroll of Remove Curse (Caster level 7)" << endl;
		}
		else if(d100 == 77)
		{
			cout << "Arcane Scroll of Repel Vermin (Caster level 7)" << endl;
		}
		else if((78 <= d100) && (d100 <= 79))
		{
			cout << "Arcane Scroll of Scrying (Caster level 7)" << endl;
		}
		else if((80 <= d100) && (d100 <= 81))
		{
			cout << "Arcane Scroll of Shadow Conjuration (Caster level 7)" << endl;
		}
		else if((82 <= d100) && (d100 <= 83))
		{
			cout << "Arcane Scroll of Shout (Caster level 7)" << endl;
		}
		else if((84 <= d100) && (d100 <= 85))
		{
			cout << "Arcane Scroll of Solid Fog (Caster level 7)" << endl;
		}
		else if(d100 == 86)
		{
			cout << "Arcane Scroll of Speak With Plants (Caster level 7)" << endl;
		}
		else if((87 <= d100) && (d100 <= 88))
		{
			cout << "Arcane Scroll of Stone Shape (Caster level 7)" << endl;
		}
		else if((89 <= d100) && (d100 <= 91))
		{
			cout << "Arcane Scroll of Stoneskin (Caster level 7)" << endl;
		}
		else if((92 <= d100) && (d100 <= 93))
		{
			cout << "Arcane Scroll of Summon Monster IV (Caster level 7)" << endl;
		}
		else if((94 <= d100) && (d100 <= 96))
		{
			cout << "Arcane Scroll of Wall of Fire (Caster level 7)" << endl;
		}
		else if((97 <= d100) && (d100 <= 99))
		{
			cout << "Arcane Scroll of Wall of Ice (Caster level 7)" << endl;
		}
		else
		{
			cout << "Arcane Scroll of Zone of Silence (Caster level 7)" << endl;
		}
	}
	void ASpell_5()
	{
		int d100 = rand()%100+1;
		if((1 <= d100) && (d100 <= 2))
		{
			cout << "Arcane Scroll of Animal Growth (Caster level 9)" << endl;
		}
		else if((3 <= d100) && (d100 <= 5))
		{
			cout << "Arcane Scroll of Baleful Polymorph (Caster level 9)" << endl;
		}
		else if((6 <= d100) && (d100 <= 7))
		{
			cout << "Arcane Scroll of Bigby's Interposing Hand (Caster level 9)" << endl;
		}
		else if((8 <= d100) && (d100 <= 9))
		{
			cout << "Arcane Scroll of Blight (Caster level 9)" << endl;
		}
		else if((10 <= d100) && (d100 <= 12))
		{
			cout << "Arcane Scroll of Break Enchantment (Caster level 9)" << endl;
		}
		else if((13 <= d100) && (d100 <= 14))
		{
			cout << "Arcane Scroll of Cloudkill (Caster level 9)" << endl;
		}
		else if((15 <= d100) && (d100 <= 17))
		{
			cout << "Arcane Scroll of Cone of Cold (Caster level 9)" << endl;
		}
		else if((18 <= d100) && (d100 <= 19))
		{
			cout << "Arcane Scroll of Contact Other Plane (Caster level 9)" << endl;
		}
		else if(d100 == 20)
		{
			cout << "Arcane Scroll of Mass Cure Light Wounds (Caster level 9)" << endl;
		}
		else if((21 <= d100) && (d100 <= 23))
		{
			cout << "Arcane Scroll of Dismissal (Caster level 9)" << endl;
		}
		else if((24 <= d100) && (d100 <= 26))
		{
			cout << "Arcane Scroll of Greater Dispel Magic (Caster level 9)" << endl;
		}
		else if((27 <= d100) && (d100 <= 28))
		{
			cout << "Arcane Scroll of Dominate Person (Caster level 9)" << endl;
		}
		else if(d100 == 29)
		{
			cout << "Arcane Scroll of Dream (Caster level 9)" << endl;
		}
		else if((30 <= d100) && (d100 <= 31))
		{
			cout << "Arcane Scroll of Fabricate (Caster level 9)" << endl;
		}
		else if((32 <= d100) && (d100 <= 33))
		{
			cout << "Arcane Scroll of False Vision (Caster level 9)" << endl;
		}
		else if((34 <= d100) && (d100 <= 35))
		{
			cout << "Arcane Scroll of Feeblemind (Caster level 9)" << endl;
		}
		else if((36 <= d100) && (d100 <= 39))
		{
			cout << "Arcane Scroll of Hold Monster (Caster level 9)" << endl;
		}
		else if(d100 == 40)
		{
			cout << "Arcane Scroll of Leomund's Secret Chest (Caster level 9)" << endl;
		}
		else if(d100 == 41)
		{
			cout << "Arcane Scroll of Magic Jar (Caster level 9)" << endl;
		}
		else if((42 <= d100) && (d100 <= 43))
		{
			cout << "Arcane Scroll of Major Creation (Caster level 9)" << endl;
		}
		else if((44 <= d100) && (d100 <= 45))
		{
			cout << "Arcane Scroll of Mind Fog (Caster level 9)" << endl;
		}
		else if((46 <= d100) && (d100 <= 47))
		{
			cout << "Arcane Scroll of Mirage Arcana (Caster level 9)" << endl;
		}
		else if((48 <= d100) && (d100 <= 49))
		{
			cout << "Arcane Scroll of Mordenkainen's Faithful Hound (Caster level 9)" << endl;
		}
		else if((50 <= d100) && (d100 <= 51))
		{
			cout << "Arcane Scroll of Mordenkainen's Private Sanctum (Caster level 9)" << endl;
		}
		else if((52 <= d100) && (d100 <= 53))
		{
			cout << "Arcane Scroll of Nightmare (Caster level 9)" << endl;
		}
		else if((54 <= d100) && (d100 <= 57))
		{
			cout << "Arcane Scroll of Overland Flight (Caster level 9)" << endl;
		}
		else if((58 <= d100) && (d100 <= 60))
		{
			cout << "Arcane Scroll of Passwall (Caster level 9)" << endl;
		}
		else if(d100 == 61)
		{
			cout << "Arcane Scroll of Permanency (Caster level 9)" << endl;
		}
		else if((62 <= d100) && (d100 <= 63))
		{
			cout << "Arcane Scroll of Persistent Image (Caster level 9)" << endl;
		}
		else if((64 <= d100) && (d100 <= 65))
		{
			cout << "Arcane Scroll of Lesser Planar Binding (Caster level 9)" << endl;
		}
		else if((66 <= d100) && (d100 <= 67))
		{
			cout << "Arcane Scroll of Prying Eyes (Caster level 9)" << endl;
		}
		else if((68 <= d100) && (d100 <= 69))
		{
			cout << "Arcane Scroll of Rary's Telepathic Bond (Caster level 9)" << endl;
		}
		else if((70 <= d100) && (d100 <= 71))
		{
			cout << "Arcane Scroll of Seeming (Caster level 9)" << endl;
		}
		else if((72 <= d100) && (d100 <= 74))
		{
			cout << "Arcane Scroll of Sending (Caster level 9)" << endl;
		}
		else if((75 <= d100) && (d100 <= 76))
		{
			cout << "Arcane Scroll of Shadow Evocation (Caster level 9)" << endl;
		}
		else if(d100 == 77)
		{
			cout << "Arcane Scroll of Song of Discord (Caster level 9)" << endl;
		}
		else if((78 <= d100) && (d100 <= 79))
		{
			cout << "Arcane Scroll of Summon Monster V (Caster level 9)" << endl;
		}
		else if(d100 == 80)
		{
			cout << "Arcane Scroll of Symbol of Pain (Caster level 9)" << endl;
		}
		else if(d100 == 81)
		{
			cout << "Arcane Scroll of Symbol of Sleep (Caster level 9)" << endl;
		}
		else if((82 <= d100) && (d100 <= 83))
		{
			cout << "Arcane Scroll of Telekinesis (Caster level 9)" << endl;
		}
		else if((84 <= d100) && (d100 <= 88))
		{
			cout << "Arcane Scroll of Teleport (Caster level 9)" << endl;
		}
		else if((89 <= d100) && (d100 <= 90))
		{
			cout << "Arcane Scroll of Transmute Mud to Rock (Caster level 9)" << endl;
		}
		else if((91 <= d100) && (d100 <= 92))
		{
			cout << "Arcane Scroll of Transmute Rock to Mud (Caster level 9)" << endl;
		}
		else if((93 <= d100) && (d100 <= 95))
		{
			cout << "Arcane Scroll of Wall of Force (Caster level 9)" << endl;
		}
		else if((96 <= d100) && (d100 <= 98))
		{
			cout << "Arcane Scroll of Wall of Stone (Caster level 9)" << endl;
		}
		else
		{
			cout << "Arcane Scroll of Waves of Fatigue (Caster level 9)" << endl;
		}
	}
	void ASpell_6()
	{
		int d100 = rand()%100+1;
		if((1 <= d100) && (d100 <= 2))
		{
			cout << "Arcane Scroll of Acid Fog (Caster level 11)" << endl;
		}
		else if((3 <= d100) && (d100 <= 5))
		{
			cout << "Arcane Scroll of Analyze Dweomer (Caster level 11)" << endl;
		}
		else if(d100 == 6)
		{
			cout << "Arcane Scroll of Animate Objects (Caster level 11)" << endl;
		}
		else if((7 <= d100) && (d100 <= 9))
		{
			cout << "Arcane Scroll of Antimagic Field (Caster level 11)" << endl;
		}
		else if((10 <= d100) && (d100 <= 12))
		{
			cout << "Arcane Scroll of Mass Bear's Endurance (Caster level 11)" << endl;
		}
		else if((13 <= d100) && (d100 <= 14))
		{
			cout << "Arcane Scroll of Bigby's Interposing Hand (Caster level 11)" << endl;
		}
		else if((15 <= d100) && (d100 <= 17))
		{
			cout << "Arcane Scroll of Mass Bull's Strength (Caster level 11)" << endl;
		}
		else if((18 <= d100) && (d100 <= 20))
		{
			cout << "Arcane Scroll of Mass Cat's Grace (Caster level 11)" << endl;
		}
		else if((21 <= d100) && (d100 <= 23))
		{
			cout << "Arcane Scroll of Chain Lightning (Caster level 11)" << endl;
		}
		else if((24 <= d100) && (d100 <= 25))
		{
			cout << "Arcane Scroll of Circle of Death (Caster level 11)" << endl;
		}
		else if(d100 == 26)
		{
			cout << "Arcane Scroll of Contingency (Caster level 11)" << endl;
		}
		else if((27 <= d100) && (d100 <= 28))
		{
			cout << "Arcane Scroll of Control Water (Caster level 11)" << endl;
		}
		else if(d100 == 29)
		{
			cout << "Arcane Scroll of Create Undead (Caster level 11)" << endl;
		}
		else if(d100 == 30)
		{
			cout << "Arcane Scroll of Mass Cure Moderate Wounds (Caster level 11)" << endl;
		}
		else if((31 <= d100) && (d100 <= 33))
		{
			cout << "Arcane Scroll of Disintegrate (Caster level 11)" << endl;
		}
		else if((34 <= d100) && (d100 <= 37))
		{
			cout << "Arcane Scroll of Greater Dispel Magic (Caster level 11)" << endl;
		}
		else if((38 <= d100) && (d100 <= 40))
		{
			cout << "Arcane Scroll of Mass Eagle's Splendor (Caster level 11)" << endl;
		}
		else if((41 <= d100) && (d100 <= 42))
		{
			cout << "Arcane Scroll of Eyebite (Caster level 11)" << endl;
		}
		else if(d100 == 43)
		{
			cout << "Arcane Scroll of Find the Path (Caster level 11)" << endl;
		}
		else if((44 <= d100) && (d100 <= 45))
		{
			cout << "Arcane Scroll of Flesh to Stone (Caster level 11)" << endl;
		}
		else if((46 <= d100) && (d100 <= 48))
		{
			cout << "Arcane Scroll of Mass Fox's Cunning (Caster level 11)" << endl;
		}
		else if(d100 == 49)
		{
			cout << "Arcane Scroll of Geas/Quest (Caster level 11)" << endl;
		}
		else if((50 <= d100) && (d100 <= 52))
		{
			cout << "Arcane Scroll of Globe of Invulnerability (Caster level 11)" << endl;
		}
		else if(d100 == 53)
		{
			cout << "Arcane Scroll of Guards and Wards (Caster level 11)" << endl;
		}
		else if(d100 == 54)
		{
			cout << "Arcane Scroll of Heroes' Feast (Caster level 11)" << endl;
		}
		else if((55 <= d100) && (d100 <= 56))
		{
			cout << "Arcane Scroll of Greater Heroism (Caster level 11)" << endl;
		}
		else if(d100 == 57)
		{
			cout << "Arcane Scroll of Legend Lore (Caster level 11)" << endl;
		}
		else if((58 <= d100) && (d100 <= 59))
		{
			cout << "Arcane Scroll of Mislead (Caster level 11)" << endl;
		}
		else if(d100 == 60)
		{
			cout << "Arcane Scroll of Mordenkainen's Lucubration (Caster level 11)" << endl;
		}
		else if((61 <= d100) && (d100 <= 62))
		{
			cout << "Arcane Scroll of Move Earth (Caster level 11)" << endl;
		}
		else if((63 <= d100) && (d100 <= 64))
		{
			cout << "Arcane Scroll of Otiluke's Freezing Sphere (Caster level 11)" << endl;
		}
		else if((65 <= d100) && (d100 <= 67))
		{
			cout << "Arcane Scroll of Mass Owl's Wisdom (Caster level 11)" << endl;
		}
		else if((68 <= d100) && (d100 <= 69))
		{
			cout << "Arcane Scroll of Permanent Image (Caster level 11)" << endl;
		}
		else if((70 <= d100) && (d100 <= 71))
		{
			cout << "Arcane Scroll of Planar Binding (Caster level 11)" << endl;
		}
		else if((72 <= d100) && (d100 <= 73))
		{
			cout << "Arcane Scroll of Programmed Image (Caster level 11)" << endl;
		}
		else if((74 <= d100) && (d100 <= 75))
		{
			cout << "Arcane Scroll of Repulsion (Caster level 11)" << endl;
		}
		else if((76 <= d100) && (d100 <= 78))
		{
			cout << "Arcane Scroll of Shadow Walk (Caster level 11)" << endl;
		}
		else if((79 <= d100) && (d100 <= 81))
		{
			cout << "Arcane Scroll of Stone to Flesh (Caster level 11)" << endl;
		}
		else if((82 <= d100) && (d100 <= 83))
		{
			cout << "Arcane Scroll of Mass Suggestion (Caster level 11)" << endl;
		}
		else if((84 <= d100) && (d100 <= 85))
		{
			cout << "Arcane Scroll of Summon Monster VI (Caster level 11)" << endl;
		}
		else if(d100 == 86)
		{
			cout << "Arcane Scroll of Symbol of Fear (Caster level 11)" << endl;
		}
		else if(d100 == 87)
		{
			cout << "Arcane Scroll of Symbol of Persuasion (Caster level 11)" << endl;
		}
		else if(d100 == 88)
		{
			cout << "Arcane Scroll of Sympathetic Vibration (Caster level 11)" << endl;
		}
		else if((89 <= d100) && (d100 <= 90))
		{
			cout << "Arcane Scroll of Tenser's Transformation (Caster level 11)" << endl;
		}
		else if((91 <= d100) && (d100 <= 93))
		{
			cout << "Arcane Scroll of True Seeing (Caster level 11)" << endl;
		}
		else if((94 <= d100) && (d100 <= 95))
		{
			cout << "Arcane Scroll of Undeath to Death (Caster level 11)" << endl;
		}
		else if((96 <= d100) && (d100 <= 97))
		{
			cout << "Arcane Scroll of Veil (Caster level 11)" << endl;
		}
		else
		{
			cout << "Arcane Scroll of Wall of Iron (Caster level 11)" << endl;
		}
	}
	void ASpell_7()
	{
		int d100 = rand()%100+1;
		if((1 <= d100) && (d100 <= 3))
		{
			cout << "Arcane Scroll of Greater Arcane Sight (Caster level 13)" << endl;
		}
		else if((4 <= d100) && (d100 <= 7))
		{
			cout << "Arcane Scroll of Banishment (Caster level 13)" << endl;
		}
		else if((8 <= d100) && (d100 <= 10))
		{
			cout << "Arcane Scroll of Bigby's Grasping Hand (Caster level 13)" << endl;
		}
		else if((11 <= d100) && (d100 <= 13))
		{
			cout << "Arcane Scroll of Control Undead (Caster level 13)" << endl;
		}
		else if((14 <= d100) && (d100 <= 16))
		{
			cout << "Arcane Scroll of Control Weather (Caster level 13)" << endl;
		}
		else if((17 <= d100) && (d100 <= 19))
		{
			cout << "Arcane Scroll of Delayed Blast Fireball (Caster level 13)" << endl;
		}
		else  if((20 <= d100) && (d100 <= 21))
		{
			cout << "Arcane Scroll of Drawmij's Instant Summons (Caster level 13)" << endl;
		}
		else if((22 <= d100) && (d100 <= 25))
		{
			cout << "Arcane Scroll of Ethereal Jaunt (Caster level 13)" << endl;
		}
		else if((26 <= d100) && (d100 <= 28))
		{
			cout << "Arcane Scroll of Finger of Death (Caster level 13)" << endl;
		}
		else if((29 <= d100) && (d100 <= 31))
		{
			cout << "Arcane Scroll of Forcecage (Caster level 13)" << endl;
		}
		else if((32 <= d100) && (d100 <= 35))
		{
			cout << "Arcane Scroll of Mass Hold Person (Caster level 13)" << endl;
		}
		else if((36 <= d100) && (d100 <= 38))
		{
			cout << "Arcane Scroll of Insanity (Caster level 13)" << endl;
		}
		else if((39 <= d100) && (d100 <= 42))
		{
			cout << "Arcane Scroll of Mass Invisibility (Caster level 13)" << endl;
		}
		else if(d100 == 43)
		{
			cout << "Arcane Scroll of Limited Wish (Caster level 13)" << endl;
		}
		else if((44 <= d100) && (d100 <= 45))
		{
			cout << "Arcane Scroll of Mordenkainen's Magnificent Mansion (Caster level 13)" << endl;
		}
		else if((46 <= d100) && (d100 <= 48))
		{
			cout << "Arcane Scroll of Mordenkainen's Sword (Caster level 13)" << endl;
		}
		else if((49 <= d100) && (d100 <= 51))
		{
			cout << "Arcane Scroll of Phase Door (Caster level 13)" << endl;
		}
		else if((52 <= d100) && (d100 <= 54))
		{
			cout << "Arcane Scroll of Plane Shift (Caster level 13)" << endl;
		}
		else if((55 <= d100) && (d100 <= 57))
		{
			cout << "Arcane Scroll of Power Word Blind (Caster level 13)" << endl;
		}
		else if((58 <= d100) && (d100 <= 61))
		{
			cout << "Arcane Scroll of Prismatic Spray (Caster level 13)" << endl;
		}
		else if((62 <= d100) && (d100 <= 64))
		{
			cout << "Arcane Scroll of Project Image (Caster level 13)" << endl;
		}
		else  if((65 <= d100) && (d100 <= 67))
		{
			cout << "Arcane Scroll of Reverse Gravity (Caster level 13)" << endl;
		}
		else if((68 <= d100) && (d100 <= 70))
		{
			cout << "Arcane Scroll of Greater Scrying (Caster level 13)" << endl;
		}
		else if((71 <= d100) && (d100 <= 73))
		{
			cout << "Arcane Scroll of Sequester (Caster level 13)" << endl;
		}
		else if((74 <= d100) && (d100 <= 76))
		{
			cout << "Arcane Scroll of Greater Shadow Conjuration (Caster level 13)" << endl;
		}
		else if(d100 == 77)
		{
			cout << "Arcane Scroll of Simulacrum (Caster level 13)" << endl;
		}
		else if((78 <= d100) && (d100 <= 80))
		{
			cout << "Arcane Scroll of Spell Turning (Caster level 13)" << endl;
		}
		else if((81 <= d100) && (d100 <= 82))
		{
			cout << "Arcane Scroll of Statue (Caster level 13)" << endl;
		}
		else if((83 <= d100) && (d100 <= 85))
		{
			cout << "Arcane Scroll of Summon Monster VII (Caster level 13)" << endl;
		}
		else if(d100 == 86)
		{
			cout << "Arcane Scroll of Symbol of Stunning (Caster level 13)" << endl;
		}
		else if(d100 == 87)
		{
			cout << "Arcane Scroll of Symbol of Weakness (Caster level 13)" << endl;
		}
		else if((88 <= d100) && (d100 <= 90))
		{
			cout << "Arcane Scroll of Teleport Object (Caster level 13)" << endl;
		}
		else if((91 <= d100) && (d100 <= 95))
		{
			cout << "Arcane Scroll of Greater Teleport (Caster level 13)" << endl;
		}
		else if((96 <= d100) && (d100 <= 97))
		{
			cout << "Arcane Scroll of Vision (Caster level 13)" << endl;
		}
		else
		{
			cout << "Arcane Scroll of Waves of Exhaustion (Caster level 13)" << endl;
		}
	}
	void ASpell_8()
	{
		int d100 = rand()%100+1;
		if((1 <= d100) && (d100 <= 2))
		{
			cout << "Arcane Scroll of Antipathy (Caster level 15)" << endl;
		}
		else if((3 <= d100) && (d100 <= 5))
		{
			cout << "Arcane Scroll of Bigby's Clenched Fist (Caster level 15)" << endl;
		}
		else if((6 <= d100) && (d100 <= 8))
		{
			cout << "Arcane Scroll of Binding (Caster level 15)" << endl;
		}
		else if((9 <= d100) && (d100 <= 12))
		{
			cout << "Arcane Scroll of Mass Charm Monster (Caster level 15)" << endl;
		}
		else if(d100 == 13)
		{
			cout << "Arcane Scroll of Clone (Caster level 15)" << endl;
		}
		else if((14 <= d100) && (d100 <= 16))
		{
			cout << "Arcane Scroll of Create Greater Undead (Caster level 15)" << endl;
		}
		else if((17 <= d100) && (d100 <= 19))
		{
			cout << "Arcane Scroll of Demand (Caster level 15)" << endl;
		}
		else if((20 <= d100) && (d100 <= 22))
		{
			cout << "Arcane Scroll of Dimensional Lock (Caster level 15)" << endl;
		}
		else if((23 <= d100) && (d100 <= 26))
		{
			cout << "Arcane Scroll of Discern Location (Caster level 15)" << endl;
		}
		else if((27 <= d100) && (d100 <= 29))
		{
			cout << "Arcane Scroll of Horrid Wilting (Caster level 15)" << endl;
		}
		else if((30 <= d100) && (d100 <= 32))
		{
			cout << "Arcane Scroll of Incendiary Cloud (Caster level 15)" << endl;
		}
		else if((33 <= d100) && (d100 <= 35))
		{
			cout << "Arcane Scroll of Iron Body (Caster level 15)" << endl;
		}
		else if((36 <= d100) && (d100 <= 38))
		{
			cout << "Arcane Scroll of Maze (Caster level 15)" << endl;
		}
		else if((39 <= d100) && (d100 <= 41))
		{
			cout << "Arcane Scroll of Mind Blank (Caster level 15)" << endl;
		}
		else if((43 <= d100) && (d100 <= 44))
		{
			cout << "Arcane Scroll of Moment of Prescience (Caster level 15)" << endl;
		}
		else if((45 <= d100) && (d100 <= 48))
		{
			cout << "Arcane Scroll of Otiluke's Telekinetic Sphere (Caster level 15)" << endl;
		}
		else if((49 <= d100) && (d100 <= 51))
		{
			cout << "Arcane Scroll of Otto's Irresistable Dance (Caster level 15)" << endl;
		}
		else if((52 <= d100) && (d100 <= 54))
		{
			cout << "Arcane Scroll of Greater Planar Binding (Caster level 15)" << endl;
		}
		else if((55 <= d100) && (d100 <= 57))
		{
			cout << "Arcane Scroll of Polar Ray (Caster level 15)" << endl;
		}
		else if((58 <= d100) && (d100 <= 60))
		{
			cout << "Arcane Scroll of Polymorph Any Object (Caster level 15)" << endl;
		}
		else if((61 <= d100) && (d100 <= 63))
		{
			cout << "Arcane Scroll of Power Word Stun (Caster level 15)" << endl;
		}
		else if((64 <= d100) && (d100 <= 66))
		{
			cout << "Arcane Scroll of Prismatic Wall (Caster level 15)" << endl;
		}
		else if((67 <= d100) && (d100 <= 70))
		{
			cout << "Arcane Scroll of Protection from Spells (Caster level 15)" << endl;
		}
		else if((71 <= d100) && (d100 <= 73))
		{
			cout << "Arcane Scroll of Greater Prying Eyes (Caster level 15)" << endl;
		}
		else if((74 <= d100) && (d100 <= 76))
		{
			cout << "Arcane Scroll of Scintillating Pattern (Caster level 15)" << endl;
		}
		else if((77 <= d100) && (d100 <= 78))
		{
			cout << "Arcane Scroll of Screen (Caster level 15)" << endl;
		}
		else if((79 <= d100) && (d100 <= 81))
		{
			cout << "Arcane Scroll of Greater Shadow Evocation (Caster level 15)" << endl;
		}
		else if((82 <= d100) && (d100 <= 84))
		{
			cout << "Arcane Scroll of Greater Shout (Caster level 15)" << endl;
		}
		else if((85 <= d100) && (d100 <= 87))
		{
			cout << "Arcane Scroll of Summon Monster VIII (Caster level 15)" << endl;
		}
		else if((88 <= d100) && (d100 <= 90))
		{
			cout << "Arcane Scroll of Sunburst (Caster level 15)" << endl;
		}
		else if(d100 == 91)
		{
			cout << "Arcane Scroll of Symbol of Death (Caster level 15)" << endl;
		}
		else if(d100 == 92)
		{
			cout << "Arcane Scroll of Symbol of Insanity (Caster level 15)" << endl;
		}
		else if((93 <= d100) && (d100 <= 94))
		{
			cout << "Arcane Scroll of Sympathy (Caster level 15)" << endl;
		}
		else if((95 <= d100) && (d100 <= 98))
		{
			cout << "Arcane Scroll of Temporal Stasis (Caster level 15)" << endl;
		}
		else
		{
			cout << "Arcane Scroll of Trap the Soul (Caster level 15)" << endl;
		}
	}
	void ASpell_9()
	{
		int d100 = rand()%100+1;
		if((1 <= d100) && (d100 <= 3))
		{
			cout << "Arcane Scroll of Astral Projection (Caster level 17)" << endl;
		}
		else if((4 <= d100) && (d100 <= 7))
		{
			cout << "Arcane Scroll of Bigby's Crushing Hand (Caster level 17)" << endl;
		}
		else if((8 <= d100) && (d100 <= 12))
		{
			cout << "Arcane Scroll of Dominate Monster (Caster level 17)" << endl;
		}
		else if((13 <= d100) && (d100 <= 16))
		{
			cout << "Arcane Scroll of Energy Drain (Caster level 17)" << endl;
		}
		else if((17 <= d100) && (d100 <= 21))
		{
			cout << "Arcane Scroll of Etherealness (Caster level 17)" << endl;
		}
		else if((22 <= d100) && (d100 <= 25))
		{
			cout << "Arcane Scroll of Foresight (Caster level 17)" << endl;
		}
		else if((26 <= d100) && (d100 <= 31))
		{
			cout << "Arcane Scroll of Freedom (Caster level 17)" << endl;
		}
		else if((32 <= d100) && (d100 <= 36))
		{
			cout << "Arcane Scroll of Gate (Caster level 17)" << endl;
		}
		else if((37 <= d100) && (d100 <= 40))
		{
			cout << "Arcane Scroll of Mass Hold Monster (Caster level 17)" << endl;
		}
		else if((41 <= d100) && (d100 <= 44))
		{
			cout << "Arcane Scroll of Imprisonment (Caster level 17)" << endl;
		}
		else if((45 <= d100) && (d100 <= 49))
		{
			cout << "Arcane Scroll of Meteor Swarm (Caster level 17)" << endl;
		}
		else if((50 <= d100) && (d100 <= 53))
		{
			cout << "Arcane Scroll of Mordenkainen's Disjunction (Caster level 17)" << endl;
		}
		else if((54 <= d100) && (d100 <= 58))
		{
			cout << "Arcane Scroll of Power Word Kill (Caster level 17)" << endl;
		}
		else if((59 <= d100) && (d100 <= 62))
		{
			cout << "Arcane Scroll of Prismatic Sphere (Caster level 17)" << endl;
		}
		else if((63 <= d100) && (d100 <= 66))
		{
			cout << "Arcane Scroll of Refuge (Caster level 17)" << endl;
		}
		else if((67 <= d100) && (d100 <= 70))
		{
			cout << "Arcane Scroll of Shades (Caster level 17)" << endl;
		}
		else if((71 <= d100) && (d100 <= 76))
		{
			cout << "Arcane Scroll of Shapechange (Caster level 17)" << endl;
		}
		else if((77 <= d100) && (d100 <= 79))
		{
			cout << "Arcane Scroll of Soul Bind (Caster level 17)" << endl;
		}
		else if((80 <= d100) && (d100 <= 83))
		{
			cout << "Arcane Scroll of Summon Monster IX (Caster level 17)" << endl;
		}
		else if((84 <= d100) && (d100 <= 86))
		{
			cout << "Arcane Scroll of Teleportation Circle (Caster level 17)" << endl;
		}
		else if((87 <= d100) && (d100 <= 91))
		{
			cout << "Arcane Scroll of Time Stop (Caster level 17)" << endl;
		}
		else if((92 <= d100) && (d100 <= 95))
		{
			cout << "Arcane Scroll of Wail of the Banshee (Caster level 17)" << endl;
		}
		else if((96 <= d100) && (d100 <= 99))
		{
			cout << "Arcane Scroll of Weird (Caster level 17)" << endl;
		}
		else
		{
			cout << "Arcane Scroll of Wish (Caster level 17)" << endl;
		}
	}
void minorDScroll()
{
	int d3 = rand()%3+1;
	int d100;
	for(int x=0; x<d3; x++)
	{
		d100 = rand()%100+1;
		if((1 <= d100) && (d100 <= 5))
		{
			DSpell_0();
		}
		else if((6 <= d100) && (d100 <= 50))
		{
			DSpell_1();
		}
		else if((51 <= d100) && (d100 <= 95))
		{
			DSpell_2();
		}
		else
		{
			DSpell_3();
		}
	}
}
void mediumDScroll()
{
	int d4 = rand()%4+1;
	int d100;
	for(int x=0; x<d4; x++)
	{
		d100 = rand()%100+1;
		if((1 <= d100) && (d100 <= 5))
		{
			DSpell_2();
		}
		else if((6 <= d100) && (d100 <= 65))
		{
			DSpell_3();
		}
		else if((66 <= d100) && (d100 <= 95))
		{
			DSpell_4();
		}
		else
		{
			DSpell_5();
		}
	}	
}
void majorDScroll()
{
	int d6 = rand()%6+1;
	int d100;
	for(int x=0; x<d6; x++)
	{
		d100 = rand()%100+1;
		if((1 <= d100) && (d100 <= 5))
		{
			DSpell_4();
		}
		else if((6 <= d100) && (d100 <= 50))
		{
			DSpell_5();
		}
		else if((51 <= d100) && (d100 <= 70))
		{
			DSpell_6();
		}
		else if((71 <= d100) && (d100 <= 85))
		{
			DSpell_7();
		}
		else if((86 <= d100) && (d100 <= 94))
		{
			DSpell_8();
		}
		else
		{
			DSpell_9();
		}
	}
}
	void DSpell_0()
	{
		int d100 = rand()%100+1;
		if((1 <= d100) && (d100 <= 7))
		{
			cout << "Divine Scroll of Create Water (Caster level 1)" << endl;
		}
		else if((8 <= d100) && (d100 <= 14))
		{
			cout << "Divine Scroll of Cure Minor Wounds (Caster level 1)" << endl;
		}
		else if((15 <= d100) && (d100 <= 22))
		{
			cout << "Divine Scroll of Detect Magic (Caster level 1)" << endl;
		}
		else if((23 <= d100) && (d100 <= 29))
		{
			cout << "Divine Scroll of Detect Poison (Caster level 1)" << endl;
		}
		else if((30 <= d100) && (d100 <= 36))
		{
			cout << "Divine Scroll of Flare (Caster level 1)" << endl;
		}
		else if((37 <= d100) && (d100 <= 43))
		{
			cout << "Divine Scroll of Guidance (Caster level 1)" << endl;
		}
		else if((44 <= d100) && (d100 <= 50))
		{
			cout << "Divine Scroll of Inflict Minor Wounds (Caster level 1)" << endl;
		}
		else if((51 <= d100) && (d100 <= 57))
		{
			cout << "Divine Scroll of Know Direction (Caster level 1)" << endl;
		}
		else if((58 <= d100) && (d100 <= 65))
		{
			cout << "Divine Scroll of Light (Caster level 1)" << endl;
		}
		else if((66 <= d100) && (d100 <= 72))
		{
			cout << "Divine Scroll of Mending (Caster level 1)" << endl;
		}
		else if((73 <= d100) && (d100 <= 79))
		{
			cout << "Divine Scroll of Purify Food and Drink (Caster level 1)" << endl;
		}
		else if((80 <= d100) && (d100 <= 86))
		{
			cout << "Divine Scroll of Read Magic (Caster level 1)" << endl;
		}
		else if((87 <= d100) && (d100 <= 93))
		{
			cout << "Divine Scroll of Resistance (Caster level 1)" << endl;
		}
		else
		{
			cout << "Divine Scroll of Virtue (Caster level 1)" << endl;
		}
	}
	void DSpell_1()
	{
		int d100 = rand()%100+1;
		if(d100 == 1)
		{
			cout << "Divine Scroll of Alarm (Caster level 1)" << endl;
		}
		else if((2 <= d100) && (d100 <= 3))
		{
			cout << "Divine Scroll of Bane (Caster level 1)" << endl;
		}
		else if((4 <= d100) && (d100 <= 6))
		{
			cout << "Divine Scroll of Bless (Caster level 1)" << endl;
		}
		else if((7 <= d100) && (d100 <= 9))
		{
			cout << "Divine Scroll of Bless Water (Caster level 1)" << endl;
		}
		else if(d100 == 10)
		{
			cout << "Divine Scroll of Bless Weapon (Caster level 1)" << endl;
		}
		else if((11 <= d100) && (d100 <= 12))
		{
			cout << "Divine Scroll of Calm Animals (Caster level 1)" << endl;
		}
		else if((13 <= d100) && (d100 <= 14))
		{
			cout << "Divine Scroll of Cause Fear (Caster level 1)" << endl;
		}
		else if((15 <= d100) && (d100 <= 16))
		{
			cout << "Divine Scroll of Charm Animal (Caster level 1)" << endl;
		}
		else if((17 <= d100) && (d100 <= 19))
		{
			cout << "Divine Scroll of Command (Caster level 1)" << endl;
		}
		else if((20 <= d100) && (d100 <= 21))
		{
			cout << "Divine Scroll of Comprehend Languages (Caster level 1)" << endl;
		}
		else if((22 <= d100) && (d100 <= 26))
		{
			cout << "Divine Scroll of Cure Light Wounds (Caster level 1)" << endl;
		}
		else if((27 <= d100) && (d100 <= 28))
		{
			cout << "Divine Scroll of Curse Water (Caster level 1)" << endl;
		}
		else if((29 <= d100) && (d100 <= 30))
		{
			cout << "Divine Scroll of Deathwatch (Caster level 1)" << endl;
		}
		else if((31 <= d100) && (d100 <= 32))
		{
			cout << "Divine Scroll of Detect Animals or Plants (Caster level 1)" << endl;
		}
		else if((33 <= d100) && (d100 <= 35))
		{
			int d4 = rand()%4+1;
			switch(d4)
			{
			case 1:
				cout << "Divine Scroll of Detect Chaos (Caster level 1)" << endl;
				break;
			case 2:
				cout << "Divine Scroll of Detect Evil (Caster level 1)" << endl;
				break;
			case 3:
				cout << "Divine Scroll of Detect Good (Caster level 1)" << endl;
				break;
			case 4:
				cout << "Divine Scroll of Detect Law (Caster level 1)" << endl;
				break;
			}
		}
		else if((36 <= d100) && (d100 <= 37))
		{
			cout << "Divine Scroll of Detect Snares and Pits (Caster level 1)" << endl;
		}
		else if((38 <= d100) && (d100 <= 39))
		{
			cout << "Divine Scroll of Detect Undead (Caster level 1)" << endl;
		}
		else if((40 <= d100) && (d100 <= 41))
		{
			cout << "Divine Scroll of Divine Favor (Caster level 1)" << endl;
		}
		else if((42 <= d100) && (d100 <= 43))
		{
			cout << "Divine Scroll of Doom (Caster level 1)" << endl;
		}
		else if((44 <= d100) && (d100 <= 48))
		{
			cout << "Divine Scroll of Endure Elements (Caster level 1)" << endl;
		}
		else if((49 <= d100) && (d100 <= 50))
		{
			cout << "Divine Scroll of Entangle (Caster level 1)" << endl;
		}
		else if((51 <= d100) && (d100 <= 52))
		{
			cout << "Divine Scroll of Entropic Shield (Caster level 1)" << endl;
		}
		else if((53 <= d100) && (d100 <= 54))
		{
			cout << "Divine Scroll of Faerie Fire (Caster level 1)" << endl;
		}
		else if((55 <= d100) && (d100 <= 56))
		{
			cout << "Divine Scroll of Goodberry (Caster level 1)" << endl;
		}
		else if((57 <= d100) && (d100 <= 58))
		{
			cout << "Divine Scroll of Hide from Animals (Caster level 1)" << endl;
		}
		else if((59 <= d100) && (d100 <= 60))
		{
			cout << "Divine Scroll of Hide from Undead (Caster level 1)" << endl;
		}
		else if((61 <= d100) && (d100 <= 62))
		{
			cout << "Divine Scroll of Inflict Light Wounds (Caster level 1)" << endl;
		}
		else if((63 <= d100) && (d100 <= 64))
		{
			cout << "Divine Scroll of Jump (Caster level 1)" << endl;
		}
		else if((65 <= d100) && (d100 <= 66))
		{
			cout << "Divine Scroll of Longstrider (Caster level 1)" << endl;
		}
		else if((67 <= d100) && (d100 <= 68))
		{
			cout << "Divine Scroll of Magic Fang (Caster level 1)" << endl;
		}
		else if((69 <= d100) && (d100 <= 72))
		{
			cout << "Divine Scroll of Magic Stone (Caster level 1)" << endl;
		}
		else if((73 <= d100) && (d100 <= 74))
		{
			cout << "Divine Scroll of Magic Weapon (Caster level 1)" << endl;
		}
		else if((75 <= d100) && (d100 <= 78))
		{
			cout << "Divine Scroll of Obscuring Mist (Caster level 1)" << endl;
		}
		else if((79 <= d100) && (d100 <= 80))
		{
			cout << "Divine Scroll of Pass Without Trace (Caster level 1)" << endl;
		}
		else if((81 <= d100) && (d100 <= 82))
		{
			cout << "Divine Scroll of Produce Flame (Caster level 1)" << endl;
		}
		else if((83 <= d100) && (d100 <= 86))
		{
			int d4 = rand()%4+1;
			switch(d4)
			{
			case 1:
				cout << "Divine Scroll of Protection from Chaos (Caster level 1)" << endl;
				break;
			case 2:
				cout << "Divine Scroll of Protection from Evil (Caster level 1)" << endl;
				break;
			case 3:
				cout << "Divine Scroll of Protection from Good (Caster level 1)" << endl;
				break;
			case 4:
				cout << "Divine Scroll of Protection from Law (Caster level 1)" << endl;
				break;
			}
		}
		else if((87 <= d100) && (d100 <= 88))
		{
			cout << "Divine Scroll of Remove Fear (Caster level 1)" << endl;
		}
		else if((89 <= d100) && (d100 <= 90))
		{
			cout << "Divine Scroll of Sanctuary (Caster level 1)" << endl;
		}
		else if((91 <= d100) && (d100 <= 92))
		{
			cout << "Divine Scroll of Shield of Faith (Caster level 1)" << endl;
		}
		else if((93 <= d100) && (d100 <= 94))
		{
			cout << "Divine Scroll of Shillelagh (Caster level 1)" << endl;
		}
		else if((95 <= d100) && (d100 <= 96))
		{
			cout << "Divine Scroll of Speak with Animals (Caster level 1)" << endl;
		}
		else if((97 <= d100) && (d100 <= 98))
		{
			cout << "Divine Scroll of Summon Monster I (Caster level 1)" << endl;
		}
		else
		{
			cout << "Divine Scroll of Summmon Nature's Ally I (Caster level 1)" << endl;
		}
	}
	void DSpell_2()
	{
		int d100 = rand()%100+1;
		if(d100 == 1)
		{
			cout << "Divine Scroll of Animal Messenger (Caster level 3)" << endl;
		}
		else if(d100 == 2)
		{
			cout << "Divine Scroll of Animal Trance (Caster level 3)" << endl;
		}
		else if((3 <= d100) && (d100 <= 4))
		{
			cout << "Divine Scroll of Augury (Caster level 3)" << endl;
		}
		else if((5 <= d100) && (d100 <= 6))
		{
			cout << "Divine Scroll of Barkskin (Caster level 3)" << endl;
		}
		else if((7 <= d100) && (d100 <= 9))
		{
			cout << "Divine Scroll of Bear's Endurance (Caster level 3)" << endl;
		}
		else if((10 <= d100) && (d100 <= 12))
		{
			cout << "Divine Scroll of Bull's Strength (Caster level 3)" << endl;
		}
		else if((13 <= d100) && (d100 <= 14))
		{
			cout << "Divine Scroll of Calm Emotions (Caster level 3)" << endl;
		}
		else if((15 <= d100) && (d100 <= 17))
		{
			cout << "Divine Scroll of Cat's Grace (Caster level 3)" << endl;
		}
		else if(d100 == 18)
		{
			cout << "Divine Scroll of Chill Metal (Caster level 3)" << endl;
		}
		else if((19 <= d100) && (d100 <= 20))
		{
			cout << "Divine Scroll of Concecrate (Caster level 3)" << endl;
		}
		else if((21 <= d100) && (d100 <= 24))
		{
			cout << "Divine Scroll of Cure Moderate Wounds (Caster level 3)" << endl;
		}
		else if((25 <= d100) && (d100 <= 26))
		{
			cout << "Divine Scroll of Darkness (Caster level 3)" << endl;
		}
		else if(d100 == 27)
		{
			cout << "Divine Scroll of Death Knell (Caster level 3)" << endl;
		}
		else if((28 <= d100) && (d100 <= 30))
		{
			cout << "Divine Scroll of Delay Poison (Caster level 3)" << endl;
		}
		else if((31 <= d100) && (d100 <= 32))
		{
			cout << "Divine Scroll of Desecrate (Caster level 3)" << endl;
		}
		else if((33 <= d100) && (d100 <= 35))
		{
			cout << "Divine Scroll of Eagle's Splendor (Caster level 3)" << endl;
		}
		else if((36 <= d100) && (d100 <= 37))
		{
			cout << "Divine Scroll of Enthrall (Caster level 3)" << endl;
		}
		else if((38 <= d100) && (d100 <= 39))
		{
			cout << "Divine Scroll of Find Traps (Caster level 3)" << endl;
		}
		else if(d100 == 40)
		{
			cout << "Divine Scroll of Fire Trap (Caster level 3)" << endl;
		}
		else if((41 <= d100) && (d100 <= 42))
		{
			cout << "Divine Scroll of Flame Blade (Caster level 3)" << endl;
		}
		else if((43 <= d100) && (d100 <= 44))
		{
			cout << "Divine Scroll of Flaming Sphere (Caster level 3)" << endl;
		}
		else if((45 <= d100) && (d100 <= 46))
		{
			cout << "Divine Scroll of Fog Cloud (Caster level 3)" << endl;
		}
		else if(d100 == 47)
		{
			cout << "Divine Scroll of Gentle Repose (Caster level 3)" << endl;
		}
		else if(d100 == 48)
		{
			cout << "Divine Scroll of Gust of Wind (Caster level 3)" << endl;
		}
		else if(d100 == 49)
		{
			cout << "Divine Scroll of Heat Metal (Caster level 3)" << endl;
		}
		else if((50 <= d100) && (d100 <= 51))
		{
			cout << "Divine Scroll of Hold Animal (Caster level 3)" << endl;
		}
		else if((52 <= d100) && (d100 <= 54))
		{
			cout << "Divine Scroll of Hold Person (Caster level 3)" << endl;
		}
		else if((55 <= d100) && (d100 <= 56))
		{
			cout << "Divine Scroll of Inflict Moderate Wounds (Caster level 3)" << endl;
		}
		else if((57 <= d100) && (d100 <= 58))
		{
			cout << "Divine Scroll of Make Whole (Caster level 3)" << endl;
		}
		else if((59 <= d100) && (d100 <= 61))
		{
			cout << "Divine Scroll of Owl's Wisdom (Caster level 3)" << endl;
		}
		else if(d100 == 62)
		{
			cout << "Divine Scroll of Reduce Animal (Caster level 3)" << endl;
		}
		else if((63 <= d100) && (d100 <= 64))
		{
			cout << "Divine Scroll of Remove Paralysis (Caster level 3)" << endl;
		}
		else if((65 <= d100) && (d100 <= 67))
		{
			cout << "Divine Scroll of Resist Energy (Caster level 3)" << endl;
		}
		else if((68 <= d100) && (d100 <= 70))
		{
			cout << "Divine Scroll of Lesser Restoration (Caster level 3)" << endl;
		}
		else if((71 <= d100) && (d100 <= 72))
		{
			cout << "Divine Scroll of Shatter (Caster level 3)" << endl;
		}
		else if((73 <= d100) && (d100 <= 74))
		{
			cout << "Divine Scroll of Shield Other (Caster level 3)" << endl;
		}
		else if((75 <= d100) && (d100 <= 76))
		{
			cout << "Divine Scroll of Silence (Caster level 3)" << endl;
		}
		else if(d100 == 77)
		{
			cout << "Divine Scroll of Snare (Caster level 3)" << endl;
		}
		else if(d100 == 78)
		{
			cout << "Divine Scroll of Soften Earth and Stone (Caster level 3)" << endl;
		}
		else if((79 <= d100) && (d100 <= 80))
		{
			cout << "Divine Scroll of Sound Burst (Caster level 3)" << endl;
		}
		else if(d100 == 81)
		{
			cout << "Divine Scroll of Speak With Plants (Caster level 3)" << endl;
		}
		else if((82 <= d100) && (d100 <= 83))
		{
			cout << "Divine Scroll of Spider Climb (Caster level 3)" << endl;
		}
		else if((84 <= d100) && (d100 <= 85))
		{
			cout << "Divine Scroll of Spiritual Weapon (Caster level 3)" << endl;
		}
		else if(d100 == 86)
		{
			cout << "Divine Scroll of Status (Caster level 3)" << endl;
		}
		else if((87 <= d100) && (d100 <= 88))
		{
			cout << "Divine Scroll of Summon Monster II (Caster level 3)" << endl;
		}
		else if((89 <= d100) && (d100 <= 90))
		{
			cout << "Divine Scroll of Summon Nature's Ally II (Caster level 3)" << endl;
		}
		else if((91 <= d100) && (d100 <= 92))
		{
			cout << "Divine Scroll of Summon Swarm (Caster level 3)" << endl;
		}
		else if(d100 == 93)
		{
			cout << "Divine Scroll of Tree Shape (Caster level 3)" << endl;
		}
		else if((94 <= d100) && (d100 <= 95))
		{
			cout << "Divine Scroll of Undetectable Alignment (Caster level 3)" << endl;
		}
		else if((96 <= d100) && (d100 <= 97))
		{
			cout << "Divine Scroll of Warp Wood (Caster level 3)" << endl;
		}
		else if(d100 == 98)
		{
			cout << "Divine Scroll of Wood Shape (Caster level 3)" << endl;
		}
		else
		{
			cout << "Divine Scroll of Zone of Truth (Caster level 3)" << endl;
		}
	}
	void DSpell_3()
	{
		int d100 = rand()%100+1;
		if((1 <= d100) && (d100 <= 2))
		{
			cout << "Divine Scroll of Animate Dead (Caster level 5)" << endl;
		}
		else if((3 <= d100) && (d100 <= 4))
		{
			cout << "Divine Scroll of Bestow Curse (Caster level 5)" << endl;
		}
		else if((5 <= d100) && (d100 <= 6))
		{
			cout << "Divine Scroll of Blindness/Deafness (Caster level 5)" << endl;
		}
		else if((7 <= d100) && (d100 <= 8))
		{
			cout << "Divine Scroll of Call Lightning (Caster level 5)" << endl;
		}
		else if((9 <= d100) && (d100 <= 10))
		{
			cout << "Divine Scroll of Contagion (Caster level 5)" << endl;
		}
		else if((11 <= d100) && (d100 <= 12))
		{
			cout << "Divine Scroll of Continual Flame (Caster level 5)" << endl;
		}
		else if((13 <= d100) && (d100 <= 14))
		{
			cout << "Divine Scroll of Create Food and Water (Caster level 5)" << endl;
		}
		else if((15 <= d100) && (d100 <= 18))
		{
			cout << "Divine Scroll of Cure Serious Wounds (Caster level 5)" << endl;
		}
		else if(d100 == 19)
		{
			cout << "Divine Scroll of Darkvision (Caster level 5)" << endl;
		}
		else if((20 <= d100) && (d100 <= 21))
		{
			cout << "Divine Scroll of Daylight (Caster level 5)" << endl;
		}
		else if((22 <= d100) && (d100 <= 23))
		{
			cout << "Divine Scroll of Deeper Darkness (Caster level 5)" << endl;
		}
		else if((24 <= d100) && (d100 <= 25))
		{
			cout << "Divine Scroll of Diminish Plants (Caster level 5)" << endl;
		}
		else if((26 <= d100) && (d100 <= 27))
		{
			cout << "Divine Scroll of Dispel Magic (Caster level 5)" << endl;
		}
		else if((28 <= d100) && (d100 <= 29))
		{
			cout << "Divine Scroll of Dominate Animal (Caster level 5)" << endl;
		}
		else if((30 <= d100) && (d100 <= 31))
		{
			cout << "Divine Scroll of Glyph of Warding (Caster level 5)" << endl;
		}
		else if(d100 == 32)
		{
			cout << "Divine Scroll of Heal Mount (Caster level 5)" << endl;
		}
		else if((33 <= d100) && (d100 <= 34))
		{
			cout << "Divine Scroll of Helping Hand (Caster level 5)" << endl;
		}
		else if((35 <= d100) && (d100 <= 36))
		{
			cout << "Divine Scroll of Inflict Serious Wounds (Caster level 5)" << endl;
		}
		else if((37 <= d100) && (d100 <= 38))
		{
			cout << "Divine Scroll of Invisibility Purge (Caster level 5)" << endl;
		}
		else if((39 <= d100) && (d100 <= 40))
		{
			cout << "Divine Scroll of Locate Object (Caster level 5)" << endl;
		}
		else if((41 <= d100) && (d100 <= 46))
		{
			int d4 = rand()%4+1;
			switch(d4)
			{
			case 1:
				cout << "Divine Scroll of Magic Circle Against Chaos (Caster level 5)" << endl;
				break;
			case 2:
				cout << "Divine Scroll of Magic Circle Against Evil (Caster level 5)" << endl;
				break;
			case 3:
				cout << "Divine Scroll of Magic Circle Against Good (Caster level 5)" << endl;
				break;
			case 4:
				cout << "Divine Scroll of Magic Circle Against Law (Caster level 5)" << endl;
				break;
			}
		}
		else if((47 <= d100) && (d100 <= 48))
		{
			cout << "Divine Scroll of Greater Magic Fang (Caster level 5)" << endl;
		}
		else if((49 <= d100) && (d100 <= 50))
		{
			cout << "Divine Scroll of Magic Vestment (Caster level 5)" << endl;
		}
		else if((51 <= d100) && (d100 <= 52))
		{
			cout << "Divine Scroll of Meld into Stone (Caster level 5)" << endl;
		}
		else if((53 <= d100) && (d100 <= 55))
		{
			cout << "Divine Scroll of Neutralize Poison (Caster level 5)" << endl;
		}
		else if((56 <= d100) && (d100 <= 57))
		{
			cout << "Divine Scroll of Obscure Object (Caster level 5)" << endl;
		}
		else if((58 <= d100) && (d100 <= 59))
		{
			cout << "Divine Scroll of Plant Growth (Caster level 5)" << endl;
		}
		else if((60 <= d100) && (d100 <= 62))
		{
			cout << "Divine Scroll of Prayer (Caster level 5)" << endl;
		}
		else if((63 <= d100) && (d100 <= 64))
		{
			cout << "Divine Scroll of Protection from Energy (Caster level 5)" << endl;
		}
		else if((65 <= d100) && (d100 <= 66))
		{
			cout << "Divine Scroll of Quench (Caster level 5)" << endl;
		}
		else if((67 <= d100) && (d100 <= 69))
		{
			cout << "Divine Scroll of Remove Blindness/Deafness (Caster level 5)" << endl;
		}
		else if((70 <= d100) && (d100 <= 71))
		{
			cout << "Divine Scroll of Remove Curse (Caster level 5)" << endl;
		}
		else if((72 <= d100) && (d100 <= 73))
		{
			cout << "Divine Scroll of Remove Disease (Caster level 5)" << endl;
		}
		else if((74 <= d100) && (d100 <= 76))
		{
			cout << "Divine Scroll of Searing Light (Caster level 5)" << endl;
		}
		else if((77 <= d100) && (d100 <= 78))
		{
			cout << "Divine Scroll of Sleet Storm (Caster level 5)" << endl;
		}
		else if((79 <= d100) && (d100 <= 80))
		{
			cout << "Divine Scroll of Snare (Caster level 5)" << endl;
		}
		else if((81 <= d100) && (d100 <= 83))
		{
			cout << "Divine Scroll of Speak with Dead (Caster level 5)" << endl;
		}
		else if((84 <= d100) && (d100 <= 85))
		{
			cout << "Divine Scroll of Speak with Plants (Caster level 5)" << endl;
		}
		else if((86 <= d100) && (d100 <= 87))
		{
			cout << "Divine Scroll of Spike Growth (Caster level 5)" << endl;
		}
		else if((88 <= d100) && (d100 <= 89))
		{
			cout << "Divine Scroll of Stone Shape (Caster level 5)" << endl;
		}
		else if((90 <= d100) && (d100 <= 91))
		{
			cout << "Divine Scroll of Summon Monster III (Caster level 5)" << endl;
		}
		else if((92 <= d100) && (d100 <= 93))
		{
			cout << "Divine Scroll of Summmon Nature's Ally III (Caster level 5)" << endl;
		}
		else if((94 <= d100) && (d100 <= 96))
		{
			cout << "Divine Scroll of Water Breathing (Caster level 5)" << endl;
		}
		else if((97 <= d100) && (d100 <= 98))
		{
			cout << "Divine Scroll of Water Walk (Caster level 5)" << endl;
		}
		else
		{
			cout << "Divine Scroll of Wind Wall (Caster level 5)" << endl;
		}
	}
	void DSpell_4()
	{
		int d100 = rand()%100+1;
		if((1 <= d100) && (d100 <= 5))
		{
			cout << "Divine Scroll of Air Walk (Caster level 7)" << endl;
		}
		else if((6 <= d100) && (d100 <= 7))
		{
			cout << "Divine Scroll of Antiplant Shell (Caster level 7)" << endl;
		}
		else if((8 <= d100) && (d100 <= 9))
		{
			cout << "Divine Scroll of Blight (Caster level 7)" << endl;
		}
		else if((8 <= d100) && (d100 <= 9))
		{
			cout << "Divine Scroll of Blight (Caster level 7)" << endl;
		}
		else if((10 <= d100) && (d100 <= 11))
		{
			cout << "Divine Scroll of Break Enchantment (Caster level 7)" << endl;
		}
		else if((12 <= d100) && (d100 <= 13))
		{
			cout << "Divine Scroll of Command Plants (Caster level 7)" << endl;
		}
		else if((14 <= d100) && (d100 <= 15))
		{
			cout << "Divine Scroll of Control Water (Caster level 7)" << endl;
		}
		else if((16 <= d100) && (d100 <= 21))
		{
			cout << "Divine Scroll of Cure Critical Wounds (Caster level 7)" << endl;
		}
		else if((22 <= d100) && (d100 <=26))
		{
			cout << "Divine Scroll of Death Ward (Caster level 7)" << endl;
		}
		else if((27 <= d100) && (d100 <= 31))
		{
			cout << "Divine Scroll of Dimensional Anchor (Caster level 7)" << endl;
		}
		else if((32 <= d100) && (d100 <= 34))
		{
			cout << "Divine Scroll of Discern Lies (Caster level 7)" << endl;
		}
		else if((35 <= d100) && (d100 <= 37))
		{
			cout << "Divine Scroll of Dismissal (Caster level 7)" << endl;
		}
		else if((38 <= d100) && (d100 <= 39))
		{
			cout << "Divine Scroll of Divination (Caster level 7)" << endl;
		}
		else if((40 <= d100) && (d100 <= 42))
		{
			cout << "Divine Scroll of Divine Power (Caster level 7)" << endl;
		}
		else if((43 <= d100) && (d100 <= 47))
		{
			cout << "Divine Scroll of Freedom of Movement (Caster level 7)" << endl;
		}
		else if((48 <= d100) && (d100 <= 49))
		{
			cout << "Divine Scroll of Giant Vermin (Caster level 7)" << endl;
		}
		else if((50 <= d100) && (d100 <= 51))
		{
			cout << "Divine Scroll of Holy Sword (Caster level 7)" << endl;
		}
		else if((52 <= d100) && (d100 <= 54))
		{
			cout << "Divine Scroll of Imbue With Spell Ability (Caster level 7)" << endl;
		}
		else if((55 <= d100) && (d100 <= 57))
		{
			cout << "Divine Scroll of Inflict Critical Wounds (Caster level 7)" << endl;
		}
		else if((58 <= d100) && (d100 <= 60))
		{
			cout << "Divine Scroll of Greater Magic Weapon (Caster level 7)" << endl;
		}
		else if((61 <= d100) && (d100 <= 62))
		{
			cout << "Divine Scroll of Nondetection (Caster level 7)" << endl;
		}
		else if((63 <= d100) && (d100 <= 64))
		{
			cout << "Divine Scroll of Lesser Planar Ally (Caster level 7)" << endl;
		}
		else if((65 <= d100) && (d100 <= 67))
		{
			cout << "Divine Scroll of Poison (Caster level 7)" << endl;
		}
		else if((68 <= d100) && (d100 <= 69))
		{
			cout << "Divine Scroll of Reincarnate (Caster level 7)" << endl;
		}
		else if((70 <= d100) && (d100 <= 71))
		{
			cout << "Divine Scroll of Repel Vermin (Caster level 7)" << endl;
		}
		else if((72 <= d100) && (d100 <= 76))
		{
			cout << "Divine Scroll of Restoration (Caster level 7)" << endl;
		}
		else if((77 <= d100) && (d100 <= 78))
		{
			cout << "Divine Scroll of Rusting Grasp (Caster level 7)" << endl;
		}
		else if((79 <= d100) && (d100 <= 81))
		{
			cout << "Divine Scroll of Sending (Caster level 7)" << endl;
		}
		else if((82 <= d100) && (d100 <= 85))
		{
			cout << "Divine Scroll of Spell Immunity (Caster level 7)" << endl;
		}
		else if((86 <= d100) && (d100 <= 87))
		{
			cout << "Divine Scroll of Spike Stones (Caster level 7)" << endl;
		}
		else if((88 <= d100) && (d100 <= 90))
		{
			cout << "Divine Scroll of Summon Monster IV (Caster level 7)" << endl;
		}
		else if((91 <= d100) && (d100 <= 93))
		{
			cout << "Divine Scroll of Summon Nature's Ally IV (Caster level 7)" << endl;
		}
		else if((94 <= d100) && (d100 <= 98))
		{
			cout << "Divine Scroll of Tongues (Caster level 7)" << endl;
		}
		else
		{
			cout << "Divine Scroll of Tree Stride (Caster level 7)" << endl;
		}
	}
	void DSpell_5()
	{
		int d100 = rand()%100+1;
		if((1 <= d100) && (d100 <= 3))
		{
			cout << "Divine Scroll of Animal Growth (Caster level 9)" << endl;
		}
		else if((4 <= d100) && (d100 <= 5))
		{
			cout << "Divine Scroll of Atonement (Caster level 9)" << endl;
		}
		else if(d100 == 6)
		{
			cout << "Divine Scroll of Awaken (Caster level 9)" << endl;
		}
		else if((7 <= d100) && (d100 <= 9))
		{
			cout << "Divine Scroll of Baleful Polymorph (Caster level 9)" << endl;
		}
		else if((10 <= d100) && (d100 <= 13))
		{
			cout << "Divine Scroll of Break Enchantment (Caster level 9)" << endl;
		}
		else if((14 <= d100) && (d100 <= 16))
		{
			cout << "Divine Scroll of Call Lightning Storm (Caster level 9)" << endl;
		}
		else if((17 <= d100) && (d100 <= 20))
		{
			cout << "Divine Scroll of Greater Command (Caster level 9)" << endl;
		}
		else if(d100 == 21)
		{
			cout << "Divine Scroll of Commune (Caster level 9)" << endl;
		}
		else if(d100 == 22)
		{
			cout << "Divine Scroll of Commune with Nature (Caster level 9)" << endl;
		}
		else if((23 <= d100) && (d100 <= 24))
		{
			cout << "Divine Scroll of Control Winds (Caster level 9)" << endl;
		}
		else if((25 <= d100) && (d100 <= 30))
		{
			cout << "Divine Scroll of Mass Cure Light Wounds (Caster level 9)" << endl;
		}
		else if((31 <= d100) && (d100 <= 34))
		{
			int d4 = rand()%4+1;
			switch(d4)
			{
			case 1:
				cout << "Divine Scroll of Dispel Chaos (Caster level 9)" << endl;
				break;
			case 2:
				cout << "Divine Scroll of Dispel Evil (Caster level 9)" << endl;
				break;
			case 3:
				cout << "Divine Scroll of Dispel Good (Caster level 9)" << endl;
				break;
			case 4:
				cout << "Divine Scroll of Dispel Law (Caster level 9)" << endl;
				break;
			}
		}
		else if((35 <= d100) && (d100 <= 38))
		{
			cout << "Divine Scroll of Disrupting Weapon (Caster level 9)" << endl;
		}
		else if((39 <= d100) && (d100 <= 41))
		{
			cout << "Divine Scroll of Flame Strike (Caster level 9)" << endl;
		}
		else if((42 <= d100) && (d100 <= 43))
		{
			cout << "Divine Scroll of Hallow (Caster level 9)" << endl;
		}
		else if((44 <= d100) && (d100 <= 46))
		{
			cout << "Divine Scroll of Ice Storm (Caster level 9)" << endl;
		}
		else if((47 <= d100) && (d100 <= 49))
		{
			cout << "Divine Scroll of Mass Inflict Light Wounds (Caster level 9)" << endl;
		}
		else if((50 <= d100) && (d100 <= 52))
		{
			cout << "Divine Scroll of Insect Plague (Caster level 9)" << endl;
		}
		else if(d100 == 53)
		{
			cout << "Divine Scroll of Mark of Justice (Caster level 9)" << endl;
		}
		else if((54 <= d100) && (d100 <= 56))
		{
			cout << "Divine Scroll of Plane Shift (Caster level 9)" << endl;
		}
		else if((57 <= d100) && (d100 <= 58))
		{
			cout << "Divine Scroll of Raise Dead (Caster level 9)" << endl;
		}
		else if((59 <= d100) && (d100 <= 61))
		{
			cout << "Divine Scroll of Righteous Might (Caster level 9)" << endl;
		}
		else if((62 <= d100) && (d100 <= 63))
		{
			cout << "Divine Scroll of Scrying (Caster level 9)" << endl;
		}
		else if((64 <= d100) && (d100 <= 66))
		{
			cout << "Divine Scroll of Slay Living (Caster level 9)" << endl;
		}
		else if((67 <= d100) && (d100 <= 69))
		{
			cout << "Divine Scroll of Spell Resistance (Caster level 9)" << endl;
		}
		else if((70 <= d100) && (d100 <= 71))
		{
			cout << "Divine Scroll of Stoneskin (Caster level 9)" << endl;
		}
		else if((72 <= d100) && (d100 <= 74))
		{
			cout << "Divine Scroll of Summon Monster V (Caster level 9)" << endl;
		}
		else if((75 <= d100) && (d100 <= 77))
		{
			cout << "Divine Scroll of Summon Nature's Ally V (Caster level 9)" << endl;
		}
		else if(d100 == 78)
		{
			cout << "Divine Scroll of Symbol of Pain (Caster level 9)" << endl;
		}
		else if(d100 == 79)
		{
			cout << "Divine Scroll of Symbol of Sleep (Caster level 9)" << endl;
		}
		else if((80 <= d100) && (d100 <= 82))
		{
			cout << "Divine Scroll of Transmute Mud to Rock (Caster level 9)" << endl;
		}
		else if((83 <= d100) && (d100 <= 85))
		{
			cout << "Divine Scroll of Transmute Rock to Mud (Caster level 9)" << endl;
		}
		else if((86 <= d100) && (d100 <= 89))
		{
			cout << "Divine Scroll of True Seeing (Caster level 9)" << endl;
		}
		else if((90 <= d100) && (d100 <= 91))
		{
			cout << "Divine Scroll of Unhallow (Caster level 9)" << endl;
		}
		else if((92 <= d100) && (d100 <= 94))
		{
			cout << "Divine Scroll of Wall of Fire (Caster level 9)" << endl;
		}
		else if((95 <= d100) && (d100 <= 97))
		{
			cout << "Divine Scroll of Wall of Stone (Caster level 9)" << endl;
		}
		else
		{
			cout << "Divine Scroll of Wall of Thorns (Caster level 9)" << endl;
		}
	}
	void DSpell_6()
	{
		int d100 = rand()%100+1;
		if((1 <= d100) && (d100 <= 3))
		{
			cout << "Divine Scroll of Animate Objects (Caster level 11)" << endl;
		}
		else if((4 <= d100) && (d100 <= 6))
		{
			cout << "Divine Scroll of Antilife Shell (Caster level 11)" << endl;
		}
		else if((7 <= d100) && (d100 <= 9))
		{
			cout << "Divine Scroll of Banishment (Caster level 11)" << endl;
		}
		else if((10 <= d100) && (d100 <= 13))
		{
			cout << "Divine Scroll of Mass Bear's Endurance (Caster level 11)" << endl;
		}
		else if((14 <= d100) && (d100 <= 16))
		{
			cout << "Divine Scroll of Blade Barrier (Caster level 11)" << endl;
		}
		else if((17 <= d100) && (d100 <= 20))
		{
			cout << "Divine Scroll of Mass Bull's Strength (Caster level 11)" << endl;
		}
		else if((21 <= d100) && (d100 <= 24))
		{
			cout << "Divine Scroll of Mass Cat's Grace (Caster level 11)" << endl;
		}
		else if(d100 == 25)
		{
			cout << "Divine Scroll of Create Undead (Caster level 11)" << endl;
		}
		else if((26 <= d100) && (d100 <= 29))
		{
			cout << "Divine Scroll of Mass Cure Moderate Wounds (Caster level 11)" << endl;
		}
		else if((30 <= d100) && (d100 <= 33))
		{
			cout << "Divine Scroll of Greater Dispel Magic (Caster level 11)" << endl;
		}
		else if((34 <= d100) && (d100 <= 37))
		{
			cout << "Divine Scroll of Mass Eagle's Splendor (Caster level 11)" << endl;
		}
		else if((38 <= d100) && (d100 <= 40))
		{
			cout << "Divine Scroll of Find the Path (Caster level 11)" << endl;
		}
		else if((41 <= d100) && (d100 <= 43))
		{
			cout << "Divine Scroll of Fire Seeds (Caster level 11)" << endl;
		}
		else if(d100 == 44)
		{
			cout << "Divine Scroll of Forbiddance (Caster level 11)" << endl;
		}
		else if(d100 == 45)
		{
			cout << "Divine Scroll of Geas/Quest (Caster level 11)" << endl;
		}
		else if(d100 == 46)
		{
			cout << "Divine Scroll of Greater Glyph of Warding (Caster level 11)" << endl;
		}
		else if((47 <= d100) && (d100 <= 49))
		{
			cout << "Divine Scroll of Harm (Caster level 11)" << endl;
		}
		else if((50 <= d100) && (d100 <= 52))
		{
			cout << "Divine Scroll of Heal (Caster level 11)" << endl;
		}
		else if((53 <= d100) && (d100 <= 55))
		{
			cout << "Divine Scroll of Heroes' Feast (Caster level 11)" << endl;
		}
		else if((56 <= d100) && (d100 <= 58))
		{
			cout << "Divine Scroll of Mass Inflict Moderate Wounds (Caster level 11)" << endl;
		}
		else if((59 <= d100) && (d100 <= 61))
		{
			cout << "Divine Scroll of Iron Wood (Caster level 11)" << endl;
		}
		else if(d100 == 62)
		{
			cout << "Divine Scroll of Liveoak (Caster level 11)" << endl;
		}
		else if((63 <= d100) && (d100 <= 65))
		{
			cout << "Divine Scroll of Move Earth (Caster level 11)" << endl;
		}
		else if((66 <= d100) && (d100 <= 69))
		{
			cout << "Divine Scroll of Mass Owl's Wisdom (Caster level 11)" << endl;
		}
		else if((70 <= d100) && (d100 <= 71))
		{
			cout << "Divine Scroll of Planar Ally (Caster level 11)" << endl;
		}
		else if((72 <= d100) && (d100 <= 74))
		{
			cout << "Divine Scroll of Repel Wood (Caster level 11)" << endl;
		}
		else if((75 <= d100) && (d100 <= 77))
		{
			cout << "Divine Scroll of Spellstaff (Caster level 11)" << endl;
		}
		else if((78 <= d100) && (d100 <= 80))
		{
			cout << "Divine Scroll of Stone Tell (Caster level 11)" << endl;
		}
		else if((81 <= d100) && (d100 <= 83))
		{
			cout << "Divine Scroll of Summon Monster VI (Caster level 11)" << endl;
		}
		else if((84 <= d100) && (d100 <= 86))
		{
			cout << "Divine Scroll of Summon Nature's Ally VI (Caster level 11)" << endl;
		}
		else if(d100 == 87)
		{
			cout << "Divine Scroll of Symbol of Fear (Caster level 11)" << endl;
		}
		else if(d100 == 88)
		{
			cout << "Divine Scroll of Symbol of Persuasion (Caster level 11)" << endl;
		}
		else if((89 <= d100) && (d100 <= 91))
		{
			cout << "Divine Scroll of Transport Via Plants (Caster level 11)" << endl;
		}
		else if((92 <= d100) && (d100 <= 94))
		{
			cout << "Divine Scroll of Undeath to Death (Caster level 11)" << endl;
		}
		else if((95 <= d100) && (d100 <= 97))
		{
			cout << "Divine Scroll of Wind Walk (Caster level 11)" << endl;
		}
		else
		{
			cout << "Divine Scroll of Word of Recall (Caster level 11)" << endl;
		}
	}
	void DSpell_7()
	{
		int d100 = rand()%100+1;
		if((1 <= d100) && (d100 <= 5))
		{
			cout << "Divine Scroll of Animate Plants (Caster level 13)" << endl;
		}
		else if((6 <= d100) && (d100 <= 9))
		{
			cout << "Divine Scroll of Blasphemy (Caster level 13)" << endl;
		}
		else if((10 <= d100) && (d100 <= 14))
		{
			cout << "Divine Scroll of Changestaff (Caster level 13)" << endl;
		}
		else if((15 <= d100) && (d100 <= 16))
		{
			cout << "Divine Scroll of Control Weather (Caster level 13)" << endl;
		}
		else if((17 <= d100) && (d100 <= 21))
		{
			cout << "Divine Scroll of Creeping Doom (Caster level 13)" << endl;
		}
		else if((22 <= d100) && (d100 <= 27))
		{
			cout << "Divine Scroll of Mass Cure Serious Wounds (Caster level 13)" << endl;
		}
		else if((28 <= d100) && (d100 <= 32))
		{
			cout << "Divine Scroll of Destruction (Caster level 13)" << endl;
		}
		else if((33 <= d100) && (d100 <= 36))
		{
			cout << "Divine Scroll of Dictum (Caster level 13)" << endl;
		}
		else if((37 <= d100) && (d100 <= 41))
		{
			cout << "Divine Scroll of Ethereal Jaunt (Caster level 13)" << endl;
		}
		else if((42 <= d100) && (d100 <= 45))
		{
			cout << "Divine Scroll of Holy Word (Caster level 13)" << endl;
		}
		else if((46 <= d100) && (d100 <= 50))
		{
			cout << "Divine Scroll of Mass Inflict Serious Wounds (Caster level 13)" << endl;
		}
		else if((51 <= d100) && (d100 <= 55))
		{
			cout << "Divine Scroll of Refuge (Caster level 13)" << endl;
		}
		else if((56 <= d100) && (d100 <= 60))
		{
			cout << "Divine Scroll of Regenerate (Caster level 13)" << endl;
		}
		else if((61 <= d100) && (d100 <= 65))
		{
			cout << "Divine Scroll of Repulsion (Caster level 13)" << endl;
		}
		else if((66 <= d100) && (d100 <= 69))
		{
			cout << "Divine Scroll of Greater Restoration (Caster level 13)" << endl;
		}
		else if((70 <= d100) && (d100 <= 71))
		{
			cout << "Divine Scroll of Resurrection (Caster level 13)" << endl;
		}
		else if((72 <= d100) && (d100 <= 76))
		{
			cout << "Divine Scroll of Greater Scrying (Caster level 13)" << endl;
		}
		else if((77 <= d100) && (d100 <= 81))
		{
			cout << "Divine Scroll of Summon Monster VII (Caster level 13)" << endl;
		}
		else if((82 <= d100) && (d100 <= 85))
		{
			cout << "Divine Scroll of Summon Nature's Ally VII (Caster level 13)" << endl;
		}
		else if((86 <= d100) && (d100 <= 90))
		{
			cout << "Divine Scroll of Sunbeam (Caster level 13)" << endl;
		}
		else if(d100 == 91)
		{
			cout << "Divine Scroll of Symbol of Stunning (Caster level 13)" << endl;
		}
		else if(d100 == 92)
		{
			cout << "Divine Scroll of Symbol of Weakness (Caster level 13)" << endl;
		}
		else if((93 <= d100) && (d100 <= 97))
		{
			cout << "Divine Scroll of Transmute Metal to Wood (Caster level 13)" << endl;
		}
		else
		{
			cout << "Divine Scroll of Word of Chaos (Caster level 13)" << endl;
		}
	}
	void DSpell_8()
	{
		int d100 = rand()%100+1;
		if((1 <= d100) && (d100 <= 4))
		{
			cout << "Divine Scroll of Animal Shapes (Caster level 15)" << endl;
		}
		else if((5 <= d100) && (d100 <= 10))
		{
			cout << "Divine Scroll of Antimagic Field (Caster level 15)" << endl;
		}
		else if((11 <= d100) && (d100 <= 13))
		{
			cout << "Divine Scroll of Cloak of Chaos (Caster level 15)" << endl;
		}
		else if((14 <= d100) && (d100 <= 17))
		{
			cout << "Divine Scroll of Control Plants (Caster level 15)" << endl;
		}
		else if((18 <= d100) && (d100 <= 20))
		{
			cout << "Divine Scroll of Create Greater Undead (Caster level 15)" << endl;
		}
		else if((21 <= d100) && (d100 <= 27))
		{
			cout << "Divine Scroll of Mass Cure Critical Wounds (Caster level 15)" << endl;
		}
		else if((28 <= d100) && (d100 <= 32))
		{
			cout << "Divine Scroll of Dimensional Lock (Caster level 15)" << endl;
		}
		else if((33 <= d100) && (d100 <= 36))
		{
			cout << "Divine Scroll of Discern Location (Caster level 15)" << endl;
		}
		else if((37 <= d100) && (d100 <= 41))
		{
			cout << "Divine Scroll of Earthquake (Caster level 15)" << endl;
		}
		else if((42 <= d100) && (d100 <= 45))
		{
			cout << "Divine Scroll of Finger of Death (Caster level 15)" << endl;
		}
		else if((46 <= d100) && (d100 <= 49))
		{
			cout << "Divine Scroll of Fire Storm (Caster level 15)" << endl;
		}
		else if((50 <= d100) && (d100 <= 52))
		{
			cout << "Divine Scroll of Holy Aura (Caster level 15)" << endl;
		}
		else if((53 <= d100) && (d100 <= 56))
		{
			cout << "Divine Scroll of Mass Inflict Critical Wounds (Caster level 15)" << endl;
		}
		else if((57 <= d100) && (d100 <= 60))
		{
			cout << "Divine Scroll of Greater Planar Ally (Caster level 15)" << endl;
		}
		else if((61 <= d100) && (d100 <= 65))
		{
			cout << "Divine Scroll of Repel Metal or Stone (Caster level 15)" << endl;
		}
		else if((66 <= d100) && (d100 <= 69))
		{
			cout << "Divine Scroll of Reverse Gravity (Caster level 15)" << endl;
		}
		else if((70 <= d100) && (d100 <= 72))
		{
			cout << "Divine Scroll of Shield of Law (Caster level 15)" << endl;
		}
		else if((73 <= d100) && (d100 <= 76))
		{
			cout << "Divine Scroll of Greater Spell Immunity (Caster level 15)" << endl;
		}
		else if((77 <= d100) && (d100 <= 80))
		{
			cout << "Divine Scroll of Summon Monster VIII (Caster level 15)" << endl;
		}
		else if((81 <= d100) && (d100 <= 84))
		{
			cout << "Divine Scroll of Summon Nature's Ally VIII (Caster level 15)" << endl;
		}
		else if((85 <= d100) && (d100 <= 89))
		{
			cout << "Divine Scroll of Sunburst (Caster level 15)" << endl;
		}
		else if((90 <= d100) && (d100 <= 91))
		{
			cout << "Divine Scroll of Symbol of Death (Caster level 15)" << endl;
		}
		else if((92 <= d100) && (d100 <= 93))
		{
			cout << "Divine Scroll of Symbol of Insanity (Caster level 15)" << endl;
		}
		else if((94 <= d100) && (d100 <= 96))
		{
			cout << "Divine Scroll of Unholy Aura (Caster level 15)" << endl;
		}
		else
		{
			cout << "Divine Scroll of Whirlwind (Caster level 15)" << endl;
		}
	}
	void DSpell_9()
	{
		int d100 = rand()%100+1;
		if((1 <= d100) && (d100 <= 4))
		{
			cout << "Divine Scroll of Antipathy (Caster level 17)" << endl;
		}
		else if((5 <= d100) && (d100 <= 7))
		{
			cout << "Divine Scroll of Astral Projection (Caster level 17)" << endl;
		}
		else if((8 <= d100) && (d100 <= 13))
		{
			cout << "Divine Scroll of Elemental Swarm (Caster level 17)" << endl;
		}
		else if((14 <= d100) && (d100 <= 19))
		{
			cout << "Divine Scroll of Energy Drain (Caster level 17)" << endl;
		}
		else if((20 <= d100) && (d100 <= 25))
		{
			cout << "Divine Scroll of Etherealness (Caster level 17)" << endl;
		}
		else if((26 <= d100) && (d100 <= 31))
		{
			cout << "Divine Scroll of Foresight (Caster level 17)" << endl;
		}
		else if((32 <= d100) && (d100 <= 37))
		{
			cout << "Divine Scroll of Gate (Caster level 17)" << endl;
		}
		else if((38 <= d100) && (d100 <= 46))
		{
			cout << "Divine Scroll of Mass Heal (Caster level 17)" << endl;
		}
		else if((47 <= d100) && (d100 <= 53))
		{
			cout << "Divine Scroll of Implosion (Caster level 17)" << endl;
		}
		else if((54 <= d100) && (d100 <= 55))
		{
			cout << "Divine Scroll of Miracle (Caster level 17)" << endl;
		}
		else if((56 <= d100) && (d100 <= 61))
		{
			cout << "Divine Scroll of Regenerate (Caster level 17)" << endl;
		}
		else if((62 <= d100) && (d100 <= 66))
		{
			cout << "Divine Scroll of Shambler (Caster level 17)" << endl;
		}
		else if((67 <= d100) && (d100 <= 72))
		{
			cout << "Divine Scroll of Shapechange (Caster level 17)" << endl;
		}
		else if((73 <= d100) && (d100 <= 77))
		{
			cout << "Divine Scroll of Soul Bind (Caster level 17)" << endl;
		}
		else if((78 <= d100) && (d100 <= 83))
		{
			cout << "Divine Scroll of Storm of Vengeance (Caster level 17)" << endl;
		}
		else if((84 <= d100) && (d100 <= 89))
		{
			cout << "Divine Scroll of Summon Monster IX (Caster level 17)" << endl;
		}
		else if((90 <= d100) && (d100 <= 95))
		{
			cout << "Divine Scroll of Summon Nature's Ally IX (Caster level 17)" << endl;
		}
		else if((96 <= d100) && (d100 <= 99))
		{
			cout << "Divine Scroll of Sympathy (Caster level 17)" << endl;
		}
		else
		{
			cout << "Divine Scroll of True Resurrection (Caster level 17)" << endl;
		}
	}

void mediumStaff()
{
	int d100 = rand()%100+1;
	int charges = rand()%50+1;
	if((1 <= d100) && (d100 <= 15))
	{
		cout << "Staff of Charming (" << charges << " charges)" << endl;
	}
	else if((16 <= d100) && (d100 <= 30))
	{
		cout << "Staff of Fire (" << charges << " charges)" << endl;
	}
	else if((31 <= d100) && (d100 <= 40))
	{
		cout << "Staff of Swarming Insects (" << charges << " charges)" << endl;
	}
	else if((41 <= d100) && (d100 <= 60))
	{
		cout << "Staff of Healing (" << charges << " charges)" << endl;
	}
	else if((61 <= d100) && (d100 <= 75))
	{
		cout << "Staff of Size Alteration (" << charges << " charges)" << endl;
	}
	else if((76 <= d100) && (d100 <= 90))
	{
		cout << "Staff of Illumination (" << charges << " charges)" << endl;
	}
	else if((91 <= d100) && (d100 <= 95))
	{
		cout << "Staff of Frost (" << charges << " charges)" << endl;
	}
	else
	{
		cout << "Staff of Defense (" << charges << " charges)" << endl;
	}
}
void majorStaff()
{
	int d100 = rand()%100+1;
	int charges = rand()%50+1;
	if((1 <= d100) && (d100 <= 3))
	{
		cout << "Staff of Charming (" << charges << " charges)" << endl;
	}
	else if((4 <= d100) && (d100 <= 9))
	{
		cout << "Staff of Fire (" << charges << " charges)" << endl;
	}
	else if((10 <= d100) && (d100 <= 11))
	{
		cout << "Staff of Swarming Insects (" << charges << " charges)" << endl;
	}
	else if((12 <= d100) && (d100 <= 17))
	{
		cout << "Staff of Healing (" << charges << " charges)" << endl;
	}
	else if((18 <= d100) && (d100 <= 19))
	{
		cout << "Staff of Size Alteration (" << charges << " charges)" << endl;
	}
	else if((20 <= d100) && (d100 <= 24))
	{
		cout << "Staff of Illumination (" << charges << " charges)" << endl;
	}
	else if((25 <= d100) && (d100 <= 31))
	{
		cout << "Staff of Frost (" << charges << " charges)" << endl;
	}
	else if((32 <= d100) && (d100 <= 38))
	{
		cout << "Staff of Defense (" << charges << " charges)" << endl;
	}
	else if((39 <= d100) && (d100 <= 43))
	{
		cout << "Staff of Abjuration (" << charges << " charges)" << endl;
	}
	else if((44 <= d100) && (d100 <= 48))
	{
		cout << "Staff of Conjuration (" << charges << " charges)" << endl;
	}
	else if((49 <= d100) && (d100 <= 53))
	{
		cout << "Staff of Enchantment (" << charges << " charges)" << endl;
	}
	else if((54 <= d100) && (d100 <= 58))
	{
		cout << "Staff of Evocation (" << charges << " charges)" << endl;
	}
	else if((59 <= d100) && (d100 <= 63))
	{
		cout << "Staff of Illusion (" << charges << " charges)" << endl;
	}
	else if((64 <= d100) && (d100 <= 68))
	{
		cout << "Staff of Necromancy (" << charges << " charges)" << endl;
	}
	else if((69 <= d100) && (d100 <= 73))
	{
		cout << "Staff of Transmutation (" << charges << " charges)" << endl;
	}
	else if((74 <= d100) && (d100 <= 77))
	{
		cout << "Staff of Divination (" << charges << " charges)" << endl;
	}
	else if((78 <= d100) && (d100 <= 82))
	{
		cout << "Staff of Earth and Stone (" << charges << " charges)" << endl;
	}
	else if((83 <= d100) && (d100 <= 87))
	{
		cout << "Staff of the Woodlands (" << charges << " charges)" << endl;
	}
	else if((88 <= d100) && (d100 <= 92))
	{
		cout << "Staff of Life (" << charges << " charges)" << endl;
	}
	else if((93 <= d100) && (d100 <= 97))
	{
		cout << "Staff of Passage (" << charges << " charges)" << endl;
	}
	else
	{
		cout << "Staff of Power (" << charges << " charges)" << endl;
	}
}

void minorWand()
{
	int d100 = rand()%100+1;
	int charges = rand()%50+1;
	if((1 <= d100) && (d100 <= 2))
	{
		cout << "Wand of Detect Magic (" << charges << " charges)" << endl;
	}
	else if((3 <= d100) && (d100 <= 4))
	{
		cout << "Wand of Light (" << charges << " charges)" << endl;
	}
	else if((5 <= d100) && (d100 <= 7))
	{
		cout << "Wand of Burning Hands (" << charges << " charges)" << endl;
	}
	else if((8 <= d100) && (d100 <= 10))
	{
		cout << "Wand of Charm Animal (" << charges << " charges)" << endl;
	}
	else if((11 <= d100) && (d100 <= 13))
	{
		cout << "Wand of Charm Person (" << charges << " charges)" << endl;
	}
	else if((14 <= d100) && (d100 <= 16))
	{
		cout << "Wand of Color Spray (" << charges << " charges)" << endl;
	}
	else if((17 <= d100) && (d100 <= 19))
	{
		cout << "Wand of Cure Light Wounds (" << charges << " charges)" << endl;
	}
	else if((20 <= d100) && (d100 <= 22))
	{
		cout << "Wand of Detect Secret Doors (" << charges << " charges)" << endl;
	}
	else if((23 <= d100) && (d100 <= 25))
	{
		cout << "Wand of Enlarge Person (" << charges << " charges)" << endl;
	}
	else if((26 <= d100) && (d100 <= 28))
	{
		cout << "Wand of Magic Missile (1st) (" << charges << " charges)" << endl;
	}
	else if((29 <= d100) && (d100 <= 31))
	{
		cout << "Wand of Shocking Grasp (" << charges << " charges)" << endl;
	}
	else if((32 <= d100) && (d100 <= 34))
	{
		cout << "Wand of Summon Monster I (" << charges << " charges)" << endl;
	}
	else if((35 <= d100) && (d100 <= 36))
	{
		cout << "Wand of Magic Missile (3rd) (" << charges << " charges)" << endl;
	}
	else if(d100 == 37)
	{
		cout << "Wand of Magic Missile (5th) (" << charges << " charges)" << endl;
	}
	else if((38 <= d100) && (d100 <= 40))
	{
		cout << "Wand of Bear's Endurance (" << charges << " charges)" << endl;
	}
	else if((41 <= d100) && (d100 <= 43))
	{
		cout << "Wand of Bull's Strength (" << charges << " charges)" << endl;
	}
	else if((44 <= d100) && (d100 <= 46))
	{
		cout << "Wand of Cat's Grace (" << charges << " charges)" << endl;
	}
	else if((47 <= d100) && (d100 <= 49))
	{
		cout << "Wand of Cure Moderate Wounds (" << charges << " charges)" << endl;
	}
	else if((50 <= d100) && (d100 <= 51))
	{
		cout << "Wand of Darkness (" << charges << " charges)" << endl;
	}
	else if((52 <= d100) && (d100 <= 54))
	{
		cout << "Wand of Daylight (" << charges << " charges)" << endl;
	}
	else if((55 <= d100) && (d100 <= 57))
	{
		cout << "Wand of Delay Poison (" << charges << " charges)" << endl;
	}
	else if((58 <= d100) && (d100 <= 60))
	{
		cout << "Wand of Eagle's Splendor (" << charges << " charges)" << endl;
	}
	else if((61 <= d100) && (d100 <= 63))
	{
		cout << "Wand of False Life (" << charges << " charges)" << endl;
	}
	else if((64 <= d100) && (d100 <= 66))
	{
		cout << "Wand of Fox's Cunning (" << charges << " charges)" << endl;
	}
	else if((67 <= d100) && (d100 <= 68))
	{
		cout << "Wand of Ghoul's Touch (" << charges << " charges)" << endl;
	}
	else if((69 <= d100) && (d100 <= 71))
	{
		cout << "Wand of Hold Person (" << charges << " charges)" << endl;
	}
	else if((72 <= d100) && (d100 <= 74))
	{
		cout << "Wand of Invisibility (" << charges << " charges)" << endl;
	}
	else if((75 <= d100) && (d100 <= 77))
	{
		cout << "Wand of Knock (" << charges << " charges)" << endl;
	}
	else if((78 <= d100) && (d100 <= 80))
	{
		cout << "Wand of Levitate (" << charges << " charges)" << endl;
	}
	else if((81 <= d100) && (d100 <= 83))
	{
		cout << "Wand of Melf's Acid Arrow (" << charges << " charges)" << endl;
	}
	else if((84 <= d100) && (d100 <= 86))
	{
		cout << "Wand of Mirror Image (" << charges << " charges)" << endl;
	}
	else if((87 <= d100) && (d100 <= 89))
	{
		cout << "Wand of Owl's Wisdom (" << charges << " charges)" << endl;
	}
	else if((90 <= d100) && (d100 <= 91))
	{
		cout << "Wand of Shatter (" << charges << " charges)" << endl;
	}
	else if((92 <= d100) && (d100 <= 94))
	{
		cout << "Wand of Silence (" << charges << " charges)" << endl;
	}
	else if((95 <= d100) && (d100 <= 97))
	{
		cout << "Wand of Summon Monster II (" << charges << " charges)" << endl;
	}
	else
	{
		cout << "Wand of Web (" << charges << " charges)" << endl;
	}
}
void mediumWand()
{
	int d100 = rand()%100+1;
	int charges = rand()%50+1;
	if((1 <= d100) && (d100 <= 3))
	{
		cout << "Wand of Magic Missile (5th) (" << charges << " charges)" << endl;
	}
	else if((4 <= d100) && (d100 <= 7))
	{
		cout << "Wand of Bear's Endurance (" << charges << " charges)" << endl;
	}
	else if((8 <= d100) && (d100 <= 11))
	{
		cout << "Wand of Bull's Strength (" << charges << " charges)" << endl;
	}
	else if((12 <= d100) && (d100 <= 15))
	{
		cout << "Wand of Cat's Grace (" << charges << " charges)" << endl;
	}
	else if((16 <= d100) && (d100 <= 20))
	{
		cout << "Wand of Cure Moderate Wounds (" << charges << " charges)" << endl;
	}
	else if((21 <= d100) && (d100 <= 22))
	{
		cout << "Wand of Darkness (" << charges << " charges)" << endl;
	}
	else if((23 <= d100) && (d100 <= 24))
	{
		cout << "Wand of Daylight (" << charges << " charges)" << endl;
	}
	else if((25 <= d100) && (d100 <= 27))
	{
		cout << "Wand of Delay Poison (" << charges << " charges)" << endl;
	}
	else if((28 <= d100) && (d100 <= 31))
	{
		cout << "Wand of Eagle's Splendor (" << charges << " charges)" << endl;
	}
	else if((32 <= d100) && (d100 <= 33))
	{
		cout << "Wand of False Life (" << charges << " charges)" << endl;
	}
	else if((34 <= d100) && (d100 <= 37))
	{
		cout << "Wand of Fox's Cunning (" << charges << " charges)" << endl;
	}
	else if(d100 == 38)
	{
		cout << "Wand of Ghoul's Touch (" << charges << " charges)" << endl;
	}
	else if(d100 == 39)
	{
		cout << "Wand of Hold Person (" << charges << " charges)" << endl;
	}
	else if((40 <= d100) && (d100 <= 42))
	{
		cout << "Wand of Invisibility (" << charges << " charges)" << endl;
	}
	else if((43 <= d100) && (d100 <= 44))
	{
		cout << "Wand of Knock (" << charges << " charges)" << endl;
	}
	else if(d100 == 45)
	{
		cout << "Wand of Levitate (" << charges << " charges)" << endl;
	}
	else if((46 <= d100) && (d100 <= 47))
	{
		cout << "Wand of Melf's Acid Arrow (" << charges << " charges)" << endl;
	}
	else if((48 <= d100) && (d100 <= 49))
	{
		cout << "Wand of Mirror Image (" << charges << " charges)" << endl;
	}
	else if((50 <= d100) && (d100 <= 53))
	{
		cout << "Wand of Owl's Wisdom (" << charges << " charges)" << endl;
	}
	else if(d100 == 54)
	{
		cout << "Wand of Shatter (" << charges << " charges)" << endl;
	}
	else if((55 <= d100) && (d100 <= 56))
	{
		cout << "Wand of Silence (" << charges << " charges)" << endl;
	}
	else if(d100 == 57)
	{
		cout << "Wand of Summon Monster II (" << charges << " charges)" << endl;
	}
	else if((58 <= d100) && (d100 <= 59))
	{
		cout << "Wand of Web (" << charges << " charges)" << endl;
	}
	else if((60 <= d100) && (d100 <= 62))
	{
		cout << "Wand of Magic Missile (7th) (" << charges << " charges)" << endl;
	}
	else if((63 <= d100) && (d100 <= 64))
	{
		cout << "Wand of Magic Missile (9th) (" << charges << " charges)" << endl;
	}
	else if((65 <= d100) && (d100 <= 67))
	{
		cout << "Wand of Call Lightning (5th) (" << charges << " charges)" << endl;
	}
	else if(d100 == 68)
	{
		cout << "Wand of Heightened Charm Person (3rd level) (" << charges << " charges)" << endl;
	}
	else if((69 <= d100) && (d100 <= 70))
	{
		cout << "Wand of Contagion (" << charges << " charges)" << endl;
	}
	else if((71 <= d100) && (d100 <= 74))
	{
		cout << "Wand of Cure Serious Wounds (" << charges << " charges)" << endl;
	}
	else if((75 <= d100) && (d100 <= 77))
	{
		cout << "Wand of Dispel Magic (" << charges << " charges)" << endl;
	}
	else if((78 <= d100) && (d100 <= 81))
	{
		cout << "Wand of Fireball (5th) (" << charges << " charges)" << endl;
	}
	else if((82 <= d100) && (d100 <= 83))
	{
		cout << "Wand of Keen Edge (" << charges << " charges)" << endl;
	}
	else if((84 <= d100) && (d100 <= 87))
	{
		cout << "Wand of Lightning Bolt (5th) (" << charges << " charges)" << endl;
	}
	else if((88 <= d100) && (d100 <= 89))
	{
		cout << "Wand of Major Image (" << charges << " charges)" << endl;
	}
	else if((90 <= d100) && (d100 <= 91))
	{
		cout << "Wand of Slow (" << charges << " charges)" << endl;
	}
	else if((92 <= d100) && (d100 <= 94))
	{
		cout << "Wand of Suggestion (" << charges << " charges)" << endl;
	}
	else if((95 <= d100) && (d100 <= 97))
	{
		cout << "Wand of Summon Monster III (" << charges << " charges)" << endl;
	}
	else if(d100 == 98)
	{
		cout << "Wand of Fireball (6th) (" << charges << " charges)" << endl;
	}
	else if(d100 == 99)
	{
		cout << "Wand of Lightning Bolt (6th) (" << charges << " charges)" << endl;
	}
	else
	{
		cout << "Wand of Searing Light (6th) (" << charges << " charges)" << endl;
	}
}
void majorWand()
{
	int d100 = rand()%100+1;
	int charges = rand()%50+1;
	if((1 <= d100) && (d100 <= 2))
	{
		cout << "Wand of Magic Missile (7th) (" << charges << " charges)" << endl;
	}
	else if((3 <= d100) && (d100 <= 5))
	{
		cout << "Wand of Magic Missile (9th) (" << charges << " charges)" << endl;
	}
	else if((6 <= d100) && (d100 <= 7))
	{
		cout << "Wand of Call Lightning (5th) (" << charges << " charges)" << endl;
	}
	else if(d100 == 8)
	{
		cout << "Wand of Heightened Charm Person (3rd level) (" << charges << " charges)" << endl;
	}
	else if((9 <= d100) && (d100 <= 10))
	{
		cout << "Wand of Contagion (" << charges << " charges)" << endl;
	}
	else if((11 <= d100) && (d100 <= 13))
	{
		cout << "Wand of Cure Serious Wounds (" << charges << " charges)" << endl;
	}
	else if((14 <= d100) && (d100 <= 15))
	{
		cout << "Wand of Dispel Magic (" << charges << " charges)" << endl;
	}
	else if((16 <= d100) && (d100 <= 17))
	{
		cout << "Wand of Fireball (5th) (" << charges << " charges)" << endl;
	}
	else if((18 <= d100) && (d100 <= 19))
	{
		cout << "Wand of Keen Edge (" << charges << " charges)" << endl;
	}
	else if((20 <= d100) && (d100 <= 21))
	{
		cout << "Wand of Lightning Bolt (5th) (" << charges << " charges)" << endl;
	}
	else if((22 <= d100) && (d100 <= 23))
	{
		cout << "Wand of Major Image (" << charges << " charges)" << endl;
	}
	else if((24 <= d100) && (d100 <= 25))
	{
		cout << "Wand of Slow (" << charges << " charges)" << endl;
	}
	else if((26 <= d100) && (d100 <= 27))
	{
		cout << "Wand of Suggestion (" << charges << " charges)" << endl;
	}
	else if((28 <= d100) && (d100 <= 29))
	{
		cout << "Wand of Summon Monster III (" << charges << " charges)" << endl;
	}
	else if((30 <= d100) && (d100 <= 31))
	{
		cout << "Wand of Fireball (6th) (" << charges << " charges)" << endl;
	}
	else if((32 <= d100) && (d100 <= 33))
	{
		cout << "Wand of Lightning Bolt (6th) (" << charges << " charges)" << endl;
	}
	else if((34 <= d100) && (d100 <= 35))
	{
		cout << "Wand of Searing Light (6th) (" << charges << " charges)" << endl;
	}
	else if((36 <= d100) && (d100 <= 37))
	{
		cout << "Wand of Call Lightning (8th) (" << charges << " charges)" << endl;
	}
	else if((38 <= d100) && (d100 <= 39))
	{
		cout << "Wand of Fireball (8th) (" << charges << " charges)" << endl;
	}
	else if((40 <= d100) && (d100 <= 41))
	{
		cout << "Wand of Lightning Bolt (8th) (" << charges << " charges)" << endl;
	}
	else if((42 <= d100) && (d100 <= 45))
	{
		cout << "Wand of Charm Monster (" << charges << " charges)" << endl;
	}
	else if((46 <= d100) && (d100 <= 50))
	{
		cout << "Wand of Cure Critical Wounds (" << charges << " charges)" << endl;
	}
	else if((51 <= d100) && (d100 <= 52))
	{
		cout << "Wand of Dimensional Anchor (" << charges << " charges)" << endl;
	}
	else if((53 <= d100) && (d100 <= 55))
	{
		cout << "Wand of Fear (" << charges << " charges)" << endl;
	}
	else if((56 <= d100) && (d100 <= 59))
	{
		cout << "Wand of Greater Invisibility (" << charges << " charges)" << endl;
	}
	else if(d100 == 60)
	{
		cout << "Wand of Heightened Hold Person (4th level spell) (" << charges << " charges)" << endl;
	}
	else if((61 <= d100) && (d100 <= 65))
	{
		cout << "Wand of Ice Storm (" << charges << " charges)" << endl;
	}
	else if((66 <= d100) && (d100 <= 68))
	{
		cout << "Wand of Inflict Critical Wounds (" << charges << " charges)" << endl;
	}
	else if((69 <= d100) && (d100 <= 72))
	{
		cout << "Wand of Neutralize Poison (" << charges << " charges)" << endl;
	}
	else if((73 <= d100) && (d100 <= 74))
	{
		cout << "Wand of Poison (" << charges << " charges)" << endl;
	}
	else if((75 <= d100) && (d100 <= 77))
	{
		cout << "Wand of Polymorph (" << charges << " charges)" << endl;
	}
	else if(d100 == 78)
	{
		cout << "Wand of Heightened Ray of Enfeeblement (4th level) (" << charges << " charges)" << endl;
	}
	else if(d100 == 79)
	{
		cout << "Wand of Heightened Suggestion (4th level) (" << charges << " charges)" << endl;
	}
	else if((80 <= d100) && (d100 <= 82))
	{
		cout << "Wand of Summon Monster IV (" << charges << " charges)" << endl;
	}
	else if((83 <= d100) && (d100 <= 86))
	{
		cout << "Wand of Wall of Fire (" << charges << " charges)" << endl;
	}
	else if((87 <= d100) && (d100 <= 90))
	{
		cout << "Wand of Wall of Ice (" << charges << " charges)" << endl;
	}
	else if(d100 == 91)
	{
		cout << "Wand of Dispel Magic (10th) (" << charges << " charges)" << endl;
	}
	else if(d100 == 92)
	{
		cout << "Wand of Fireball (10th) (" << charges << " charges)" << endl;
	}
	else if(d100 == 93)
	{
		cout << "Wand of Lightning Bolt (10th) (" << charges << " charges)" << endl;
	}
	else if(d100 == 94)
	{
		cout << "Wand of Chaos Hammer (8th) (" << charges << " charges)" << endl;
	}
	else if(d100 == 95)
	{
		cout << "Wand of Holy Smite (8th) (" << charges << " charges)" << endl;
	}
	else if(d100 == 96)
	{
		cout << "Wand of Order's Wrath (8th) (" << charges << " charges)" << endl;
	}
	else if(d100 == 97)
	{
		cout << "Wand of Unholy Blight (8th) (" << charges << " charges)" << endl;
	}
	else if((98 <= d100) && (d100 <= 99))
	{
		cout << "Wand of Restoration (" << charges << " charges)" << endl;
	}
	else
	{
		cout << "Wand of Stoneskin (" << charges << " charges)" << endl;
	}
}

void minorWondrousItem()
{
	int d100 = rand()%100+1;
	if(d100 == 1)
	{
		cout << "Quaal's Feather Token, Anchor" << endl;
	}
	else if(d100 == 2)
	{
		cout << "Universal Solvent" << endl;
	}
	else if(d100 == 3)
	{
		cout << "Elixer of Love" << endl;
	}
	else if(d100 == 4)
	{
		cout << "Unguent of Timelessness" << endl;
	}
	else if(d100 == 5)
	{
		cout << "Quaal's Feather Token, Fan" << endl;
	}
	else if(d100 == 6)
	{
		cout << "Dust of Tracelessness" << endl;
	}
	else if(d100 == 7)
	{
		cout << "Elixer of Hiding" << endl;
	}
	else if(d100 == 8)
	{
		cout << "Elixer of Sneaking" << endl;
	}
	else if(d100 == 9)
	{
		cout << "Elixer of Swimming" << endl;
	}
	else if(d100 == 10)
	{
		cout << "Elixer of Vision" << endl;
	}
	else if(d100 == 11)
	{
		cout << "Silversheen (oil)" << endl;
	}
	else if(d100 == 12)
	{
		cout << "Quaal's Feather Token, Bird" << endl;
	}
	else if(d100 == 13)
	{
		cout << "Quaal's Feather Token, Tree" << endl;
	}
	else if(d100 == 14)
	{
		cout << "Quaal's Feather Token, Swan Boat" << endl;
	}
	else if(d100 == 15)
	{
		cout << "Elixer of Truth" << endl;
	}
	else if(d100 == 16)
	{
		cout << "Quaal's Feather Token, Whip" << endl;
	}
	else if(d100 == 17)
	{
		cout << "Dust of Dryness" << endl;
	}
	else if(d100 == 18)
	{
		cout << "Bag of Tricks (Gray)" << endl;
	}
	else if(d100 == 19)
	{
		cout << "Hand of the Mage" << endl;
	}
	else if(d100 == 20)
	{
		cout << "Cloak of Resistance +1" << endl;
	}
	else if(d100 == 21)
	{
		cout << "Bracers of Armor +1" << endl;
	}
	else if(d100 == 22)
	{
		cout << "Pear of Power (1st level spell)" << endl;
	}
	else if(d100 == 23)
	{
		cout << "Phylactery of Faithfulness" << endl;
	}
	else if(d100 == 24)
	{
		cout << "Salve of Slipperiness" << endl;
	}
	else if(d100 == 25)
	{
		cout << "Elixer of Firebreath" << endl;
	}
	else if(d100 == 26)
	{
		cout << "Pipes of the Sewers" << endl;
	}
	else if(d100 == 27)
	{
		cout << "Dust of Illusion" << endl;
	}
	else if(d100 == 28)
	{
		cout << "Goggles of Minute Seeing" << endl;
	}
	else if(d100 == 29)
	{
		cout << "Brooch of Shielding" << endl;
	}
	else if(d100 == 30)
	{
		cout << "Necklace of Fireballs (Type I)" << endl;
	}
	else if(d100 == 31)
	{
		cout << "Dust of Appearance" << endl;
	}
	else if(d100 == 32)
	{
		cout << "Hat of Disguise" << endl;
	}
	else if(d100 == 33)
	{
		cout << "Pipes of Sounding" << endl;
	}
	else if(d100 == 34)
	{
		cout << "Quiver of Ehlonna" << endl;
	}
	else if(d100 == 35)
	{
		cout << "Amulet of Natural Armor +1" << endl;
	}
	else if(d100 == 36)
	{
		cout << "Heward's Handy Haversack" << endl;
	}
	else if(d100 == 37)
	{
		cout << "Horn of Fog" << endl;
	}
	else if(d100 == 38)
	{
		cout << "Elemental Gem" << endl;
	}
	else if(d100 == 39)
	{
		cout << "Robe of Bones" << endl;
	}
	else if(d100 == 40)
	{
		cout << "Sovereign Glue" << endl;
	}
	else if(d100 == 41)
	{
		cout << "Bag of Holding (Type I)" << endl;
	}
	else if(d100 == 42)
	{
		cout << "Boots of Elvenkind" << endl;
	}
	else if(d100 == 43)
	{
		cout << "Boots of the Winterlands" << endl;
	}
	else if(d100 == 44)
	{
		cout << "Candle of Truth" << endl;
	}
	else if(d100 == 45)
	{
		cout << "Cloak of Elvenkind" << endl;
	}
	else if(d100 == 46)
	{
		cout << "Eyes of the Eagle" << endl;
	}
	else if(d100 == 47)
	{
		cout << "Golembane Scarab" << endl;
	}
	else if(d100 == 48)
	{
		cout << "Necklace of Fireballs (Type II)" << endl;
	}
	else if(d100 == 49)
	{
		cout << "Stone of Alarm" << endl;
	}
	else if(d100 == 50)
	{
		cout << "Bag of Tricks (Rust)" << endl;
	}
	else if(d100 == 51)
	{
		cout << "Bead of Force" << endl;
	}
	else if(d100 == 52)
	{
		cout << "Chime of Opening" << endl;
	}
	else if(d100 == 53)
	{
		cout << "Horseshoes of Speed" << endl;
	}
	else if(d100 == 54)
	{
		cout << "Rope of Climbing" << endl;
	}
	else if(d100 == 55)
	{
		cout << "Dust of Disappearance" << endl;
	}
	else if(d100 == 56)
	{
		cout << "Lens of Detection" << endl;
	}
	else if(d100 == 57)
	{
		cout << "Druid's Vestment" << endl;
	}
	else if(d100 == 58)
	{
		cout << "Figurine of Wondrous Power (Silver Raven)" << endl;
	}
	else if(d100 == 59)
	{
		cout << "Amulet of Health +2" << endl;
	}
	else if(d100 == 60)
	{
		cout << "Bracers of Armor +2" << endl;
	}
	else if(d100 == 61)
	{
		cout << "Cloak of Charisma +2" << endl;
	}
	else if(d100 == 62)
	{
		cout << "Cloak of Resistance +2" << endl;
	}
	else if(d100 == 63)
	{
		cout << "Gauntlets of Ogre Power" << endl;
	}
	else if(d100 == 64)
	{
		cout << "Gloves of Arrow Snaring" << endl;
	}
	else if(d100 == 65)
	{
		cout << "Gloves of Dexterity +2" << endl;
	}
	else if(d100 == 66)
	{
		cout << "Headband of Intellect +2" << endl;
	}
	else if(d100 == 67)
	{
		cout << "Ioun Stone (Clear Spindle)" << endl;
	}
	else if(d100 == 68)
	{
		cout << "Keoghtom's Ointment" << endl;
	}
	else if(d100 == 69)
	{
		cout << "Nolzur's Marvelous Pigments" << endl;
	}
	else if(d100 == 70)
	{
		cout << "Pear of Power (2nd level spell)" << endl;
	}
	else if(d100 == 71)
	{
		cout << "Periapt of Wisdom +2" << endl;
	}
	else if(d100 == 72)
	{
		cout << "Stone Salve" << endl;
	}
	else if(d100 == 73)
	{
		cout << "Necklace of Fireballs (Type III)" << endl;
	}
	else if(d100 == 74)
	{
		cout << "Circlet of Persuasion" << endl;
	}
	else if(d100 == 75)
	{
		cout << "Slippers of Spider Climbing" << endl;
	}
	else if(d100 == 76)
	{
		cout << "Incense of Meditation" << endl;
	}
	else if(d100 == 77)
	{
		cout << "Bag of Holding (Type II)" << endl;
	}
	else if(d100 == 78)
	{
		cout << "Lesser Bracers of Archery" << endl;
	}
	else if(d100 == 79)
	{
		cout << "Ioun Stone (Dusty Rose Prism)" << endl;
	}
	else if(d100 == 80)
	{
		cout << "Helm of Comprehend Languages and Read Magic" << endl;
	}
	else if(d100 == 81)
	{
		cout << "Vest of Escape" << endl;
	}
	else if(d100 == 82)
	{
		cout << "Eversmoking Bottle" << endl;
	}
	else if(d100 == 83)
	{
		cout << "Murlynd's Spoon" << endl;
	}
	else if(d100 == 84)
	{
		cout << "Necklance of Fireballs (Type IV)" << endl;
	}
	else if(d100 == 85)
	{
		cout << "Boots of Striding and Springing" << endl;
	}
	else if(d100 == 86)
	{
		cout << "Wind Fan" << endl;
	}
	else if(d100 == 87)
	{
		cout << "Amulet of Mighty Fists +1" << endl;
	}
	else if(d100 == 88)
	{
		cout << "Horseshoes of a Zephyr" << endl;
	}
	else if(d100 == 89)
	{
		cout << "Pipes of Haunting" << endl;
	}
	else if(d100 == 90)
	{
		cout << "Necklace of Fireballs (Type V)" << endl;
	}
	else if(d100 == 91)
	{
		cout << "Gloves of Swimming and Climbing" << endl;
	}
	else if(d100 == 92)
	{
		cout << "Bag of Tricks (Tan)" << endl;
	}
	else if(d100 == 93)
	{
		cout << "Circlet of Blasting (Minor)" << endl;
	}
	else if(d100 == 94)
	{
		cout << "Horn of Goodness/Evil" << endl;
	}
	else if(d100 == 95)
	{
		cout << "Robe of Useful Items" << endl;
	}
	else if(d100 == 96)
	{
		cout << "Folding Boat" << endl;
	}
	else if(d100 == 97)
	{
		cout << "Cloak of the Manta Ray" << endl;
	}
	else if(d100 == 98)
	{
		cout << "Bottle of Air" << endl;
	}
	else if(d100 == 99)
	{
		cout << "Bag of Holding (Type III)" << endl;
	}
	else if(d100 == 100)
	{
		cout << "Periapt of Health" << endl;
	}
}
void mediumWondrousItem()
{
	int d100 = rand()%100+1;
	if(d100 == 1)
	{
		cout << "Boots of Levitation" << endl;
	}
	else if(d100 == 2)
	{
		cout << "Harp of Charming" << endl;
	}
	else if(d100 == 3)
	{
		cout << "Amulet of Natural Armor +2" << endl;
	}
	else if(d100 == 4)
	{
		cout << "Golem Manual (Flesh)" << endl;
	}
	else if(d100 == 5)
	{
		cout << "Hand of Glory" << endl;
	}
	else if(d100 == 6)
	{
		cout << "Ioun Stone (Deep Red Sphere)" << endl;
	}
	else if(d100 == 7)
	{
		cout << "Ioun Stone (Incandescent Blue Sphere)" << endl;
	}
	else if(d100 == 8)
	{
		cout << "Ioun Stone (Pale Blue Rhomboid)" << endl;
	}
	else if(d100 == 9)
	{
		cout << "Ioun Stone (Pink and Green Sphere)" << endl;
	}
	else if(d100 == 10)
	{
		cout << "Ioun Stone (Pink Rhomboid)" << endl;
	}
	else if(d100 == 11)
	{
		cout << "Ioun Stone (Scarlet and Blue Sphere)" << endl;
	}
	else if(d100 == 12)
	{
		cout << "Deck of Illusions" << endl;
	}
	else if(d100 == 13)
	{
		cout << "Necklace of Fireballs (Type VI)" << endl;
	}
	else if(d100 == 14)
	{
		cout << "Bracers of Armor +3" << endl;
	}
	else if(d100 == 15)
	{
		cout << "Candle of Invocation" << endl;
	}
	else if(d100 == 16)
	{
		cout << "Cloak of Resistance +3" << endl;
	}
	else if(d100 == 17)
	{
		cout << "Decanter of Endless Water" << endl;
	}
	else if(d100 == 18)
	{
		cout << "Necklace of Adaptation" << endl;
	}
	else if(d100 == 19)
	{
		cout << "Pearl of Power (3rd level spell)" << endl;
	}
	else if(d100 == 20)
	{
		cout << "Talisman of the Sphere" << endl;
	}
	else if(d100 == 21)
	{
		cout << "Figurine of Wondrous Power (Serpentine Owl)" << endl;
	}
	else if(d100 == 22)
	{
		cout << "Necklace of Fireballs (Type VII)" << endl;
	}
	else if(d100 == 23)
	{
		cout << "Lesser Strand of Prayer Beads" << endl;
	}
	else if(d100 == 24)
	{
		cout << "Bag of Holding (Type IV)" << endl;
	}
	else if(d100 == 25)
	{
		cout << "Figurine of Wondrous Power (Bronze Griffin)" << endl;
	}
	else if(d100 == 26)
	{
		cout << "Figurine of Wondrous Power (Ebony Fly)" << endl;
	}
	else if(d100 == 27)
	{
		cout << "Glove of Storing" << endl;
	}
	else if(d100 == 28)
	{
		cout << "Ioun Stone (Dark Blue Rhomboid)" << endl;
	}
	else if(d100 == 29)
	{
		cout << "Stone Horse (Courser" << endl;
	}
	else if(d100 == 30)
	{
		cout << "Cape of the Mountebank" << endl;
	}
	else if(d100 == 31)
	{
		cout << "Phylactery of Undead Turning" << endl;
	}
	else if(d100 == 32)
	{
		cout << "Gauntlet of Rust" << endl;
	}
	else if(d100 == 33)
	{
		cout << "Boots of Speed" << endl;
	}
	else if(d100 == 34)
	{
		cout << "Goggles of Night" << endl;
	}
	else if(d100 == 35)
	{
		cout << "Golem Manual (Clay)" << endl;
	}
	else if(d100 == 36)
	{
		cout << "Medallion of Thoughts" << endl;
	}
	else if(d100 == 37)
	{
		cout << "Pipes of Pain" << endl;
	}
	else if(d100 == 38)
	{
		cout << "Boccob's Blessed Book" << endl;
	}
	else if(d100 == 39)
	{
		cout << "Monk's Belt" << endl;
	}
	else if(d100 == 40)
	{
		cout << "Gem of Brightness" << endl;
	}
	else if(d100 == 41)
	{
		cout << "Lyre of Building" << endl;
	}
	else if(d100 == 42)
	{
		cout << "Cloak of Arachnida" << endl;
	}
	else if(d100 == 43)
	{
		cout << "Stone Horse (Destrier)" << endl;
	}
	else if(d100 == 44)
	{
		cout << "Belt of Dwarvenkind" << endl;
	}
	else if(d100 == 45)
	{
		cout << "Horn of the Tritons" << endl;
	}
	else if(d100 == 46)
	{
		cout << "Pearl of the Sirenes" << endl;
	}
	else if(d100 == 47)
	{
		cout << "Figurine of Wondrous Power (Onyx Dog)" << endl;
	}
	else if(d100 == 48)
	{
		cout << "Periapt of Wound Closure" << endl;
	}
	else if(d100 == 49)
	{
		cout << "Amulet of Health +4" << endl;
	}
	else if(d100 == 50)
	{
		cout << "Belt of Giant Strength +4" << endl;
	}
	else if(d100 == 51)
	{
		cout << "Winged Boots" << endl;
	}
	else if(d100 == 52)
	{
		cout << "Bracers of Armor +4" << endl;
	}
	else if(d100 == 53)
	{
		cout << "Cloak of Charisma +4" << endl;
	}
	else if(d100 == 54)
	{
		cout << "Cloak of Resistance +4" << endl;
	}
	else if(d100 == 55)
	{
		cout << "Gloves of Dexterity +4" << endl;
	}
	else if(d100 == 56)
	{
		cout << "Headband of Intellect +4" << endl;
	}
	else if(d100 == 57)
	{
		cout << "Pearl of Power (4th level spell)" << endl;
	}
	else if(d100 == 58)
	{
		cout << "Periapt of Wisdom +4" << endl;
	}
	else if(d100 == 59)
	{
		cout << "Scabbard of Keen Edges" << endl;
	}
	else if(d100 == 60)
	{
		cout << "Figurine of Wondrous Power (Golden Lions)" << endl;
	}
	else if(d100 == 61)
	{
		cout << "Chime of Interruption" << endl;
	}
	else if(d100 == 62)
	{
		cout << "Broom of Flying" << endl;
	}
	else if(d100 == 63)
	{
		cout << "Figurine of Wondrous Power (Marble Elephant)" << endl;
	}
	else if(d100 == 64)
	{
		cout << "Amulet of Natural Armor +3" << endl;
	}
	else if(d100 == 65)
	{
		cout << "Ioun Stone (Iridescent Spindle)" << endl;
	}
	else if(d100 == 66)
	{
		cout << "Bracelet of Friends" << endl;
	}
	else if(d100 == 67)
	{
		cout << "Carpet of Flying (5 ft. by 5 ft.)" << endl;
	}
	else if(d100 == 68)
	{
		cout << "Horn of Blasting" << endl;
	}
	else if(d100 == 69)
	{
		cout << "Ioun Stone (Pale Lavender Ellipsoid)" << endl;
	}
	else if(d100 == 70)
	{
		cout << "Ioun Stone (Pearly White Spindle)" << endl;
	}
	else if(d100 == 71)
	{
		cout << "Portable Hole" << endl;
	}
	else if(d100 == 72)
	{
		cout << "Stone of Good Luck" << endl;
	}
	else if(d100 == 73)
	{
		cout << "Figurine of Wondrous Power (Ivory Goats)" << endl;
	}
	else if(d100 == 74)
	{
		cout << "Rope of Entanglement" << endl;
	}
	else if(d100 == 75)
	{
		cout << "Golem Manual (Stone)" << endl;
	}
	else if(d100 == 76)
	{
		cout << "Mask of the Skull" << endl;
	}
	else if(d100 == 77)
	{
		cout << "Mattock of the Titans" << endl;
	}
	else if(d100 == 78)
	{
		cout << "Circlet of Blasting (Major)" << endl;
	}
	else if(d100 == 79)
	{
		cout << "Amulet of Mighty Fists +2" << endl;
	}
	else if(d100 == 80)
	{
		cout << "Minor Cloak of Displacement" << endl;
	}
	else if(d100 == 81)
	{
		cout << "Helm of Underwater Action" << endl;
	}
	else if(d100 == 82)
	{
		cout << "Greater Bracers of Archery" << endl;
	}
	else if(d100 == 83)
	{
		cout << "Bracers of Armor +5" << endl;
	}
	else if(d100 == 84)
	{
		cout << "Cloak of Resistance +5" << endl;
	}
	else if(d100 == 85)
	{
		cout << "Eyes of Doom" << endl;
	}
	else if(d100 == 86)
	{
		cout << "Pearl of Power (5th level spell)" << endl;
	}
	else if(d100 == 87)
	{
		cout << "Maul of the Titans" << endl;
	}
	else if(d100 == 88)
	{
		cout << "Strand of Prayer Beads" << endl;
	}
	else if(d100 == 89)
	{
		cout << "Cloak of the Bat" << endl;
	}
	else if(d100 == 90)
	{
		cout << "Iron Bands of Bilarro" << endl;
	}
	else if(d100 == 91)
	{
		cout << "Cube of Frost Resistance" << endl;
	}
	else if(d100 == 92)
	{
		cout << "Helm of Telepathy" << endl;
	}
	else if(d100 == 93)
	{
		cout << "Periapt of Proof Against Poison" << endl;
	}
	else if(d100 == 94)
	{
		cout << "Robe of Scintillating Colors" << endl;
	}
	else if(d100 == 95)
	{
		cout << "Manual of Bodily Health +1" << endl;
	}
	else if(d100 == 96)
	{
		cout << "Manual of Gainful Excercise +1" << endl;
	}
	else if(d100 == 97)
	{
		cout << "Manual of Quickness of Action +1" << endl;
	}
	else if(d100 == 98)
	{
		cout << "Tome of Clear Thought +1" << endl;
	}
	else if(d100 == 99)
	{
		cout << "Tome of Leadership and Influence +1" << endl;
	}
	else
	{
		cout << "Tome of Understanding +1" << endl;
	}
}
void majorWondrousItem()
{
	int d100 = rand()%100+1;
	if(d100 == 1)
	{
		cout << "Dimensional Shackles" << endl;
	}
	else if(d100 == 2)
	{
		cout << "Figurine of Wondrous Power (Obsidian Steed)" << endl;
	}
	else if(d100 == 3)
	{
		cout << "Drums of Panic" << endl;
	}
	else if(d100 == 4)
	{
		cout << "Ioun Stone (Orange)" << endl;
	}
	else if(d100 == 5)
	{
		cout << "Ioun Stone (Pale Green Prism)" << endl;
	}
	else if(d100 == 6)
	{
		cout << "Lantern of Revealing" << endl;
	}
	else if(d100 == 7)
	{
		cout << "Robe of Blending" << endl;
	}
	else if(d100 == 8)
	{
		cout << "Amulet of Natural Armor +4" << endl;
	}
	else if(d100 == 9)
	{
		cout << "Amulet of Proof Against Detection and Location" << endl;
	}
	else if(d100 == 10)
	{
		cout << "Carpet of Flying (5 ft. by 10 ft." << endl;
	}
	else if(d100 == 11)
	{
		cout << "Golem Manual (Iron)" << endl;
	}
	else if(d100 == 12)
	{
		cout << "Amulet of Health +6" << endl;
	}
	else if(d100 == 13)
	{
		cout << "Belt of Giant Strength +6" << endl;
	}
	else if(d100 == 14)
	{
		cout << "Bracers of Armor +6" << endl;
	}
	else if(d100 == 15)
	{
		cout << "Cloak of Charisma +6" << endl;
	}
	else if(d100 == 16)
	{
		cout << "Gloves of Dexterity +6" << endl;
	}
	else if(d100 == 17)
	{
		cout << "Headband of Intellect +6" << endl;
	}
	else if(d100 == 18)
	{
		cout << "Ioun Stone (Vibrant Purple Prism)" << endl;
	}
	else if(d100 == 19)
	{
		cout << "Pearl of Power (6th level spell)" << endl;
	}
	else if(d100 == 20)
	{
		cout << "Periapt of Wisdom +6" << endl;
	}
	else if(d100 == 21)
	{
		cout << "Scarab of Protection" << endl;
	}
	else if(d100 == 22)
	{
		cout << "Ioun Stone (Lavender and Green Ellipsoid)" << endl;
	}
	else if(d100 == 23)
	{
		cout << "Ring Gates" << endl;
	}
	else if(d100 == 24)
	{
		cout << "Crystal Ball" << endl;
	}
	else if(d100 == 25)
	{
		cout << "Golem Manual (Greater Stone)" << endl;
	}
	else if(d100 == 26)
	{
		cout << "Orb of Storms" << endl;
	}
	else if(d100 == 27)
	{
		cout << "Boots of Teleportation" << endl;
	}
	else if(d100 == 28)
	{
		cout << "Bracers of Armor +7" << endl;
	}
	else if(d100 == 29)
	{
		cout << "Pearl of Power (7th level spell)" << endl;
	}
	else if(d100 == 30)
	{
		cout << "Amulet of Natural Armor +5" << endl;
	}
	else if(d100 == 31)
	{
		cout << "Cloak of Displacement (Major)" << endl;
	}
	else if(d100 == 32)
	{
		cout << "Crystal Ball with See Invisibility" << endl;
	}
	else if(d100 == 33)
	{
		cout << "Horn of Valhalla" << endl;
	}
	else if(d100 == 34)
	{
		cout << "Crystal Ball with Detect Thoughts" << endl;
	}
	else if(d100 == 35)
	{
		cout << "Carpet of Flying (6 ft. by 9 ft.)" << endl;
	}
	else if(d100 == 36)
	{
		cout << "Amulet of Mighty  Fists +3" << endl;
	}
	else if(d100 == 37)
	{
		cout << "Wings of Flying" << endl;
	}
	else if(d100 == 38)
	{
		cout << "Cloak of Etherealness" << endl;
	}
	else if(d100 == 39)
	{
		cout << "Daern's Instant Fortress" << endl;
	}
	else if(d100 == 40)
	{
		cout << "Manual of Bodily Health +2" << endl;
	}
	else if(d100 == 41)
	{
		cout << "Manual of Gainful Exercise +2" << endl;
	}
	else if(d100 == 42)
	{
		cout << "Manual of Quickness of Action +2" << endl;
	}
	else if(d100 == 43)
	{
		cout << "Tome of Clear Thought +2" << endl;
	}
	else if(d100 == 44)
	{
		cout << "Tome of Leadership and Influence +2" << endl;
	}
	else if(d100 == 45)
	{
		cout << "Tome of Understanding +2" << endl;
	}
	else if(d100 == 46)
	{
		cout << "Eyes of Charming" << endl;
	}
	else if(d100 == 47)
	{
		cout << "Robe of Stars" << endl;
	}
	else if(d100 == 48)
	{
		cout << "Carpet of Flying (10 ft. by 10. ft)" << endl;
	}
	else if(d100 == 49)
	{
		cout << "Darkskull" << endl;
	}
	else if(d100 == 50)
	{
		cout << "Cube of Force" << endl;
	}
	else if(d100 == 51)
	{
		cout << "Bracers of Armor +8" << endl;
	}
	else if(d100 == 52)
	{
		cout << "Pearl of Power (8th level spell)" << endl;
	}
	else if(d100 == 53)
	{
		cout << "Crystal Ball with Telepathy" << endl;
	}
	else if(d100 == 54)
	{
		cout << "Horn of Blasting (Greater)" << endl;
	}
	else if(d100 == 55)
	{
		cout << "Pearl of Power (two spells)" << endl;
	}
	else if(d100 == 56)
	{
		cout << "Helm of Teleportation" << endl;
	}
	else if(d100 == 57)
	{
		cout << "Gem of Seeing" << endl;
	}
	else if(d100 == 58)
	{
		cout << "Robe of the Archmagi" << endl;
	}
	else if(d100 == 59)
	{
		cout << "Mantle of Faith" << endl;
	}
	else if(d100 == 60)
	{
		cout << "Crystal Ball with True Seeing" << endl;
	}
	else if(d100 == 61)
	{
		cout << "Pearl of Power (9th level spell)" << endl;
	}
	else if(d100 == 62)
	{
		cout << "Well of Many Worlds" << endl;
	}
	else if(d100 == 63)
	{
		cout << "Manual of Bodily Health +3" << endl;
	}
	else if(d100 == 64)
	{
		cout << "Manual of Gainful Exercise +3" << endl;
	}
	else if(d100 == 65)
	{
		cout << "Manual of Quickness in Action +3" << endl;
	}
	else if(d100 == 66)
	{
		cout << "Tome of Clear Thought +3" << endl;
	}
	else if(d100 == 67)
	{
		cout << "Tome of Leadership and Influence +3" << endl;
	}
	else if(d100 == 68)
	{
		cout << "Tome of Understanding +3" << endl;
	}
	else if(d100 == 69)
	{
		cout << "Apparatus of Kwalish" << endl;
	}
	else if(d100 == 70)
	{
		cout << "Mantle of Spell Resistance" << endl;
	}
	else if(d100 == 71)
	{
		cout << "Mirror of Opposition" << endl;
	}
	else if(d100 == 72)
	{
		cout << "Strand of Prayer Beads (Greater)" << endl;
	}
	else if(d100 == 73)
	{
		cout << "Amulet of Mighty Fists +4" << endl;
	}
	else if(d100 == 74)
	{
		cout << "Eyes of Petrification" << endl;
	}
	else if(d100 == 75)
	{
		cout << "Bowl of Commanding Water Elementals" << endl;
	}
	else if(d100 == 76)
	{
		cout << "Brazier of Commanding Fire Elementals" << endl;
	}
	else if(d100 == 77)
	{
		cout << "Censer of Controlling Air Elementals" << endl;
	}
	else if(d100 == 78)
	{
		cout << "Stone of Controlling Earth Elementals" << endl;
	}
	else if(d100 == 79)
	{
		cout << "Manual of Bodily Health +4" << endl;
	}
	else if(d100 == 80)
	{
		cout << "Manual of Gainful Exercise +4" << endl;
	}
	else if(d100 == 81)
	{
		cout << "Manual of Quickness in Action +4" << endl;
	}
	else if(d100 == 82)
	{
		cout << "Tome of Clear Thought +4" << endl;
	}
	else if(d100 == 83)
	{
		cout << "Tome of Leadership and Influence +4" << endl;
	}
	else if(d100 == 84)
	{
		cout << "Tome of Understanding +4" << endl;
	}
	else if(d100 == 85)
	{
		cout << "Amulet of the Planes" << endl;
	}
	else if(d100 == 86)
	{
		cout << "Robe of Eyes" << endl;
	}
	else if(d100 == 87)
	{
		cout << "Helm of Brilliance" << endl;
	}
	else if(d100 == 88)
	{
		cout << "Manual of Bodily Health +5" << endl;
	}
	else if(d100 == 89)
	{
		cout << "Manual of Gainful Exercise +5" << endl;
	}
	else if(d100 == 90)
	{
		cout << "Manual of Quickness in Action +5" << endl;
	}
	else if(d100 == 91)
	{
		cout << "Tome of Clear Thought +5" << endl;
	}
	else if(d100 == 92)
	{
		cout << "Tome of Leadership and Influence +5" << endl;
	}
	else if(d100 == 93)
	{
		cout << "Tome of Understanding +5" << endl;
	}
	else if(d100 == 94)
	{
		cout << "Efreeti Bottle" << endl;
	}
	else if(d100 == 95)
	{
		cout << "Amulet of Mighty Fists +5" << endl;
	}
	else if(d100 == 96)
	{
		cout << "Chaos Diamond" << endl;
	}
	else if(d100 == 97)
	{
		cout << "Cubic Gate" << endl;
	}
	else if(d100 == 98)
	{
		cout << "Iron Flask" << endl;
	}
	else if(d100 == 99)
	{
		cout << "Mirror of Mental Prowess" << endl;
	}
	else
	{
		cout << "Mirror of Life Trapping" << endl;
	}
}
