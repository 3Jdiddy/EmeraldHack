PetalburgCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_OnFrame
	.byte 0

PetalburgCity_OnTransition: @ 81DC2D7
	setflag FLAG_VISITED_PETALBURG_CITY
	compare VAR_PETALBURG_CITY_STATE, 0
	call_if_eq PetalburgCity_EventScript_MoveBoyToWestEntrance
	compare VAR_PETALBURG_CITY_STATE, 2
	call_if_eq PetalburgCity_EventScript_DisableMapNameAndMusic
	compare VAR_PETALBURG_CITY_STATE, 4
	call_if_eq PetalburgCity_EventScript_DisableMapNameAndMusic
	compare VAR_PETALBURG_GYM_STATE, 8
	call_if_eq PetalburgCity_EventScript_SetGymDoorsUnlocked
	end

PetalburgCity_EventScript_MoveBoyToWestEntrance:: @ 81DC307
	setobjectxyperm 8, 5, 11
	return

PetalburgCity_EventScript_DisableMapNameAndMusic:: @ 81DC30F
	setflag FLAG_HIDE_MAP_NAME_POPUP
	savebgm MUS_TSURETEK
	return

PetalburgCity_EventScript_SetGymDoorsUnlocked:: @ 81DC316
	setvar VAR_PETALBURG_GYM_STATE, 7
	return

PetalburgCity_OnFrame: @ 81DC31C
	map_script_2 VAR_PETALBURG_CITY_STATE, 2, PetalburgCity_EventScript_WallyTutorial
	map_script_2 VAR_PETALBURG_CITY_STATE, 4, PetalburgCity_EventScript_WalkToWallyHouse
	.2byte 0

PetalburgCity_EventScript_WallyTutorial:: @ 81DC32E
	lockall
	special SavePlayerParty
	special PutZigzagoonInPlayerParty
	applymovement 2, PetalburgCity_Movement_WallyTutorialWally
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_WallyTutorialPlayer
	waitmovement 0
	msgbox Route102_Text_WatchMeCatchPokemon, MSGBOX_DEFAULT
	special StartWallyTutorialBattle
	waitstate
	msgbox Route102_Text_WallyIDidIt, MSGBOX_DEFAULT
	applymovement 2, Common_Movement_WalkInPlaceFastestLeft, MAP_PETALBURG_CITY
	waitmovement 2, MAP_PETALBURG_CITY
	msgbox Route102_Text_LetsGoBack, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_PETALBURG_CITY_STATE, 3
	fadedefaultbgm
	clearflag FLAG_DONT_TRANSITION_MUSIC
	special LoadPlayerParty
	setvar VAR_PETALBURG_GYM_STATE, 1
	warp MAP_PETALBURG_CITY_GYM, 255, 4, 108
	waitstate
	releaseall
	end

PetalburgCity_EventScript_WalkToWallyHouse:: @ 81DC390
	lockall
	setflag FLAG_HIDE_MAP_NAME_POPUP
	applymovement 5, PetalburgCity_Movement_WalkToWallyHouseUncle
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_WalkToWallyHousePlayer
	waitmovement 0
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 5
	opendoor VAR_0x8004, VAR_0x8005
	waitdooranim
	applymovement 5, PetalburgCity_Movement_WalkInsideHouseUncle
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_WalkInsideHousePlayer
	waitmovement 0
	setflag FLAG_HIDE_PETALBURG_CITY_WALLYS_UNCLE
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_PETALBURG_CITY
	closedoor VAR_0x8004, VAR_0x8005
	waitdooranim
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	fadedefaultbgm
	clearflag FLAG_DONT_TRANSITION_MUSIC
	warp MAP_PETALBURG_CITY_WALLYS_HOUSE, 255, 2, 4
	waitstate
	releaseall
	end

PetalburgCity_EventScript_Boy1:: @ 81DC3E6
	lock
	faceplayer
	msgbox PetalburgCity_Text_WaterReflection, MSGBOX_DEFAULT
	closemessage
	applymovement 3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PetalburgCity_EventScript_WallyAunt:: @ 81DC3FD
	msgbox PetalburgCity_Text_WhereIsWally, MSGBOX_NPC
	end

PetalburgCity_Movement_WalkToWallyHousePlayer: @ 81DC406
	delay_8
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PetalburgCity_Movement_WalkInsideHousePlayer: @ 81DC418
	walk_up
	walk_up
	step_end

PetalburgCity_Movement_WalkToWallyHouseUncle: @ 81DC41B
	delay_8
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PetalburgCity_Movement_WalkInsideHouseUncle: @ 81DC42D
	walk_up
	set_invisible
	step_end

PetalburgCity_Movement_WallyTutorialPlayer: @ 81DC430
	delay_8
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_in_place_fastest_right
	step_end

PetalburgCity_Movement_WallyTutorialWally: @ 81DC451
	delay_8
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	delay_16
	walk_in_place_fastest_up
	delay_16
	delay_16
	walk_in_place_fastest_right
	step_end

PetalburgCity_EventScript_GymSign:: @ 81DC476
	msgbox PetalburgCity_Text_GymSign, MSGBOX_SIGN
	end

PetalburgCity_EventScript_CitySign:: @ 81DC47F
	msgbox PetalburgCity_Text_CitySign, MSGBOX_SIGN
	end

PetalburgCity_EventScript_Gentleman:: @ 81DC488
	msgbox PetalburgCity_Text_FullPartyExplanation, MSGBOX_NPC
	end

PetalburgCity_EventScript_WallyHouseSign:: @ 81DC491
	msgbox PetalburgCity_Text_WallyHouseSign, MSGBOX_SIGN
	end

PetalburgCity_EventScript_ShowGymToPlayer0:: @ 81DC49A
	lockall
	setvar VAR_0x8008, 0
	goto PetalburgCity_EventScript_ShowGymToPlayer
	end

PetalburgCity_EventScript_ShowGymToPlayer1:: @ 81DC4A6
	lockall
	setvar VAR_0x8008, 1
	goto PetalburgCity_EventScript_ShowGymToPlayer
	end

PetalburgCity_EventScript_ShowGymToPlayer2:: @ 81DC4B2
	lockall
	setvar VAR_0x8008, 2
	goto PetalburgCity_EventScript_ShowGymToPlayer
	end

PetalburgCity_EventScript_ShowGymToPlayer3:: @ 81DC4BE
	lockall
	setvar VAR_0x8008, 3
	goto PetalburgCity_EventScript_ShowGymToPlayer
	end

PetalburgCity_EventScript_ShowGymToPlayer:: @ 81DC4CA
	applymovement 8, Common_Movement_FacePlayer
	waitmovement 0
	playbgm MUS_TSURETEK, 0
	playse SE_PIN
	applymovement 8, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	compare VAR_0x8008, 0
	call_if_eq PetalburgCity_EventScript_BoyApproachPlayer0
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_EventScript_BoyApproachPlayer1
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_EventScript_BoyApproachPlayer2
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_EventScript_BoyApproachPlayer3
	msgbox PetalburgCity_Text_AreYouRookieTrainer, MSGBOX_DEFAULT
	closemessage
	compare VAR_0x8008, 0
	call_if_eq PetalburgCity_EventScript_LeadPlayerToGym0
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_EventScript_LeadPlayerToGym1
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_EventScript_LeadPlayerToGym2
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_EventScript_LeadPlayerToGym3
	msgbox PetalburgCity_Text_ThisIsPetalburgGym, MSGBOX_DEFAULT
	applymovement 8, Common_Movement_WalkInPlaceFastestRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox PetalburgCity_Text_ThisIsGymSign, MSGBOX_DEFAULT
	closemessage
	applymovement 8, PetalburgCity_Movement_BoyWalkAway
	waitmovement 0
	fadedefaultbgm
	releaseall
	end

PetalburgCity_EventScript_BoyApproachPlayer0:: @ 81DC57F
	applymovement 8, PetalburgCity_Movement_BoyApproachPlayer0
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

PetalburgCity_EventScript_BoyApproachPlayer1:: @ 81DC594
	applymovement 8, PetalburgCity_Movement_BoyApproachPlayer1
	waitmovement 0
	return

PetalburgCity_EventScript_BoyApproachPlayer2:: @ 81DC59F
	applymovement 8, PetalburgCity_Movement_BoyApproachPlayer2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	return

PetalburgCity_EventScript_BoyApproachPlayer3:: @ 81DC5B4
	applymovement 8, PetalburgCity_Movement_BoyApproachPlayer3
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	return

PetalburgCity_EventScript_LeadPlayerToGym0:: @ 81DC5C9
	applymovement 8, PetalburgCity_Movement_BoyWalkToGym0
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_PlayerWalkToGym0
	waitmovement 0
	return

PetalburgCity_EventScript_LeadPlayerToGym1:: @ 81DC5DB
	applymovement 8, PetalburgCity_Movement_BoyWalkToGym1
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_PlayerWalkToGym1
	waitmovement 0
	return

PetalburgCity_EventScript_LeadPlayerToGym2:: @ 81DC5ED
	applymovement 8, PetalburgCity_Movement_BoyWalkToGym2
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_PlayerWalkToGym2
	waitmovement 0
	return

PetalburgCity_EventScript_LeadPlayerToGym3:: @ 81DC5FF
	applymovement 8, PetalburgCity_Movement_BoyWalkToGym3
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_PlayerWalkToGym3
	waitmovement 0
	return

@ Unused
PetalburgCity_Movement_Delay48:: @ 81DC611
	delay_16
	delay_16
	delay_16
	step_end

PetalburgCity_Movement_BoyApproachPlayer0: @ 81DC615
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

PetalburgCity_Movement_BoyApproachPlayer1: @ 81DC61A
	walk_right
	walk_right
	step_end

PetalburgCity_Movement_BoyApproachPlayer2: @ 81DC61D
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_down
	step_end

PetalburgCity_Movement_BoyApproachPlayer3: @ 81DC622
	walk_down
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_down
	step_end

PetalburgCity_Movement_BoyWalkToGym0: @ 81DC628
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_right
	walk_in_place_fastest_up
	step_end

