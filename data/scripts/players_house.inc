PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet:: @ 82926FE
	setvar VAR_LITTLEROOT_INTRO_STATE, 5
	return

PlayersHouse_1F_EventScript_EnterHouseMovingIn:: @ 8292704
	msgbox PlayersHouse_1F_Text_IsntItNiceInHere, MSGBOX_DEFAULT
	applymovement VAR_0x8004, Common_Movement_FacePlayer
	waitmovement 0
	compare VAR_0x8005, MALE
	call_if_eq PlayersHouse_1F_EventScript_MomFacePlayerMovingInMale
	compare VAR_0x8005, FEMALE
	call_if_eq PlayersHouse_1F_EventScript_MomFacePlayerMovingInFemale
	msgbox PlayersHouse_1F_Text_MoversPokemonGoSetClock, MSGBOX_DEFAULT
	closemessage
	setvar VAR_LITTLEROOT_INTRO_STATE, 4
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerWalkIn
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	releaseall
	end

PlayersHouse_1F_EventScript_MomFacePlayerMovingInMale:: @ 829274D
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

PlayersHouse_1F_EventScript_MomFacePlayerMovingInFemale:: @ 8292758
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	return

PlayersHouse_1F_Movement_PlayerWalkIn: @ 8292763
	walk_up
	step_end

PlayersHouse_1F_EventScript_MomGoSeeRoom:: @ 8292765
	msgbox PlayersHouse_1F_Text_ArentYouInterestedInRoom, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFastestUp
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_MovePlayerAwayFromDoor
	waitmovement 0
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_WallClock:: @ 8292781
	lockall
	setvar VAR_0x8004, MALE
	goto PlayersHouse_2F_EventScript_WallClock
	end

LittlerootTown_MaysHouse_2F_EventScript_WallClock:: @ 829278D
	lockall
	setvar VAR_0x8004, FEMALE
	goto PlayersHouse_2F_EventScript_WallClock
	end

PlayersHouse_2F_EventScript_WallClock:: @ 8292799
	goto_if_set FLAG_SET_WALL_CLOCK, PlayersHouse_2F_EventScript_CheckWallClock
	msgbox PlayersHouse_2F_Text_ClockIsStopped, MSGBOX_DEFAULT
	call PlayersHouse_2F_EventScript_SetWallClock
	delay 30
	setvar VAR_LITTLEROOT_INTRO_STATE, 6
	setflag FLAG_SET_WALL_CLOCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_1
	setflag FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_2
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq PlayersHouse_2F_EventScript_MomComesUpstairsMale
	compare VAR_RESULT, FEMALE
	call_if_eq PlayersHouse_2F_EventScript_MomComesUpstairsFemale
	playse SE_KAIDAN
	removeobject VAR_0x8008
	releaseall
	end

PlayersHouse_2F_EventScript_MomComesUpstairsMale:: @ 82927DF
	setvar VAR_0x8008, 14
	addobject VAR_0x8008
	applymovement VAR_0x8008, PlayersHouse_2F_Movement_MomEntersMale
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox PlayersHouse_2F_Text_HowDoYouLikeYourRoom, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8008, PlayersHouse_2F_Movement_MomExitsMale
	waitmovement 0
	return

PlayersHouse_2F_EventScript_MomComesUpstairsFemale:: @ 829280F
	setvar VAR_0x8008, 14
	addobject VAR_0x8008
	applymovement VAR_0x8008, PlayersHouse_2F_Movement_MomEntersFemale
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox PlayersHouse_2F_Text_HowDoYouLikeYourRoom, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8008, PlayersHouse_2F_Movement_MomExitsFemale
	waitmovement 0
	return

PlayersHouse_2F_EventScript_CheckWallClock:: @ 829283F
	incrementgamestat GAME_STAT_CHECKED_CLOCK
	fadescreen FADE_TO_BLACK
	special Special_ViewWallClock
	waitstate
	releaseall
	end

PlayersHouse_2F_EventScript_SetWallClock:: @ 8292849
	fadescreen FADE_TO_BLACK
	special StartWallClock
	waitstate
	return

PlayersHouse_2F_Movement_MomEntersMale: @ 8292850
	delay_8
	walk_down
	walk_in_place_fastest_left
	delay_16
	delay_8
	walk_left
	step_end

PlayersHouse_2F_Movement_MomExitsMale: @ 8292857
	walk_right
	walk_up
	delay_8
	step_end

PlayersHouse_2F_Movement_MomEntersFemale: @ 829285B
	delay_8
	walk_down
	walk_in_place_fastest_right
	delay_16
	delay_8
	walk_right
	step_end

