haf_mandrox = Creature:new {
	objectName = "",
	customName = "Haf Mandrox",
	socialGroup = "borvo",
	faction = "borvo",
	level = 4,
	chanceHit = 0.24,
	damageMin = 40,
	damageMax = 45,
	baseXp = 62,
	baseHAM = 113,
	baseHAMmax = 138,
	armor = 0,
	resists = {0,0,0,0,0,0,0,-1,-1},
	meatType = "",
	meatAmount = 0,
	hideType = "",
	hideAmount = 0,
	boneType = "",
	boneAmount = 0,
	milk = 0,
	tamingChance = 0,
	ferocity = 0,
	pvpBitmask = ATTACKABLE,
	creatureBitmask = HERD,
	optionsBitmask = 264,
	diet = HERBIVORE,

	templates = { "object/mobile/dressed_unarmed_trainer_01.iff" },
	lootGroups = {},
	weapons = {},
	conversationTemplate = "gavyn_sykes_mission_target_convotemplate",
	attacks = brawlermaster
}

CreatureTemplates:addCreatureTemplate(haf_mandrox, "haf_mandrox")