PetalburgCity_Movement_BoyWalkToGym1: @ 81DC633
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_in_place_fastest_up
	step_end

PetalburgCity_Movement_BoyWalkToGym2: @ 81DC641
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_right
	walk_in_place_fastest_up
	step_end

PetalburgCity_Movement_BoyWalkToGym3: @ 81DC64C
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_in_place_fastest_up
	step_end

PetalburgCity_Movement_BoyWalkAway: @ 81DC658
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_PlayerWalkToGym0: @ 81DC665
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

PetalburgCity_Movement_PlayerWalkToGym1: @ 81DC66F
	delay_16
	delay_16
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

PetalburgCity_Movement_PlayerWalkToGym2: @ 81DC67C
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

PetalburgCity_Movement_PlayerWalkToGym3: @ 81DC686
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

PetalburgCity_EventScript_Scott0:: @ 81DC691
	lockall
	addobject 9
	setvar VAR_0x8008, 0
	setobjectxy 9, 13, 10
	goto PetalburgCity_EventScript_Scott
	end

PetalburgCity_EventScript_Scott1:: @ 81DC6A7
	lockall
	addobject 9
	setvar VAR_0x8008, 1
	setobjectxy 9, 13, 11
	goto PetalburgCity_EventScript_Scott
	end

PetalburgCity_EventScript_Scott2:: @ 81DC6BD
	lockall
	addobject 9
	setvar VAR_0x8008, 2
	setobjectxy 9, 13, 12
	goto PetalburgCity_EventScript_Scott
	end

PetalburgCity_EventScript_Scott3:: @ 81DC6D3
	lockall
	addobject 9
	setvar VAR_0x8008, 3
	setobjectxy 9, 13, 13
	goto PetalburgCity_EventScript_Scott
	end

PetalburgCity_EventScript_Scott:: @ 81DC6E9
	applymovement 9, PetalburgCity_Movement_ScottStartWalkLeft
	waitmovement 0
	playse SE_PIN
	applymovement 9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, PetalburgCity_Movement_ScottApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	setvar VAR_SCOTT_STATE, 1
	msgbox PetalburgCity_Text_AreYouATrainer, MSGBOX_DEFAULT
	closemessage
	applymovement 9, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	delay 30
	msgbox PetalburgCity_Text_WellMaybeNot, MSGBOX_DEFAULT
	closemessage
	applymovement 9, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	delay 30
	msgbox PetalburgCity_Text_ImLookingForTalentedTrainers, MSGBOX_DEFAULT
	closemessage
	compare VAR_0x8008, 0
	call_if_eq PetalburgCity_EventScript_ScottExit0
	compare VAR_0x8008, 1
	call_if_eq PetalburgCity_EventScript_ScottExit1
	compare VAR_0x8008, 2
	call_if_eq PetalburgCity_EventScript_ScottExit2
	compare VAR_0x8008, 3
	call_if_eq PetalburgCity_EventScript_ScottExit3
	setvar VAR_SCOTT_PETALBURG_ENCOUNTER, 1
	removeobject 9
	releaseall
	end

PetalburgCity_EventScript_ScottExit0:: @ 81DC78E
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_PlayerWatchScottExit0
	applymovement 9, PetalburgCity_Movement_ScottExit0
	waitmovement 0
	return

PetalburgCity_EventScript_ScottExit1:: @ 81DC7A0
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_PlayerWatchScottExit1
	applymovement 9, PetalburgCity_Movement_ScottExit1
	waitmovement 0
	return

PetalburgCity_EventScript_ScottExit2:: @ 81DC7B2
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_PlayerWatchScottExit2
	applymovement 9, PetalburgCity_Movement_ScottExit2
	waitmovement 0
	return

PetalburgCity_EventScript_ScottExit3:: @ 81DC7C4
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgCity_Movement_PlayerWatchScottExit3
	applymovement 9, PetalburgCity_Movement_ScottExit3
	waitmovement 0
	return

PetalburgCity_Movement_ScottStartWalkLeft: @ 81DC7D6
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_ScottApproachPlayer: @ 81DC7DB
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_ScottExit0: @ 81DC7E0
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_PlayerWatchScottExit0: @ 81DC7EE
	delay_16
	walk_in_place_fastest_down
	delay_16
	delay_16
	delay_8
	walk_in_place_fastest_left
	step_end

PetalburgCity_Movement_ScottExit1: @ 81DC7F5
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_PlayerWatchScottExit1: @ 81DC802
	delay_16
	walk_in_place_fastest_down
	delay_16
	delay_8
	walk_in_place_fastest_left
	step_end

PetalburgCity_Movement_ScottExit2: @ 81DC808
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_PlayerWatchScottExit2: @ 81DC815
	delay_16
	walk_in_place_fastest_down
	delay_16
	delay_8
	walk_in_place_fastest_left
	step_end

PetalburgCity_Movement_ScottExit3: @ 81DC81B
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_PlayerWatchScottExit3: @ 81DC828
	delay_16
	walk_in_place_fastest_up
	delay_16
	delay_8
	walk_in_place_fastest_left
	step_end

PetalburgCity_EventScript_Boy2:: @ 81DC82E
	msgbox PetalburgCity_Text_AreYouRookieTrainer, MSGBOX_NPC
	end

PetalburgCity_EventScript_Guy1::
	msgbox PetalburgCity_EventScript_Guy1_text, MSGBOX_NPC
	end

PetalburgCity_EventScript_Guy2::
	msgbox PetalburgCity_EventScript_Guy2_text, MSGBOX_NPC
	end

PetalburgCity_EventScript_Sign::
	msgbox PetalburgCity_EventScript_Sign_text, MSGBOX_SIGN
	end

PetalburgCity_EventScript_Sign_text::
	.string "Levata Town\p"
	.string "Home to the Levata Trainer's Academy.$"

PetalburgCity_EventScript_Guy1_text::
	.string "Ahhh...\p"
	.string "Being up this high, it brings me so\n"
	.string "much joy.\p"
	.string "The air is so fresh and pristine, heheh.$"

PetalburgCity_EventScript_Guy2_text::
	.string "No problem here.\p"
	.string "...\p"
	.string "What?$"

PetalburgCity_Text_WhereIsWally: @ 81DC837
	.string "Are you curious about the layout\n"
	.string "of our town?\p"
	.string "Me too!$"

PetalburgCity_Text_AreYouRookieTrainer: @ 81DC881
	.string "See that kid up near the waterfall?\p"
	.string "Pfft, yeah-- real werido that one.\p"
	.string "I wouldn't take what he says too\n"
	.string "seriously.$"

PetalburgCity_Text_ThisIsPetalburgGym: @ 81DC91B
	.string "See? This is PETALBURG CITY's GYM.$"

PetalburgCity_Text_ThisIsGymSign: @ 81DC93E
	.string "This is the GYM's sign. Look for it\n"
	.string "whenever you're looking for a GYM.$"

PetalburgCity_Text_WaterReflection: @ 81DC985
	.string "My face is reflected in the water.\p"
	.string "Is it a shining grin full of hope…?\p"
	.string "Or could it be a look of somber\n"
	.string "silence, struggling with fear…?\p"
	.string "Your face is reflected in the water.\p"
	.string "Do you like what you see?$"

PetalburgCity_Text_FullPartyExplanation: @ 81DCA30
	.string "This here school is the pride and joy\n"
	.string "of Yuronashi.\p"
	.string "I remember graduating with the class\n"
	.string "of '23\p"
	.string "Did you graduate from here recently?$" 

PetalburgCity_Text_GymSign: @ 81DCAAA
	.string "PETALBURG CITY Pokémon GYM\n"
	.string "LEADER: NORMAN\l"
	.string "“A man in pursuit of power!”$"

PetalburgCity_Text_CitySign: @ 81DCAF1
	.string "PETALBURG CITY\n"
	.string "“Where people mingle with nature.”$"

PetalburgCity_Text_WallyHouseSign: @ 81DCB23
	.string "WALLY'S HOUSE$"

PetalburgCity_Text_AreYouATrainer: @ 81DCB31
	.string "Excuse me!\p"
	.string "Let me guess, from the way you're\n"
	.string "dressed, are you a POKéMON TRAINER?$"

PetalburgCity_Text_WellMaybeNot: @ 81DCB82
	.string "… … … … … …\p"
	.string "Well, maybe not.\n"
	.string "Your clothes aren't all that dirty.\p"
	.string "You're either a rookie TRAINER,\n"
	.string "or maybe you're just an ordinary kid.$"

PetalburgCity_Text_ImLookingForTalentedTrainers: @ 81DCC09
	.string "I'm roaming the land in search of\n"
	.string "talented TRAINERS.\p"
	.string "I'm sorry to have taken your time.$"

trainerSchoolClosed::
	setflag FLAG_UNUSED_0x026
	setflag FLAG_UNUSED_0x029
	msgbox trainerSchoolClosed_text, MSGBOX_SIGN
	end

trainerSchoolClosed_text::
	.string "Closed for cleaning.$"

schoolJanitor::
	msgbox schoolJanitor_text, MSGBOX_NPC
	setflag FLAG_UNUSED_0x026
	end

schoolJanitor_text::
	.string "Hmm...?\p"
	.string "Oh, hey there, {PLAYER}. Long time\n"
	.string "no see, buddy.\p"
	.string "The summer quarter is starting up soon,\n"
	.string "so I'm cleaning up the place to get it\l"
	.string "ready.\p"
	.string "You should come back sometime and visit\n"
	.string "once the quarter begins!$"

