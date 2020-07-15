gText_AbnormalWeatherEnded_Rain:: @ 8273656
	.string "The massive downpour appears to\n"
	.string "have stopped…$"

gText_AbnormalWeatherEnded_Sun:: @ 8273684
	.string "The intense sunshine appears to\n"
	.string "have subsided…$"

fatMan_pot::
	lock
	faceplayer
	msgbox loveMyPots, MSGBOX_DEFAULT
	release
	end

loveMyPots::
	.string "I don't have a lot, but I have my pots.\p"
	.string "They once belonged to my father,\n"
	.string "and his father before him.\p"
	.string "I think, as long as I have these pots,\n"
	.string "I can be happy, even if it's with what\l"
	.string "some would say is so little.\p"
	.string "Do you have something like my pots\n"
	.string "in your life?$"

AsierForestTown_blondeMan::
	lock
	faceplayer
	msgbox AsierForestTown_blondeMan_text, MSGBOX_DEFAULT
	release
	end

AsierForestTown_blondeMan_text::
	.string "It's not easy living out here in the\n"
	.string "middle of the forest, but it's safe.\p"
	.string "You don't attract unwanted attention...$"

AsierForestTown_bangsLady::
	lock
	faceplayer
	msgbox AsierForestTown_bangsLady_text, MSGBOX_DEFAULT
	release
	end

AsierForestTown_bangsLady_text::
	.string "My husband's actually a strong\n"
	.string "Pokémon trainer.\p"
	.string "We decided to move here after he got his\n"
	.string "third badge, but we still get their\l"
	.string "letters...\p"
	.string "Honestly. Yorunashi hasn't seen war in\n"
	.string "ages, but they've been harrassing every\l"
	.string "trainer they find to join them!\p"
	.string "What could they be up to?\p"
	.string "I miss General Akuji...$"

AsierForestTown_prettyLady::
	lock
	faceplayer
	msgbox AsierForestTown_prettyLady_text, MSGBOX_DEFAULT
	release
	end

AsierForestTown_prettyLady_text::
	.string "Hi, {PLAYER}! Ready for the big move?\p"
	.string "Just, uhh... be careful out there,\n"
	.string "okay?$"

AsierForest_trainerEmerson::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_2, introEmerson, defeatEmerson
	msgbox emersonAfter, MSGBOX_DEFAULT
	release
	end

introEmerson::
	.string "Hey! Are you a trainer too?\p"
	.string "Then, we should battle!$"

defeatEmerson::
	.string "Man... Not good enough.$"

emersonAfter::
	.string "Are you from the forest?\p"
	.string "Wow! I can't imagine living around\n"
	.string "here.$"

trainerRyan::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_3, introRyan, defeatRyan
	msgbox ryanAfter, MSGBOX_DEFAULT
	release
	end

introRyan::
	.string "There are so many different types of\n"
	.string "Pokémon to catch here.\p"
	.string "What kind have you found?$"

defeatRyan::
	.string "Man. I need more bugs...$"

ryanAfter::
	.string "You want to battle again?\p"
	.string "Maybe later.\p"
	.string "If I rematch you right now, i'll\n"
	.string "just lose again!$"

trainerAnna::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_4, introAnna, defeatAnna
	msgbox annaAfter, MSGBOX_DEFAULT
	release
	end

introAnna::
	.string "Hey there! Did you come from the\n"
	.string "forest town?\p"
	.string "So, like, are you some sort of fairy?$"

defeatAnna::
	.string "No? Then, maybe like an Elf?$"

annaAfter::
	.string "Sorry, I guess calling you an elf was\n"
	.string "a bit of a stretch.$"

trainerBuster::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_1, introBuster, defeatBuster
	msgbox busterAfter, MSGBOX_DEFAULT
	release
	end

introBuster::
	.string "Heh, I heard that bug Pokémon are the\n"
	.string "strongest of all.\p"
	.string "You won't stand a chance!$"

defeatBuster::
	.string "What? How did I lose...$"

busterAfter::
	.string "The Gym Leader in Ensio City, Pierre,\n"
	.string "told me that Bug-Type Pokémon are the\l" 
	.string "strongest of them all...\p"
	.string "Could he have been wrong?\p"
	.string "No...$"
	
trainerLexia::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_2, introLexia, defeatLexia
	msgbox lexiaAfter, MSGBOX_DEFAULT
	release
	end

introLexia::
	.string "Huh?\p"
	.string "You thought I wasn't a trainer just\n"
	.string "because I was walking around?\p"
	.string "That's... really weird.$"

defeatLexia::
	.string "Hmph.\p"
	.string "You shouldn't judge a book by its cover!$"

lexiaAfter::
	.string "Trainers come in all shapes and sizes,\n"
	.string "young and old.\p"
	.string "I've heard that some won't even battle\n"
	.string "you unless you have a certain amout of\l"
	.string "gym badges!$"

trainerKent::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_2, introKent, defeatKent
	msgbox kentAfter, MSGBOX_DEFAULT
	release
	end

introKent::
	.string "Me and Marg just rented a bunch of cool\n"
	.string "and strong Pokémon from the school.\p"
	.string "They're so rare, it almost feels like\n"
	.string "cheating!$"

defeatKent::
	.string "What is that Pokémon?\p"
	.string "It must be super rare...$"

kentAfter::
	.string "They're rare Pokémon, but they can all\n"
	.string "be found in this Forest.$"

trainerMarg::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_3, introMarg, defeatMarg
	msgbox margAfter, MSGBOX_DEFAULT
	release
	end

introMarg::
	.string "What are your Pokémon like?\p"
	.string "Did you borrow them from school,\n"
	.string "or did you catch them yourself?$"

defeatMarg::
	.string "You're really good...$"

margAfter::
	.string "You should stop by the Trainers school.\p"
	.string "You're good, but some extra studying can\n"
	.string "always help!$"

trainerJoe::
	trainerbattle_single TRAINER_GRUNT_PETALBURG_WOODS, introJoe, defeatJoe
	msgbox joeAfter, MSGBOX_DEFAULT
	release
	end

introJoe::
	.string "BEHOLD THE POWER OF BUG-TYPE POKéMON!$"

defeatJoe::
	.string "NOOOOOooooo!!$"

joeAfter::
	.string "I may have lost, but my Butterfree did\n"
	.string "pretty good, right?$"

asierForestSign::
	lock
	msgbox asierForestSign_text, MSGBOX_DEFAULT
	release
	end

asierForestSign_text::
	.string "Asier Forest Town$"

asierForestMartSign::
	lock
	msgbox asierForestMartSign_text, MSGBOX_DEFAULT
	release
	end

asierForestMartSign_text::
	.string "Local Market\p"
	.string "Get all your basic goods;\n"
	.string "support local buisiness.$"