PlayersHouse_2F_Movement_MomExitsFemale: @ 8292862
	walk_left
	walk_up
	delay_8
	step_end

PlayersHouse_1F_EventScript_SetWatchedBroadcast:: @ 8292866
	setvar VAR_LITTLEROOT_INTRO_STATE, 7
	releaseall
	end

PlayersHouse_1F_EventScript_PetalburgGymReportMale:: @ 829286D
	applymovement VAR_0x8005, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	call PlayersHouse_1F_EventScript_MomNoticeGymBroadcast
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerApproachTVForGymMale
	waitmovement 0
	playbgm MUS_INTER_V, 0
	msgbox PlayersHouse_1F_Text_MaybeDadWillBeOn, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8005, PlayersHouse_1F_Movement_MomMakeRoomToSeeTVMale
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerMoveToTVMale
	waitmovement 0
	call PlayersHouse_1F_EventScript_WatchGymBroadcast
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox PlayersHouse_1F_Text_ItsOverWeMissedHim, MSGBOX_DEFAULT
	msgbox PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_1, 1
	applymovement VAR_0x8005, PlayersHouse_1F_Movement_MomReturnToSeatMale
	waitmovement 0
	goto PlayersHouse_1F_EventScript_SetWatchedBroadcast
	end

PlayersHouse_1F_EventScript_PetalburgGymReportFemale:: @ 82928DC
	applymovement VAR_0x8005, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	call PlayersHouse_1F_EventScript_MomNoticeGymBroadcast
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerApproachTVForGymFemale
	waitmovement 0
	playbgm MUS_INTER_V, 0
	msgbox PlayersHouse_1F_Text_MaybeDadWillBeOn, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8005, PlayersHouse_1F_Movement_MomMakeRoomToSeeTVFemale
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerMoveToTVFemale
	waitmovement 0
	call PlayersHouse_1F_EventScript_WatchGymBroadcast
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox PlayersHouse_1F_Text_ItsOverWeMissedHim, MSGBOX_DEFAULT
	msgbox PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_1, 1
	applymovement VAR_0x8005, PlayersHouse_1F_Movement_MomReturnToSeatFemale
	waitmovement 0
	goto PlayersHouse_1F_EventScript_SetWatchedBroadcast
	end

PlayersHouse_1F_EventScript_MomNoticeGymBroadcast:: @ 829294B
	playse SE_PIN
	applymovement VAR_0x8005, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8005, Common_Movement_Delay48
	waitmovement 0
	msgbox PlayersHouse_1F_Text_OhComeQuickly, MSGBOX_DEFAULT
	closemessage
	return

PlayersHouse_1F_EventScript_WatchGymBroadcast:: @ 829296C
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox PlayersHouse_1F_Text_ReportFromPetalburgGym, MSGBOX_DEFAULT
	fadedefaultbgm
	special TurnOffTVScreen
	setflag FLAG_SYS_TV_HOME
	delay 35
	return

PlayersHouse_1F_Movement_MomApproachDadMale: @ 8292989
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_in_place_fastest_right
	step_end

PlayersHouse_1F_Movement_MomApproachDadFemale: @ 8292991
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_in_place_fastest_left
	step_end

PlayersHouse_1F_Movement_MomApproachPlayerMale: @ 8292999
	walk_right
	step_end

PlayersHouse_1F_Movement_MomApproachPlayerFemale: @ 829299B
	walk_left
	step_end

PlayersHouse_1F_Movement_MomNoticesLatiBroadcastMale: @ 829299D
	walk_in_place_fastest_left
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_fastest_right
	delay_16
	delay_16
	step_end

PlayersHouse_1F_Movement_MomNoticesLatiBroadcastFemale: @ 82929A6
	walk_in_place_fastest_right
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_fastest_left
	delay_16
	delay_16
	step_end

PlayersHouse_1F_Movement_MomApproachPlayerAfterTVMale: @ 82929AF
	walk_up
	walk_left
	walk_left
	step_end

PlayersHouse_1F_Movement_MomApproachPlayerAfterTVFemale: @ 82929B3
	walk_up
	walk_right
	walk_right
	step_end

PlayersHouse_1F_Movement_MomMakeRoomToSeeTVMale: @ 82929B7
	walk_left
	walk_in_place_fastest_right
	step_end

PlayersHouse_1F_Movement_MomMakeRoomToSeeTVFemale: @ 82929BA
	walk_right
	walk_in_place_fastest_left
	step_end

PlayersHouse_1F_Movement_MomReturnToSeatMale: @ 82929BD
	walk_left
	walk_down
	walk_in_place_fastest_right
	step_end