firstEvilTeamMeeting_left::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, teamMeeting_playerMove1_left
	applymovement 11, privateGirlMove1
	waitmovement 0
	msgbox privateGirl_text1, MSGBOX_DEFAULT
	closemessage
	applymovement 12, girlbossMove1
	msgbox girlboss_text1, MSGBOX_DEFAULT
	closemessage
	msgbox nerdGuy_text1 MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_UNUSED_0x026
	addobject 9
	applymovement 9, nerdGuy_move1
	waitmovement 9
	msgbox nerdGuy_text2, MSGBOX_DEFAULT
	closemessage
	applymovement 12, girlbossMove2
	msgbox girlboss_text2, MSGBOX_DEFAULT
	msgbox nerdGuy_text3, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, teamMeeting_playerMove2
	waitmovement 0
	msgbox girlboss_text3, MSGBOX_DEFAULT
	applymovement 10, malePrivate_moveStep
	msgbox malePrivate_text1, MSGBOX_DEFAULT
	msgbox girlboss_text4, MSGBOX_DEFAULT
	closemessage
	applymovement 10, malePrivate_move1
	waitmovement 0
	msgbox malePrivate_text2, MSGBOX_DEFAULT
	applymovement 12, girlbossMove3
	applymovement 11, privateGirlMove2
	waitmovement 0
	applymovement 10, malePrivate_move2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, playerFaceUpWHyNot
	waitmovement 0
	msgbox kalle_text1, MSGBOX_DEFAULT
	closemessage
	setvar VAR_FORTREE_CITY_STATE, 1
	applymovement 10, kalle_move1
	waitmovement 0
	removeobject 10
	setflag FLAG_UNUSED_0x028
	removeobject 12
	removeobject 11
	setflag FLAG_UNUSED_0x027
	applymovement 9, arthurMove1
	applymovement OBJ_EVENT_ID_PLAYER, teamMeeting_playerFaceSide
	waitmovement 0
	msgbox arthurText1, MSGBOX_DEFAULT
	closemessage
	applymovement 9, arthurMove1andaHalf
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, teamMeeting_playerFaceDown
	waitmovement 0
	msgbox arthurText2, MSGBOX_DEFAULT
	closemessage
	applymovement 9, arthurMove2
	waitmovement 0
	removeobject 9
	setflag FLAG_UNUSED_0x026
	clearflag FLAG_UNUSED_0x029
	release
	end

firstEvilTeamMeeting_right::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, teamMeeting_playerMove1
	applymovement 11, privateGirlMove1
	waitmovement 0
	msgbox privateGirl_text1, MSGBOX_DEFAULT
	closemessage
	applymovement 12, girlbossMove1
	msgbox girlboss_text1, MSGBOX_DEFAULT
	closemessage
	msgbox nerdGuy_text1 MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_UNUSED_0x026
	addobject 9
	applymovement 9, nerdGuy_move1
	waitmovement 9
	msgbox nerdGuy_text2, MSGBOX_DEFAULT
	closemessage
	applymovement 12, girlbossMove2
	msgbox girlboss_text2, MSGBOX_DEFAULT
	msgbox nerdGuy_text3, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, teamMeeting_playerMove2
	waitmovement 0
	msgbox girlboss_text3, MSGBOX_DEFAULT
	applymovement 10, malePrivate_moveStep
	msgbox malePrivate_text1, MSGBOX_DEFAULT
	msgbox girlboss_text4, MSGBOX_DEFAULT
	closemessage
	applymovement 10, malePrivate_move1
	waitmovement 0
	msgbox malePrivate_text2, MSGBOX_DEFAULT
	applymovement 12, girlbossMove3
	applymovement 11, privateGirlMove2
	waitmovement 0
	applymovement 10, malePrivate_move2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, playerFaceUpWHyNot
	waitmovement 0
	msgbox kalle_text1, MSGBOX_DEFAULT
	closemessage
	setvar VAR_FORTREE_CITY_STATE, 1
	applymovement 10, kalle_move1
	waitmovement 0
	removeobject 10
	setflag FLAG_UNUSED_0x028
	removeobject 12
	removeobject 11
	setflag FLAG_UNUSED_0x027
	applymovement 9, arthurMove1
	applymovement OBJ_EVENT_ID_PLAYER, teamMeeting_playerFaceSide
	waitmovement 0
	msgbox arthurText1, MSGBOX_DEFAULT
	closemessage
	applymovement 9, arthurMove1andaHalf
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, teamMeeting_playerFaceDown
	waitmovement 0
	msgbox arthurText2, MSGBOX_DEFAULT
	closemessage
	applymovement 9, arthurMove2
	waitmovement 0
	removeobject 9
	setflag FLAG_UNUSED_0x026
	clearflag FLAG_UNUSED_0x029
	release
	end

teamMeeting_playerFaceSide::
	walk_in_place_left
	step_end

teamMeeting_playerFaceDown::
	walk_in_place_down
	step_end

arthurMove2::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

arthurText2::
	.string	"{COLOR 40}If you want, you can visit me in my\n"
	.string "office on the top floor of the academy.\p"
	.string "I think it's only fair that I\n"
	.string "fill you in on what's going on.$"

arthurMove1andaHalf::
	walk_down
	walk_down
	face_up
	step_end

arthurText1::
	.string "{COLOR 40} T-Thank you for stepping in there.\p"
	.string "You were quite brave for one so young.\p"
	.string "However, I erge you to distance yourself\n"
	.string "from those-- those thugs...\p"
	.string "I am sure you are a fine trainer but\n"
	.string "trust me, they are on another level.$"

arthurMove1::
	walk_up
	face_right
	step_end

malePrivate_moveStep::
	walk_in_place_left
	step_end

playerFaceUpWHyNot::
	walk_in_place_up
	step_end

kalle_text1::
	.string "...\p"
	.string "No badges, huh?\p"
	.string "Listen, kid. I'm not gonna fight you or\n"
	.string "anything. Just forget what you saw and\l"
	.string "don't get in the Leutenants way again,\l"
	.string "okay?\p"
	.string "Take it from me, you don't want her\n"
	.string "to remember you.$"

kalle_move1::
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end

malePrivate_move2::
	walk_down
	step_end

girlbossMove3::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

privateGirlMove2::
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

malePrivate_text2::
	.string "Roger.$"

malePrivate_text1::
	.string "Leutenant?$"

malePrivate_move1::
	walk_in_place_down
	step_end

girlboss_text3::
	.string "{COLOR 04}Oh?\p"
	.string "Who are you?\p"
	.string "I don't think you realise who you're\n"
	.string "dealing with, kid.\p"
	.string "Private Kalle!$"

girlboss_text4::
	.string "{COLOR 04}Show them.$"

teamMeeting_playerMove2::
	walk_right
	walk_right
	walk_up
	walk_up
	face_up
	step_end

nerdGuy_text3::
	.string "{COLOR 40}Arthur: Eeep...!$"

girlboss_text2::
	.string "{COLOR 04}Arthur, you again?\p"
	.string "This is military buisiness, and any\n"
	.string "interference will be seen as treason.\p"
	.string "If I were you, I would scurry off to\n"
	.string "that hole you call an academy and go\l"
	.string "back to your trivial and shallow\l"
	.string "research.\p"
	.string "Unless, of course, you intend on\n"
	.string "stopping me yourself?$"

girlbossMove2::
	walk_in_place_down
	step_end

nerdGuy_text2::
	.string "{COLOR 40}???: Please, you don't know what you're\n"
	.string "dealing with!$"

teamMeeting_playerMove1_left::
	emote_exclamation_mark
	delay_16
	walk_left
	walk_left
	face_down
	step_end

teamMeeting_playerMove1::
	emote_exclamation_mark
	delay_16
	walk_left
	face_down
	step_end

nerdGuy_move1::
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	step_end

nerdGuy_text1::
	.string "{COLOR 40}???: WAAIIIT!!$"

girlboss_text1::
	.string "{COLOR 04}Good. Let's get going, then.$"

girlbossMove1::
	walk_in_place_up
	step_end

privateGirl_text1::
	.string "Leutenant, we retreived the papers you\n"
	.string "asked for.$"

privateGirlMove1::
	walk_in_place_right
	step_end

arthurExplain0::
	lock
	faceplayer
	goto_if_set FLAG_UNUSED_0x02A, arthurAfterExplain
	msgbox arthurExplain1, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq arthurExplain_PlayerAnsweredYES
	msgbox arthurExplainFULL, MSGBOX_NPC
	goto arthurExplain_PlayerAnsweredYES2

arthurExplain_PlayerAnsweredYES::
	msgbox arthurBUFFER, MSGBOX_NPC
	msgbox arthurExplainPartial, MSGBOX_NPC
	setflag FLAG_UNUSED_0x02A
	release
	end

arthurExplain_PlayerAnsweredYES2::
	msgbox arthurExplainPartial, MSGBOX_NPC
	setflag FLAG_UNUSED_0x02A
	release
	end

arthurExplain1::
	.string "{COLOR 40}Oh... You came.\p"
	.string "Sorry. I don't mean to be rude, but\n"
	.string "there is a part of me that was hoping\l"
	.string "you wouldn't be interested.\p"
	.string "Although, after all the fuss,\n"
	.string  "how could one not be curious?\p"
	.string "So, tell me, have you heard of the\n"
	.string "Legendary Titans?$"

arthurBUFFER::
	.string "{COLOR 40}I see.\p"
	.string "Then you should know exactly\n"
	.string "how dangerous they are.$"

arthurExplainFULL::
	.string "{COLOR 40}The Legendary Titans-- Regirock,\n"
	.string "Regice, and Registeel-- are three\l"
	.string "Pokémon with incredible power,\l"
	.string "created by a golem and worshiped\l"
	.string "by ancient people.$"

arthurExplainPartial::
	.string "{COLOR 40}Those papers contained information\n"
	.string "regarding the location of one of\l"
	.string "these Titans.\p"
	.string "Those people you saw before--\n"
	.string "they once served as the military\l"
	.string "force of Yorunashi.\p"
	.string "However, since General Akuji\n"
	.string "dissapeared, his son Alexander took\l"
	.string "control of the army.\p"
	.string "Alexander has been tearing strong\n"
	.string "trainers away from their families,\l"
	.string "imposing harsh tariffs on international\l"
	.string "goods, and otherwise doing\l"
	.string "whatever he can to accrue power.\p"
	.string "But, why?\p"
	.string "There is still much we don't know,\n"
	.string "and I would advice you to stay far\l"
	.string "away from their kind.\p"
	.string "As you saw first hand, being stripped\n"
	.string "from their families hasn't nessesarily\l"
	.string "ignighted the flames of battle in the\l"
	.string "hearts of the soldiers.\p"
	.string "However, there are also those that\n"
	.string "fully support Alexander.\p"
	.string "They won't hesitate to remove you\n"
	.string "if you stand in there way!\p"
	.string "What I mean to say is: be careful.$"

