theme_park_rebel_bounty_hunter = Creature:new {
	objectName = "@mob/creature_names:bounty_hunter",
	socialGroup = "mercenary",
	faction = "",
	level = 24,
	chanceHit = 0.350000,
	damageMin = 220,
	damageMax = 230,
	baseXp = 2443,
	baseHAM = 6300,
	baseHAMmax = 7700,
	armor = 0,
	resists = {20,20,0,0,0,0,-1,-1,-1},
	meatType = "",
	meatAmount = 0,
	hideType = "",
	hideAmount = 0,
	boneType = "",
	boneAmount = 0,
	milk = 0,
	tamingChance = 0.000000,
	ferocity = 0,
	pvpBitmask = ATTACKABLE,
	optionsBitmask = 128,
	creatureBitmask = KILLER,
	diet = HERBIVORE,

	templates = {"object/mobile/dressed_bountyhunter_trainer_03.iff"},
	lootGroups = {},
	weapons = {"pirate_weapons_heavy"},
	attacks = merge(brawlermaster,marksmanmaster)
}

CreatureTemplates:addCreatureTemplate(theme_park_rebel_bounty_hunter, "theme_park_rebel_bounty_hunter")