PlayersHouse_1F_Movement_MomReturnToSeatFemale: @ 82929C1
	walk_right
	walk_down
	walk_in_place_fastest_left
	step_end

PlayersHouse_1F_EventScript_Mom:: @ 82929C5
	lock
	faceplayer
	compare VAR_LITTLEROOT_HOUSES_STATE_MAY, 4
	goto_if_eq PlayersHouse_1F_EventScript_DontPushYourselfTooHard
	compare VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 4
	goto_if_eq PlayersHouse_1F_EventScript_DontPushYourselfTooHard
	goto_if_set FLAG_HAS_MATCH_CALL, PlayersHouse_1F_EventScript_TryRegisterMom
	goto_if_set FLAG_RESCUED_BIRCH, PlayersHouse_1F_EventScript_MomHealsParty
	compare VAR_TEMP_1, 1
	goto_if_eq PlayersHouse_1F_EventScript_SeeYouHoney
	compare VAR_LITTLEROOT_INTRO_STATE, 7
	goto_if_eq PlayersHouse_1F_EventScript_DidYouMeetProfBirch
	msgbox PlayersHouse_1F_Text_IsntItNiceInHere, MSGBOX_DEFAULT
	release
	end

PlayersHouse_1F_EventScript_DontPushYourselfTooHard:: @ 8292A0F
	msgbox PlayersHouse_1F_Text_DontPushYourselfTooHard, MSGBOX_DEFAULT
	release
	end

PlayersHouse_1F_EventScript_TryRegisterMom:: @ 8292A19
	goto_if_set FLAG_ENABLE_MOM_MATCH_CALL, PlayersHouse_1F_EventScript_CheckGiveAmuletCoin
	msgbox PlayersHouse_1F_Text_IsThatAPokenav, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_ME_TORE_EYE
	msgbox PlayersHouse_1F_Text_RegisteredMom, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_MOM_MATCH_CALL
	release
	end

PlayersHouse_1F_EventScript_CheckGiveAmuletCoin:: @ 8292A43
	goto_if_set FLAG_BADGE05_GET, PlayersHouse_1F_EventScript_TryGiveAmuletCoin
	goto PlayersHouse_1F_EventScript_MomHealsParty

PlayersHouse_1F_EventScript_TryGiveAmuletCoin:: @ 8292A51
	goto_if_set FLAG_RECEIVED_AMULET_COIN, PlayersHouse_1F_EventScript_MomHealsParty
	msgbox PlayersHouse_1F_Text_GotDadsBadgeHeresSomethingFromMom, MSGBOX_DEFAULT
	giveitem ITEM_AMULET_COIN
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	msgbox PlayersHouse_1F_Text_DontPushYourselfTooHard, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_AMULET_COIN
	release
	end

PlayersHouse_1F_EventScript_MomHealsParty:: @ 8292A86
	msgbox PlayersHouse_1F_Text_YouShouldRestABit, MSGBOX_DEFAULT
	goto PlayersHouse_1F_EventScript_HealParty
	end

PlayersHouse_1F_EventScript_SeeYouHoney:: @ 8292A94
	msgbox PlayersHouse_1F_Text_SeeYouHoney, MSGBOX_DEFAULT
	release
	end

PlayersHouse_1F_EventScript_HealParty:: @ 8292A9E
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	incrementgamestat GAME_STAT_RESTED_AT_HOME
	msgbox PlayersHouse_1F_Text_TakeCareHoney, MSGBOX_DEFAULT
	release
	end

PlayersHouse_1F_EventScript_DidYouMeetProfBirch:: @ 8292AB0
	msgbox PlayersHouse_1F_Text_DidYouMeetProfBirch, MSGBOX_DEFAULT
	release
	end

PlayersHouse_1F_EventScript_Vigoroth1:: @ 8292ABA
	lock
	faceplayer
	waitse
	playmoncry SPECIES_VIGOROTH, 0
	msgbox PlayersHouse_1F_Text_Vigoroth1, MSGBOX_DEFAULT
	waitmoncry
	release
	end

PlayersHouse_1F_EventScript_Vigoroth2:: @ 8292ACD
	lock
	faceplayer
	waitse
	playmoncry SPECIES_VIGOROTH, 0
	msgbox PlayersHouse_1F_Text_Vigoroth2, MSGBOX_DEFAULT
	waitmoncry
	release
	end

PlayersHouse_1F_Movement_PlayerApproachTVForGymMale: @ 8292AE0
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

PlayersHouse_1F_Movement_PlayerMoveToTVMale: @ 8292AE6
	walk_left
	step_end