arthurAfterExplain::
	msgbox arthurAfterExplainText, MSGBOX_NPC
	release
	end

arthurAfterExplainText::
	.string "{COLOR 40}Soon, I'll head to Uraranta City to\n"
	.string "discuss this with-- well,\l"
	.string "'the higher ups'.\p"
	.string "I suggest you keep your head down.$"

emptySchoolKid::
	lock
	msgbox emptySchoolKidText, MSGBOX_NPC
	release
	end

emptySchoolKidText::
	.string "Wow...\p"
	.string "The school seems a lot bigger when\n"
	.string "it's empty.\p"
	.string "I hope school starts again soon though.\n"
	.string "I want to rent a Pokémon!$"

Route105_EventScript_Steven3J::
	trainerbattle_single TRAINER_ALBERTO, Route105_EventScript_Steven3J_intro, Route105_EventScript_Steven3J_defeat
	msgbox Route105_EventScript_Steven3J_text, MSGBOX_NPC
	end

Route105_EventScript_Steven3J_text::
	.string "Mr. Yamashita is really nice for letting\n"
	.string "us look for Pokémon in his yard!$"

Route105_EventScript_Steven3J_intro::
	.string "Hey!\p"
	.string "This is private property you know!$"

Route105_EventScript_Steven3J_defeat::
	.string "Well...\n"
	.string "I never said it was MY private property.$"

Route105_EventScript_Jonathan3J::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_4, Route105_EventScript_Jonathan3J_intro, Route105_EventScript_Jonathan3J_defeat
	msgbox Route105_EventScript_Jonathan3J_text, MSGBOX_NPC
	end

Route105_EventScript_Jonathan3J_text::
	.string "Isn't it weird to see a dock on a river?\p"
	.string "You'd think it would be hard to maintain.\p"
	.string "Maybe I'll build a bridge one day!$"

Route105_EventScript_Jonathan3J_intro::
	.string "Woah!\p"
	.string "Be careful--\n"
	.string "you almost made me fall in!$"

Route105_EventScript_Jonathan3J_defeat::
	.string "Uhg. I'm always rusty in the summer.$"

Route105_EventScript_Todd3J::
	trainerbattle_single TRAINER_DECLAN, Route105_EventScript_Todd3J_intro, Route105_EventScript_Todd3J_defeat
	msgbox Route105_EventScript_Todd3J_text, MSGBOX_NPC
	end

Route105_EventScript_Todd3J_text::
	.string "Take it from me kid, you can't lose\n"
	.string "if you don't play.$"

Route105_EventScript_Todd3J_intro::
	.string "Heheheh...\n"
	.string "...Heh...Hehehe...heh\l"
	.string "Heh...\p"
	.string "You like Magikarp?$" 

Route105_EventScript_Todd3J_defeat::
	.string "You win..?\p"
	.string "No, heheh, I ALWAYS win.$"

Route105_EventScript_KatMad3J::
	trainerbattle_single TRAINER_GRUNT_RUSTURF_TUNNEL, Route105_EventScript_KatMad3J_intro, Route105_EventScript_KatMad3J_defeat
	msgbox Route105_EventScript_KatMad3J_text, MSGBOX_NPC
	end

Route105_EventScript_KatMad3J_text::
	.string "Kat: You are way strong!\p"
	.string "Maddy: Yeah, you made us look like utter\n"
	.string "garbage!\p"
	.string "Kat: Yeah!\p"
	.string "Kat: Wait...$"

Route105_EventScript_KatMad3J_intro::
	.string "Kat: You think you can take us both on?\p"
	.string "Maddy: Haha! You probably can; we are\n"
	.string "pretty bad!\p"
	.string "Kat: Yeah!\p"
	.string "Kat: Wait...$" 

Route105_EventScript_KatMad3J_defeat::
	.string "Kat: Aack! Maddy! You totally threw me\n"
	.string "off!\p"
	.string "Maddy: Eh? I did? Oops.$"

Route105_schoolkid::
	msgbox Route105_schoolkid_text, MSGBOX_NPC
	end

Route105_lass::
	msgbox Route105_lass_text, MSGBOX_NPC
	end

Route105_fisherman::
	lock
	faceplayer
	msgbox Route105_fisherman_text, MSGBOX_DEFAULT
	end

Route105_swimmer::
	msgbox Route105_swimmer_text, MSGBOX_NPC
	end

Route105_schoolkid_text::
	.string "It's rare to see nature in full bloom\n"
	.string "right outside of the city.\p"
	.string "Too many Combees if you ask me though!$"

Route105_lass_text::
	.string "Did you say hi to Mr. Yamashita?\p"
	.string "I heard he used to be a trainer, but\n"
	.string "he never likes to talk about it for\l"
	.string "some reason.$"

Route105_fisherman_text::
	.string "Having a dock out on a river is really\n"
	.string "convenient.\p"
	.string "The current isn't fast, but it's enough\n"
	.string "to bring in a large variety of fish.$"

Route105_swimmer_text::
	.string "Huff Huff Huff...\p"
	.string "I gotta big meet soon, so I basically\n"
	.string "practice 24/7\p"
	.string "Huuuuf huff...$"

EnsioCity_PhoneGuy::
	lock
	msgbox EnsioCity_PhoneGuy_Text, MSGBOX_DEFAULT
	msgbox EnsioCity_PhoneGuy_Text1, MSGBOX_NPC
	release
	end

EnsioCity_PhoneGuy_Text::
	.string "So they're in Uraranta... huh?$"

EnsioCity_PhoneGuy_Text1::
	.string "Oi, mate. I'm having a phoner.\p"
	.string "Buzz off.\p"
	.string "Yeah so as I was saying...$"

EnsioSKITTYHAHAHAH::
	lock
	faceplayer
	playmoncry SPECIES_SKITTY, 0
	release
	end

EnsioCity_SkittyGirl::
	msgbox EnsioCity_SkittyGirl_text, MSGBOX_NPC
	end

EnsioCity_SkittyGirl_text::
	.string "Aww!\p"
	.string "I just found this cutie playing with a\n"
	.string "flower in the park!\p"
	.string "If only I had a trainers license--\n"
	.string "I would catch you in a heartbeat!$"

EnsioCity_BugCatcher::
	msgbox EnsioCity_BugCatcher_text, MSGBOX_NPC
	end

EnsioCity_BugCatcher_text::
	.string "Man, even these Pokémon don't stand a\n"
	.string "chance against Pierre's prized Caterpie!\p"
	.string "I gotta train hard!$"

EnsioCity_HeartyMan::
	msgbox EnsioCity_HeartyMan_text, MSGBOX_NPC
	end

EnsioCity_HeartyMan_text::
	.string "OooOoh geez... Where's the Pokémart?\n"
	.string "This place is bigger than I thought.$"

EnsioCity_Gent::
	msgbox EnsioCity_Gent_text, MSGBOX_NPC
	end

EnsioCity_Gent_text::
	.string "FUUUUuuuuuAaahhh...\p"
	.string "Never in my day has there been a city\n"
	.string "with air as fresh as this!\p"
	.string "Ensio City truly is a joy!$"

EnsioCity_FlowerGirl::
	msgbox EnsioCity_FlowerGirl_text, MSGBOX_NPC
	end

EnsioCity_FlowerGirl_text::
	.string "Professor Lupin has quite the green\n"
	.string "thumb.\p"
	.string "Why, if these flowers could dance,\n"
	.string "I sure they would be, hohoho!$"

EnsioCity_WiseLady::
	lock
	msgbox EnsioCity_WiseLady_text, MSGBOX_DEFAULT
	msgbox EnsioCity_WiseLady_text2, MSGBOX_NPC
	end

EnsioCity_WiseLady_text::
	.string "Those flowers...\p"
	.string "Since when was the Professor so\n"
	.string "interested in botany?$"

EnsioCity_WiseLady_text2::
	.string "Oh dearie, don't mind me.\p"
	.string "I am just thinking about the past.$"

EnsioCity_Scott::
	setflag FLAG_UNUSED_0x02E  
	setflag FLAG_UNUSED_0x02D
	msgbox EnsioCity_Scott_text, MSGBOX_NPC
	end

EnsioCity_Scott_text::
	.string "Heya, sport!\p"
	.string "Pierre's already seeing a challenger\n"
	.string "right now.\p"
	.string "Why don't you look around town for a\n"
	.string "bit?\p"
	.string "I would recommend the flower shop--\n"
	.string "It's the pride of the city!\p"
	.string "Err, after this here Gym of course.\p"
	.string "Ahah...$"

EnsioCity_ApartmentFL2_Sign0::
	msgbox apartmentFL2_sign0, MSGBOX_SIGN

apartmentFL2_sign0::
	.string "Room 201$"

EnsioCity_ApartmentFL2_Sign1::
	msgbox apartmentFL2_sign1, MSGBOX_SIGN

apartmentFL2_sign1::
	.string "Room 202$"

EnsioCity_ApartmentFL2_Sign2::
	msgbox apartmentFL2_sign2, MSGBOX_SIGN

apartmentFL2_sign2::
	.string "Room 203$"

EnsioCity_ApartmentFL2_Sign3::
	msgbox apartmentFL2_sign3, MSGBOX_SIGN

apartmentFL2_sign3::
	.string "Room 204$"

EnsioCity_ApartmentFL2_Sign4::
	msgbox apartmentFL2_sign4, MSGBOX_SIGN

apartmentFL2_sign4::
	.string "Room 205$"

EnsioCity_ApartmentFL2_Sign5::
	msgbox apartmentFL2_sign5, MSGBOX_SIGN

apartmentFL2_sign5::
	.string "Room 206$"


