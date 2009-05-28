# Copyright (C) 2007 <SWGEmu>
 
# This File is part of Core3.
 
# This program is free software; you can redistribute 
# it and/or modify it under the terms of the GNU Lesser 
# General Public License as published by the Free Software
# Foundation; either version 2 of the License, 
# or (at your option) any later version.
 
# This program is distributed in the hope that it will be useful, 
# but WITHOUT ANY WARRANTY; without even the implied warranty of 
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
# See the GNU Lesser General Public License for
# more details.
 
# You should have received a copy of the GNU Lesser General 
# Public License along with this program; if not, write to
# the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 
# Linking Engine3 statically or dynamically with other modules 
# is making a combined work based on Engine3. 
# Thus, the terms and conditions of the GNU Lesser General Public License 
# cover the whole combination.
 
# In addition, as a special exception, the copyright holders of Engine3 
# give you permission to combine Engine3 program with free software 
# programs or libraries that are released under the GNU LGPL and with 
# code included in the standard release of Core3 under the GNU LGPL 
# license (or modified versions of such code, with unchanged license). 
# You may copy and distribute such a system following the terms of the
# GNU LGPL for Engine3 and the licenses of the other code concerned, 
# provided that you include the source code of that other code when 
# and as the GNU LGPL requires distribution of source code.
 
# Note that people who make modified versions of Engine3 are not obligated 
# to grant this special exception for their modified versions; 
# it is their choice whether to do so. The GNU Lesser General Public License 
# gives permission to release a modified version without this exception; 
# this exception also makes it possible to release a modified version 
# which carries forward this exception.

IDLC = /usr/local/bin/idlc

IDL_SOURCES = server/zone/Zone.idl \
				server/zone/ZoneClientSession.idl \
				server/zone/ZoneServer.idl \
				server/zone/objects/SceneObject.idl \
				server/zone/objects/tangible/TangibleObject.idl \
				server/zone/objects/tangible/creature/CreatureObject.idl \
				server/zone/objects/tangible/creature/player/Player.idl \
				server/zone/objects/intangible/IntangibleObject.idl \
				server/zone/objects/intangible/player/PlayerObject.idl \
				server/zone/managers/crafting/CraftingManager.idl \
				server/zone/managers/bank/BankManager.idl \
				server/zone/managers/bazaar/BazaarManager.idl \
				server/zone/managers/bazaar/BazaarPlanetManager.idl \
				server/zone/managers/creature/CreatureManager.idl \
				server/zone/managers/guild/GuildMap.idl \
				server/zone/managers/guild/GuildManager.idl \
				server/zone/managers/item/ItemManager.idl \
				server/zone/managers/loot/LootTableManager.idl \
				server/zone/managers/mission/MissionManager.idl \
				server/zone/managers/planet/PlanetManager.idl \
				server/zone/managers/player/PlayerManager.idl \
				server/zone/managers/player/PlayerMap.idl \
				server/zone/managers/resource/ResourceManager.idl \
				server/zone/managers/resource/ResourceList.idl \
				server/zone/managers/resource/ResourceItem.idl \
				server/zone/managers/resource/ResourceSpawn.idl \
				server/zone/managers/resource/SpawnLocation.idl \
				server/zone/managers/structure/StructureManager.idl \
				server/zone/managers/user/UserManager.idl \
				server/chat/room/ChatRoom.idl \

all:
	cd src && $(IDLC) $(IDL_SOURCES)
	cd build/unix && ../../configure && make
	cp build/unix/src/core3* bin
	#done

rebuild: clean all

config:
	autoreconf --force
	#done

clean: cleanidl
	cd build/unix && make clean
	#done

cleanidl:
	cd src && $(IDLC) -rebuild $(IDL_SOURCES)
