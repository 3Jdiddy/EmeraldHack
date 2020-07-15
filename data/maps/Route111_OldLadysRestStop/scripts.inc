Route111_OldLadysRestStop_MapScripts:: @ 822A916
	map_script MAP_SCRIPT_ON_TRANSITION, Route111_OldLadysRestStop_OnTransition
	.byte 0

Route111_OldLadysRestStop_OnTransition: @ 822A91C
	setflag FLAG_LANDMARK_OLD_LADY_REST_SHOP
	end

Route111_OldLadysRestStop_EventScript_OldLady:: @ 822A920
	lock
	faceplayer
	compare 0x4059, 2
	goto_if_eq rainyRest
	goto_if_gt stormyRest
	msgbox Route111_OldLadysRestStop_Text_RestUpHere, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route111_OldLadysRestStop_EventScript_Rest
	compare VAR_RESULT, NO
	goto_if_eq Route111_OldLadysRestStop_EventScript_DeclineRest
	end

rainyRest::
	msgbox rainyRest_text, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route111_OldLadysRestStop_EventScript_Rest
	compare VAR_RESULT, NO
	goto_if_eq Route111_OldLadysRestStop_EventScript_DeclineRest
	end

rainyRest_text::
	.string "Hey there, {PLAYER}!\p"
	.string "Did you come in to escape the rain,\n"
	.string "or just to see me?\p"
	.string "Hahah-- I'm only kidding.\p"
	.string "You are welcome to stay for tea if\n"
	.string "you'd like.\p"
	.string "So, how about it?$"

stormyRest::
	msgbox stormyRest_text, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route111_OldLadysRestStop_EventScript_Rest
	compare VAR_RESULT, NO
	goto_if_eq Route111_OldLadysRestStop_EventScript_DeclineRest
	end

stormyRest_text::
	.string "{PLAYER}?\p"
	.string "What are you doing out in this weather?\p"
	.string "Here, have some tea and stay a while--\n"
	.string "that should warm you up!$"

Route111_OldLadysRestStop_EventScript_Rest:: @ 822A941
	msgbox Route111_OldLadysRestStop_Text_TakeYourTimeRestUp, MSGBOX_DEFAULT
	setrespawn HEAL_LOCATION_OLDALE_TOWN
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox Route111_OldLadysRestStop_Text_After, MSGBOX_DEFAULT
	release
	end

Route111_OldLadysRestStop_Text_After::
	.string "Thank you for stopping by!\p"
	.string "Come again sometime, and we can have\n"
	.string "another chat.$"

Route111_OldLadysRestStop_EventScript_DeclineRest:: @ 822A96E
	msgbox Route111_OldLadysRestStop_Text_DontNeedToBeShy, MSGBOX_DEFAULT
	release
	end

Route111_OldLadysRestStop_Text_RestUpHere: @ 822A978
	.string "Oh, my!\n"
	.string "Are your Pokémon tired?\p"
	.string "If you'd like, you can rest up here.\n"
	.string "I can brew you some tea!$"

Route111_OldLadysRestStop_Text_TakeYourTimeRestUp: @ 822A9EC
	.string "Wonderful.\n"
	.string "I'll put the kettle on.$"

Route111_OldLadysRestStop_Text_DontNeedToBeShy: @ 822AA8F
	.string "Are you sure?\n"
	.string "You don't need to be shy about it.$"