EnsioCity_ApartmentFL1_Sign0::
	msgbox apartmentFL1_sign0, MSGBOX_SIGN

apartmentFL1_sign0::
	.string "Room 101$"

EnsioCity_ApartmentFL1_Sign1::
	msgbox apartmentFL1_sign1, MSGBOX_SIGN

apartmentFL1_sign1::
	.string "Room 102$"

EnsioCity_ApartmentFL1_Sign2::
	msgbox apartmentFL1_sign2, MSGBOX_SIGN

apartmentFL1_sign2::
	.string "Room 103$"

EnsioCity_ApartmentFL1_Sign3::
	msgbox apartmentFL1_sign3, MSGBOX_SIGN

apartmentFL1_sign3::
	.string "Room 104$"

EnsioCity_ApartmentFL1_Sign4::
	msgbox apartmentFL1_sign4, MSGBOX_SIGN

apartmentFL1_sign4::
	.string "Room 105$"

EnsioCity_ApartmentFL1_Sign5::
	msgbox apartmentFL1_sign5, MSGBOX_SIGN

apartmentFL1_sign5::
	.string "Room 106$"

locked::
	msgbox locked_text, MSGBOX_SIGN
	end

locked_text::
	.string "Locked.$"

noHotel::
	lock
	applymovement 1, hotelGirl_move1
	msgbox hotelGirl_text1, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, playerLeaveHotel
	waitmovement 0
	applymovement 1, hotelGirl_move2
	waitmovement 0
	release
	end

playerLeaveHotel::
	walk_down
	walk_down
	step_end

hotelGirl_text1::
	.string "Excuse me, but only guests and residents\n"
	.string "are allowed beyond this point.$"

hotelGirl_move1::
	emote_exclamation_mark
	face_left
	step_end

hotelGirl_move2::
	face_down
	step_end

hotelGirl::
	msgbox hotelGirl_text, MSGBOX_NPC
	end

hotelGirl_text::
	.string "Welcome!$"

hotelManager::
	applymovement 3, hotelManager_move
	msgbox hotelManager_text, MSGBOX_NPC
	end

hotelManager_move::
	walk_in_place_down
	step_end

hotelManager_text::
	.string "Welcome!\p"
	.string "Or, that is what I would like to say,\n"
	.string "but we are currently full!\p"
	.string "Things have been busy recently in\n"
	.string "preperation for the star festival.\p"
	.string "Sorry for the inconvienience.$"

flowerShopWoman::
	msgbox flowerShopWoman_text, MSGBOX_NPC
	end

flowerShopWoman_text::
	.string "Hmm I wonder what we should get him...$"

flowerShopGirl::
	msgbox flowerShopGirl_text, MSGBOX_NPC
	end

flowerShopGirl_text::
	.string "Mom always goes all-out on Father's Day.\p"
	.string "It's sweet, but sometimes it feels like\n"
	.string "a competition between the two!$"

flowerShopOldWoman::
	msgbox flowerShopOldWoman_text, MSGBOX_NPC
	end

flowerShopOldWoman_text::
	.string "Mr. Lupine has a wonderful aesthetic\n"
	.string "sense.\p"
	.string "Though, I wonder if he is still doing\n"
	.string "research?$"

flowerShopScene_3::
	lock
	applymovement 1, flowershop_prof_move1
	waitmovement 0
	msgbox flowershop_professor_Welcome, MSGBOX_NPC
	closemessage
	applymovement 1, flowershop_prof_move2
	waitmovement 0
	msgbox flowershop_professor_text2, MSGBOX_NPC
	closemessage
	applymovement 1, flowershop_professor_move3
	applymovement OBJ_EVENT_ID_PLAYER, playerGetOnProfLevel_3
	waitmovement 0
	msgbox flowershop_professor_text3, MSGBOX_DEFAULT
	closemessage
	applymovement 1, flowershop_professor_move4
	waitmovement 0
	msgbox flowershop_professor_text4, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, surprisedToSee
	applymovement 5, flowershop_dodinas_move1
	waitmovement 0
	applymovement 1, flowershop_professor_move5
	waitmovement 0
	applymovement 5, flowershop_dodinas_move2
	waitmovement 0
	msgbox flowershop_dodinas_text1, MSGBOX_DEFAULT
	closemessage
	applymovement 1, flowershop_professor_move6
	waitmovement 0
	msgbox flowershop_professor_text5, MSGBOX_DEFAULT
	closemessage
	applymovement 1, flowershop_professor_move7
	waitmovement 0
	msgbox flowershop_professor_text6, MSGBOX_DEFAULT
	applymovement 5, flowershop_dodinas_move2
	waitmovement 0
	msgbox flowershop_dodinas_text2, MSGBOX_DEFAULT
	closemessage 
	applymovement 1, flowershop_professor_move8
	waitmovement 0
	applymovement 5, flowershop_dodinas_move3
	waitmovement 0
	msgbox flowershop_dodinas_text3, MSGBOX_DEFAULT
	applymovement 1, flowershop_professor_move7
	msgbox flowershop_professor_text7, MSGBOX_DEFAULT
	closemessage
	applymovement 1, flowershop_professor_move9
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, flowershop_playerMove
	applymovement 5, flowershop_dodinas_move4
	waitmovement 0
	msgbox flowershop_professor_text8, MSGBOX_DEFAULT
	closemessage
	applymovement 1, flowershop_professor_moveA
	waitmovement 0
	playfanfare MUS_FANFA4
	waitfanfare
	msgbox system_DexReceived, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_ADVENTURE_STARTED
	applymovement 1, flowershop_professor_moveB
	waitmovement 0
	msgbox system_DexReceived_dodinas, MSGBOX_DEFAULT
	closemessage
	applymovement 1, flowershop_professor_moveC
	waitmovement 0
	msgbox flowershop_professor_text9, MSGBOX_DEFAULT
	msgbox flowershop_dodinas_text4, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, flowershop_professor_move8
	waitmovement 0
	msgbox flowershop_professor_textA, MSGBOX_DEFAULT
	closemessage
	applymovement 5, flowershop_dodinas_move5
	waitmovement 0
	msgbox flowershop_dodinas_text5, MSGBOX_DEFAULT
	closemessage
	applymovement 1, flowershop_professor_moveD
	applymovement 5, flowershop_dodinas_move6
	waitmovement 0
	hideobjectat 5, MAP_ROUTE104_PROTOTYPE_PRETTY_PETAL_FLOWER_SHOP
	setflag FLAG_UNUSED_0x02E
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_UNUSED_0x02C 
	setflag FLAG_SYS_NATIONAL_DEX   
	setvar VAR_EVER_GRANDE_CITY_STATE, 1
	release
	end

flowerShopScene_2::
	lock
	applymovement 1, flowershop_prof_move1
	waitmovement 0
	msgbox flowershop_professor_Welcome, MSGBOX_NPC
	closemessage
	applymovement 1, flowershop_prof_move2
	waitmovement 0
	msgbox flowershop_professor_text2, MSGBOX_NPC
	closemessage
	applymovement 1, flowershop_professor_move3
	applymovement OBJ_EVENT_ID_PLAYER, playerGetOnProfLevel_2
	waitmovement 0
	msgbox flowershop_professor_text3, MSGBOX_DEFAULT
	closemessage
	applymovement 1, flowershop_professor_move4
	waitmovement 0
	msgbox flowershop_professor_text4, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, surprisedToSee
	applymovement 5, flowershop_dodinas_move1
	waitmovement 0
	applymovement 1, flowershop_professor_move5
	waitmovement 0
	applymovement 5, flowershop_dodinas_move2
	waitmovement 0
	msgbox flowershop_dodinas_text1, MSGBOX_DEFAULT
	closemessage
	applymovement 1, flowershop_professor_move6
	waitmovement 0
	msgbox flowershop_professor_text5, MSGBOX_DEFAULT
	closemessage
	applymovement 1, flowershop_professor_move7
	waitmovement 0
	msgbox flowershop_professor_text6, MSGBOX_DEFAULT
	applymovement 5, flowershop_dodinas_move2
	waitmovement 0
	msgbox flowershop_dodinas_text2, MSGBOX_DEFAULT
	closemessage 
	applymovement 1, flowershop_professor_move8
	waitmovement 0
	applymovement 5, flowershop_dodinas_move3
	waitmovement 0
	msgbox flowershop_dodinas_text3, MSGBOX_DEFAULT
	applymovement 1, flowershop_professor_move7
	msgbox flowershop_professor_text7, MSGBOX_DEFAULT
	closemessage
	applymovement 1, flowershop_professor_move9
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, flowershop_playerMove
	applymovement 5, flowershop_dodinas_move4
	waitmovement 0
	msgbox flowershop_professor_text8, MSGBOX_DEFAULT
	closemessage
	applymovement 1, flowershop_professor_moveA
	waitmovement 0
	playfanfare MUS_FANFA4
	waitfanfare
	msgbox system_DexReceived, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_ADVENTURE_STARTED
	applymovement 1, flowershop_professor_moveB
	waitmovement 0
	msgbox system_DexReceived_dodinas, MSGBOX_DEFAULT
	closemessage
	applymovement 1, flowershop_professor_moveC
	waitmovement 0
	msgbox flowershop_professor_text9, MSGBOX_DEFAULT
	msgbox flowershop_dodinas_text4, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, flowershop_professor_move8
	waitmovement 0
	msgbox flowershop_professor_textA, MSGBOX_DEFAULT
	closemessage
	applymovement 5, flowershop_dodinas_move5
	waitmovement 0
	msgbox flowershop_dodinas_text5, MSGBOX_DEFAULT
	closemessage
	applymovement 1, flowershop_professor_moveD
	applymovement 5, flowershop_dodinas_move6
	waitmovement 0
	hideobjectat 5, MAP_ROUTE104_PROTOTYPE_PRETTY_PETAL_FLOWER_SHOP
	setflag FLAG_UNUSED_0x02E
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_UNUSED_0x02C 
	setvar VAR_EVER_GRANDE_CITY_STATE, 1
	setflag FLAG_SYS_NATIONAL_DEX
	release
	end

