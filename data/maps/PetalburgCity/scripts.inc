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
	.string "No problem here.$"

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
	.string "Your face is reflected in the water\p"
	.string "Do you like what you see?$"

PetalburgCity_Text_FullPartyExplanation: @ 81DCA30
	.string "This here school is the pride and joy\n"
	.string "of Yuronashi.\p"
	.string "I remember graduating with the class\n"
	.string "of '23\p"
	.string "Did you graduate from here recently?$" 

PetalburgCity_Text_GymSign: @ 81DCAAA
	.string "PETALBURG CITY POKéMON GYM\n"
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
	.string "The summer semester is starting up soon,\n"
	.string "so I'm cleaning up the place to get it\l"
	.string "ready.\p"
	.string "You should come back sometime and visit\n"
	.string "once the semester begins!$"

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
	.string	"If you want, you can visit me in my\n"
	.string "office, on the top floor of the academy.\p"
	.string "I'll have a little gift for your courage.\p" 
	.string "And-- well I think it's only fair that I\n"
	.string "fill you in on what's going on.$"

arthurMove1andaHalf::
	walk_down
	walk_down
	walk_down
	face_down
	step_end

arthurText1::
	.string "T-Thank you for stepping in there.\p"
	.string "You were quite brave for one so young.\p"
	.string "However, I erge you to distance yourself\n"
	.string "from those-- those thugs...\p"
	.string "I am sure you are a fine trainer, but\n"
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

defeatKalle::
	.string "So strong...\p"
	.string "Who are you?$"

introKalle::
	.string "Sorry kid.\p"
	.string "Don't say that we didn't warn ya!$"

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