PlayersHouse_1F_Movement_PlayerApproachTVForGymFemale: @ 8292AE8
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

PlayersHouse_1F_Movement_PlayerMoveToTVFemale: @ 8292AEE
	walk_right
	step_end

PlayersHouse_1F_Movement_MovePlayerAwayFromDoor: @ 8292AF0
	walk_up
	step_end

PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV:: @ 8292AF2
	lockall
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq PlayersHouse_1F_EventScript_SetUpObjectEventVarsMale
	compare VAR_RESULT, FEMALE
	call_if_eq PlayersHouse_1F_EventScript_SetUpObjectEventVarsFemale
	compare VAR_0x8008, MALE
	call_if_eq PlayersHouse_1F_EventScript_PlayerEnterRoomMale
	compare VAR_0x8008, FEMALE
	call_if_eq PlayersHouse_1F_EventScript_PlayerEnterRoomFemale
	applymovement VAR_0x8009, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement VAR_0x8009, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8009, Common_Movement_Delay48
	waitmovement 0
	delay 20
	compare VAR_0x8008, MALE
	call_if_eq PlayersHouse_1F_EventScript_DadApproachPlayerMale
	compare VAR_0x8008, FEMALE
	call_if_eq PlayersHouse_1F_EventScript_DadApproachPlayerFemale
	msgbox PlayersHouse_1F_Text_TicketFromBrineyCameForYou, MSGBOX_DEFAULT
	giveitem ITEM_SS_TICKET
	msgbox PlayersHouse_1F_Text_PortsInSlateportLilycove, MSGBOX_DEFAULT
	closemessage
	delay 20
	compare VAR_0x8008, MALE
	call_if_eq PlayersHouse_1F_EventScript_MomApproachDadMale
	compare VAR_0x8008, FEMALE
	call_if_eq PlayersHouse_1F_EventScript_MomApproachDadFemale
	msgbox PlayersHouse_1F_Text_BetterGetBackToGym, MSGBOX_DEFAULT
	closemessage
	compare VAR_0x8008, MALE
	call_if_eq PlayersHouse_1F_EventScript_DadExitsMale
	compare VAR_0x8008, FEMALE
	call_if_eq PlayersHouse_1F_EventScript_DadExitsFemale
	playse SE_DOOR
	removeobject VAR_0x8009
	setflag FLAG_RECEIVED_SS_TICKET
	delay 30
	compare VAR_0x8008, MALE
	call_if_eq PlayersHouse_1F_EventScript_MomApproachPlayerMale
	compare VAR_0x8008, FEMALE
	call_if_eq PlayersHouse_1F_EventScript_MomApproachPlayerFemale
	delay 20
	msgbox PlayersHouse_1F_Text_DadShouldStayLonger, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SYS_TV_LATIAS_LATIOS
	special TurnOnTVScreen
	delay 60
	compare VAR_0x8008, MALE
	call_if_eq PlayersHouse_1F_EventScript_MomNoticesLatiBroadcastMale
	compare VAR_0x8008, FEMALE
	call_if_eq PlayersHouse_1F_EventScript_MomNoticesLatiBroadcastFemale
	msgbox PlayersHouse_1F_Text_IsThatABreakingStory, MSGBOX_DEFAULT
	closemessage
	compare VAR_0x8008, MALE
	call_if_eq PlayersHouse_1F_EventScript_PlayerApproachTVForLatiMale
	compare VAR_0x8008, FEMALE
	call_if_eq PlayersHouse_1F_EventScript_PlayerApproachTVForLatiFemale
	msgbox PlayersHouse_1F_Text_LatiEmergencyNewsFlash, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_SYS_TV_LATIAS_LATIOS
	setflag FLAG_LATIOS_OR_LATIAS_ROAMING
	special TurnOffTVScreen
	compare VAR_0x8008, MALE
	call_if_eq PlayersHouse_1F_EventScript_MomApproachPlayerAfterTVMale
	compare VAR_0x8008, FEMALE
	call_if_eq PlayersHouse_1F_EventScript_MomApproachPlayerAfterTVFemale
	msgbox PlayersHouse_1F_Text_WhatColorDidTheySay, MSGBOX_DEFAULT
	multichoice 22, 8, MULTI_TV_LATI, 1
	copyvar VAR_0x8004, VAR_RESULT
	special InitRoamer
	copyvar VAR_ROAMER_POKEMON, VAR_RESULT
	msgbox PlayersHouse_1F_Text_StillUnknownPokemon, MSGBOX_DEFAULT
	closemessage
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 4
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 4
	releaseall
	end