flowerShopScene_1::
	lock
	applymovement 1, flowershop_prof_move1
	waitmovement 0
	msgbox flowershop_professor_Welcome, MSGBOX_DEFAULT
	closemessage
	applymovement 1, flowershop_prof_move2
	waitmovement 0
	msgbox flowershop_professor_text2, MSGBOX_DEFAULT
	closemessage
	applymovement 1, flowershop_professor_move3
	applymovement OBJ_EVENT_ID_PLAYER, playerGetOnProfLevel_1
	waitmovement 0
	msgbox flowershop_professor_text3, MSGBOX_DEFAULT
	closemessage
	applymovement 1, flowershop_professor_move4
	waitmovement 0
	msgbox flowershop_professor_text4, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, surprisedToSee
	applymovement 5, flowershop_dodinas_move1
	waitmovement 0
	applymovement 1, flowershop_professor_move5
	waitmovement 0
	applymovement 5, flowershop_dodinas_move2
	waitmovement 0
	msgbox flowershop_dodinas_text1, MSGBOX_DEFAULT
	closemessage
	applymovement 1, flowershop_professor_move6
	waitmovement 0
	msgbox flowershop_professor_text5, MSGBOX_DEFAULT
	closemessage
	applymovement 1, flowershop_professor_move7
	waitmovement 0
	msgbox flowershop_professor_text6, MSGBOX_DEFAULT
	applymovement 5, flowershop_dodinas_move2
	waitmovement 0
	msgbox flowershop_dodinas_text2, MSGBOX_DEFAULT
	closemessage 
	applymovement 1, flowershop_professor_move8
	waitmovement 0
	applymovement 5, flowershop_dodinas_move3
	waitmovement 0
	msgbox flowershop_dodinas_text3, MSGBOX_DEFAULT
	applymovement 1, flowershop_professor_move7
	msgbox flowershop_professor_text7, MSGBOX_DEFAULT
	closemessage
	applymovement 1, flowershop_professor_move9
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, flowershop_playerMove
	applymovement 5, flowershop_dodinas_move4
	waitmovement 0
	msgbox flowershop_professor_text8, MSGBOX_DEFAULT
	closemessage
	applymovement 1, flowershop_professor_moveA
	waitmovement 0
	playfanfare MUS_FANFA4
	waitfanfare
	msgbox system_DexReceived, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_ADVENTURE_STARTED
	applymovement 1, flowershop_professor_moveB
	waitmovement 0
	msgbox system_DexReceived_dodinas, MSGBOX_DEFAULT
	closemessage
	applymovement 1, flowershop_professor_moveC
	waitmovement 0
	msgbox flowershop_professor_text9, MSGBOX_DEFAULT
	msgbox flowershop_dodinas_text4, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, flowershop_professor_move8
	waitmovement 0
	applymovement 1, flowershop_professor_moveD
	waitmovement 0
	msgbox flowershop_professor_textA, MSGBOX_DEFAULT
	closemessage
	applymovement 5, flowershop_dodinas_move5
	waitmovement 0
	msgbox flowershop_dodinas_text5, MSGBOX_DEFAULT
	closemessage
	applymovement 5, flowershop_dodinas_move6
	waitmovement 0
	hideobjectat 5, MAP_ROUTE104_PROTOTYPE_PRETTY_PETAL_FLOWER_SHOP
	setflag FLAG_UNUSED_0x02E
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_UNUSED_0x02C 
	setvar VAR_EVER_GRANDE_CITY_STATE, 1
	setflag FLAG_SYS_NATIONAL_DEX
	release
	end

flowershop_dodinas_move6::
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

flowershop_professor_moveD::
	walk_in_place_down
	step_end

flowershop_lupine::
	msgbox flowershop_lupine_text, MSGBOX_NPC
	release
	end

flowershop_lupine_text::
	.string "Thanks again for your help.\p"
	.string "I am counting on you!\p"
	.string "The Pokédex is a valuable tool; I am\n"
	.string "sure this won't be a one sided deal!$"

flowershop_dodinas_move5::
	walk_in_place_left
	step_end

flowershop_dodinas_text5::
	.string "{COLOR 15}Dodinas: Well, {PLAYER}.\p"
	.string "Do your best out there.$"

flowershop_professor_textA::
	.string "Lupine: YES!!\p"
	.string "Thank you both so much!\p"
	.string "I can't begin to tell you how much this\n"
	.string "means to me.\p"
	.string "I wish I could do more to help you,\n"
	.string "but given my situation, I will have\l"
	.string "to leave it to you two.$"


flowershop_professor_text9::
	.string "Lupine: With these, I--\p"
	.string "We can continue researching even under\n"
	.string "military surveillance.\p"
	.string "They have no way of knowing it's the\n"
	.string "two of you who have them.\p"
	.string "They may not even know what they look\n"
	.string "like, so there's no added danger.\p"
	.string "Please, help me with this research!\p"
	.string "All you have to do is catch new Pokémon;\n"
	.string "this research means the world to me--\p"
	.string "It's my life's work! It's--$"

flowershop_dodinas_text4::
	.string "{COLOR 15}Dodinas: Professor.\p"
	.string "We'll do it.$"
	
flowershop_professor_moveC::
	walk_left
	walk_up
	walk_in_place_down
	step_end

system_DexReceived_dodinas::
	.string "Dodinas received the Pokédex.$"

system_DexReceived::
	.string "{PLAYER} received the Pokédex.$"

flowershop_professor_moveB::
	walk_right
	walk_in_place_down
	step_end


flowershop_professor_moveA::
	walk_down
	step_end

flowershop_professor_text8::
	.string "However...\p"
	.string "There's something we can do that they\n"
	.string "would have no way to track.$"

flowershop_playerMove::
	walk_slow_up
	step_end

flowershop_dodinas_move4::
	walk_in_place_up
	step_end

flowershop_professor_move9::
	walk_slow_up
	walk_slow_up
	step_end


flowershop_dodinas_text3::
	.string "{COLOR 15}Dodinas: What?\p"
	.string "We're we not going to mention that?\p"
	.string "If you are going to ask them for help\n"
	.string "The least you could do is fill them in.$"

flowershop_professor_text7::
	.string "Lupine: ...\p"
	.string "You're right--\n"
	.string "Like he said, the military is holding\l"
	.string "most of my recent research over my\l"
	.string "head.\p"
	.string "They check in every so often to\n"
	.string "remind me...\p"
	.string "It's not all bad though!\p"
	.string "With all my newfound spare time,\n" 
	.string "I've gotten into gardening, hah...$"

flowershop_professor_move8::
	emote_exclamation_mark
	face_right
	step_end

flowershop_dodinas_move3::
	walk_in_place_left
	step_end

flowershop_dodinas_text2::
	.string "{COLOR 15}Dodinas: We're being blackmailed by\n"
	.string "the military.$"

flowershop_dodinas_move2::
	walk_in_place_down
	step_end

flowershop_professor_move7::
	walk_in_place_down
	step_end

flowershop_professor_move6::
	walk_in_place_right
	step_end

flowershop_professor_text5::
	.string "Lupine: So you two are already\n"
	.string "acquainted?\p"
	.string "Perfect, then I'll get right to it.$"

flowershop_professor_text6::
	.string "Lupine: Dodinas is my assistant.\n"
	.string "However, I have had to discontinue\l"
	.string "the majority of my research due to...\p"
	.string "Well...$"

flowershop_dodinas_text1::
	.string "{COLOR 15}Dodinas: It's nice to see you again,\n"
	.string "{PLAYER}.$"

surprisedToSee::
	emote_exclamation_mark
	step_end

flowershop_professor_move5::
	walk_in_place_down
	step_end

flowershop_dodinas_move1::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_down
	step_end

flowershop_professor_move4::
	walk_in_place_right
	step_end


flowershop_professor_text4::
	.string "Dodinas! {PLAYER} is here!\p"
	.string "The one I told you about earlier!$"

playerGetOnProfLevel_1::
	walk_up
	walk_right
	face_up
	step_end

playerGetOnProfLevel_2::
	walk_up
	step_end

playerGetOnProfLevel_3::
	walk_up
	walk_left
	face_up
	step_end

flowershop_prof_move1::
	walk_in_place_down
	step_end

flowershop_professor_Welcome::
	.string "Hello! Welco--$"

flowershop_prof_move2::
	emote_exclamation_mark
	step_end

flowershop_professor_text2::
	.string "Oh, you are...$"

flowershop_professor_move3::
	walk_left
	walk_down
	face_down
	walk_in_place_down
	step_end

flowershop_professor_text3::
	.string "{PLAYER}!\p"
	.string "I almost didn't recognize you; it's\n"
	.string "been a while!\p"
	.string "Your mother said you'd be stopping by,\n"
	.string "but I guess I lost track of time...\p"
	.string "Oh...!\p"
	.string "There's actually someone I want you\n"
	.string "to meet.$"

rivalEnter::
	walk_down
	walk_left
	step_end

dodinasFirstMeet_right::
	applymovement OBJ_EVENT_ID_PLAYER, dodinasFirstMeet_playerMoveLeft
	waitmovement 0
	goto dodinasFirstMeet

dodinasFirstMeet_playerMoveRight::
	walk_right
	face_up
	step_end

dodinasFirstMeet_left::
	applymovement OBJ_EVENT_ID_PLAYER, dodinasFirstMeet_playerMoveRight
	waitmovement 0
	goto dodinasFirstMeet

dodinasFirstMeet_playerMoveLeft::
	walk_left
	face_up
	step_end

dodinasFirstMeet::
	lock
	setflag FLAG_UNUSED_0x030
	fadeoutbgm 0
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, dodinasFirstMeet_CameraUp
	waitmovement 0
	applymovement 13, dodinasFirstMove1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, dodinasFirstMeet_playerMoveUp
	waitmovement 0
	special RemoveCameraObject
	msgbox dodinasFirstText1, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_RUNECITY 0
	applymovement 13, dodinasFirstMove2
	waitmovement 0
	msgbox dodinasFirstText2, MSGBOX_DEFAULT
	multichoice 20, 4, MULTI_CONTEST_INFO, 1
	waitmessage
	switch VAR_RESULT
	case 0, wishAnswer_money
	case 1, wishAnswer_power
	case 2, wishAnswer_love
	case 3, wishAnswer_hotdog
	release
	end

