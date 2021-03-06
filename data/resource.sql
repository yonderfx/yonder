DROP TABLE IF EXISTS "licenses";
CREATE TABLE "licenses" ("id" INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL , "license_name" VARCHAR);
INSERT INTO "licenses" VALUES(1,'free');
INSERT INTO "licenses" VALUES(2,'cc-by');
INSERT INTO "licenses" VALUES(3,'cc-by-nc');
INSERT INTO "licenses" VALUES(4,'cc-by-nc-nd');
INSERT INTO "licenses" VALUES(5,'cc-by-sa');
INSERT INTO "licenses" VALUES(6,'cc-by-nd');
INSERT INTO "licenses" VALUES(7,'commercial');
INSERT INTO "licenses" VALUES(8,'public domain');
DROP TABLE IF EXISTS "online_resources";
CREATE TABLE "online_resources" ("id" INTEGER PRIMARY KEY  NOT NULL ,"url" TEXT,"title" VARCHAR,"description" TEXT,"rating" INTEGER DEFAULT (0) ,"artist" VARCHAR,"license" INTEGER DEFAULT (1) ,"loop" INTEGER DEFAULT (0) ,"music" INTEGER DEFAULT (0) ,"sfx" INTEGER DEFAULT (0) ,"tags" TEXT);
INSERT INTO "online_resources" VALUES(1,'http://diablo-3.gamersunity.de/files/allgemeines/-soundtrack.download.470.html','Diablo Soundtrack','The soundtrack from the original Diablo Hack & Slay game by Blizzard',0,'Matt Uelmen',1,0,2,0,NULL);
INSERT INTO "online_resources" VALUES(2,'http://diablo-3.gamersunity.de/files/allgemeines/-2-soundtrack.download.471.html','Diablo II Soundtrack','The famous soundtrack from Diablo II',0,'Matt Uelmen',1,0,2,0,NULL);
INSERT INTO "online_resources" VALUES(3,'http://www.eveonline.com/download/music/','EVE Online Soundtrack','Soundtrack from one of the biggest Science Fiction MMORPGs',0,NULL,1,0,2,0,NULL);
INSERT INTO "online_resources" VALUES(4,'http://auralnetwork.com/releases','Fallout Soundtrack','Fallout and Fallout 2 Soundtrack',0,'Mark Morgan',1,0,2,0,NULL);
INSERT INTO "online_resources" VALUES(5,'http://www.sachal.de.vu/','Christoph Sachal','Classic high fantasy music ',0,'Christoph Sachal',1,0,2,0,NULL);
INSERT INTO "online_resources" VALUES(6,'http://flashkit.com/','Flashkit','Resource for hundreds of loops and sound effects',0,NULL,1,2,0,2,NULL);
INSERT INTO "online_resources" VALUES(7,'http://incompetech.com/','incompetech.com','Professional songs for nearly every theme and mood',0,'Kevin MacLeod ',2,2,2,0,NULL);
INSERT INTO "online_resources" VALUES(8,'http://www.jamendo.com/en/album/85843','Adventure MovieScore','Suspensful four-track movie score',0,'Bruce',4,0,2,0,NULL);
INSERT INTO "online_resources" VALUES(9,'http://www.jamendo.com/en/album/51672','HERO Original Motion Picture Score','Score from the 2005 film "Hero"',0,'Brandon K. Guttenfelder',5,0,2,0,NULL);
INSERT INTO "online_resources" VALUES(10,'http://www.jamendo.com/en/album/100211','Film Score Suite #17','A generic film score',0,'Nelson Jenstad',6,0,2,0,'paris');
INSERT INTO "online_resources" VALUES(11,'http://www.freesound.org/','freesound.org','Huge archive with free and creative commons sound effects and loops',0,'Music Technology Group',1,2,0,2,NULL);
INSERT INTO "online_resources" VALUES(12,'http://www.tombraiderchronicles.com/soundtrack/index.html','Tomb Raider Soundtracks','Official soundtracks from "Tomb Raider" games and inspired compositions',0,NULL,1,0,2,0,NULL);
INSERT INTO "online_resources" VALUES(13,'http://www.zreomusic.com/listen','Zelda Reorchestrated','Synthesized Zelda soundtracks',0,'The ZREO Team',1,0,2,0,NULL);
INSERT INTO "online_resources" VALUES(14,'http://kylegabler.com/WorldOfGooSoundtrack/','World Of Goo Soundtrack','Soundtrack from the highly successful indie game "World Of Goo"',0,'Kyle Gabler',1,0,2,0,NULL);
INSERT INTO "online_resources" VALUES(15,'http://nwvault.ign.com/View.php?view=Sounds.Detail&id=554','Neverwinter Nights Community Music Pack','235 tracks provided by the loyal community of the classic RPG "Neverwinter Nights". In *.bmu-format, easily convertable to mp3 with <a href="http://nwvault.ign.com/View.php?view=Other.Detail&id=225%22">mp3tobmu</a>',0,'Tiberius_Morguhn',1,0,2,0,NULL);
INSERT INTO "online_resources" VALUES(16,'http://billbrownmusic.com/music_adventure.php','Bill Brown adventure game music','Soundtracks from "The Incredible Hulk", "Wolfenstein (2008)" and "Michael Crichton''s Timeline"',0,'Bill Brown',1,0,2,0,NULL);
INSERT INTO "online_resources" VALUES(17,'http://billbrownmusic.com/music_action.php','Bill Brown action game music','Soundtracks from "Command and Conquer: Generals", "Generals: Zero Hour", "R6 3: Raven Shield", "The Sum of All Fears", "Ghost Recon", "Desert Siege", "Island Thunder", "Rainbow Six", "Eagle Watch", "Rogue Spear" and "Urban Ops"',0,'Bill Brown',1,0,2,0,NULL);
INSERT INTO "online_resources" VALUES(18,'http://billbrownmusic.com/music_horror.php','Bill Brown horror game music','Soundtracks from "Return To Castle Wolfenstein", "Clive Barker''s Undying" and "Quake II & III"',0,'Bill Brown',1,0,2,0,NULL);
INSERT INTO "online_resources" VALUES(19,'http://www.billbrownmusic.com/music.php','Bill Brown music','Miscellaneous soundtracks',0,'Bill Brown',1,0,2,0,'Dramatic, Mysterious, Action, Suspense, Thriller, Romantic Comedy, Horror, Period Drama, Electronic, Experimental, Rock, CSI : NY');
INSERT INTO "online_resources" VALUES(20,'http://www.schattenreigen.de/earthdawn/','Earthdawn im Schattenreigen','Assorted fantasy/roleplaying music',0,NULL,1,0,2,0,NULL);
INSERT INTO "online_resources" VALUES(21,'http://sierrahelp.com/Assets/Music/Arcanum/','Arcanum Soundtrack','Soundtrack from the 2001 steampunk-rpg "Arcanum"',0,'Ben Houge',1,0,2,0,NULL);
INSERT INTO "online_resources" VALUES(22,'http://www.amazon.com/L-A-Noire-Official-Soundtrack/dp/B00532LQ1C/?tag=trollzacdedsa-21','L.A. Noire Soundtrack','One of the best ingame soundtracks of 2011.

If you already own a copy of this game, you can also extract all sound loops and voice files, but it''s an advanced procedure to get them. Check this Link to find out how: http://forum.xentax.com/viewtopic.php?f=10&t=6623',0,'Rockstar Games',7,2,2,2,'Pulp');
INSERT INTO "online_resources" VALUES(23,'http://archive.org/details/Caruso_part1','Collected Works of Caruso','Recordings of the famous opera singer Caruso (1873–1921)',0,'Caruso',1,0,2,0,'opera, enrico, tenor');
INSERT INTO "online_resources" VALUES(24,'http://freepd.com/','freepd.com','Professional songs for nearly every theme and mood.

By the same author as incompetech.com, but these songs are in the public domain, while the others must be attributed.',0,'Kevin MacLeod ',8,2,2,0,NULL);
INSERT INTO "online_resources" VALUES(25,'http://www.blackmesasource.com/soundtrack.html','Black Mesa: Source Soundtrack','The Soundtrack of the Half Life remake.
With several tracks for different moods',0,'Joel Nielsen',1,0,2,0,NULL);