@ Never called.
PlayersHouse_1F_EventScript_AirLatiBroadcast:: @ 8292C72
	setflag FLAG_SYS_TV_LATIAS_LATIOS
	return

PlayersHouse_1F_EventScript_SetUpObjectEventVarsMale:: @ 8292C76
	setvar VAR_0x8008, MALE
	setvar VAR_0x8009, 5  @ Dad object event ID
	setvar VAR_0x800A, 1  @ Mom object event ID
	return

PlayersHouse_1F_EventScript_SetUpObjectEventVarsFemale:: @ 8292C86
	setvar VAR_0x8008, FEMALE
	setvar VAR_0x8009, 5  @ Dad object event ID
	setvar VAR_0x800A, 1  @ Mom object event ID
	return

PlayersHouse_1F_EventScript_DadApproachPlayerMale:: @ 8292C96
	applymovement VAR_0x8009, PlayersHouse_1F_Movement_DadApproachPlayerMale
	waitmovement 0
	return

PlayersHouse_1F_EventScript_DadApproachPlayerFemale:: @ 8292CA1
	applymovement VAR_0x8009, PlayersHouse_1F_Movement_DadApproachPlayerFemale
	waitmovement 0
	return

PlayersHouse_1F_EventScript_MomApproachDadMale:: @ 8292CAC
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomApproachDadMale
	waitmovement 0
	applymovement VAR_0x8009, PlayersHouse_1F_Movement_DadFaceMomMale
	waitmovement 0
	return

PlayersHouse_1F_EventScript_MomApproachDadFemale:: @ 8292CC1
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomApproachDadFemale
	waitmovement 0
	applymovement VAR_0x8009, PlayersHouse_1F_Movement_DadFaceMomFemale
	waitmovement 0
	return

PlayersHouse_1F_EventScript_DadExitsMale:: @ 8292CD6
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_MomAndPlayerWatchDadExit
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomAndPlayerWatchDadExit
	applymovement VAR_0x8009, PlayersHouse_1F_Movement_DadExitsMale
	waitmovement 0
	return

PlayersHouse_1F_EventScript_DadExitsFemale:: @ 8292CEF
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_MomAndPlayerWatchDadExit
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomAndPlayerWatchDadExit
	applymovement VAR_0x8009, PlayersHouse_1F_Movement_DadExitsFemale
	waitmovement 0
	return

PlayersHouse_1F_EventScript_PlayerEnterRoomMale:: @ 8292D08
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerEnterRoomMale
	waitmovement 0
	return

PlayersHouse_1F_EventScript_PlayerEnterRoomFemale:: @ 8292D13
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerEnterRoomFemale
	waitmovement 0
	return

PlayersHouse_1F_EventScript_PlayerApproachTVForLatiMale:: @ 8292D1E
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerApproachTVForLatiMale
	waitmovement 0
	applymovement VAR_0x800A, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	return

PlayersHouse_1F_EventScript_PlayerApproachTVForLatiFemale:: @ 8292D33
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_1F_Movement_PlayerApproachTVForLatiFemale
	waitmovement 0
	applymovement VAR_0x800A, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

PlayersHouse_1F_EventScript_MomApproachPlayerMale:: @ 8292D48
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomApproachPlayerMale
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	return

PlayersHouse_1F_EventScript_MomApproachPlayerFemale:: @ 8292D5D
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomApproachPlayerFemale
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

PlayersHouse_1F_EventScript_MomNoticesLatiBroadcastMale:: @ 8292D72
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomNoticesLatiBroadcastMale
	waitmovement 0
	return

PlayersHouse_1F_EventScript_MomNoticesLatiBroadcastFemale:: @ 8292D7D
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomNoticesLatiBroadcastFemale
	waitmovement 0
	return

PlayersHouse_1F_EventScript_MomApproachPlayerAfterTVMale:: @ 8292D88
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomApproachPlayerAfterTVMale
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

PlayersHouse_1F_EventScript_MomApproachPlayerAfterTVFemale:: @ 8292D9D
	applymovement VAR_0x800A, PlayersHouse_1F_Movement_MomApproachPlayerAfterTVFemale
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	return

PlayersHouse_1F_Movement_DadApproachPlayerMale: @ 8292DB2
	walk_right
	walk_right
	step_end

PlayersHouse_1F_Movement_DadApproachPlayerFemale: @ 8292DB5
	walk_left
	walk_left
	step_end

PlayersHouse_1F_Movement_DadFaceMomMale: @ 8292DB8
	face_left
	step_end

PlayersHouse_1F_Movement_DadFaceMomFemale: @ 8292DBA
	face_right
	step_end