dodinasFirstMeet2::
	special HealPlayerParty
	compare VAR_STARTER_MON, 1
	goto_if_lt dodinasFirstMeetHoundour
	goto_if_gt dodinasFirstMeetShroomish
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT_NO_MUSIC, TRAINER_GRUNT_WEATHER_INST_2, 13, intrododinas1, defeatDodinas1, dodinasContinued1, NO_MUSIC
	end


dodinasFirstMeetShroomish::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT_NO_MUSIC, TRAINER_GRUNT_MUSEUM_1, 13, intrododinas1, defeatDodinas1, dodinasContinued1, NO_MUSIC

dodinasFirstMeetStaryu::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT_NO_MUSIC, TRAINER_GRUNT_WEATHER_INST_2, 13, intrododinas1, defeatDodinas1, dodinasContinued1, NO_MUSIC

dodinasFirstMeetHoundour::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT_NO_MUSIC, TRAINER_GRUNT_WEATHER_INST_3, 13, intrododinas1, defeatDodinas1, dodinasContinued1, NO_MUSIC

dodinasContinued1::
	playbgm MUS_RUNECITY 0
	setvar VAR_ROUTE102_STATE, 1
	msgbox dodinasFirstText3, MSGBOX_DEFAULT
	closemessage
	applymovement 13, dodinasFirstMove3
	waitmovement 0
	compare VAR_ROUTE103_STATE, 0
	goto_if_eq dodinasContinued1_2
	compare VAR_ROUTE103_STATE, 1
	goto_if_eq dodinasContinued1_3
	compare VAR_ROUTE103_STATE, 2
	goto_if_eq dodinasContinued1_4
	compare VAR_ROUTE103_STATE, 3
	goto_if_eq dodinasContinued1_5

dodinasContinued1_2::
	msgbox moneyWish_text, MSGBOX_DEFAULT
	closemessage
	applymovement 13, dodinasFirstMove4
	waitmovement 0
	msgbox moneyWish_text2, MSGBOX_DEFAULT
	closemessage
	goto dodinasFinish

moneyWish_text::
	.string "{COLOR 15}For someone who values money as much as\n"
	.string "you do, you are rather generous with\l"
	.string "your time.$"

moneyWish_text2::
	.string "{COLOR 15}Time is money too, you know.$"

dodinasContinued1_3::
	msgbox powerWish_text, MSGBOX_DEFAULT
	closemessage
	applymovement 13, dodinasFirstMove4
	waitmovement 0
	msgbox powerWish_text2, MSGBOX_DEFAULT
	closemessage
	goto dodinasFinish

powerWish_text::
	.string "{COLOR 15}Power, huh?\p"
	.string "The attempt to combine wisdom and power\n"
	.string "has only rarely been successful.\p"
	.string "In which case, it is only for a\n"
	.string "short while.$"

powerWish_text2::
	.string "{COLOR 15}I guess what I mean to say is, be\n"
	.string "careful what you wish for.$"

dodinasContinued1_4::
	msgbox loveWish_text, MSGBOX_DEFAULT
	closemessage
	applymovement 13, dodinasFirstMove4
	waitmovement 0
	msgbox loveWish_text2, MSGBOX_DEFAULT
	closemessage
	goto dodinasFinish

loveWish_text::
	.string "{COLOR 15}Would you say it is better to have\n"
	.string "loved and lost?\p"
	.string "...$"

loveWish_text2::
	.string "{COLOR 15}Maybe I am asking the wrong person.$"


dodinasContinued1_5::
	msgbox hotdogWish_text, MSGBOX_DEFAULT
	closemessage
	goto dodinasFinish

hotdogWish_text::
	.string "{COLOR 15}That battle sure worked up an appetite.\p"
	.string "Maybe I'll grab a hotdog in Ensio City.$"

dodinasFinish::
	applymovement 13, dodinasFirstLeave
	waitmovement 0
	hideobjectat 13, MAP_PETALBURG_CITY
	setflag FLAG_UNUSED_0x02F
	fadedefaultbgm
	release
	end

dodinasFirstLeave::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

dodinasFirstMove3::
	walk_slow_up
	walk_slow_up
	step_end

dodinasFirstMove4::
	walk_in_place_slow_down
	step_end

intrododinas1::
	.string "{COLOR 15}I think I have asked enough questions.\p"
	.string "Instead, how about a battle?\n"
	.string "You are a trainer, aren't you?\p"
	.string "Don't worry--\n"
	.string "I am new to this myself.$"

defeatDodinas1::
	.string "It seems I was correct.\p"
	.string "You are quite strong, {PLAYER}.$"

dodinasFirstText3::
	.string "{COLOR 15}That was useful, thank you.\p"
	.string "The Star Festival is coming up, isn't it?\p"
	.string "Maybe your wish will come true.$"

wishAnswer_hotdog::
	setvar VAR_ROUTE103_STATE, 3
	msgbox wishAnswer_hotdog_text, MSGBOX_DEFAULT
	goto dodinasFirstMeet2

wishAnswer_love::
	setvar VAR_ROUTE103_STATE, 2
	msgbox wishAnswer_love_text, MSGBOX_DEFAULT
	goto dodinasFirstMeet2

wishAnswer_power::
	setvar VAR_ROUTE103_STATE, 1
	msgbox wishAnswer_power_text, MSGBOX_DEFAULT
	goto dodinasFirstMeet2

wishAnswer_money::
	msgbox wishAnswer_money_text, MSGBOX_DEFAULT
	goto dodinasFirstMeet2

wishAnswer_hotdog_text::
	.string "{COLOR 15}...\p"
	.string "I see.\p"
	.string "Are you avoiding the question?\p"
	.string "Or maybe you're just satisfied with\n"
	.string "what you have?\p"
	.string "Or...\p"
	.string "You just really like hotdogs?\p"
	.string "Well...$"

wishAnswer_love_text::
	.string "{COLOR 15}Love?\p"
	.string "...\p"
	.string "I did not expect that.\n"
	.string "Did you not feel loved as a child?\p"
	.string "Or, are you simply a romantic?\p"
	.string "No-- that's alright.$"

wishAnswer_power_text::
	.string "{COLOR 15}Power?\p"
	.string "Intersting, and a little spooky.\n"
	.string "For Pokémon battles? Or...\l"
	.string "Maybe you have something else in mind?\p"
	.string "No-- that's alright.$"

wishAnswer_money_text::
	.string "{COLOR 15}That makes sense...\n"
	.string "everyone needs money.\p"
	.string "Hmm... but what would you spend it on?\n"
	.string "No-- that's alright.$"

dodinasFirstText2::
	.string "{COLOR 15}Excuse me.\p"
	.string "Can I ask you a question?\p"
	.string "If you could have one wish, what would\n"
	.string "you wish for?$"

dodinasFirstMove2::
	walk_down
	walk_down
	step_end
	
dodinasFirstText1::
	.string "{COLOR 15}???: ...$"

dodinasFirstMove1::
	walk_in_place_down
	step_end

dodinasFirstMeet_CameraUp::
	walk_slow_up
	walk_slow_up
	step_end

dodinasFirstMeet_playerMoveUp::
	walk_slow_up
	walk_slow_up
	step_end

sign_route105::
	msgbox sign_route105_text, MSGBOX_SIGN
	end

sign_route105_text::
	.string "Mr. Yamashita's house.$"

yamashita::
	lock
	goto_if_set FLAG_UNUSED_0x031, yamashita_after
	msgbox yamashita_text, MSGBOX_NPC
	compare VAR_STARTER_MON, 1
	goto_if_gt yamashita_give_grass
	goto_if_lt yamashita_give_grass
	msgbox yamashita_give_grass, MSGBOX_DEFAULT
	end

yamashita_after::
	msgbox yamashita_after_text, MSGBOX_NPC
	end

yamashita_after_text::
	.string "Hmm?\p"
	.string "You look dissapointed...\p"
	.string "Hahah, hey now-- beggars can't be\n"
	.string "choosers!\p"
	.string "Make the best of it!$"

yamashita_text::
	.string "Hey there, welcome!\p"
	.string "Having fun out there?\p"
	.string "Trainers seem to love my yard;\n"
	.string "I don't mind, so I let them hang\l"
	.string "around!\p"
	.string "Since you took the time to say hi,\n"
	.string "I feel like giving you something!\p"
	.string "Let's see...$"

yamashita_text2::
	.string "Ah!\p"
	.string "This should be good for you!$"

yamashita_give_grass::
	msgbox yamashita_text2
	giveitem ITEM_TM20_SAFEGUARD, 1
	setflag FLAG_UNUSED_0x031
	release
	end

yamashita_give_fire::
	msgbox yamashita_text2
	giveitem ITEM_GARDEVOIRITE, 1
	setflag FLAG_UNUSED_0x031
	release
	end

yamashita_give_water::
	msgbox yamashita_text2
	giveitem ITEM_GARDEVOIRITE, 1
	setflag FLAG_UNUSED_0x031
	release
	end
	
firstGym::
	lock
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, firstGym_cameraMove1
	waitmovement 0
	msgbox youngsterText1, MSGBOX_DEFAULT
	closemessage
	applymovement 2, youngsterWalk
	msgbox youngsterText2, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_CAMERA, firstGym_cameraMove2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, gym1PlayerMove
	msgbox pierreText1, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_CAMERA, firstGym_cameraMove3
	applymovement 2, youngsterMove
	waitmovement 0
	hideobjectat 2, MAP_RUSTBORO_CITY_GYM
	setflag FLAG_UNUSED_0x033
	applymovement OBJ_EVENT_ID_PLAYER, playerMoveBackGym
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_ROUTE105_STATE, 1
	release
	end