PlayersHouse_1F_Movement_DadExitsMale: @ 8292DBC
	walk_down
	walk_right
	walk_down
	delay_8
	step_end

PlayersHouse_1F_Movement_DadExitsFemale: @ 8292DC1
	walk_down
	walk_left
	walk_down
	delay_8
	step_end

PlayersHouse_1F_Movement_PlayerEnterRoomMale: @ 8292DC6
	delay_16
	walk_down
	walk_down
	walk_down
	walk_in_place_fastest_left
	step_end

PlayersHouse_1F_Movement_MomAndPlayerWatchDadExit: @ 8292DCC
	delay_8
	delay_16
	delay_16
	walk_in_place_fastest_down
	step_end

PlayersHouse_1F_Movement_PlayerEnterRoomFemale: @ 8292DD1
	delay_16
	walk_down
	walk_down
	walk_down
	walk_in_place_fastest_right
	step_end

PlayersHouse_1F_Movement_PlayerApproachTVForLatiMale: @ 8292DD7
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end

PlayersHouse_1F_Movement_PlayerApproachTVForLatiFemale: @ 8292DDE
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

EventScript_RunningShoesManual:: @ 8292DE5
	msgbox PlayersHouse_1F_Text_RunningShoesManual, MSGBOX_SIGN
	end

firstCutScene::
	lock
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
	setflag FLAG_UNUSED_0x025
	setflag FLAG_SYS_NATIONAL_DEX
	setflag FLAG_SYS_B_DASH
	setvar VAR_UNUSED_0x404E, 1
	applymovement OBJ_EVENT_ID_PLAYER, firstCutScene_playerMove1
	waitmovement 0
	applymovement 2, momStep
	waitmovement 0
	msgbox firstCutScene_Text_0
	closemessage
	applymovement 1, lucySeesPlayer
	waitmovement 0
	msgbox firstCutScene_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq firstCutScene_2
	msgbox firstCutScene_Text_3
	closemessage
	goto firstCutScene_1

firstCutScene_playerMove1::
	walk_down
	walk_down
	walk_in_place_left
	step_end

firstCutScene_1:
	applymovement 2, momToPlayer
	waitmovement 0
	msgbox firstCutScene_Text_4
	closemessage
	applymovement 2, momFaceDown
	waitmovement 0
	release
	end

momFaceDown:
	walk_up
	walk_right
	face_left
	step_end

firstCutScene_2:
	msgbox firstCutScene_Text_2
	closemessage
	goto firstCutScene_1

momToPlayer:
	walk_right
	walk_right
	step_end

playerHouse_TV::
	msgbox playerHouse_TV_text, MSGBOX_SIGN
	end

playerHouse_TV_text::
	.string "It's a cooking show!\p"
	.string "The chef looks angry.$"

momStep:
	walk_in_place_right
	step_end

lucySeesPlayer:
	emote_exclamation_mark
	delay_16
	face_player
	step_end

firstCutScene_Text_0:
	.string "{COLOR 04}Mom: Oh, {PLAYER}!\p"
	.string "There you are!$"

firstCutScene_Text_1:
	.string "{COLOR 06}Lucy: Hey, {PLAYER}!\p"
	.string "Have you finished packing yet?$"

firstCutScene_Text_2:
	.string "{COLOR 04}Mom: Don't worry about it, {PLAYER}.\p"
	.string "I'll take care of what's left.$"

firstCutScene_Text_3:
	.string "{COLOR 06}Lucy: About time!\p"
	.string "We should really get going soon!$"

firstCutScene_Text_4:
	.string "{COLOR 04}Mom: Before you head out, I have one\n"
	.string "more thing for the two of you!\p"
	.string "Why don't you take a look in\n"
	.string "that bag on the table?$"

lucyTalk::
	lock
	faceplayer
	msgbox lucyText, MSGBOX_DEFAULT
	release
	end

lucyText:
	.string "{COLOR 06}Lucy: Hehe.\p"
	.string "Your Mom's so funny,\n"
	.string "trying to play coy like that.\p"
	.string "You and I both know what's in that\n"
	.string "bag!\p"
	.string "Just make sure you save one for me!$"

momTalk::
	lock
	faceplayer
	goto_if_set FLAG_UNUSED_0x024, momNorm
	goto_if_set FLAG_UNUSED_0x023, momTalk1
	msgbox momText0, MSGBOX_DEFAULT
	release
	end

momText0:
	.string "{COLOR 04}Mom: I think this is well overdue.\p"
	.string "Go on! Take a look in the bag.$"

momTalk1::
	msgbox momText1, MSGBOX_DEFAULT
	setflag FLAG_UNUSED_0x024
	release
	end

momNorm::
	msgbox momHeal, MSGBOX_YESNO
	compare VAR_RESULT 1
	goto_if_eq yesHeal
	msgbox momPreBadge, MSGBOX_DEFAULT
	release
	end

yesHeal::
	fadescreen 1
	special HealPlayerParty
	fadescreen 0
	msgbox postHeal, MSGBOX_DEFAULT
	release
	end

postHeal:
	.string "{COLOR 04}Ready to go?\p"
	.string "Do your best out there!$"


momPreBadge:
	.string "{COLOR 04}When you get to Ensio City, say hi\n"
	.string "to the Professor for me!\p"
	.string "He was the one who gave me those\n"
	.string "Pokémon.$"

momHeal:
	.string "{COLOR 04}Hi, {PLAYER}. Do you need to rest?$"

momText1:
	.string "{COLOR 04}Mom: Take care of yourself, {PLAYER}!\p"
	.string "You can always visit, but you may\n"
	.string "be cozier getting an apartment in\l"
	.string "Ensio City!$"

tableBag::
	lock
	setflag FLAG_UNUSED_0x023
	goto_if_set FLAG_UNUSED_0x021, alreadyGot
	special ChooseStarter
	fadescreen FADE_TO_BLACK
	call Common_EventScript_NameReceivedPartyMon
	setflag FLAG_SYS_POKEMON_GET
	goto afterPoke

alreadyGot::
	msgbox noMorePokes, MSGBOX_DEFAULT
	release
	end

noMorePokes:
	.string "{COLOR 04}Mom: {PLAYER}!\p"
	.string "Save that last one, okay?\p"
	.string "The Professor said he had plans\n"
	.string "for it.$"

afterPoke::
    applymovement 1, lucyBag
	applymovement OBJ_EVENT_ID_PLAYER, faceLucy
	msgbox lucyPoke, MSGBOX_DEFAULT
	setflag FLAG_UNUSED_0x021
	setvar VAR_DEWFORD_TOWN_STATE, 1
	compare VAR_STARTER_MON, 1
	goto_if_gt lucyHoundour
	goto_if_lt lucyStaryu
	msgbox lucyShroomishGot, MSGBOX_SIGN
	goto pokeGot

dontLeave::
	lock
	applymovement 2, lookThisMAYHAHA
	applymovement OBJ_EVENT_ID_PLAYER, moveBack
	msgbox pokesFirst, MSGBOX_DEFAULT
	release
	end

lookThisMAYHAHA:
	face_down
	step_end

moveBack:
	walk_up
	step_end

pokesFirst:
	.string "{COLOR 04}Mom: Hey!\p"
	.string "Where do you think you are going?\p"
	.string "You won't get very far without a Pokémo-\n"
	.string "Ehhhh I mean, your mystery present!\p"
	.string "Ohh-- just look in the bag, {PLAYER}!$"


faceLucy:
	face_down
	step_end
	
lucyHoundour::
	msgbox lucyHoundourGot, MSGBOX_SIGN
	goto pokeGot

lucyHoundourGot:
	.string "Lucy received the Houndour.$"

lucyShroomishGot:
	.string "Lucy received the Shroomish.$"

lucyStaryu::
	msgbox lucyStaryuGot, MSGBOX_SIGN
	goto pokeGot

lucyStaryuGot:
	.string "Lucy received the Staryu.$"

lucyPoke:
	.string "{COLOR 06}Hmmmm...\p"
	.string "Okay! I'll take this one!$"

lucyBag:
	walk_in_place_right
	step_end

pokeGot::
	applymovement 2, momFace
	waitmovement 0
	applymovement 1, lucyFacePlayer
	waitmovement 0
	msgbox lucyGot, MSGBOX_DEFAULT
	applymovement 1, lucyMomFace
	waitmovement 0
	msgbox lucyMomTalk, MSGBOX_DEFAULT
	applymovement 2, momStep2
	waitmovement 0
	msgbox momLucyTalk, MSGBOX_DEFAULT
	msgbox lucyMomTalk2, MSGBOX_DEFAULT
	closemessage
	applymovement 1, lucyLeave
	waitmovement 0
	removeobject 1
	setflag FLAG_UNUSED_0x022
	release
	end

lucyLeave:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	step_end

lucyMomTalk2:
	.string "{COLOR 06}Lucy: Will do!\p"
	.string "Well, I'm off!$"


momLucyTalk:
	.string "{COLOR 04}Mom: You are so welcome!\p"
	.string "Travel safe, and when you get the\n"
	.string "chance, drag {PLAYER} down with you\l"
	.string "to visit!$"