youngsterWalk::
	walk_in_place_up
	step_end

playerMoveBackGym::
	walk_right
	face_up
	step_end

pierreGym::
	goto_if_set FLAG_BADGE02_GET, pierreGym_afterBattle
	msgbox pierreGym_text, MSGBOX_NPC
	release
	end

pierreGym_afterBattle::
	msgbox pierreGym_afterBattle_text
	release
	end

pierreGym_afterBattle_text::
	.string "What!?\p"
	.string "I gave you your badge, freak!\n"
	.string "Leave me alone!$"


pierreGym_text::
	.string "Umm, are you new?\p"
	.string "Go on the podium!$"

youngsterMove::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

gym1PlayerMove::
	walk_slow_left
	face_right
	step_end

pierreText1::
	.string "Pierre: NOOOOOOOOOOOOOOOoooooooooooo\n"
	.string "ooooooooooooooookayy kid, nice fight.\p"
	.string "You are officially a gym badge holder.\p"
	.string "Congradulations, now uhh-- You can go.\p"
	.string "Remember to tell all your friends about\n"
	.string "the Ensio City gym and its powerful yet\l"
	.string "benevolent leader.$."

youngsterText1::
	.string "Yes!! I did it!!$"

youngsterText2::
	.string "I finally defeated your ultra powerful\n"
	.string "Caterpie!!$"

firstGym_cameraMove2::
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	step_end

firstGym_cameraMove1::
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

firstGym_cameraMove3::
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fast_down
	walk_fast_down
	walk_down
	step_end

gymBattleOne::
	lockall
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, gymBattleOne_cameraMove1
	waitmovement 0
	msgbox gymBattle_pierreText1, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq gymBattle_pierreText1_YES
	applymovement 1, pierreWalkPlace
	waitmovement 0
	msgbox gymBattle_pierreText1_NO, MSGBOX_DEFAULT
	setvar VAR_0x8004, 3   @ vertical pan
	setvar VAR_0x8005, 3   @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 4   @ shake delay
	special ShakeCamera
	msgbox rumbleText, MSGBOX_DEFAULT
	closemessage
	applymovement 1, pierePrep
	waitmovement 0
	applymovement 1, pierreFlyUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, pierreFlyUp_camerafollow
	waitmovement 0
	applymovement 1, extraDown
	waitmovement 0
	applymovement 1, pierreFlyDown
	waitmovement 0
	applymovement 1, malePrivate_move1
	waitmovement 0
	msgbox disrespectPierre, MSGBOX_DEFAULT
	setflag FLAG_DISABLE_BAG
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT_NO_MUSIC, TRAINER_ROXANNE_1, 1, introPierre, defeatPierre, afterPierre, NO_MUSIC
	clearflag FLAG_DISABLE_BAG
	release
	end

disrespectPierre::
	.string "You disrespectful little punk!\p"
	.string "What do you know about me?\p"
	.string "What do you know about ART!?$"

pierreFlyUp_camerafollow::
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	walk_fastest_down
	step_end

pierePrep::
	face_left
	face_up
	face_right
	face_down
	face_left
	face_up
	face_right
	face_down
	step_end


pierreFlyUp::
	face_left
	face_up
	face_right
	face_down
	face_left
	face_up
	face_right
	face_down
	fly_up
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end



pierreFlyDown::
	fly_down
	face_left
	face_up
	face_right
	face_down
	face_left
	face_up
	face_right
	face_down
	step_end


gymBattle_pierreText1_YES::
	msgbox happyPierre, MSGBOX_DEFAULT
	closemessage
	showmoneybox 0, 0, 0
	msgbox payup, MSGBOX_YESNO
	hidemoneybox
	compare VAR_RESULT, 1
	goto_if_eq payup_yes
	msgbox gymBattle_pierreText1_NO, MSGBOX_DEFAULT
	setvar VAR_0x8004, 3   @ vertical pan
	setvar VAR_0x8005, 3   @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 4   @ shake delay
	special ShakeCamera
	msgbox rumbleText, MSGBOX_DEFAULT
	closemessage
	applymovement 1, pierePrep
	waitmovement 0
	applymovement 1, pierreFlyUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, pierreFlyUp_camerafollow
	waitmovement 0
	applymovement 1, extraDown
	waitmovement 0
	applymovement 1, pierreFlyDown
	waitmovement 0
	applymovement 1, malePrivate_move1
	waitmovement 0
	msgbox pierreYou, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 3   @ vertical pan
	setvar VAR_0x8005, 3   @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 4   @ shake delay
	special ShakeCamera
	msgbox pierreYOU,  MSGBOX_DEFAULT
	setflag FLAG_DISABLE_BAG
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT_NO_MUSIC, TRAINER_ROXANNE_1, 1, introPierre, defeatPierre, afterPierre, NO_MUSIC
	closemessage
	release
	end

extraDown::
	walk_down
	walk_down
	walk_down
	step_end

pierreYou::
	.string "You...\p"
	.string "You think you're better than me,\n"
	.string "don't you?\p"
	.string "Grrrrr-- you little...$"

pierreYOU::
	.string "YOU FREAK!!!$"

payup_yes::
	checkmoney 50000, 0
	compare VAR_RESULT, 0
	goto_if_eq Pierre_NotEnoughMoney
	release
	end

Pierre_NotEnoughMoney::
	msgbox pierreMoneyLacking, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_CAMERA, pierreFlyUp_camerafollow
	waitmovement 0
	special RemoveCameraObject
	release
	end

pierreMoneyLacking::
	.string "Wonderful! You'll be champ in no time\n"
	.string "at this rate!\p"
	.string "Hmm?\p"
	.string "Hey! This isn't nearly enough!\p"
	.string "Scram, peasant!$"



pierreWalkPlace::
	walk_in_place_down
	step_end

introPierre::
	.string "Fine... You think you're so tough?\p"
	.string "I hate people like you-- just like\n"
	.string "the Professor, intruding on everyone's\l"
	.string "buisiness with his stupid flowers.\p" 
	.string "You're all freaks-- Freaks!\p"
	.string "I'll beat you down so hard, you'll\n"
	.string "never battle again!$"

defeatPierre::
	.string "NO!\p"
	.string "Damn it! You little--\n"
	.string "I hate you! I--\p"
	.string "...Uhhg$"

afterPierre::
	clearflag FLAG_DISABLE_BAG
	msgbox takeFirstBadge, MSGBOX_DEFAULT
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox pierre_getOut, MSGBOX_DEFAULT
	special RemoveCameraObject
	release
	end

pierre_getOut::
	.string "That's the beatle badge.\p"
	.string "What? That's it. I'm done.\p"
	.string "If you are serious about the\n"
	.string "gym challenge, I would go west\l" 
	.string "to Ururanta City, but you can\l"
	.string "do whatever-- I don't care.$"

takeFirstBadge::
	.string "Fine... Fine!\p"
	.string "Take your badge.$"

happyPierre::
	.string "You have fine taste! Wow, such talent!\p"
	.string "You may have what it takes to be a fine\n"
	.string "trainer one day!\p"
	.string "In fact, I have a special offer for you.$"

payup::
	.string "Pay me 50,000 big ones; I give you\n"
	.string "an easy fight.\p"
	.string "How about it?$"

gymBattle_pierreText1_NO::
	.string "Hahah, yes of course...\p"
	.string "Wait...$"

rumbleText::
	.string "WWHHAAAATTT!!??$"

gymBattle_pierreText1::
	.string "Pierre: Welcome. I am Pierre-- the Ensio\n"
	.string "City Gym Leader.\p"
	.string "I use Bug-Type Pokémon, and my garden is\n"
	.string "nicest in town...\p"
	.string "Err, not that anyone has any doubts--\n"
	.string "I mean, look how many flowers I have!\p"
	.string "I am sure a fine trainer such as yourself\n"
	.string "can appreciate my gym's artful aesthetic."

gymBattle_pierreText2::
	.string "$"

gymBattleOne_cameraMove1::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

AsierForestSign_resthouse::
	msgbox AsierForestSign_resthouse_text, MSGBOX_SIGN
	end

AsierForestSign_resthouse_text::
	.string "Feeling tired? Come in a have a rest!$"

EnsioCity_Mother::
	msgbox EnsioCity_Mother_text, MSGBOX_NPC
	release
	end

EnsioCity_Mother_text::
	.string "The river is so clean!\p"
	.string "We are lucky that we have a nice place\n"
	.string "to swim in the summer.\p"
	.string "So close to the city too!$"

Berryboy::
	msgbox Berryboy_text, MSGBOX_NPC
	end

Berryboy_text::
	.string "A lot of trainers overlook the\n"
	.string "importance of berries.\p"
	.string "All good trainers use berries to their\n"
	.string "fullest potential!$"

fatpokecentermaninlavata::
	msgbox fatpokecentermaninlavata_text, MSGBOX_NPC
	end

fatpokecentermaninlavata_text::
	.string "Hmmm...\p"
	.string "I wonder what I should wish for\n"
	.string "this year?\p"
	.string "Well, its not like it would ever\n"
	.string "come true.$"

apartmentSign::
	msgbox apartmentSign_text, MSGBOX_SIGN
	end

apartmentSign_text::
	.string "Ensio City Housing.$" 

bikeShop::
	msgbox bikeShop_text, MSGBOX_SIGN
	end

bikeShop_text::
	.string "Marko's Bike Shop$"

colorTest::
	.string "{COLOR 0} color 0\p"
	.string "{COLOR 1} color 1\p"
	.string "{COLOR 2} color 2\p"
	.string "{COLOR 3} color 3\p"
	.string "{COLOR 4} color 4\p"
	.string "{COLOR 5} color 5\p"
	.string "{COLOR 6} color 6\p"
	.string "{COLOR 7} color 7\p"
	.string "{COLOR 8} color 8\p"
	.string "{COLOR 9} color 9\p"
	.string "{COLOR 10} color 10\p"
	.string "{COLOR 11} color 11\p"
	.string "{COLOR 12} color 12\p"
	.string "{COLOR 13} color 13$"