momStep2:
	walk_in_place_left
	step_end

lucyMomTalk:
	.string "{COLOR 06}Thank you for having me, and for\n"
	.string "the Pokémon, of course!$"

lucyMomFace:
	face_right
	step_end

lucyGot:
	.string "{COLOR 06}Alright.\p"
	.string "{PLAYER}, I am going to head to town,\n"
	.string "so meet me there when you're ready!$"

lucyFacePlayer:
	face_player
	step_end

momFace:
	face_down
	face_down
	step_end

weatherTile::
	compare VAR_MAUVILLE_CITY_STATE, 1
	goto_if_gt wasStormy
	goto_if_eq wasRainy
    random 36
    switch VAR_RESULT
    case 0, weatherSunny
    case 1, weatherSunny
    case 2, weatherSunny
    case 3, weatherSunny
    case 4, weatherSunny
    case 5, weatherSunny
    case 6, weatherSunny
    case 7, weatherRainy
    case 8, weatherSunny
    case 9, weatherSunny
	case 10, weatherSunny
	case 11, weatherSunny
	case 12, weatherSunny
	case 13, weatherSunny
	case 14, weatherSunny
	case 15, weatherSunny
	case 16, weatherSunny
	case 17, weatherSunny
	case 18, weatherSunny
	case 19, weatherSunny
	case 20, weatherSunny
	case 21, weatherSunny
	case 22, weatherSunny
	case 23, weatherSunny
	case 24, weatherSunny
	case 25, weatherSunny
	case 26, weatherSunny
	case 27, weatherSunny
	case 28, weatherSunny
	case 29, weatherSunny
	case 30, weatherSunny
	case 31, weatherSunny
	case 32, weatherSunny
	case 33, weatherSunny
	case 34, weatherSunny
	case 35, weatherSunny
	release
    end

wasRainy::
	random 36
    switch VAR_RESULT
    case 0, weatherRainy
    case 1, weatherRainy
    case 2, weatherRainy
    case 3, weatherRainy
    case 4, weatherRainy
    case 5, weatherRainy
    case 6, weatherRainy
    case 7, weatherRainy
    case 8, weatherRainy
    case 9, weatherStorm
	case 10, weatherStorm
	case 11, weatherStorm
	case 12, weatherRainy
	case 13, weatherRainy
	case 14, weatherRainy
	case 15, weatherRainy
	case 16, weatherRainy
	case 17, weatherRainy
	case 18, weatherRainy
	case 19, weatherRainy
	case 20, weatherRainy
	case 21, weatherRainy
	case 22, weatherRainy
	case 23, weatherRainy
	case 24, weatherRainy
	case 25, weatherRainy
	case 26, weatherRainy
	case 27, weatherRainy
	case 28, weatherRainy
	case 29, weatherRainy
	case 30, weatherRainy
	case 31, weatherRainy
	case 31, weatherRainy
	case 33, weatherRainy
	case 34, weatherSunny
	case 35, weatherSunny
	release
    end

wasStormy::
	random 36
    switch VAR_RESULT
    case 0, weatherStorm
    case 1, weatherStorm
    case 2, weatherStorm
    case 3, weatherStorm
    case 4, weatherStorm
    case 5, weatherStorm
    case 6, weatherStorm
    case 7, weatherStorm
    case 8, weatherStorm
    case 9, weatherStorm
	case 10, weatherStorm
	case 11, weatherStorm
	case 12, weatherStorm
	case 13, weatherStorm
	case 14, weatherStorm
	case 15, weatherStorm
	case 16, weatherRainy
	case 17, weatherRainy
	case 18, weatherRainy
	case 19, weatherRainy
	case 20, weatherRainy
	case 21, weatherRainy
	case 22, weatherRainy
	case 23, weatherRainy
	case 24, weatherRainy
	case 25, weatherRainy
	case 26, weatherRainy
	case 27, weatherRainy
	case 28, weatherRainy
	case 29, weatherRainy
	case 30, weatherStorm
	case 31, weatherStorm
	case 32, weatherStorm
	case 33, weatherStorm
	case 34, weatherStorm
	case 35, weatherStorm
	release
    end

weatherSunny::
    setweather WEATHER_SUNNY
	setvar VAR_MAUVILLE_CITY_STATE, 0
    doweather
	release
    end

weatherRainy::
    setweather WEATHER_RAIN
	setvar VAR_MAUVILLE_CITY_STATE, 1
    doweather
	release
    end

weatherStorm::
    setweather WEATHER_RAIN_THUNDERSTORM
	setvar VAR_MAUVILLE_CITY_STATE, 2
    doweather
	release
    end

